// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
// *** DO NOT MODIFY THIS FILE generated 05/16/2018 14:33:48 ***
const bool Coverage_activated = false;
const char **Coverage_array   = NULL;
struct Array_t;
typedef struct Array_t Array;
typedef struct Array_t {
   int itype;
   int refCount;
   int len;
   int cap;
   char **data;
};

#include <stdbool.h>
#include <stdlib.h>

typedef void (*Array_refModifier)(char *);
typedef int (*Array_compare)(const char *left, const char *right);
Array *Array_new(int itype);
void Array_incRef(Array *arr);
void Array_decRef(Array *arr, Array_refModifier decRef, int elemSize);
void Array_truncate(Array *arr, int newLength, Array_refModifier decRef, int elemSize);
void Array_mayGrow(Array *arr, int increment, int elemSize);
static inline char *Array_get(Array *arr, int index, int elemSize);
void Array_set(Array *arr, int index, char *newElem, Array_refModifier incRef, Array_refModifier decRef, int elemSize);
void Array_popN(Array *arr, int N, char *output, Array_refModifier decRef, int elemSize);
void Array_pushN(Array *arr, int N, char *input, Array_refModifier incRef, int elemSize);
char *Array_insertN(Array *arr, int index, int N, char *input, Array_refModifier incRef, int elemSize);
void Array_removeN(Array *arr, int index, int N, Array_refModifier decRef, int elemSize);
void Array_fit(Array *arr, int elemSize);
bool ArrayFIt_next(ArrayFIt *iterator, Array_refModifier decRef, int elemSize);
bool ArrayRIt_next(ArrayRIt *iterator, Array_refModifier decRef, int elemSize);
int Array_binSearchWithInsertMulti(Array *arr, char *key, int *insert, Array_compare comparer, char **lowerBound, char **upperBound, int elemSize);
void Array_sort(Array *arr, Array_compare comparer, int elemSize);
void Array_binInsert(Array *arr, char *elem, Array_compare comparer, Array_refModifier incRef, Array_refModifier decRef, int elemSize);
void Array_binRemove(Array *arr, char *elem, Array_compare comparer, Array_refModifier decRef, int elemSize);
char *Array_binSearch(Array *arr, char *elem, Array_compare comparer, int elemSize);
void Array_pqUp(Array *arr, int j, Array_compare comparer, int elemSize);
bool Array_pqDown(Array *arr, int i0, int n, Array_compare comparer, int elemSize);
void Array_pqSort(Array *arr, Array_compare comparer, int elemSize);
void Array_pqPush(Array *arr, char *elem, Array_compare comparer, Array_refModifier incRef, int elemSize);
bool Array_pqPop(Array *arr, char *elem, Array_compare comparer, Array_refModifier decRef, int elemSize);
char *Array_pqPeek(Array *arr);


// REMEMBER: when you specify a range of elements to operate on, always select the range as
// [start, end) : here start is the first index of the subsequence, and end is ONE-PAST the last
// index of the subsequence. With this, the number of elements in the subsequence is end-start.

#define Array_formatIndexError(err, m, n, o) Error_format((err), "Index out of range (%d, %d, %d)", (m), (n), (o))
#define Array_len(arr) (arr)->len
#define Array_ptr(arr, index, elemSize) ((arr)->data + (index)*(elemSize))

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
            for (char *p = arr->data; p < Array_ptr(arr, arr->len, elemSize); p += elemSize) {
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
                char *p  = Array_ptr(arr, i, elemSize);
                char **d = (char**)p;
                decRef(*d);
            }
        }
        memset(arr->data + newLength*elemSize, 0, (arr->len-newLength)*elemSize);
        arr->len = newLength;
   }
   return;
}

void Array_reserve(Array *arr, int newCap, int elemSize) {
    if (newCap > arr->cap) {
        Array_mayGrow(arr, newCap - arr->cap, elemSize);
    }
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
   return Array_ptr(arr, index, elemSize);
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
    char *p = Array_ptr(arr, index, elemSize);
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
    char *end   = Array_ptr(arr, arr->len, elemSize);
    arr->len   -= N;
    char *start = Array_ptr(arr, arr->len, elemSize);
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
    char *pushed = Array_ptr(arr, arr->len, elemSize);
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
    char *subStart  = Array_ptr(arr, index, elemSize);
    char *subEnd    = Array_ptr(arr, index+N, elemSize);
    char *arrayEnd  = Array_ptr(arr, arr->len, elemSize);
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
   char *removeStart = Array_ptr(arr, index, elemSize); 
   char *removeEnd   = Array_ptr(arr, index+N, elemSize);
   char *clearStart  = Array_ptr(arr, arr->len-N, elemSize);
   char *clearEnd    = Array_ptr(arr, arr->len, elemSize);
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
        Array_removeN(iterator->arr, iterator->index, 1, decRef, elemSize);
        iterator->index--;
        iterator->remove = false;
    }

    if (iterator->index+1 >= Array_len(iterator->arr) || iterator->index+1 < 0) {
      return false;
    }
    
    iterator->index++;
    if (decRef) {
        char **p      = (char**)Array_ptr(iterator->arr, iterator->index, elemSize);
        iterator->var = *p;
    } else {
        //XXX: This doesn't currently have any use case
        iterator->var = Array_ptr(iterator->arr, iterator->index, elemSize);
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
        char **p      = (char**)Array_ptr(iterator->arr, iterator->index, elemSize);
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

    char *target = Array_ptr(arr, index, elemSize);
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

bool Array_binSearch(Array *arr, char *key, char *output, Array_compare comparer, int elemSize) {
    int insert = -1;
    char *lower = NULL;
    char *upper = NULL;
    int index  = Array_binSearchWithInsertMulti(arr, key, &insert, comparer, &lower, &upper, elemSize);
    if (index < 0) {
        return false;
    }
    memmove(output, Array_ptr(arr, index, elemSize), elemSize);
    return true;
}

//
// Priority queue. This code is ported from https://golang.org/src/container/heap/heap.go
//

#define PQ_LESS(i, j) ((comparer(Array_ptr(arr->data, i, elemSize), Array_ptr(arr->data, j, elemSize)) < 0)
#define PQ_SWAP(i, j) do {\
    memmove(Array_ptr(arr, arr->len, elemSize), Array_ptr(arr, i, elemSize),        elemSize);\
    memmove(Array_ptr(arr, i, elemSize),        Array_ptr(arr, j, elemSize),        elemSize);\
    memmove(Array_ptr(arr, j, elemSize),        Array_ptr(arr, arr->len, elemSize), elemSize);\
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

bool Array_pqPop(Array *arr, char *output, Array_compare comparer, Array_refModifier decRef, int elemSize) 
{
    if (Array_len(arr) <= 0) {
        return false;
    }

    if (elem != NULL) {
        memmove(output, arr->data, elemSize);
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
struct Arguments_t;
typedef struct Arguments_t Arguments;
struct AtomAr_t;
typedef struct AtomAr_t AtomAr;
struct AtomArAr_t;
typedef struct AtomArAr_t AtomArAr;
struct AtomRf_t;
typedef struct AtomRf_t AtomRf;
struct BendOutlet_t;
typedef struct BendOutlet_t BendOutlet;
struct CcOutlet_t;
typedef struct CcOutlet_t CcOutlet;
struct DecrementFrameDispatch_t;
typedef struct DecrementFrameDispatch_t DecrementFrameDispatch;
struct Dispatch_t;
typedef struct Dispatch_t Dispatch;
struct DispatchAr_t;
typedef struct DispatchAr_t DispatchAr;
struct DropDown_t;
typedef struct DropDown_t DropDown;
struct FloatEvent_t;
typedef struct FloatEvent_t FloatEvent;
struct FloatEventAr_t;
typedef struct FloatEventAr_t FloatEventAr;
struct FloatSequence_t;
typedef struct FloatSequence_t FloatSequence;
struct Hub_t;
typedef struct Hub_t Hub;
struct IncrementFrameDispatch_t;
typedef struct IncrementFrameDispatch_t IncrementFrameDispatch;
struct Int_t;
typedef struct Int_t Int;
struct IntAr_t;
typedef struct IntAr_t IntAr;
struct ManageChokeGroupsDispatch_t;
typedef struct ManageChokeGroupsDispatch_t ManageChokeGroupsDispatch;
struct Marshal_t;
typedef struct Marshal_t Marshal;
struct MarshalSi_t;
typedef struct MarshalSi_t MarshalSi;
struct MarshalSii_t;
typedef struct MarshalSii_t MarshalSii;
struct MarshalSs_t;
typedef struct MarshalSs_t MarshalSs;
struct MidiFileDropDispatch_t;
typedef struct MidiFileDropDispatch_t MidiFileDropDispatch;
struct MusicalContext_t;
typedef struct MusicalContext_t MusicalContext;
struct NoteEvent_t;
typedef struct NoteEvent_t NoteEvent;
struct NoteEventAr_t;
typedef struct NoteEventAr_t NoteEventAr;
struct NoteOutlet_t;
typedef struct NoteOutlet_t NoteOutlet;
struct NoteSequence_t;
typedef struct NoteSequence_t NoteSequence;
struct NullOutlet_t;
typedef struct NullOutlet_t NullOutlet;
struct Outlet_t;
typedef struct Outlet_t Outlet;
struct OutletSpecifier_t;
typedef struct OutletSpecifier_t OutletSpecifier;
struct Pad_t;
typedef struct Pad_t Pad;
struct PadAr_t;
typedef struct PadAr_t PadAr;
struct Port_t;
typedef struct Port_t Port;
struct PortFind_t;
typedef struct PortFind_t PortFind;
struct PortFindCell_t;
typedef struct PortFindCell_t PortFindCell;
struct PortFindCellAr_t;
typedef struct PortFindCellAr_t PortFindCellAr;
struct PortRef_t;
typedef struct PortRef_t PortRef;
struct Ptr_t;
typedef struct Ptr_t Ptr;
struct PtrAr_t;
typedef struct PtrAr_t PtrAr;
struct RecordBuffer_t;
typedef struct RecordBuffer_t RecordBuffer;
struct SelectNextPushedPadDispatch_t;
typedef struct SelectNextPushedPadDispatch_t SelectNextPushedPadDispatch;
struct Sequence_t;
typedef struct Sequence_t Sequence;
struct SequenceAr_t;
typedef struct SequenceAr_t SequenceAr;
struct StringAr_t;
typedef struct StringAr_t StringAr;
struct SymbolAr_t;
typedef struct SymbolAr_t SymbolAr;
struct SymbolAr_t;
typedef struct SymbolAr_t SymbolAr;
struct Timed_t;
typedef struct Timed_t Timed;
struct TimedOff_t;
typedef struct TimedOff_t TimedOff;
struct TimedOffAr_t;
typedef struct TimedOffAr_t TimedOffAr;
struct TimedPq_t;
typedef struct TimedPq_t TimedPq;
struct Track_t;
typedef struct Track_t Track;
struct TrackAr_t;
typedef struct TrackAr_t TrackAr;
struct VstOutlet_t;
typedef struct VstOutlet_t VstOutlet;
struct Arguments_t
{
    int itype;
    int refCount;
    Symbol * s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
};
typedef struct AtomAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   AtomRf **data;
};

typedef struct AtomArFIt_t {
   AtomAr *arr;
   bool remove;
   int index;
   AtomRf *var;
} AtomArFIt;

typedef struct AtomArRIt_t {
   AtomAr *arr;
   bool remove;
   int index;
   AtomRf *var;
} AtomArRIt;

typedef struct AtomArAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   AtomAr **data;
};

typedef struct AtomArArFIt_t {
   AtomArAr *arr;
   bool remove;
   int index;
   AtomAr *var;
} AtomArArFIt;

typedef struct AtomArArRIt_t {
   AtomArAr *arr;
   bool remove;
   int index;
   AtomAr *var;
} AtomArArRIt;

struct AtomRf_t
{
    int itype;
    int refCount;
    Atom a;
};
struct BendOutlet_t
{
    int itype;
    int refCount;
    AtomAr *atoms;
    Port *port;
};
struct CcOutlet_t
{
    int itype;
    int refCount;
    int cc;
    AtomAr *atoms;
    Port *port;
};
struct DecrementFrameDispatch_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
    Marshal * marshal;
};
struct Dispatch_t
{
    itype int;
};
typedef struct DispatchAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Dispatch **data;
};

typedef struct DispatchArFIt_t {
   DispatchAr *arr;
   bool remove;
   int index;
   Dispatch *var;
} DispatchArFIt;

typedef struct DispatchArRIt_t {
   DispatchAr *arr;
   bool remove;
   int index;
   Dispatch *var;
} DispatchArRIt;

struct DropDown_t
{
    int itype;
    int refCount;
    SymbolAr *table;
    int selected;
    Outlet *outlet;
};
struct FloatEvent_t
{
    int itype;
    int refCount;
    Ticks stime;
    double value;
};
typedef struct FloatEventAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   FloatEvent **data;
};

typedef struct FloatEventArFIt_t {
   FloatEventAr *arr;
   bool remove;
   int index;
   FloatEvent *var;
} FloatEventArFIt;

typedef struct FloatEventArRIt_t {
   FloatEventAr *arr;
   bool remove;
   int index;
   FloatEvent *var;
} FloatEventArRIt;

struct FloatSequence_t
{
    int itype;
    int refCount;
    long version;
    Ticks startTime;
    OutletSpecifier *outletSpecifier;
    Ticks sequenceLength;
    int cursor;
    bool cycle;
    bool inEndgroup;
    Outlet *outlet;
    FloatSequence * recordingSeq;
    FloatEventAr *events;
    double restoreValue;
};
struct Hub_t
{
    int itype;
    int refCount;
    PadAr *padList;
    TrackAr *trackList;
    Port *currBankPort;
    Port *currFramePort;
    Port *selBankPort;
    Port *selFramePort;
    Port *selPadPort;
    Port *chokeGroupPort;
    DropDown *cgLocalGlobalMenu;
    DropDown *cgInstrumentMenu;
    DropDown *cgIndexMenu;
    int bank;
    int frame;
    bool grabNextTappedPad;
    int selectedPad;
    Arguments *arguments;
    DispatchAr *dispatcher;
    Ticks masterClock;
};
struct IncrementFrameDispatch_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
    Marshal * marshal;
};
struct Int_t
{
    int itype;
    int refCount;
    int i;
};
typedef struct IntAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Int **data;
};

typedef struct IntArFIt_t {
   IntAr *arr;
   bool remove;
   int index;
   Int *var;
} IntArFIt;

typedef struct IntArRIt_t {
   IntAr *arr;
   bool remove;
   int index;
   Int *var;
} IntArRIt;

struct ManageChokeGroupsDispatch_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
    Marshal * marshal;
};
struct Marshal_t
{
    itype int;
};
struct MarshalSi_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
};
struct MarshalSii_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
};
struct MarshalSs_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
};
struct MidiFileDropDispatch_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
    Marshal * marshal;
};
struct MusicalContext_t
{
    int itype;
    int refCount;
    Ticks ticksPerQuarterNote;
    Ticks quarterNotesPerMeasure;
};
struct NoteEvent_t
{
    int itype;
    int refCount;
    uint8_t pitch;
    uint8_t velocity;
    Ticks stime;
    Ticks duration;
};
typedef struct NoteEventAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   NoteEvent **data;
};

typedef struct NoteEventArFIt_t {
   NoteEventAr *arr;
   bool remove;
   int index;
   NoteEvent *var;
} NoteEventArFIt;

typedef struct NoteEventArRIt_t {
   NoteEventAr *arr;
   bool remove;
   int index;
   NoteEvent *var;
} NoteEventArRIt;

struct NoteOutlet_t
{
    int itype;
    int refCount;
    AtomAr *atoms;
    Port *port;
};
struct NoteSequence_t
{
    int itype;
    int refCount;
    long version;
    Ticks startTime;
    OutletSpecifier *outletSpecifier;
    Ticks sequenceLength;
    int cursor;
    bool cycle;
    Ticks nextOffEvent;
    Ticks nextOnEvent;
    bool inEndgroup;
    Outlet *outlet;
    NoteSequence * recordingSeq;
    TimedOffAr *offs;
    NoteEventAr *events;
};
struct NullOutlet_t
{
    int itype;
    int refCount;
    int unused;
};
struct Outlet_t
{
    itype int;
};
struct OutletSpecifier_t
{
    int itype;
    int refCount;
    Symbol * track;
    int pluginIndex;
    Symbol * parameter;
    int paramIndex;
};
struct Pad_t
{
    int itype;
    int refCount;
    Symbol * trackName;
    int padIndex;
    Sequence *SequenceAr;
    bool chokeGroupGlobal;
    int chokeGroupInstrument;
    int chokeGroupIndex;
    int64_t chokeGroup;
    bool noteReleasePending;
    bool inEndgroup;
    Track *track;
    bool useMasterClock;
};
typedef struct PadAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Pad **data;
};

typedef struct PadArFIt_t {
   PadAr *arr;
   bool remove;
   int index;
   Pad *var;
} PadArFIt;

typedef struct PadArRIt_t {
   PadAr *arr;
   bool remove;
   int index;
   Pad *var;
} PadArRIt;

struct Port_t
{
    int itype;
    int refCount;
    MaxObject obj;
    long inletnum;
    PtrAr *proxy;
    PtrAr *outlet;
    Symbol * track;
    Symbol * id;
    long intInlets;
    long intOutlets;
    void * hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct PortFind_t
{
    int itype;
    int refCount;
    PortFindCellAr *objects;
    void * hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct PortFindCell_t
{
    int itype;
    int refCount;
    Port reciever;
    Symbol * varname;
};
typedef struct PortFindCellAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   PortFindCell **data;
};

typedef struct PortFindCellArFIt_t {
   PortFindCellAr *arr;
   bool remove;
   int index;
   PortFindCell *var;
} PortFindCellArFIt;

typedef struct PortFindCellArRIt_t {
   PortFindCellAr *arr;
   bool remove;
   int index;
   PortFindCell *var;
} PortFindCellArRIt;

struct PortRef_t
{
    int itype;
    int refCount;
    Port * port;
    int outlet;
};
struct Ptr_t
{
    int itype;
    int refCount;
    void * p;
};
typedef struct PtrAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Ptr **data;
};

typedef struct PtrArFIt_t {
   PtrAr *arr;
   bool remove;
   int index;
   Ptr *var;
} PtrArFIt;

typedef struct PtrArRIt_t {
   PtrAr *arr;
   bool remove;
   int index;
   Ptr *var;
} PtrArRIt;

struct RecordBuffer_t
{
    int itype;
    int refCount;
    Ticks recordStart;
    SequenceAr *sequences;
};
struct SelectNextPushedPadDispatch_t
{
    int itype;
    int refCount;
    Symbol * selector;
    Symbol * portId;
    int inlet;
    Marshal * marshal;
};
struct Sequence_t
{
    itype int;
};
typedef struct SequenceAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Sequence **data;
};

typedef struct SequenceArFIt_t {
   SequenceAr *arr;
   bool remove;
   int index;
   Sequence *var;
} SequenceArFIt;

typedef struct SequenceArRIt_t {
   SequenceAr *arr;
   bool remove;
   int index;
   Sequence *var;
} SequenceArRIt;

typedef struct StringAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   String **data;
};

typedef struct StringArFIt_t {
   StringAr *arr;
   bool remove;
   int index;
   String *var;
} StringArFIt;

typedef struct StringArRIt_t {
   StringAr *arr;
   bool remove;
   int index;
   String *var;
} StringArRIt;

typedef struct SymbolAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Symbol **data;
};

typedef struct SymbolArFIt_t {
   SymbolAr *arr;
   bool remove;
   int index;
   Symbol *var;
} SymbolArFIt;

typedef struct SymbolArRIt_t {
   SymbolAr *arr;
   bool remove;
   int index;
   Symbol *var;
} SymbolArRIt;

typedef struct SymbolAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Symbol **data;
};

typedef struct SymbolArFIt_t {
   SymbolAr *arr;
   bool remove;
   int index;
   Symbol *var;
} SymbolArFIt;

typedef struct SymbolArRIt_t {
   SymbolAr *arr;
   bool remove;
   int index;
   Symbol *var;
} SymbolArRIt;

struct Timed_t
{
    int itype;
    int refCount;
    Ticks time;
    int version;
    Sequence *sequence;
};
struct TimedOff_t
{
    int itype;
    int refCount;
    Ticks time;
    int pitch;
};
typedef struct TimedOffAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   TimedOff **data;
};

typedef struct TimedOffArFIt_t {
   TimedOffAr *arr;
   bool remove;
   int index;
   TimedOff *var;
} TimedOffArFIt;

typedef struct TimedOffArRIt_t {
   TimedOffAr *arr;
   bool remove;
   int index;
   TimedOff *var;
} TimedOffArRIt;

typedef struct TimedPq_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Timed **data;
};

typedef struct TimedPqFIt_t {
   TimedPq *arr;
   bool remove;
   int index;
   Timed *var;
} TimedPqFIt;

typedef struct TimedPqRIt_t {
   TimedPq *arr;
   bool remove;
   int index;
   Timed *var;
} TimedPqRIt;

struct Track_t
{
    int itype;
    int refCount;
    Symbol * name;
};
typedef struct TrackAr_t {
   int itype;
   int refCount;
   int len;
   int cap;
   Track **data;
};

typedef struct TrackArFIt_t {
   TrackAr *arr;
   bool remove;
   int index;
   Track *var;
} TrackArFIt;

typedef struct TrackArRIt_t {
   TrackAr *arr;
   bool remove;
   int index;
   Track *var;
} TrackArRIt;

struct VstOutlet_t
{
    int itype;
    int refCount;
    AtomAr *atoms;
    Port *port;
};
#define Arguments_itype 11
#define AtomRf_itype 12
#define BendOutlet_itype 13
#define CcOutlet_itype 14
#define DecrementFrameDispatch_itype 15
#define DropDown_itype 16
#define FloatEvent_itype 17
#define FloatSequence_itype 18
#define Hub_itype 19
#define IncrementFrameDispatch_itype 20
#define Int_itype 21
#define ManageChokeGroupsDispatch_itype 22
#define MarshalSi_itype 23
#define MarshalSii_itype 24
#define MarshalSs_itype 25
#define MidiFileDropDispatch_itype 26
#define MusicalContext_itype 27
#define NoteEvent_itype 28
#define NoteOutlet_itype 29
#define NoteSequence_itype 30
#define NullOutlet_itype 31
#define OutletSpecifier_itype 32
#define Pad_itype 33
#define Port_itype 34
#define PortFind_itype 35
#define PortFindCell_itype 36
#define PortRef_itype 37
#define Ptr_itype 38
#define RecordBuffer_itype 39
#define SelectNextPushedPadDispatch_itype 40
#define Timed_itype 41
#define TimedOff_itype 42
#define Track_itype 43
#define VstOutlet_itype 44
const char *Interface_toString(int itype)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Interface_toString");
       return NULL;
   }
   switch(itype) {
       case Arguments_itype:
           return "Arguments";
       case AtomRf_itype:
           return "AtomRf";
       case BendOutlet_itype:
           return "BendOutlet";
       case CcOutlet_itype:
           return "CcOutlet";
       case DecrementFrameDispatch_itype:
           return "DecrementFrameDispatch";
       case DropDown_itype:
           return "DropDown";
       case FloatEvent_itype:
           return "FloatEvent";
       case FloatSequence_itype:
           return "FloatSequence";
       case Hub_itype:
           return "Hub";
       case IncrementFrameDispatch_itype:
           return "IncrementFrameDispatch";
       case Int_itype:
           return "Int";
       case ManageChokeGroupsDispatch_itype:
           return "ManageChokeGroupsDispatch";
       case MarshalSi_itype:
           return "MarshalSi";
       case MarshalSii_itype:
           return "MarshalSii";
       case MarshalSs_itype:
           return "MarshalSs";
       case MidiFileDropDispatch_itype:
           return "MidiFileDropDispatch";
       case MusicalContext_itype:
           return "MusicalContext";
       case NoteEvent_itype:
           return "NoteEvent";
       case NoteOutlet_itype:
           return "NoteOutlet";
       case NoteSequence_itype:
           return "NoteSequence";
       case NullOutlet_itype:
           return "NullOutlet";
       case OutletSpecifier_itype:
           return "OutletSpecifier";
       case Pad_itype:
           return "Pad";
       case Port_itype:
           return "Port";
       case PortFind_itype:
           return "PortFind";
       case PortFindCell_itype:
           return "PortFindCell";
       case PortRef_itype:
           return "PortRef";
       case Ptr_itype:
           return "Ptr";
       case RecordBuffer_itype:
           return "RecordBuffer";
       case SelectNextPushedPadDispatch_itype:
           return "SelectNextPushedPadDispatch";
       case Timed_itype:
           return "Timed";
       case TimedOff_itype:
           return "TimedOff";
       case Track_itype:
           return "Track";
       case VstOutlet_itype:
           return "VstOutlet";
    }
    return "Unknown";
}
Arguments *Arguments_new();
void Arguments_incRef(Arguments *self);
void Arguments_decRef(Arguments *self);
Arguments *Arguments_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Arguments_toJson(Arguments *self, Error *err);
Arguments *Arguments_clone(Arguments *self);
static inline Symbol * Arguments_s1(Arguments *self){return self->s1;}
static inline void Arguments_setS1(Arguments *self, Symbol * value){self->s1 = value;}
static inline long Arguments_i1(Arguments *self){return self->i1;}
static inline void Arguments_setI1(Arguments *self, long value){self->i1 = value;}
static inline long Arguments_i2(Arguments *self){return self->i2;}
static inline void Arguments_setI2(Arguments *self, long value){self->i2 = value;}
static inline long Arguments_ivalue(Arguments *self){return self->ivalue;}
static inline void Arguments_setIvalue(Arguments *self, long value){self->ivalue = value;}
static inline long Arguments_inlet(Arguments *self){return self->inlet;}
static inline void Arguments_setInlet(Arguments *self, long value){self->inlet = value;}
#define AtomAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
AtomAr *AtomAr_clone(AtomAr *arr);
void AtomAr_decRef(AtomAr *arr);
void AtomAr_fit(AtomAr *arr);
#define AtomAr_foreach(var, arr)               for (AtomArFIt var = {arr, false, 0, NULL};        AtomArFIt_next(&var); )
#define AtomAr_foreachOffset(var, arr, offset) for (AtomArFIt var = {arr, false, offset-1, NULL}; AtomArFIt_next(&var); )
AtomAr *AtomAr_fromJson(JSON_Value *jval, Error *err);
AtomRf *AtomAr_get(AtomAr *arr, int index, Error *err);
void AtomAr_incRef(AtomAr *arr);
void AtomAr_insert(AtomAr *arr, int index, AtomRf *elem, Error *err);
int AtomAr_last(AtomAr *arr);
int AtomAr_len(AtomAr *arr);
AtomAr *AtomAr_new();
void AtomAr_pop(AtomAr *arr, Error *err);
AtomRf *AtomAr_pop(AtomAr *arr, Error *err);
void AtomAr_push(AtomAr *arr, AtomRf *elem);
void AtomAr_remove(AtomAr *arr, int index, Error *err);
void AtomAr_reserve(AtomAr *arr, int newCap);
#define AtomAr_rforeach(var, arr)               for (AtomArFIt var = {arr, false, (arr)->len, NULL};        AtomArFIt_next(&var); )
#define AtomAr_rforeachOffset(var, arr, offset) for (AtomArFIt var = {arr, false, (arr)->len-offset, NULL}; AtomArFIt_next(&var); )
void AtomAr_set(AtomAr *arr, int index, AtomRf *elem, Error *err);
JSON_Value *AtomAr_toJson(AtomAr *self, Error *err);
void AtomAr_truncate(AtomAr *arr, int newLen);
bool AtomArFIt_next(AtomArFIt *iterator);
bool AtomArRIt_next(AtomArRIt *iterator);
#define AtomArAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
AtomArAr *AtomArAr_clone(AtomArAr *arr);
void AtomArAr_decRef(AtomArAr *arr);
void AtomArAr_fit(AtomArAr *arr);
#define AtomArAr_foreach(var, arr)               for (AtomArArFIt var = {arr, false, 0, NULL};        AtomArArFIt_next(&var); )
#define AtomArAr_foreachOffset(var, arr, offset) for (AtomArArFIt var = {arr, false, offset-1, NULL}; AtomArArFIt_next(&var); )
AtomArAr *AtomArAr_fromJson(JSON_Value *jval, Error *err);
AtomAr *AtomArAr_get(AtomArAr *arr, int index, Error *err);
void AtomArAr_incRef(AtomArAr *arr);
void AtomArAr_insert(AtomArAr *arr, int index, AtomAr *elem, Error *err);
int AtomArAr_last(AtomArAr *arr);
int AtomArAr_len(AtomArAr *arr);
AtomArAr *AtomArAr_new();
void AtomArAr_pop(AtomArAr *arr, Error *err);
AtomAr *AtomArAr_pop(AtomArAr *arr, Error *err);
void AtomArAr_push(AtomArAr *arr, AtomAr *elem);
void AtomArAr_remove(AtomArAr *arr, int index, Error *err);
void AtomArAr_reserve(AtomArAr *arr, int newCap);
#define AtomArAr_rforeach(var, arr)               for (AtomArArFIt var = {arr, false, (arr)->len, NULL};        AtomArArFIt_next(&var); )
#define AtomArAr_rforeachOffset(var, arr, offset) for (AtomArArFIt var = {arr, false, (arr)->len-offset, NULL}; AtomArArFIt_next(&var); )
void AtomArAr_set(AtomArAr *arr, int index, AtomAr *elem, Error *err);
JSON_Value *AtomArAr_toJson(AtomArAr *self, Error *err);
void AtomArAr_truncate(AtomArAr *arr, int newLen);
bool AtomArArFIt_next(AtomArArFIt *iterator);
bool AtomArArRIt_next(AtomArArRIt *iterator);
AtomRf *AtomRf_new();
void AtomRf_incRef(AtomRf *self);
void AtomRf_decRef(AtomRf *self);
AtomRf *AtomRf_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *AtomRf_toJson(AtomRf *self, Error *err);
AtomRf *AtomRf_clone(AtomRf *self);
static inline Atom AtomRf_a(AtomRf *self){return self->a;}
static inline void AtomRf_setA(AtomRf *self, Atom value){self->a = value;}
BendOutlet *BendOutlet_new();
void BendOutlet_incRef(BendOutlet *self);
void BendOutlet_decRef(BendOutlet *self);
BendOutlet *BendOutlet_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *BendOutlet_toJson(BendOutlet *self, Error *err);
BendOutlet *BendOutlet_clone(BendOutlet *self);
static inline AtomAr *BendOutlet_atoms(BendOutlet *self){return self->atoms;}
void BendOutlet_setAtoms(BendOutlet *self, AtomAr *value);
static inline Port *BendOutlet_port(BendOutlet *self){return self->port;}
void BendOutlet_setPort(BendOutlet *self, Port *value);
static inline BendOutlet *BendOutlet_castFromOutlet(Outlet *self) {
   if (self->itype == BendOutlet_itype) {
       return (BendOutlet*)self;
   }
   return NULL;
}
static inline Outlet *BendOutlet_castToOutlet(BendOutlet *self) {
   return (Outlet*)self;
}
CcOutlet *CcOutlet_new();
void CcOutlet_incRef(CcOutlet *self);
void CcOutlet_decRef(CcOutlet *self);
CcOutlet *CcOutlet_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *CcOutlet_toJson(CcOutlet *self, Error *err);
CcOutlet *CcOutlet_clone(CcOutlet *self);
static inline int CcOutlet_cc(CcOutlet *self){return self->cc;}
static inline void CcOutlet_setCc(CcOutlet *self, int value){self->cc = value;}
static inline AtomAr *CcOutlet_atoms(CcOutlet *self){return self->atoms;}
void CcOutlet_setAtoms(CcOutlet *self, AtomAr *value);
static inline Port *CcOutlet_port(CcOutlet *self){return self->port;}
void CcOutlet_setPort(CcOutlet *self, Port *value);
static inline CcOutlet *CcOutlet_castFromOutlet(Outlet *self) {
   if (self->itype == CcOutlet_itype) {
       return (CcOutlet*)self;
   }
   return NULL;
}
static inline Outlet *CcOutlet_castToOutlet(CcOutlet *self) {
   return (Outlet*)self;
}
DecrementFrameDispatch *DecrementFrameDispatch_new();
void DecrementFrameDispatch_incRef(DecrementFrameDispatch *self);
void DecrementFrameDispatch_decRef(DecrementFrameDispatch *self);
DecrementFrameDispatch *DecrementFrameDispatch_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *DecrementFrameDispatch_toJson(DecrementFrameDispatch *self, Error *err);
DecrementFrameDispatch *DecrementFrameDispatch_clone(DecrementFrameDispatch *self);
static inline Symbol * DecrementFrameDispatch_selector(DecrementFrameDispatch *self){return self->selector;}
static inline void DecrementFrameDispatch_setSelector(DecrementFrameDispatch *self, Symbol * value){self->selector = value;}
static inline Symbol * DecrementFrameDispatch_portId(DecrementFrameDispatch *self){return self->portId;}
static inline void DecrementFrameDispatch_setPortId(DecrementFrameDispatch *self, Symbol * value){self->portId = value;}
static inline int DecrementFrameDispatch_inlet(DecrementFrameDispatch *self){return self->inlet;}
static inline void DecrementFrameDispatch_setInlet(DecrementFrameDispatch *self, int value){self->inlet = value;}
static inline Marshal * DecrementFrameDispatch_marshal(DecrementFrameDispatch *self){return self->marshal;}
static inline void DecrementFrameDispatch_setMarshal(DecrementFrameDispatch *self, Marshal * value){self->marshal = value;}
static inline DecrementFrameDispatch *DecrementFrameDispatch_castFromDispatch(Dispatch *self) {
   if (self->itype == DecrementFrameDispatch_itype) {
       return (DecrementFrameDispatch*)self;
   }
   return NULL;
}
static inline Dispatch *DecrementFrameDispatch_castToDispatch(DecrementFrameDispatch *self) {
   return (Dispatch*)self;
}
int Dispatch_nthIType(int n, int *itype);
#define Dispatch_foreachIType(itype) for (int __##itype = 0, itype = 0; Dispatch_nthIType(__##itype, &itype); __##itype++)
void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error * a3, Error *err, Error *err);
Dispatch *Dispatch_create(int itype, Error *err);
void Dispatch_free(Dispatch *self, Error *err);
void Dispatch_initDispatchAr(int itype, DispatchAr *a1, Error * a2, Error *err, Error *err);
#define DispatchAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
DispatchAr *DispatchAr_clone(DispatchAr *arr);
void DispatchAr_decRef(DispatchAr *arr);
void DispatchAr_fit(DispatchAr *arr);
#define DispatchAr_foreach(var, arr)               for (DispatchArFIt var = {arr, false, 0, NULL};        DispatchArFIt_next(&var); )
#define DispatchAr_foreachOffset(var, arr, offset) for (DispatchArFIt var = {arr, false, offset-1, NULL}; DispatchArFIt_next(&var); )
DispatchAr *DispatchAr_fromJson(JSON_Value *jval, Error *err);
Dispatch *DispatchAr_get(DispatchAr *arr, int index, Error *err);
void DispatchAr_incRef(DispatchAr *arr);
void DispatchAr_insert(DispatchAr *arr, int index, Dispatch *elem, Error *err);
int DispatchAr_last(DispatchAr *arr);
int DispatchAr_len(DispatchAr *arr);
DispatchAr *DispatchAr_new();
void DispatchAr_pop(DispatchAr *arr, Error *err);
Dispatch *DispatchAr_pop(DispatchAr *arr, Error *err);
void DispatchAr_push(DispatchAr *arr, Dispatch *elem);
void DispatchAr_remove(DispatchAr *arr, int index, Error *err);
void DispatchAr_reserve(DispatchAr *arr, int newCap);
#define DispatchAr_rforeach(var, arr)               for (DispatchArFIt var = {arr, false, (arr)->len, NULL};        DispatchArFIt_next(&var); )
#define DispatchAr_rforeachOffset(var, arr, offset) for (DispatchArFIt var = {arr, false, (arr)->len-offset, NULL}; DispatchArFIt_next(&var); )
void DispatchAr_set(DispatchAr *arr, int index, Dispatch *elem, Error *err);
JSON_Value *DispatchAr_toJson(DispatchAr *self, Error *err);
void DispatchAr_truncate(DispatchAr *arr, int newLen);
bool DispatchArFIt_next(DispatchArFIt *iterator);
bool DispatchArRIt_next(DispatchArRIt *iterator);
void DispatchAr_binInsert(DispatchAr *arr, Dispatch *elem);
void DispatchAr_binRemove(DispatchAr *arr, Dispatch *elem);
Dispatch *DispatchAr_binSearch(DispatchAr *arr, Dispatch *elem);
int Dispatch_cmpIndirectResolve(Dispatch **left, Dispatch **right);
Dispatch *DispatchAr_pqPeek(DispatchAr *arr);
void DispatchAr_pqPopDecRef(DispatchAr *arr, Dispatch *elem);
Dispatch *DispatchAr_pqPop(DispatchAr *arr);
void DispatchAr_pqPush(DispatchAr *arr, Dispatch *elem);
void DispatchAr_pqSort(DispatchAr *arr);
void DispatchAr_sort(DispatchAr *arr);
DropDown *DropDown_new();
void DropDown_incRef(DropDown *self);
void DropDown_decRef(DropDown *self);
DropDown *DropDown_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *DropDown_toJson(DropDown *self, Error *err);
DropDown *DropDown_clone(DropDown *self);
static inline SymbolAr *DropDown_table(DropDown *self){return self->table;}
void DropDown_setTable(DropDown *self, SymbolAr *value);
static inline int DropDown_selected(DropDown *self){return self->selected;}
static inline void DropDown_setSelected(DropDown *self, int value){self->selected = value;}
static inline Outlet *DropDown_outlet(DropDown *self){return self->outlet;}
void DropDown_setOutlet(DropDown *self, Outlet *value);
FloatEvent *FloatEvent_new();
void FloatEvent_incRef(FloatEvent *self);
void FloatEvent_decRef(FloatEvent *self);
FloatEvent *FloatEvent_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *FloatEvent_toJson(FloatEvent *self, Error *err);
FloatEvent *FloatEvent_clone(FloatEvent *self);
static inline Ticks FloatEvent_stime(FloatEvent *self){return self->stime;}
static inline void FloatEvent_setStime(FloatEvent *self, Ticks value){self->stime = value;}
static inline double FloatEvent_value(FloatEvent *self){return self->value;}
static inline void FloatEvent_setValue(FloatEvent *self, double value){self->value = value;}
#define FloatEventAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
FloatEventAr *FloatEventAr_clone(FloatEventAr *arr);
void FloatEventAr_decRef(FloatEventAr *arr);
void FloatEventAr_fit(FloatEventAr *arr);
#define FloatEventAr_foreach(var, arr)               for (FloatEventArFIt var = {arr, false, 0, NULL};        FloatEventArFIt_next(&var); )
#define FloatEventAr_foreachOffset(var, arr, offset) for (FloatEventArFIt var = {arr, false, offset-1, NULL}; FloatEventArFIt_next(&var); )
FloatEventAr *FloatEventAr_fromJson(JSON_Value *jval, Error *err);
FloatEvent *FloatEventAr_get(FloatEventAr *arr, int index, Error *err);
void FloatEventAr_incRef(FloatEventAr *arr);
void FloatEventAr_insert(FloatEventAr *arr, int index, FloatEvent *elem, Error *err);
int FloatEventAr_last(FloatEventAr *arr);
int FloatEventAr_len(FloatEventAr *arr);
FloatEventAr *FloatEventAr_new();
void FloatEventAr_pop(FloatEventAr *arr, Error *err);
FloatEvent *FloatEventAr_pop(FloatEventAr *arr, Error *err);
void FloatEventAr_push(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_remove(FloatEventAr *arr, int index, Error *err);
void FloatEventAr_reserve(FloatEventAr *arr, int newCap);
#define FloatEventAr_rforeach(var, arr)               for (FloatEventArFIt var = {arr, false, (arr)->len, NULL};        FloatEventArFIt_next(&var); )
#define FloatEventAr_rforeachOffset(var, arr, offset) for (FloatEventArFIt var = {arr, false, (arr)->len-offset, NULL}; FloatEventArFIt_next(&var); )
void FloatEventAr_set(FloatEventAr *arr, int index, FloatEvent *elem, Error *err);
JSON_Value *FloatEventAr_toJson(FloatEventAr *self, Error *err);
void FloatEventAr_truncate(FloatEventAr *arr, int newLen);
bool FloatEventArFIt_next(FloatEventArFIt *iterator);
bool FloatEventArRIt_next(FloatEventArRIt *iterator);
void FloatEventAr_binInsert(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_binRemove(FloatEventAr *arr, FloatEvent *elem);
FloatEvent *FloatEventAr_binSearch(FloatEventAr *arr, FloatEvent *elem);
int FloatEvent_cmpIndirectResolve(FloatEvent **left, FloatEvent **right);
FloatEvent *FloatEventAr_pqPeek(FloatEventAr *arr);
void FloatEventAr_pqPopDecRef(FloatEventAr *arr, FloatEvent *elem);
FloatEvent *FloatEventAr_pqPop(FloatEventAr *arr);
void FloatEventAr_pqPush(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_pqSort(FloatEventAr *arr);
void FloatEventAr_sort(FloatEventAr *arr);
FloatSequence *FloatSequence_new();
void FloatSequence_incRef(FloatSequence *self);
void FloatSequence_decRef(FloatSequence *self);
FloatSequence *FloatSequence_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *FloatSequence_toJson(FloatSequence *self, Error *err);
FloatSequence *FloatSequence_clone(FloatSequence *self);
static inline long FloatSequence_version(FloatSequence *self){return self->version;}
static inline void FloatSequence_setVersion(FloatSequence *self, long value){self->version = value;}
static inline Ticks FloatSequence_startTime(FloatSequence *self){return self->startTime;}
static inline void FloatSequence_setStartTime(FloatSequence *self, Ticks value){self->startTime = value;}
static inline OutletSpecifier *FloatSequence_outletSpecifier(FloatSequence *self){return self->outletSpecifier;}
void FloatSequence_setOutletSpecifier(FloatSequence *self, OutletSpecifier *value);
static inline Ticks FloatSequence_sequenceLength(FloatSequence *self){return self->sequenceLength;}
static inline void FloatSequence_setSequenceLength(FloatSequence *self, Ticks value){self->sequenceLength = value;}
static inline int FloatSequence_cursor(FloatSequence *self){return self->cursor;}
static inline void FloatSequence_setCursor(FloatSequence *self, int value){self->cursor = value;}
static inline bool FloatSequence_cycle(FloatSequence *self){return self->cycle;}
static inline void FloatSequence_setCycle(FloatSequence *self, bool value){self->cycle = value;}
static inline bool FloatSequence_inEndgroup(FloatSequence *self){return self->inEndgroup;}
static inline void FloatSequence_setInEndgroup(FloatSequence *self, bool value){self->inEndgroup = value;}
static inline Outlet *FloatSequence_outlet(FloatSequence *self){return self->outlet;}
void FloatSequence_setOutlet(FloatSequence *self, Outlet *value);
static inline FloatSequence * FloatSequence_recordingSeq(FloatSequence *self){return self->recordingSeq;}
static inline void FloatSequence_setRecordingSeq(FloatSequence *self, FloatSequence * value){self->recordingSeq = value;}
static inline FloatEventAr *FloatSequence_events(FloatSequence *self){return self->events;}
void FloatSequence_setEvents(FloatSequence *self, FloatEventAr *value);
static inline double FloatSequence_restoreValue(FloatSequence *self){return self->restoreValue;}
static inline void FloatSequence_setRestoreValue(FloatSequence *self, double value){self->restoreValue = value;}
static inline FloatSequence *FloatSequence_castFromSequence(Sequence *self) {
   if (self->itype == FloatSequence_itype) {
       return (FloatSequence*)self;
   }
   return NULL;
}
static inline Sequence *FloatSequence_castToSequence(FloatSequence *self) {
   return (Sequence*)self;
}
Hub *Hub_new();
void Hub_incRef(Hub *self);
void Hub_decRef(Hub *self);
Hub *Hub_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Hub_toJson(Hub *self, Error *err);
Hub *Hub_clone(Hub *self);
static inline PadAr *Hub_padList(Hub *self){return self->padList;}
void Hub_setPadList(Hub *self, PadAr *value);
static inline TrackAr *Hub_trackList(Hub *self){return self->trackList;}
void Hub_setTrackList(Hub *self, TrackAr *value);
static inline Port *Hub_currBankPort(Hub *self){return self->currBankPort;}
void Hub_setCurrBankPort(Hub *self, Port *value);
static inline Port *Hub_currFramePort(Hub *self){return self->currFramePort;}
void Hub_setCurrFramePort(Hub *self, Port *value);
static inline Port *Hub_selBankPort(Hub *self){return self->selBankPort;}
void Hub_setSelBankPort(Hub *self, Port *value);
static inline Port *Hub_selFramePort(Hub *self){return self->selFramePort;}
void Hub_setSelFramePort(Hub *self, Port *value);
static inline Port *Hub_selPadPort(Hub *self){return self->selPadPort;}
void Hub_setSelPadPort(Hub *self, Port *value);
static inline Port *Hub_chokeGroupPort(Hub *self){return self->chokeGroupPort;}
void Hub_setChokeGroupPort(Hub *self, Port *value);
static inline DropDown *Hub_cgLocalGlobalMenu(Hub *self){return self->cgLocalGlobalMenu;}
void Hub_setCgLocalGlobalMenu(Hub *self, DropDown *value);
static inline DropDown *Hub_cgInstrumentMenu(Hub *self){return self->cgInstrumentMenu;}
void Hub_setCgInstrumentMenu(Hub *self, DropDown *value);
static inline DropDown *Hub_cgIndexMenu(Hub *self){return self->cgIndexMenu;}
void Hub_setCgIndexMenu(Hub *self, DropDown *value);
static inline int Hub_bank(Hub *self){return self->bank;}
static inline void Hub_setBank(Hub *self, int value){self->bank = value;}
static inline int Hub_frame(Hub *self){return self->frame;}
static inline void Hub_setFrame(Hub *self, int value){self->frame = value;}
static inline bool Hub_grabNextTappedPad(Hub *self){return self->grabNextTappedPad;}
static inline void Hub_setGrabNextTappedPad(Hub *self, bool value){self->grabNextTappedPad = value;}
static inline int Hub_selectedPad(Hub *self){return self->selectedPad;}
static inline void Hub_setSelectedPad(Hub *self, int value){self->selectedPad = value;}
static inline Arguments *Hub_arguments(Hub *self){return self->arguments;}
void Hub_setArguments(Hub *self, Arguments *value);
static inline DispatchAr *Hub_dispatcher(Hub *self){return self->dispatcher;}
void Hub_setDispatcher(Hub *self, DispatchAr *value);
static inline Ticks Hub_masterClock(Hub *self){return self->masterClock;}
static inline void Hub_setMasterClock(Hub *self, Ticks value){self->masterClock = value;}
IncrementFrameDispatch *IncrementFrameDispatch_new();
void IncrementFrameDispatch_incRef(IncrementFrameDispatch *self);
void IncrementFrameDispatch_decRef(IncrementFrameDispatch *self);
IncrementFrameDispatch *IncrementFrameDispatch_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *IncrementFrameDispatch_toJson(IncrementFrameDispatch *self, Error *err);
IncrementFrameDispatch *IncrementFrameDispatch_clone(IncrementFrameDispatch *self);
static inline Symbol * IncrementFrameDispatch_selector(IncrementFrameDispatch *self){return self->selector;}
static inline void IncrementFrameDispatch_setSelector(IncrementFrameDispatch *self, Symbol * value){self->selector = value;}
static inline Symbol * IncrementFrameDispatch_portId(IncrementFrameDispatch *self){return self->portId;}
static inline void IncrementFrameDispatch_setPortId(IncrementFrameDispatch *self, Symbol * value){self->portId = value;}
static inline int IncrementFrameDispatch_inlet(IncrementFrameDispatch *self){return self->inlet;}
static inline void IncrementFrameDispatch_setInlet(IncrementFrameDispatch *self, int value){self->inlet = value;}
static inline Marshal * IncrementFrameDispatch_marshal(IncrementFrameDispatch *self){return self->marshal;}
static inline void IncrementFrameDispatch_setMarshal(IncrementFrameDispatch *self, Marshal * value){self->marshal = value;}
static inline IncrementFrameDispatch *IncrementFrameDispatch_castFromDispatch(Dispatch *self) {
   if (self->itype == IncrementFrameDispatch_itype) {
       return (IncrementFrameDispatch*)self;
   }
   return NULL;
}
static inline Dispatch *IncrementFrameDispatch_castToDispatch(IncrementFrameDispatch *self) {
   return (Dispatch*)self;
}
Int *Int_new();
void Int_incRef(Int *self);
void Int_decRef(Int *self);
Int *Int_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Int_toJson(Int *self, Error *err);
Int *Int_clone(Int *self);
static inline int Int_i(Int *self){return self->i;}
static inline void Int_setI(Int *self, int value){self->i = value;}
#define IntAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
IntAr *IntAr_clone(IntAr *arr);
void IntAr_decRef(IntAr *arr);
void IntAr_fit(IntAr *arr);
#define IntAr_foreach(var, arr)               for (IntArFIt var = {arr, false, 0, NULL};        IntArFIt_next(&var); )
#define IntAr_foreachOffset(var, arr, offset) for (IntArFIt var = {arr, false, offset-1, NULL}; IntArFIt_next(&var); )
IntAr *IntAr_fromJson(JSON_Value *jval, Error *err);
Int *IntAr_get(IntAr *arr, int index, Error *err);
void IntAr_incRef(IntAr *arr);
void IntAr_insert(IntAr *arr, int index, Int *elem, Error *err);
int IntAr_last(IntAr *arr);
int IntAr_len(IntAr *arr);
IntAr *IntAr_new();
void IntAr_pop(IntAr *arr, Error *err);
Int *IntAr_pop(IntAr *arr, Error *err);
void IntAr_push(IntAr *arr, Int *elem);
void IntAr_remove(IntAr *arr, int index, Error *err);
void IntAr_reserve(IntAr *arr, int newCap);
#define IntAr_rforeach(var, arr)               for (IntArFIt var = {arr, false, (arr)->len, NULL};        IntArFIt_next(&var); )
#define IntAr_rforeachOffset(var, arr, offset) for (IntArFIt var = {arr, false, (arr)->len-offset, NULL}; IntArFIt_next(&var); )
void IntAr_set(IntAr *arr, int index, Int *elem, Error *err);
JSON_Value *IntAr_toJson(IntAr *self, Error *err);
void IntAr_truncate(IntAr *arr, int newLen);
bool IntArFIt_next(IntArFIt *iterator);
bool IntArRIt_next(IntArRIt *iterator);
void IntAr_binInsert(IntAr *arr, Int *elem);
void IntAr_binRemove(IntAr *arr, Int *elem);
Int *IntAr_binSearch(IntAr *arr, Int *elem);
int Int_cmpIndirectResolve(Int **left, Int **right);
Int *IntAr_pqPeek(IntAr *arr);
void IntAr_pqPopDecRef(IntAr *arr, Int *elem);
Int *IntAr_pqPop(IntAr *arr);
void IntAr_pqPush(IntAr *arr, Int *elem);
void IntAr_pqSort(IntAr *arr);
void IntAr_sort(IntAr *arr);
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_new();
void ManageChokeGroupsDispatch_incRef(ManageChokeGroupsDispatch *self);
void ManageChokeGroupsDispatch_decRef(ManageChokeGroupsDispatch *self);
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *ManageChokeGroupsDispatch_toJson(ManageChokeGroupsDispatch *self, Error *err);
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_clone(ManageChokeGroupsDispatch *self);
static inline Symbol * ManageChokeGroupsDispatch_selector(ManageChokeGroupsDispatch *self){return self->selector;}
static inline void ManageChokeGroupsDispatch_setSelector(ManageChokeGroupsDispatch *self, Symbol * value){self->selector = value;}
static inline Symbol * ManageChokeGroupsDispatch_portId(ManageChokeGroupsDispatch *self){return self->portId;}
static inline void ManageChokeGroupsDispatch_setPortId(ManageChokeGroupsDispatch *self, Symbol * value){self->portId = value;}
static inline int ManageChokeGroupsDispatch_inlet(ManageChokeGroupsDispatch *self){return self->inlet;}
static inline void ManageChokeGroupsDispatch_setInlet(ManageChokeGroupsDispatch *self, int value){self->inlet = value;}
static inline Marshal * ManageChokeGroupsDispatch_marshal(ManageChokeGroupsDispatch *self){return self->marshal;}
static inline void ManageChokeGroupsDispatch_setMarshal(ManageChokeGroupsDispatch *self, Marshal * value){self->marshal = value;}
static inline ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_castFromDispatch(Dispatch *self) {
   if (self->itype == ManageChokeGroupsDispatch_itype) {
       return (ManageChokeGroupsDispatch*)self;
   }
   return NULL;
}
static inline Dispatch *ManageChokeGroupsDispatch_castToDispatch(ManageChokeGroupsDispatch *self) {
   return (Dispatch*)self;
}
int Marshal_nthIType(int n, int *itype);
#define Marshal_foreachIType(itype) for (int __##itype = 0, itype = 0; Marshal_nthIType(__##itype, &itype); __##itype++)
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom * a3, Error * a4, Error *err, Error *err);
void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err);
MarshalSi *MarshalSi_new();
void MarshalSi_incRef(MarshalSi *self);
void MarshalSi_decRef(MarshalSi *self);
MarshalSi *MarshalSi_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *MarshalSi_toJson(MarshalSi *self, Error *err);
MarshalSi *MarshalSi_clone(MarshalSi *self);
static inline Symbol * MarshalSi_selector(MarshalSi *self){return self->selector;}
static inline void MarshalSi_setSelector(MarshalSi *self, Symbol * value){self->selector = value;}
static inline Symbol * MarshalSi_portId(MarshalSi *self){return self->portId;}
static inline void MarshalSi_setPortId(MarshalSi *self, Symbol * value){self->portId = value;}
static inline int MarshalSi_inlet(MarshalSi *self){return self->inlet;}
static inline void MarshalSi_setInlet(MarshalSi *self, int value){self->inlet = value;}
static inline MarshalSi *MarshalSi_castFromMarshal(Marshal *self) {
   if (self->itype == MarshalSi_itype) {
       return (MarshalSi*)self;
   }
   return NULL;
}
static inline Marshal *MarshalSi_castToMarshal(MarshalSi *self) {
   return (Marshal*)self;
}
MarshalSii *MarshalSii_new();
void MarshalSii_incRef(MarshalSii *self);
void MarshalSii_decRef(MarshalSii *self);
MarshalSii *MarshalSii_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *MarshalSii_toJson(MarshalSii *self, Error *err);
MarshalSii *MarshalSii_clone(MarshalSii *self);
static inline Symbol * MarshalSii_selector(MarshalSii *self){return self->selector;}
static inline void MarshalSii_setSelector(MarshalSii *self, Symbol * value){self->selector = value;}
static inline Symbol * MarshalSii_portId(MarshalSii *self){return self->portId;}
static inline void MarshalSii_setPortId(MarshalSii *self, Symbol * value){self->portId = value;}
static inline int MarshalSii_inlet(MarshalSii *self){return self->inlet;}
static inline void MarshalSii_setInlet(MarshalSii *self, int value){self->inlet = value;}
static inline MarshalSii *MarshalSii_castFromMarshal(Marshal *self) {
   if (self->itype == MarshalSii_itype) {
       return (MarshalSii*)self;
   }
   return NULL;
}
static inline Marshal *MarshalSii_castToMarshal(MarshalSii *self) {
   return (Marshal*)self;
}
MarshalSs *MarshalSs_new();
void MarshalSs_incRef(MarshalSs *self);
void MarshalSs_decRef(MarshalSs *self);
MarshalSs *MarshalSs_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *MarshalSs_toJson(MarshalSs *self, Error *err);
MarshalSs *MarshalSs_clone(MarshalSs *self);
static inline Symbol * MarshalSs_selector(MarshalSs *self){return self->selector;}
static inline void MarshalSs_setSelector(MarshalSs *self, Symbol * value){self->selector = value;}
static inline Symbol * MarshalSs_portId(MarshalSs *self){return self->portId;}
static inline void MarshalSs_setPortId(MarshalSs *self, Symbol * value){self->portId = value;}
static inline int MarshalSs_inlet(MarshalSs *self){return self->inlet;}
static inline void MarshalSs_setInlet(MarshalSs *self, int value){self->inlet = value;}
static inline MarshalSs *MarshalSs_castFromMarshal(Marshal *self) {
   if (self->itype == MarshalSs_itype) {
       return (MarshalSs*)self;
   }
   return NULL;
}
static inline Marshal *MarshalSs_castToMarshal(MarshalSs *self) {
   return (Marshal*)self;
}
MidiFileDropDispatch *MidiFileDropDispatch_new();
void MidiFileDropDispatch_incRef(MidiFileDropDispatch *self);
void MidiFileDropDispatch_decRef(MidiFileDropDispatch *self);
MidiFileDropDispatch *MidiFileDropDispatch_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *MidiFileDropDispatch_toJson(MidiFileDropDispatch *self, Error *err);
MidiFileDropDispatch *MidiFileDropDispatch_clone(MidiFileDropDispatch *self);
static inline Symbol * MidiFileDropDispatch_selector(MidiFileDropDispatch *self){return self->selector;}
static inline void MidiFileDropDispatch_setSelector(MidiFileDropDispatch *self, Symbol * value){self->selector = value;}
static inline Symbol * MidiFileDropDispatch_portId(MidiFileDropDispatch *self){return self->portId;}
static inline void MidiFileDropDispatch_setPortId(MidiFileDropDispatch *self, Symbol * value){self->portId = value;}
static inline int MidiFileDropDispatch_inlet(MidiFileDropDispatch *self){return self->inlet;}
static inline void MidiFileDropDispatch_setInlet(MidiFileDropDispatch *self, int value){self->inlet = value;}
static inline Marshal * MidiFileDropDispatch_marshal(MidiFileDropDispatch *self){return self->marshal;}
static inline void MidiFileDropDispatch_setMarshal(MidiFileDropDispatch *self, Marshal * value){self->marshal = value;}
static inline MidiFileDropDispatch *MidiFileDropDispatch_castFromDispatch(Dispatch *self) {
   if (self->itype == MidiFileDropDispatch_itype) {
       return (MidiFileDropDispatch*)self;
   }
   return NULL;
}
static inline Dispatch *MidiFileDropDispatch_castToDispatch(MidiFileDropDispatch *self) {
   return (Dispatch*)self;
}
MusicalContext *MusicalContext_new();
void MusicalContext_incRef(MusicalContext *self);
void MusicalContext_decRef(MusicalContext *self);
MusicalContext *MusicalContext_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *MusicalContext_toJson(MusicalContext *self, Error *err);
MusicalContext *MusicalContext_clone(MusicalContext *self);
static inline Ticks MusicalContext_ticksPerQuarterNote(MusicalContext *self){return self->ticksPerQuarterNote;}
static inline void MusicalContext_setTicksPerQuarterNote(MusicalContext *self, Ticks value){self->ticksPerQuarterNote = value;}
static inline Ticks MusicalContext_quarterNotesPerMeasure(MusicalContext *self){return self->quarterNotesPerMeasure;}
static inline void MusicalContext_setQuarterNotesPerMeasure(MusicalContext *self, Ticks value){self->quarterNotesPerMeasure = value;}
NoteEvent *NoteEvent_new();
void NoteEvent_incRef(NoteEvent *self);
void NoteEvent_decRef(NoteEvent *self);
NoteEvent *NoteEvent_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *NoteEvent_toJson(NoteEvent *self, Error *err);
NoteEvent *NoteEvent_clone(NoteEvent *self);
static inline uint8_t NoteEvent_pitch(NoteEvent *self){return self->pitch;}
static inline void NoteEvent_setPitch(NoteEvent *self, uint8_t value){self->pitch = value;}
static inline uint8_t NoteEvent_velocity(NoteEvent *self){return self->velocity;}
static inline void NoteEvent_setVelocity(NoteEvent *self, uint8_t value){self->velocity = value;}
static inline Ticks NoteEvent_stime(NoteEvent *self){return self->stime;}
static inline void NoteEvent_setStime(NoteEvent *self, Ticks value){self->stime = value;}
static inline Ticks NoteEvent_duration(NoteEvent *self){return self->duration;}
static inline void NoteEvent_setDuration(NoteEvent *self, Ticks value){self->duration = value;}
#define NoteEventAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
NoteEventAr *NoteEventAr_clone(NoteEventAr *arr);
void NoteEventAr_decRef(NoteEventAr *arr);
void NoteEventAr_fit(NoteEventAr *arr);
#define NoteEventAr_foreach(var, arr)               for (NoteEventArFIt var = {arr, false, 0, NULL};        NoteEventArFIt_next(&var); )
#define NoteEventAr_foreachOffset(var, arr, offset) for (NoteEventArFIt var = {arr, false, offset-1, NULL}; NoteEventArFIt_next(&var); )
NoteEventAr *NoteEventAr_fromJson(JSON_Value *jval, Error *err);
NoteEvent *NoteEventAr_get(NoteEventAr *arr, int index, Error *err);
void NoteEventAr_incRef(NoteEventAr *arr);
void NoteEventAr_insert(NoteEventAr *arr, int index, NoteEvent *elem, Error *err);
int NoteEventAr_last(NoteEventAr *arr);
int NoteEventAr_len(NoteEventAr *arr);
NoteEventAr *NoteEventAr_new();
void NoteEventAr_pop(NoteEventAr *arr, Error *err);
NoteEvent *NoteEventAr_pop(NoteEventAr *arr, Error *err);
void NoteEventAr_push(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_remove(NoteEventAr *arr, int index, Error *err);
void NoteEventAr_reserve(NoteEventAr *arr, int newCap);
#define NoteEventAr_rforeach(var, arr)               for (NoteEventArFIt var = {arr, false, (arr)->len, NULL};        NoteEventArFIt_next(&var); )
#define NoteEventAr_rforeachOffset(var, arr, offset) for (NoteEventArFIt var = {arr, false, (arr)->len-offset, NULL}; NoteEventArFIt_next(&var); )
void NoteEventAr_set(NoteEventAr *arr, int index, NoteEvent *elem, Error *err);
JSON_Value *NoteEventAr_toJson(NoteEventAr *self, Error *err);
void NoteEventAr_truncate(NoteEventAr *arr, int newLen);
bool NoteEventArFIt_next(NoteEventArFIt *iterator);
bool NoteEventArRIt_next(NoteEventArRIt *iterator);
void NoteEventAr_binInsert(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_binRemove(NoteEventAr *arr, NoteEvent *elem);
NoteEvent *NoteEventAr_binSearch(NoteEventAr *arr, NoteEvent *elem);
int NoteEvent_cmpIndirectResolve(NoteEvent **left, NoteEvent **right);
NoteEvent *NoteEventAr_pqPeek(NoteEventAr *arr);
void NoteEventAr_pqPopDecRef(NoteEventAr *arr, NoteEvent *elem);
NoteEvent *NoteEventAr_pqPop(NoteEventAr *arr);
void NoteEventAr_pqPush(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_pqSort(NoteEventAr *arr);
void NoteEventAr_sort(NoteEventAr *arr);
NoteOutlet *NoteOutlet_new();
void NoteOutlet_incRef(NoteOutlet *self);
void NoteOutlet_decRef(NoteOutlet *self);
NoteOutlet *NoteOutlet_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *NoteOutlet_toJson(NoteOutlet *self, Error *err);
NoteOutlet *NoteOutlet_clone(NoteOutlet *self);
static inline AtomAr *NoteOutlet_atoms(NoteOutlet *self){return self->atoms;}
void NoteOutlet_setAtoms(NoteOutlet *self, AtomAr *value);
static inline Port *NoteOutlet_port(NoteOutlet *self){return self->port;}
void NoteOutlet_setPort(NoteOutlet *self, Port *value);
static inline NoteOutlet *NoteOutlet_castFromOutlet(Outlet *self) {
   if (self->itype == NoteOutlet_itype) {
       return (NoteOutlet*)self;
   }
   return NULL;
}
static inline Outlet *NoteOutlet_castToOutlet(NoteOutlet *self) {
   return (Outlet*)self;
}
NoteSequence *NoteSequence_new();
void NoteSequence_incRef(NoteSequence *self);
void NoteSequence_decRef(NoteSequence *self);
NoteSequence *NoteSequence_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *NoteSequence_toJson(NoteSequence *self, Error *err);
NoteSequence *NoteSequence_clone(NoteSequence *self);
static inline long NoteSequence_version(NoteSequence *self){return self->version;}
static inline void NoteSequence_setVersion(NoteSequence *self, long value){self->version = value;}
static inline Ticks NoteSequence_startTime(NoteSequence *self){return self->startTime;}
static inline void NoteSequence_setStartTime(NoteSequence *self, Ticks value){self->startTime = value;}
static inline OutletSpecifier *NoteSequence_outletSpecifier(NoteSequence *self){return self->outletSpecifier;}
void NoteSequence_setOutletSpecifier(NoteSequence *self, OutletSpecifier *value);
static inline Ticks NoteSequence_sequenceLength(NoteSequence *self){return self->sequenceLength;}
static inline void NoteSequence_setSequenceLength(NoteSequence *self, Ticks value){self->sequenceLength = value;}
static inline int NoteSequence_cursor(NoteSequence *self){return self->cursor;}
static inline void NoteSequence_setCursor(NoteSequence *self, int value){self->cursor = value;}
static inline bool NoteSequence_cycle(NoteSequence *self){return self->cycle;}
static inline void NoteSequence_setCycle(NoteSequence *self, bool value){self->cycle = value;}
static inline Ticks NoteSequence_nextOffEvent(NoteSequence *self){return self->nextOffEvent;}
static inline void NoteSequence_setNextOffEvent(NoteSequence *self, Ticks value){self->nextOffEvent = value;}
static inline Ticks NoteSequence_nextOnEvent(NoteSequence *self){return self->nextOnEvent;}
static inline void NoteSequence_setNextOnEvent(NoteSequence *self, Ticks value){self->nextOnEvent = value;}
static inline bool NoteSequence_inEndgroup(NoteSequence *self){return self->inEndgroup;}
static inline void NoteSequence_setInEndgroup(NoteSequence *self, bool value){self->inEndgroup = value;}
static inline Outlet *NoteSequence_outlet(NoteSequence *self){return self->outlet;}
void NoteSequence_setOutlet(NoteSequence *self, Outlet *value);
static inline NoteSequence * NoteSequence_recordingSeq(NoteSequence *self){return self->recordingSeq;}
static inline void NoteSequence_setRecordingSeq(NoteSequence *self, NoteSequence * value){self->recordingSeq = value;}
static inline TimedOffAr *NoteSequence_offs(NoteSequence *self){return self->offs;}
void NoteSequence_setOffs(NoteSequence *self, TimedOffAr *value);
static inline NoteEventAr *NoteSequence_events(NoteSequence *self){return self->events;}
void NoteSequence_setEvents(NoteSequence *self, NoteEventAr *value);
static inline NoteSequence *NoteSequence_castFromSequence(Sequence *self) {
   if (self->itype == NoteSequence_itype) {
       return (NoteSequence*)self;
   }
   return NULL;
}
static inline Sequence *NoteSequence_castToSequence(NoteSequence *self) {
   return (Sequence*)self;
}
NullOutlet *NullOutlet_new();
void NullOutlet_incRef(NullOutlet *self);
void NullOutlet_decRef(NullOutlet *self);
NullOutlet *NullOutlet_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *NullOutlet_toJson(NullOutlet *self, Error *err);
NullOutlet *NullOutlet_clone(NullOutlet *self);
static inline int NullOutlet_unused(NullOutlet *self){return self->unused;}
static inline void NullOutlet_setUnused(NullOutlet *self, int value){self->unused = value;}
static inline NullOutlet *NullOutlet_castFromOutlet(Outlet *self) {
   if (self->itype == NullOutlet_itype) {
       return (NullOutlet*)self;
   }
   return NULL;
}
static inline Outlet *NullOutlet_castToOutlet(NullOutlet *self) {
   return (Outlet*)self;
}
int Outlet_nthIType(int n, int *itype);
#define Outlet_foreachIType(itype) for (int __##itype = 0, itype = 0; Outlet_nthIType(__##itype, &itype); __##itype++)
void Outlet_sendNote(Outlet *self, uint8_t a1, uint8_t a2, Error *err);
void Outlet_sendFloat(Outlet *self, double a1, Error *err);
OutletSpecifier *OutletSpecifier_new();
void OutletSpecifier_incRef(OutletSpecifier *self);
void OutletSpecifier_decRef(OutletSpecifier *self);
OutletSpecifier *OutletSpecifier_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *OutletSpecifier_toJson(OutletSpecifier *self, Error *err);
OutletSpecifier *OutletSpecifier_clone(OutletSpecifier *self);
static inline Symbol * OutletSpecifier_track(OutletSpecifier *self){return self->track;}
static inline void OutletSpecifier_setTrack(OutletSpecifier *self, Symbol * value){self->track = value;}
static inline int OutletSpecifier_pluginIndex(OutletSpecifier *self){return self->pluginIndex;}
static inline void OutletSpecifier_setPluginIndex(OutletSpecifier *self, int value){self->pluginIndex = value;}
static inline Symbol * OutletSpecifier_parameter(OutletSpecifier *self){return self->parameter;}
static inline void OutletSpecifier_setParameter(OutletSpecifier *self, Symbol * value){self->parameter = value;}
static inline int OutletSpecifier_paramIndex(OutletSpecifier *self){return self->paramIndex;}
static inline void OutletSpecifier_setParamIndex(OutletSpecifier *self, int value){self->paramIndex = value;}
Pad *Pad_new();
void Pad_incRef(Pad *self);
void Pad_decRef(Pad *self);
Pad *Pad_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Pad_toJson(Pad *self, Error *err);
Pad *Pad_clone(Pad *self);
static inline Symbol * Pad_trackName(Pad *self){return self->trackName;}
static inline void Pad_setTrackName(Pad *self, Symbol * value){self->trackName = value;}
static inline int Pad_padIndex(Pad *self){return self->padIndex;}
static inline void Pad_setPadIndex(Pad *self, int value){self->padIndex = value;}
static inline Sequence *Pad_SequenceAr(Pad *self){return self->SequenceAr;}
void Pad_setSequenceAr(Pad *self, Sequence *value);
static inline bool Pad_chokeGroupGlobal(Pad *self){return self->chokeGroupGlobal;}
static inline void Pad_setChokeGroupGlobal(Pad *self, bool value){self->chokeGroupGlobal = value;}
static inline int Pad_chokeGroupInstrument(Pad *self){return self->chokeGroupInstrument;}
static inline void Pad_setChokeGroupInstrument(Pad *self, int value){self->chokeGroupInstrument = value;}
static inline int Pad_chokeGroupIndex(Pad *self){return self->chokeGroupIndex;}
static inline void Pad_setChokeGroupIndex(Pad *self, int value){self->chokeGroupIndex = value;}
static inline int64_t Pad_chokeGroup(Pad *self){return self->chokeGroup;}
static inline void Pad_setChokeGroup(Pad *self, int64_t value){self->chokeGroup = value;}
static inline bool Pad_noteReleasePending(Pad *self){return self->noteReleasePending;}
static inline void Pad_setNoteReleasePending(Pad *self, bool value){self->noteReleasePending = value;}
static inline bool Pad_inEndgroup(Pad *self){return self->inEndgroup;}
static inline void Pad_setInEndgroup(Pad *self, bool value){self->inEndgroup = value;}
static inline Track *Pad_track(Pad *self){return self->track;}
void Pad_setTrack(Pad *self, Track *value);
static inline bool Pad_useMasterClock(Pad *self){return self->useMasterClock;}
static inline void Pad_setUseMasterClock(Pad *self, bool value){self->useMasterClock = value;}
#define PadAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PadAr *PadAr_clone(PadAr *arr);
void PadAr_decRef(PadAr *arr);
void PadAr_fit(PadAr *arr);
#define PadAr_foreach(var, arr)               for (PadArFIt var = {arr, false, 0, NULL};        PadArFIt_next(&var); )
#define PadAr_foreachOffset(var, arr, offset) for (PadArFIt var = {arr, false, offset-1, NULL}; PadArFIt_next(&var); )
PadAr *PadAr_fromJson(JSON_Value *jval, Error *err);
Pad *PadAr_get(PadAr *arr, int index, Error *err);
void PadAr_incRef(PadAr *arr);
void PadAr_insert(PadAr *arr, int index, Pad *elem, Error *err);
int PadAr_last(PadAr *arr);
int PadAr_len(PadAr *arr);
PadAr *PadAr_new();
void PadAr_pop(PadAr *arr, Error *err);
Pad *PadAr_pop(PadAr *arr, Error *err);
void PadAr_push(PadAr *arr, Pad *elem);
void PadAr_remove(PadAr *arr, int index, Error *err);
void PadAr_reserve(PadAr *arr, int newCap);
#define PadAr_rforeach(var, arr)               for (PadArFIt var = {arr, false, (arr)->len, NULL};        PadArFIt_next(&var); )
#define PadAr_rforeachOffset(var, arr, offset) for (PadArFIt var = {arr, false, (arr)->len-offset, NULL}; PadArFIt_next(&var); )
void PadAr_set(PadAr *arr, int index, Pad *elem, Error *err);
JSON_Value *PadAr_toJson(PadAr *self, Error *err);
void PadAr_truncate(PadAr *arr, int newLen);
bool PadArFIt_next(PadArFIt *iterator);
bool PadArRIt_next(PadArRIt *iterator);
static inline MaxObject Port_obj(Port *self){return self->obj;}
static inline void Port_setObj(Port *self, MaxObject value){self->obj = value;}
static inline long Port_inletnum(Port *self){return self->inletnum;}
static inline void Port_setInletnum(Port *self, long value){self->inletnum = value;}
static inline PtrAr *Port_proxy(Port *self){return self->proxy;}
void Port_setProxy(Port *self, PtrAr *value);
static inline PtrAr *Port_outlet(Port *self){return self->outlet;}
void Port_setOutlet(Port *self, PtrAr *value);
static inline Symbol * Port_track(Port *self){return self->track;}
static inline void Port_setTrack(Port *self, Symbol * value){self->track = value;}
static inline Symbol * Port_id(Port *self){return self->id;}
static inline void Port_setId(Port *self, Symbol * value){self->id = value;}
static inline long Port_intInlets(Port *self){return self->intInlets;}
static inline void Port_setIntInlets(Port *self, long value){self->intInlets = value;}
static inline long Port_intOutlets(Port *self){return self->intOutlets;}
static inline void Port_setIntOutlets(Port *self, long value){self->intOutlets = value;}
static inline void * Port_hub(Port *self){return self->hub;}
static inline void Port_setHub(Port *self, void * value){self->hub = value;}
static inline Port_anythingDispatchFunc Port_anythingDispatch(Port *self){return self->anythingDispatch;}
static inline void Port_setAnythingDispatch(Port *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc Port_intDispatch(Port *self){return self->intDispatch;}
static inline void Port_setIntDispatch(Port *self, Port_intDispatchFunc value){self->intDispatch = value;}
PortFind *PortFind_new();
void PortFind_incRef(PortFind *self);
void PortFind_decRef(PortFind *self);
PortFind *PortFind_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *PortFind_toJson(PortFind *self, Error *err);
PortFind *PortFind_clone(PortFind *self);
static inline PortFindCellAr *PortFind_objects(PortFind *self){return self->objects;}
void PortFind_setObjects(PortFind *self, PortFindCellAr *value);
static inline void * PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void * value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
PortFindCell *PortFindCell_new();
void PortFindCell_incRef(PortFindCell *self);
void PortFindCell_decRef(PortFindCell *self);
PortFindCell *PortFindCell_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *PortFindCell_toJson(PortFindCell *self, Error *err);
PortFindCell *PortFindCell_clone(PortFindCell *self);
static inline Port PortFindCell_reciever(PortFindCell *self){return self->reciever;}
static inline void PortFindCell_setReciever(PortFindCell *self, Port value){self->reciever = value;}
static inline Symbol * PortFindCell_varname(PortFindCell *self){return self->varname;}
static inline void PortFindCell_setVarname(PortFindCell *self, Symbol * value){self->varname = value;}
#define PortFindCellAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PortFindCellAr *PortFindCellAr_clone(PortFindCellAr *arr);
void PortFindCellAr_decRef(PortFindCellAr *arr);
void PortFindCellAr_fit(PortFindCellAr *arr);
#define PortFindCellAr_foreach(var, arr)               for (PortFindCellArFIt var = {arr, false, 0, NULL};        PortFindCellArFIt_next(&var); )
#define PortFindCellAr_foreachOffset(var, arr, offset) for (PortFindCellArFIt var = {arr, false, offset-1, NULL}; PortFindCellArFIt_next(&var); )
PortFindCellAr *PortFindCellAr_fromJson(JSON_Value *jval, Error *err);
PortFindCell *PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err);
void PortFindCellAr_incRef(PortFindCellAr *arr);
void PortFindCellAr_insert(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err);
int PortFindCellAr_last(PortFindCellAr *arr);
int PortFindCellAr_len(PortFindCellAr *arr);
PortFindCellAr *PortFindCellAr_new();
void PortFindCellAr_pop(PortFindCellAr *arr, Error *err);
PortFindCell *PortFindCellAr_pop(PortFindCellAr *arr, Error *err);
void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell *elem);
void PortFindCellAr_remove(PortFindCellAr *arr, int index, Error *err);
void PortFindCellAr_reserve(PortFindCellAr *arr, int newCap);
#define PortFindCellAr_rforeach(var, arr)               for (PortFindCellArFIt var = {arr, false, (arr)->len, NULL};        PortFindCellArFIt_next(&var); )
#define PortFindCellAr_rforeachOffset(var, arr, offset) for (PortFindCellArFIt var = {arr, false, (arr)->len-offset, NULL}; PortFindCellArFIt_next(&var); )
void PortFindCellAr_set(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err);
JSON_Value *PortFindCellAr_toJson(PortFindCellAr *self, Error *err);
void PortFindCellAr_truncate(PortFindCellAr *arr, int newLen);
bool PortFindCellArFIt_next(PortFindCellArFIt *iterator);
bool PortFindCellArRIt_next(PortFindCellArRIt *iterator);
PortRef *PortRef_new();
void PortRef_incRef(PortRef *self);
void PortRef_decRef(PortRef *self);
PortRef *PortRef_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *PortRef_toJson(PortRef *self, Error *err);
PortRef *PortRef_clone(PortRef *self);
static inline Port * PortRef_port(PortRef *self){return self->port;}
static inline void PortRef_setPort(PortRef *self, Port * value){self->port = value;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}
static inline void PortRef_setOutlet(PortRef *self, int value){self->outlet = value;}
Ptr *Ptr_new();
void Ptr_incRef(Ptr *self);
void Ptr_decRef(Ptr *self);
Ptr *Ptr_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Ptr_toJson(Ptr *self, Error *err);
Ptr *Ptr_clone(Ptr *self);
static inline void * Ptr_p(Ptr *self){return self->p;}
static inline void Ptr_setP(Ptr *self, void * value){self->p = value;}
#define PtrAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PtrAr *PtrAr_clone(PtrAr *arr);
void PtrAr_decRef(PtrAr *arr);
void PtrAr_fit(PtrAr *arr);
#define PtrAr_foreach(var, arr)               for (PtrArFIt var = {arr, false, 0, NULL};        PtrArFIt_next(&var); )
#define PtrAr_foreachOffset(var, arr, offset) for (PtrArFIt var = {arr, false, offset-1, NULL}; PtrArFIt_next(&var); )
PtrAr *PtrAr_fromJson(JSON_Value *jval, Error *err);
Ptr *PtrAr_get(PtrAr *arr, int index, Error *err);
void PtrAr_incRef(PtrAr *arr);
void PtrAr_insert(PtrAr *arr, int index, Ptr *elem, Error *err);
int PtrAr_last(PtrAr *arr);
int PtrAr_len(PtrAr *arr);
PtrAr *PtrAr_new();
void PtrAr_pop(PtrAr *arr, Error *err);
Ptr *PtrAr_pop(PtrAr *arr, Error *err);
void PtrAr_push(PtrAr *arr, Ptr *elem);
void PtrAr_remove(PtrAr *arr, int index, Error *err);
void PtrAr_reserve(PtrAr *arr, int newCap);
#define PtrAr_rforeach(var, arr)               for (PtrArFIt var = {arr, false, (arr)->len, NULL};        PtrArFIt_next(&var); )
#define PtrAr_rforeachOffset(var, arr, offset) for (PtrArFIt var = {arr, false, (arr)->len-offset, NULL}; PtrArFIt_next(&var); )
void PtrAr_set(PtrAr *arr, int index, Ptr *elem, Error *err);
JSON_Value *PtrAr_toJson(PtrAr *self, Error *err);
void PtrAr_truncate(PtrAr *arr, int newLen);
bool PtrArFIt_next(PtrArFIt *iterator);
bool PtrArRIt_next(PtrArRIt *iterator);
RecordBuffer *RecordBuffer_new();
void RecordBuffer_incRef(RecordBuffer *self);
void RecordBuffer_decRef(RecordBuffer *self);
RecordBuffer *RecordBuffer_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *RecordBuffer_toJson(RecordBuffer *self, Error *err);
RecordBuffer *RecordBuffer_clone(RecordBuffer *self);
static inline Ticks RecordBuffer_recordStart(RecordBuffer *self){return self->recordStart;}
static inline void RecordBuffer_setRecordStart(RecordBuffer *self, Ticks value){self->recordStart = value;}
static inline SequenceAr *RecordBuffer_sequences(RecordBuffer *self){return self->sequences;}
void RecordBuffer_setSequences(RecordBuffer *self, SequenceAr *value);
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_new();
void SelectNextPushedPadDispatch_incRef(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_decRef(SelectNextPushedPadDispatch *self);
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *SelectNextPushedPadDispatch_toJson(SelectNextPushedPadDispatch *self, Error *err);
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_clone(SelectNextPushedPadDispatch *self);
static inline Symbol * SelectNextPushedPadDispatch_selector(SelectNextPushedPadDispatch *self){return self->selector;}
static inline void SelectNextPushedPadDispatch_setSelector(SelectNextPushedPadDispatch *self, Symbol * value){self->selector = value;}
static inline Symbol * SelectNextPushedPadDispatch_portId(SelectNextPushedPadDispatch *self){return self->portId;}
static inline void SelectNextPushedPadDispatch_setPortId(SelectNextPushedPadDispatch *self, Symbol * value){self->portId = value;}
static inline int SelectNextPushedPadDispatch_inlet(SelectNextPushedPadDispatch *self){return self->inlet;}
static inline void SelectNextPushedPadDispatch_setInlet(SelectNextPushedPadDispatch *self, int value){self->inlet = value;}
static inline Marshal * SelectNextPushedPadDispatch_marshal(SelectNextPushedPadDispatch *self){return self->marshal;}
static inline void SelectNextPushedPadDispatch_setMarshal(SelectNextPushedPadDispatch *self, Marshal * value){self->marshal = value;}
static inline SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_castFromDispatch(Dispatch *self) {
   if (self->itype == SelectNextPushedPadDispatch_itype) {
       return (SelectNextPushedPadDispatch*)self;
   }
   return NULL;
}
static inline Dispatch *SelectNextPushedPadDispatch_castToDispatch(SelectNextPushedPadDispatch *self) {
   return (Dispatch*)self;
}
int Sequence_nthIType(int n, int *itype);
#define Sequence_foreachIType(itype) for (int __##itype = 0, itype = 0; Sequence_nthIType(__##itype, &itype); __##itype++)
void Sequence_start(Sequence *self, Ticks a1, Ticks a2, TimedPq *a3, RecordBuffer *a4, Error * *a5, Error *err, Error *err);
void Sequence_drive(Sequence *self, Ticks a1, TimedPq *a2, Error * a3, Error *err, Error *err);
void Sequence_stop(Sequence *self, Ticks a1, Error * a2, Error *err, Error *err);
void Sequence_padNoteOff(Sequence *self, Ticks a1, Error * a2, Error *err, Error *err);
void Sequence_setCycle(Sequence *self, bool a1, Error *err);
void Sequence_free(Sequence *self, Error *err);
Sequence *Sequence_compactNew(Sequence *self, Ticks a1, Error *err);
void Sequence_compactConcat(Sequence *self, Sequence *a1, Error * a2, Error *err, Error *err);
void Sequence_compactSortEvents(Sequence *self, Error *err);
Ticks Sequence_compactComputeSequenceLength(Sequence *self, Error *err);
void Sequence_compactFinish(Sequence *self, Ticks a1, Ticks a2, Error * a3, Error *err, Error *err);
#define SequenceAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SequenceAr *SequenceAr_clone(SequenceAr *arr);
void SequenceAr_decRef(SequenceAr *arr);
void SequenceAr_fit(SequenceAr *arr);
#define SequenceAr_foreach(var, arr)               for (SequenceArFIt var = {arr, false, 0, NULL};        SequenceArFIt_next(&var); )
#define SequenceAr_foreachOffset(var, arr, offset) for (SequenceArFIt var = {arr, false, offset-1, NULL}; SequenceArFIt_next(&var); )
SequenceAr *SequenceAr_fromJson(JSON_Value *jval, Error *err);
Sequence *SequenceAr_get(SequenceAr *arr, int index, Error *err);
void SequenceAr_incRef(SequenceAr *arr);
void SequenceAr_insert(SequenceAr *arr, int index, Sequence *elem, Error *err);
int SequenceAr_last(SequenceAr *arr);
int SequenceAr_len(SequenceAr *arr);
SequenceAr *SequenceAr_new();
void SequenceAr_pop(SequenceAr *arr, Error *err);
Sequence *SequenceAr_pop(SequenceAr *arr, Error *err);
void SequenceAr_push(SequenceAr *arr, Sequence *elem);
void SequenceAr_remove(SequenceAr *arr, int index, Error *err);
void SequenceAr_reserve(SequenceAr *arr, int newCap);
#define SequenceAr_rforeach(var, arr)               for (SequenceArFIt var = {arr, false, (arr)->len, NULL};        SequenceArFIt_next(&var); )
#define SequenceAr_rforeachOffset(var, arr, offset) for (SequenceArFIt var = {arr, false, (arr)->len-offset, NULL}; SequenceArFIt_next(&var); )
void SequenceAr_set(SequenceAr *arr, int index, Sequence *elem, Error *err);
JSON_Value *SequenceAr_toJson(SequenceAr *self, Error *err);
void SequenceAr_truncate(SequenceAr *arr, int newLen);
bool SequenceArFIt_next(SequenceArFIt *iterator);
bool SequenceArRIt_next(SequenceArRIt *iterator);
void SequenceAr_binInsert(SequenceAr *arr, Sequence *elem);
void SequenceAr_binRemove(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_binSearch(SequenceAr *arr, Sequence *elem);
int Sequence_cmpPpIndirectResolve(Sequence **left, Sequence **right);
Sequence *SequenceAr_pqPeek(SequenceAr *arr);
void SequenceAr_pqPopDecRef(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPop(SequenceAr *arr);
void SequenceAr_pqPush(SequenceAr *arr, Sequence *elem);
void SequenceAr_pqSort(SequenceAr *arr);
void SequenceAr_sort(SequenceAr *arr);
void SequenceAr_binInsertPointer(SequenceAr *arr, Sequence *elem);
void SequenceAr_binRemovePointer(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_binSearchPointer(SequenceAr *arr, Sequence *elem);
int Sequence_cmpPointerPpIndirectResolve(Sequence **left, Sequence **right);
Sequence *SequenceAr_pqPeekPointer(SequenceAr *arr);
void SequenceAr_pqPopDecRefPointer(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPopPointer(SequenceAr *arr);
void SequenceAr_pqPushPointer(SequenceAr *arr, Sequence *elem);
void SequenceAr_pqSortPointer(SequenceAr *arr);
void SequenceAr_sortPointer(SequenceAr *arr);
#define StringAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
StringAr *StringAr_clone(StringAr *arr);
void StringAr_decRef(StringAr *arr);
void StringAr_fit(StringAr *arr);
#define StringAr_foreach(var, arr)               for (StringArFIt var = {arr, false, 0, NULL};        StringArFIt_next(&var); )
#define StringAr_foreachOffset(var, arr, offset) for (StringArFIt var = {arr, false, offset-1, NULL}; StringArFIt_next(&var); )
StringAr *StringAr_fromJson(JSON_Value *jval, Error *err);
String *StringAr_get(StringAr *arr, int index, Error *err);
void StringAr_incRef(StringAr *arr);
void StringAr_insert(StringAr *arr, int index, String *elem, Error *err);
int StringAr_last(StringAr *arr);
int StringAr_len(StringAr *arr);
StringAr *StringAr_new();
void StringAr_pop(StringAr *arr, Error *err);
String *StringAr_pop(StringAr *arr, Error *err);
void StringAr_push(StringAr *arr, String *elem);
void StringAr_remove(StringAr *arr, int index, Error *err);
void StringAr_reserve(StringAr *arr, int newCap);
#define StringAr_rforeach(var, arr)               for (StringArFIt var = {arr, false, (arr)->len, NULL};        StringArFIt_next(&var); )
#define StringAr_rforeachOffset(var, arr, offset) for (StringArFIt var = {arr, false, (arr)->len-offset, NULL}; StringArFIt_next(&var); )
void StringAr_set(StringAr *arr, int index, String *elem, Error *err);
JSON_Value *StringAr_toJson(StringAr *self, Error *err);
void StringAr_truncate(StringAr *arr, int newLen);
bool StringArFIt_next(StringArFIt *iterator);
bool StringArRIt_next(StringArRIt *iterator);
void StringAr_binInsert(StringAr *arr, String *elem);
void StringAr_binRemove(StringAr *arr, String *elem);
String *StringAr_binSearch(StringAr *arr, String *elem);
int String_cmpIndirectResolve(String **left, String **right);
String *StringAr_pqPeek(StringAr *arr);
void StringAr_pqPopDecRef(StringAr *arr, String *elem);
String *StringAr_pqPop(StringAr *arr);
void StringAr_pqPush(StringAr *arr, String *elem);
void StringAr_pqSort(StringAr *arr);
void StringAr_sort(StringAr *arr);
#define SymbolAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SymbolAr *SymbolAr_clone(SymbolAr *arr);
void SymbolAr_decRef(SymbolAr *arr);
void SymbolAr_fit(SymbolAr *arr);
#define SymbolAr_foreach(var, arr)               for (SymbolArFIt var = {arr, false, 0, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_foreachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, offset-1, NULL}; SymbolArFIt_next(&var); )
SymbolAr *SymbolAr_fromJson(JSON_Value *jval, Error *err);
Symbol *SymbolAr_get(SymbolAr *arr, int index, Error *err);
void SymbolAr_incRef(SymbolAr *arr);
void SymbolAr_insert(SymbolAr *arr, int index, Symbol *elem, Error *err);
int SymbolAr_last(SymbolAr *arr);
int SymbolAr_len(SymbolAr *arr);
SymbolAr *SymbolAr_new();
void SymbolAr_pop(SymbolAr *arr, Error *err);
Symbol *SymbolAr_pop(SymbolAr *arr, Error *err);
void SymbolAr_push(SymbolAr *arr, Symbol *elem);
void SymbolAr_remove(SymbolAr *arr, int index, Error *err);
void SymbolAr_reserve(SymbolAr *arr, int newCap);
#define SymbolAr_rforeach(var, arr)               for (SymbolArFIt var = {arr, false, (arr)->len, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_rforeachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, (arr)->len-offset, NULL}; SymbolArFIt_next(&var); )
void SymbolAr_set(SymbolAr *arr, int index, Symbol *elem, Error *err);
JSON_Value *SymbolAr_toJson(SymbolAr *self, Error *err);
void SymbolAr_truncate(SymbolAr *arr, int newLen);
bool SymbolArFIt_next(SymbolArFIt *iterator);
bool SymbolArRIt_next(SymbolArRIt *iterator);
void SymbolAr_binInsertUnderlying(SymbolAr *arr, Symbol *elem);
void SymbolAr_binRemoveUnderlying(SymbolAr *arr, Symbol *elem);
Symbol *SymbolAr_binSearchUnderlying(SymbolAr *arr, Symbol *elem);
int Symbol_cmpUnderlyingIndirectResolve(Symbol **left, Symbol **right);
Symbol *SymbolAr_pqPeekUnderlying(SymbolAr *arr);
void SymbolAr_pqPopDecRefUnderlying(SymbolAr *arr, Symbol *elem);
Symbol *SymbolAr_pqPopUnderlying(SymbolAr *arr);
void SymbolAr_pqPushUnderlying(SymbolAr *arr, Symbol *elem);
void SymbolAr_pqSortUnderlying(SymbolAr *arr);
void SymbolAr_sortUnderlying(SymbolAr *arr);
#define SymbolAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SymbolAr *SymbolAr_clone(SymbolAr *arr);
void SymbolAr_decRef(SymbolAr *arr);
void SymbolAr_fit(SymbolAr *arr);
#define SymbolAr_foreach(var, arr)               for (SymbolArFIt var = {arr, false, 0, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_foreachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, offset-1, NULL}; SymbolArFIt_next(&var); )
SymbolAr *SymbolAr_fromJson(JSON_Value *jval, Error *err);
Symbol *SymbolAr_get(SymbolAr *arr, int index, Error *err);
void SymbolAr_incRef(SymbolAr *arr);
void SymbolAr_insert(SymbolAr *arr, int index, Symbol *elem, Error *err);
int SymbolAr_last(SymbolAr *arr);
int SymbolAr_len(SymbolAr *arr);
SymbolAr *SymbolAr_new();
void SymbolAr_pop(SymbolAr *arr, Error *err);
Symbol *SymbolAr_pop(SymbolAr *arr, Error *err);
void SymbolAr_push(SymbolAr *arr, Symbol *elem);
void SymbolAr_remove(SymbolAr *arr, int index, Error *err);
void SymbolAr_reserve(SymbolAr *arr, int newCap);
#define SymbolAr_rforeach(var, arr)               for (SymbolArFIt var = {arr, false, (arr)->len, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_rforeachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, (arr)->len-offset, NULL}; SymbolArFIt_next(&var); )
void SymbolAr_set(SymbolAr *arr, int index, Symbol *elem, Error *err);
JSON_Value *SymbolAr_toJson(SymbolAr *self, Error *err);
void SymbolAr_truncate(SymbolAr *arr, int newLen);
bool SymbolArFIt_next(SymbolArFIt *iterator);
bool SymbolArRIt_next(SymbolArRIt *iterator);
Timed *Timed_new();
void Timed_incRef(Timed *self);
void Timed_decRef(Timed *self);
Timed *Timed_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Timed_toJson(Timed *self, Error *err);
Timed *Timed_clone(Timed *self);
static inline Ticks Timed_time(Timed *self){return self->time;}
static inline void Timed_setTime(Timed *self, Ticks value){self->time = value;}
static inline int Timed_version(Timed *self){return self->version;}
static inline void Timed_setVersion(Timed *self, int value){self->version = value;}
static inline Sequence *Timed_sequence(Timed *self){return self->sequence;}
void Timed_setSequence(Timed *self, Sequence *value);
TimedOff *TimedOff_new();
void TimedOff_incRef(TimedOff *self);
void TimedOff_decRef(TimedOff *self);
TimedOff *TimedOff_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *TimedOff_toJson(TimedOff *self, Error *err);
TimedOff *TimedOff_clone(TimedOff *self);
static inline Ticks TimedOff_time(TimedOff *self){return self->time;}
static inline void TimedOff_setTime(TimedOff *self, Ticks value){self->time = value;}
static inline int TimedOff_pitch(TimedOff *self){return self->pitch;}
static inline void TimedOff_setPitch(TimedOff *self, int value){self->pitch = value;}
#define TimedOffAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
TimedOffAr *TimedOffAr_clone(TimedOffAr *arr);
void TimedOffAr_decRef(TimedOffAr *arr);
void TimedOffAr_fit(TimedOffAr *arr);
#define TimedOffAr_foreach(var, arr)               for (TimedOffArFIt var = {arr, false, 0, NULL};        TimedOffArFIt_next(&var); )
#define TimedOffAr_foreachOffset(var, arr, offset) for (TimedOffArFIt var = {arr, false, offset-1, NULL}; TimedOffArFIt_next(&var); )
TimedOffAr *TimedOffAr_fromJson(JSON_Value *jval, Error *err);
TimedOff *TimedOffAr_get(TimedOffAr *arr, int index, Error *err);
void TimedOffAr_incRef(TimedOffAr *arr);
void TimedOffAr_insert(TimedOffAr *arr, int index, TimedOff *elem, Error *err);
int TimedOffAr_last(TimedOffAr *arr);
int TimedOffAr_len(TimedOffAr *arr);
TimedOffAr *TimedOffAr_new();
void TimedOffAr_pop(TimedOffAr *arr, Error *err);
TimedOff *TimedOffAr_pop(TimedOffAr *arr, Error *err);
void TimedOffAr_push(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err);
void TimedOffAr_reserve(TimedOffAr *arr, int newCap);
#define TimedOffAr_rforeach(var, arr)               for (TimedOffArFIt var = {arr, false, (arr)->len, NULL};        TimedOffArFIt_next(&var); )
#define TimedOffAr_rforeachOffset(var, arr, offset) for (TimedOffArFIt var = {arr, false, (arr)->len-offset, NULL}; TimedOffArFIt_next(&var); )
void TimedOffAr_set(TimedOffAr *arr, int index, TimedOff *elem, Error *err);
JSON_Value *TimedOffAr_toJson(TimedOffAr *self, Error *err);
void TimedOffAr_truncate(TimedOffAr *arr, int newLen);
bool TimedOffArFIt_next(TimedOffArFIt *iterator);
bool TimedOffArRIt_next(TimedOffArRIt *iterator);
void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_binRemoveTime(TimedOffAr *arr, TimedOff *elem);
TimedOff *TimedOffAr_binSearchTime(TimedOffAr *arr, TimedOff *elem);
int TimedOff_cmpTimeIndirectResolve(TimedOff **left, TimedOff **right);
TimedOff *TimedOffAr_pqPeekTime(TimedOffAr *arr);
void TimedOffAr_pqPopDecRefTime(TimedOffAr *arr, TimedOff *elem);
TimedOff *TimedOffAr_pqPopTime(TimedOffAr *arr);
void TimedOffAr_pqPushTime(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_pqSortTime(TimedOffAr *arr);
void TimedOffAr_sortTime(TimedOffAr *arr);
#define TimedPq_at(arr, index) ((arr)->data[index*sizeof(void*)])
TimedPq *TimedPq_clone(TimedPq *arr);
void TimedPq_decRef(TimedPq *arr);
void TimedPq_fit(TimedPq *arr);
#define TimedPq_foreach(var, arr)               for (TimedPqFIt var = {arr, false, 0, NULL};        TimedPqFIt_next(&var); )
#define TimedPq_foreachOffset(var, arr, offset) for (TimedPqFIt var = {arr, false, offset-1, NULL}; TimedPqFIt_next(&var); )
TimedPq *TimedPq_fromJson(JSON_Value *jval, Error *err);
Timed *TimedPq_get(TimedPq *arr, int index, Error *err);
void TimedPq_incRef(TimedPq *arr);
void TimedPq_insert(TimedPq *arr, int index, Timed *elem, Error *err);
int TimedPq_last(TimedPq *arr);
int TimedPq_len(TimedPq *arr);
TimedPq *TimedPq_new();
void TimedPq_pop(TimedPq *arr, Error *err);
Timed *TimedPq_pop(TimedPq *arr, Error *err);
void TimedPq_push(TimedPq *arr, Timed *elem);
void TimedPq_remove(TimedPq *arr, int index, Error *err);
void TimedPq_reserve(TimedPq *arr, int newCap);
#define TimedPq_rforeach(var, arr)               for (TimedPqFIt var = {arr, false, (arr)->len, NULL};        TimedPqFIt_next(&var); )
#define TimedPq_rforeachOffset(var, arr, offset) for (TimedPqFIt var = {arr, false, (arr)->len-offset, NULL}; TimedPqFIt_next(&var); )
void TimedPq_set(TimedPq *arr, int index, Timed *elem, Error *err);
JSON_Value *TimedPq_toJson(TimedPq *self, Error *err);
void TimedPq_truncate(TimedPq *arr, int newLen);
bool TimedPqFIt_next(TimedPqFIt *iterator);
bool TimedPqRIt_next(TimedPqRIt *iterator);
void TimedPq_binInsert(TimedPq *arr, Timed *elem);
void TimedPq_binRemove(TimedPq *arr, Timed *elem);
Timed *TimedPq_binSearch(TimedPq *arr, Timed *elem);
int Timed_cmpIndirectResolve(Timed **left, Timed **right);
Timed *TimedPq_pqPeek(TimedPq *arr);
void TimedPq_pqPopDecRef(TimedPq *arr, Timed *elem);
Timed *TimedPq_pqPop(TimedPq *arr);
void TimedPq_pqPush(TimedPq *arr, Timed *elem);
void TimedPq_pqSort(TimedPq *arr);
void TimedPq_sort(TimedPq *arr);
Track *Track_new();
void Track_incRef(Track *self);
void Track_decRef(Track *self);
Track *Track_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *Track_toJson(Track *self, Error *err);
Track *Track_clone(Track *self);
static inline Symbol * Track_name(Track *self){return self->name;}
static inline void Track_setName(Track *self, Symbol * value){self->name = value;}
#define TrackAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
TrackAr *TrackAr_clone(TrackAr *arr);
void TrackAr_decRef(TrackAr *arr);
void TrackAr_fit(TrackAr *arr);
#define TrackAr_foreach(var, arr)               for (TrackArFIt var = {arr, false, 0, NULL};        TrackArFIt_next(&var); )
#define TrackAr_foreachOffset(var, arr, offset) for (TrackArFIt var = {arr, false, offset-1, NULL}; TrackArFIt_next(&var); )
TrackAr *TrackAr_fromJson(JSON_Value *jval, Error *err);
Track *TrackAr_get(TrackAr *arr, int index, Error *err);
void TrackAr_incRef(TrackAr *arr);
void TrackAr_insert(TrackAr *arr, int index, Track *elem, Error *err);
int TrackAr_last(TrackAr *arr);
int TrackAr_len(TrackAr *arr);
TrackAr *TrackAr_new();
void TrackAr_pop(TrackAr *arr, Error *err);
Track *TrackAr_pop(TrackAr *arr, Error *err);
void TrackAr_push(TrackAr *arr, Track *elem);
void TrackAr_remove(TrackAr *arr, int index, Error *err);
void TrackAr_reserve(TrackAr *arr, int newCap);
#define TrackAr_rforeach(var, arr)               for (TrackArFIt var = {arr, false, (arr)->len, NULL};        TrackArFIt_next(&var); )
#define TrackAr_rforeachOffset(var, arr, offset) for (TrackArFIt var = {arr, false, (arr)->len-offset, NULL}; TrackArFIt_next(&var); )
void TrackAr_set(TrackAr *arr, int index, Track *elem, Error *err);
JSON_Value *TrackAr_toJson(TrackAr *self, Error *err);
void TrackAr_truncate(TrackAr *arr, int newLen);
bool TrackArFIt_next(TrackArFIt *iterator);
bool TrackArRIt_next(TrackArRIt *iterator);
VstOutlet *VstOutlet_new();
void VstOutlet_incRef(VstOutlet *self);
void VstOutlet_decRef(VstOutlet *self);
VstOutlet *VstOutlet_fromJson(JSON_Value *jvalue, Error *err);
JSON_Value *VstOutlet_toJson(VstOutlet *self, Error *err);
VstOutlet *VstOutlet_clone(VstOutlet *self);
static inline AtomAr *VstOutlet_atoms(VstOutlet *self){return self->atoms;}
void VstOutlet_setAtoms(VstOutlet *self, AtomAr *value);
static inline Port *VstOutlet_port(VstOutlet *self){return self->port;}
void VstOutlet_setPort(VstOutlet *self, Port *value);
static inline VstOutlet *VstOutlet_castFromOutlet(Outlet *self) {
   if (self->itype == VstOutlet_itype) {
       return (VstOutlet*)self;
   }
   return NULL;
}
static inline Outlet *VstOutlet_castToOutlet(VstOutlet *self) {
   return (Outlet*)self;
}
const char *Interface_toString(int itype);
void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args);
void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args);
void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err);
void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args);
Marshal *Marshal_create(int itype);
void Marshal_free(Marshal *self);
Dispatch *IncrementFrameDispatch_create(int itype);
void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *DecrementFrameDispatch_create(int itype);
void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *SelectNextPushedPadDispatch_create(int itype);
void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *MidiFileDropDispatch_create(int itype);
void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err);
Dispatch *ManageChokeGroupsDispatch_create(int itype);
void ManageChokeGroupsDispatch_initDispatchAr(int itype, DispatchAr *disPtAr, Error *ignored);
void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err);
int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp);
void Dispatch_freeDefault(Dispatch *d);
void Dispatch_initDispatchArDefault(int itype, DispatchAr *disPtAr, Error *err);
void DispatchAr_populate(DispatchAr *self, Error *err);
void String_split(String *src, const char *delim, StringPtAr *stringPtAr);
int Symbol_cmpUnderlying(Symbol *left, Symbol *right);
Symbol *Symbol_gen(const char *word);
void Symbol_freeAll();
Port *Port_new();
void Port_init(Port *p);
void Port_free(Port *p);
void Port_clear(Port *p);
int port_parseEvSymbol(Symbol *id);
void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err);
void Port_sendInteger(Port *self, int outlet, long value, Error *err);
int Int_cmp(Int *left, Int *right);
static inline Symbol *PortRef_track(PortRef *self);
int PortRef_cmp(PortRef *left, PortRef *right);
void DropDown_build(DropDown *self, const char **table, Outlet *outlet);
DropDown *DropDown_newCGLocalGlobal(Outlet *outlet);
DropDown *DropDown_newCGInstrument(Outlet *outlet);
DropDown *DropDown_newCGIndex(DropDown *dd, Outlet *outlet);
DropDown *DropDown_updateSelected(DropDown *dd, Error *err);
DropDown *DropDown_setSelected(DropDown *dd, int selected, Error *err);
DropDown *DropDown_initializeMenu(DropDown *dd, Error *err);
long PortFind_iterator(PortFind *pf, MaxObject *targetBox);
int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err);
long PortFind_iterator(PortFind *pf, MaxObject *targetBox);
int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err);
Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol);
Port *PortFind_findById(PortFind *pf, Symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);
Outlet *PortFind_createOutlet(PortFind *self, OutletSpecifier *spec);
void Pad_computeChokeGroup(Pad *pad);
PadList *PadList_newN(int npads);
void PadList_play(PadList *self, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *self, int padIndex, bool pending, Error *err);
Pad *PadList_pad(PadList *pl, int index, Error *err);
void PadList_assignTrack(PadList *pl, TrackList *tl);
int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right);
int TimedOff_cmpTime(TimedOff *left, TimedOff *right);
Hub *Hub_newBuild(PortFind *pf, Error *err);
void Hub_build(Hub *hub, PortFind *pf, Error *err);
void Hub_updateGuiCurrentCoordinates(Hub *hub);
void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err);
void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv);
void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet);
void NoteOutlet_sendNote(NoteOutlet *self, uint8_t pitch, uint8_t velocity);
NoteOutlet *NoteOutlet_newBuild(Port *port);
void CcOutlet_dbRewindSent();
void CcOutlet_sendFloat(CcOutlet *self, double value);
CcOutlet *CcOutlet_newBuild(Port *port, int cc);
void BendOutlet_dbRewindSent();
void BendOutlet_sendFloat(BendOutlet *self, double value);
BendOutlet *BendOutlet_newBuild(Port *port);
void VstOutlet_sendFloat(VstOutlet *self, double value);
int Timed_cmp(Timed *left, Timed *right);
void TimedPq_enqueue(TimedPq *self, Ticks time, Sequence *s);
Sequence *TimedPq_dequeue(TimedPq *self, Ticks current);
void TimedPq_invalidateSequence(TimedPq *self, SequenceAr *removes);
NoteEvent *NoteEvent_newValue(Ticks stime, int pitch, int velocity, Ticks duration);
int NoteEvent_cmp(NoteEvent *left, NoteEvent *right);
NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind);
NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv, Error *err);
void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err);
void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err);
void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err);
void NoteSequence_padNoteOff(NoteSequence *self, Ticks current, Error *err);
void NoteSequence_makeConsistent(NoteSequence *self, Error *err);
Sequence *NoteSequence_compactNew(NoteSequence *self, Ticks recordStart);
void NoteSequence_compactConcat(NoteSequence *self, Sequence *otherSeq, Error *err);
void NoteSequence_compactSortEvents(NoteSequence *self);
Ticks NoteSequence_computeEndgroupTime(NoteSequence *self);
Ticks NoteSequence_compactComputeSequenceLength(NoteSequence *self);
void NoteSequence_compactFinish(NoteSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err);
int FloatEvent_cmp(FloatEvent *left, FloatEvent *right);
FloatSequence *FloatSequence_newCc(Symbol *track, int cc, PortFind *portFind);
FloatSequence *FloatSequence_newBend(Symbol *track, PortFind *portFind);
FloatSequence *FloatSequence_newFromEvents(Symbol *track, int ccOrNegForBend, PortFind *portFind, int argc, FloatEvent *argv);
void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err);
void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err);
void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err);
void FloatSequence_padNoteOff(FloatSequence *self, Ticks current, Error *err);
void FloatSequence_makeConsistent(FloatSequence *self);
Sequence *FloatSequence_compactNew(FloatSequence *self, Ticks recordStart);
void FloatSequence_compactConcat(FloatSequence *self, Sequence *otherSeq, Error *err);
void FloatSequence_compactSortEvents(FloatSequence *self);
Ticks FloatSequence_compactComputeSequenceLength(FloatSequence *self);
void FloatSequence_compactFinish(FloatSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err);
void Sequence_freePpErrless(Sequence **s);
int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq);
int Sequence_cmpPointer(Sequence *leftSeq, Sequence *rightSeq);
int Sequence_cmpPp(Sequence **left, Sequence **right);
int Sequence_cmpPointerPp(Sequence **left, Sequence **right);
void Sequence_incVersion(Sequence *seq);
RecordBuffer *RecordBuffer_newStart(Ticks recordStart);
void RecordBuffer_push(RecordBuffer *self, Sequence *sequence);
void RecordBuffer_compact(RecordBuffer *self, SequenceAr *output, Error *err);
void Midi_fromfile(const char *midiFilePath, SequenceAr *output, Symbol *defaultTrack, PortFind *portFind, Error *err);
void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn);
void Frontend_drive(Hub *hub);
void Frontend_stop(Hub *hub);
Arguments *Arguments_new()
{
   Arguments *self = Mem_malloc(sizeof(Arguments));
   self->itype = Arguments_itype;
   self->refCount = 1;
   self->s1 = 0;
   self->i1 = 0;
   self->i2 = 0;
   self->ivalue = 0;
   self->inlet = 0;
   return self;
}
void Arguments_incRef(Arguments *self)
{
    self->refCount++;
}
void Arguments_decRef(Arguments *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *Arguments_toJson(Arguments *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Arguments") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Arguments");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Arguments *Arguments_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Arguments_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Arguments");
           return NULL;
       } else if (strcmp(s, "Arguments") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Arguments'", s);
           return NULL;
       }
       
   }

   Arguments *self = Arguments_new();
   return self;

   FAIL:
   Arguments_free(self);
   return NULL;
}
Arguments *Arguments_clone(Arguments *self) {
   Arguments *other = Arguments_new();
   other->s1 = self->s1;
   other->i1 = self->i1;
   other->i2 = self->i2;
   other->ivalue = self->ivalue;
   other->inlet = self->inlet;
   return self;
}
#define AtomAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
AtomAr *AtomAr_clone(AtomAr *arr);
void AtomAr_decRef(AtomAr *arr);
void AtomAr_fit(AtomAr *arr);
#define AtomAr_foreach(var, arr)               for (AtomArFIt var = {arr, false, 0, NULL};        AtomArFIt_next(&var); )
#define AtomAr_foreachOffset(var, arr, offset) for (AtomArFIt var = {arr, false, offset-1, NULL}; AtomArFIt_next(&var); )
AtomAr *AtomAr_fromJson(JSON_Value *jval, Error *err);
AtomRf *AtomAr_get(AtomAr *arr, int index, Error *err);
void AtomAr_incRef(AtomAr *arr);
void AtomAr_insert(AtomAr *arr, int index, AtomRf *elem, Error *err);
int AtomAr_last(AtomAr *arr);
int AtomAr_len(AtomAr *arr);
AtomAr *AtomAr_new();
void AtomAr_pop(AtomAr *arr, Error *err);
AtomRf *AtomAr_pop(AtomAr *arr, Error *err);
void AtomAr_push(AtomAr *arr, AtomRf *elem);
void AtomAr_remove(AtomAr *arr, int index, Error *err);
void AtomAr_reserve(AtomAr *arr, int newCap);
#define AtomAr_rforeach(var, arr)               for (AtomArFIt var = {arr, false, (arr)->len, NULL};        AtomArFIt_next(&var); )
#define AtomAr_rforeachOffset(var, arr, offset) for (AtomArFIt var = {arr, false, (arr)->len-offset, NULL}; AtomArFIt_next(&var); )
void AtomAr_set(AtomAr *arr, int index, AtomRf *elem, Error *err);
JSON_Value *AtomAr_toJson(AtomAr *self, Error *err);
void AtomAr_truncate(AtomAr *arr, int newLen);
bool AtomArFIt_next(AtomArFIt *iterator);
bool AtomArRIt_next(AtomArRIt *iterator);
#define AtomArAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
AtomArAr *AtomArAr_clone(AtomArAr *arr);
void AtomArAr_decRef(AtomArAr *arr);
void AtomArAr_fit(AtomArAr *arr);
#define AtomArAr_foreach(var, arr)               for (AtomArArFIt var = {arr, false, 0, NULL};        AtomArArFIt_next(&var); )
#define AtomArAr_foreachOffset(var, arr, offset) for (AtomArArFIt var = {arr, false, offset-1, NULL}; AtomArArFIt_next(&var); )
AtomArAr *AtomArAr_fromJson(JSON_Value *jval, Error *err);
AtomAr *AtomArAr_get(AtomArAr *arr, int index, Error *err);
void AtomArAr_incRef(AtomArAr *arr);
void AtomArAr_insert(AtomArAr *arr, int index, AtomAr *elem, Error *err);
int AtomArAr_last(AtomArAr *arr);
int AtomArAr_len(AtomArAr *arr);
AtomArAr *AtomArAr_new();
void AtomArAr_pop(AtomArAr *arr, Error *err);
AtomAr *AtomArAr_pop(AtomArAr *arr, Error *err);
void AtomArAr_push(AtomArAr *arr, AtomAr *elem);
void AtomArAr_remove(AtomArAr *arr, int index, Error *err);
void AtomArAr_reserve(AtomArAr *arr, int newCap);
#define AtomArAr_rforeach(var, arr)               for (AtomArArFIt var = {arr, false, (arr)->len, NULL};        AtomArArFIt_next(&var); )
#define AtomArAr_rforeachOffset(var, arr, offset) for (AtomArArFIt var = {arr, false, (arr)->len-offset, NULL}; AtomArArFIt_next(&var); )
void AtomArAr_set(AtomArAr *arr, int index, AtomAr *elem, Error *err);
JSON_Value *AtomArAr_toJson(AtomArAr *self, Error *err);
void AtomArAr_truncate(AtomArAr *arr, int newLen);
bool AtomArArFIt_next(AtomArArFIt *iterator);
bool AtomArArRIt_next(AtomArArRIt *iterator);
AtomRf *AtomRf_new()
{
   AtomRf *self = Mem_malloc(sizeof(AtomRf));
   self->itype = AtomRf_itype;
   self->refCount = 1;
   self->a = 0;
   return self;
}
void AtomRf_incRef(AtomRf *self)
{
    self->refCount++;
}
void AtomRf_decRef(AtomRf *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *AtomRf_toJson(AtomRf *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "AtomRf") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type AtomRf");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
AtomRf *AtomRf_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "AtomRf_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type AtomRf");
           return NULL;
       } else if (strcmp(s, "AtomRf") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'AtomRf'", s);
           return NULL;
       }
       
   }

   AtomRf *self = AtomRf_new();
   return self;

   FAIL:
   AtomRf_free(self);
   return NULL;
}
AtomRf *AtomRf_clone(AtomRf *self) {
   AtomRf *other = AtomRf_new();
   other->a = self->a;
   return self;
}
BendOutlet *BendOutlet_new()
{
   BendOutlet *self = Mem_malloc(sizeof(BendOutlet));
   self->itype = BendOutlet_itype;
   self->refCount = 1;
   self->atoms = AtomAr_new();
   self->port = Port_new();
   return self;
}
void BendOutlet_incRef(BendOutlet *self)
{
    self->refCount++;
}
void BendOutlet_decRef(BendOutlet *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       AtomAr_decRef(self->atoms);        
       Port_decRef(self->port);        
       Mem_free(self);
   }
   return;
}
JSON_Value *BendOutlet_toJson(BendOutlet *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "BendOutlet") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type BendOutlet");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = AtomAr_toJson(self->atoms, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "atoms", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of atoms on type BendOutlet");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->port, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "port", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of port on type BendOutlet");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
BendOutlet *BendOutlet_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "BendOutlet_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type BendOutlet");
           return NULL;
       } else if (strcmp(s, "BendOutlet") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'BendOutlet'", s);
           return NULL;
       }
       
   }

   BendOutlet *self = BendOutlet_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "atoms");
       if (target == NULL) {
           Error_format0(err, "'BendOutlet' json object does not contain a json value for 'atoms'");
           goto FAIL;
       }
       self->atoms = AtomAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "port");
       if (target == NULL) {
           Error_format0(err, "'BendOutlet' json object does not contain a json value for 'port'");
           goto FAIL;
       }
       self->port = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   BendOutlet_free(self);
   return NULL;
}
BendOutlet *BendOutlet_clone(BendOutlet *self) {
   BendOutlet *other = BendOutlet_new();
   other->atoms = AtomAr_clone(self->atoms);
   other->port = Port_clone(self->port);
   return self;
}
void BendOutlet_setAtoms(BendOutlet *self, AtomAr *value) {
   AtomAr *old = self->atoms;
   self->atoms = value;
   AtomAr_incRef(self->atoms);
   AtomAr_decRef(old);
}
void BendOutlet_setPort(BendOutlet *self, Port *value) {
   Port *old = self->port;
   self->port = value;
   Port_incRef(self->port);
   Port_decRef(old);
}
CcOutlet *CcOutlet_new()
{
   CcOutlet *self = Mem_malloc(sizeof(CcOutlet));
   self->itype = CcOutlet_itype;
   self->refCount = 1;
   self->cc = 0;
   self->atoms = AtomAr_new();
   self->port = Port_new();
   return self;
}
void CcOutlet_incRef(CcOutlet *self)
{
    self->refCount++;
}
void CcOutlet_decRef(CcOutlet *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       AtomAr_decRef(self->atoms);        
       Port_decRef(self->port);        
       Mem_free(self);
   }
   return;
}
JSON_Value *CcOutlet_toJson(CcOutlet *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "CcOutlet") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type CcOutlet");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = AtomAr_toJson(self->atoms, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "atoms", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of atoms on type CcOutlet");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->port, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "port", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of port on type CcOutlet");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
CcOutlet *CcOutlet_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "CcOutlet_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type CcOutlet");
           return NULL;
       } else if (strcmp(s, "CcOutlet") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'CcOutlet'", s);
           return NULL;
       }
       
   }

   CcOutlet *self = CcOutlet_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "atoms");
       if (target == NULL) {
           Error_format0(err, "'CcOutlet' json object does not contain a json value for 'atoms'");
           goto FAIL;
       }
       self->atoms = AtomAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "port");
       if (target == NULL) {
           Error_format0(err, "'CcOutlet' json object does not contain a json value for 'port'");
           goto FAIL;
       }
       self->port = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   CcOutlet_free(self);
   return NULL;
}
CcOutlet *CcOutlet_clone(CcOutlet *self) {
   CcOutlet *other = CcOutlet_new();
   other->cc = self->cc;
   other->atoms = AtomAr_clone(self->atoms);
   other->port = Port_clone(self->port);
   return self;
}
void CcOutlet_setAtoms(CcOutlet *self, AtomAr *value) {
   AtomAr *old = self->atoms;
   self->atoms = value;
   AtomAr_incRef(self->atoms);
   AtomAr_decRef(old);
}
void CcOutlet_setPort(CcOutlet *self, Port *value) {
   Port *old = self->port;
   self->port = value;
   Port_incRef(self->port);
   Port_decRef(old);
}
DecrementFrameDispatch *DecrementFrameDispatch_new()
{
   DecrementFrameDispatch *self = Mem_malloc(sizeof(DecrementFrameDispatch));
   self->itype = DecrementFrameDispatch_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   self->marshal = 0;
   return self;
}
void DecrementFrameDispatch_incRef(DecrementFrameDispatch *self)
{
    self->refCount++;
}
void DecrementFrameDispatch_decRef(DecrementFrameDispatch *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *DecrementFrameDispatch_toJson(DecrementFrameDispatch *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "DecrementFrameDispatch") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type DecrementFrameDispatch");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
DecrementFrameDispatch *DecrementFrameDispatch_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "DecrementFrameDispatch_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type DecrementFrameDispatch");
           return NULL;
       } else if (strcmp(s, "DecrementFrameDispatch") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'DecrementFrameDispatch'", s);
           return NULL;
       }
       
   }

   DecrementFrameDispatch *self = DecrementFrameDispatch_new();
   return self;

   FAIL:
   DecrementFrameDispatch_free(self);
   return NULL;
}
DecrementFrameDispatch *DecrementFrameDispatch_clone(DecrementFrameDispatch *self) {
   DecrementFrameDispatch *other = DecrementFrameDispatch_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   other->marshal = self->marshal;
   return self;
}
int Dispatch_nthIType(int n, int *itype);
#define Dispatch_foreachIType(itype) for (int __##itype = 0, itype = 0; Dispatch_nthIType(__##itype, &itype); __##itype++)
void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error * a3, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Dispatch_exec");
       return 0;
   }
   switch(self->itype) {
       case DecrementFrameDispatch_itype:
           DecrementFrameDispatch_exec((DecrementFrameDispatch*)self, a1, a2, a3, err);
           return;
       case IncrementFrameDispatch_itype:
           IncrementFrameDispatch_exec((IncrementFrameDispatch*)self, a1, a2, a3, err);
           return;
       case ManageChokeGroupsDispatch_itype:
           ManageChokeGroupsDispatch_exec((ManageChokeGroupsDispatch*)self, a1, a2, a3, err);
           return;
       case MidiFileDropDispatch_itype:
           MidiFileDropDispatch_exec((MidiFileDropDispatch*)self, a1, a2, a3, err);
           return;
       case SelectNextPushedPadDispatch_itype:
           SelectNextPushedPadDispatch_exec((SelectNextPushedPadDispatch*)self, a1, a2, a3, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_exec: found type %s", Interface_toString(self->itype));
    }
    return;
}

Dispatch *Dispatch_create(int itype, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Dispatch_create");
       return NULL;
   }
   switch(itype) {
       case DecrementFrameDispatch_itype:
           return DecrementFrameDispatch_create(itype);
       case IncrementFrameDispatch_itype:
           return IncrementFrameDispatch_create(itype);
       case ManageChokeGroupsDispatch_itype:
           return ManageChokeGroupsDispatch_create(itype);
       case MidiFileDropDispatch_itype:
           return MidiFileDropDispatch_create(itype);
       case SelectNextPushedPadDispatch_itype:
           return SelectNextPushedPadDispatch_create(itype);
       default:
           Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_create: found type %s", Interface_toString(itype));
    }
    return NULL;
}

void Dispatch_free(Dispatch *self, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Dispatch_free");
       return 0;
   }
   switch(self->itype) {
       case DecrementFrameDispatch_itype:
           Dispatch_freeDefault(self);
           return;
       case IncrementFrameDispatch_itype:
           Dispatch_freeDefault(self);
           return;
       case ManageChokeGroupsDispatch_itype:
           Dispatch_freeDefault(self);
           return;
       case MidiFileDropDispatch_itype:
           Dispatch_freeDefault(self);
           return;
       case SelectNextPushedPadDispatch_itype:
           Dispatch_freeDefault(self);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_free: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Dispatch_initDispatchAr(int itype, DispatchAr *a1, Error * a2, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Dispatch_initDispatchAr");
       return 0;
   }
   switch(itype) {
       case DecrementFrameDispatch_itype:
           Dispatch_initDispatchArDefault(itype, a1, a2, err);
           return;
       case IncrementFrameDispatch_itype:
           Dispatch_initDispatchArDefault(itype, a1, a2, err);
           return;
       case ManageChokeGroupsDispatch_itype:
           ManageChokeGroupsDispatch_initDispatchAr(itype, a1, a2, err);
           return;
       case MidiFileDropDispatch_itype:
           Dispatch_initDispatchArDefault(itype, a1, a2, err);
           return;
       case SelectNextPushedPadDispatch_itype:
           Dispatch_initDispatchArDefault(itype, a1, a2, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_initDispatchAr: found type %s", Interface_toString(itype));
    }
    return;
}

#define DispatchAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
DispatchAr *DispatchAr_clone(DispatchAr *arr);
void DispatchAr_decRef(DispatchAr *arr);
void DispatchAr_fit(DispatchAr *arr);
#define DispatchAr_foreach(var, arr)               for (DispatchArFIt var = {arr, false, 0, NULL};        DispatchArFIt_next(&var); )
#define DispatchAr_foreachOffset(var, arr, offset) for (DispatchArFIt var = {arr, false, offset-1, NULL}; DispatchArFIt_next(&var); )
DispatchAr *DispatchAr_fromJson(JSON_Value *jval, Error *err);
Dispatch *DispatchAr_get(DispatchAr *arr, int index, Error *err);
void DispatchAr_incRef(DispatchAr *arr);
void DispatchAr_insert(DispatchAr *arr, int index, Dispatch *elem, Error *err);
int DispatchAr_last(DispatchAr *arr);
int DispatchAr_len(DispatchAr *arr);
DispatchAr *DispatchAr_new();
void DispatchAr_pop(DispatchAr *arr, Error *err);
Dispatch *DispatchAr_pop(DispatchAr *arr, Error *err);
void DispatchAr_push(DispatchAr *arr, Dispatch *elem);
void DispatchAr_remove(DispatchAr *arr, int index, Error *err);
void DispatchAr_reserve(DispatchAr *arr, int newCap);
#define DispatchAr_rforeach(var, arr)               for (DispatchArFIt var = {arr, false, (arr)->len, NULL};        DispatchArFIt_next(&var); )
#define DispatchAr_rforeachOffset(var, arr, offset) for (DispatchArFIt var = {arr, false, (arr)->len-offset, NULL}; DispatchArFIt_next(&var); )
void DispatchAr_set(DispatchAr *arr, int index, Dispatch *elem, Error *err);
JSON_Value *DispatchAr_toJson(DispatchAr *self, Error *err);
void DispatchAr_truncate(DispatchAr *arr, int newLen);
bool DispatchArFIt_next(DispatchArFIt *iterator);
bool DispatchArRIt_next(DispatchArRIt *iterator);
void DispatchAr_binInsert(DispatchAr *arr, Dispatch *elem);
void DispatchAr_binRemove(DispatchAr *arr, Dispatch *elem);
Dispatch *DispatchAr_binSearch(DispatchAr *arr, Dispatch *elem);
Dispatch *DispatchAr_pqPeek(DispatchAr *arr);
void DispatchAr_pqPopDecRef(DispatchAr *arr, Dispatch *elem);
Dispatch *DispatchAr_pqPop(DispatchAr *arr);
void DispatchAr_pqPush(DispatchAr *arr, Dispatch *elem);
void DispatchAr_pqSort(DispatchAr *arr);
void DispatchAr_sort(DispatchAr *arr);
DropDown *DropDown_new()
{
   DropDown *self = Mem_malloc(sizeof(DropDown));
   self->itype = DropDown_itype;
   self->refCount = 1;
   self->table = SymbolAr_new();
   self->selected = 0;
   self->outlet = Outlet_new();
   return self;
}
void DropDown_incRef(DropDown *self)
{
    self->refCount++;
}
void DropDown_decRef(DropDown *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       SymbolAr_decRef(self->table);        
       Outlet_decRef(self->outlet);        
       Mem_free(self);
   }
   return;
}
JSON_Value *DropDown_toJson(DropDown *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "DropDown") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type DropDown");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = SymbolAr_toJson(self->table, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "table", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of table on type DropDown");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Outlet_toJson(self->outlet, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "outlet", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of outlet on type DropDown");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
DropDown *DropDown_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "DropDown_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type DropDown");
           return NULL;
       } else if (strcmp(s, "DropDown") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'DropDown'", s);
           return NULL;
       }
       
   }

   DropDown *self = DropDown_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "table");
       if (target == NULL) {
           Error_format0(err, "'DropDown' json object does not contain a json value for 'table'");
           goto FAIL;
       }
       self->table = SymbolAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "outlet");
       if (target == NULL) {
           Error_format0(err, "'DropDown' json object does not contain a json value for 'outlet'");
           goto FAIL;
       }
       self->outlet = Outlet_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   DropDown_free(self);
   return NULL;
}
DropDown *DropDown_clone(DropDown *self) {
   DropDown *other = DropDown_new();
   other->table = SymbolAr_clone(self->table);
   other->selected = self->selected;
   other->outlet = Outlet_clone(self->outlet);
   return self;
}
void DropDown_setTable(DropDown *self, SymbolAr *value) {
   SymbolAr *old = self->table;
   self->table = value;
   SymbolAr_incRef(self->table);
   SymbolAr_decRef(old);
}
void DropDown_setOutlet(DropDown *self, Outlet *value) {
   Outlet *old = self->outlet;
   self->outlet = value;
   Outlet_incRef(self->outlet);
   Outlet_decRef(old);
}
FloatEvent *FloatEvent_new()
{
   FloatEvent *self = Mem_malloc(sizeof(FloatEvent));
   self->itype = FloatEvent_itype;
   self->refCount = 1;
   self->stime = 0;
   self->value = 0;
   return self;
}
void FloatEvent_incRef(FloatEvent *self)
{
    self->refCount++;
}
void FloatEvent_decRef(FloatEvent *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *FloatEvent_toJson(FloatEvent *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "FloatEvent") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type FloatEvent");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
FloatEvent *FloatEvent_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "FloatEvent_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type FloatEvent");
           return NULL;
       } else if (strcmp(s, "FloatEvent") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'FloatEvent'", s);
           return NULL;
       }
       
   }

   FloatEvent *self = FloatEvent_new();
   return self;

   FAIL:
   FloatEvent_free(self);
   return NULL;
}
FloatEvent *FloatEvent_clone(FloatEvent *self) {
   FloatEvent *other = FloatEvent_new();
   other->stime = self->stime;
   other->value = self->value;
   return self;
}
#define FloatEventAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
FloatEventAr *FloatEventAr_clone(FloatEventAr *arr);
void FloatEventAr_decRef(FloatEventAr *arr);
void FloatEventAr_fit(FloatEventAr *arr);
#define FloatEventAr_foreach(var, arr)               for (FloatEventArFIt var = {arr, false, 0, NULL};        FloatEventArFIt_next(&var); )
#define FloatEventAr_foreachOffset(var, arr, offset) for (FloatEventArFIt var = {arr, false, offset-1, NULL}; FloatEventArFIt_next(&var); )
FloatEventAr *FloatEventAr_fromJson(JSON_Value *jval, Error *err);
FloatEvent *FloatEventAr_get(FloatEventAr *arr, int index, Error *err);
void FloatEventAr_incRef(FloatEventAr *arr);
void FloatEventAr_insert(FloatEventAr *arr, int index, FloatEvent *elem, Error *err);
int FloatEventAr_last(FloatEventAr *arr);
int FloatEventAr_len(FloatEventAr *arr);
FloatEventAr *FloatEventAr_new();
void FloatEventAr_pop(FloatEventAr *arr, Error *err);
FloatEvent *FloatEventAr_pop(FloatEventAr *arr, Error *err);
void FloatEventAr_push(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_remove(FloatEventAr *arr, int index, Error *err);
void FloatEventAr_reserve(FloatEventAr *arr, int newCap);
#define FloatEventAr_rforeach(var, arr)               for (FloatEventArFIt var = {arr, false, (arr)->len, NULL};        FloatEventArFIt_next(&var); )
#define FloatEventAr_rforeachOffset(var, arr, offset) for (FloatEventArFIt var = {arr, false, (arr)->len-offset, NULL}; FloatEventArFIt_next(&var); )
void FloatEventAr_set(FloatEventAr *arr, int index, FloatEvent *elem, Error *err);
JSON_Value *FloatEventAr_toJson(FloatEventAr *self, Error *err);
void FloatEventAr_truncate(FloatEventAr *arr, int newLen);
bool FloatEventArFIt_next(FloatEventArFIt *iterator);
bool FloatEventArRIt_next(FloatEventArRIt *iterator);
void FloatEventAr_binInsert(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_binRemove(FloatEventAr *arr, FloatEvent *elem);
FloatEvent *FloatEventAr_binSearch(FloatEventAr *arr, FloatEvent *elem);
FloatEvent *FloatEventAr_pqPeek(FloatEventAr *arr);
void FloatEventAr_pqPopDecRef(FloatEventAr *arr, FloatEvent *elem);
FloatEvent *FloatEventAr_pqPop(FloatEventAr *arr);
void FloatEventAr_pqPush(FloatEventAr *arr, FloatEvent *elem);
void FloatEventAr_pqSort(FloatEventAr *arr);
void FloatEventAr_sort(FloatEventAr *arr);
FloatSequence *FloatSequence_new()
{
   FloatSequence *self = Mem_malloc(sizeof(FloatSequence));
   self->itype = FloatSequence_itype;
   self->refCount = 1;
   self->version = 0;
   self->startTime = 0;
   self->outletSpecifier = OutletSpecifier_new();
   self->sequenceLength = 0;
   self->cursor = 0;
   self->cycle = 0;
   self->inEndgroup = 0;
   self->outlet = Outlet_new();
   self->recordingSeq = 0;
   self->events = FloatEventAr_new();
   self->restoreValue = 0;
   return self;
}
void FloatSequence_incRef(FloatSequence *self)
{
    self->refCount++;
}
void FloatSequence_decRef(FloatSequence *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       OutletSpecifier_decRef(self->outletSpecifier);        
       Outlet_decRef(self->outlet);        
       FloatEventAr_decRef(self->events);        
       Mem_free(self);
   }
   return;
}
JSON_Value *FloatSequence_toJson(FloatSequence *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "FloatSequence") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type FloatSequence");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = OutletSpecifier_toJson(self->outletSpecifier, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "outletSpecifier", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of outletSpecifier on type FloatSequence");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Outlet_toJson(self->outlet, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "outlet", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of outlet on type FloatSequence");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = FloatEventAr_toJson(self->events, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "events", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of events on type FloatSequence");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
FloatSequence *FloatSequence_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "FloatSequence_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type FloatSequence");
           return NULL;
       } else if (strcmp(s, "FloatSequence") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'FloatSequence'", s);
           return NULL;
       }
       
   }

   FloatSequence *self = FloatSequence_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "outletSpecifier");
       if (target == NULL) {
           Error_format0(err, "'FloatSequence' json object does not contain a json value for 'outletSpecifier'");
           goto FAIL;
       }
       self->outletSpecifier = OutletSpecifier_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "outlet");
       if (target == NULL) {
           Error_format0(err, "'FloatSequence' json object does not contain a json value for 'outlet'");
           goto FAIL;
       }
       self->outlet = Outlet_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "events");
       if (target == NULL) {
           Error_format0(err, "'FloatSequence' json object does not contain a json value for 'events'");
           goto FAIL;
       }
       self->events = FloatEventAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   FloatSequence_free(self);
   return NULL;
}
FloatSequence *FloatSequence_clone(FloatSequence *self) {
   FloatSequence *other = FloatSequence_new();
   other->version = self->version;
   other->startTime = self->startTime;
   other->outletSpecifier = OutletSpecifier_clone(self->outletSpecifier);
   other->sequenceLength = self->sequenceLength;
   other->cursor = self->cursor;
   other->cycle = self->cycle;
   other->inEndgroup = self->inEndgroup;
   other->outlet = Outlet_clone(self->outlet);
   other->recordingSeq = self->recordingSeq;
   other->events = FloatEventAr_clone(self->events);
   other->restoreValue = self->restoreValue;
   return self;
}
void FloatSequence_setOutletSpecifier(FloatSequence *self, OutletSpecifier *value) {
   OutletSpecifier *old = self->outletSpecifier;
   self->outletSpecifier = value;
   OutletSpecifier_incRef(self->outletSpecifier);
   OutletSpecifier_decRef(old);
}
void FloatSequence_setOutlet(FloatSequence *self, Outlet *value) {
   Outlet *old = self->outlet;
   self->outlet = value;
   Outlet_incRef(self->outlet);
   Outlet_decRef(old);
}
void FloatSequence_setEvents(FloatSequence *self, FloatEventAr *value) {
   FloatEventAr *old = self->events;
   self->events = value;
   FloatEventAr_incRef(self->events);
   FloatEventAr_decRef(old);
}
Hub *Hub_new()
{
   Hub *self = Mem_malloc(sizeof(Hub));
   self->itype = Hub_itype;
   self->refCount = 1;
   self->padList = PadAr_new();
   self->trackList = TrackAr_new();
   self->currBankPort = Port_new();
   self->currFramePort = Port_new();
   self->selBankPort = Port_new();
   self->selFramePort = Port_new();
   self->selPadPort = Port_new();
   self->chokeGroupPort = Port_new();
   self->cgLocalGlobalMenu = DropDown_new();
   self->cgInstrumentMenu = DropDown_new();
   self->cgIndexMenu = DropDown_new();
   self->bank = 0;
   self->frame = 0;
   self->grabNextTappedPad = 0;
   self->selectedPad = 0;
   self->arguments = Arguments_new();
   self->dispatcher = DispatchAr_new();
   self->masterClock = 0;
   return self;
}
void Hub_incRef(Hub *self)
{
    self->refCount++;
}
void Hub_decRef(Hub *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       PadAr_decRef(self->padList);        
       TrackAr_decRef(self->trackList);        
       Port_decRef(self->currBankPort);        
       Port_decRef(self->currFramePort);        
       Port_decRef(self->selBankPort);        
       Port_decRef(self->selFramePort);        
       Port_decRef(self->selPadPort);        
       Port_decRef(self->chokeGroupPort);        
       DropDown_decRef(self->cgLocalGlobalMenu);        
       DropDown_decRef(self->cgInstrumentMenu);        
       DropDown_decRef(self->cgIndexMenu);        
       Arguments_decRef(self->arguments);        
       DispatchAr_decRef(self->dispatcher);        
       Mem_free(self);
   }
   return;
}
JSON_Value *Hub_toJson(Hub *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Hub") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Hub");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = PadAr_toJson(self->padList, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "padList", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of padList on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = TrackAr_toJson(self->trackList, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "trackList", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of trackList on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->currBankPort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "currBankPort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of currBankPort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->currFramePort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "currFramePort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of currFramePort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->selBankPort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "selBankPort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of selBankPort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->selFramePort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "selFramePort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of selFramePort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->selPadPort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "selPadPort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of selPadPort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->chokeGroupPort, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "chokeGroupPort", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of chokeGroupPort on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = DropDown_toJson(self->cgLocalGlobalMenu, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "cgLocalGlobalMenu", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of cgLocalGlobalMenu on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = DropDown_toJson(self->cgInstrumentMenu, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "cgInstrumentMenu", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of cgInstrumentMenu on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = DropDown_toJson(self->cgIndexMenu, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "cgIndexMenu", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of cgIndexMenu on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Arguments_toJson(self->arguments, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "arguments", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of arguments on type Hub");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = DispatchAr_toJson(self->dispatcher, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "dispatcher", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of dispatcher on type Hub");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Hub *Hub_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Hub_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Hub");
           return NULL;
       } else if (strcmp(s, "Hub") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Hub'", s);
           return NULL;
       }
       
   }

   Hub *self = Hub_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "padList");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'padList'");
           goto FAIL;
       }
       self->padList = PadAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "trackList");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'trackList'");
           goto FAIL;
       }
       self->trackList = TrackAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "currBankPort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'currBankPort'");
           goto FAIL;
       }
       self->currBankPort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "currFramePort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'currFramePort'");
           goto FAIL;
       }
       self->currFramePort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "selBankPort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'selBankPort'");
           goto FAIL;
       }
       self->selBankPort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "selFramePort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'selFramePort'");
           goto FAIL;
       }
       self->selFramePort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "selPadPort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'selPadPort'");
           goto FAIL;
       }
       self->selPadPort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "chokeGroupPort");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'chokeGroupPort'");
           goto FAIL;
       }
       self->chokeGroupPort = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "cgLocalGlobalMenu");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'cgLocalGlobalMenu'");
           goto FAIL;
       }
       self->cgLocalGlobalMenu = DropDown_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "cgInstrumentMenu");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'cgInstrumentMenu'");
           goto FAIL;
       }
       self->cgInstrumentMenu = DropDown_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "cgIndexMenu");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'cgIndexMenu'");
           goto FAIL;
       }
       self->cgIndexMenu = DropDown_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "arguments");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'arguments'");
           goto FAIL;
       }
       self->arguments = Arguments_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "dispatcher");
       if (target == NULL) {
           Error_format0(err, "'Hub' json object does not contain a json value for 'dispatcher'");
           goto FAIL;
       }
       self->dispatcher = DispatchAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   Hub_free(self);
   return NULL;
}
Hub *Hub_clone(Hub *self) {
   Hub *other = Hub_new();
   other->padList = PadAr_clone(self->padList);
   other->trackList = TrackAr_clone(self->trackList);
   other->currBankPort = Port_clone(self->currBankPort);
   other->currFramePort = Port_clone(self->currFramePort);
   other->selBankPort = Port_clone(self->selBankPort);
   other->selFramePort = Port_clone(self->selFramePort);
   other->selPadPort = Port_clone(self->selPadPort);
   other->chokeGroupPort = Port_clone(self->chokeGroupPort);
   other->cgLocalGlobalMenu = DropDown_clone(self->cgLocalGlobalMenu);
   other->cgInstrumentMenu = DropDown_clone(self->cgInstrumentMenu);
   other->cgIndexMenu = DropDown_clone(self->cgIndexMenu);
   other->bank = self->bank;
   other->frame = self->frame;
   other->grabNextTappedPad = self->grabNextTappedPad;
   other->selectedPad = self->selectedPad;
   other->arguments = Arguments_clone(self->arguments);
   other->dispatcher = DispatchAr_clone(self->dispatcher);
   other->masterClock = self->masterClock;
   return self;
}
void Hub_setPadList(Hub *self, PadAr *value) {
   PadAr *old = self->padList;
   self->padList = value;
   PadAr_incRef(self->padList);
   PadAr_decRef(old);
}
void Hub_setTrackList(Hub *self, TrackAr *value) {
   TrackAr *old = self->trackList;
   self->trackList = value;
   TrackAr_incRef(self->trackList);
   TrackAr_decRef(old);
}
void Hub_setCurrBankPort(Hub *self, Port *value) {
   Port *old = self->currBankPort;
   self->currBankPort = value;
   Port_incRef(self->currBankPort);
   Port_decRef(old);
}
void Hub_setCurrFramePort(Hub *self, Port *value) {
   Port *old = self->currFramePort;
   self->currFramePort = value;
   Port_incRef(self->currFramePort);
   Port_decRef(old);
}
void Hub_setSelBankPort(Hub *self, Port *value) {
   Port *old = self->selBankPort;
   self->selBankPort = value;
   Port_incRef(self->selBankPort);
   Port_decRef(old);
}
void Hub_setSelFramePort(Hub *self, Port *value) {
   Port *old = self->selFramePort;
   self->selFramePort = value;
   Port_incRef(self->selFramePort);
   Port_decRef(old);
}
void Hub_setSelPadPort(Hub *self, Port *value) {
   Port *old = self->selPadPort;
   self->selPadPort = value;
   Port_incRef(self->selPadPort);
   Port_decRef(old);
}
void Hub_setChokeGroupPort(Hub *self, Port *value) {
   Port *old = self->chokeGroupPort;
   self->chokeGroupPort = value;
   Port_incRef(self->chokeGroupPort);
   Port_decRef(old);
}
void Hub_setCgLocalGlobalMenu(Hub *self, DropDown *value) {
   DropDown *old = self->cgLocalGlobalMenu;
   self->cgLocalGlobalMenu = value;
   DropDown_incRef(self->cgLocalGlobalMenu);
   DropDown_decRef(old);
}
void Hub_setCgInstrumentMenu(Hub *self, DropDown *value) {
   DropDown *old = self->cgInstrumentMenu;
   self->cgInstrumentMenu = value;
   DropDown_incRef(self->cgInstrumentMenu);
   DropDown_decRef(old);
}
void Hub_setCgIndexMenu(Hub *self, DropDown *value) {
   DropDown *old = self->cgIndexMenu;
   self->cgIndexMenu = value;
   DropDown_incRef(self->cgIndexMenu);
   DropDown_decRef(old);
}
void Hub_setArguments(Hub *self, Arguments *value) {
   Arguments *old = self->arguments;
   self->arguments = value;
   Arguments_incRef(self->arguments);
   Arguments_decRef(old);
}
void Hub_setDispatcher(Hub *self, DispatchAr *value) {
   DispatchAr *old = self->dispatcher;
   self->dispatcher = value;
   DispatchAr_incRef(self->dispatcher);
   DispatchAr_decRef(old);
}
IncrementFrameDispatch *IncrementFrameDispatch_new()
{
   IncrementFrameDispatch *self = Mem_malloc(sizeof(IncrementFrameDispatch));
   self->itype = IncrementFrameDispatch_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   self->marshal = 0;
   return self;
}
void IncrementFrameDispatch_incRef(IncrementFrameDispatch *self)
{
    self->refCount++;
}
void IncrementFrameDispatch_decRef(IncrementFrameDispatch *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *IncrementFrameDispatch_toJson(IncrementFrameDispatch *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "IncrementFrameDispatch") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type IncrementFrameDispatch");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
IncrementFrameDispatch *IncrementFrameDispatch_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "IncrementFrameDispatch_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type IncrementFrameDispatch");
           return NULL;
       } else if (strcmp(s, "IncrementFrameDispatch") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'IncrementFrameDispatch'", s);
           return NULL;
       }
       
   }

   IncrementFrameDispatch *self = IncrementFrameDispatch_new();
   return self;

   FAIL:
   IncrementFrameDispatch_free(self);
   return NULL;
}
IncrementFrameDispatch *IncrementFrameDispatch_clone(IncrementFrameDispatch *self) {
   IncrementFrameDispatch *other = IncrementFrameDispatch_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   other->marshal = self->marshal;
   return self;
}
Int *Int_new()
{
   Int *self = Mem_malloc(sizeof(Int));
   self->itype = Int_itype;
   self->refCount = 1;
   self->i = 0;
   return self;
}
void Int_incRef(Int *self)
{
    self->refCount++;
}
void Int_decRef(Int *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *Int_toJson(Int *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Int") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Int");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Int *Int_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Int_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Int");
           return NULL;
       } else if (strcmp(s, "Int") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Int'", s);
           return NULL;
       }
       
   }

   Int *self = Int_new();
   return self;

   FAIL:
   Int_free(self);
   return NULL;
}
Int *Int_clone(Int *self) {
   Int *other = Int_new();
   other->i = self->i;
   return self;
}
#define IntAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
IntAr *IntAr_clone(IntAr *arr);
void IntAr_decRef(IntAr *arr);
void IntAr_fit(IntAr *arr);
#define IntAr_foreach(var, arr)               for (IntArFIt var = {arr, false, 0, NULL};        IntArFIt_next(&var); )
#define IntAr_foreachOffset(var, arr, offset) for (IntArFIt var = {arr, false, offset-1, NULL}; IntArFIt_next(&var); )
IntAr *IntAr_fromJson(JSON_Value *jval, Error *err);
Int *IntAr_get(IntAr *arr, int index, Error *err);
void IntAr_incRef(IntAr *arr);
void IntAr_insert(IntAr *arr, int index, Int *elem, Error *err);
int IntAr_last(IntAr *arr);
int IntAr_len(IntAr *arr);
IntAr *IntAr_new();
void IntAr_pop(IntAr *arr, Error *err);
Int *IntAr_pop(IntAr *arr, Error *err);
void IntAr_push(IntAr *arr, Int *elem);
void IntAr_remove(IntAr *arr, int index, Error *err);
void IntAr_reserve(IntAr *arr, int newCap);
#define IntAr_rforeach(var, arr)               for (IntArFIt var = {arr, false, (arr)->len, NULL};        IntArFIt_next(&var); )
#define IntAr_rforeachOffset(var, arr, offset) for (IntArFIt var = {arr, false, (arr)->len-offset, NULL}; IntArFIt_next(&var); )
void IntAr_set(IntAr *arr, int index, Int *elem, Error *err);
JSON_Value *IntAr_toJson(IntAr *self, Error *err);
void IntAr_truncate(IntAr *arr, int newLen);
bool IntArFIt_next(IntArFIt *iterator);
bool IntArRIt_next(IntArRIt *iterator);
void IntAr_binInsert(IntAr *arr, Int *elem);
void IntAr_binRemove(IntAr *arr, Int *elem);
Int *IntAr_binSearch(IntAr *arr, Int *elem);
Int *IntAr_pqPeek(IntAr *arr);
void IntAr_pqPopDecRef(IntAr *arr, Int *elem);
Int *IntAr_pqPop(IntAr *arr);
void IntAr_pqPush(IntAr *arr, Int *elem);
void IntAr_pqSort(IntAr *arr);
void IntAr_sort(IntAr *arr);
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_new()
{
   ManageChokeGroupsDispatch *self = Mem_malloc(sizeof(ManageChokeGroupsDispatch));
   self->itype = ManageChokeGroupsDispatch_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   self->marshal = 0;
   return self;
}
void ManageChokeGroupsDispatch_incRef(ManageChokeGroupsDispatch *self)
{
    self->refCount++;
}
void ManageChokeGroupsDispatch_decRef(ManageChokeGroupsDispatch *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *ManageChokeGroupsDispatch_toJson(ManageChokeGroupsDispatch *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "ManageChokeGroupsDispatch") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type ManageChokeGroupsDispatch");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "ManageChokeGroupsDispatch_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type ManageChokeGroupsDispatch");
           return NULL;
       } else if (strcmp(s, "ManageChokeGroupsDispatch") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'ManageChokeGroupsDispatch'", s);
           return NULL;
       }
       
   }

   ManageChokeGroupsDispatch *self = ManageChokeGroupsDispatch_new();
   return self;

   FAIL:
   ManageChokeGroupsDispatch_free(self);
   return NULL;
}
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_clone(ManageChokeGroupsDispatch *self) {
   ManageChokeGroupsDispatch *other = ManageChokeGroupsDispatch_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   other->marshal = self->marshal;
   return self;
}
int Marshal_nthIType(int n, int *itype);
#define Marshal_foreachIType(itype) for (int __##itype = 0, itype = 0; Marshal_nthIType(__##itype, &itype); __##itype++)
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom * a3, Error * a4, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Marshal_process");
       return 0;
   }
   switch(self->itype) {
       case MarshalSi_itype:
           MarshalSi_process((MarshalSi*)self, a1, a2, a3, a4, err);
           return;
       case MarshalSii_itype:
           MarshalSii_process((MarshalSii*)self, a1, a2, a3, a4, err);
           return;
       case MarshalSs_itype:
           MarshalSs_process((MarshalSs*)self, a1, a2, a3, a4, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in MarshalSs_process: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Marshal_zeroArgs");
       return 0;
   }
   switch(self->itype) {
       case MarshalSi_itype:
           MarshalSi_zeroArgs((MarshalSi*)self, a1);
           return;
       case MarshalSii_itype:
           MarshalSii_zeroArgs((MarshalSii*)self, a1);
           return;
       case MarshalSs_itype:
           MarshalSs_zeroArgs((MarshalSs*)self, a1);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in MarshalSs_zeroArgs: found type %s", Interface_toString(self->itype));
    }
    return;
}

MarshalSi *MarshalSi_new()
{
   MarshalSi *self = Mem_malloc(sizeof(MarshalSi));
   self->itype = MarshalSi_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   return self;
}
void MarshalSi_incRef(MarshalSi *self)
{
    self->refCount++;
}
void MarshalSi_decRef(MarshalSi *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *MarshalSi_toJson(MarshalSi *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "MarshalSi") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type MarshalSi");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
MarshalSi *MarshalSi_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "MarshalSi_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type MarshalSi");
           return NULL;
       } else if (strcmp(s, "MarshalSi") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'MarshalSi'", s);
           return NULL;
       }
       
   }

   MarshalSi *self = MarshalSi_new();
   return self;

   FAIL:
   MarshalSi_free(self);
   return NULL;
}
MarshalSi *MarshalSi_clone(MarshalSi *self) {
   MarshalSi *other = MarshalSi_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   return self;
}
MarshalSii *MarshalSii_new()
{
   MarshalSii *self = Mem_malloc(sizeof(MarshalSii));
   self->itype = MarshalSii_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   return self;
}
void MarshalSii_incRef(MarshalSii *self)
{
    self->refCount++;
}
void MarshalSii_decRef(MarshalSii *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *MarshalSii_toJson(MarshalSii *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "MarshalSii") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type MarshalSii");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
MarshalSii *MarshalSii_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "MarshalSii_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type MarshalSii");
           return NULL;
       } else if (strcmp(s, "MarshalSii") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'MarshalSii'", s);
           return NULL;
       }
       
   }

   MarshalSii *self = MarshalSii_new();
   return self;

   FAIL:
   MarshalSii_free(self);
   return NULL;
}
MarshalSii *MarshalSii_clone(MarshalSii *self) {
   MarshalSii *other = MarshalSii_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   return self;
}
MarshalSs *MarshalSs_new()
{
   MarshalSs *self = Mem_malloc(sizeof(MarshalSs));
   self->itype = MarshalSs_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   return self;
}
void MarshalSs_incRef(MarshalSs *self)
{
    self->refCount++;
}
void MarshalSs_decRef(MarshalSs *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *MarshalSs_toJson(MarshalSs *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "MarshalSs") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type MarshalSs");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
MarshalSs *MarshalSs_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "MarshalSs_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type MarshalSs");
           return NULL;
       } else if (strcmp(s, "MarshalSs") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'MarshalSs'", s);
           return NULL;
       }
       
   }

   MarshalSs *self = MarshalSs_new();
   return self;

   FAIL:
   MarshalSs_free(self);
   return NULL;
}
MarshalSs *MarshalSs_clone(MarshalSs *self) {
   MarshalSs *other = MarshalSs_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   return self;
}
MidiFileDropDispatch *MidiFileDropDispatch_new()
{
   MidiFileDropDispatch *self = Mem_malloc(sizeof(MidiFileDropDispatch));
   self->itype = MidiFileDropDispatch_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   self->marshal = 0;
   return self;
}
void MidiFileDropDispatch_incRef(MidiFileDropDispatch *self)
{
    self->refCount++;
}
void MidiFileDropDispatch_decRef(MidiFileDropDispatch *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *MidiFileDropDispatch_toJson(MidiFileDropDispatch *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "MidiFileDropDispatch") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type MidiFileDropDispatch");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
MidiFileDropDispatch *MidiFileDropDispatch_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "MidiFileDropDispatch_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type MidiFileDropDispatch");
           return NULL;
       } else if (strcmp(s, "MidiFileDropDispatch") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'MidiFileDropDispatch'", s);
           return NULL;
       }
       
   }

   MidiFileDropDispatch *self = MidiFileDropDispatch_new();
   return self;

   FAIL:
   MidiFileDropDispatch_free(self);
   return NULL;
}
MidiFileDropDispatch *MidiFileDropDispatch_clone(MidiFileDropDispatch *self) {
   MidiFileDropDispatch *other = MidiFileDropDispatch_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   other->marshal = self->marshal;
   return self;
}
MusicalContext *MusicalContext_new()
{
   MusicalContext *self = Mem_malloc(sizeof(MusicalContext));
   self->itype = MusicalContext_itype;
   self->refCount = 1;
   self->ticksPerQuarterNote = 0;
   self->quarterNotesPerMeasure = 0;
   return self;
}
void MusicalContext_incRef(MusicalContext *self)
{
    self->refCount++;
}
void MusicalContext_decRef(MusicalContext *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *MusicalContext_toJson(MusicalContext *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "MusicalContext") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type MusicalContext");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
MusicalContext *MusicalContext_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "MusicalContext_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type MusicalContext");
           return NULL;
       } else if (strcmp(s, "MusicalContext") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'MusicalContext'", s);
           return NULL;
       }
       
   }

   MusicalContext *self = MusicalContext_new();
   return self;

   FAIL:
   MusicalContext_free(self);
   return NULL;
}
MusicalContext *MusicalContext_clone(MusicalContext *self) {
   MusicalContext *other = MusicalContext_new();
   other->ticksPerQuarterNote = self->ticksPerQuarterNote;
   other->quarterNotesPerMeasure = self->quarterNotesPerMeasure;
   return self;
}
Array NoteEvent_pool     = {-1, 1};
int NoteEvent_poolSize   = 1000;
int NoteEvent_poolMiss   = 0;
NoteEvent *NoteEvent_new()
{
   NoteEvent *self = NULL;
   if (Array_len(&NoteEvent_pool) > 0) {
       Array_popN(&NoteEvent_pool, 1, &self, NULL, sizeof(void *));
   } else {
       self = Mem_malloc(sizeof(NoteEvent));
       NoteEvent_poolMiss++;
   }
   self->itype = NoteEvent_itype;
   self->refCount = 1;
   self->pitch = 0;
   self->velocity = 0;
   self->stime = 0;
   self->duration = 0;
   return self;
}
void NoteEvent_incRef(NoteEvent *self)
{
    self->refCount++;
}
void NoteEvent_decRef(NoteEvent *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
   if (Array_len(&NoteEvent_pool) < NoteEvent_poolSize) {
       memset(self, 0, sizeof(NoteEvent));
       Array_pushN(&NoteEvent_pool, 1, &self, NULL, sizeof(void *));
   } else {
       Mem_free(self);
   }
   return;
}
JSON_Value *NoteEvent_toJson(NoteEvent *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "NoteEvent") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type NoteEvent");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
NoteEvent *NoteEvent_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "NoteEvent_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type NoteEvent");
           return NULL;
       } else if (strcmp(s, "NoteEvent") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'NoteEvent'", s);
           return NULL;
       }
       
   }

   NoteEvent *self = NoteEvent_new();
   return self;

   FAIL:
   NoteEvent_free(self);
   return NULL;
}
NoteEvent *NoteEvent_clone(NoteEvent *self) {
   NoteEvent *other = NoteEvent_new();
   other->pitch = self->pitch;
   other->velocity = self->velocity;
   other->stime = self->stime;
   other->duration = self->duration;
   return self;
}
#define NoteEventAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
NoteEventAr *NoteEventAr_clone(NoteEventAr *arr);
void NoteEventAr_decRef(NoteEventAr *arr);
void NoteEventAr_fit(NoteEventAr *arr);
#define NoteEventAr_foreach(var, arr)               for (NoteEventArFIt var = {arr, false, 0, NULL};        NoteEventArFIt_next(&var); )
#define NoteEventAr_foreachOffset(var, arr, offset) for (NoteEventArFIt var = {arr, false, offset-1, NULL}; NoteEventArFIt_next(&var); )
NoteEventAr *NoteEventAr_fromJson(JSON_Value *jval, Error *err);
NoteEvent *NoteEventAr_get(NoteEventAr *arr, int index, Error *err);
void NoteEventAr_incRef(NoteEventAr *arr);
void NoteEventAr_insert(NoteEventAr *arr, int index, NoteEvent *elem, Error *err);
int NoteEventAr_last(NoteEventAr *arr);
int NoteEventAr_len(NoteEventAr *arr);
NoteEventAr *NoteEventAr_new();
void NoteEventAr_pop(NoteEventAr *arr, Error *err);
NoteEvent *NoteEventAr_pop(NoteEventAr *arr, Error *err);
void NoteEventAr_push(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_remove(NoteEventAr *arr, int index, Error *err);
void NoteEventAr_reserve(NoteEventAr *arr, int newCap);
#define NoteEventAr_rforeach(var, arr)               for (NoteEventArFIt var = {arr, false, (arr)->len, NULL};        NoteEventArFIt_next(&var); )
#define NoteEventAr_rforeachOffset(var, arr, offset) for (NoteEventArFIt var = {arr, false, (arr)->len-offset, NULL}; NoteEventArFIt_next(&var); )
void NoteEventAr_set(NoteEventAr *arr, int index, NoteEvent *elem, Error *err);
JSON_Value *NoteEventAr_toJson(NoteEventAr *self, Error *err);
void NoteEventAr_truncate(NoteEventAr *arr, int newLen);
bool NoteEventArFIt_next(NoteEventArFIt *iterator);
bool NoteEventArRIt_next(NoteEventArRIt *iterator);
void NoteEventAr_binInsert(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_binRemove(NoteEventAr *arr, NoteEvent *elem);
NoteEvent *NoteEventAr_binSearch(NoteEventAr *arr, NoteEvent *elem);
NoteEvent *NoteEventAr_pqPeek(NoteEventAr *arr);
void NoteEventAr_pqPopDecRef(NoteEventAr *arr, NoteEvent *elem);
NoteEvent *NoteEventAr_pqPop(NoteEventAr *arr);
void NoteEventAr_pqPush(NoteEventAr *arr, NoteEvent *elem);
void NoteEventAr_pqSort(NoteEventAr *arr);
void NoteEventAr_sort(NoteEventAr *arr);
NoteOutlet *NoteOutlet_new()
{
   NoteOutlet *self = Mem_malloc(sizeof(NoteOutlet));
   self->itype = NoteOutlet_itype;
   self->refCount = 1;
   self->atoms = AtomAr_new();
   self->port = Port_new();
   return self;
}
void NoteOutlet_incRef(NoteOutlet *self)
{
    self->refCount++;
}
void NoteOutlet_decRef(NoteOutlet *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       AtomAr_decRef(self->atoms);        
       Port_decRef(self->port);        
       Mem_free(self);
   }
   return;
}
JSON_Value *NoteOutlet_toJson(NoteOutlet *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "NoteOutlet") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type NoteOutlet");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = AtomAr_toJson(self->atoms, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "atoms", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of atoms on type NoteOutlet");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->port, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "port", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of port on type NoteOutlet");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
NoteOutlet *NoteOutlet_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "NoteOutlet_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type NoteOutlet");
           return NULL;
       } else if (strcmp(s, "NoteOutlet") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'NoteOutlet'", s);
           return NULL;
       }
       
   }

   NoteOutlet *self = NoteOutlet_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "atoms");
       if (target == NULL) {
           Error_format0(err, "'NoteOutlet' json object does not contain a json value for 'atoms'");
           goto FAIL;
       }
       self->atoms = AtomAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "port");
       if (target == NULL) {
           Error_format0(err, "'NoteOutlet' json object does not contain a json value for 'port'");
           goto FAIL;
       }
       self->port = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   NoteOutlet_free(self);
   return NULL;
}
NoteOutlet *NoteOutlet_clone(NoteOutlet *self) {
   NoteOutlet *other = NoteOutlet_new();
   other->atoms = AtomAr_clone(self->atoms);
   other->port = Port_clone(self->port);
   return self;
}
void NoteOutlet_setAtoms(NoteOutlet *self, AtomAr *value) {
   AtomAr *old = self->atoms;
   self->atoms = value;
   AtomAr_incRef(self->atoms);
   AtomAr_decRef(old);
}
void NoteOutlet_setPort(NoteOutlet *self, Port *value) {
   Port *old = self->port;
   self->port = value;
   Port_incRef(self->port);
   Port_decRef(old);
}
NoteSequence *NoteSequence_new()
{
   NoteSequence *self = Mem_malloc(sizeof(NoteSequence));
   self->itype = NoteSequence_itype;
   self->refCount = 1;
   self->version = 0;
   self->startTime = 0;
   self->outletSpecifier = OutletSpecifier_new();
   self->sequenceLength = 0;
   self->cursor = 0;
   self->cycle = 0;
   self->nextOffEvent = 0;
   self->nextOnEvent = 0;
   self->inEndgroup = 0;
   self->outlet = Outlet_new();
   self->recordingSeq = 0;
   self->offs = TimedOffAr_new();
   self->events = NoteEventAr_new();
   return self;
}
void NoteSequence_incRef(NoteSequence *self)
{
    self->refCount++;
}
void NoteSequence_decRef(NoteSequence *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       OutletSpecifier_decRef(self->outletSpecifier);        
       Outlet_decRef(self->outlet);        
       TimedOffAr_decRef(self->offs);        
       NoteEventAr_decRef(self->events);        
       Mem_free(self);
   }
   return;
}
JSON_Value *NoteSequence_toJson(NoteSequence *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "NoteSequence") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type NoteSequence");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = OutletSpecifier_toJson(self->outletSpecifier, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "outletSpecifier", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of outletSpecifier on type NoteSequence");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Outlet_toJson(self->outlet, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "outlet", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of outlet on type NoteSequence");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = TimedOffAr_toJson(self->offs, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "offs", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of offs on type NoteSequence");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = NoteEventAr_toJson(self->events, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "events", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of events on type NoteSequence");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
NoteSequence *NoteSequence_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "NoteSequence_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type NoteSequence");
           return NULL;
       } else if (strcmp(s, "NoteSequence") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'NoteSequence'", s);
           return NULL;
       }
       
   }

   NoteSequence *self = NoteSequence_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "outletSpecifier");
       if (target == NULL) {
           Error_format0(err, "'NoteSequence' json object does not contain a json value for 'outletSpecifier'");
           goto FAIL;
       }
       self->outletSpecifier = OutletSpecifier_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "outlet");
       if (target == NULL) {
           Error_format0(err, "'NoteSequence' json object does not contain a json value for 'outlet'");
           goto FAIL;
       }
       self->outlet = Outlet_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "offs");
       if (target == NULL) {
           Error_format0(err, "'NoteSequence' json object does not contain a json value for 'offs'");
           goto FAIL;
       }
       self->offs = TimedOffAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "events");
       if (target == NULL) {
           Error_format0(err, "'NoteSequence' json object does not contain a json value for 'events'");
           goto FAIL;
       }
       self->events = NoteEventAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   NoteSequence_free(self);
   return NULL;
}
NoteSequence *NoteSequence_clone(NoteSequence *self) {
   NoteSequence *other = NoteSequence_new();
   other->version = self->version;
   other->startTime = self->startTime;
   other->outletSpecifier = OutletSpecifier_clone(self->outletSpecifier);
   other->sequenceLength = self->sequenceLength;
   other->cursor = self->cursor;
   other->cycle = self->cycle;
   other->nextOffEvent = self->nextOffEvent;
   other->nextOnEvent = self->nextOnEvent;
   other->inEndgroup = self->inEndgroup;
   other->outlet = Outlet_clone(self->outlet);
   other->recordingSeq = self->recordingSeq;
   other->offs = TimedOffAr_clone(self->offs);
   other->events = NoteEventAr_clone(self->events);
   return self;
}
void NoteSequence_setOutletSpecifier(NoteSequence *self, OutletSpecifier *value) {
   OutletSpecifier *old = self->outletSpecifier;
   self->outletSpecifier = value;
   OutletSpecifier_incRef(self->outletSpecifier);
   OutletSpecifier_decRef(old);
}
void NoteSequence_setOutlet(NoteSequence *self, Outlet *value) {
   Outlet *old = self->outlet;
   self->outlet = value;
   Outlet_incRef(self->outlet);
   Outlet_decRef(old);
}
void NoteSequence_setOffs(NoteSequence *self, TimedOffAr *value) {
   TimedOffAr *old = self->offs;
   self->offs = value;
   TimedOffAr_incRef(self->offs);
   TimedOffAr_decRef(old);
}
void NoteSequence_setEvents(NoteSequence *self, NoteEventAr *value) {
   NoteEventAr *old = self->events;
   self->events = value;
   NoteEventAr_incRef(self->events);
   NoteEventAr_decRef(old);
}
NullOutlet *NullOutlet_new()
{
   NullOutlet *self = Mem_malloc(sizeof(NullOutlet));
   self->itype = NullOutlet_itype;
   self->refCount = 1;
   self->unused = 0;
   return self;
}
void NullOutlet_incRef(NullOutlet *self)
{
    self->refCount++;
}
void NullOutlet_decRef(NullOutlet *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *NullOutlet_toJson(NullOutlet *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "NullOutlet") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type NullOutlet");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
NullOutlet *NullOutlet_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "NullOutlet_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type NullOutlet");
           return NULL;
       } else if (strcmp(s, "NullOutlet") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'NullOutlet'", s);
           return NULL;
       }
       
   }

   NullOutlet *self = NullOutlet_new();
   return self;

   FAIL:
   NullOutlet_free(self);
   return NULL;
}
NullOutlet *NullOutlet_clone(NullOutlet *self) {
   NullOutlet *other = NullOutlet_new();
   other->unused = self->unused;
   return self;
}
int Outlet_nthIType(int n, int *itype);
#define Outlet_foreachIType(itype) for (int __##itype = 0, itype = 0; Outlet_nthIType(__##itype, &itype); __##itype++)
void Outlet_sendNote(Outlet *self, uint8_t a1, uint8_t a2, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Outlet_sendNote");
       return 0;
   }
   switch(self->itype) {
       case BendOutlet_itype:
           return;
       case CcOutlet_itype:
           return;
       case NoteOutlet_itype:
           NoteOutlet_sendNote((NoteOutlet*)self, a1, a2);
           return;
       case NullOutlet_itype:
           return;
       case VstOutlet_itype:
           return;
       default:
           Error_format(err, "Failed to resolve interface call in VstOutlet_sendNote: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Outlet_sendFloat(Outlet *self, double a1, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Outlet_sendFloat");
       return 0;
   }
   switch(self->itype) {
       case BendOutlet_itype:
           BendOutlet_sendFloat((BendOutlet*)self, a1);
           return;
       case CcOutlet_itype:
           CcOutlet_sendFloat((CcOutlet*)self, a1);
           return;
       case NoteOutlet_itype:
           return;
       case NullOutlet_itype:
           return;
       case VstOutlet_itype:
           VstOutlet_sendFloat((VstOutlet*)self, a1);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in VstOutlet_sendFloat: found type %s", Interface_toString(self->itype));
    }
    return;
}

OutletSpecifier *OutletSpecifier_new()
{
   OutletSpecifier *self = Mem_malloc(sizeof(OutletSpecifier));
   self->itype = OutletSpecifier_itype;
   self->refCount = 1;
   self->track = 0;
   self->pluginIndex = 0;
   self->parameter = 0;
   self->paramIndex = 0;
   return self;
}
void OutletSpecifier_incRef(OutletSpecifier *self)
{
    self->refCount++;
}
void OutletSpecifier_decRef(OutletSpecifier *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *OutletSpecifier_toJson(OutletSpecifier *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "OutletSpecifier") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type OutletSpecifier");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
OutletSpecifier *OutletSpecifier_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "OutletSpecifier_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type OutletSpecifier");
           return NULL;
       } else if (strcmp(s, "OutletSpecifier") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'OutletSpecifier'", s);
           return NULL;
       }
       
   }

   OutletSpecifier *self = OutletSpecifier_new();
   return self;

   FAIL:
   OutletSpecifier_free(self);
   return NULL;
}
OutletSpecifier *OutletSpecifier_clone(OutletSpecifier *self) {
   OutletSpecifier *other = OutletSpecifier_new();
   other->track = self->track;
   other->pluginIndex = self->pluginIndex;
   other->parameter = self->parameter;
   other->paramIndex = self->paramIndex;
   return self;
}
Pad *Pad_new()
{
   Pad *self = Mem_malloc(sizeof(Pad));
   self->itype = Pad_itype;
   self->refCount = 1;
   self->trackName = 0;
   self->padIndex = 0;
   self->SequenceAr = Sequence_new();
   self->chokeGroupGlobal = 0;
   self->chokeGroupInstrument = 0;
   self->chokeGroupIndex = 0;
   self->chokeGroup = 0;
   self->noteReleasePending = 0;
   self->inEndgroup = 0;
   self->track = Track_new();
   self->useMasterClock = 0;
   return self;
}
void Pad_incRef(Pad *self)
{
    self->refCount++;
}
void Pad_decRef(Pad *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Sequence_decRef(self->SequenceAr);        
       Track_decRef(self->track);        
       Mem_free(self);
   }
   return;
}
JSON_Value *Pad_toJson(Pad *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Pad") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Pad");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Sequence_toJson(self->SequenceAr, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "SequenceAr", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of SequenceAr on type Pad");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Track_toJson(self->track, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "track", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of track on type Pad");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Pad *Pad_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Pad_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Pad");
           return NULL;
       } else if (strcmp(s, "Pad") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Pad'", s);
           return NULL;
       }
       
   }

   Pad *self = Pad_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "SequenceAr");
       if (target == NULL) {
           Error_format0(err, "'Pad' json object does not contain a json value for 'SequenceAr'");
           goto FAIL;
       }
       self->SequenceAr = Sequence_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "track");
       if (target == NULL) {
           Error_format0(err, "'Pad' json object does not contain a json value for 'track'");
           goto FAIL;
       }
       self->track = Track_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   Pad_free(self);
   return NULL;
}
Pad *Pad_clone(Pad *self) {
   Pad *other = Pad_new();
   other->trackName = self->trackName;
   other->padIndex = self->padIndex;
   other->SequenceAr = Sequence_clone(self->SequenceAr);
   other->chokeGroupGlobal = self->chokeGroupGlobal;
   other->chokeGroupInstrument = self->chokeGroupInstrument;
   other->chokeGroupIndex = self->chokeGroupIndex;
   other->chokeGroup = self->chokeGroup;
   other->noteReleasePending = self->noteReleasePending;
   other->inEndgroup = self->inEndgroup;
   other->track = Track_clone(self->track);
   other->useMasterClock = self->useMasterClock;
   return self;
}
void Pad_setSequenceAr(Pad *self, Sequence *value) {
   Sequence *old = self->SequenceAr;
   self->SequenceAr = value;
   Sequence_incRef(self->SequenceAr);
   Sequence_decRef(old);
}
void Pad_setTrack(Pad *self, Track *value) {
   Track *old = self->track;
   self->track = value;
   Track_incRef(self->track);
   Track_decRef(old);
}
#define PadAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PadAr *PadAr_clone(PadAr *arr);
void PadAr_decRef(PadAr *arr);
void PadAr_fit(PadAr *arr);
#define PadAr_foreach(var, arr)               for (PadArFIt var = {arr, false, 0, NULL};        PadArFIt_next(&var); )
#define PadAr_foreachOffset(var, arr, offset) for (PadArFIt var = {arr, false, offset-1, NULL}; PadArFIt_next(&var); )
PadAr *PadAr_fromJson(JSON_Value *jval, Error *err);
Pad *PadAr_get(PadAr *arr, int index, Error *err);
void PadAr_incRef(PadAr *arr);
void PadAr_insert(PadAr *arr, int index, Pad *elem, Error *err);
int PadAr_last(PadAr *arr);
int PadAr_len(PadAr *arr);
PadAr *PadAr_new();
void PadAr_pop(PadAr *arr, Error *err);
Pad *PadAr_pop(PadAr *arr, Error *err);
void PadAr_push(PadAr *arr, Pad *elem);
void PadAr_remove(PadAr *arr, int index, Error *err);
void PadAr_reserve(PadAr *arr, int newCap);
#define PadAr_rforeach(var, arr)               for (PadArFIt var = {arr, false, (arr)->len, NULL};        PadArFIt_next(&var); )
#define PadAr_rforeachOffset(var, arr, offset) for (PadArFIt var = {arr, false, (arr)->len-offset, NULL}; PadArFIt_next(&var); )
void PadAr_set(PadAr *arr, int index, Pad *elem, Error *err);
JSON_Value *PadAr_toJson(PadAr *self, Error *err);
void PadAr_truncate(PadAr *arr, int newLen);
bool PadArFIt_next(PadArFIt *iterator);
bool PadArRIt_next(PadArRIt *iterator);
void Port_setProxy(Port *self, PtrAr *value) {
   PtrAr *old = self->proxy;
   self->proxy = value;
   PtrAr_incRef(self->proxy);
   PtrAr_decRef(old);
}
void Port_setOutlet(Port *self, PtrAr *value) {
   PtrAr *old = self->outlet;
   self->outlet = value;
   PtrAr_incRef(self->outlet);
   PtrAr_decRef(old);
}
PortFind *PortFind_new()
{
   PortFind *self = Mem_malloc(sizeof(PortFind));
   self->itype = PortFind_itype;
   self->refCount = 1;
   self->objects = PortFindCellAr_new();
   self->hub = 0;
   self->anythingDispatch = 0;
   self->intDispatch = 0;
   return self;
}
void PortFind_incRef(PortFind *self)
{
    self->refCount++;
}
void PortFind_decRef(PortFind *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       PortFindCellAr_decRef(self->objects);        
       Mem_free(self);
   }
   return;
}
JSON_Value *PortFind_toJson(PortFind *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "PortFind") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type PortFind");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = PortFindCellAr_toJson(self->objects, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "objects", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of objects on type PortFind");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
PortFind *PortFind_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "PortFind_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type PortFind");
           return NULL;
       } else if (strcmp(s, "PortFind") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'PortFind'", s);
           return NULL;
       }
       
   }

   PortFind *self = PortFind_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "objects");
       if (target == NULL) {
           Error_format0(err, "'PortFind' json object does not contain a json value for 'objects'");
           goto FAIL;
       }
       self->objects = PortFindCellAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   PortFind_free(self);
   return NULL;
}
PortFind *PortFind_clone(PortFind *self) {
   PortFind *other = PortFind_new();
   other->objects = PortFindCellAr_clone(self->objects);
   other->hub = self->hub;
   other->anythingDispatch = self->anythingDispatch;
   other->intDispatch = self->intDispatch;
   return self;
}
void PortFind_setObjects(PortFind *self, PortFindCellAr *value) {
   PortFindCellAr *old = self->objects;
   self->objects = value;
   PortFindCellAr_incRef(self->objects);
   PortFindCellAr_decRef(old);
}
PortFindCell *PortFindCell_new()
{
   PortFindCell *self = Mem_malloc(sizeof(PortFindCell));
   self->itype = PortFindCell_itype;
   self->refCount = 1;
   self->reciever = 0;
   self->varname = 0;
   return self;
}
void PortFindCell_incRef(PortFindCell *self)
{
    self->refCount++;
}
void PortFindCell_decRef(PortFindCell *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *PortFindCell_toJson(PortFindCell *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "PortFindCell") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type PortFindCell");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
PortFindCell *PortFindCell_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "PortFindCell_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type PortFindCell");
           return NULL;
       } else if (strcmp(s, "PortFindCell") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'PortFindCell'", s);
           return NULL;
       }
       
   }

   PortFindCell *self = PortFindCell_new();
   return self;

   FAIL:
   PortFindCell_free(self);
   return NULL;
}
PortFindCell *PortFindCell_clone(PortFindCell *self) {
   PortFindCell *other = PortFindCell_new();
   other->reciever = self->reciever;
   other->varname = self->varname;
   return self;
}
#define PortFindCellAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PortFindCellAr *PortFindCellAr_clone(PortFindCellAr *arr);
void PortFindCellAr_decRef(PortFindCellAr *arr);
void PortFindCellAr_fit(PortFindCellAr *arr);
#define PortFindCellAr_foreach(var, arr)               for (PortFindCellArFIt var = {arr, false, 0, NULL};        PortFindCellArFIt_next(&var); )
#define PortFindCellAr_foreachOffset(var, arr, offset) for (PortFindCellArFIt var = {arr, false, offset-1, NULL}; PortFindCellArFIt_next(&var); )
PortFindCellAr *PortFindCellAr_fromJson(JSON_Value *jval, Error *err);
PortFindCell *PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err);
void PortFindCellAr_incRef(PortFindCellAr *arr);
void PortFindCellAr_insert(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err);
int PortFindCellAr_last(PortFindCellAr *arr);
int PortFindCellAr_len(PortFindCellAr *arr);
PortFindCellAr *PortFindCellAr_new();
void PortFindCellAr_pop(PortFindCellAr *arr, Error *err);
PortFindCell *PortFindCellAr_pop(PortFindCellAr *arr, Error *err);
void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell *elem);
void PortFindCellAr_remove(PortFindCellAr *arr, int index, Error *err);
void PortFindCellAr_reserve(PortFindCellAr *arr, int newCap);
#define PortFindCellAr_rforeach(var, arr)               for (PortFindCellArFIt var = {arr, false, (arr)->len, NULL};        PortFindCellArFIt_next(&var); )
#define PortFindCellAr_rforeachOffset(var, arr, offset) for (PortFindCellArFIt var = {arr, false, (arr)->len-offset, NULL}; PortFindCellArFIt_next(&var); )
void PortFindCellAr_set(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err);
JSON_Value *PortFindCellAr_toJson(PortFindCellAr *self, Error *err);
void PortFindCellAr_truncate(PortFindCellAr *arr, int newLen);
bool PortFindCellArFIt_next(PortFindCellArFIt *iterator);
bool PortFindCellArRIt_next(PortFindCellArRIt *iterator);
PortRef *PortRef_new()
{
   PortRef *self = Mem_malloc(sizeof(PortRef));
   self->itype = PortRef_itype;
   self->refCount = 1;
   self->port = 0;
   self->outlet = 0;
   return self;
}
void PortRef_incRef(PortRef *self)
{
    self->refCount++;
}
void PortRef_decRef(PortRef *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *PortRef_toJson(PortRef *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "PortRef") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type PortRef");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
PortRef *PortRef_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "PortRef_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type PortRef");
           return NULL;
       } else if (strcmp(s, "PortRef") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'PortRef'", s);
           return NULL;
       }
       
   }

   PortRef *self = PortRef_new();
   return self;

   FAIL:
   PortRef_free(self);
   return NULL;
}
PortRef *PortRef_clone(PortRef *self) {
   PortRef *other = PortRef_new();
   other->port = self->port;
   other->outlet = self->outlet;
   return self;
}
Ptr *Ptr_new()
{
   Ptr *self = Mem_malloc(sizeof(Ptr));
   self->itype = Ptr_itype;
   self->refCount = 1;
   self->p = 0;
   return self;
}
void Ptr_incRef(Ptr *self)
{
    self->refCount++;
}
void Ptr_decRef(Ptr *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *Ptr_toJson(Ptr *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Ptr") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Ptr");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Ptr *Ptr_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Ptr_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Ptr");
           return NULL;
       } else if (strcmp(s, "Ptr") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Ptr'", s);
           return NULL;
       }
       
   }

   Ptr *self = Ptr_new();
   return self;

   FAIL:
   Ptr_free(self);
   return NULL;
}
Ptr *Ptr_clone(Ptr *self) {
   Ptr *other = Ptr_new();
   other->p = self->p;
   return self;
}
#define PtrAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
PtrAr *PtrAr_clone(PtrAr *arr);
void PtrAr_decRef(PtrAr *arr);
void PtrAr_fit(PtrAr *arr);
#define PtrAr_foreach(var, arr)               for (PtrArFIt var = {arr, false, 0, NULL};        PtrArFIt_next(&var); )
#define PtrAr_foreachOffset(var, arr, offset) for (PtrArFIt var = {arr, false, offset-1, NULL}; PtrArFIt_next(&var); )
PtrAr *PtrAr_fromJson(JSON_Value *jval, Error *err);
Ptr *PtrAr_get(PtrAr *arr, int index, Error *err);
void PtrAr_incRef(PtrAr *arr);
void PtrAr_insert(PtrAr *arr, int index, Ptr *elem, Error *err);
int PtrAr_last(PtrAr *arr);
int PtrAr_len(PtrAr *arr);
PtrAr *PtrAr_new();
void PtrAr_pop(PtrAr *arr, Error *err);
Ptr *PtrAr_pop(PtrAr *arr, Error *err);
void PtrAr_push(PtrAr *arr, Ptr *elem);
void PtrAr_remove(PtrAr *arr, int index, Error *err);
void PtrAr_reserve(PtrAr *arr, int newCap);
#define PtrAr_rforeach(var, arr)               for (PtrArFIt var = {arr, false, (arr)->len, NULL};        PtrArFIt_next(&var); )
#define PtrAr_rforeachOffset(var, arr, offset) for (PtrArFIt var = {arr, false, (arr)->len-offset, NULL}; PtrArFIt_next(&var); )
void PtrAr_set(PtrAr *arr, int index, Ptr *elem, Error *err);
JSON_Value *PtrAr_toJson(PtrAr *self, Error *err);
void PtrAr_truncate(PtrAr *arr, int newLen);
bool PtrArFIt_next(PtrArFIt *iterator);
bool PtrArRIt_next(PtrArRIt *iterator);
RecordBuffer *RecordBuffer_new()
{
   RecordBuffer *self = Mem_malloc(sizeof(RecordBuffer));
   self->itype = RecordBuffer_itype;
   self->refCount = 1;
   self->recordStart = 0;
   self->sequences = SequenceAr_new();
   return self;
}
void RecordBuffer_incRef(RecordBuffer *self)
{
    self->refCount++;
}
void RecordBuffer_decRef(RecordBuffer *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       SequenceAr_decRef(self->sequences);        
       Mem_free(self);
   }
   return;
}
JSON_Value *RecordBuffer_toJson(RecordBuffer *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "RecordBuffer") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type RecordBuffer");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = SequenceAr_toJson(self->sequences, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "sequences", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of sequences on type RecordBuffer");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
RecordBuffer *RecordBuffer_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "RecordBuffer_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type RecordBuffer");
           return NULL;
       } else if (strcmp(s, "RecordBuffer") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'RecordBuffer'", s);
           return NULL;
       }
       
   }

   RecordBuffer *self = RecordBuffer_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "sequences");
       if (target == NULL) {
           Error_format0(err, "'RecordBuffer' json object does not contain a json value for 'sequences'");
           goto FAIL;
       }
       self->sequences = SequenceAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   RecordBuffer_free(self);
   return NULL;
}
RecordBuffer *RecordBuffer_clone(RecordBuffer *self) {
   RecordBuffer *other = RecordBuffer_new();
   other->recordStart = self->recordStart;
   other->sequences = SequenceAr_clone(self->sequences);
   return self;
}
void RecordBuffer_setSequences(RecordBuffer *self, SequenceAr *value) {
   SequenceAr *old = self->sequences;
   self->sequences = value;
   SequenceAr_incRef(self->sequences);
   SequenceAr_decRef(old);
}
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_new()
{
   SelectNextPushedPadDispatch *self = Mem_malloc(sizeof(SelectNextPushedPadDispatch));
   self->itype = SelectNextPushedPadDispatch_itype;
   self->refCount = 1;
   self->selector = 0;
   self->portId = 0;
   self->inlet = 0;
   self->marshal = 0;
   return self;
}
void SelectNextPushedPadDispatch_incRef(SelectNextPushedPadDispatch *self)
{
    self->refCount++;
}
void SelectNextPushedPadDispatch_decRef(SelectNextPushedPadDispatch *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *SelectNextPushedPadDispatch_toJson(SelectNextPushedPadDispatch *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "SelectNextPushedPadDispatch") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type SelectNextPushedPadDispatch");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "SelectNextPushedPadDispatch_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type SelectNextPushedPadDispatch");
           return NULL;
       } else if (strcmp(s, "SelectNextPushedPadDispatch") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'SelectNextPushedPadDispatch'", s);
           return NULL;
       }
       
   }

   SelectNextPushedPadDispatch *self = SelectNextPushedPadDispatch_new();
   return self;

   FAIL:
   SelectNextPushedPadDispatch_free(self);
   return NULL;
}
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_clone(SelectNextPushedPadDispatch *self) {
   SelectNextPushedPadDispatch *other = SelectNextPushedPadDispatch_new();
   other->selector = self->selector;
   other->portId = self->portId;
   other->inlet = self->inlet;
   other->marshal = self->marshal;
   return self;
}
int Sequence_nthIType(int n, int *itype);
#define Sequence_foreachIType(itype) for (int __##itype = 0, itype = 0; Sequence_nthIType(__##itype, &itype); __##itype++)
void Sequence_start(Sequence *self, Ticks a1, Ticks a2, TimedPq *a3, RecordBuffer *a4, Error * *a5, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_start");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_start((FloatSequence*)self, a1, a2, a3, a4, a5, err);
           return;
       case NoteSequence_itype:
           NoteSequence_start((NoteSequence*)self, a1, a2, a3, a4, a5, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_start: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_drive(Sequence *self, Ticks a1, TimedPq *a2, Error * a3, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_drive");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_drive((FloatSequence*)self, a1, a2, a3, err);
           return;
       case NoteSequence_itype:
           NoteSequence_drive((NoteSequence*)self, a1, a2, a3, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_drive: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_stop(Sequence *self, Ticks a1, Error * a2, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_stop");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_stop((FloatSequence*)self, a1, a2, err);
           return;
       case NoteSequence_itype:
           NoteSequence_stop((NoteSequence*)self, a1, a2, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_stop: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_padNoteOff(Sequence *self, Ticks a1, Error * a2, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_padNoteOff");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_padNoteOff((FloatSequence*)self, a1, a2, err);
           return;
       case NoteSequence_itype:
           NoteSequence_padNoteOff((NoteSequence*)self, a1, a2, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_padNoteOff: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_setCycle(Sequence *self, bool a1, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_setCycle");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_setCycle((FloatSequence*)self, a1);
           return;
       case NoteSequence_itype:
           NoteSequence_setCycle((NoteSequence*)self, a1);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_setCycle: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_free(Sequence *self, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_free");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_free((FloatSequence*)self);
           return;
       case NoteSequence_itype:
           NoteSequence_free((NoteSequence*)self);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_free: found type %s", Interface_toString(self->itype));
    }
    return;
}

Sequence *Sequence_compactNew(Sequence *self, Ticks a1, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_compactNew");
       return NULL;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           return FloatSequence_compactNew((FloatSequence*)self, a1);
       case NoteSequence_itype:
           return NoteSequence_compactNew((NoteSequence*)self, a1);
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_compactNew: found type %s", Interface_toString(self->itype));
    }
    return NULL;
}

void Sequence_compactConcat(Sequence *self, Sequence *a1, Error * a2, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_compactConcat");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_compactConcat((FloatSequence*)self, a1, a2, err);
           return;
       case NoteSequence_itype:
           NoteSequence_compactConcat((NoteSequence*)self, a1, a2, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_compactConcat: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_compactSortEvents(Sequence *self, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_compactSortEvents");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_compactSortEvents((FloatSequence*)self);
           return;
       case NoteSequence_itype:
           NoteSequence_compactSortEvents((NoteSequence*)self);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_compactSortEvents: found type %s", Interface_toString(self->itype));
    }
    return;
}

Ticks Sequence_compactComputeSequenceLength(Sequence *self, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_compactComputeSequenceLength");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           return FloatSequence_compactComputeSequenceLength((FloatSequence*)self);
       case NoteSequence_itype:
           return NoteSequence_compactComputeSequenceLength((NoteSequence*)self);
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_compactComputeSequenceLength: found type %s", Interface_toString(self->itype));
    }
    return 0;
}

void Sequence_compactFinish(Sequence *self, Ticks a1, Ticks a2, Error * a3, Error *err, Error *err)
{
   if (self == NULL) {
       Error_format0(err, "Undefined interface passed to Sequence_compactFinish");
       return 0;
   }
   switch(self->itype) {
       case FloatSequence_itype:
           FloatSequence_compactFinish((FloatSequence*)self, a1, a2, a3, err);
           return;
       case NoteSequence_itype:
           NoteSequence_compactFinish((NoteSequence*)self, a1, a2, a3, err);
           return;
       default:
           Error_format(err, "Failed to resolve interface call in NoteSequence_compactFinish: found type %s", Interface_toString(self->itype));
    }
    return;
}

#define SequenceAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SequenceAr *SequenceAr_clone(SequenceAr *arr);
void SequenceAr_decRef(SequenceAr *arr);
void SequenceAr_fit(SequenceAr *arr);
#define SequenceAr_foreach(var, arr)               for (SequenceArFIt var = {arr, false, 0, NULL};        SequenceArFIt_next(&var); )
#define SequenceAr_foreachOffset(var, arr, offset) for (SequenceArFIt var = {arr, false, offset-1, NULL}; SequenceArFIt_next(&var); )
SequenceAr *SequenceAr_fromJson(JSON_Value *jval, Error *err);
Sequence *SequenceAr_get(SequenceAr *arr, int index, Error *err);
void SequenceAr_incRef(SequenceAr *arr);
void SequenceAr_insert(SequenceAr *arr, int index, Sequence *elem, Error *err);
int SequenceAr_last(SequenceAr *arr);
int SequenceAr_len(SequenceAr *arr);
SequenceAr *SequenceAr_new();
void SequenceAr_pop(SequenceAr *arr, Error *err);
Sequence *SequenceAr_pop(SequenceAr *arr, Error *err);
void SequenceAr_push(SequenceAr *arr, Sequence *elem);
void SequenceAr_remove(SequenceAr *arr, int index, Error *err);
void SequenceAr_reserve(SequenceAr *arr, int newCap);
#define SequenceAr_rforeach(var, arr)               for (SequenceArFIt var = {arr, false, (arr)->len, NULL};        SequenceArFIt_next(&var); )
#define SequenceAr_rforeachOffset(var, arr, offset) for (SequenceArFIt var = {arr, false, (arr)->len-offset, NULL}; SequenceArFIt_next(&var); )
void SequenceAr_set(SequenceAr *arr, int index, Sequence *elem, Error *err);
JSON_Value *SequenceAr_toJson(SequenceAr *self, Error *err);
void SequenceAr_truncate(SequenceAr *arr, int newLen);
bool SequenceArFIt_next(SequenceArFIt *iterator);
bool SequenceArRIt_next(SequenceArRIt *iterator);
void SequenceAr_binInsert(SequenceAr *arr, Sequence *elem);
void SequenceAr_binRemove(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_binSearch(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPeek(SequenceAr *arr);
void SequenceAr_pqPopDecRef(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPop(SequenceAr *arr);
void SequenceAr_pqPush(SequenceAr *arr, Sequence *elem);
void SequenceAr_pqSort(SequenceAr *arr);
void SequenceAr_sort(SequenceAr *arr);
void SequenceAr_binInsertPointer(SequenceAr *arr, Sequence *elem);
void SequenceAr_binRemovePointer(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_binSearchPointer(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPeekPointer(SequenceAr *arr);
void SequenceAr_pqPopDecRefPointer(SequenceAr *arr, Sequence *elem);
Sequence *SequenceAr_pqPopPointer(SequenceAr *arr);
void SequenceAr_pqPushPointer(SequenceAr *arr, Sequence *elem);
void SequenceAr_pqSortPointer(SequenceAr *arr);
void SequenceAr_sortPointer(SequenceAr *arr);
#define StringAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
StringAr *StringAr_clone(StringAr *arr);
void StringAr_decRef(StringAr *arr);
void StringAr_fit(StringAr *arr);
#define StringAr_foreach(var, arr)               for (StringArFIt var = {arr, false, 0, NULL};        StringArFIt_next(&var); )
#define StringAr_foreachOffset(var, arr, offset) for (StringArFIt var = {arr, false, offset-1, NULL}; StringArFIt_next(&var); )
StringAr *StringAr_fromJson(JSON_Value *jval, Error *err);
String *StringAr_get(StringAr *arr, int index, Error *err);
void StringAr_incRef(StringAr *arr);
void StringAr_insert(StringAr *arr, int index, String *elem, Error *err);
int StringAr_last(StringAr *arr);
int StringAr_len(StringAr *arr);
StringAr *StringAr_new();
void StringAr_pop(StringAr *arr, Error *err);
String *StringAr_pop(StringAr *arr, Error *err);
void StringAr_push(StringAr *arr, String *elem);
void StringAr_remove(StringAr *arr, int index, Error *err);
void StringAr_reserve(StringAr *arr, int newCap);
#define StringAr_rforeach(var, arr)               for (StringArFIt var = {arr, false, (arr)->len, NULL};        StringArFIt_next(&var); )
#define StringAr_rforeachOffset(var, arr, offset) for (StringArFIt var = {arr, false, (arr)->len-offset, NULL}; StringArFIt_next(&var); )
void StringAr_set(StringAr *arr, int index, String *elem, Error *err);
JSON_Value *StringAr_toJson(StringAr *self, Error *err);
void StringAr_truncate(StringAr *arr, int newLen);
bool StringArFIt_next(StringArFIt *iterator);
bool StringArRIt_next(StringArRIt *iterator);
void StringAr_binInsert(StringAr *arr, String *elem);
void StringAr_binRemove(StringAr *arr, String *elem);
String *StringAr_binSearch(StringAr *arr, String *elem);
String *StringAr_pqPeek(StringAr *arr);
void StringAr_pqPopDecRef(StringAr *arr, String *elem);
String *StringAr_pqPop(StringAr *arr);
void StringAr_pqPush(StringAr *arr, String *elem);
void StringAr_pqSort(StringAr *arr);
void StringAr_sort(StringAr *arr);
#define SymbolAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SymbolAr *SymbolAr_clone(SymbolAr *arr);
void SymbolAr_decRef(SymbolAr *arr);
void SymbolAr_fit(SymbolAr *arr);
#define SymbolAr_foreach(var, arr)               for (SymbolArFIt var = {arr, false, 0, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_foreachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, offset-1, NULL}; SymbolArFIt_next(&var); )
SymbolAr *SymbolAr_fromJson(JSON_Value *jval, Error *err);
Symbol *SymbolAr_get(SymbolAr *arr, int index, Error *err);
void SymbolAr_incRef(SymbolAr *arr);
void SymbolAr_insert(SymbolAr *arr, int index, Symbol *elem, Error *err);
int SymbolAr_last(SymbolAr *arr);
int SymbolAr_len(SymbolAr *arr);
SymbolAr *SymbolAr_new();
void SymbolAr_pop(SymbolAr *arr, Error *err);
Symbol *SymbolAr_pop(SymbolAr *arr, Error *err);
void SymbolAr_push(SymbolAr *arr, Symbol *elem);
void SymbolAr_remove(SymbolAr *arr, int index, Error *err);
void SymbolAr_reserve(SymbolAr *arr, int newCap);
#define SymbolAr_rforeach(var, arr)               for (SymbolArFIt var = {arr, false, (arr)->len, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_rforeachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, (arr)->len-offset, NULL}; SymbolArFIt_next(&var); )
void SymbolAr_set(SymbolAr *arr, int index, Symbol *elem, Error *err);
JSON_Value *SymbolAr_toJson(SymbolAr *self, Error *err);
void SymbolAr_truncate(SymbolAr *arr, int newLen);
bool SymbolArFIt_next(SymbolArFIt *iterator);
bool SymbolArRIt_next(SymbolArRIt *iterator);
void SymbolAr_binInsertUnderlying(SymbolAr *arr, Symbol *elem);
void SymbolAr_binRemoveUnderlying(SymbolAr *arr, Symbol *elem);
Symbol *SymbolAr_binSearchUnderlying(SymbolAr *arr, Symbol *elem);
Symbol *SymbolAr_pqPeekUnderlying(SymbolAr *arr);
void SymbolAr_pqPopDecRefUnderlying(SymbolAr *arr, Symbol *elem);
Symbol *SymbolAr_pqPopUnderlying(SymbolAr *arr);
void SymbolAr_pqPushUnderlying(SymbolAr *arr, Symbol *elem);
void SymbolAr_pqSortUnderlying(SymbolAr *arr);
void SymbolAr_sortUnderlying(SymbolAr *arr);
#define SymbolAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
SymbolAr *SymbolAr_clone(SymbolAr *arr);
void SymbolAr_decRef(SymbolAr *arr);
void SymbolAr_fit(SymbolAr *arr);
#define SymbolAr_foreach(var, arr)               for (SymbolArFIt var = {arr, false, 0, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_foreachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, offset-1, NULL}; SymbolArFIt_next(&var); )
SymbolAr *SymbolAr_fromJson(JSON_Value *jval, Error *err);
Symbol *SymbolAr_get(SymbolAr *arr, int index, Error *err);
void SymbolAr_incRef(SymbolAr *arr);
void SymbolAr_insert(SymbolAr *arr, int index, Symbol *elem, Error *err);
int SymbolAr_last(SymbolAr *arr);
int SymbolAr_len(SymbolAr *arr);
SymbolAr *SymbolAr_new();
void SymbolAr_pop(SymbolAr *arr, Error *err);
Symbol *SymbolAr_pop(SymbolAr *arr, Error *err);
void SymbolAr_push(SymbolAr *arr, Symbol *elem);
void SymbolAr_remove(SymbolAr *arr, int index, Error *err);
void SymbolAr_reserve(SymbolAr *arr, int newCap);
#define SymbolAr_rforeach(var, arr)               for (SymbolArFIt var = {arr, false, (arr)->len, NULL};        SymbolArFIt_next(&var); )
#define SymbolAr_rforeachOffset(var, arr, offset) for (SymbolArFIt var = {arr, false, (arr)->len-offset, NULL}; SymbolArFIt_next(&var); )
void SymbolAr_set(SymbolAr *arr, int index, Symbol *elem, Error *err);
JSON_Value *SymbolAr_toJson(SymbolAr *self, Error *err);
void SymbolAr_truncate(SymbolAr *arr, int newLen);
bool SymbolArFIt_next(SymbolArFIt *iterator);
bool SymbolArRIt_next(SymbolArRIt *iterator);
Timed *Timed_new()
{
   Timed *self = Mem_malloc(sizeof(Timed));
   self->itype = Timed_itype;
   self->refCount = 1;
   self->time = 0;
   self->version = 0;
   self->sequence = Sequence_new();
   return self;
}
void Timed_incRef(Timed *self)
{
    self->refCount++;
}
void Timed_decRef(Timed *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Sequence_decRef(self->sequence);        
       Mem_free(self);
   }
   return;
}
JSON_Value *Timed_toJson(Timed *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Timed") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Timed");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Sequence_toJson(self->sequence, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "sequence", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of sequence on type Timed");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Timed *Timed_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Timed_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Timed");
           return NULL;
       } else if (strcmp(s, "Timed") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Timed'", s);
           return NULL;
       }
       
   }

   Timed *self = Timed_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "sequence");
       if (target == NULL) {
           Error_format0(err, "'Timed' json object does not contain a json value for 'sequence'");
           goto FAIL;
       }
       self->sequence = Sequence_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   Timed_free(self);
   return NULL;
}
Timed *Timed_clone(Timed *self) {
   Timed *other = Timed_new();
   other->time = self->time;
   other->version = self->version;
   other->sequence = Sequence_clone(self->sequence);
   return self;
}
void Timed_setSequence(Timed *self, Sequence *value) {
   Sequence *old = self->sequence;
   self->sequence = value;
   Sequence_incRef(self->sequence);
   Sequence_decRef(old);
}
TimedOff *TimedOff_new()
{
   TimedOff *self = Mem_malloc(sizeof(TimedOff));
   self->itype = TimedOff_itype;
   self->refCount = 1;
   self->time = 0;
   self->pitch = 0;
   return self;
}
void TimedOff_incRef(TimedOff *self)
{
    self->refCount++;
}
void TimedOff_decRef(TimedOff *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *TimedOff_toJson(TimedOff *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "TimedOff") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type TimedOff");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
TimedOff *TimedOff_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "TimedOff_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type TimedOff");
           return NULL;
       } else if (strcmp(s, "TimedOff") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'TimedOff'", s);
           return NULL;
       }
       
   }

   TimedOff *self = TimedOff_new();
   return self;

   FAIL:
   TimedOff_free(self);
   return NULL;
}
TimedOff *TimedOff_clone(TimedOff *self) {
   TimedOff *other = TimedOff_new();
   other->time = self->time;
   other->pitch = self->pitch;
   return self;
}
#define TimedOffAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
TimedOffAr *TimedOffAr_clone(TimedOffAr *arr);
void TimedOffAr_decRef(TimedOffAr *arr);
void TimedOffAr_fit(TimedOffAr *arr);
#define TimedOffAr_foreach(var, arr)               for (TimedOffArFIt var = {arr, false, 0, NULL};        TimedOffArFIt_next(&var); )
#define TimedOffAr_foreachOffset(var, arr, offset) for (TimedOffArFIt var = {arr, false, offset-1, NULL}; TimedOffArFIt_next(&var); )
TimedOffAr *TimedOffAr_fromJson(JSON_Value *jval, Error *err);
TimedOff *TimedOffAr_get(TimedOffAr *arr, int index, Error *err);
void TimedOffAr_incRef(TimedOffAr *arr);
void TimedOffAr_insert(TimedOffAr *arr, int index, TimedOff *elem, Error *err);
int TimedOffAr_last(TimedOffAr *arr);
int TimedOffAr_len(TimedOffAr *arr);
TimedOffAr *TimedOffAr_new();
void TimedOffAr_pop(TimedOffAr *arr, Error *err);
TimedOff *TimedOffAr_pop(TimedOffAr *arr, Error *err);
void TimedOffAr_push(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err);
void TimedOffAr_reserve(TimedOffAr *arr, int newCap);
#define TimedOffAr_rforeach(var, arr)               for (TimedOffArFIt var = {arr, false, (arr)->len, NULL};        TimedOffArFIt_next(&var); )
#define TimedOffAr_rforeachOffset(var, arr, offset) for (TimedOffArFIt var = {arr, false, (arr)->len-offset, NULL}; TimedOffArFIt_next(&var); )
void TimedOffAr_set(TimedOffAr *arr, int index, TimedOff *elem, Error *err);
JSON_Value *TimedOffAr_toJson(TimedOffAr *self, Error *err);
void TimedOffAr_truncate(TimedOffAr *arr, int newLen);
bool TimedOffArFIt_next(TimedOffArFIt *iterator);
bool TimedOffArRIt_next(TimedOffArRIt *iterator);
void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_binRemoveTime(TimedOffAr *arr, TimedOff *elem);
TimedOff *TimedOffAr_binSearchTime(TimedOffAr *arr, TimedOff *elem);
TimedOff *TimedOffAr_pqPeekTime(TimedOffAr *arr);
void TimedOffAr_pqPopDecRefTime(TimedOffAr *arr, TimedOff *elem);
TimedOff *TimedOffAr_pqPopTime(TimedOffAr *arr);
void TimedOffAr_pqPushTime(TimedOffAr *arr, TimedOff *elem);
void TimedOffAr_pqSortTime(TimedOffAr *arr);
void TimedOffAr_sortTime(TimedOffAr *arr);
#define TimedPq_at(arr, index) ((arr)->data[index*sizeof(void*)])
TimedPq *TimedPq_clone(TimedPq *arr);
void TimedPq_decRef(TimedPq *arr);
void TimedPq_fit(TimedPq *arr);
#define TimedPq_foreach(var, arr)               for (TimedPqFIt var = {arr, false, 0, NULL};        TimedPqFIt_next(&var); )
#define TimedPq_foreachOffset(var, arr, offset) for (TimedPqFIt var = {arr, false, offset-1, NULL}; TimedPqFIt_next(&var); )
TimedPq *TimedPq_fromJson(JSON_Value *jval, Error *err);
Timed *TimedPq_get(TimedPq *arr, int index, Error *err);
void TimedPq_incRef(TimedPq *arr);
void TimedPq_insert(TimedPq *arr, int index, Timed *elem, Error *err);
int TimedPq_last(TimedPq *arr);
int TimedPq_len(TimedPq *arr);
TimedPq *TimedPq_new();
void TimedPq_pop(TimedPq *arr, Error *err);
Timed *TimedPq_pop(TimedPq *arr, Error *err);
void TimedPq_push(TimedPq *arr, Timed *elem);
void TimedPq_remove(TimedPq *arr, int index, Error *err);
void TimedPq_reserve(TimedPq *arr, int newCap);
#define TimedPq_rforeach(var, arr)               for (TimedPqFIt var = {arr, false, (arr)->len, NULL};        TimedPqFIt_next(&var); )
#define TimedPq_rforeachOffset(var, arr, offset) for (TimedPqFIt var = {arr, false, (arr)->len-offset, NULL}; TimedPqFIt_next(&var); )
void TimedPq_set(TimedPq *arr, int index, Timed *elem, Error *err);
JSON_Value *TimedPq_toJson(TimedPq *self, Error *err);
void TimedPq_truncate(TimedPq *arr, int newLen);
bool TimedPqFIt_next(TimedPqFIt *iterator);
bool TimedPqRIt_next(TimedPqRIt *iterator);
void TimedPq_binInsert(TimedPq *arr, Timed *elem);
void TimedPq_binRemove(TimedPq *arr, Timed *elem);
Timed *TimedPq_binSearch(TimedPq *arr, Timed *elem);
Timed *TimedPq_pqPeek(TimedPq *arr);
void TimedPq_pqPopDecRef(TimedPq *arr, Timed *elem);
Timed *TimedPq_pqPop(TimedPq *arr);
void TimedPq_pqPush(TimedPq *arr, Timed *elem);
void TimedPq_pqSort(TimedPq *arr);
void TimedPq_sort(TimedPq *arr);
Track *Track_new()
{
   Track *self = Mem_malloc(sizeof(Track));
   self->itype = Track_itype;
   self->refCount = 1;
   self->name = 0;
   return self;
}
void Track_incRef(Track *self)
{
    self->refCount++;
}
void Track_decRef(Track *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       Mem_free(self);
   }
   return;
}
JSON_Value *Track_toJson(Track *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "Track") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type Track");
       goto FAIL;
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
Track *Track_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "Track_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type Track");
           return NULL;
       } else if (strcmp(s, "Track") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'Track'", s);
           return NULL;
       }
       
   }

   Track *self = Track_new();
   return self;

   FAIL:
   Track_free(self);
   return NULL;
}
Track *Track_clone(Track *self) {
   Track *other = Track_new();
   other->name = self->name;
   return self;
}
#define TrackAr_at(arr, index) ((arr)->data[index*sizeof(void*)])
TrackAr *TrackAr_clone(TrackAr *arr);
void TrackAr_decRef(TrackAr *arr);
void TrackAr_fit(TrackAr *arr);
#define TrackAr_foreach(var, arr)               for (TrackArFIt var = {arr, false, 0, NULL};        TrackArFIt_next(&var); )
#define TrackAr_foreachOffset(var, arr, offset) for (TrackArFIt var = {arr, false, offset-1, NULL}; TrackArFIt_next(&var); )
TrackAr *TrackAr_fromJson(JSON_Value *jval, Error *err);
Track *TrackAr_get(TrackAr *arr, int index, Error *err);
void TrackAr_incRef(TrackAr *arr);
void TrackAr_insert(TrackAr *arr, int index, Track *elem, Error *err);
int TrackAr_last(TrackAr *arr);
int TrackAr_len(TrackAr *arr);
TrackAr *TrackAr_new();
void TrackAr_pop(TrackAr *arr, Error *err);
Track *TrackAr_pop(TrackAr *arr, Error *err);
void TrackAr_push(TrackAr *arr, Track *elem);
void TrackAr_remove(TrackAr *arr, int index, Error *err);
void TrackAr_reserve(TrackAr *arr, int newCap);
#define TrackAr_rforeach(var, arr)               for (TrackArFIt var = {arr, false, (arr)->len, NULL};        TrackArFIt_next(&var); )
#define TrackAr_rforeachOffset(var, arr, offset) for (TrackArFIt var = {arr, false, (arr)->len-offset, NULL}; TrackArFIt_next(&var); )
void TrackAr_set(TrackAr *arr, int index, Track *elem, Error *err);
JSON_Value *TrackAr_toJson(TrackAr *self, Error *err);
void TrackAr_truncate(TrackAr *arr, int newLen);
bool TrackArFIt_next(TrackArFIt *iterator);
bool TrackArRIt_next(TrackArRIt *iterator);
VstOutlet *VstOutlet_new()
{
   VstOutlet *self = Mem_malloc(sizeof(VstOutlet));
   self->itype = VstOutlet_itype;
   self->refCount = 1;
   self->atoms = AtomAr_new();
   self->port = Port_new();
   return self;
}
void VstOutlet_incRef(VstOutlet *self)
{
    self->refCount++;
}
void VstOutlet_decRef(VstOutlet *self)
{
   self->refCount--;
   if (self->refCount <= 0) {
       AtomAr_decRef(self->atoms);        
       Port_decRef(self->port);        
       Mem_free(self);
   }
   return;
}
JSON_Value *VstOutlet_toJson(VstOutlet *self, Error *err) {
   JSON_Value *jval  = json_value_init_object();
   JSON_Object *jobj = json_value_get_object(jval);
   
   if (json_object_set_string(jobj, "*type", "VstOutlet") != JSONSuccess) {
       Error_format0(err, "toJson failed to set_string (typename) on type VstOutlet");
       goto FAIL;
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = AtomAr_toJson(self->atoms, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "atoms", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of atoms on type VstOutlet");
           goto FAIL;
       }
   }
   {   
       // NOTE: json_object_set_value TAKES target, it doesn't copy it.
       JSON_Value *target = Port_toJson(self->port, err);
       Error_gotoLabelOnError(err, FAIL);
       if (json_object_set_value(jobj, "port", target) != JSONSuccess) {
           json_value_free(target);
           Error_format0(err, "toJson failed to set_value (reference) of port on type VstOutlet");
           goto FAIL;
       }
   }
   return jval;

   FAIL:
   json_value_free(jval);
   return NULL;
}
VstOutlet *VstOutlet_fromJson(JSON_Value *jval, Error *err) {
   JSON_Object *jobj = json_value_get_object(jval);
   if (jobj == NULL) {
       Error_format0(err, "VstOutlet_fromJson passed non-object");
       return NULL;
   }
   {
       const char *s = json_object_get_string(jobj, "*type");
       if (s == NULL) {
           Error_format0(err, "fromJson object does not contain *type on type VstOutlet");
           return NULL;
       } else if (strcmp(s, "VstOutlet") != 0) {
           Error_format0(err, "fromJson *type mismatch: found '%s' expected 'VstOutlet'", s);
           return NULL;
       }
       
   }

   VstOutlet *self = VstOutlet_new();
   {   
       JSON_Value *target = json_object_get_value(jobj, "atoms");
       if (target == NULL) {
           Error_format0(err, "'VstOutlet' json object does not contain a json value for 'atoms'");
           goto FAIL;
       }
       self->atoms = AtomAr_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   {   
       JSON_Value *target = json_object_get_value(jobj, "port");
       if (target == NULL) {
           Error_format0(err, "'VstOutlet' json object does not contain a json value for 'port'");
           goto FAIL;
       }
       self->port = Port_fromJson(target, err);
       Error_gotoLabelOnError(err, FAIL);
   }
   return self;

   FAIL:
   VstOutlet_free(self);
   return NULL;
}
VstOutlet *VstOutlet_clone(VstOutlet *self) {
   VstOutlet *other = VstOutlet_new();
   other->atoms = AtomAr_clone(self->atoms);
   other->port = Port_clone(self->port);
   return self;
}
void VstOutlet_setAtoms(VstOutlet *self, AtomAr *value) {
   AtomAr *old = self->atoms;
   self->atoms = value;
   AtomAr_incRef(self->atoms);
   AtomAr_decRef(old);
}
void VstOutlet_setPort(VstOutlet *self, Port *value) {
   Port *old = self->port;
   self->port = value;
   Port_incRef(self->port);
   Port_decRef(old);
}
#line 1 "src/dispatch.in.c"

#line 15 "src/dispatch.in.c"

#line 35 "src/dispatch.in.c"

#line 56 "src/dispatch.in.c"

#line 77 "src/dispatch.in.c"

#line 98 "src/dispatch.in.c"

#line 144 "src/dispatch.in.c"

#line 169 "src/dispatch.in.c"

#line 194 "src/dispatch.in.c"

#line 219 "src/dispatch.in.c"

#line 244 "src/dispatch.in.c"

#line 269 "src/dispatch.in.c"





APIF void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSi expected 1 additional argument, found %d", (int)argc);
      return;
   }
   if (!Atom_isNumber(argv + 0)) {
      Error_format0(err, "MarshalSi second argument should be an integer");
      return;  
   }
   Arguments_setI1(args, Atom_toInteger(argv + 0));
}

APIF void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setI1(args, 0);
}

APIF void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 2) {
      Error_format(err, "MarshalSii expected 2 additional arguments, found %d", (int)argc);
      return;
   }
   if (!Atom_isNumber(argv + 0)) {
      Error_format0(err, "MarshalSii second argument should be an integer");
      return;  
   }
   if (!Atom_isNumber(argv + 1)) {
      Error_format0(err, "MarshalSii third argument should be an integer");
      return;  
   }
   Arguments_setI1(args, Atom_toInteger(argv + 0));
   Arguments_setI2(args, Atom_toInteger(argv + 1));
}

APIF void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setI1(args, 0);
   Arguments_setI2(args, 0);
}

APIF void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSs expected 1 additional arguments, found %d", (int)argc);
      return;
   }
   if (!Atom_isSymbol(argv + 0)) {
      Error_format0(err, "MarshalSs second argument should be an symbol");
      return;  
   }
   Arguments_setS1(args, Atom_toSymbol(argv + 0));
}

APIF void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setS1(args, NULL);
}

APIF Marshal *Marshal_create(int itype) {
   Marshal *self = (Marshal*)Mem_malloc(itype);
   self->itype = itype;
   return self;
}

APIF void Marshal_free(Marshal *self) {
   Mem_free(self);
}

APIF Dispatch *IncrementFrameDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("incrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
      if (Hub_frame(hub) >= (Hub_framesPerBank-1)) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)+1);
    Hub_updateGuiCurrentCoordinates(hub);
}

APIF Dispatch *DecrementFrameDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("decrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
    if (Hub_frame(hub) <= 0) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)-1);
    Hub_updateGuiCurrentCoordinates(hub);
}


APIF Dispatch *SelectNextPushedPadDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("selectNextPushedPad");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Hub_setGrabNextTappedPad(hub, true);
}


APIF Dispatch *MidiFileDropDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("midiFileDrop");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = Marshal_create(MarshalSs_itype); 
   return self;
}

APIF void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Symbol *path = Arguments_s1(args);
   
   const char *colon = strchr(Symbol_cstr(path), ':');
   if (colon == NULL) {
     Error_format0(err, "midiFileDrop expected to find colon (:) in filename");
     return;
   }
   String *filename = String_fmt("%s", colon+1);
   Midiseq *mseq = Midiseq_fromfile(filename, err);
   if (Error_iserror(err)) {
     return;
   }
   String_free(filename);
   Pad *pad = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
   if (Error_iserror(err)) {
     Midiseq_free(mseq);
     return;
   }
   Pad_setSequence(pad, mseq);
}

APIF Dispatch *ManageChokeGroupsDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = NULL;
   self->portId   = Symbol_gen("chokeGroup");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void ManageChokeGroupsDispatch_initDispatchAr(int itype, DispatchAr *disPtAr, Error *ignored) {
   for (int i = 0; i < 3; i++) {
      Dispatch *dis = ManageChokeGroupsDispatch_create(itype);
      dis->inlet    = i;
      DispatchAr_push(disPtAr, dis);
   }
   return;
}

APIF void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Pad *pad   = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
   long value = Arguments_ivalue(args);
   switch (self->inlet) {
      case 0:
         DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupGlobal(pad, value ? true : false);
         break;
      case 1:
         DropDown_setSelected(Hub_cgInstrumentMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupInstrument(pad, value);
         break;
      case 2:
         DropDown_setSelected(Hub_cgIndexMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupIndex(pad, value);
         break;
      default:
         Error_format(err, "INTERNAL ERROR: bad inlet %d", self->inlet);
         return;
   }
   Pad_computeChokeGroup(pad);
}

APIF int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp) 
{
   Dispatch *left = *leftp;
   Dispatch *right = *rightp;
   if (left->selector < right->selector) {
      return -1;
   } else if (left->selector > right->selector) {
      return 1;
   } else if (left->portId < right->portId) {
      return -1;
   } else if (left->portId > right->portId) {
      return 1;
   } else if (left->inlet < right->inlet) {
      return -1;
   } else if (left->inlet > right->inlet) {
      return 1;
   }
   return 0;
}

APIF void Dispatch_freeDefault(Dispatch *d) {
   Marshal_free(d->marshal);
   Mem_free(d);
}

APIF void Dispatch_initDispatchArDefault(int itype, DispatchAr *disPtAr, Error *err) {
   Dispatch *dis = Dispatch_create(itype, err);
   Error_returnVoidOnError(err);
   DispatchAr_push(disPtAr, dis);
}

APIF void DispatchAr_populate(DispatchAr *self, Error *err) {
   DispatchAr_truncate(self);
   Dispatch_foreachIType(itype) {
      Dispatch_initDispatchAr(itype, self, err);
      Error_maypost(err);
   }
   DispatchAr_sort(self);
}


#line 1 "src/midiseq.in.c"

#define APIF /**/
String *stripBaseName(const char *path);

#line 16 "src/midiseq.in.c"

APIF void String_split(String *src, const char *delim, StringPtAr *stringPtAr)
{
    static StringBody *buffer = NULL;
    if (buffer == NULL) {
        buffer = String_toStringBody(String_empty());
    }
    StringBody *body = String_toStringBody(src);
    if (buffer->len < body->len) {
        String *s = buffer->ch;
        String_resize(&s, body->len);
        buffer = String_toStringBody(s);
    }
    strncpy(buffer->ch, body->ch, body->len+1);
    StringPtAr_truncate(stringPtAr);   
    char *string = buffer->ch;
    char *token  = NULL;
    while ((token = strsep(&string, delim)) != NULL) {
        StringPtAr_push(stringPtAr, String_fmt("%s", token));
    }
    return;
}

#line 49 "src/midiseq.in.c"

APIF int Symbol_cmpUnderlying(Symbol *left, Symbol *right) 
{
    return strcmp(Symbol_cstr(left), Symbol_cstr(right)); 
}

#ifdef TEST_BUILD
SymbolPtAr *gSymbols = NULL;

APIF Symbol *Symbol_gen(const char *word) 
{
    if (gSymbols == NULL) {
        gSymbols = SymbolAr_new();
    }
    Symbol s  = {word};
    Symbol **rp = SymbolPtAr_binSearchUnderlying(gSymbols, &s);
    if (rp != NULL) {
        return *rp;
    }
    Symbol *n = Mem_calloc(sizeof(Symbol));
    n->name = strdup(word);
    SymbolPtAr_binInsertUnderlying(gSymbols, n);
    return n;
}

APIF void Symbol_freeAll() 
{
    SymbolPtAr_foreach(it, gSymbols) {
        Mem_free(*it.var);
    }
    SymbolPtAr_truncate(gSymbols);
}

#endif

#line 92 "src/midiseq.in.c"

#line 100 "src/midiseq.in.c"

#line 108 "src/midiseq.in.c"

#line 128 "src/midiseq.in.c"


Port Port_nullImpl =
{
    {
        0
    }
};

#define Port_null (&Port_nullImpl)


APIF Port *Port_new() 
{
    return Port_null;
}
APIF void Port_init(Port *p)
{
    *p = Port_nullImpl;
}

#ifndef TEST_BUILD
APIF void Port_free(Port *p)
{
}

APIF void Port_clear(Port *p)
{
}
#endif

// Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
APIF int port_parseEvSymbol(Symbol *id)
{
    int r = -1;
    int consumed = 0;
    if (id == NULL) {
        return -1;
    }

    if (sscanf(Symbol_cstr(id), "ev%d%n", &r, &consumed) != 1) {
        return -1;
    }
    if (strlen(Symbol_cstr(id)) != consumed) {
        return -1;
    }
    return r;
}

APIF void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err)
{   
    if (self == Port_null) {
        return;
    }
    
#ifndef TEST_BUILD
    Symbol *selector = Atom_toSymbol(argv + 0);
    void *out = PtrAr_get(&self->outlet, outletIndex, err);
    Error_returnVoidOnError(err);
    outlet_anything(out, selector, argc-1, argv+1);  
#else
    AtomArAr *arr = self->obj.utilityPointer;
    if (arr != NULL) {
        AtomAr subAr;
        AtomAr_init(&subAr, 0);
        for (int i = 0; i < argc; i++){
            AtomAr_push(&subAr, argv[i]);
        }
        AtomArAr_push(arr, subAr);
        // Explicitly DO NOT deallocate subAr
    }
#endif
}

APIF void Port_sendInteger(Port *self, int outlet, long value, Error *err) 
{
    if (self == Port_null) {
        return;
    }

    void *out = PtrAr_get(&self->outlet, outlet, err);
    Error_returnVoidOnError(err); 
#ifndef TEST_BUILD
    outlet_int(out, value);  
#else
    AtomArAr *arr = self->obj.utilityPointer;
    if (arr != NULL) {
        AtomAr subAr;
        AtomAr_init(&subAr, 0);
        AtomAr_push(&subAr, Atom_fromInteger(value));
        AtomArAr_push(arr, subAr);
        // Explicitly DO NOT deallocate subAr
    }
#endif
}

#line 232 "src/midiseq.in.c"

#line 240 "src/midiseq.in.c"

#line 248 "src/midiseq.in.c"

#line 257 "src/midiseq.in.c"
APIF int Int_cmp(Int *left, Int *right)
{
    if (left->i < right->i) {
        return -1;
    } else if (left->i > right->i) {
        return 1;
    }
    return 0;
}

#line 277 "src/midiseq.in.c"

#line 332 "src/midiseq.in.c"

#line 359 "src/midiseq.in.c"

#line 378 "src/midiseq.in.c"

#line 394 "src/midiseq.in.c"

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
COVER static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)
PortRef PortRef_nullImpl = {Port_null, 0};
#define PortRef_null  &PortRef_nullImpl
APIF static inline Symbol *PortRef_track(PortRef *self)
{ 
    return Port_track(self->port);
}


APIF int PortRef_cmp(PortRef *left, PortRef *right) 
{
    if (left->port < right->port) {
        return -1;
    } else if (left->port > right->port) {
        return 1;
    } else if (left->outlet < right->outlet) {
        return -1;
    } else if (left->outlet > right->outlet) {
        return 1;
    }
    return 0;
}



#line 445 "src/midiseq.in.c"

//
// D R O P   D O W N
//

APIF void DropDown_build(DropDown *self, const char **table, Outlet *outlet) {
    const char **ptr = table;
    while (*ptr) {
        Symbol *s = Symbol_gen(*ptr);
        SymbolAr_push(self->table, s);
        ptr++;
    }
    DropDown_setOutlet(self, outlet);
    return;
}

APIF DropDown *DropDown_newCGLocalGlobal(Outlet *outlet) {
    Coverage_off;
    const char *t[] = {
        "local",
        "global",
        NULL
    };
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

APIF DropDown *DropDown_newCGInstrument(Outlet *outlet) {
    Coverage_off;
    const char *t[] = {
        "none",
        "lead",
        "rhythm",
        "piano",
        "bass",
        "drums",
        NULL,
    };
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

APIF DropDown *DropDown_newCGIndex(DropDown *dd, Outlet *outlet) {
    Coverage_off;
    const char *t[] = {
        "none",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "11",
        "12",
        "13",
        "14",
        "15",
        "16",
        NULL
    };
    Coverage_on;
    DropDown *self = DropDown_new();
    DropDown_build(self, t, outlet);
    return self;
}

// APIF void DropDown_clear(DropDown *dd) {
//     SymbolPtrAr_clear(&dd->table);
// }

// APIF void DropDown_free(DropDown *dd) {
//     DropDown_clear(dd);
//     Mem_free(dd);
// }

APIF DropDown *DropDown_updateSelected(DropDown *dd, Error *err) {
    Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
    Error_returnVoidOnError(err);

    Atom a[2] = {Atom_fromSymbol(Symbol_gen("set")), Atom_fromSymbol(s)};
    // PortRef_send(DropDown_portRef(dd), 2, a, err);
}

APIF DropDown *DropDown_setSelected(DropDown *dd, int selected, Error *err) {
    if (selected < 0 || selected >= SymbolPtrAr_len(&dd->table)) {
        Error_format(err, "Index out of range (%d, %d)", selected, SymbolPtrAr_len(&dd->table));
        return;
    }
    dd->selected = selected;
}

APIF DropDown *DropDown_initializeMenu(DropDown *dd, Error *err) {
    Atom clear = Atom_fromSymbol(Symbol_gen("clear"));
    Atom append = Atom_fromSymbol(Symbol_gen("append"));

    // PortRef_send(&dd->portRef, 1, &clear, err);
    Error_returnVoidOnError(err);

    SymbolAr_foreach(it, &dd->table) {
        Atom a[2] = {append, Atom_fromSymbol(*it.var)};
        // PortRef_send(&dd->portRef, 2, a, err);
        Error_returnVoidOnError(err);        
    }
}
#line 639 "src/midiseq.in.c"

#line 657 "src/midiseq.in.c"

//
// U t i l i t y
//

// APIF int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line)
// {
//     errno = 0;
//     long v = strtol(src, NULL, 10);
//     if (errno != 0) {
//         Coverage_off;
//         Error_formatFileLine(err, function, file, line, String_fmt("Failed to convert int error code %s", 
//           (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));
//         Coverage_on;

//     }
//     return v;
// }


#define Midiseq_convertInt(src, err) Midiseq_convertIntFileLine(src, err, __func__, __FILE__, __LINE__)

// APIF Midiseq *Midiseq_newNote(int pitch)
// {
//     Midiseq *mseq = Midiseq_new();
//     MEventAr_truncate(&mseq->events);

//     mseq->sequenceLength = 480*4;
    
//     MEvent zero = {0}, cell = {0};

//     MEvent_t(cell)    = 0;
//     MEvent_type(cell) = Midiseq_endgrptype;
//     MEventAr_push(&mseq->events, cell);

//     cell = zero;
//     MEvent_t(cell)            = 0;
//     MEvent_type(cell)         = Midiseq_notetype;
//     MEvent_notePitch(cell)    = pitch;
//     MEvent_noteVelocity(cell) = 90;
//     MEvent_noteDuration(cell) = 480;
//     MEventAr_push(&mseq->events, cell);

//     cell              = zero;
//     MEvent_t(cell)    = mseq->sequenceLength;
//     MEvent_type(cell) = Midiseq_cycletype;
//     MEventAr_push(&mseq->events, cell);

//     MEventAr_fit(&mseq->events);

//     return mseq;
// }

//
// P A T C H E R    F I N D
//
#line 735 "src/midiseq.in.c"

#line 759 "src/midiseq.in.c"

#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


#ifndef TEST_BUILD
APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
{
    MaxObject *obj = jbox_get_object(targetBox);
    if (Symbol_gen("Port") != object_classname(obj)) {
        return 0;
    }

    Symbol *varname = object_attr_getsym(targetBox, Symbol_gen("varname"));
    if (varname == NULL) {
        varname = Symbol_gen("unknown");
    }

    PortFindCell pfc = {0};
    Port *port          = (Port*)obj;
    pfc.reciever        = port;
    pfc.varname         = varname;
    PortFindCellAr_push(&pf->objects, pfc);

    Port_setHub(port, PortFind_hub(pf));
    Port_setAnythingDispatch(port, PortFind_anythingDispatch(pf));
    Port_setIntDispatch(port, PortFind_intDispatch(pf));

    return 0;
}

APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
{
    PortFind_setHub(pf, hub);
    PortFind_setAnythingDispatch(pf, (Port_anythingDispatchFunc)Hub_anythingDispatch);
    PortFind_setIntDispatch(pf, (Port_intDispatchFunc)Hub_intDispatch);

    MaxObject *patcher = NULL;
    long result       = 0;
    t_max_err maxErr = object_obex_lookup(sourceMaxObject, Symbol_gen("#P"), &patcher);
    if (maxErr != MAX_ERR_NONE) {
        Error_format(err, "Failed object_obex_lookup (%s)", Error_maxErrToString(maxErr));
        return 0;
    }
    object_method(patcher, Symbol_gen("iterate"), PortFind_iterator, (void *)pf, PI_WANTBOX | PI_DEEP, &result);

    PortFind_setHub(pf, NULL);
    PortFind_setAnythingDispatch(pf, NULL);
    PortFind_setIntDispatch(pf, NULL);

    return 0;
}

#else 
APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
{
    return 0;
}
APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
{
    return 0;
}
#endif

APIF Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects) {
        if (it.var->varname == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects){
        if (it.var->reciever->track == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF Port *PortFind_findById(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects){
        if (Port_id(it.var->reciever) == symbol) {
            return it.var->reciever;
        }
    }
    return Port_null;
}


APIF int PortFind_portCount(PortFind *pf)
{
    return PortFindCellAr_len(&pf->objects);
}


APIF Port *PortFind_findByIndex(PortFind *pf, int index, Error *err)
{
    PortFindCell cell = PortFindCellAr_get(&pf->objects, index, err);
    if (Error_iserror(err)) {
        return Port_null;
    }
    
    return cell.reciever;
}

APIF Outlet *PortFind_createOutlet(PortFind *self, OutletSpecifier *spec) 
{
    Port *port = PortFind_findByTrack(self, spec->track);

    if (spec->parameter == Symbol_gen("*note")) {
        NoteOutlet *outlet = NoteOutlet_newBuild(port);
        return NoteOutlet_castToOutlet(outlet);
    } else if (spec->parameter == Symbol_gen("*bend")) {
        BendOutlet *outlet = BendOutlet_newBuild(port);
        return BendOutlet_castToOutlet(outlet);
    } else if (spec->parameter == Symbol_gen("*cc")) {
        CcOutlet *outlet = CcOutlet_newBuild(port, spec->paramIndex);
        return CcOutlet_castToOutlet(outlet);
    }
    
    return NullOutlet_castToOutlet(NullOutlet_new());
}


//
// P A D
//

APIF void Pad_computeChokeGroup(Pad *pad) {
    if (!Pad_chokeGroupGlobal(pad) && Pad_chokeGroupInstrument(pad) == 0 && Pad_chokeGroupIndex(pad) == 0) {
        Pad_setChokeGroup(pad, 0);
        return;    
    }

    int64_t value = 0;
    if (!Pad_chokeGroupGlobal(pad)) {

        int64_t bank  = hub_padIndexToBank(Pad_padIndex(pad));
        int64_t frame = hub_padIndexToFrame(Pad_padIndex(pad));

        //Hubbank;
        value |= bank & 0x7FFFFFFF;        // 32 bit for bank
        value |= (frame & 0xFF) << 32;     // 8 bit for frame
    }
    int64_t instrument = Pad_chokeGroupInstrument(pad);
    int64_t index      = Pad_chokeGroupIndex(pad);

    value |= (instrument & 0xFF) << 40; // 8 bits for instrument
    value |= (index & 0xFF)      << 48; // 8 bits for index
    Pad_setChokeGroup(pad, value);
}

//
// P A D   L I S T
//
APIF PadList *PadList_newN(int npads)
{
    PadList *self = PadList_new();
    PadAr_changeLength(&self->pads, npads);
    PadAr_foreach(it, &self->pads) {
        Pad_init(it.var);
    }
    return self;
}

APIF void PadList_play(PadList *self, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    Pad *pad = PadAr_getp(&self->pads, padIndex, err);
    Error_returnVoidOnError(err);

    // Since we're starting to play, we just recieved a Note-on for this pad. Reset the pad
    Pad_setInEndgroup(pad, false);
    Pad_setNoteReleasePending(pad, true);

    // Now let's find a place to stick this pad into the running array
    PadPtrAr_foreach(it, &self->running) {
        Pad *p = *it.var;
        if (Pad_chokeGroup(pad) != 0 && Pad_chokeGroup(pad) == Pad_chokeGroup(p)) {
            PadPtrAr_remove(&self->running, it.index, err);
            Error_returnVoidOnError(err);
            break;
        }
    }

    PadPtrAr_push(&self->running, pad);

   Midiseq_start(Pad_sequence(pad), startTime, currentTime, false, err);
}


APIF void PadList_markReleasePending(PadList *self, int padIndex, bool pending, Error *err)
{
    Pad *pad = PadAr_getp(&self->pads, padIndex, err);
    Error_returnVoidOnError(err);
    Pad_setNoteReleasePending(pad, pending);
    if (!pending) {
        // We recieved a note-off. So cancel any pending endgroups
        NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
    }
}

APIF Pad *PadList_pad(PadList *pl, int index, Error *err)
{
    return PadAr_getp(&pl->pads, index, err);
}


APIF void PadList_assignTrack(PadList *pl, TrackList *tl)
{
    PadAr_foreach(it, &pl->pads) {
        Pad *pad = it.var;
        Pad_setTrack(pad, TrackList_findTrackByName(tl, Pad_trackName(pad)));
    }
}




//
// I N D E X E D   AND   T I M E D   O F F
//

APIF int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right) {
    if (left->padIndex < right->padIndex) {
        return -1;
    } else if (left->padIndex > right->padIndex) {
        return 1;
    }
    return 0;
}

APIF int TimedOff_cmpTime(TimedOff *left, TimedOff *right) {
    if (left->time < right->time) {
        return -1;
    } else if (left->time > right->time) {
        return 1;
    }
    return 0;   
}

//
// H U B
//

APIF Hub *Hub_newBuild(PortFind *pf, Error *err) {
    Hub *self = Hub_new();
    Hub_build(self, pf, err);
    if (Error_iserror(err)) {
        Hub_free(self);
        return NULL;
    }
    return self;
}

APIF void Hub_build(Hub *hub, PortFind *pf, Error *err) {
    Hub_setCurrBankPort(hub, PortFind_findById(pf, Symbol_gen("currBank")));
    Hub_setCurrFramePort(hub, PortFind_findById(pf, Symbol_gen("currFrame")));
    Hub_setSelBankPort(hub, PortFind_findById(pf, Symbol_gen("selBank")));
    Hub_setSelFramePort(hub, PortFind_findById(pf, Symbol_gen("selFrame")));
    Hub_setSelPadPort(hub, PortFind_findById(pf, Symbol_gen("selPad")));

    /*
    Outlet *broken = NULL;
    // Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
    Hub_setCgLogcalGlobalMenu(hub, DropDown_newCGLocalGlobal(broken));
    Hub_setCgInstru(hub, DropDown_newCGInstrument(broken));

    DropDown_buildCGInstrument(Hub_cgInstrumentMenu(hub), portRef);

    PortRef_set(portRef, cg, 2);
    DropDown_buildCGIndex(Hub_cgIndexMenu(hub), portRef);

    DropDown_initializeMenu(Hub_cgLocalGlobalMenu(hub), err);
    Error_returnVoidOnError(err);

    DropDown_initializeMenu(Hub_cgInstrumentMenu(hub), err);
    Error_returnVoidOnError(err);

    DropDown_initializeMenu(Hub_cgIndexMenu(hub), err);
    Error_returnVoidOnError(err);    

    Atom a[2] = {Atom_fromSymbol(Symbol_gen("cantchange")), Atom_fromInteger(1)};
    Port_send(Hub_currBankPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    Port_send(Hub_currFramePort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);
    
    Port_send(Hub_selBankPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);
    
    Port_send(Hub_selFramePort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    Port_send(Hub_selPadPort(hub), 0, 2, a, err);
    Error_returnVoidOnError(err);

    DispatchPtAr_init(&hub->dispatcher, 0);
    DispatchPtAr_populate(&hub->dispatcher, err);
    Error_returnVoidOnError(err);
    */
}

APIF void Hub_updateGuiCurrentCoordinates(Hub *hub) 
{
    Error_declare(err);
    Port_sendInteger(Hub_currBankPort(hub),  0, Hub_bank(hub), err);
    Error_maypost(err);
    Port_sendInteger(Hub_currFramePort(hub), 0, Hub_frame(hub), err);
    Error_maypost(err);
}

APIF void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err) {
    Hub_setSelectedPad(hub, selectedPadIndex);
    Pad *pad = PadList_pad(Hub_padList(hub), selectedPadIndex, err);
    Error_returnVoidOnError(err);

    // choke group set
    DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), Pad_chokeGroupGlobal(pad) ? 1 : 0, err);
    Error_returnVoidOnError(err);
    DropDown_setSelected(Hub_cgInstrumentMenu(hub), Pad_chokeGroupInstrument(pad), err);
    Error_returnVoidOnError(err);
    DropDown_setSelected(Hub_cgIndexMenu(hub), Pad_chokeGroupIndex(pad), err);
    Error_returnVoidOnError(err);

    // Choke Group GUI
    DropDown_updateSelected(Hub_cgLocalGlobalMenu(hub), err);
    Error_returnVoidOnError(err);
    DropDown_updateSelected(Hub_cgInstrumentMenu(hub), err);
    Error_returnVoidOnError(err);
    DropDown_updateSelected(Hub_cgIndexMenu(hub), err);
    Error_returnVoidOnError(err);

    // Selected coordinates
    Port_sendInteger(Hub_selBankPort(hub),  0, (long)Hub_selectedBank(hub), err);
    Error_returnVoidOnError(err);
    Port_sendInteger(Hub_selFramePort(hub), 0, (long)Hub_selectedFrame(hub), err);  
    Error_returnVoidOnError(err);
    Port_sendInteger(Hub_selPadPort(hub),   0, (long)Hub_relativeSelectedPad(hub), err);
    Error_returnVoidOnError(err);
}

APIF void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv)
{

    Error_declare(err);

    Dispatch_declare(cell, Undefined_itype, selector, Port_id(port), 0, NULL);
    Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);

    if (dis == NULL) {
        return;
    }
    
    Marshal *marshal = Dispatch_marshal(*dis);
    if (marshal != NULL) {
        Marshal_process(marshal, &hub->arguments, argc, argv, err);
        if (Error_maypost(err)) {
            return;
        }
    }
    
    Dispatch_exec(*dis, hub, &hub->arguments, err);
    if (Error_maypost(err)) {
        return;
    }
    if (marshal != NULL) {
        Marshal_zeroArgs(marshal, &hub->arguments, err);
        if (Error_maypost(err)) {
            return;
        }
    }

    return;
}



APIF void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet)
{
    Error_declare(err);
    Dispatch_declare(cell, Undefined_itype, NULL, Port_id(port), (int)inlet, NULL);
    Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);
    if (dis == NULL) {
        return;
    }

    Arguments_setIvalue(&hub->arguments, value);
    Arguments_setInlet(&hub->arguments, inlet);
    Dispatch_exec(*dis, hub, &hub->arguments, err);
    if (Error_maypost(err)) {
        return;
    }
    Arguments_setIvalue(&hub->arguments, 0);
    Arguments_setInlet(&hub->arguments, 0);
}
#line 1 "src/sequence.in.c"

#line 17 "src/sequence.in.c"

#define MusicalContext_declareDefault(name) MusicalContext name = {.ticksPerQuarterNote = 480, .quarterNotesPerMeasure = 4}

#line 36 "src/sequence.in.c"

// This is the decimal representation of binary 10010000
#define NOTEON_COMMAND 144


APIF void NoteOutlet_sendNote(NoteOutlet *self, uint8_t pitch, uint8_t velocity)
{
#   ifdef TEST_BUILD
    // printf("OUTLET pitch=%d velocity=%d\n", pitch, velocity);
    NoteOutlet_dbRecordEvent(pitch, velocity);
#   endif

    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(NOTEON_COMMAND);
    av[2] = Atom_fromInteger(pitch);
    av[3] = Atom_fromInteger(velocity);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);
}

APIF NoteOutlet *NoteOutlet_newBuild(Port *port)
{
    NoteOutlet *self = NoteOutlet_new();
    self->port       = port;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}

#line 87 "src/sequence.in.c"

#ifdef TEST_BUILD
FloatEventAr *CcOutlet_dbSent = NULL;
APIF void CcOutlet_dbRewindSent() 
{
    if (CcOutlet_dbSent != NULL) {
        FloatEventAr_truncate(CcOutlet_dbSent);    
    }
}
#endif

// This is a decimal version of the binary number 10110000
#define CC_COMMAND 176
APIF void CcOutlet_sendFloat(CcOutlet *self, double value) 
{
#   ifdef TEST_BUILD
    if (CcOutlet_dbSent == NULL) {
        CcOutlet_dbSent = FloatEventAr_new(0);
    }
    FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
    FloatEventAr_push(CcOutlet_dbSent, e);
#   else
    int v = (int)value;
    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(CC_COMMAND);
    av[2] = Atom_fromInteger(self->cc);
    av[3] = Atom_fromInteger(v);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);   
#   endif
}

APIF CcOutlet *CcOutlet_newBuild(Port *port, int cc)
{
    CcOutlet *self = CcOutlet_new();
    self->port = port;
    self->cc   = cc;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}

#line 147 "src/sequence.in.c"

#ifdef TEST_BUILD
FloatEventAr *BendOutlet_dbSent = NULL;
APIF void BendOutlet_dbRewindSent() 
{
    if (BendOutlet_dbSent != NULL) {
        FloatEventAr_truncate(BendOutlet_dbSent);    
    }
}
#endif

#define BEND_COMMAND 224
APIF void BendOutlet_sendFloat(BendOutlet *self, double value)
{
#   ifdef TEST_BUILD
    if (BendOutlet_dbSent == NULL) {
        BendOutlet_dbSent = FloatEventAr_new(0);
    }
    FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
    FloatEventAr_push(BendOutlet_dbSent, e);
#   else
    int v = (int)value;
    int lsb = v & 0x7F;
    int msb = (v >> 7) & 0x7F;
    AtomAr_changeLength(&self->atoms, 4);
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(BEND_COMMAND);
    av[2] = Atom_fromInteger(msb);
    av[3] = Atom_fromInteger(lsb);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);   
#   endif
}

APIF BendOutlet *BendOutlet_newBuild(Port *port)
{
    BendOutlet *self = BendOutlet_new();
    self->port = port;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}


#line 208 "src/sequence.in.c"

APIF void VstOutlet_sendFloat(VstOutlet *self, double value)
{
}

#line 225 "src/sequence.in.c"


#line 248 "src/sequence.in.c"

#line 260 "src/sequence.in.c"

COVER void OutletSpecifier_dbPrint(OutletSpecifier *self)
{
    printf("OutletSpecifier %s %d %s %d\n", Symbol_cstr(self->track), self->pluginIndex, Symbol_cstr(self->parameter), self->paramIndex);
}

COVER OutletSpecifier OutletSpecifier_makeCC(Symbol *track, int cc) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*cc");
    self->paramIndex  = cc;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeBend(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*bend");
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeNote(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*note");
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeVst(Symbol *track, int pluginIndex, Symbol *parameter) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = pluginIndex;
    self->parameter   = parameter;
    self->paramIndex  = 0;
    return selfValue;
}

COVER OutletSpecifier OutletSpecifier_makeAudio() {
    // Every audio sequence sorts equal. So every audio sequence shares the same config for OutletSpecifier
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = Symbol_gen("*audio");
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*audio");
    self->paramIndex  = 0;
    return selfValue;
}


#line 338 "src/sequence.in.c"

APIF int Timed_cmp(Timed *left, Timed *right)
{
    if (left->time < right->time) {
        return -1;
    } else if (left->time > right->time) {
        return 1;
    }
    return 0;
}

APIF void TimedPq_enqueue(TimedPq *self, Ticks time, Sequence *s) {
    Sequence_incVersion(s);
    Timed cell = {.time = time, .version = Sequence_version(s), .sequence = s};
    TimedPq_pqPush(self, cell);
}

APIF Sequence *TimedPq_dequeue(TimedPq *self, Ticks current) {
    Timed *peeked = TimedPq_pqPeek(self);

    while (peeked != NULL) {
        if (Timed_time(peeked) > current) {
            break;
        } 

        Timed timed = {0};
        TimedPq_pqPop(self, &timed);
        Sequence *seq = Timed_sequence(&timed);
        if (seq != NULL && Timed_version(&timed) == Sequence_version(seq)) {
            return Timed_sequence(&timed);
        }       
        peeked = TimedPq_pqPeek(self);
    }

    return NULL;
}

APIF void TimedPq_invalidateSequence(TimedPq *self, SequenceAr *removes) 
{
    SequenceAr_sortPointer(removes);
    TimedPq_foreach(it, self) {
        Sequence *seq = Timed_sequence(it.var);
        if (seq == NULL) {
            continue;
        }
        if (SequenceAr_binSearchPointer(removes, seq) != NULL) {
            Timed_setSequence(it.var, NULL);
        }
    }
}



#line 414 "src/sequence.in.c"

Ticks NoteSequence_cycleDuration   = -1;
Ticks NoteSequence_endgDuration    = -2;
Ticks NoteSequence_noteOffDuration = -3;

APIF NoteEvent *NoteEvent_newValue(Ticks stime, int pitch, int velocity, Ticks duration)
{
    NoteEvent *self = NoteEvent_new();
    self->stime = stime;
    self->pitch = (uint8_t)pitch;
    self->velocity = (uint8_t)velocity;
    self->duration = duration;
    return self;
}

APIF int NoteEvent_cmp(NoteEvent *left, NoteEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    } 

    // This sorts cycle to the end of equal time, and endgroup to the begining of equal time.
    Coverage_off;
    Ticks leftDuration = left->duration >= 0 ? left->duration : 
                         left->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                         left->duration == NoteSequence_endgDuration ? -Ticks_maxTime : left->duration;
    Ticks rightDuration = right->duration >= 0 ? right->duration : 
                          right->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                          right->duration == NoteSequence_endgDuration ? -Ticks_maxTime : right->duration;
    Coverage_on;
    if (leftDuration < rightDuration) {
        return -1;
    } else if (leftDuration > rightDuration) {
        return 1;
    }

    if (left->pitch < right->pitch) {
        return -1;
    } else if (left->pitch > right->pitch) {
        return 1;
    }
    return 0;
}

#line 522 "src/sequence.in.c"

#define NoteSequence_isMarkerValue(v) (v < 0)
#define Sequence_minSequenceLength 5

APIF NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind)
{
    // XXX: I don't know if this should be a legal new! 
    NoteSequence *self    = NoteSequence_new();
    self->outletSpecifier = OutletSpecifier_makeNote(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv, Error *err)
{
    if (argc <= 0) {
        Error_format0(err, "Bad argc passed to newFromEvents");
        goto END;
    }

    NoteSequence *self = NoteSequence_newTrack(track, portFind);
    NoteEventAr_truncate(self->events, 0);
    for (int i = 0; i < argc; i++) {
        NoteEventAr_push(self->events, argv[i]);
    }
    NoteEventAr_sort(self->events);

    NoteEvent *last = NoteEventAr_get(self->events, NoteEventAr_len(self->events)-1, err);
    Error_returnNullOnError(err);

    if (last->duration != NoteSequence_cycleDuration) {
        Error_format0(err, "Called newFromEvents without proper cycle marker");
        goto END;
    }
    self->sequenceLength = last->stime;
    NoteSequence_makeConsistent(self, err);

  END:
    if (Error_iserror(err)) {
        NoteSequence_free(self);
        return NULL;
    }
    return self;
}

COVER static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOffEvent = Ticks_maxTime;
    int nremoves = 0;
    TimedOffAr_foreach(it, self->offs) {
        if (it.var->time > current) {
            self->nextOffEvent = it.var->time;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0, err);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(self->offs, 0, nremoves, err);
        Error_maypost(err);
    }
}

COVER static inline void NoteSequence_playEvents(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOnEvent = Ticks_maxTime;
    for (;;) {
        NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
            NoteEvent *ne = it.var;
            if (ne->stime + self->startTime > current) {
                self->nextOnEvent = ne->stime + self->startTime;
                return;
            }
            if (!NoteSequence_isMarkerValue(ne->duration)) {
                // Queue the note off
                TimedOff off = {.time = self->startTime + ne->stime + ne->duration, .pitch = ne->pitch};
                TimedOffAr_binInsertTime(self->offs, off);
                if (self->nextOffEvent > off.time) {
                    self->nextOffEvent = off.time;
                }

                // Play the note on
                Outlet_sendNote(self->outlet, ne->pitch, ne->velocity, err);
            } else if (ne->duration == NoteSequence_endgDuration && !self->cycle) {
                self->inEndgroup = true;
            } 

            if (self->recordingSeq != NULL && !NoteSequence_isMarkerValue(ne->duration)) {
                NoteEventAr_push(&self->recordingSeq->events, *ne);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= Sequence_minSequenceLength) {
               self->sequenceLength = Sequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            return;
        }
    }
}

COVER static inline Ticks NoteSequence_nextEvent(NoteSequence *self) {
    bool maxOff = self->nextOffEvent == Ticks_maxTime;
    bool maxOn  = self->nextOnEvent  == Ticks_maxTime;
    if (maxOff && maxOn) {
        return -1;
    } else if (maxOff) {
        return self->nextOnEvent;
    } else if (maxOn) {
        return self->nextOffEvent;
    } else {
        return self->nextOffEvent < self->nextOnEvent ? self->nextOffEvent : self->nextOnEvent;
    }
}

//
// time and seqTime are related by
//      seqTime = (time-sequenceStartTime) % sequenceLength
//      seqBase = sequenceLength * ((time - sequenceStartTime)/ sequenceLength) + sequenceStartTime
//      time    = seqTime + seqBase 
// Then write 
//      seqTime + seqBase = (time-sequenceStartTime) % sequenceLength + sequenceLength * ((time - sequenceStartTime)/ sequenceLength) + sequenceStartTime
//                        = (time-sequenceStartTime) + sequenceStartTime
//                        = time
// Where the last relation is due to the integer relation
//      n       = n % len + (n/len)*len

APIF void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) 
{
    int nevents = NoteEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        if (self->sequenceLength <= Sequence_minSequenceLength) {
            self->sequenceLength = Sequence_minSequenceLength;
        }
        while (current - self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        NoteEventAr_foreach(it, &self->events) {
            if (it.var->stime + self->startTime >= current) {
                nextEvent = it.var->stime + self->startTime;
                break;
            }
            self->cursor++;
        }
        if (self->cursor >= nevents) {
            Error_format0(err, "INTERNAL ERROR: cursor found to be >= nevents");
            return;
        }
    } else {
        NoteEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }
    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        NoteSequence *other = NoteSequence_castFromSequence(NoteSequence_compactNew(self, self->startTime));
        self->recordingSeq  = other; 
        RecordBuffer_push(recordBuffer, NoteSequence_castToSequence(other));
    }
    if (nextEvent != 0) {
        TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

APIF void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err) {
    self->cursor       = NoteEventAr_len(self->events);
    self->version++;

    if (self->recordingSeq != NULL) {
        // In the recording sequence Adjust the duration of all the pending note-offs
        TimedOffAr_foreach(offIt, self->offs) {
            NoteEventAr_rforeach(noteIt, self->recordingSeq->events) {
                if (noteIt.var->pitch == offIt.var->pitch) {
                    noteIt.var->duration = current - (self->startTime + noteIt.var->stime);
                    if (noteIt.var->duration <= 0) {
                        // Silently ignore this condition
                        NoteEventArRIt_remove(&noteIt);
                    }
                    break;
                }
            }
        } 
        self->recordingSeq = NULL;
    }
    
    NoteSequence_playNoteOffs(self, Ticks_maxTime, err);
}

APIF void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err) 
{
    NoteSequence_playNoteOffs(self, current, err);
    NoteSequence_playEvents(self, current, err);
    Ticks nextEvent = NoteSequence_nextEvent(self);
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

APIF void NoteSequence_padNoteOff(NoteSequence *self, Ticks current, Error *err) 
{
    if (self->inEndgroup && !self->cycle) {
        NoteSequence_stop(self, current, err);
    }
}

APIF void NoteSequence_makeConsistent(NoteSequence *self, Error *err)
{
    if (NoteEventAr_len(self->events) < 1) {
        Error_format0(err, "Called makeConsistent on empty sequence");
        return;
    }

    NoteEventAr_sort(self->events);

    NoteEvent last = NoteEventAr_get(self->events, NoteEventAr_len(self->events)-1, err);
    Error_returnVoidOnError(err);

    if (last->duration != NoteSequence_cycleDuration) {
        Error_format0(err, "Called makeConsistent without proper cycle marker");
        return;
    }

    if (last->stime != self->sequenceLength) {
        Error_format0(err, "Called cycle marker and sequenceLength are inconsistent");
        return;
    }

    int timeNextNoteStart[128] = {0};
    for (int i = 0; i < 128; i++) {
        timeNextNoteStart[i] = INT_MAX;
    }
    NoteEventAr_rforeach(it, self->events) {
        if (it.var->stime + it.var->duration > timeNextNoteStart[it.var->pitch]) {
            it.var->duration = timeNextNoteStart[it.var->pitch] - it.var->stime;
            if (it.var->duration <= 0) {
                // This is the case when the same note is played at the same time. Notice we
                NoteEventArRIt_remove(&it);
                continue;        
            }
        }
        timeNextNoteStart[it.var->pitch] = it.var->stime;
    }
    return;
}

APIF Sequence *NoteSequence_compactNew(NoteSequence *self, Ticks recordStart)
{
    NoteSequence *other    = NoteSequence_new();
    // WHen we create a compact sequence, we always set it's startTime to the recordStart which is <= than all the startTimes in the RecordBuffer
    other->startTime       = recordStart;
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = self->outlet;
    return NoteSequence_castToSequence(other);
}

APIF void NoteSequence_compactConcat(NoteSequence *self, Sequence *otherSeq, Error *err)
{
    NoteSequence *other = NoteSequence_castFromSequence(otherSeq);
    if (other == NULL) {
        Error_format(err, "NoteSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
        return;
    }
    NoteEventAr_foreach(it, other->events) {
        NoteEvent e = *it.var;
        if (NoteSequence_isMarkerValue(e.duration)) {
            continue;
        }
        // Rememver in RecordBuffer_compact we're gauranteed that self->startTime < other->startTime
        e.stime += (other->startTime - self->startTime);
        NoteEventAr_push(self->events, e); 
    }
}

APIF void NoteSequence_compactSortEvents(NoteSequence *self)
{
    NoteEventAr_sort(self->events);
}

// Return the time that endgroup should be inserted, or -1 if no endgroup applies.
// Note we return absolute time.
APIF Ticks NoteSequence_computeEndgroupTime(NoteSequence *self)
{
    // Endgroup is the 
    Ticks endgroupTime = -1;
    NoteEventAr_rforeach(it, self->events) {
        if (NoteSequence_isMarkerValue(it.var->duration)) {
            continue;
        }
        endgroupTime = self->startTime + it.var->stime;
        break;
    }
    return endgroupTime;
}

APIF Ticks NoteSequence_compactComputeSequenceLength(NoteSequence *self)
{
    Ticks lastTime = Sequence_minSequenceLength;
    NoteEventAr_rforeach(it, self->events) {
        if (NoteSequence_isMarkerValue(it.var->duration)) {
            continue;
        }
        Ticks end = it.var->stime + it.var->duration;
        if (end > lastTime) {
            lastTime = end;
        }
    }

    MusicalContext_declareDefault(musicalContext);
    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < Sequence_minSequenceLength) {
        seqLen = Sequence_minSequenceLength;
    }

    return seqLen;
}

APIF void NoteSequence_compactFinish(NoteSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
{
    if (endgroupTime >= 0) {
        int index = NoteEventAr_len(self->events) > 0 ? 0 : -1;
        NoteEventAr_rforeach(it, self->events) {
            if (NoteSequence_isMarkerValue(it.var->duration)) {
                continue;
            }
            if (self->startTime + it.var->stime < endgroupTime) {
                index = it.index + 1;
                break;
            }
        }
        if (index >= 0) {
            NoteEvent newEv = {.stime = endgroupTime, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
            NoteEventAr_insert(self->events, index, newEv, err);
            Error_returnVoidOnError(err);
        }
    }


    self->sequenceLength = sequenceLength;
    NoteEvent newEv = {.stime = sequenceLength, .duration = NoteSequence_cycleDuration, .pitch = 0, .velocity = 0};
    NoteEventAr_push(self->events, newEv);
    NoteSequence_makeConsistent(self, err);
    return;
}

#line 900 "src/sequence.in.c"

APIF int FloatEvent_cmp(FloatEvent *left, FloatEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    }
    return 0;
}

#line 964 "src/sequence.in.c"

APIF FloatSequence *FloatSequence_newCc(Symbol *track, int cc, PortFind *portFind) 
{
    FloatSequence *self   = FloatSequence_new();
    self->outletSpecifier = OutletSpecifier_makeCC(track, cc);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF FloatSequence *FloatSequence_newBend(Symbol *track, PortFind *portFind) 
{
    FloatSequence *self   = FloatSequence_new();
    self->outletSpecifier = OutletSpecifier_makeBend(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF FloatSequence *FloatSequence_newFromEvents(Symbol *track, int ccOrNegForBend, PortFind *portFind, int argc, FloatEvent *argv) 
{
    FloatSequence *self = NULL;
    if (ccOrNegForBend >= 0) {
        self = FloatSequence_newCc(track, ccOrNegForBend, portFind);
    } else {
        self = FloatSequence_newBend(track, portFind);
    }
    FloatEventAr_truncate(self->events);
    for (int i = 0; i < argc; i++) {
        FloatEventAr_push(self->events, argv[i]);
    }
    FloatSequence_makeConsistent(self);
    return self;
}


double FloatSequence_endgMarker  = -1.0e40;
double FloatSequence_cycleMarker = -1.0e41;
#define FloatSequence_isMarkerValue(v) (v < -1.0e10)

APIF void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) {
    int nevents = FloatEventAr_len(self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        if (self->sequenceLength <= Sequence_minSequenceLength) {
            self->sequenceLength = Sequence_minSequenceLength;
        }
        while (current-self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        FloatEventAr_foreach(it, self->events) {
            if (it.var->stime + self->startTime > current) {
                nextEvent = it.var->stime + self->startTime;
                break;
            }
            self->cursor++;
        }
        if (self->cursor >= nevents) {
            self->startTime += self->sequenceLength;
            nextEvent        = self->startTime;
            self->cursor     = 0;
        }
    } else {
        FloatEventAr_foreach(it, self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }

    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        FloatSequence *other = FloatSequence_castFromSequence(FloatSequence_compactNew(self, self->startTime));        
        self->recordingSeq  = other;    
        RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
}

APIF void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err) {
    Ticks nextEvent = -1;
    for (;;) {
        FloatEventAr_foreachOffset(it, self->events, self->cursor) {
            FloatEvent *fe = it.var;
            if (fe->stime + self->startTime > current) {
                nextEvent = fe->stime + self->startTime;
                goto DONE;
            }
            if (fe->value == FloatSequence_endgMarker) {
                self->inEndgroup = true;
            } else if (fe->value == FloatSequence_cycleMarker) {
                // Do nothing
            } else {
                Outlet_sendFloat(self->outlet, fe->value, err);
            }

            if (self->recordingSeq != NULL && !FloatSequence_isMarkerValue(fe->value)) {
                FloatEvent e = *fe;
                e.stime      = self->recordingSeq->startTime + fe->stime;
                FloatEventAr_push(self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= Sequence_minSequenceLength) {
                self->sequenceLength = Sequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            goto DONE;
        }
    }
   DONE:
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
    }
}

APIF void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err) {
    self->cursor       = FloatEventAr_len(self->events);
    self->version++;
    self->recordingSeq = NULL;
    Outlet_sendFloat(self->outlet, self->restoreValue, err);
}

APIF void FloatSequence_padNoteOff(FloatSequence *self, Ticks current, Error *err) {
    if (self->inEndgroup && !self->cycle) {
        FloatSequence_stop(self, current, err);
    }
}

APIF void FloatSequence_makeConsistent(FloatSequence *self)
{
    FloatEventAr_sort(self->events);
    double seen = -1;
    FloatEventAr_rforeach(it, self->events) {
        if (seen == it.var->stime) {
            FloatEventArRIt_remove(&it);
        }
        seen = it.var->stime;
    }
}

APIF Sequence *FloatSequence_compactNew(FloatSequence *self, Ticks recordStart)
{
    FloatSequence *other   = FloatSequence_new();
    other->startTime       = recordStart;
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = self->outlet;
    return FloatSequence_castToSequence(other);
}

APIF void FloatSequence_compactConcat(FloatSequence *self, Sequence *otherSeq, Error *err)
{
    FloatSequence *other = FloatSequence_castFromSequence(otherSeq);
    if (other == NULL) {
        Error_format(err, "FloatSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
        return;
    }
    FloatEventAr_foreach(it, other->events) {
        FloatEvent e = *it.var;
        if (FloatSequence_isMarkerValue(e.value)) {
            continue;
        }
        // Remember that self->startTime == recordStart
        e.stime += (other->startTime - self->startTime);
        FloatEventAr_push(self->events, e); 
    }
    return;
}

APIF void FloatSequence_compactSortEvents(FloatSequence *self)
{
    FloatSequence_makeConsistent(self);
}

APIF Ticks FloatSequence_compactComputeSequenceLength(FloatSequence *self)
{
    Ticks lastTime = -1;
    FloatEventAr_rforeach(it, self->events) {
        lastTime = it.var->stime;
        break;
    }

    MusicalContext_declareDefault(musicalContext);
    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < Sequence_minSequenceLength) {
        seqLen = Sequence_minSequenceLength;
    }
    return seqLen;
}

APIF void FloatSequence_compactFinish(FloatSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
{
    if (endgroupTime >= 0) {
        int index = FloatEventAr_len(self->events) > 0 ? 0 : -1;
        FloatEventAr_rforeach(it, self->events) {
            if (FloatSequence_isMarkerValue(it.var->value)) {
                continue;
            }
            if (self->startTime + it.var->stime < endgroupTime) {
                index = it.index + 1;
                break;
            }
        }
        if (index >= 0) {
            FloatEvent newEv = {.stime = endgroupTime, .value = FloatSequence_endgMarker};
            FloatEventAr_insert(self->events, index, newEv, err);
            Error_returnVoidOnError(err);
        }
    }

    self->sequenceLength = sequenceLength;
    FloatEvent newEv = {.stime = sequenceLength, .value = FloatSequence_cycleMarker};
    FloatEventAr_push(self->events, newEv);
    FloatSequence_makeConsistent(self);
    return;
}

#line 1312 "src/sequence.in.c"

// APIF void SequenceAr_truncateNoClear(SequenceAr *self) {
//     SequenceAr_foreach(it, self) {
//         *it.var = NULL;
//     }
//     SequenceAr_truncate(self);
// }

APIF void Sequence_freePpErrless(Sequence **s)
{
    Error_declare(err);
    Sequence_free(*s, err);
    Error_maypost(err);
}

// Sort into unique OutletSpecifiers, and sort by startTime within the same OutletSpecifier.
APIF int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq) 
{
    OutletSpecifier *left  = &leftSeq->outletSpecifier;
    OutletSpecifier *right = &rightSeq->outletSpecifier;
    int q = Symbol_cmp(OutletSpecifier_track(left), OutletSpecifier_track(right));
    if (q) {
        return q;
    }

    // Want to sort NoteSequence to the front of the array. We could do this by looking for *note in parameter name, but I like this better.
    bool noteLeft  = Interface_itype(leftSeq)  == NoteSequence_itype;
    bool noteRight = Interface_itype(rightSeq) == NoteSequence_itype;
    if (noteLeft && !noteRight) {
        return -1;
    } else if (!noteLeft && noteRight) {
        return 1;
    }
    
    int leftPi  = OutletSpecifier_pluginIndex(left);
    int rightPi = OutletSpecifier_pluginIndex(right);
    if (leftPi < rightPi) {
        return -1;
    } else if (leftPi > rightPi) {
        return 1;
    }

    q = Symbol_cmp(OutletSpecifier_parameter(left), OutletSpecifier_parameter(right));
    if (q) {
        return q;
    }    

    leftPi  = OutletSpecifier_paramIndex(left);
    rightPi = OutletSpecifier_paramIndex(right);
    if (leftPi < rightPi) {
        return -1;
    } else if (leftPi > rightPi) {
        return 1;
    }    

    return 0;
}

APIF int Sequence_cmpPointer(Sequence *leftSeq, Sequence *rightSeq) {
    if (leftSeq < rightSeq) {
        return -1;
    }  else if (leftSeq > rightSeq) {
        return 1;
    }

    return 0;
}

APIF int Sequence_cmpPp(Sequence **left, Sequence **right) {
    return Sequence_cmp(*left, *right);
}

APIF int Sequence_cmpPointerPp(Sequence **left, Sequence **right)
{
    return Sequence_cmpPointer(*left, *right);
}

APIF void Sequence_incVersion(Sequence *seq) {
    seq->version++;
}

#line 1415 "src/sequence.in.c"
APIF RecordBuffer *RecordBuffer_newStart(Ticks recordStart)
{
    RecordBuffer *self = RecordBuffer_new();
    self->recordStart = recordStart;
    return self;
}

APIF void RecordBuffer_push(RecordBuffer *self, Sequence *sequence)
{
    SequenceAr_push(&self->sequences, sequence);
}

APIF void RecordBuffer_compact(RecordBuffer *self, SequenceAr *output, Error *err)
{
    SequenceAr_sort(&self->sequences);
    SequenceAr_truncate(output);

    // Compact all the sequences we can
    Sequence *current = NULL;
    SequenceAr_foreach(it, &self->sequences) {
        if (current == NULL || Sequence_cmp(*it.var, current) != 0) {
            current = Sequence_compactNew(*it.var, self->recordStart, err);
            Error_gotoLabelOnError(err, END);
            SequenceAr_push(output, current);
        } 
        Sequence_compactConcat(current, *it.var, err);
        Error_gotoLabelOnError(err, END); 
    }

    Ticks sequenceLength = -1;
    SequenceAr_foreach(it, output) {
        Sequence *s = *it.var;
        Sequence_compactSortEvents(s, err);
        Error_gotoLabelOnError(err, END); 
        Ticks len = Sequence_compactComputeSequenceLength(s, err);
        Error_gotoLabelOnError(err, END);
        if (len > sequenceLength) {
            sequenceLength = len;
        }
    }

    // We assign the endgroup for a collection of sequences by looking at the first and only noteSequence for a given track. If no noteSequence
    // exists for this track, endgroup is unassigned.
    Ticks currentEndgroupTime = -1;
    Symbol *track = NULL;
    SequenceAr_foreach(it, output) {
        Sequence *s = *it.var;

        if (track != s->outletSpecifier.track) {
            track = s->outletSpecifier.track;
            NoteSequence *ns = NoteSequence_castFromSequence(s);
            if (ns == NULL) {
                currentEndgroupTime = -1;
            } else {
                currentEndgroupTime = NoteSequence_computeEndgroupTime(ns);
            }
        }
        Sequence_compactFinish(s, currentEndgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }

  END:
    if (Error_iserror(err)) {
        SequenceAr_truncate(output);
    }
    return;
}


enum {
    Midi_noteEventType   = 1,
    Midi_ccEventType     = 2,
    Midi_bendEventType   = 3,
    Midi_headerEventType = 4,
    Midi_eofEventType    = 5
};

typedef struct MidiEvent_t {
    int type;
    Ticks time;
    long arg1;
    long arg2;
} MidiEvent;

COVER MidiEvent Midi_getNextEvent(FILE *pipe, Error *err)
{
    static String *buffer       = NULL;
    static StringPtAr *arBuffer = NULL;
    if (buffer == NULL) {
        buffer   = String_empty();
        arBuffer = StringPtAr_new(0);
    }
    
    MidiEvent event = {0}, zero = {0};
    for (;;) {
        event      = zero;
        event.type = Midi_eofEventType;
        if (!String_readline(&buffer, pipe, err)) {
            return event;
        }

        String_split(buffer, ",", arBuffer);
        StringPtAr_foreach(it, arBuffer) {
            String_trim(it.var);
        }

        if (StringPtAr_len(arBuffer) < 3) {
            Error_format0(err, "Not enough fields in midicsv file");
            return event;
        }

        String *timeString = StringPtAr_get(arBuffer, 1, err);
        Error_returnValueOnError(err, event);
        event.time = String_toInteger(timeString, err);
        Error_returnValueOnError(err, event);

        String *type = StringPtAr_get(arBuffer, 2, err);
        Error_returnValueOnError(err, event);

        if (String_cequal(type, "Note_off_c") || String_cequal(type, "Note_on_c")) {
            event.type = Midi_noteEventType;
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Note_off/on_c");
                return event;
            }
        } else if (String_cequal(type, "Pitch_bend_c")) {
            event.type = Midi_bendEventType;
            if (StringPtAr_len(arBuffer) < 5) {
                Error_format0(err, "Bad Pitch_bend_c");
                return event;
            }
        } else if (String_cequal(type, "Control_c")) {
            event.type = Midi_ccEventType;
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Control_c");
                return event;
            }
        } else if (String_cequal(type, "Header")) {
            if (StringPtAr_len(arBuffer) < 6) {
                Error_format0(err, "Bad Control_c");
                return event;
            }
        } else {
            continue;
        }

        break;
    }
    
    String *arg1 = StringPtAr_get(arBuffer, 4, err);
    Error_returnValueOnError(err, event);
    event.arg1 = String_toInteger(arg1, err); 
    
    if (event.type != Midi_bendEventType) {
        String *arg2 = StringPtAr_get(arBuffer, 5, err);
        Error_returnValueOnError(err, event);
        event.arg2 = String_toInteger(arg2, err); 
    }

    return event;
}

APIF void Midi_fromfile(const char *midiFilePath, SequenceAr *output, Symbol *defaultTrack, PortFind *portFind, Error *err)
{
    static String *midiCsvExecPath = NULL;
    if (midiCsvExecPath == NULL) {
        midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
    }

    String *buffer = String_fmt("'%s' '%s'", midiCsvExecPath, midiFilePath);    
    FILE *pipe = popen(buffer, "r");
    if (pipe == NULL) {
        Error_format(err, "Failed to create pipe for command `%s`", midiCsvExecPath);
        return;
    }

    //
    // Loop and collect events. Write them into each sequence type
    //
    MusicalContext_declareDefault(musicalContext);
    float tickFactor = 1.0;
    NoteSequence *noteSeq   = NULL;
    FloatSequence *bendSeq   = NULL;
    FloatSequence *ccSeqs[128] = {NULL};
    for (;;) {
        MidiEvent ev = Midi_getNextEvent(pipe, err);
        Error_returnVoidOnError(err);

        if (ev.type == Midi_eofEventType) {
            break;
        }

        switch (ev.type) {
            case Midi_noteEventType: {
                if (noteSeq == NULL) {
                    noteSeq = NoteSequence_newTrack(defaultTrack, portFind);
                }
                if (ev.arg2 == 0) {
                    bool found = false;
                    NoteEventAr_rforeach(it, noteSeq->events) {
                        if (it.var->pitch == ev.arg1) {
                            if (it.var->duration != NoteSequence_noteOffDuration) {
                                Error_format(err, "Found unpaired note-off at %lld", ev.time);
                                goto END;
                            }
                            it.var->duration = ev.time-it.var->stime;
                            found            = true;
                            break;
                        }
                    }
                    if (!found) {
                        Error_format(err, "Failed to find paired note-on for note-off at %lld", ev.time);
                        goto END;
                    }
                } else {
                    NoteEvent newEv = {.pitch = ev.arg1, .velocity = ev.arg2, .stime = ev.time, .duration = NoteSequence_noteOffDuration};
                    NoteEventAr_push(noteSeq->events, newEv);
                }
                break;
            }
            case Midi_bendEventType: {
                if (bendSeq == NULL) {
                    bendSeq = FloatSequence_newBend(defaultTrack, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg1};
                FloatEventAr_push(bendSeq->events, newEv);
                break;
            }
            case Midi_ccEventType: {
                if (ccSeqs[ev.arg1] == NULL) {
                    ccSeqs[ev.arg1] = FloatSequence_newCc(defaultTrack, ev.arg1, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg2};
                FloatEventAr_push((ccSeqs[ev.arg1])->events, newEv);
                break;
            }
            case Midi_headerEventType: {
                long ppqn = ev.arg2;
                tickFactor = (float)(musicalContext.ticksPerQuarterNote)/(float)(ppqn);
                break;    
            }
        }
    }


    //
    // Try and compute endgroup
    //
    Ticks endgroupTime = -1;
    if (noteSeq != NULL) {
        endgroupTime = NoteSequence_computeEndgroupTime(noteSeq);  
    }

    //
    // Compute length
    //
    Ticks sequenceLength = -1;
    if (noteSeq != NULL) {
        sequenceLength = NoteSequence_compactComputeSequenceLength(noteSeq);
    }
    if (bendSeq != NULL) {
        Ticks len = FloatSequence_compactComputeSequenceLength(bendSeq);
        if (sequenceLength < len) {
            sequenceLength = len;
        }
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            Ticks len = FloatSequence_compactComputeSequenceLength(ccSeqs[i]);
            if (sequenceLength < len) {
                sequenceLength = len;
            }       
        }
    }

    //
    // Finish sequences off
    //
    if (noteSeq != NULL) {
        NoteSequence_compactFinish(noteSeq, endgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }
    if (bendSeq != NULL) {
        FloatSequence_compactFinish(bendSeq, endgroupTime, sequenceLength, err);
        Error_gotoLabelOnError(err, END);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatSequence_compactFinish(ccSeqs[i], endgroupTime, sequenceLength, err);
            Error_gotoLabelOnError(err, END);
        }
    }

  END:
    if (pipe != NULL) {
        pclose(pipe);
    }
    if (Error_iserror(err)) {
        if (noteSeq != NULL) {
            NoteSequence_free(noteSeq);
        }
        if (bendSeq != NULL) {
            FloatSequence_free(bendSeq);
        }
        for (int i = 0; i < 128; i++) {
            if (ccSeqs[i] != NULL) {
                FloatSequence_free(ccSeqs[i]);
            }
        }
        return;
    }

    //
    // Populate output array
    //
    SequenceAr_truncate(output);
    if (noteSeq != NULL) {
        SequenceAr_push(output, NoteSequence_castToSequence(noteSeq));
    }
    if (bendSeq != NULL) {
        SequenceAr_push(output, FloatSequence_castToSequence(bendSeq));
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            SequenceAr_push(output, FloatSequence_castToSequence(ccSeqs[i]));
        }
    }
    SequenceAr_sort(output);
}

//
//
//
/*
APIF void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn){
	Error_declare(err);
    int padIndex = Hub_padIndexFromInNote(hub, pitchIn);
    if (padIndex >= PadAr_len(PadList_pads(Hub_padList(hub)))) {
        post("Bad padIndex %d", padIndex);
        return;
    }

    if (velocityIn == 0) {
        Pad *pad = PadList_pad(Hub_padList(x), padIndex, err);
        if (Error_maypost(err)) {
            return;
        }
        Pad_setNoteReleasePending(pad, false);
        SequenceAr_foreach(it, Pad_sequenceList(pad)) {
        Sequence_padNoteOff(it.var);
    }
    return;
    }

    if (Hub_grabNextTappedPad(hub)) {
      Hub_setGrabNextTappedPad(hub, false); 
      Hub_changeSelectedPad(hub, padIndex, err);
      Error_maypost(err);
    }


    Ticks now = Ticks_now();
    Ticks clockStart = Pad_useMasterClock(pad) ? Hub_masterClock(hub) : now;
    SequenceAr_foreach(it, Pad_sequenceList(pad)) {
       SequenceAr_binInsertSeqPt(Hub_runningSequences(hub), it.var);
       Sequence_start(it.var, clockStart, now, Hub_queue(hub), Hub_recordBuffer(hub));
    }

    Error_clear(err);
}

APIF void Frontend_drive(Hub *hub) {
	Ticks now = Ticks_now();
	TimedPq *queue = Hub_queue(hub);
	Sequence *seq = TimedPq_dequeue(queue);
	while (seq != NULL) {
		Sequence_drive(seq, now, queue);
		seq = TimedPq_dequeue(queue);
	}
}

APIF void Frontend_stop(Hub *hub) {
	SequenceAr_foreach(it, Hub_runningSequences(hub)) {
		Sequence_stop(it.var);
	}
}
*/
void PooledType_init() {
   for (int i = 0; i < NoteEvent_poolSize; i++) {
       NoteEvent *self = NoteEvent_new();
       NoteEvent_decRef(self);
   }
}
#line 1 "**coverage**" 
void Coverage_initialize()
{
   Coverage_array = Mem_calloc(sizeof(const char *) * 0);   
}

void Coverage_finalize(const char *file)
{
   String *coverFile = Coverage_createCoverageFile(file);
   FILE *out = fopen(coverFile, "w");
   if (!out) {
       Error_declare(err);
       Error_format(err, "Failed to open coverage file %s", coverFile);
       Error_maypost(err);
       exit(1);
   }
   fprintf(out, "*totalSize %d\n", 0);
   for (int i = 0; i < 0; i++) {
       if (Coverage_array[i] != NULL) {
           fprintf(out, "%s\n", Coverage_array[i]);
       }
   }
   fclose(out);
   String_free(coverFile);
}
