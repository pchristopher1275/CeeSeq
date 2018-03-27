
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
