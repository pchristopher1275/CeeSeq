#include <string.h>
#include <stdlib.h>
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
    Port_vstType = 1,
    Port_noType = 2,
};

typedef struct
{
    t_object d_obj;
    int porttype;
    void *outlet1;
} Port;

static const char *Port_typeString(Port *port)
{
    switch(port->porttype) {
        case Port_vstType:
            return "Port_vstType";
        case Port_noType:
            return "Port_noType";
        default:
            return "PORT-UNKNOWN";
    }
}


static int Port_isVstType(Port *port)
{
    return port->porttype == Port_vstType;
}


void Port_sendnote(Port *port, int pitch, int velocity, Ticks duration, Error *err)
{
    if (Port_isVstType(port)) {
        const short ac = 3;
        t_atom av[ac] = {
            {
                0
            }
        };
        atom_setlong(av+0, pitch);
        atom_setlong(av+1, velocity);
        atom_setfloat(av+2, (float)duration);
        outlet_anything(port->outlet1, gensym("note"), ac, av);
    }
    else {
        Error_format(err, "Port_sendnote called on porttype = %s", Port_typeString(port));
    }
}

void Port_send(Port *port, short argc, t_atom *argv, Error *err)
{
    t_symbol *selector = atom_getsym(argv + 0);
    if (Port_isVstType(port)) {
        outlet_anything(port->outlet1, selector, argc-1, argv+1);
    }
    else {
        Error_format(err, "Port_send called on porttype = %s", Port_typeString(port));
    }
}
