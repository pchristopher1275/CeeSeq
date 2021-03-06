#define APIF /**/
#define Coverage_off /**/
#define Coverage_on /**/
#define COVER /**/
#define NOCOVER /**/



#ifdef TEST_BUILD
#  define Error_maxErrorInteger int
#else
#  define Error_maxErrorInteger t_max_err
#endif


//
// M E M O R Y
//

#ifdef TEST_BUILD
// 
// T e s t i n g   M e m o r y  F u n c t i o n s
//

#define Mem_realloc(ptr, size) realloc(ptr, size)
#define Mem_malloc(size)       malloc(size)
#define Mem_calloc(size)       calloc(size, 1)
#define Mem_free(ptr)          free(ptr)


#else

//
// M a x   M e m o r y   F u n c t i o n s 
//
#define Mem_malloc(size)       (void*)sysmem_newptr(size)
#define Mem_calloc(size)       (void*)sysmem_newptrclear(size)
#define Mem_realloc(ptr, size) (void*)sysmem_resizeptr((ptr), (size))
#define Mem_free(ptr)          sysmem_freeptr(ptr)
#endif 

//
// String
//

typedef struct StringBody_t {
    int len; // len DOES NOT include the null terminator
    char ch[0];
} StringBody;

typedef const char String;
void String_free(String *s);

APIF StringBody *String_toStringBody(String *s)
{
    return (StringBody*)(s - sizeof(int));
}


APIF String *String_fmt(const char *format, ...) 
{
    va_list ap;
    va_start(ap, format);
    size_t needed = vsnprintf(NULL, 0, format, ap);
    va_end(ap);
    StringBody *body = (StringBody*)Mem_malloc(needed+1+sizeof(int));
    body->len        = needed;
    va_start(ap, format);
    vsnprintf(body->ch, needed+1, format, ap);
    va_end(ap);
    return body->ch;
}

APIF int String_len(String *s) {
    StringBody *body = String_toStringBody(s);
    return body->len;
}

APIF bool String_isempty(String *s)
{
    return String_len(s) == 0;
}

APIF void String_freep(String **sp) 
{
    String_free(*sp);
}

APIF void String_free(String *s) 
{
    StringBody *body = String_toStringBody(s);
    Mem_free(body);
}

APIF int String_cmp(String *self, String *other)
{
    return strcmp(self, other);
}

APIF int String_cmpPp(String **self, String **other)
{
    return strcmp(*self, *other);
}

APIF int String_equal(String *self, String *other)
{
    return String_cmp(self, other) == 0;
}

APIF int String_cequal(String *self, const char *other)
{
    return String_cmp(self, other) == 0;   
}

APIF String *String_empty()
{
    StringBody *body = (StringBody*)Mem_malloc(1+sizeof(int));
    body->len = 0;
    body->ch[0] = '\0';
    return body->ch;
}

APIF void String_trim(String **sp)
{
    String *s = *sp;
    StringBody *body = String_toStringBody(s);


    char *p = (char*)s;
    int l   = body->len;

    while(isspace(p[l - 1])) {
        p[--l] = '\0';
    }
    while(*p && isspace(*p)) {
        p++;
    }
    *sp = String_fmt("%s", p);
    String_free(s);
}

APIF String *String_dup(String *src) 
{
    return String_fmt("%s", src);
}

// newLen DOES NOT include the null byte
APIF void String_resize(String **src, int newLen)
{
    StringBody *body = String_toStringBody(*src);
    if (newLen < 0) {
        return;
    }

    StringBody *nw = Mem_malloc(newLen + 1 + sizeof(int));
    nw->len        = newLen;
    int cpyLen = body->len < newLen ? body->len : newLen;
    strncpy(nw->ch, *src, cpyLen);
    nw->ch[cpyLen] = '\0';
    String_free(*src);
    *src = nw->ch;
}

char *basename(char *filename)
{
    char *p = strrchr(filename, '/');
    return p ? p + 1 : (char *)filename;
}
APIF String *Coverage_createCoverageFile(const char *filename)
{
    String *str = String_fmt("%s", filename);
    char *dot   = strrchr(str, '.');
    char *slash = strrchr(str, '/');
    if (!slash) {
        slash = (char*)str;
    }
    if (dot && dot > slash) {
        *dot = '\0';
    }
    String *coverFile = String_fmt("test/coverage/%s.touched", (*slash == '/' ? slash+1 : slash));
    return coverFile;    
}

//
// T E X T    L O G G I N G
//

FILE *dbLog_outputFd = NULL;


String *DBLog_stripBaseNameString = NULL;
APIF const char *DBLog_stripBaseName(const char *path)
{
    if (DBLog_stripBaseNameString != NULL) {
        String_free(DBLog_stripBaseNameString);
    }
    const char *p = strrchr(path, '/');
    if (p == NULL) {
        p = path;
    }
    else {
        p++;
    }

    DBLog_stripBaseNameString = String_fmt("%s", p);
    return DBLog_stripBaseNameString;
}


APIF void DBLog_printSDS(const char *file, int line, String *message)
{
    if (dbLog_outputFd != NULL) {
        fprintf(dbLog_outputFd, "[%s: %d] %s\n", DBLog_stripBaseName(file), line, message);
        fflush(dbLog_outputFd);
    }
    String_free(message);
}


#define dblog(format, ...) DBLog_printSDS(__FILE__, __LINE__, String_fmt(format, __VA_ARGS__))
#define dblog0(format) DBLog_printSDS(__FILE__, __LINE__, String_fmt("%s", format))

//
// E R R O R    C L A S S
//
typedef struct ErrorBacktraceCell_t {
    int line;
    const char *function;
    const char *file;
} ErrorBacktraceCell;

typedef struct ErrorBacktrace_t {
    int len;
    int cap;
    ErrorBacktraceCell *cells;
} ErrorBacktrace;

APIF ErrorBacktrace *ErrorBacktrace_new()
{
    ErrorBacktrace *self = Mem_calloc(sizeof(ErrorBacktrace));
    self->cap   = 1000;
    self->cells = Mem_calloc(sizeof(ErrorBacktraceCell) * self->cap);
    return self;
}

APIF void ErrorBacktrace_free(ErrorBacktrace *self)
{
    if (self != NULL) {
        Mem_free(self->cells);
        Mem_free(self);
    }
}

#define Error_returnVoidOnError(err)           if (Error_iserrorMaybeBacktrace(err)) return
#define Error_returnZeroOnError(err)           if (Error_iserrorMaybeBacktrace(err)) return 0
#define Error_returnNullOnError(err)           if (Error_iserrorMaybeBacktrace(err)) return NULL
#define Error_gotoLabelOnError(err, label)     if (Error_iserrorMaybeBacktrace(err)) goto label
#define Error_returnValueOnError(err, value)   if (Error_iserrorMaybeBacktrace(err)) return value
#define Error_declare(name) Error _##name = {0}; Error *name = &_##name

#ifdef TEST_BUILD
#define Error_iserrorMaybeBacktrace(err) Error_iserrorWithBacktrace(err, __LINE__, __func__, __FILE__)
#else
#define Error_iserrorMaybeBacktrace(err) Error_iserror(err)
#define Error_post(first, ...) post(first, __VA_ARGS__) 
#endif



typedef struct Error_t
{
    bool iserror;
    String *message;
#   ifdef TEST_BUILD
    ErrorBacktrace *backtrace;
#   endif
} Error;

// 
// Error_post
#ifdef TEST_BUILD
static inline void Error_postImpl(String *s)
{
    printf("ERROR: %s\n", s);
    String_free(s);
}

#define Error_post(first, ...) do {\
    String *s = String_fmt(first, __VA_ARGS__);\
    printf("ERROR: %s\n", s);\
    String_free(s);\
} while (0)

#endif

APIF static inline bool Error_iserror(Error *err)
{
    return err->iserror;
}


APIF const char *Error_message(Error *err)
{
    if (err->iserror) {
        return err->message;
    }
    return NULL;
}

APIF void Error_clear(Error *err)
{
    if (err->message != NULL) {
        String_free(err->message);
#       ifdef  TEST_BUILD
        ErrorBacktrace_free(err->backtrace);
#       endif
    }
    err->message = NULL;
    err->iserror = false;
}

NOCOVER bool Error_iserrorWithBacktrace(Error *err, int line, const char *function, const char *file) {
    if (Error_iserror(err)) {
#       ifdef TEST_BUILD
        ErrorBacktrace *bt = err->backtrace;
        if (bt->len < bt->cap) {
            bt->cells[bt->len].line     = line;
            bt->cells[bt->len].function = function;
            bt->cells[bt->len].file     = file;
            bt->len++;
        }
#       endif
        return true;
    }
    return false;
}

APIF void Error_formatFileLine(Error *dst, const char *function, const char *file, int line, String *message)
{
    Error_clear(dst);
    dst->message = String_fmt("[%s:%s:%d] %s", function, DBLog_stripBaseName(file), line, message);
    dst->iserror = true;
#   ifdef TEST_BUILD
    dst->backtrace = ErrorBacktrace_new();
    Error_iserrorWithBacktrace(dst, line, function, file);
#   endif
    String_free(message);
}


#define Error_format(dst, format, ...) Error_formatFileLine(dst, __func__, __FILE__, __LINE__, String_fmt((format), __VA_ARGS__))
#define Error_format0(dst, format)     Error_formatFileLine(dst, __func__, __FILE__, __LINE__, String_fmt(format))



APIF void Error_printBacktrace(Error *err)
{
#   ifdef TEST_BUILD
    if (err->backtrace != NULL) {
        printf("ERROR BACKTRACE:\n");
        printf("    %20s %10s %20s\n", "file", "line", "function");
        for (int i = 0; i < err->backtrace->len; i++) {
            ErrorBacktraceCell cell = err->backtrace->cells[i];
            printf("    %20s %10d %20s\n", cell.file, cell.line, cell.function);
        }
    } else {
        printf("NO BACKTRACE TO PRINT\n");
    }
#   endif
    return;
}

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

//
// More    S T R I N G
//
APIF int String_readline(String **buffer, FILE *inp, Error *err)
{
    static char *linep     = NULL;
    static size_t linecapp = 0;
    ssize_t len = getline(&linep, &linecapp, inp);
    if (len < 0) {
        if (feof(inp)) {
            return 0;
        }
        Error_format0(err, "String_readline failed");
        return 0;
    }
    if (linep[len-1] == '\n') {
        linep[len-1] = '\0';
        len--;
    }
    StringBody *body = String_toStringBody(*buffer);
    if (body->len < len) {
        String *s = body->ch;
        String_resize(&s, len);
        body = String_toStringBody(s);
    }
    strncpy(body->ch, linep, len);
    body->ch[len] = '\0';
    *buffer = body->ch;
    return 1;
}

APIF long String_toInteger(String *s, Error *err)
{
    long value = 0;
    if (sscanf(s, "%ld", &value) != 1) {
        Error_format0(err, "String_toInteger failed to convert integer");
    }
    return value;  
}

//
// D B L O G    a g a i n
//
APIF void DBLog_init(const char *tag, Error *err)
{
    if (dbLog_outputFd == NULL) {        
        String *outputFile = String_fmt("%s/%s_DBLog.txt", CSEQ_HOME, tag);
        dbLog_outputFd = fopen(outputFile, "w");
        if (dbLog_outputFd == NULL) {
            Error_format(err, "DBLog_init failed to open log file %s", outputFile);
        }
        else {
            time_t ltime;                         /* calendar time */
            ltime=time(NULL);                     /* get current cal time */
            dblog("DBLog starting at %s", asctime(localtime(&ltime)));
        }
        String_free(outputFile);
    }
}

//
// M A X   O B J E C T
//
#ifdef TEST_BUILD
typedef struct MaxObject_t {void *utilityPointer;} MaxObject;
#else
#  define MaxObject t_object
#endif 

//
// S Y M B O L
//
#ifdef TEST_BUILD
typedef struct Symbol_t {const char *name;} Symbol;
Symbol *Symbol_gen(const char *word);
static inline const char *Symbol_cstr(Symbol *s) {
    return s->name;
}
#else
#define Symbol t_symbol
#define Symbol_gen gensym
#define Symbol_cstr(s) ((s)->s_name)
#endif

static inline int Symbol_cmp(Symbol *left, Symbol *right)
{
    if (left < right) {
        return -1;
    } else if (left > right) {
        return 1;
    }
    return 0;
}



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

static inline Atom Atom_fromInteger(long value) {
    Atom a = {0};
    a.atype = Atom_typeInteger;
    a.value.integer = value;
    return a;
}

static inline Atom Atom_fromSymbol(Symbol *value) {
    Atom a = {0};
    a.atype = Atom_typeSymbol;
    a.value.symbol = value;
    return a;
}

static inline Atom Atom_fromFloat(double value) {
    Atom a = {0};
    a.atype = Atom_typeFloat;
    a.value.number = value;
    return a;
}


static inline bool Atom_isSymbol(Atom *a) {
    return a->atype == Atom_typeSymbol;
}
static inline Symbol *Atom_toSymbol(Atom *a) {
    return a->atype == Atom_typeSymbol ? a->value.symbol : NULL;
}

static inline bool Atom_isNumber(Atom *a) {
    return a->atype == Atom_typeInteger || a->atype == Atom_typeFloat;
}

static inline long Atom_toInteger(Atom *a) {
    return a->atype == Atom_typeInteger ? a->value.integer : 
           a->atype == Atom_typeFloat   ? (long)a->value.number : 0;
} 
static inline double Atom_toFloat(Atom *a) {
    return a->atype == Atom_typeInteger ? (double)a->value.integer : 
           a->atype == Atom_typeFloat   ? a->value.number : 0.0;
}

#else

#define Atom t_atom

static inline Atom Atom_fromInteger(long value) {
    Atom a = {0};
    atom_setlong(&a, value);
    return a;
}

static inline Atom Atom_fromSymbol(Symbol *value) {
    Atom a = {0};
    atom_setsym(&a, value);
    return a;
}

static inline Atom Atom_fromFloat(double value) {
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

//
// T I M E
//
typedef long long Ticks;
#define Ticks_maxTime LLONG_MAX 

#ifdef TEST_BUILD
Ticks Ticks_dbCurrent = -1;
void Ticks_dbSetNow(Ticks current){Ticks_dbCurrent = current;}
Ticks Ticks_dbNow(){return Ticks_dbCurrent;}
Ticks Ticks_replaceMaxTime(Ticks value, Ticks replace) {
    if (value == Ticks_maxTime) {
        return replace;
    }
    return value;
}
#endif

#ifndef TEST_BUILD
APIF Ticks cseqHub_now()
{
    return (Ticks)itm_getticks(itm_getglobal());
}
APIF Ticks Ticks_now()
{
    return (Ticks)itm_getticks(itm_getglobal());
}
APIF double Ticks_toMs(Ticks ticks)
{
    return itm_tickstoms(itm_getglobal(), (double)ticks);
}
#endif


//
// M E V E N T
//
typedef struct MEvent_t
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
} MEvent;
#define MEvent_newUninitialized() ((MEvent*)Mem_malloc(sizeof(MEvent)))
#define MEvent_type(cell) ((cell).type)
#define MEvent_t(cell) ((cell).t)
#define MEvent_notePitch(cell) ((cell).b.b[0])
#define MEvent_noteVelocity(cell) ((cell).b.b[1])
#define MEvent_noteDuration(cell) ((cell).duration)
#define MEvent_ccNumber(cell) ((cell).b.b[0])
#define MEvent_ccValue(cell) ((cell).b.b[1])
#define MEvent_bendValue(cell) ((cell).b.bend)

struct Port_t;
typedef struct Port_t Port;
typedef void (*Port_anythingDispatchFunc)(void *hub, struct Port_t *port, Symbol *msg, long argc, Atom *argv);
typedef void (*Port_intDispatchFunc)(void *hub, struct Port_t *port, long value, long inlet);
