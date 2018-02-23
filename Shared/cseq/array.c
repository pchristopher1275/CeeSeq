

#define sb_free(a)         ((a) ? sysmem_freeptr(sb__raw(a)),0 : 0)
#define sb_push(a,v)       (sb__maybegrow(a,1), (a)[sb__len(a)++] = (v))
#define sb_count(a)        ((a) ? sb__len(a) : 0)
#define sb_add(a,n)        (sb__maybegrow(a,n), sb__len(a)+=(n), &(a)[sb__len(a)-(n)])
#define sb_last(a)         ((a)[sb__len(a)-1])
#define sb_pop(a)          ((a) != NULL && sb__len(a) > 0 ? sb__len(a)-- : 0)
#define sb_clear(a)        (sb_free(a), (a) = NULL, 0)

#define sb__raw(a) ((int *) (a) - 2)
#define sb__cap(a) sb__raw(a)[0]
#define sb__len(a) sb__raw(a)[1]

#define sb__needgrow(a,n)  ((a)==0 || sb__len(a)+(n) >= sb__cap(a))
#define sb__maybegrow(a,n) (sb__needgrow(a,(n)) ? sb__grow(a,n) : 0)
#define sb__grow(a,n)      ((a) = sb_growf((a), (n), sizeof(*(a))))

#include <stdlib.h>

typedef void (*Array_deleteElement)(void *);
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   Array_deleteElement deleter;
   char *data;
} Array;

// REMEMBER: when you specify a range of elements to operate on, always select the range as
// [start, end) : here start is the first index of the subsequence, and end is ONE-PAST the last
// index of the subsequence. With this, the number of elements in the subsequence is end-start.

#define Array_formatIndexError(err, m, n, o) Error_format((err), "Index out of range (%d, %d, %d)", (m), (n), (o))

Array *Array_new(int nelems, int elemSize) {
   Array *a = (Array*)sysmem_newptrclear(sizeof(Array))
   a->elemSize = elemSize;
   a->len      = nelems;
   a->cap      = nelems;
   if (nelems > 0) {
      a->data = (char*)sysmem_newptrclear(nelems*elemSize); 
   } 
   return a;
}

void Array_clear(Array *arr) {
   a->len = 0;
}

int Array_len(Array *arr) {
   return arr->len;
}

void Array_mayGrow(Array *arr, int increment) {
   if (arr->len + increment >= arr->cap) {
      int requiredBytes = (arr->len + increment)*arr->elemSize;
      int dblCurrBytes  = 2*arr->cap*arr->elemSize;
      int szBytes       = dblCurrBytes < requiredBytes ? dblCurrBytes : requiredBytes;
      arr->data         = (char*)sysmem_resizeptrclear(arr->data, szBytes);
   }
}

#define Array_at(arr, index) ((arr)->data + index*(arr)->elemSize)

#define Array_getCheck(arr_in, index_in, err) do {\
   Array *a   = (arr_in);\
   int index  = (index_in);\
   if (index < 0 || index >= a->len) {\
      Array_formatIndexError((err), index, 0, a->len);\
      return NULL;\
   }\
while (0)

#define Array_setCheck(arr_in, index_in, err) do {\
   Array *a   = (arr_in);\
   int index  = (index_in);\
   if (index < 0 || index >= a->len) {\
      Array_formatIndexError((err), index, 0, a->len);\
      return;\
   }\
while (0)

char *Array_get(Array *arr, int index) {
   return (arr->data + index*arr->elemSize);
}

#define Array_popNCheck(arr_in, N_in, err) do {\
   Array *a = (arr_in);\
   int N    = (N_in);\
   if (N < 1 || N >= a->len) {\
      Array_formatIndexError((err), 0, N, a->len);\
      return;\
   }\
while (0)

void Array_popN(Array *arr, int N) {
   char *end   = arr->data + arr->len*arr->elemSize;
   arr->len   -= N;
   char *start = arr->data + (arr->len-1)*arr->elemSize;
   if (arr->deleter != NULL) {
      for (char *p = start; p != end; p += arr->elemSize) {
            arr->deleter(p);
      }
   }
   memset(start, 0, (size_t)(end-start));
} 

char *Array_pushN(Array *arr, int N) {
   Array_mayGrow(arr, N);
   char *pushed = arr->data + arr->len*arr->elemSize;
   arr->len    += N;
   return pushed;
}

#define Array_insertNCheck(arr_in, index_in, N_in, err) do {\
   Array *a   = (arr_in);\
   int index  = (index_in);\
   int N      = (N_in);\
   if (index < 0 || N < 1 || index >= a->len) {\
      Array_formatIndexError((err), index, N, a->len);\
      return NULL;\
   }\
while (0)

char *Array_insertN(Array *arr, int index, int N) {
   Array_mayGrow(arr, N, arr->elemSize);
   char *subStart  = arr->data + index*arr->elemSize;
   char *subEnd    = arr->data + (index+N)*arr->elemSize;
   char *arrayEnd  = arr->data + arr->len*arr->elemSize;
   arr->len       += N;
   
   memmove(subEnd, subStart, (size_t)(arrayEnd-subStart));
   memset(subStart, 0,      (size_t)(subEnd-subStart));
   return src;
}

#define Array_removeNCheck(arr_in, index_in, N_in, err) do {\
   Array *a   = (arr_in);\
   int index  = (index_in);\
   int N      = (N_in);\
   if (index < 0 || N < 1 || (index + N) >= arr->len || N >= arr->len) {\
      Array_formatIndexError((err), index, N, a->len);\
      return;\
   }\
while (0)

void Array_removeN(Array *arr, int index, int N) {
   char *subStart   = arr->data + index*arr->elemSize;
   char *subEnd     = arr->data + (index+N)*arr->elemSize;
   arr->len        -= N;
   char *arrayStart = arr->data + (arr->len-N)*arr->elemSize; 
   char *arrayEnd   = arr->data + arr->len*arr->elemSize;
   
   memmove(subStart, subEnd, (size_t)(arrayEnd-subEnd));
   memset(arrayStart, 0,     (size_t)(arrayEnd-arrayStart))
   return;
}

void Array_fit(Array *arr) {
   int szBytes       = arr->len*arr->elemSize;
   arr->data         = (char*)sysmem_resizeptrclear(arr->data, szBytes);
   arr->cap          = arr->len;
}

typedef struct {} Foo;

typedef struct FooArr_t FooArr;
struct FooArr_t {Array a;};

FooArr *FooArr_new(int nelems) {
   Array *a = Array_new(nelems, sizeof(Foo));
   return (FooArr*)a;
}

Foo *FooArr_data(FooArr *a) {
   return FooArr_get(a, 0);
}

Foo *FooArr_get(FooArr *a, int index) {
   return (Foo*)Array_get((Array*)a, index, sizeof(Foo));
}

void FooArr_set(FooArr *a, int index, Foo value) {
   *FooArr_get(a, index) = value;
}

int FooArr_len(FooArr *a) {
   return Array_len((Array*)a);
}

Foo *FooArr_push(FooArr *a) {
   return (Foo*)Array_pushN((Array*)a, 1, sizeof(Foo));
}

Foo *FooArr_pushN(FooArr *a, int N) {
   return (Foo*)Array_pushN((Array*)a, N, sizeof(Foo));
}

Foo *FooArr_insert(FooArr *a, int index) {
   return (Foo*)Array_insert((Array*)a, index, sizeof(Foo));
}

int FooArr_remove(Array *a, int index) {
   return Array_remove((Array*)a, index, sizeof(Foo));  
}


