#ifndef CORE_C
#define CORE_C
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sds.c"

#ifndef APIF
#  define APIF /**/
#endif 

#ifdef TEST_BUILD
#  define Error_maxErrorInteger int
#else
#  define Error_maxErrorInteger t_max_err
#endif
//
// T E X T    L O G G I N G
//

FILE *dbLog_outputFd = NULL;


sds DBLog_stripBaseNameString = NULL;
APIF sds DBLog_stripBaseName(const char *path)
{
    if (DBLog_stripBaseNameString != NULL) {
        sdsfree(DBLog_stripBaseNameString);
    }
    const char *p = strrchr(path, '/');
    if (p == NULL) {
        p = path;
    }
    else {
        p++;
    }

    DBLog_stripBaseNameString = sdsnew(p);
    return DBLog_stripBaseNameString;
}


APIF void DBLog_printSDS(const char *file, int line, sds message)
{
    if (dbLog_outputFd != NULL) {
        fprintf(dbLog_outputFd, "[%s: %d] %s\n", DBLog_stripBaseName(file), line, message);
        fflush(dbLog_outputFd);
    }
    sdsfree(message);
}


#define dblog(format, ...) DBLog_printSDS(__FILE__, __LINE__, sdscatprintf(sdsempty(), format, __VA_ARGS__))
#define dblog0(format) DBLog_printSDS(__FILE__, __LINE__, sdsnew(format))

//
// E R R O R    C L A S S
//
typedef struct Error_t
{
    bool iserror;
    sds message;
} Error;

#ifdef TEST_BUILD
#  define Error_post dblog 
#else
#  define Error_post post
#endif


#define Error_declare(name) Error _##name = {false, NULL}; Error *name = &_##name

APIF static inline bool Error_iserror(Error *err)
{
    return err->iserror;
}


APIF sds Error_message(Error *err)
{
    if (err->iserror) {
        return err->message;
    }
    return NULL;
}


APIF void Error_clear(Error *err)
{
    if (err->message != NULL) {
        sdsfree(err->message);
    }
    err->message = NULL;
    err->iserror = false;
}


APIF void Error_formatFileLine(Error *dst, const char *file, int line, sds message)
{
    Error_clear(dst);
    dst->message = sdscatprintf(sdsempty(), "[%s:%d] %s", DBLog_stripBaseName(file), line, message);
    dst->iserror = true;
    sdsfree(message);
}


#define Error_format(dst, format, ...) Error_formatFileLine(dst, __FILE__, __LINE__, sdscatprintf(sdsempty(), (format), __VA_ARGS__))
#define Error_format0(dst, format) Error_formatFileLine(dst, __FILE__, __LINE__, sdscatprintf(sdsempty(), (format)))



APIF const char *Error_maxErrToString(Error_maxErrorInteger maxErr)
{
    const char *label = "UNKNOWN";
#   ifndef TEST_BUILD
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
#   endif
    return label;
}

#ifdef TEST_BUILD
#define Error_print(err) printf("ERROR: %s\n", Error_iserror(err) ? Error_message(err) : "<none>")
#endif



APIF int Error_maypost(Error *err)
{
    int iserror = Error_iserror(err);
    if (iserror) {
        Error_post("%s", Error_message(err));
    }
    Error_clear(err);
    return iserror;
}

#define Error_returnVoidOnError(err)           if (Error_iserror(err)) return
#define Error_returnZeroOnError(err)           if (Error_iserror(err)) return 0
#define Error_returnNullOnError(err)           if (Error_iserror(err)) return NULL
#define Error_gotoLabelOnError(err, label)     if (Error_iserror(err)) goto label



//
// D B L O G    a g a i n
//
APIF void DBLog_init(const char *tag, Error *err)
{
    if (dbLog_outputFd == NULL) {        
        sds outputFile = sdscatprintf(sdsempty(), "%s/%s_DBLog.txt", CSEQ_HOME, tag);
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
// S Y M B O L
//
#ifdef TEST_BUILD
typedef struct Symbol_t {sds name;} Symbol;
static inline const char *Symbol_cstr(Symbol *s) {
    return s->name;
}
static inline Symbol *Symbol_gen(const char *word) {
    Symbol *s = Mem_malloc(sizeof(Symbol));
    s->name = sdsnew(word);
    return s;
}

#else
#define Symbol t_symbol
#define Symbol_gen gensym
#define Symbol_cstr(s) (s->s_name)
#endif


//
// A T O M
//
#ifdef TEST_BUILD
#define Atom_typeSymbol 1
#define Atom_typeInteger 2
#define Atom_typeFloat 3
typedef struct Atom_t {
    int atype;
    union {
        Symbol *symbol;
        long integer;
        double number;
    } value;
} Atom;

static inline Atom Atom_integer(long value) {
    Atom a = {0};
    a.atype = Atom_typeInteger;
    a.value.integer = value;
    return a;
}

static inline Atom Atom_symbol(Symbol *value) {
    Atom a = {0};
    a.atype = Atom_typeSymbol;
    a.value.symbol = value;
    return a;
}

static inline Atom Atom_float(double value) {
    Atom a = {0};
    a.atype = Atom_typeFloat;
    a.value.number = value;
    return a;
}


static inline bool Atom_isSymbol(Atom *a) {
    return a->atype == Atom_typeSymbol;
}
static inline Symbol *Atom_toSymbol(Atom *a) {
    return a->type == Atom_typeSymbol ? a->value.symbol : NULL;
}

static inline bool Atom_isNumber(Atom *a) {
    return a->atype == Atom_typeInteger || a->atype == Atom_typeFloat;
}

static inline long Atom_toInteger(Atom *a) {
    return a->type == Atom_typeInteger ? a->value.integer : 
           a->type == Atom_typeFloat   ? (long)a->value.number;
} 
static inline double Atom_toFloat(Atom *a) {
    return a->type == Atom_typeInteger ? (double)a->value.integer : 
           a->type == Atom_typeFloat   ? a->value.number;
}

#else

#define Atom t_atom

static inline Atom Atom_integer(long value) {
    Atom a = {0};
    atom_setlong(&a, value);
    return a;
}

static inline Atom Atom_symbol(Symbol *value) {
    Atom a = {0};
    atom_setsym(*a, value);
    return a;
}

static inline Atom Atom_float(double value) {
    Atom a = {0};
    atom_setfloat(&a, value);
    return a;
}

static inline bool Atom_isSymbol(Atom *a) {
    int t = atom_gettype(a);
    return t == A_SYM;
}
static inline Symbol *Atom_toSymbol(Atom *a) {
    return atom_getsym(a);
}

static inline bool Atom_isNumber(Atom *a) {
    int t = atom_gettype(a);
    return t == A_LONG || t == A_FLOAT;
}
static inline long Atom_toInteger(Atom *a) {
    return atom_getlong(a);
} 
static inline double Atom_toFloat(Atom *a) {
    return atom_getfloat(a);
} 

#endif



// ifndef CORE_C
#endif