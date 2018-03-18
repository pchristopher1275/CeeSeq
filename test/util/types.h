// *** DO NOT MODIFY THIS FILE (see test/util/for_tarray.in.h) generated 03/18/2018 13:38:09 ***
struct Foo_t;
typedef struct Foo_t Foo;
// *** DO NOT MODIFY THIS FILE (see test/util/for_tarray.in.h) generated 03/18/2018 13:38:09 ***
struct Foo_t
{
    int i;
    double d;
};
typedef struct FooArr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Foo*);
   Foo *data;
} FooArr;

typedef struct FooArrSlice_t {
    int len;
    Foo *data;
    int index;
    Foo *var;
} FooArrSlice;

typedef struct FooArrIter_t {
   FooArr *arr;
   int index;
   bool last;
   Foo *var;
} FooArrIter;

// *** DO NOT MODIFY THIS FILE (see test/util/for_tarray.in.h) generated 03/18/2018 13:38:09 ***
