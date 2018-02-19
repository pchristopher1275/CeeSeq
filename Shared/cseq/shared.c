#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../stretchy_buffer.h"
#include "../sds/sds.h"
#include "../sds/sds.c"

sds stripBaseNameString = NULL;
sds stripBaseName(const char *path)
{
    if (stripBaseNameString != NULL) {
        sdsfree(stripBaseNameString);
    }
    const char *p = strrchr(path, '/');
    if (p == NULL) {
        p = path;
    }
    else {
        p++;
    }

    stripBaseNameString = sdsnew(p);
    return stripBaseNameString;
}


//
// T I M E
//
typedef long long Ticks;
Ticks cseqHub_now()
{
    return (Ticks)itm_getticks(itm_getglobal());
}


//
// E R R O R    C L A S S
//
typedef struct _Error
{
    bool iserror;
    sds message;
} Error;

#define Error_declare(name) Error _##name = {false, NULL}; Error *name = &_##name

static inline bool Error_iserror(Error *err)
{
    return err->iserror;
}


sds Error_message(Error *err)
{
    if (err->iserror) {
        return err->message;
    }
    return NULL;
}


void Error_clear(Error *err)
{
    if (err->message != NULL) {
        sdsfree(err->message);
    }
    err->message = NULL;
    err->iserror = false;
}


void Error_formatFileLine(Error *dst, const char *file, int line, sds message)
{
    Error_clear(dst);
    dst->message = sdscatprintf(sdsempty(), "[%s:%d] %s", stripBaseName(file), line, message);
    dst->iserror = true;
    sdsfree(message);
}


#define Error_format(dst, format, ...) Error_formatFileLine(dst, __FILE__, __LINE__, sdscatprintf(sdsempty(), (format), __VA_ARGS__))
#define Error_format0(dst, format) Error_formatFileLine(dst, __FILE__, __LINE__, sdscatprintf(sdsempty(), (format)))

const char *Error_maxErrToString(t_max_err maxErr)
{
    const char *label = "UNKNOWN";
    switch (maxErr) {
        case MAX_ERR_NONE:
            label = "NONE";
        case MAX_ERR_GENERIC:
            label = "GENERIC";
        case MAX_ERR_INVALID_PTR:
            label = "INVALID_PTR";
        case MAX_ERR_DUPLICATE:
            label = "DUPLICATE";
        case MAX_ERR_OUT_OF_MEM:
            label = "OUT_OF_MEM";
    }
    return label;
}


int Error_maypost(Error *err)
{
    int iserror = Error_iserror(err);
    if (iserror) {
        post("%s", Error_message(err));
    }
    Error_clear(err);
    return iserror;
}

#define Error_returnVoidOnError(err)           if (Error_iserror(err)) return
#define Error_returnZeroOnError(err)           if (Error_iserror(err)) return 0
#define Error_returnNullOnError(err)           if (Error_iserror(err)) return NULL
#define Error_gotoLabelOnError(err, label)     if (Error_iserror(err)) goto label
//
// T E X T    L O G G I N G
//

FILE *dbLog_outputFd = NULL;

void DBLog_printSDS(const char *file, int line, sds message)
{
    if (dbLog_outputFd != NULL) {
        fprintf(dbLog_outputFd, "[%s: %d] %s\n", stripBaseName(file), line, message);
        fflush(dbLog_outputFd);
    }
    sdsfree(message);
}


#define dblog(format, ...) DBLog_printSDS(__FILE__, __LINE__, sdscatprintf(sdsempty(), format, __VA_ARGS__))
#define dblog0(format) DBLog_printSDS(__FILE__, __LINE__, sdsnew(format))

void DBLog_init(const char *tag, Error *err)
{
    if (dbLog_outputFd == NULL) {
        const char *HOME = getenv("HOME");
        if (HOME == NULL) {
            Error_format0(err, "Failed to find $HOME");
            return;
        }
        sds outputFile = sdscatprintf(sdsempty(), "%s/CeeSeq/%s_DBLog.txt", HOME, tag);
        dbLog_outputFd = fopen(outputFile, "w");
        if (dbLog_outputFd == NULL) {
            Error_format(err, "DBLog_init failed to open log file %s", outputFile);
        }
        else {
            time_t ltime;                         /* calendar time */
            ltime=time(NULL);                     /* get current cal time */
            dblog("DBLog starting at %s", asctime(localtime(&ltime)));
        }
        sdsfree(outputFile);
    }
}


//
// P O R T
//

enum
{
    // XXX: Port type is deprecated use the track and type symbols on Port
    Port_nullType = 0,
    Port_vstType = 1,
};

struct Port_t;
typedef void (*Port_anythingDispatchFunc)(void *hub, struct Port_t *port, t_symbol *msg, long argc, t_atom *argv);
typedef void (*Port_intDispatchFunc)(void *hub, struct Port_t *port, long value, long inlet);
typedef struct Port_t
{
    t_object d_obj;
    int porttype;
    long inletnum;
    void **proxy;
    void **outlet;
    t_symbol *track;
    t_symbol *id;
    long intInlets;
    long intOutlets;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
    t_atom *sendBuffer;
} Port;

Port PORT_NULL_IMPL =
{
    {
        0
    }
};

#define Port_null (&PORT_NULL_IMPL)
#define Port_track(p)            ((p)->track)
#define Port_id(p)               ((p)->id)
#define Port_hub(p)              ((p)->hub)
#define Port_anythingDispatch(p) ((p)->anythingDispatch)
#define Port_intDispatch(p)      ((p)->intDispatch)
#define Port_sendBuffer(p)       ((p)->sendBuffer)
#define Port_outlet(p, n)        ((p)->outlet[(n)])
#define Port_proxy(p, n)         ((p)->proxy[(n)])
#define Port_intInlets(p)        ((p)->intInlets)
#define Port_intOutlets(p)       ((p)->intOutlets)
#define Port_inletnum(p)         (p)->inletnum

// Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
int port_parseEvSymbol(t_symbol *id)
{
    int r = -1;
    int consumed = 0;
    if (id == NULL) {
        return -1;
    }

    if (sscanf(id->s_name, "ev%d%n", &r, &consumed) != 1) {
        return -1;
    }
    if (strlen(id->s_name) != consumed) {
        return -1;
    }
    return r;
}


static const char *Port_idString(Port *port)
{
    switch(port->porttype) {
        case Port_nullType:
            return "Port_nullType";
        case Port_vstType:
            return "Port_vstType";
        default:
            return "PORT-UNKNOWN";
    }
}


static int Port_isVstType(Port *port)
{
    return port->porttype == Port_vstType;
}


static int Port_isNullType(Port *port)
{
    return port->porttype == Port_nullType;
}


void Port_send(Port *port, short argc, t_atom *argv, Error *err)
{
    if (Port_isNullType(port)) {
        return;
    }
    else if (Port_isVstType(port)) {
        t_symbol *selector = atom_getsym(argv + 0);
        outlet_anything(Port_outlet(port, 0), selector, argc-1, argv+1);
    }
    else {
        Error_format(err, "Port_send called on porttype = %s", Port_idString(port));
    }
}

void Port_sendInteger(Port *p, long value) {
    outlet_int(Port_outlet(p, 0), value);   
}

void Port_sendSelectorAndInteger(Port *port, t_symbol *selector, int value)
{
    t_atom a = {0};
    atom_setlong(&a, value);
    outlet_anything(Port_outlet(port, 0), selector, 1, &a);
}
