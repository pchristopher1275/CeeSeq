
#include <stdbool.h>
#include <stdlib.h>
#include "mem.c"

typedef void (*Array_clearElement)(void *);
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   Array_clearElement clearer;
   char *data;
} Array;
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

// typedef struct ArrayIter {
//    Array *arr;
//    int index;
//    char *element;
// } ArrayIter;

// ArrayIter ArrayIter_create(Array *arr) {
//    ArrayIter iter = {arr, 0, NULL};
//    return iter;
// }



// bool ArrayIter_continue(ArrayIter *iterator) {
//    if (iterator->index < 0 || iterator->index >= Array_len(iterator->arr)) {
//       return false;
//    }
//    iterator->elem = Array_get(iterator->arr, iterator->index);
//    iterator->index++;
//    return true;
// }

// #define ArrayIter_declare(name) ArrayIter _##name = {0}; ArrayIter *name = &_##name


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
   arr->len      = nelems;
   arr->cap      = nelems;
   arr->clearer  = clearer;
   if (nelems > 0) {
      arr->data = (char*)Mem_malloc(nelems*elemSize); 
   } 
}

void Array_clear(Array *arr) {
   Array_truncate(arr);
   Mem_free(arr->data);
}

void Array_free(Array *arr) {
   Array_clear(arr);
   Mem_free(arr);
}

/*
bool Array_nextIterator(Array *arr, ArrayIter *iterator, char **element) {
   if (iterator->index >= Array_len(arr) || iterator->index < 0) {
      *element = NULL;
      return false;
   }
   *element = Array_get(arr, iterator->index);
   iterator->index++;
   return true;
}

// insert element before last next element
bool Array_insertIterator(Array *arr, ArrayIter *iterator, char *element) {
   if (iterator->index > Array_len(arr) || iterator->index < 1) {
      return false;
   }
   //char *Array_insertN(Array *arr, int index, int N) 
   char *p = Array_insertN(arr, iterator->index-1, 1);
   memmove(p, element, arr->elemSize);
   iterator->index++;// by doing this, the next time next is called, you'll look at the same element reguardless of if you insert or not
   return true; 
}

bool Array_removeIterator(Array *arr, ArrayIter *iterator) {
   if (iterator->index > Array_len(arr) || iterator->index < 1) {
      return false;
   }
   //void Array_removeN(Array *arr, int index, int N) 
   Array_removeN(arr, iteator->index, 1);
   iterator->index--;
   return true;
}
*/


void Array_truncate(Array *arr) {
   if (arr->clearer != NULL) {
      char *start = arr->data;
      char *end   = arr->data + arr->len;
      for (char *p = start; p != end; p += arr->elemSize) {
         arr->clearer(p);
      }
   }
   arr->len = 0;
}

int Array_len(Array *arr) {
   return arr->len;
}

void Array_mayGrow(Array *arr, int increment) {
   if (arr->len + increment >= arr->cap) {
      int requiredBytes = (arr->len + increment)*arr->elemSize;
      int dblCurrBytes  = 2*arr->cap*arr->elemSize;
      int szBytes       = dblCurrBytes < requiredBytes ? dblCurrBytes : requiredBytes;
      arr->data         = (char*)Mem_realloc(arr->data, szBytes);
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

char *Array_get(Array *arr, int index) {
   return (arr->data + index*arr->elemSize);
}

#define Array_setCheck(arr_in, index_in, err) do {\
   Array *a   = (arr_in);\
   int index  = (index_in);\
   if (index < 0 || index >= a->len) {\
      Array_formatIndexError((err), index, 0, a->len);\
      return;\
   }\
while (0)

void Array_set(Array *arr, int index, char *newElem) {
   char *p = arr->data + index*arr->elemSize;
   if (arr->clearer != NULL) {
      arr->clearer(p);
   }
   memmove(p, newElem, arr->elemSize);
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
   Array *a   = (arr_in);\
   int index  = (index_in);\
   int N      = (N_in);\
   if (index < 0 || N < 1 || index > a->len) {\
      /*Notice that it IS legal to insert at index == a->len. This just means push onto the end of the list*/ \
      Array_formatIndexError((err), index, N, a->len);\
      return NULL;\
   }\
while (0)

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
   
   if (arr->clearer != NULL) {
      for (char *p = subStart; p != subEnd; p += arr->elemSize) {
            arr->clearer(p);
      }
   }

   memmove(subStart, subEnd, (size_t)(arrayEnd-subEnd));
   memset(arrayStart, 0,     (size_t)(arrayEnd-arrayStart));
   return;
}

void Array_fit(Array *arr) {
   int szBytes       = arr->len*arr->elemSize;
   arr->data         = (char*)Mem_realloc(arr->data, szBytes);
   arr->cap          = arr->len;
}

