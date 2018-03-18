typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typename) ((typename*)&Undefined_instance)

// From file 'test/util/for_tarray.in.h'
const char *Interface_toString(int itype);