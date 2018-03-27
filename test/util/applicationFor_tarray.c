// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
// *** DO NOT MODIFY THIS FILE generated 03/27/2018 10:19:50 ***
struct Foo_t;
typedef struct Foo_t Foo;
struct IntArr_t;
typedef struct IntArr_t IntArr;
struct FooArr_t;
typedef struct FooArr_t FooArr;
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(char*);
   char *data;
} Array;

typedef struct ArrayFIt_t {
   Array *arr;
   int lBound;
   int uBound;

   int index;
   char *var;
} ArrayFIt;

typedef struct ArrayRIt_t {
   Array *arr;
   int lBound;
   int uBound;

   int index;
   char *var;
} ArrayRIt;


#include <stdbool.h>
#include <stdlib.h>

typedef void (*Array_clearElement)(char *);
/*
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   Array_clearElement clearer;
   char *data;
} Array;
*/
Array *Array_new(int nelems, int elemSize, Array_clearElement clearer);
void Array_init(Array *arr, int nelems, int elemSize, Array_clearElement clearer);
void Array_clear(Array *arr);
void Array_free(Array *arr);
void Array_truncate(Array *arr);
int Array_len(Array *arr);
void Array_set(Array *arr, int index, char *newElem);
void Array_popN(Array *arr, int N);
void Array_mayGrow(Array *arr, int increment);
char *Array_pushN(Array *arr, int N);
char *Array_insertN(Array *arr, int index, int N);
void Array_removeN(Array *arr, int index, int N);
void Array_fit(Array *arr);

// REMEMBER: when you specify a range of elements to operate on, always select the range as
// [start, end) : here start is the first index of the subsequence, and end is ONE-PAST the last
// index of the subsequence. With this, the number of elements in the subsequence is end-start.

#define Array_formatIndexError(err, m, n, o) Error_format((err), "Index out of range (%d, %d, %d)", (m), (n), (o))

Array *Array_new(int nelems, int elemSize, Array_clearElement clearer) {
   Array *arr = (Array*)Mem_malloc(sizeof(Array));
   Array_init(arr, nelems, elemSize, clearer);
   return arr;
}

void Array_init(Array *arr, int nelems, int elemSize, Array_clearElement clearer) {
   arr->elemSize = elemSize;
   arr->len      = nelems > 0 ? nelems : 0;
   arr->cap      = nelems > 0 ? nelems : 0;
   arr->data     = NULL;
   arr->clearer  = clearer;
   if (nelems > 0) {
      arr->data = (char*)Mem_malloc(nelems*elemSize); 
   } 
}

void Array_clear(Array *arr) {
   Array_truncate(arr);
   if (arr->cap > 0) {
      Mem_free(arr->data);
   }
   memset(arr, 0, sizeof(Array));
}

void Array_free(Array *arr) {
   Array_clear(arr);
   Mem_free(arr);
}

void Array_truncate(Array *arr) {
   if (arr->clearer != NULL) {
      char *start = arr->data;
      char *end   = arr->data + arr->len*arr->elemSize;
      for (char *p = start; p < end; p += arr->elemSize) {
         arr->clearer(p);
      }
   }
   memset(arr->data, 0, arr->len*arr->elemSize);
   arr->len = 0;
}

void Array_changeLength(Array *arr, int newLength) {
   if (newLength == arr->len) {
      return;
   } else if (newLength < arr->len) {
      if (arr->clearer != NULL) {
         char *start = arr->data + newLength*arr->elemSize;
         char *end   = arr->data + arr->len*arr->elemSize;
         for (char *p = start; p < end; p += arr->elemSize) {
            arr->clearer(p);
         }
      }
      memset(arr->data + newLength*arr->elemSize, 0, (arr->len-newLength)*arr->elemSize);
      arr->len = newLength;
      return;
   } 

   if (arr->cap < newLength) {
      Array_mayGrow(arr, newLength-arr->len);
   }
   arr->len = newLength;
}

int Array_len(Array *arr) {
   return arr->len;
}

void Array_mayGrow(Array *arr, int increment) {
   if (arr->len + increment >= arr->cap) {
      int requiredBytes = (arr->len + increment)*arr->elemSize;
      int dblCurrBytes  = 2*arr->cap*arr->elemSize;
      int szBytes       = dblCurrBytes >= requiredBytes ? dblCurrBytes : requiredBytes;
      arr->cap          = szBytes/arr->elemSize;
      arr->data         = (char*)Mem_realloc(arr->data, szBytes);
   }
}

#define Array_at(arr, index) ((arr)->data + index*(arr)->elemSize)

#define Array_getCheck(arr_in, index_in, failedReturn, err) do {\
   Array *_arr = (Array *)(arr_in);\
   int _index  = (index_in);\
   if (_index < 0 || _index >= _arr->len) {\
      Array_formatIndexError((err), _index, 0, _arr->len);\
      return failedReturn;\
   }\
} while (0)

static inline char *Array_get(Array *arr, int index) {
   return (arr->data + index*arr->elemSize);
}

#define Array_setCheck(arr_in, index_in, err) do {\
   Array *_arr   = (Array *)(arr_in);\
   int _index  = (index_in);\
   if (_index < 0 || _index >= _arr->len) {\
      Array_formatIndexError((err), _index, 0, _arr->len);\
      return;\
   }\
} while (0)

void Array_set(Array *arr, int index, char *newElem) {
   char *p = arr->data + index*arr->elemSize;
   if (arr->clearer != NULL) {
      arr->clearer(p);
   }
   memmove(p, newElem, arr->elemSize);
}


#define Array_popNCheck(arr_in, N_in, err) do {\
   Array *_arr = (Array *)(arr_in);\
   int _N    = (N_in);\
   if (_N < 1 || _N > _arr->len) {\
      Array_formatIndexError((err), 0, _N, _arr->len);\
      return;\
   }\
} while (0)

void Array_popN(Array *arr, int N) {
   char *end   = arr->data + arr->len*arr->elemSize;
   arr->len   -= N;
   char *start = arr->data + arr->len*arr->elemSize;
   if (arr->clearer != NULL) {
      for (char *p = start; p != end; p += arr->elemSize) {
            arr->clearer(p);
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
   Array *_arr   = (Array *)(arr_in);\
   int _index  = (index_in);\
   int _N      = (N_in);\
   if (_index < 0 || _N < 1 || _index > _arr->len) {\
      /*Notice that it IS legal to insert at index == a->len. This just means push onto the end of the list*/ \
      Array_formatIndexError((err), _index, _N, _arr->len);\
      return;\
   }\
} while (0)

char *Array_insertN(Array *arr, int index, int N) {
   Array_mayGrow(arr, N);
   char *subStart  = arr->data + index*arr->elemSize;
   char *subEnd    = arr->data + (index+N)*arr->elemSize;
   char *arrayEnd  = arr->data + arr->len*arr->elemSize;
   arr->len       += N;
   
   memmove(subEnd, subStart, (size_t)(arrayEnd-subStart));
   memset(subStart, 0,      (size_t)(subEnd-subStart));
   return subStart;
}

#define Array_removeNCheck(arr_in, index_in, N_in, err) do {\
   Array *_arr = (Array *)(arr_in);\
   int _index  = (index_in);\
   int _N      = (N_in);\
   if (_index < 0 || _N < 1 || (_index + _N-1) >= _arr->len) {\
      Array_formatIndexError((err), _index, _N, _arr->len);\
      return;\
   }\
} while (0)

void Array_removeN(Array *arr, int index, int N) {
   char *removeStart = arr->data + index*arr->elemSize;
   char *removeEnd   = arr->data + (index+N)*arr->elemSize;
   char *clearStart  = arr->data + (arr->len-N)*arr->elemSize; 
   char *clearEnd    = arr->data + arr->len*arr->elemSize;
   arr->len         -= N;


   if (arr->clearer != NULL) {
      for (char *p = removeStart; p < removeEnd; p += arr->elemSize) {
            arr->clearer(p);
      }
   }

   memmove(removeStart,  removeEnd, (size_t)(clearEnd-removeEnd));
   memset(clearStart,    0,         (size_t)(clearEnd-clearStart));
   return;
}

void Array_fit(Array *arr) {
   if (arr->len <= 0) {
      if (arr->cap > 0) {
         Mem_free(arr->data);
      }
      arr->data = NULL;
      arr->len  = 0;
      arr->cap  = 0;
      return;
   }

   int szBytes = arr->len*arr->elemSize;
   arr->data   = (char*)Mem_realloc(arr->data, szBytes);
   arr->cap    = arr->len;
}

int Array_elemSize(Array *arr){
   return arr->elemSize;
}

/*
typedef struct ArrayIt {
   Array *arr;
   int index;
   bool last;
   char *element;
} ArrayIt;
*/


// bool ArrayIt_next(ArrayIt *iterator) {
//    if (iterator->jump >= 0) {
//       iterator->index = iterator->jump;
//       iterator->jump  = -1;
//    }
//    if (iterator->index+1 < 0 || iterator->index+1 >= Array_len(iterator->arr)) {
//       return false;
//    }

//    iterator->index++;
//    iterator->var  = Array_get(iterator->arr, iterator->index);
//    return true;
// }

// bool ArrayIt_previous(ArrayIt *iterator) {
//    if (iterator->jump >= 0) {
//       iterator->index = iterator->jump;
//       iterator->jump  = -1;
//    }
//    if (iterator->index-1 < 0 || iterator->index-1 >= Array_len(iterator->arr)) {
//       return false;
//    }   
   
//    iterator->index--;
//    iterator->var  = Array_get(iterator->arr, iterator->index);

//    return true;
// }


bool ArrayFIt_next(ArrayFIt *iterator) {
   if (iterator->index+1 < iterator->lBound || iterator->index+1 >= iterator->uBound) {
      return false;
   }
   iterator->index++;
   iterator->var = Array_get(iterator->arr, iterator->index);
   return true;
}

bool ArrayRIt_next(ArrayRIt *iterator) {
   if (iterator->index-1 < iterator->lBound || iterator->index-1 >= iterator->uBound) {
      return false;
   }
   iterator->index--;
   iterator->var  = Array_get(iterator->arr, iterator->index);
   return true;
}


bool ArrayFIt_remove(ArrayFIt *iterator) {
   if (iterator->index < iterator->lBound || iterator->index >= iterator->uBound) {
      return false;
   }   

   int index = iterator->index;
   iterator->index--;
   iterator->var = NULL;
   iterator->uBound--;
   Array_removeN(iterator->arr, index, 1);
   return true;
}

bool ArrayRIt_remove(ArrayRIt *iterator) {
   if (iterator->index < iterator->lBound || iterator->index >= iterator->uBound) {
      return false;
   }   

   iterator->var = NULL;
   Array_removeN(iterator->arr, iterator->index, 1);
   return true;
}

typedef int (*Array_compare)(const void *left, const void *right);

typedef struct ArraySlice_t {
   int len;
   char *data;
   int index;
   char *var;
} ArraySlice;

// This code is based on bsearch pulled from the linux kernal
int Array_binSearchWithInsertMulti(Array *arr, char *key, int *insert, Array_compare comparer, char **lowerBound, char **upperBound) {  
   char *base  = arr->data;
   size_t num  = arr->len;
   size_t size = arr->elemSize;
   char *high  = NULL;
   char *pivot = NULL;
   // If there are no elements in the incomming array, and lowerBound != NULL, this makes sure that the insert index is set.
   int result = 1; 
   while (num > 0) {
      pivot  = base + (num >> 1) * size;
      result = comparer((void*)key, (void*)pivot);

      if (result == 0) {
         if (lowerBound != NULL) {
            break;
         }
         // Found a solution, find the right most element if this is a multi
         char *end = arr->data + arr->len*size;
         while (pivot+size < end && comparer(key, pivot+size) == 0) {
            pivot += size;
         }
         return (int)(((size_t)(pivot-arr->data))/size);
      }

      if (result > 0) {
         // key > elt: push base to 1 element greater than pivot
         base = pivot + size;
         num--;
      } else {
         // key < elt: we set high to point to the smallest element which compares key < elt
         high = pivot;
      }

      num >>= 1;
   }

   if (result != 0 || lowerBound == NULL) {
      if (high == NULL) {
         // high == NULL implies that NO elements in the array where such that key <= elt, which implies that you should insert at the
         // end of the array.
         *insert = arr->len;
      } else {
         *insert = (int)(((size_t)(high-arr->data))/size);
      }
      return -1;
   }

   // Linear search to find the bounds of the multi
   char *lower = pivot;
   char *upper = pivot;
   char *start = arr->data;
   char *end   = arr->data + arr->len*size;
   while (lower-size >= start && comparer(key, lower-size) == 0) {
      lower -= size;
   }
   while (upper+size < end && comparer(key, upper+size) == 0) {
      upper += size;
   }

   // Remember that lowerBound and upperBound can be NULL
   *lowerBound = lower;
   *upperBound = upper+size; // NOTE: upperBound points 1 PAST the end of the sequence
   
   return (int)(((size_t)(upper-arr->data))/size);
}


void Array_sort(Array *arr, Array_compare comparer) {
   qsort(arr->data, arr->len, arr->elemSize, (void*)comparer);
}

void Array_binInsert(Array *arr, char *elem, Array_compare comparer, bool append) {
   int insert = -1;
   int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, NULL, NULL);
   if (index < 0) {
      Error_declare(err);
      char *d = Array_insertN(arr, insert, 1);
      memmove(d, elem, arr->elemSize);
      Error_clear(err);
      return;
   }

   char *target = NULL;
   if (append) {
      target = Array_insertN(arr, index+1, 1);
   } else {
      target = Array_get(arr, index); 
      if (arr->clearer) {
         arr->clearer(target);
      }
   }
   memmove(target, elem, arr->elemSize);
   return;
}

void Array_binRemove(Array *arr, char *elem, Array_compare comparer, bool all) {
   int insert = -1;
   char *lower = NULL;
   char *upper = NULL;
   int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, &lower, &upper);
   if (index < 0) {
      return;
   }
   if (all) {
      size_t N = (size_t)(upper-lower)/arr->elemSize;
      size_t ind = (lower-arr->data)/arr->elemSize;
      Array_removeN(arr, ind, N);
   } else {
      Array_removeN(arr, index, 1);
   }
}

char *Array_binSearch(Array *arr, char *elem, Array_compare comparer, ArraySlice *slice) {
   int insert = -1;
   char *lower = NULL;
   char *upper = NULL;
   int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, &lower, &upper);
   if (index < 0) {
      return NULL;
   }
   if (slice != NULL) {
      slice->index = 0;
      slice->var   = upper;
      slice->len   = (int)(upper-lower)/arr->elemSize;
      slice->data  = lower;
   }
   return lower;
}
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

typedef struct FooArrFIt_t {
   FooArr *arr;
   int lBound;
   int uBound;

   int index;
   Foo *var;
} FooArrFIt;

typedef struct FooArrRIt_t {
   FooArr *arr;
   int lBound;
   int uBound;

   int index;
   Foo *var;
} FooArrRIt;

typedef struct IntArr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(int*);
   int *data;
} IntArr;

typedef struct IntArrFIt_t {
   IntArr *arr;
   int lBound;
   int uBound;

   int index;
   int *var;
} IntArrFIt;

typedef struct IntArrRIt_t {
   IntArr *arr;
   int lBound;
   int uBound;

   int index;
   int *var;
} IntArrRIt;

const char *Interface_toString(int itype);
typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typeName) ((typeName*)&Undefined_instance)
#define Foo_newUninitialized() ((Foo*)sysmem_newptrclear(sizeof(Foo)))        
static inline int Foo_i(Foo *self){return self->i;}
static inline void Foo_setI(Foo *self, int value){self->i = value;}
static inline double Foo_d(Foo *self){return self->d;}
static inline void Foo_setD(Foo *self, double value){self->d = value;}
static inline void IntArr_changeLength(IntArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void IntArr_clear(IntArr *arr) {
    Array_clear((Array*)arr);
    IntArr zero = {0};
    *arr = zero;
}

#define IntArr_each(it, arr) for (int* it = arr->data; it < arr->data + arr->len; it++)

static inline void IntArr_fit(IntArr *arr) {
    Array_fit((Array*)arr);
}

#define IntArr_foreach(var, arr)  for (IntArrFIt_declare(var, arr); IntArrFIt_next(&var); )            

static inline void IntArr_free(IntArr *arr) {
    Array_free((Array*)arr);
}

static inline int IntArr_get(IntArr *arr, int index, Error *err) {
    int v = 0;
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline int *IntArr_getp(IntArr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (int *)Array_get((Array*)arr, index);
}

static inline void IntArr_init(IntArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_insert(IntArr *arr, int index, int elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IntArr_insertp(IntArr *arr, int index, int *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int IntArr_last(IntArr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int IntArr_len(IntArr *arr) {
    return Array_len((Array*)arr);
}

#define IntArr_loop(var) while (IntArrFIt_next(&var)) 

static inline IntArr *IntArr_new(int nelems) {
    return (IntArr*)Array_new(nelems, sizeof(int), (Array_clearElement)NULL);
}

static inline void IntArr_pop(IntArr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IntArr_push(IntArr *arr, int elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void IntArr_pushp(IntArr *arr, int *elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define IntArr_reach(it, arr) for (int* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void IntArr_remove(IntArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IntArr_removeN(IntArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define IntArr_rforeach(var, arr)  for (IntArrRIt_declare(var, arr); IntArrRIt_next(&var); )            

#define IntArr_rloop(var) while (IntArrRIt_next(&var))             

static inline void IntArr_set(IntArr *arr, int index, int elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IntArr_setp(IntArr *arr, int index, int *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IntArr_truncate(IntArr *arr) {
    Array_truncate((Array*)arr);
}

#define IntArrFIt_declare(var, arr)  IntArrFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool IntArrFIt_next(IntArrFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool IntArrFIt_remove(IntArrFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

#define IntArrRIt_declare(var, arr)  IntArrRIt var = {arr, 0, (arr)->len, (arr)->len, NULL}

static inline bool IntArrRIt_next(IntArrRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool IntArrRIt_remove(IntArrRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void FooArr_changeLength(FooArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void FooArr_clear(FooArr *arr) {
    Array_clear((Array*)arr);
    FooArr zero = {0};
    *arr = zero;
}

#define FooArr_declareSlice(name) FooArrSlice name = {0}            

#define FooArr_each(it, arr) for (Foo* it = arr->data; it < arr->data + arr->len; it++)

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

#define FooArr_foreach(var, arr)  for (FooArrFIt_declare(var, arr); FooArrFIt_next(&var); )            

static inline void FooArr_free(FooArr *arr) {
    Array_free((Array*)arr);
}

static inline Foo FooArr_get(FooArr *arr, int index, Error *err) {
    Foo v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Foo *FooArr_getp(FooArr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Foo *)Array_get((Array*)arr, index);
}

static inline void FooArr_init(FooArr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_insert(FooArr *arr, int index, Foo elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo *p = (Foo *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void FooArr_insertp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Foo *p = (Foo *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int FooArr_last(FooArr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int FooArr_len(FooArr *arr) {
    return Array_len((Array*)arr);
}

#define FooArr_loop(var) while (FooArrFIt_next(&var)) 

static inline FooArr *FooArr_new(int nelems) {
    return (FooArr*)Array_new(nelems, sizeof(Foo), (Array_clearElement)record_clearer);
}

static inline void FooArr_pop(FooArr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void FooArr_push(FooArr *arr, Foo elem) {
    Foo *p = (Foo *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void FooArr_pushp(FooArr *arr, Foo *elem) {
    Foo *p = (Foo *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define FooArr_reach(it, arr) for (Foo* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void FooArr_remove(FooArr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void FooArr_removeN(FooArr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define FooArr_rforeach(var, arr)  for (FooArrRIt_declare(var, arr); FooArrRIt_next(&var); )            

#define FooArr_rloop(var) while (FooArrRIt_next(&var))             

#define FooArr_rsliceForeach(slice) for (slice.index=slice.len-1, slice.var = slice.data + slice.index*sizeof(Foo); \\
                                               slice.index >= 0; slice.index--, slice.var--)

static inline void FooArr_set(FooArr *arr, int index, Foo elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FooArr_setp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

#define FooArr_sliceEmpty(slice) (slice.data == NULL)

#define FooArr_sliceForeach(slice) for (slice.index=0, slice.var=slice.data; slice.index < slice.len; slice.index++, slice.var++)

static inline void FooArr_truncate(FooArr *arr) {
    Array_truncate((Array*)arr);
}

#define FooArrFIt_declare(var, arr)  FooArrFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool FooArrFIt_next(FooArrFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool FooArrFIt_remove(FooArrFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

#define FooArrRIt_declare(var, arr)  FooArrRIt var = {arr, 0, (arr)->len, (arr)->len, NULL}

static inline bool FooArrRIt_next(FooArrRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool FooArrRIt_remove(FooArrRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void FooArr_binInsert(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void FooArr_binRemove(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Foo *FooArr_binSearch(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline void FooArr_sort(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void FooArr_binRemoveBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Foo *FooArr_binSearchBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    return (Foo *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline void FooArr_sortBoth(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void FooArr_binRemoveMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline FooArrSlice FooArr_binSearchMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void FooArr_binInsertBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void FooArr_binRemoveBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline FooArrSlice FooArr_binSearchBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    FooArrSlice slice = {0};
    Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArraySlice*)&slice);
    return slice;
}

static inline void FooArr_sortBothMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

const char *Interface_toString(int itype)
{
    switch(itype) {
        case Undefined_itype:
            return "Undefined";
    }
    return "Unknown";
}
#line 23 "./for_tarray.in.c"

#line 31 "./for_tarray.in.c"
