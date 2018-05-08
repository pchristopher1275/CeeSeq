
#include <stdbool.h>
#include <stdlib.h>

typedef void (*Array_refModifier)(char *);
typedef int (*Array_compare)(const char *left, const char *right);

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
#define Array_len(arr) (arr)->len
#define Array_at(arr, index, elemSize) ((arr)->data + (index)*(elemSize))

Array *Array_new(int itype) {
    Array *arr = (Array*)Mem_calloc(sizeof(Array));
    arr->itype    = itype;
    arr->refCount = 1;
    arr->len      = 0;
    arr->cap      = 0;
    arr->data     = NULL;
    return arr;
}

void Array_incRef(Array *arr)
{
    arr->refCount++;
}

void Array_decRef(Array *arr, Array_refModifier decRef, int elemSize)
{
    arr->refCount--;
    if (arr->refCount <= 0) {
        if (decRef) {
            for (char *p = arr->data; p < arr->data + elemSize*arr->len; p += elemSize) {
                char **d = (char**)p;
                decRef(*d);
            }
        }
        memset(arr->data, 0, arr->len*elemSize);
        if (arr->cap > 0) {
            Mem_free(arr->data);
        }
        memset(arr, 0, sizeof(Array));
        Mem_free(arr); 
    }
}

void Array_truncate(Array *arr, int newLength, Array_refModifier decRef, int elemSize) {
   if (newLength < arr->len) {
        if (decRef) {
            for (int i = newLength; i < Array_len(arr); i++) {
                char *p  = Array_at(arr, i, elemSize);
                char **d = (char**)p;
                decRef(*d);
            }
        }
        memset(arr->data + newLength*elemSize, 0, (arr->len-newLength)*elemSize);
        arr->len = newLength;
   }
   return;
}

void Array_mayGrow(Array *arr, int increment, int elemSize) {
    if (arr->len + increment >= arr->cap) {
        int requiredBytes = (arr->len + increment)*elemSize;
        int dblCurrBytes  = 2*arr->cap*elemSize;
        int szBytes       = dblCurrBytes >= requiredBytes ? dblCurrBytes : requiredBytes;
        int oldCap        = arr->cap;
        arr->cap          = szBytes/elemSize;
        arr->data         = (char*)Mem_realloc(arr->data, szBytes);
        memset(arr->data + oldCap*elemSize, 0, (arr->cap-oldCap)*elemSize);
    }
}

#define Array_getCheck(arr_in, index_in, failedReturn, err) do {\
   Array *_arr = (Array *)(arr_in);\
   int _index  = (index_in);\
   if (_index < 0 || _index >= _arr->len) {\
      Array_formatIndexError((err), _index, 0, _arr->len);\
      return failedReturn;\
   }\
} while (0)

static inline char *Array_get(Array *arr, int index, int elemSize) {
   return Array_at(arr, index, elemSize);
}

#define Array_setCheck(arr_in, index_in, err) do {\
   Array *_arr   = (Array *)(arr_in);\
   int _index  = (index_in);\
   if (_index < 0 || _index >= _arr->len) {\
      Array_formatIndexError((err), _index, 0, _arr->len);\
      return;\
   }\
} while (0)

void Array_set(Array *arr, int index, char *newElem, Array_refModifier incRef, Array_refModifier decRef, int elemSize) {
    char *p = Array_at(arr, index, elemSize);
    char *toDec = decRef ? *((char**)p) : NULL; 
    memmove(p, newElem, elemSize);

    // We do the incRef first to handle the case when the new object is the same object as the old object.
    if (incRef) {
        char **d = (char**)p;
        incRef(*d);
    }
    if (decRef) {
        decRef(toDec);
    }
}


#define Array_popNCheck(arr_in, N_in, err) do {\
   Array *_arr = (Array *)(arr_in);\
   int _N    = (N_in);\
   if (_N < 1 || _N > _arr->len) {\
      Array_formatIndexError((err), 0, _N, _arr->len);\
      return;\
   }\
} while (0)

void Array_popN(Array *arr, int N, char *output, Array_refModifier decRef, int elemSize) {
    char *end   = Array_at(arr, arr->len, elemSize);
    arr->len   -= N;
    char *start = Array_at(arr, arr->len, elemSize);
    if (decRef) {
        for (char *p = start; p <= end; p += elemSize) {
            char **d = (char**)p;
            decRef(d);
        }
    }
    if (output) {
        memmove(output, start, (size_t)(end-start));
    }
    memset(start, 0, (size_t)(end-start));
} 

void Array_pushN(Array *arr, int N, char *input, Array_refModifier incRef, int elemSize) {
    Array_mayGrow(arr, N);
    char *pushed = Array_at(arr, arr->len, elemSize);
    memmove(pushed, input, N*elemSize);
    arr->len += N;
    if (incRef) {
        for (char *p = pushed; p < arr->data + elemSize*arr->len; p += elemSize) {
            char **d = (char**)p;
            incRef(*d);
        }
    }
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

char *Array_insertN(Array *arr, int index, int N, char *input, Array_refModifier incRef, int elemSize) {
    Array_mayGrow(arr, N);
    char *subStart  = Array_at(arr, index, elemSize);
    char *subEnd    = Array_at(arr, index+N, elemSize);
    char *arrayEnd  = Array_at(arr, arr->len, elemSize);
    arr->len       += N;

    memmove(subEnd, subStart, (size_t)(arrayEnd-subStart));
    memmove(subStart, input, (size_t)(subEnd-subStart));
    if (incRef) {
        for (char *p = subStart; p < subEnd; p += elemSize) {
            char **d = (char**)p;
            incRef(*d);
        }
    }
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

void Array_removeN(Array *arr, int index, int N, Array_refModifier decRef, int elemSize) {
   char *removeStart = Array_at(arr, index, elemSize); 
   char *removeEnd   = Array_at(arr, index+N, elemSize);
   char *clearStart  = Array_at(arr, arr->len-N, elemSize);
   char *clearEnd    = Array_at(arr, arr->len, elemSize);
   arr->len         -= N;

   if (decRef) {
        for (char *p = removeStart; p < removeEnd; p += elemSize) {
            char **d = (char**)p;
            decRef(*d);
        }
    }

    memmove(removeStart,  removeEnd, (size_t)(clearEnd-removeEnd));
    memset(clearStart,    0,         (size_t)(clearEnd-clearStart));
    return;
}

void Array_fit(Array *arr, int elemSize) {
    if (arr->len <= 0) {
        if (arr->cap > 0) {
            Mem_free(arr->data);
        }
        arr->data = NULL;
        arr->len  = 0;
        arr->cap  = 0;
        return;
    }

    int szBytes = arr->len*elemSize;
    arr->data   = (char*)Mem_realloc(arr->data, szBytes);
    arr->cap    = arr->len;
}

bool ArrayFIt_next(ArrayFIt *iterator, Array_refModifier decRef, int elemSize) {
    if (iterator->remove && iterator->index < Array_len(iterator->arr) && iterator->index >= 0) {
        Array_removeN(iterator->arr, iterator->index, 1, decRef);
        iterator->index--;
        iterator->remove = false;
    }

    if (iterator->index+1 >= Array_len(iterator->arr) || iterator->index+1 < 0) {
      return false;
    }
    
    iterator->index++;
    if (decRef) {
        char **p      = (char**)Array_at(iterator->arr, iterator->index, elemSize);
        iterator->var = *p;
    } else {
        iterator->var = Array_at(iterator->arr, iterator->index, elemSize);
    }
    return true;
}

bool ArrayRIt_next(ArrayRIt *iterator, Array_refModifier decRef, int elemSize) {
    if (iterator->remove && iterator->index < Array_len(iterator->arr) && iterator->index >= 0) {
        Array_removeN(iterator->arr, iterator->index, 1, decRef, elemSize);
        iterator->remove = false;
    }

    if (iterator->index-1 >= Array_len(iterator->arr) || iterator->index-1 < 0) {
        return false;
    }

    iterator->index--;
    if (decRef) {
        char **p      = (char**)Array_at(iterator->arr, iterator->index, elemSize);
        iterator->var = *p;
    } else {
        iterator->var = Array_get(iterator->arr, iterator->index);
    }

    return true;
}

// This code is based on bsearch pulled from the linux kernal
int Array_binSearchWithInsertMulti(Array *arr, char *key, int *insert, Array_compare comparer, char **lowerBound, char **upperBound, int elemSize) {  
   char *base  = arr->data;
   size_t num  = arr->len;
   size_t size = (size_t)elemSize;
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


void Array_sort(Array *arr, Array_compare comparer, int elemSize) {
    qsort(arr->data, arr->len, elemSize, (void*)comparer);
}

void Array_binInsert(Array *arr, char *elem, Array_compare comparer, Array_refModifier incRef, Array_refModifier decRef, int elemSize) {
    int insert = -1;
    int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, NULL, NULL, elemSize);
    if (index < 0) {
      Array_insertN(arr, insert, 1, elem, incRef, elemSize);
      return;
    }

    char *target = Array_at(arr, index, elemSize);
    char *toDec = decRef ? *((char**)target) : NULL; 
    memmove(target, elem, elemSize);
    // incRef first to handle the case when the new and old object are the same reference.
    if (incRef) {
        char **d = (char**)target;
        incRef(*d);
    }
    if (decRef) {
        decRef(toDec);
    }

    return;
}

void Array_binRemove(Array *arr, char *elem, Array_compare comparer, Array_refModifier decRef, int elemSize) {
    int insert = -1;
    char *lower = NULL;
    char *upper = NULL;
    int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, &lower, &upper, elemSize);
    if (index < 0) {
        return;
    }
    
    Array_removeN(arr, index, 1, decRef, elemSize);
}

char *Array_binSearch(Array *arr, char *elem, Array_compare comparer, int elemSize) {
   int insert = -1;
   char *lower = NULL;
   char *upper = NULL;
   int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, &lower, &upper, elemSize);
   if (index < 0) {
      return NULL;
   }
   
   return lower;
}

//
// Priority queue. This code is ported from https://golang.org/src/container/heap/heap.go
//

#define PQ_LESS(i, j) ((comparer(Array_at(arr->data, i, elemSize), Array_at(arr->data, j, elemSize)) < 0)
#define PQ_SWAP(i, j) do {\
    memmove(Array_at(arr, arr->len, elemSize), Array_at(arr, i, elemSize),        elemSize);\
    memmove(Array_at(arr, i, elemSize),        Array_at(arr, j, elemSize),        elemSize);\
    memmove(Array_at(arr, j, elemSize),        Array_at(arr, arr->len, elemSize), elemSize);\
} while (0)


/*
func up(h Interface, j int) {
   for {
      i := (j - 1) / 2 // parent
      if i == j || !h.Less(j, i) {
         break
      }
      h.Swap(i, j)
      j = i
   }
}
*/

void Array_pqUp(Array *arr, int j, Array_compare comparer, int elemSize) 
{
   Array_mayGrow(arr, 1); // use the first unused element of the array as the swap space
   for (;;) {
      int i = (j-1)/2; // parent
      if (i == j || !PQ_LESS(j, i)) {
         break;
      }
      PQ_SWAP(i, j);
      j = i;
   }
}

/*
func down(h Interface, i0, n int) bool {
   i := i0
   for {
      j1 := 2*i + 1
      if j1 >= n || j1 < 0 { // j1 < 0 after int overflow
         break
      }
      j := j1 // left child
      if j2 := j1 + 1; j2 < n && h.Less(j2, j1) {
         j = j2 // = 2*i + 2  // right child
      }
      if !h.Less(j, i) {
         break
      }
      h.Swap(i, j)
      i = j
   }
   return i > i0
}
*/
bool Array_pqDown(Array *arr, int i0, int n, Array_compare comparer, int elemSize) {
    Array_mayGrow(arr, 1);
    int i = i0;
    for (;;) {
        int j1 = 2*i + 1; // left child
        if (j1 >= n || j1 < 0) { // j1 < 0 after int overflow
            break; 
        }
        int j = j1; 
        int j2 = j1 + 1; // right child
        if (j2 < n && PQ_LESS(j2, j1)) {
            j = j2;
        }
        if (!PQ_LESS(j, i)) {
            break;
        }
        PQ_SWAP(i, j);
        i = j;
    }
    return i > i0;
}

/*
func Init(h Interface) {
   // heapify
   n := h.Len()
   for i := n/2 - 1; i >= 0; i-- {
      down(h, i, n)
   }
}
*/

void Array_pqSort(Array *arr, Array_compare comparer, int elemSize) 
{
    int n = Array_len(arr);
    for (int i = n/2-1; i >= 0; i--) {
        Array_pqDown(arr, i, n, comparer, elemSize);
    }
}

/*
func Push(h Interface, x interface{}) {
   h.Push(x)
   up(h, h.Len()-1)
}
*/

void Array_pqPush(Array *arr, char *elem, Array_compare comparer, Array_refModifier incRef, int elemSize)
{
    Array_pushN(arr, 1, elem, incRef, elemSize);
    Array_pqUp(arr, Array_len(arr)-1, comparer, elemSize);
}

/*
func Pop(h Interface) interface{} {
   n := h.Len() - 1
   h.Swap(0, n)
   down(h, 0, n)
   return h.Pop()
}
*/

bool Array_pqPop(Array *arr, char *elem, Array_compare comparer, Array_refModifier decRef, int elemSize) 
{
    if (Array_len(arr) <= 0) {
        return false;
    }

    if (elem != NULL) {
        memmove(elem, arr->data, elemSize);
    }
    if (decRef) {
        char **d = (char**)arr->data;
        decRef(*d);
        *d = NULL;
    }

    int n = Array_len(arr)-1;
    PQ_SWAP(0, n);
    Array_pqDown(arr, 0, n, comparer, elemSize);
    arr->len--;
    return true;    
}

char *Array_pqPeek(Array *arr) {
   if (Array_len(arr) > 0) {
      return arr->data;
   }
   return NULL;
}

#undef PQ_LESS
#undef PQ_SWAP
