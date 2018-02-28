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



// ifndef CORE_C
#endif