// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
// *** DO NOT MODIFY THIS FILE generated 04/11/2018 16:42:56 ***
struct Arguments_t;
typedef struct Arguments_t Arguments;
struct AtomAr_t;
typedef struct AtomAr_t AtomAr;
struct AtomArAr_t;
typedef struct AtomArAr_t AtomArAr;
struct BendOutlet_t;
typedef struct BendOutlet_t BendOutlet;
struct BinFile_t;
typedef struct BinFile_t BinFile;
struct BinFilePayload_t;
typedef struct BinFilePayload_t BinFilePayload;
struct CcOutlet_t;
typedef struct CcOutlet_t CcOutlet;
typedef struct Dispatch_t DecrementFrameDispatch;
struct Dispatch_t;
typedef struct Dispatch_t Dispatch;
struct DispatchPtAr_t;
typedef struct DispatchPtAr_t DispatchPtAr;
struct DropDown_t;
typedef struct DropDown_t DropDown;
struct FloatEvent_t;
typedef struct FloatEvent_t FloatEvent;
struct FloatEventAr_t;
typedef struct FloatEventAr_t FloatEventAr;
struct FloatSequence_t;
typedef struct FloatSequence_t FloatSequence;
struct Foo_t;
typedef struct Foo_t Foo;
struct FooArr_t;
typedef struct FooArr_t FooArr;
struct Hub_t;
typedef struct Hub_t Hub;
typedef struct Dispatch_t IncrementFrameDispatch;
struct IndexedOff_t;
typedef struct IndexedOff_t IndexedOff;
struct IndexedOffAr_t;
typedef struct IndexedOffAr_t IndexedOffAr;
struct IntAr_t;
typedef struct IntAr_t IntAr;
struct IntArr_t;
typedef struct IntArr_t IntArr;
struct MEventAr_t;
typedef struct MEventAr_t MEventAr;
typedef struct Dispatch_t ManageChokeGroupsDispatch;
struct Marshal_t;
typedef struct Marshal_t Marshal;
typedef struct Marshal_t MarshalSi;
typedef struct Marshal_t MarshalSii;
typedef struct Marshal_t MarshalSs;
typedef struct Dispatch_t MidiFileDropDispatch;
struct Midiseq_t;
typedef struct Midiseq_t Midiseq;
struct MusicalContext_t;
typedef struct MusicalContext_t MusicalContext;
struct NoteEvent_t;
typedef struct NoteEvent_t NoteEvent;
struct NoteEventAr_t;
typedef struct NoteEventAr_t NoteEventAr;
struct NoteManager_t;
typedef struct NoteManager_t NoteManager;
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
struct PadList_t;
typedef struct PadList_t PadList;
struct PadPtrAr_t;
typedef struct PadPtrAr_t PadPtrAr;
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
struct PtrAr_t;
typedef struct PtrAr_t PtrAr;
struct RecordBuffer_t;
typedef struct RecordBuffer_t RecordBuffer;
typedef struct Dispatch_t SelectNextPushedPadDispatch;
struct Sequence_t;
typedef struct Sequence_t Sequence;
struct SequenceAr_t;
typedef struct SequenceAr_t SequenceAr;
struct StringPtAr_t;
typedef struct StringPtAr_t StringPtAr;
struct SymbolPtAr_t;
typedef struct SymbolPtAr_t SymbolPtAr;
struct SymbolPtrAr_t;
typedef struct SymbolPtrAr_t SymbolPtrAr;
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
struct TrackList_t;
typedef struct TrackList_t TrackList;
struct VstOutlet_t;
typedef struct VstOutlet_t VstOutlet;
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
   Array *arr = (Array*)Mem_calloc(sizeof(Array));
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
      arr->data = (char*)Mem_calloc(nelems*elemSize); 
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
        int oldCap        = arr->cap;
        arr->cap          = szBytes/arr->elemSize;
        arr->data         = (char*)Mem_realloc(arr->data, szBytes);
        memset(arr->data + oldCap*arr->elemSize, 0, (arr->cap-oldCap)*arr->elemSize);
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

typedef int (*Array_compare)(const char *left, const char *right);

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

char *Array_binSearch(Array *arr, char *elem, Array_compare comparer, ArrayFIt *iterator) {
   int insert = -1;
   char *lower = NULL;
   char *upper = NULL;
   int index  = Array_binSearchWithInsertMulti(arr, elem, &insert, comparer, &lower, &upper);
   if (index < 0) {
      return NULL;
   }
   if (iterator != NULL) {
      iterator->arr    = arr;
      iterator->lBound = (int)((lower - arr->data)/arr->elemSize);
      iterator->uBound = (int)((upper - arr->data)/arr->elemSize);
      iterator->index  = iterator->lBound-1;
      iterator->var    = NULL;
   }

   return lower;
}

//
// Priority queue. This code is ported from https://golang.org/src/container/heap/heap.go
//

#define PQ_LESS(i, j) ((comparer(arr->data + arr->elemSize*i, arr->data + arr->elemSize*j)) < 0)
#define PQ_SWAP(i, j) do {\
    memmove(arr->data + arr->elemSize*arr->len, arr->data + arr->elemSize*i,        arr->elemSize);\
    memmove(arr->data + arr->elemSize*i,        arr->data + arr->elemSize*j,        arr->elemSize);\
    memmove(arr->data + arr->elemSize*j,        arr->data + arr->elemSize*arr->len, arr->elemSize);\
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

void Array_pqUp(Array *arr, int j, int (*comparer)(const char *, const char*)) 
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
bool Array_pqDown(Array *arr, int i0, int n, int (*comparer)(const char *, const char *)) {
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

void Array_pqSort(Array *arr, int (*comparer)(const char *, const char*)) 
{
    int n = Array_len(arr);
    for (int i = n/2-1; i >= 0; i--) {
        Array_pqDown(arr, i, n, comparer);
    }
}

/*
func Push(h Interface, x interface{}) {
   h.Push(x)
   up(h, h.Len()-1)
}
*/

void Array_pqPush(Array *arr, char *elem, int (*comparer)(const char *, const char*))
{
   char *dst = Array_pushN(arr, 1);
   memmove(dst, elem, arr->elemSize);
   Array_pqUp(arr, Array_len(arr)-1, comparer);
}

/*
func Pop(h Interface) interface{} {
   n := h.Len() - 1
   h.Swap(0, n)
   down(h, 0, n)
   return h.Pop()
}
*/

bool Array_pqPop(Array *arr, char *elem, int (*comparer)(const char *, const char*)) 
{
    if (Array_len(arr) <= 0) {
        return false;
    }

    if (elem != NULL) {
        memmove(elem, arr->data, arr->elemSize);
    } else if (arr->clearer != NULL) {
        arr->clearer(arr->data);
    }

    int n = Array_len(arr)-1;
    PQ_SWAP(0, n);
    Array_pqDown(arr, 0, n, comparer);
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
typedef struct AtomAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Atom*);
   Atom *data;
} AtomAr;

typedef struct AtomArFIt_t {
   AtomAr *arr;
   int lBound;
   int uBound;

   int index;
   Atom *var;
} AtomArFIt;

typedef struct AtomArRIt_t {
   AtomAr *arr;
   int lBound;
   int uBound;

   int index;
   Atom *var;
} AtomArRIt;

struct VstOutlet_t
{
    int itype;
    AtomAr atoms;
    Port *port;
};
struct Track_t
{
    Symbol *name;
    NoteManager *noteManager;
};
typedef struct TrackAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Track*);
   Track *data;
} TrackAr;

typedef struct TrackArFIt_t {
   TrackAr *arr;
   int lBound;
   int uBound;

   int index;
   Track *var;
} TrackArFIt;

typedef struct TrackArRIt_t {
   TrackAr *arr;
   int lBound;
   int uBound;

   int index;
   Track *var;
} TrackArRIt;

struct TrackList_t
{
    TrackAr list;
};
struct Timed_t
{
    Ticks time;
    int version;
    Sequence *sequence;
};
typedef struct TimedPq_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Timed*);
   Timed *data;
} TimedPq;

typedef struct TimedPqFIt_t {
   TimedPq *arr;
   int lBound;
   int uBound;

   int index;
   Timed *var;
} TimedPqFIt;

typedef struct TimedPqRIt_t {
   TimedPq *arr;
   int lBound;
   int uBound;

   int index;
   Timed *var;
} TimedPqRIt;

struct TimedOff_t
{
    Ticks time;
    int pitch;
};
typedef struct TimedOffAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(TimedOff*);
   TimedOff *data;
} TimedOffAr;

typedef struct TimedOffArFIt_t {
   TimedOffAr *arr;
   int lBound;
   int uBound;

   int index;
   TimedOff *var;
} TimedOffArFIt;

typedef struct TimedOffArRIt_t {
   TimedOffAr *arr;
   int lBound;
   int uBound;

   int index;
   TimedOff *var;
} TimedOffArRIt;

typedef struct SymbolPtrAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Symbol **);
   Symbol **data;
} SymbolPtrAr;

typedef struct SymbolPtrArFIt_t {
   SymbolPtrAr *arr;
   int lBound;
   int uBound;

   int index;
   Symbol **var;
} SymbolPtrArFIt;

typedef struct SymbolPtrArRIt_t {
   SymbolPtrAr *arr;
   int lBound;
   int uBound;

   int index;
   Symbol **var;
} SymbolPtrArRIt;

typedef struct SymbolPtAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Symbol **);
   Symbol **data;
} SymbolPtAr;

typedef struct SymbolPtArFIt_t {
   SymbolPtAr *arr;
   int lBound;
   int uBound;

   int index;
   Symbol **var;
} SymbolPtArFIt;

typedef struct SymbolPtArRIt_t {
   SymbolPtAr *arr;
   int lBound;
   int uBound;

   int index;
   Symbol **var;
} SymbolPtArRIt;

typedef struct StringPtAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(String **);
   String **data;
} StringPtAr;

typedef struct StringPtArFIt_t {
   StringPtAr *arr;
   int lBound;
   int uBound;

   int index;
   String **var;
} StringPtArFIt;

typedef struct StringPtArRIt_t {
   StringPtAr *arr;
   int lBound;
   int uBound;

   int index;
   String **var;
} StringPtArRIt;

typedef struct SequenceAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Sequence **);
   Sequence **data;
} SequenceAr;

typedef struct SequenceArFIt_t {
   SequenceAr *arr;
   int lBound;
   int uBound;

   int index;
   Sequence **var;
} SequenceArFIt;

typedef struct SequenceArRIt_t {
   SequenceAr *arr;
   int lBound;
   int uBound;

   int index;
   Sequence **var;
} SequenceArRIt;

struct Sequence_t
{
    int itype;
    long version;
};
struct SelectNextPushedPadDispatch_t
{
    int itype;
};
struct RecordBuffer_t
{
    Ticks recordStart;
    SequenceAr sequences;
};
typedef struct PtrAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(void **);
   void **data;
} PtrAr;

typedef struct PtrArFIt_t {
   PtrAr *arr;
   int lBound;
   int uBound;

   int index;
   void **var;
} PtrArFIt;

typedef struct PtrArRIt_t {
   PtrAr *arr;
   int lBound;
   int uBound;

   int index;
   void **var;
} PtrArRIt;

struct PortRef_t
{
    Port *port;
    int outlet;
};
struct PortFindCell_t
{
    Port *reciever;
    Symbol *varname;
};
typedef struct PortFindCellAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(PortFindCell*);
   PortFindCell *data;
} PortFindCellAr;

typedef struct PortFindCellArFIt_t {
   PortFindCellAr *arr;
   int lBound;
   int uBound;

   int index;
   PortFindCell *var;
} PortFindCellArFIt;

typedef struct PortFindCellArRIt_t {
   PortFindCellAr *arr;
   int lBound;
   int uBound;

   int index;
   PortFindCell *var;
} PortFindCellArRIt;

struct PortFind_t
{
    PortFindCellAr objects;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct Port_t
{
    MaxObject obj;
    long inletnum;
    PtrAr proxy;
    PtrAr outlet;
    Symbol *track;
    Symbol *id;
    long intInlets;
    long intOutlets;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
typedef struct PadPtrAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Pad **);
   Pad **data;
} PadPtrAr;

typedef struct PadPtrArFIt_t {
   PadPtrAr *arr;
   int lBound;
   int uBound;

   int index;
   Pad **var;
} PadPtrArFIt;

typedef struct PadPtrArRIt_t {
   PadPtrAr *arr;
   int lBound;
   int uBound;

   int index;
   Pad **var;
} PadPtrArRIt;

struct Pad_t
{
    Symbol *trackName;
    int padIndex;
    Midiseq *sequence;
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
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Pad*);
   Pad *data;
} PadAr;

typedef struct PadArFIt_t {
   PadAr *arr;
   int lBound;
   int uBound;

   int index;
   Pad *var;
} PadArFIt;

typedef struct PadArRIt_t {
   PadAr *arr;
   int lBound;
   int uBound;

   int index;
   Pad *var;
} PadArRIt;

struct PadList_t
{
    PadAr pads;
    PadPtrAr running;
};
struct OutletSpecifier_t
{
    Symbol *track;
    int pluginIndex;
    Symbol *parameter;
    int paramIndex;
};
struct Outlet_t
{
    int itype;
};
struct NullOutlet_t
{
    int itype;
    int unused;
};
struct NoteEvent_t
{
    uint8_t pitch;
    uint8_t velocity;
    Ticks stime;
    Ticks duration;
};
typedef struct NoteEventAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(NoteEvent*);
   NoteEvent *data;
} NoteEventAr;

typedef struct NoteEventArFIt_t {
   NoteEventAr *arr;
   int lBound;
   int uBound;

   int index;
   NoteEvent *var;
} NoteEventArFIt;

typedef struct NoteEventArRIt_t {
   NoteEventAr *arr;
   int lBound;
   int uBound;

   int index;
   NoteEvent *var;
} NoteEventArRIt;

struct NoteSequence_t
{
    int itype;
    long version;
    Ticks startTime;
    Ticks sequenceLength;
    OutletSpecifier outletSpecifier;
    int cursor;
    bool cycle;
    Ticks nextOffEvent;
    Ticks nextOnEvent;
    bool inEndgroup;
    Outlet *outlet;
    NoteSequence *recordingSeq;
    TimedOffAr offs;
    NoteEventAr events;
};
struct NoteOutlet_t
{
    int itype;
    AtomAr atoms;
    Port *port;
};
struct IndexedOff_t
{
    int padIndex;
    int pitch;
};
typedef struct IndexedOffAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(IndexedOff*);
   IndexedOff *data;
} IndexedOffAr;

typedef struct IndexedOffArFIt_t {
   IndexedOffAr *arr;
   int lBound;
   int uBound;

   int index;
   IndexedOff *var;
} IndexedOffArFIt;

typedef struct IndexedOffArRIt_t {
   IndexedOffAr *arr;
   int lBound;
   int uBound;

   int index;
   IndexedOff *var;
} IndexedOffArRIt;

struct NoteManager_t
{
    TimedOffAr pending;
    IndexedOffAr endgroups;
    Port *output;
    Atom *atoms;
};
struct MusicalContext_t
{
    Ticks ticksPerQuarterNote;
    Ticks quarterNotesPerMeasure;
};
typedef struct MEventAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(MEvent*);
   MEvent *data;
} MEventAr;

typedef struct MEventArFIt_t {
   MEventAr *arr;
   int lBound;
   int uBound;

   int index;
   MEvent *var;
} MEventArFIt;

typedef struct MEventArRIt_t {
   MEventAr *arr;
   int lBound;
   int uBound;

   int index;
   MEvent *var;
} MEventArRIt;

struct Midiseq_t
{
    bool useMasterClock;
    Ticks sequenceLength;
    MEventAr events;
    Ticks startTime;
    int ptr;
};
struct MidiFileDropDispatch_t
{
    int itype;
};
struct MarshalSs_t
{
    int itype;
};
struct MarshalSii_t
{
    int itype;
};
struct MarshalSi_t
{
    int itype;
};
struct Marshal_t
{
    int itype;
};
struct ManageChokeGroupsDispatch_t
{
    int itype;
};
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

typedef struct IntAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(int*);
   int *data;
} IntAr;

typedef struct IntArFIt_t {
   IntAr *arr;
   int lBound;
   int uBound;

   int index;
   int *var;
} IntArFIt;

typedef struct IntArRIt_t {
   IntAr *arr;
   int lBound;
   int uBound;

   int index;
   int *var;
} IntArRIt;

struct IncrementFrameDispatch_t
{
    int itype;
};
typedef struct DispatchPtAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(Dispatch **);
   Dispatch **data;
} DispatchPtAr;

typedef struct DispatchPtArFIt_t {
   DispatchPtAr *arr;
   int lBound;
   int uBound;

   int index;
   Dispatch **var;
} DispatchPtArFIt;

typedef struct DispatchPtArRIt_t {
   DispatchPtAr *arr;
   int lBound;
   int uBound;

   int index;
   Dispatch **var;
} DispatchPtArRIt;

struct Arguments_t
{
    Symbol *s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
};
struct DropDown_t
{
    SymbolPtrAr table;
    int selected;
    PortRef portRef;
};
struct Hub_t
{
    PadList *padList;
    TrackList *trackList;
    Port *currBankPort;
    Port *currFramePort;
    Port *selBankPort;
    Port *selFramePort;
    Port *selPadPort;
    Port *chokeGroupPort;
    DropDown cgLocalGlobalMenu;
    DropDown cgInstrumentMenu;
    DropDown cgIndexMenu;
    int bank;
    int frame;
    bool grabNextTappedPad;
    int selectedPad;
    Arguments arguments;
    DispatchPtAr dispatcher;
    Ticks masterClock;
};
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

struct FloatEvent_t
{
    Ticks stime;
    double value;
};
typedef struct FloatEventAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(FloatEvent*);
   FloatEvent *data;
} FloatEventAr;

typedef struct FloatEventArFIt_t {
   FloatEventAr *arr;
   int lBound;
   int uBound;

   int index;
   FloatEvent *var;
} FloatEventArFIt;

typedef struct FloatEventArRIt_t {
   FloatEventAr *arr;
   int lBound;
   int uBound;

   int index;
   FloatEvent *var;
} FloatEventArRIt;

struct FloatSequence_t
{
    int itype;
    long version;
    Ticks startTime;
    Ticks sequenceLength;
    OutletSpecifier outletSpecifier;
    int cursor;
    bool cycle;
    bool inEndgroup;
    Outlet *outlet;
    FloatSequence *recordingSeq;
    FloatEventAr events;
    double restoreValue;
};
struct Dispatch_t
{
    int itype;
    Symbol *selector;
    Symbol *portId;
    int inlet;
    Marshal *marshal;
};
struct DecrementFrameDispatch_t
{
    int itype;
};
struct CcOutlet_t
{
    int itype;
    int cc;
    AtomAr atoms;
    Port *port;
};
struct BinFilePayload_t
{
    PortFind *portFind;
};
struct BinFile_t
{
    int version;
    String *filename;
    String *buffer;
    FILE *stream;
    BinFilePayload *payload;
};
struct BendOutlet_t
{
    int itype;
    AtomAr atoms;
    Port *port;
};
typedef struct AtomArAr_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(AtomAr*);
   AtomAr *data;
} AtomArAr;

typedef struct AtomArArFIt_t {
   AtomArAr *arr;
   int lBound;
   int uBound;

   int index;
   AtomAr *var;
} AtomArArFIt;

typedef struct AtomArArRIt_t {
   AtomArAr *arr;
   int lBound;
   int uBound;

   int index;
   AtomAr *var;
} AtomArArRIt;

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
void ManageChokeGroupsDispatch_initDispatchPtAr(int itype, DispatchPtAr *disPtAr, Error *ignored);
void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err);
int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp);
void Dispatch_freeDefault(Dispatch *d);
void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr, Error *err);
void DispatchPtAr_populate(DispatchPtAr *self, Error *err);
void String_split(String *src, const char *delim, StringPtAr *stringPtAr);
int Symbol_cmpUnderlying(Symbol **left, Symbol **right);
Port *Port_new();
void Port_init(Port *p);
void Port_free(Port *p);
void Port_clear(Port *p);
int port_parseEvSymbol(Symbol *id);
void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err);
void Port_sendInteger(Port *self, int outlet, long value);
static inline Symbol *PortRef_track(PortRef *self);
int PortRef_cmp(PortRef *left, PortRef *right);
void DropDown_build(DropDown *dd, const char **table, PortRef *pr);
void DropDown_buildCGLocalGlobal(DropDown *dd, PortRef *pr);
void DropDown_buildCGInstrument(DropDown *dd, PortRef *pr);
void DropDown_buildCGIndex(DropDown *dd, PortRef *pr);
void DropDown_updateSelected(DropDown *dd, Error *err);
void DropDown_setSelected(DropDown *dd, int selected, Error *err);
void DropDown_initializeMenu(DropDown *dd, Error *err);
int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line);
void Midiseq_userInit(Midiseq *self);
void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err);
void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_newNote(int pitch);
int Midiseq_len(Midiseq *mseq);
void Midiseq_push(Midiseq *mseq, MEvent cell);
MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err);
void Midiseq_setMidicsvExecPath();
void Midiseq_dblog(Midiseq *mseq);
int midiseq_tokenize(FILE *fd, StringPtAr **ret, Error *err);
int Midiseq_assignLength(Midiseq *mseq);
int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err);
void Midiseq_insertEndgroup(Midiseq *mseq, Error *err);
int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void Midiseq_stop(Midiseq *mseq);
int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err);
int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err);
Midiseq *Midiseq_fromfile(const char *fullpath, Error *err);
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
void Pad_setSequence(Pad *pad, Midiseq *midi);
void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err);
Pad *Pad_fromBinFile(BinFile *bf, Error *err);
void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err);
void Pad_computeChokeGroup(Pad *pad);
PadList *PadList_newN(int npads);
void PadList_play(PadList *self, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *self, int padIndex, bool pending, Error *err);
Pad *PadList_pad(PadList *pl, int index, Error *err);
void PadList_assignTrack(PadList *pl, TrackList *tl);
void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err);
PadList *PadList_fromBinFile(BinFile *bf, Error *err);
void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err);
TrackList *TrackList_newBuild(PortFind *pf);
void TrackList_build(TrackList *tl, PortFind *pf);
Track *TrackList_findTrackByName(TrackList *tl, Symbol *name);
int TrackList_count(TrackList *tl);
Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);
int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right);
int TimedOff_cmpTime(TimedOff *left, TimedOff *right);
NoteManager *NoteManager_newFromPort(Port *port);
void NoteManager_userInit(NoteManager *self);
void NoteManager_userClear(NoteManager *self);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_allOff(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);
Hub *Hub_newBuild(PortFind *pf, Error *err);
void Hub_build(Hub *hub, PortFind *pf, Error *err);
void Hub_updateGuiCurrentCoordinates(Hub *hub);
void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err);
void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv);
void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);
BinFile *BinFile_newWriter(const char *file, Error *err);
BinFile *BinFile_newReader(const char *file, Error *err);
void BinFile_userClear(BinFile *bf);
int binFile_hexDigitToInt(char hex);
char binFile_intToHexDigit(int digit);
off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err);
void BinFile_writeFlags(BinFile *bf, long flags, Error *err);
void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err);
void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err);
long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err);
off_t BinFile_tell(BinFile *bf, Error *err);
void BinFile_fillBuffer(BinFile *bf, long size, Error *err);
void BinFile_writeInteger(BinFile *bf, long value, Error *err);
long BinFile_readInteger(BinFile *bf, Error *err);
void BinFile_writeString(BinFile *bf, String *value, Error *err);
String *BinFile_readString(BinFile *bf, Error *err);
void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err);
Symbol *BinFile_readSymbol(BinFile *bf, Error *err);
void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err);
Ticks BinFile_readTicks(BinFile *bf, Error *err);
void BinFile_writeBool(BinFile *bf, bool value, Error *err);
bool BinFile_readBool(BinFile *bf, Error *err);
void BinFile_writeTag(BinFile *bf, const char *tag, Error *err);
void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err);
void NoteOutlet_dbRewindSent();
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
int NoteEvent_cmp(NoteEvent *left, NoteEvent *right);
NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind);
NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv);
void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err);
void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err);
void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err);
void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current, Error *err);
OutletSpecifier *NoteSequence_outSpec(NoteSequence *self);
NoteSequence *NoteSequence_recordClone(NoteSequence *self);
void NoteSequence_makeConsistent(NoteSequence *self);
int FloatEvent_cmp(FloatEvent *left, FloatEvent *right);
FloatSequence *FloatSequence_newCc(Symbol *track, int cc, PortFind *portFind);
FloatSequence *FloatSequence_newBend(Symbol *track, PortFind *portFind);
FloatSequence *FloatSequence_newFromEvents(Symbol *track, int ccOrNegForBend, PortFind *portFind, int argc, FloatEvent *argv);
void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err);
void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err);
void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err);
void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current, Error *err);
OutletSpecifier *FloatSequence_outSpec(FloatSequence *self);
FloatSequence *FloatSequence_recordClone(FloatSequence *self);
void FloatSequence_makeConsistent(FloatSequence *self);
void Sequence_freePpErrless(Sequence **s);
int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq);
int Sequence_cmpPointer(Sequence *leftSeq, Sequence *rightSeq);
int Sequence_cmpPp(Sequence **left, Sequence **right);
int Sequence_cmpPointerPp(Sequence **left, Sequence **right);
void Sequence_incVersion(Sequence *seq);
void RecordBuffer_push(RecordBuffer *self, Sequence *sequence);
void Midi_fromfile(const char *midiFilePath, SequenceAr *output, Symbol *defaultTrack, PortFind *portFind, Error *err);
void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn);
void Frontend_drive(Hub *hub);
void Frontend_stop(Hub *hub);
void Foo_recorder(Foo *self);
int Foo_cmp(Foo *left, Foo *right);
int Foo_cmpBoth(Foo *left, Foo *right);
Port *Port_newTrackId(Symbol *track, Symbol *id);
void Port_free(Port *self);
PortFind *PortFind_newFromTable(int argc, PortFindCell *cells);
PortFind *PortFind_createStandardSpoof();
void PortFind_userClear(PortFind *self);
void Arguments_clear(Arguments *self);
void Arguments_free(Arguments *self);
void Arguments_init(Arguments *self);
Arguments *Arguments_new();
void BendOutlet_clear(BendOutlet *self);
void BendOutlet_free(BendOutlet *self);
void BendOutlet_init(BendOutlet *self);
BendOutlet *BendOutlet_new();
void BinFile_clear(BinFile *self);
void BinFile_free(BinFile *self);
void BinFile_init(BinFile *self);
BinFile *BinFile_new();
void BinFilePayload_clear(BinFilePayload *self);
void BinFilePayload_free(BinFilePayload *self);
void BinFilePayload_init(BinFilePayload *self);
BinFilePayload *BinFilePayload_new();
void CcOutlet_clear(CcOutlet *self);
void CcOutlet_free(CcOutlet *self);
void CcOutlet_init(CcOutlet *self);
CcOutlet *CcOutlet_new();
void DecrementFrameDispatch_clear(DecrementFrameDispatch *self);
void DecrementFrameDispatch_free(DecrementFrameDispatch *self);
void DecrementFrameDispatch_init(DecrementFrameDispatch *self);
DecrementFrameDispatch *DecrementFrameDispatch_new();
void DropDown_clear(DropDown *self);
void DropDown_free(DropDown *self);
void DropDown_init(DropDown *self);
DropDown *DropDown_new();
void FloatEvent_clear(FloatEvent *self);
void FloatEvent_free(FloatEvent *self);
void FloatEvent_init(FloatEvent *self);
FloatEvent *FloatEvent_new();
void FloatSequence_clear(FloatSequence *self);
void FloatSequence_free(FloatSequence *self);
void FloatSequence_init(FloatSequence *self);
FloatSequence *FloatSequence_new();
void Foo_clear(Foo *self);
void Foo_free(Foo *self);
void Foo_init(Foo *self);
Foo *Foo_new();
void Hub_clear(Hub *self);
void Hub_free(Hub *self);
void Hub_init(Hub *self);
Hub *Hub_new();
void IncrementFrameDispatch_clear(IncrementFrameDispatch *self);
void IncrementFrameDispatch_free(IncrementFrameDispatch *self);
void IncrementFrameDispatch_init(IncrementFrameDispatch *self);
IncrementFrameDispatch *IncrementFrameDispatch_new();
void IndexedOff_clear(IndexedOff *self);
void IndexedOff_free(IndexedOff *self);
void IndexedOff_init(IndexedOff *self);
IndexedOff *IndexedOff_new();
void ManageChokeGroupsDispatch_clear(ManageChokeGroupsDispatch *self);
void ManageChokeGroupsDispatch_free(ManageChokeGroupsDispatch *self);
void ManageChokeGroupsDispatch_init(ManageChokeGroupsDispatch *self);
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_new();
void MarshalSi_clear(MarshalSi *self);
void MarshalSi_free(MarshalSi *self);
void MarshalSi_init(MarshalSi *self);
MarshalSi *MarshalSi_new();
void MarshalSii_clear(MarshalSii *self);
void MarshalSii_free(MarshalSii *self);
void MarshalSii_init(MarshalSii *self);
MarshalSii *MarshalSii_new();
void MarshalSs_clear(MarshalSs *self);
void MarshalSs_free(MarshalSs *self);
void MarshalSs_init(MarshalSs *self);
MarshalSs *MarshalSs_new();
void MidiFileDropDispatch_clear(MidiFileDropDispatch *self);
void MidiFileDropDispatch_free(MidiFileDropDispatch *self);
void MidiFileDropDispatch_init(MidiFileDropDispatch *self);
MidiFileDropDispatch *MidiFileDropDispatch_new();
void Midiseq_clear(Midiseq *self);
void Midiseq_free(Midiseq *self);
void Midiseq_init(Midiseq *self);
Midiseq *Midiseq_new();
void MusicalContext_clear(MusicalContext *self);
void MusicalContext_free(MusicalContext *self);
void MusicalContext_init(MusicalContext *self);
MusicalContext *MusicalContext_new();
void NoteEvent_clear(NoteEvent *self);
void NoteEvent_free(NoteEvent *self);
void NoteEvent_init(NoteEvent *self);
NoteEvent *NoteEvent_new();
void NoteManager_clear(NoteManager *self);
void NoteManager_free(NoteManager *self);
void NoteManager_init(NoteManager *self);
NoteManager *NoteManager_new();
void NoteOutlet_clear(NoteOutlet *self);
void NoteOutlet_free(NoteOutlet *self);
void NoteOutlet_init(NoteOutlet *self);
NoteOutlet *NoteOutlet_new();
void NoteSequence_clear(NoteSequence *self);
void NoteSequence_free(NoteSequence *self);
void NoteSequence_init(NoteSequence *self);
NoteSequence *NoteSequence_new();
void NullOutlet_clear(NullOutlet *self);
void NullOutlet_free(NullOutlet *self);
void NullOutlet_init(NullOutlet *self);
NullOutlet *NullOutlet_new();
void OutletSpecifier_clear(OutletSpecifier *self);
void OutletSpecifier_free(OutletSpecifier *self);
void OutletSpecifier_init(OutletSpecifier *self);
OutletSpecifier *OutletSpecifier_new();
void Pad_clear(Pad *self);
void Pad_free(Pad *self);
void Pad_init(Pad *self);
Pad *Pad_new();
void PadList_clear(PadList *self);
void PadList_free(PadList *self);
void PadList_init(PadList *self);
PadList *PadList_new();
void PortFind_clear(PortFind *self);
void PortFind_free(PortFind *self);
void PortFind_init(PortFind *self);
PortFind *PortFind_new();
void PortFindCell_clear(PortFindCell *self);
void PortFindCell_free(PortFindCell *self);
void PortFindCell_init(PortFindCell *self);
PortFindCell *PortFindCell_new();
void PortRef_clear(PortRef *self);
void PortRef_free(PortRef *self);
void PortRef_init(PortRef *self);
PortRef *PortRef_new();
void RecordBuffer_clear(RecordBuffer *self);
void RecordBuffer_free(RecordBuffer *self);
void RecordBuffer_init(RecordBuffer *self);
RecordBuffer *RecordBuffer_new();
void SelectNextPushedPadDispatch_clear(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_free(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_init(SelectNextPushedPadDispatch *self);
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_new();
void Timed_clear(Timed *self);
void Timed_free(Timed *self);
void Timed_init(Timed *self);
Timed *Timed_new();
void TimedOff_clear(TimedOff *self);
void TimedOff_free(TimedOff *self);
void TimedOff_init(TimedOff *self);
TimedOff *TimedOff_new();
void Track_clear(Track *self);
void Track_free(Track *self);
void Track_init(Track *self);
Track *Track_new();
void TrackList_clear(TrackList *self);
void TrackList_free(TrackList *self);
void TrackList_init(TrackList *self);
TrackList *TrackList_new();
void VstOutlet_clear(VstOutlet *self);
void VstOutlet_free(VstOutlet *self);
void VstOutlet_init(VstOutlet *self);
VstOutlet *VstOutlet_new();
typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typeName) ((typeName*)&Undefined_instance)
#define BendOutlet_itype 11
#define CcOutlet_itype 12
#define DecrementFrameDispatch_itype 13
#define FloatSequence_itype 14
#define IncrementFrameDispatch_itype 15
#define ManageChokeGroupsDispatch_itype 16
#define MarshalSi_itype 17
#define MarshalSii_itype 18
#define MarshalSs_itype 19
#define MidiFileDropDispatch_itype 20
#define NoteOutlet_itype 21
#define NoteSequence_itype 22
#define NullOutlet_itype 23
#define SelectNextPushedPadDispatch_itype 24
#define VstOutlet_itype 25
void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err);
Dispatch *Dispatch_create(int itype, Error *err);
void Dispatch_free(Dispatch *self, Error *err);
void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err);
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err);
void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err);
void Outlet_sendNote(Outlet *self, uint8_t a1, uint8_t a2, Error *err);
void Outlet_sendFloat(Outlet *self, double a1, Error *err);
void Sequence_start(Sequence *self, Ticks a1, Ticks a2, TimedPq *a3, RecordBuffer *a4, Error *err);
void Sequence_drive(Sequence *self, Ticks a1, TimedPq *a2, Error *err);
void Sequence_stop(Sequence *self, Ticks a1, Error *err);
void Sequence_padNoteOff(Sequence *self, int a1, Ticks a2, Error *err);
void Sequence_setCycle(Sequence *self, bool a1, Error *err);
void Sequence_free(Sequence *self, Error *err);
OutletSpecifier *Sequence_outSpec(Sequence *self, Error *err);
static inline Symbol *Arguments_s1(Arguments *self){return self->s1;}
static inline void Arguments_setS1(Arguments *self, Symbol *value){self->s1 = value;}
static inline long Arguments_i1(Arguments *self){return self->i1;}
static inline void Arguments_setI1(Arguments *self, long value){self->i1 = value;}
static inline long Arguments_i2(Arguments *self){return self->i2;}
static inline void Arguments_setI2(Arguments *self, long value){self->i2 = value;}
static inline long Arguments_ivalue(Arguments *self){return self->ivalue;}
static inline void Arguments_setIvalue(Arguments *self, long value){self->ivalue = value;}
static inline long Arguments_inlet(Arguments *self){return self->inlet;}
static inline void Arguments_setInlet(Arguments *self, long value){self->inlet = value;}
static inline void AtomAr_changeLength(AtomAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void AtomAr_clear(AtomAr *arr) {
    Array_clear((Array*)arr);
    AtomAr zero = {0};
    *arr = zero;
}

#define AtomAr_each(it, arr) for (Atom* it = arr->data; it < arr->data + arr->len; it++)

static inline void AtomAr_fit(AtomAr *arr) {
    Array_fit((Array*)arr);
}

#define AtomAr_foreach(var, arr)                for (AtomArFIt_declare(var, arr, 0); AtomArFIt_next(&var); )
#define AtomAr_foreachOffset(var, arr, offset)  for (AtomArFIt_declare(var, arr, offset); AtomArFIt_next(&var); )            

static inline void AtomAr_free(AtomAr *arr) {
    Array_free((Array*)arr);
}

static inline Atom AtomAr_get(AtomAr *arr, int index, Error *err) {
    Atom v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Atom *AtomAr_getp(AtomAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Atom *)Array_get((Array*)arr, index);
}

static inline void AtomAr_init(AtomAr *arr, int nelems) {
   void (*clearer)(Atom *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Atom), (Array_clearElement)clearer);
}

static inline void AtomAr_insert(AtomAr *arr, int index, Atom elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Atom *p = (Atom *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void AtomAr_insertp(AtomAr *arr, int index, Atom *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Atom *p = (Atom *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int AtomAr_last(AtomAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int AtomAr_len(AtomAr *arr) {
    return Array_len((Array*)arr);
}

#define AtomAr_loop(var) while (AtomArFIt_next(&var)) 

static inline AtomAr *AtomAr_new(int nelems) {
    void (*clearer)(Atom *) = NULL;
    return (AtomAr*)Array_new(nelems, sizeof(Atom), (Array_clearElement)clearer);
}

static inline void AtomAr_pop(AtomAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void AtomAr_push(AtomAr *arr, Atom elem) {
    Atom *p = (Atom *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void AtomAr_pushp(AtomAr *arr, Atom *elem) {
    Atom *p = (Atom *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define AtomAr_reach(it, arr) for (Atom* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void AtomAr_remove(AtomAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void AtomAr_removeN(AtomAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define AtomAr_rforeach(var, arr)                for (AtomArRIt_declare(var, arr, 0); AtomArRIt_next(&var); )
#define AtomAr_rforeachOffset(var, arr, offset)  for (AtomArRIt_declare(var, arr, offset); AtomArRIt_next(&var); )

#define AtomAr_rloop(var) while (AtomArRIt_next(&var))             

static inline void AtomAr_set(AtomAr *arr, int index, Atom elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void AtomAr_setp(AtomAr *arr, int index, Atom *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void AtomAr_truncate(AtomAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool AtomArFIt_atEnd(AtomArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define AtomArFIt_declare(var, arr, offset)  AtomArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define AtomArFIt_declare0(var)  AtomArFIt var = {0}

static inline bool AtomArFIt_next(AtomArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool AtomArFIt_remove(AtomArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool AtomArRIt_atEnd(AtomArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define AtomArRIt_declare(var, arr, offset)  AtomArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define AtomArRIt_declare0(var)  AtomArRIt var = {0}

static inline bool AtomArRIt_next(AtomArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool AtomArRIt_remove(AtomArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void AtomArAr_changeLength(AtomArAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void AtomArAr_clear(AtomArAr *arr) {
    Array_clear((Array*)arr);
    AtomArAr zero = {0};
    *arr = zero;
}

#define AtomArAr_each(it, arr) for (AtomAr* it = arr->data; it < arr->data + arr->len; it++)

static inline void AtomArAr_fit(AtomArAr *arr) {
    Array_fit((Array*)arr);
}

#define AtomArAr_foreach(var, arr)                for (AtomArArFIt_declare(var, arr, 0); AtomArArFIt_next(&var); )
#define AtomArAr_foreachOffset(var, arr, offset)  for (AtomArArFIt_declare(var, arr, offset); AtomArArFIt_next(&var); )            

static inline void AtomArAr_free(AtomArAr *arr) {
    Array_free((Array*)arr);
}

static inline AtomAr AtomArAr_get(AtomArAr *arr, int index, Error *err) {
    AtomAr v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline AtomAr *AtomArAr_getp(AtomArAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (AtomAr *)Array_get((Array*)arr, index);
}

static inline void AtomArAr_init(AtomArAr *arr, int nelems) {
   void (*clearer)(AtomAr *) = AtomAr_clear;
    Array_init((Array*)arr, nelems, sizeof(AtomAr), (Array_clearElement)clearer);
}

static inline void AtomArAr_insert(AtomArAr *arr, int index, AtomAr elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    AtomAr *p = (AtomAr *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void AtomArAr_insertp(AtomArAr *arr, int index, AtomAr *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    AtomAr *p = (AtomAr *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int AtomArAr_last(AtomArAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int AtomArAr_len(AtomArAr *arr) {
    return Array_len((Array*)arr);
}

#define AtomArAr_loop(var) while (AtomArArFIt_next(&var)) 

static inline AtomArAr *AtomArAr_new(int nelems) {
    void (*clearer)(AtomAr *) = AtomAr_clear;
    return (AtomArAr*)Array_new(nelems, sizeof(AtomAr), (Array_clearElement)clearer);
}

static inline void AtomArAr_pop(AtomArAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void AtomArAr_push(AtomArAr *arr, AtomAr elem) {
    AtomAr *p = (AtomAr *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void AtomArAr_pushp(AtomArAr *arr, AtomAr *elem) {
    AtomAr *p = (AtomAr *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define AtomArAr_reach(it, arr) for (AtomAr* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void AtomArAr_remove(AtomArAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void AtomArAr_removeN(AtomArAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define AtomArAr_rforeach(var, arr)                for (AtomArArRIt_declare(var, arr, 0); AtomArArRIt_next(&var); )
#define AtomArAr_rforeachOffset(var, arr, offset)  for (AtomArArRIt_declare(var, arr, offset); AtomArArRIt_next(&var); )

#define AtomArAr_rloop(var) while (AtomArArRIt_next(&var))             

static inline void AtomArAr_set(AtomArAr *arr, int index, AtomAr elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void AtomArAr_setp(AtomArAr *arr, int index, AtomAr *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void AtomArAr_truncate(AtomArAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool AtomArArFIt_atEnd(AtomArArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define AtomArArFIt_declare(var, arr, offset)  AtomArArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define AtomArArFIt_declare0(var)  AtomArArFIt var = {0}

static inline bool AtomArArFIt_next(AtomArArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool AtomArArFIt_remove(AtomArArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool AtomArArRIt_atEnd(AtomArArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define AtomArArRIt_declare(var, arr, offset)  AtomArArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define AtomArArRIt_declare0(var)  AtomArArRIt var = {0}

static inline bool AtomArArRIt_next(AtomArArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool AtomArArRIt_remove(AtomArArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline AtomAr BendOutlet_atoms(BendOutlet *self){return self->atoms;}
static inline void BendOutlet_setAtoms(BendOutlet *self, AtomAr value){self->atoms = value;}
static inline Port *BendOutlet_port(BendOutlet *self){return self->port;}
static inline void BendOutlet_setPort(BendOutlet *self, Port *value){self->port = value;}
static inline BendOutlet *BendOutlet_castFromOutlet(Outlet *self) {
    if (self->itype == BendOutlet_itype) {
        return (BendOutlet*)self;
    }
    return NULL;
}
static inline Outlet *BendOutlet_castToOutlet(BendOutlet *self) {
    return (Outlet*)self;
}
static inline int BinFile_version(BinFile *self){return self->version;}
static inline void BinFile_setVersion(BinFile *self, int value){self->version = value;}
static inline String *BinFile_filename(BinFile *self){return self->filename;}
static inline void BinFile_setFilename(BinFile *self, String *value){self->filename = value;}
static inline String *BinFile_buffer(BinFile *self){return self->buffer;}
static inline void BinFile_setBuffer(BinFile *self, String *value){self->buffer = value;}
static inline FILE *BinFile_stream(BinFile *self){return self->stream;}
static inline void BinFile_setStream(BinFile *self, FILE *value){self->stream = value;}
static inline int CcOutlet_cc(CcOutlet *self){return self->cc;}
static inline void CcOutlet_setCc(CcOutlet *self, int value){self->cc = value;}
static inline AtomAr CcOutlet_atoms(CcOutlet *self){return self->atoms;}
static inline void CcOutlet_setAtoms(CcOutlet *self, AtomAr value){self->atoms = value;}
static inline Port *CcOutlet_port(CcOutlet *self){return self->port;}
static inline void CcOutlet_setPort(CcOutlet *self, Port *value){self->port = value;}
static inline CcOutlet *CcOutlet_castFromOutlet(Outlet *self) {
    if (self->itype == CcOutlet_itype) {
        return (CcOutlet*)self;
    }
    return NULL;
}
static inline Outlet *CcOutlet_castToOutlet(CcOutlet *self) {
    return (Outlet*)self;
}
static inline DecrementFrameDispatch *DecrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == DecrementFrameDispatch_itype) {
        return (DecrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *DecrementFrameDispatch_castToDispatch(DecrementFrameDispatch *self) {
    return (Dispatch*)self;
}
static inline int Dispatch_nthIType(int n, int *itype) {
    static int itypes[] = {
        DecrementFrameDispatch_itype, IncrementFrameDispatch_itype, ManageChokeGroupsDispatch_itype, MidiFileDropDispatch_itype, SelectNextPushedPadDispatch_itype
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Dispatch_foreachIType(itype) for (int __##itype = 0, itype = 0; Dispatch_nthIType(__##itype, &itype); __##itype++)
static inline Symbol *Dispatch_selector(Dispatch *self){return self->selector;}
static inline void Dispatch_setSelector(Dispatch *self, Symbol *value){self->selector = value;}
static inline Symbol *Dispatch_portId(Dispatch *self){return self->portId;}
static inline void Dispatch_setPortId(Dispatch *self, Symbol *value){self->portId = value;}
static inline int Dispatch_inlet(Dispatch *self){return self->inlet;}
static inline void Dispatch_setInlet(Dispatch *self, int value){self->inlet = value;}
static inline Marshal *Dispatch_marshal(Dispatch *self){return self->marshal;}
static inline void Dispatch_setMarshal(Dispatch *self, Marshal *value){self->marshal = value;}
#define Dispatch_declare(name, itype, selector, portId, inlet, marshal) Dispatch name = {(itype), (selector), (portId), (inlet), (marshal)}
static inline void DispatchPtAr_changeLength(DispatchPtAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void DispatchPtAr_clear(DispatchPtAr *arr) {
    Array_clear((Array*)arr);
    DispatchPtAr zero = {0};
    *arr = zero;
}

#define DispatchPtAr_each(it, arr) for (Dispatch ** it = arr->data; it < arr->data + arr->len; it++)

static inline void DispatchPtAr_fit(DispatchPtAr *arr) {
    Array_fit((Array*)arr);
}

#define DispatchPtAr_foreach(var, arr)                for (DispatchPtArFIt_declare(var, arr, 0); DispatchPtArFIt_next(&var); )
#define DispatchPtAr_foreachOffset(var, arr, offset)  for (DispatchPtArFIt_declare(var, arr, offset); DispatchPtArFIt_next(&var); )            

static inline void DispatchPtAr_free(DispatchPtAr *arr) {
    Array_free((Array*)arr);
}

static inline Dispatch *DispatchPtAr_get(DispatchPtAr *arr, int index, Error *err) {
    Dispatch * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Dispatch **DispatchPtAr_getp(DispatchPtAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Dispatch **)Array_get((Array*)arr, index);
}

static inline void DispatchPtAr_init(DispatchPtAr *arr, int nelems) {
   void (*clearer)(Dispatch **) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Dispatch *), (Array_clearElement)clearer);
}

static inline void DispatchPtAr_insert(DispatchPtAr *arr, int index, Dispatch *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Dispatch * *p = (Dispatch **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void DispatchPtAr_insertp(DispatchPtAr *arr, int index, Dispatch **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Dispatch * *p = (Dispatch **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int DispatchPtAr_last(DispatchPtAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int DispatchPtAr_len(DispatchPtAr *arr) {
    return Array_len((Array*)arr);
}

#define DispatchPtAr_loop(var) while (DispatchPtArFIt_next(&var)) 

static inline DispatchPtAr *DispatchPtAr_new(int nelems) {
    void (*clearer)(Dispatch **) = NULL;
    return (DispatchPtAr*)Array_new(nelems, sizeof(Dispatch *), (Array_clearElement)clearer);
}

static inline void DispatchPtAr_pop(DispatchPtAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void DispatchPtAr_push(DispatchPtAr *arr, Dispatch *elem) {
    Dispatch * *p = (Dispatch **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void DispatchPtAr_pushp(DispatchPtAr *arr, Dispatch **elem) {
    Dispatch * *p = (Dispatch **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define DispatchPtAr_reach(it, arr) for (Dispatch ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void DispatchPtAr_remove(DispatchPtAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void DispatchPtAr_removeN(DispatchPtAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define DispatchPtAr_rforeach(var, arr)                for (DispatchPtArRIt_declare(var, arr, 0); DispatchPtArRIt_next(&var); )
#define DispatchPtAr_rforeachOffset(var, arr, offset)  for (DispatchPtArRIt_declare(var, arr, offset); DispatchPtArRIt_next(&var); )

#define DispatchPtAr_rloop(var) while (DispatchPtArRIt_next(&var))             

static inline void DispatchPtAr_set(DispatchPtAr *arr, int index, Dispatch *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void DispatchPtAr_setp(DispatchPtAr *arr, int index, Dispatch **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void DispatchPtAr_truncate(DispatchPtAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool DispatchPtArFIt_atEnd(DispatchPtArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define DispatchPtArFIt_declare(var, arr, offset)  DispatchPtArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define DispatchPtArFIt_declare0(var)  DispatchPtArFIt var = {0}

static inline bool DispatchPtArFIt_next(DispatchPtArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool DispatchPtArFIt_remove(DispatchPtArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool DispatchPtArRIt_atEnd(DispatchPtArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define DispatchPtArRIt_declare(var, arr, offset)  DispatchPtArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define DispatchPtArRIt_declare0(var)  DispatchPtArRIt var = {0}

static inline bool DispatchPtArRIt_next(DispatchPtArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool DispatchPtArRIt_remove(DispatchPtArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void DispatchPtAr_binInsert(DispatchPtAr *arr, Dispatch *elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void DispatchPtAr_binRemove(DispatchPtAr *arr, Dispatch *elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Dispatch **DispatchPtAr_binSearch(DispatchPtAr *arr, Dispatch *elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    return (Dispatch **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline Dispatch **DispatchPtAr_pqPeek(DispatchPtAr *arr) {
   return (Dispatch **)Array_pqPeek((Array*)arr);
}

static inline bool DispatchPtAr_pqPop(DispatchPtAr *arr, Dispatch **elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void DispatchPtAr_pqPush(DispatchPtAr *arr, Dispatch *elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void DispatchPtAr_pqSort(DispatchPtAr *arr) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void DispatchPtAr_sort(DispatchPtAr *arr) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline SymbolPtrAr *DropDown_table(DropDown *self){return &self->table;}
static inline int DropDown_selected(DropDown *self){return self->selected;}
static inline Ticks FloatEvent_stime(FloatEvent *self){return self->stime;}
static inline void FloatEvent_setStime(FloatEvent *self, Ticks value){self->stime = value;}
static inline double FloatEvent_value(FloatEvent *self){return self->value;}
static inline void FloatEvent_setValue(FloatEvent *self, double value){self->value = value;}
static inline void FloatEventAr_changeLength(FloatEventAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void FloatEventAr_clear(FloatEventAr *arr) {
    Array_clear((Array*)arr);
    FloatEventAr zero = {0};
    *arr = zero;
}

#define FloatEventAr_each(it, arr) for (FloatEvent* it = arr->data; it < arr->data + arr->len; it++)

static inline void FloatEventAr_fit(FloatEventAr *arr) {
    Array_fit((Array*)arr);
}

#define FloatEventAr_foreach(var, arr)                for (FloatEventArFIt_declare(var, arr, 0); FloatEventArFIt_next(&var); )
#define FloatEventAr_foreachOffset(var, arr, offset)  for (FloatEventArFIt_declare(var, arr, offset); FloatEventArFIt_next(&var); )            

static inline void FloatEventAr_free(FloatEventAr *arr) {
    Array_free((Array*)arr);
}

static inline FloatEvent FloatEventAr_get(FloatEventAr *arr, int index, Error *err) {
    FloatEvent v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline FloatEvent *FloatEventAr_getp(FloatEventAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (FloatEvent *)Array_get((Array*)arr, index);
}

static inline void FloatEventAr_init(FloatEventAr *arr, int nelems) {
   void (*clearer)(FloatEvent *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(FloatEvent), (Array_clearElement)clearer);
}

static inline void FloatEventAr_insert(FloatEventAr *arr, int index, FloatEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    FloatEvent *p = (FloatEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void FloatEventAr_insertp(FloatEventAr *arr, int index, FloatEvent *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    FloatEvent *p = (FloatEvent *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int FloatEventAr_last(FloatEventAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int FloatEventAr_len(FloatEventAr *arr) {
    return Array_len((Array*)arr);
}

#define FloatEventAr_loop(var) while (FloatEventArFIt_next(&var)) 

static inline FloatEventAr *FloatEventAr_new(int nelems) {
    void (*clearer)(FloatEvent *) = NULL;
    return (FloatEventAr*)Array_new(nelems, sizeof(FloatEvent), (Array_clearElement)clearer);
}

static inline void FloatEventAr_pop(FloatEventAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void FloatEventAr_push(FloatEventAr *arr, FloatEvent elem) {
    FloatEvent *p = (FloatEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void FloatEventAr_pushp(FloatEventAr *arr, FloatEvent *elem) {
    FloatEvent *p = (FloatEvent *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define FloatEventAr_reach(it, arr) for (FloatEvent* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void FloatEventAr_remove(FloatEventAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void FloatEventAr_removeN(FloatEventAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define FloatEventAr_rforeach(var, arr)                for (FloatEventArRIt_declare(var, arr, 0); FloatEventArRIt_next(&var); )
#define FloatEventAr_rforeachOffset(var, arr, offset)  for (FloatEventArRIt_declare(var, arr, offset); FloatEventArRIt_next(&var); )

#define FloatEventAr_rloop(var) while (FloatEventArRIt_next(&var))             

static inline void FloatEventAr_set(FloatEventAr *arr, int index, FloatEvent elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FloatEventAr_setp(FloatEventAr *arr, int index, FloatEvent *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void FloatEventAr_truncate(FloatEventAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool FloatEventArFIt_atEnd(FloatEventArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define FloatEventArFIt_declare(var, arr, offset)  FloatEventArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define FloatEventArFIt_declare0(var)  FloatEventArFIt var = {0}

static inline bool FloatEventArFIt_next(FloatEventArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool FloatEventArFIt_remove(FloatEventArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool FloatEventArRIt_atEnd(FloatEventArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define FloatEventArRIt_declare(var, arr, offset)  FloatEventArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define FloatEventArRIt_declare0(var)  FloatEventArRIt var = {0}

static inline bool FloatEventArRIt_next(FloatEventArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool FloatEventArRIt_remove(FloatEventArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void FloatEventAr_binInsert(FloatEventAr *arr, FloatEvent elem) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void FloatEventAr_binRemove(FloatEventAr *arr, FloatEvent elem) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline FloatEvent *FloatEventAr_binSearch(FloatEventAr *arr, FloatEvent elem) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
    return (FloatEvent *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline FloatEvent *FloatEventAr_pqPeek(FloatEventAr *arr) {
   return (FloatEvent *)Array_pqPeek((Array*)arr);
}

static inline bool FloatEventAr_pqPop(FloatEventAr *arr, FloatEvent *elem) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void FloatEventAr_pqPush(FloatEventAr *arr, FloatEvent elem) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void FloatEventAr_pqSort(FloatEventAr *arr) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void FloatEventAr_sort(FloatEventAr *arr) {
    int (*compare)(FloatEvent *, FloatEvent *) = FloatEvent_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline long FloatSequence_version(FloatSequence *self){return self->version;}
static inline void FloatSequence_setVersion(FloatSequence *self, long value){self->version = value;}
static inline Ticks FloatSequence_startTime(FloatSequence *self){return self->startTime;}
static inline void FloatSequence_setStartTime(FloatSequence *self, Ticks value){self->startTime = value;}
static inline Ticks FloatSequence_sequenceLength(FloatSequence *self){return self->sequenceLength;}
static inline void FloatSequence_setSequenceLength(FloatSequence *self, Ticks value){self->sequenceLength = value;}
static inline OutletSpecifier FloatSequence_outletSpecifier(FloatSequence *self){return self->outletSpecifier;}
static inline void FloatSequence_setOutletSpecifier(FloatSequence *self, OutletSpecifier value){self->outletSpecifier = value;}
static inline int FloatSequence_cursor(FloatSequence *self){return self->cursor;}
static inline void FloatSequence_setCursor(FloatSequence *self, int value){self->cursor = value;}
static inline bool FloatSequence_cycle(FloatSequence *self){return self->cycle;}
static inline void FloatSequence_setCycle(FloatSequence *self, bool value){self->cycle = value;}
static inline bool FloatSequence_inEndgroup(FloatSequence *self){return self->inEndgroup;}
static inline void FloatSequence_setInEndgroup(FloatSequence *self, bool value){self->inEndgroup = value;}
static inline Outlet *FloatSequence_outlet(FloatSequence *self){return self->outlet;}
static inline void FloatSequence_setOutlet(FloatSequence *self, Outlet *value){self->outlet = value;}
static inline FloatSequence *FloatSequence_recordingSeq(FloatSequence *self){return self->recordingSeq;}
static inline void FloatSequence_setRecordingSeq(FloatSequence *self, FloatSequence *value){self->recordingSeq = value;}
static inline FloatEventAr FloatSequence_events(FloatSequence *self){return self->events;}
static inline void FloatSequence_setEvents(FloatSequence *self, FloatEventAr value){self->events = value;}
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
static inline int Foo_i(Foo *self){return self->i;}
static inline void Foo_setI(Foo *self, int value){self->i = value;}
static inline double Foo_d(Foo *self){return self->d;}
static inline void Foo_setD(Foo *self, double value){self->d = value;}
static inline void FooArr_changeLength(FooArr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void FooArr_clear(FooArr *arr) {
    Array_clear((Array*)arr);
    FooArr zero = {0};
    *arr = zero;
}

#define FooArr_each(it, arr) for (Foo* it = arr->data; it < arr->data + arr->len; it++)

static inline void FooArr_fit(FooArr *arr) {
    Array_fit((Array*)arr);
}

#define FooArr_foreach(var, arr)                for (FooArrFIt_declare(var, arr, 0); FooArrFIt_next(&var); )
#define FooArr_foreachOffset(var, arr, offset)  for (FooArrFIt_declare(var, arr, offset); FooArrFIt_next(&var); )            

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
   void (*clearer)(Foo *) = Foo_recorder;
    Array_init((Array*)arr, nelems, sizeof(Foo), (Array_clearElement)clearer);
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
    void (*clearer)(Foo *) = Foo_recorder;
    return (FooArr*)Array_new(nelems, sizeof(Foo), (Array_clearElement)clearer);
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

#define FooArr_rforeach(var, arr)                for (FooArrRIt_declare(var, arr, 0); FooArrRIt_next(&var); )
#define FooArr_rforeachOffset(var, arr, offset)  for (FooArrRIt_declare(var, arr, offset); FooArrRIt_next(&var); )

#define FooArr_rloop(var) while (FooArrRIt_next(&var))             

static inline void FooArr_set(FooArr *arr, int index, Foo elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void FooArr_setp(FooArr *arr, int index, Foo *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void FooArr_truncate(FooArr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool FooArrFIt_atEnd(FooArrFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define FooArrFIt_declare(var, arr, offset)  FooArrFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define FooArrFIt_declare0(var)  FooArrFIt var = {0}

static inline bool FooArrFIt_next(FooArrFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool FooArrFIt_remove(FooArrFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool FooArrRIt_atEnd(FooArrRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define FooArrRIt_declare(var, arr, offset)  FooArrRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define FooArrRIt_declare0(var)  FooArrRIt var = {0}

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

static inline Foo *FooArr_pqPeek(FooArr *arr) {
   return (Foo *)Array_pqPeek((Array*)arr);
}

static inline bool FooArr_pqPop(FooArr *arr, Foo *elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void FooArr_pqPush(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void FooArr_pqSort(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
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

static inline Foo *FooArr_pqPeekBoth(FooArr *arr) {
   return (Foo *)Array_pqPeek((Array*)arr);
}

static inline bool FooArr_pqPopBoth(FooArr *arr, Foo *elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void FooArr_pqPushBoth(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void FooArr_pqSortBoth(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   Array_pqSort((Array*)arr, (Array_compare)compare);
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

static inline FooArrFIt FooArr_binSearchMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
    FooArrFIt it = {0};
   if (Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArrayFIt*)&it) != NULL) {
       return it;
    }
   it.index  = arr->len;
   it.uBound = 0;
    return it;
}

static inline Foo *FooArr_pqPeekMulti(FooArr *arr) {
   return (Foo *)Array_pqPeek((Array*)arr);
}

static inline bool FooArr_pqPopMulti(FooArr *arr, Foo *elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void FooArr_pqPushMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void FooArr_pqSortMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
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

static inline FooArrFIt FooArr_binSearchBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    FooArrFIt it = {0};
   if (Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArrayFIt*)&it) != NULL) {
       return it;
    }
   it.index  = arr->len;
   it.uBound = 0;
    return it;
}

static inline Foo *FooArr_pqPeekBothMulti(FooArr *arr) {
   return (Foo *)Array_pqPeek((Array*)arr);
}

static inline bool FooArr_pqPopBothMulti(FooArr *arr, Foo *elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void FooArr_pqPushBothMulti(FooArr *arr, Foo elem) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void FooArr_pqSortBothMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void FooArr_sortBothMulti(FooArr *arr) {
    int (*compare)(Foo *, Foo *) = Foo_cmpBoth;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline PadList *Hub_padList(Hub *self){return self->padList;}
static inline void Hub_setPadList(Hub *self, PadList *value){self->padList = value;}
static inline TrackList *Hub_trackList(Hub *self){return self->trackList;}
static inline void Hub_setTrackList(Hub *self, TrackList *value){self->trackList = value;}
static inline Port *Hub_currBankPort(Hub *self){return self->currBankPort;}
static inline void Hub_setCurrBankPort(Hub *self, Port *value){self->currBankPort = value;}
static inline Port *Hub_currFramePort(Hub *self){return self->currFramePort;}
static inline void Hub_setCurrFramePort(Hub *self, Port *value){self->currFramePort = value;}
static inline Port *Hub_selBankPort(Hub *self){return self->selBankPort;}
static inline void Hub_setSelBankPort(Hub *self, Port *value){self->selBankPort = value;}
static inline Port *Hub_selFramePort(Hub *self){return self->selFramePort;}
static inline void Hub_setSelFramePort(Hub *self, Port *value){self->selFramePort = value;}
static inline Port *Hub_selPadPort(Hub *self){return self->selPadPort;}
static inline void Hub_setSelPadPort(Hub *self, Port *value){self->selPadPort = value;}
static inline Port *Hub_chokeGroupPort(Hub *self){return self->chokeGroupPort;}
static inline void Hub_setChokeGroupPort(Hub *self, Port *value){self->chokeGroupPort = value;}
static inline DropDown *Hub_cgLocalGlobalMenu(Hub *self){return &self->cgLocalGlobalMenu;}
static inline DropDown *Hub_cgInstrumentMenu(Hub *self){return &self->cgInstrumentMenu;}
static inline DropDown *Hub_cgIndexMenu(Hub *self){return &self->cgIndexMenu;}
static inline int Hub_bank(Hub *self){return self->bank;}
static inline void Hub_setBank(Hub *self, int value){self->bank = value;}
static inline int Hub_frame(Hub *self){return self->frame;}
static inline void Hub_setFrame(Hub *self, int value){self->frame = value;}
static inline bool Hub_grabNextTappedPad(Hub *self){return self->grabNextTappedPad;}
static inline void Hub_setGrabNextTappedPad(Hub *self, bool value){self->grabNextTappedPad = value;}
static inline int Hub_selectedPad(Hub *self){return self->selectedPad;}
static inline void Hub_setSelectedPad(Hub *self, int value){self->selectedPad = value;}
static inline Arguments Hub_arguments(Hub *self){return self->arguments;}
static inline void Hub_setArguments(Hub *self, Arguments value){self->arguments = value;}
static inline DispatchPtAr *Hub_dispatcher(Hub *self){return &self->dispatcher;}
static inline Ticks Hub_masterClock(Hub *self){return self->masterClock;}
static inline void Hub_setMasterClock(Hub *self, Ticks value){self->masterClock = value;}
static inline IncrementFrameDispatch *IncrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == IncrementFrameDispatch_itype) {
        return (IncrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *IncrementFrameDispatch_castToDispatch(IncrementFrameDispatch *self) {
    return (Dispatch*)self;
}
static inline int IndexedOff_padIndex(IndexedOff *self){return self->padIndex;}
static inline void IndexedOff_setPadIndex(IndexedOff *self, int value){self->padIndex = value;}
static inline int IndexedOff_pitch(IndexedOff *self){return self->pitch;}
static inline void IndexedOff_setPitch(IndexedOff *self, int value){self->pitch = value;}
#define IndexedOff_declare(name, padIndex, pitch) IndexedOff name = {(padIndex), (pitch)}
static inline void IndexedOffAr_changeLength(IndexedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void IndexedOffAr_clear(IndexedOffAr *arr) {
    Array_clear((Array*)arr);
    IndexedOffAr zero = {0};
    *arr = zero;
}

#define IndexedOffAr_each(it, arr) for (IndexedOff* it = arr->data; it < arr->data + arr->len; it++)

static inline void IndexedOffAr_fit(IndexedOffAr *arr) {
    Array_fit((Array*)arr);
}

#define IndexedOffAr_foreach(var, arr)                for (IndexedOffArFIt_declare(var, arr, 0); IndexedOffArFIt_next(&var); )
#define IndexedOffAr_foreachOffset(var, arr, offset)  for (IndexedOffArFIt_declare(var, arr, offset); IndexedOffArFIt_next(&var); )            

static inline void IndexedOffAr_free(IndexedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline IndexedOff IndexedOffAr_get(IndexedOffAr *arr, int index, Error *err) {
    IndexedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline IndexedOff *IndexedOffAr_getp(IndexedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (IndexedOff *)Array_get((Array*)arr, index);
}

static inline void IndexedOffAr_init(IndexedOffAr *arr, int nelems) {
   void (*clearer)(IndexedOff *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(IndexedOff), (Array_clearElement)clearer);
}

static inline void IndexedOffAr_insert(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IndexedOffAr_insertp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    IndexedOff *p = (IndexedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int IndexedOffAr_last(IndexedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int IndexedOffAr_len(IndexedOffAr *arr) {
    return Array_len((Array*)arr);
}

#define IndexedOffAr_loop(var) while (IndexedOffArFIt_next(&var)) 

static inline IndexedOffAr *IndexedOffAr_new(int nelems) {
    void (*clearer)(IndexedOff *) = NULL;
    return (IndexedOffAr*)Array_new(nelems, sizeof(IndexedOff), (Array_clearElement)clearer);
}

static inline void IndexedOffAr_pop(IndexedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IndexedOffAr_push(IndexedOffAr *arr, IndexedOff elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void IndexedOffAr_pushp(IndexedOffAr *arr, IndexedOff *elem) {
    IndexedOff *p = (IndexedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define IndexedOffAr_reach(it, arr) for (IndexedOff* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void IndexedOffAr_remove(IndexedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IndexedOffAr_removeN(IndexedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define IndexedOffAr_rforeach(var, arr)                for (IndexedOffArRIt_declare(var, arr, 0); IndexedOffArRIt_next(&var); )
#define IndexedOffAr_rforeachOffset(var, arr, offset)  for (IndexedOffArRIt_declare(var, arr, offset); IndexedOffArRIt_next(&var); )

#define IndexedOffAr_rloop(var) while (IndexedOffArRIt_next(&var))             

static inline void IndexedOffAr_set(IndexedOffAr *arr, int index, IndexedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IndexedOffAr_setp(IndexedOffAr *arr, int index, IndexedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IndexedOffAr_truncate(IndexedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool IndexedOffArFIt_atEnd(IndexedOffArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define IndexedOffArFIt_declare(var, arr, offset)  IndexedOffArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define IndexedOffArFIt_declare0(var)  IndexedOffArFIt var = {0}

static inline bool IndexedOffArFIt_next(IndexedOffArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool IndexedOffArFIt_remove(IndexedOffArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool IndexedOffArRIt_atEnd(IndexedOffArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define IndexedOffArRIt_declare(var, arr, offset)  IndexedOffArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define IndexedOffArRIt_declare0(var)  IndexedOffArRIt var = {0}

static inline bool IndexedOffArRIt_next(IndexedOffArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool IndexedOffArRIt_remove(IndexedOffArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void IndexedOffAr_binInsertPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void IndexedOffAr_binRemovePadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline IndexedOffArFIt IndexedOffAr_binSearchPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    IndexedOffArFIt it = {0};
   if (Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArrayFIt*)&it) != NULL) {
       return it;
    }
   it.index  = arr->len;
   it.uBound = 0;
    return it;
}

static inline IndexedOff *IndexedOffAr_pqPeekPadIndex(IndexedOffAr *arr) {
   return (IndexedOff *)Array_pqPeek((Array*)arr);
}

static inline bool IndexedOffAr_pqPopPadIndex(IndexedOffAr *arr, IndexedOff *elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void IndexedOffAr_pqPushPadIndex(IndexedOffAr *arr, IndexedOff elem) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void IndexedOffAr_pqSortPadIndex(IndexedOffAr *arr) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void IndexedOffAr_sortPadIndex(IndexedOffAr *arr) {
    int (*compare)(IndexedOff *, IndexedOff *) = IndexedOff_cmpPadIndex;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void IntAr_changeLength(IntAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void IntAr_clear(IntAr *arr) {
    Array_clear((Array*)arr);
    IntAr zero = {0};
    *arr = zero;
}

#define IntAr_each(it, arr) for (int* it = arr->data; it < arr->data + arr->len; it++)

static inline void IntAr_fit(IntAr *arr) {
    Array_fit((Array*)arr);
}

#define IntAr_foreach(var, arr)                for (IntArFIt_declare(var, arr, 0); IntArFIt_next(&var); )
#define IntAr_foreachOffset(var, arr, offset)  for (IntArFIt_declare(var, arr, offset); IntArFIt_next(&var); )            

static inline void IntAr_free(IntAr *arr) {
    Array_free((Array*)arr);
}

static inline int IntAr_get(IntAr *arr, int index, Error *err) {
    int v = 0;
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline int *IntAr_getp(IntAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (int *)Array_get((Array*)arr, index);
}

static inline void IntAr_init(IntAr *arr, int nelems) {
   void (*clearer)(int *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)clearer);
}

static inline void IntAr_insert(IntAr *arr, int index, int elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void IntAr_insertp(IntAr *arr, int index, int *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    int *p = (int *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int IntAr_last(IntAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int IntAr_len(IntAr *arr) {
    return Array_len((Array*)arr);
}

#define IntAr_loop(var) while (IntArFIt_next(&var)) 

static inline IntAr *IntAr_new(int nelems) {
    void (*clearer)(int *) = NULL;
    return (IntAr*)Array_new(nelems, sizeof(int), (Array_clearElement)clearer);
}

static inline void IntAr_pop(IntAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void IntAr_push(IntAr *arr, int elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void IntAr_pushp(IntAr *arr, int *elem) {
    int *p = (int *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define IntAr_reach(it, arr) for (int* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void IntAr_remove(IntAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IntAr_removeN(IntAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define IntAr_rforeach(var, arr)                for (IntArRIt_declare(var, arr, 0); IntArRIt_next(&var); )
#define IntAr_rforeachOffset(var, arr, offset)  for (IntArRIt_declare(var, arr, offset); IntArRIt_next(&var); )

#define IntAr_rloop(var) while (IntArRIt_next(&var))             

static inline void IntAr_set(IntAr *arr, int index, int elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void IntAr_setp(IntAr *arr, int index, int *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void IntAr_truncate(IntAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool IntArFIt_atEnd(IntArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define IntArFIt_declare(var, arr, offset)  IntArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define IntArFIt_declare0(var)  IntArFIt var = {0}

static inline bool IntArFIt_next(IntArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool IntArFIt_remove(IntArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool IntArRIt_atEnd(IntArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define IntArRIt_declare(var, arr, offset)  IntArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define IntArRIt_declare0(var)  IntArRIt var = {0}

static inline bool IntArRIt_next(IntArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool IntArRIt_remove(IntArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

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

#define IntArr_foreach(var, arr)                for (IntArrFIt_declare(var, arr, 0); IntArrFIt_next(&var); )
#define IntArr_foreachOffset(var, arr, offset)  for (IntArrFIt_declare(var, arr, offset); IntArrFIt_next(&var); )            

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
   void (*clearer)(int *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(int), (Array_clearElement)clearer);
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
    void (*clearer)(int *) = NULL;
    return (IntArr*)Array_new(nelems, sizeof(int), (Array_clearElement)clearer);
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

#define IntArr_rforeach(var, arr)                for (IntArrRIt_declare(var, arr, 0); IntArrRIt_next(&var); )
#define IntArr_rforeachOffset(var, arr, offset)  for (IntArrRIt_declare(var, arr, offset); IntArrRIt_next(&var); )

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

static inline bool IntArrFIt_atEnd(IntArrFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define IntArrFIt_declare(var, arr, offset)  IntArrFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define IntArrFIt_declare0(var)  IntArrFIt var = {0}

static inline bool IntArrFIt_next(IntArrFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool IntArrFIt_remove(IntArrFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool IntArrRIt_atEnd(IntArrRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define IntArrRIt_declare(var, arr, offset)  IntArrRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define IntArrRIt_declare0(var)  IntArrRIt var = {0}

static inline bool IntArrRIt_next(IntArrRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool IntArrRIt_remove(IntArrRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void MEventAr_changeLength(MEventAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void MEventAr_clear(MEventAr *arr) {
    Array_clear((Array*)arr);
    MEventAr zero = {0};
    *arr = zero;
}

#define MEventAr_each(it, arr) for (MEvent* it = arr->data; it < arr->data + arr->len; it++)

static inline void MEventAr_fit(MEventAr *arr) {
    Array_fit((Array*)arr);
}

#define MEventAr_foreach(var, arr)                for (MEventArFIt_declare(var, arr, 0); MEventArFIt_next(&var); )
#define MEventAr_foreachOffset(var, arr, offset)  for (MEventArFIt_declare(var, arr, offset); MEventArFIt_next(&var); )            

static inline void MEventAr_free(MEventAr *arr) {
    Array_free((Array*)arr);
}

static inline MEvent MEventAr_get(MEventAr *arr, int index, Error *err) {
    MEvent v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline MEvent *MEventAr_getp(MEventAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (MEvent *)Array_get((Array*)arr, index);
}

static inline void MEventAr_init(MEventAr *arr, int nelems) {
   void (*clearer)(MEvent *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(MEvent), (Array_clearElement)clearer);
}

static inline void MEventAr_insert(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void MEventAr_insertp(MEventAr *arr, int index, MEvent *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int MEventAr_last(MEventAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int MEventAr_len(MEventAr *arr) {
    return Array_len((Array*)arr);
}

#define MEventAr_loop(var) while (MEventArFIt_next(&var)) 

static inline MEventAr *MEventAr_new(int nelems) {
    void (*clearer)(MEvent *) = NULL;
    return (MEventAr*)Array_new(nelems, sizeof(MEvent), (Array_clearElement)clearer);
}

static inline void MEventAr_pop(MEventAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void MEventAr_push(MEventAr *arr, MEvent elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void MEventAr_pushp(MEventAr *arr, MEvent *elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define MEventAr_reach(it, arr) for (MEvent* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void MEventAr_remove(MEventAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void MEventAr_removeN(MEventAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define MEventAr_rforeach(var, arr)                for (MEventArRIt_declare(var, arr, 0); MEventArRIt_next(&var); )
#define MEventAr_rforeachOffset(var, arr, offset)  for (MEventArRIt_declare(var, arr, offset); MEventArRIt_next(&var); )

#define MEventAr_rloop(var) while (MEventArRIt_next(&var))             

static inline void MEventAr_set(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void MEventAr_setp(MEventAr *arr, int index, MEvent *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void MEventAr_truncate(MEventAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool MEventArFIt_atEnd(MEventArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define MEventArFIt_declare(var, arr, offset)  MEventArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define MEventArFIt_declare0(var)  MEventArFIt var = {0}

static inline bool MEventArFIt_next(MEventArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool MEventArFIt_remove(MEventArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool MEventArRIt_atEnd(MEventArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define MEventArRIt_declare(var, arr, offset)  MEventArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define MEventArRIt_declare0(var)  MEventArRIt var = {0}

static inline bool MEventArRIt_next(MEventArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool MEventArRIt_remove(MEventArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == ManageChokeGroupsDispatch_itype) {
        return (ManageChokeGroupsDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *ManageChokeGroupsDispatch_castToDispatch(ManageChokeGroupsDispatch *self) {
    return (Dispatch*)self;
}
static inline int Marshal_nthIType(int n, int *itype) {
    static int itypes[] = {
        MarshalSi_itype, MarshalSii_itype, MarshalSs_itype
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Marshal_foreachIType(itype) for (int __##itype = 0, itype = 0; Marshal_nthIType(__##itype, &itype); __##itype++)
static inline MarshalSi *MarshalSi_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSi_itype) {
        return (MarshalSi*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSi_castToMarshal(MarshalSi *self) {
    return (Marshal*)self;
}
static inline MarshalSii *MarshalSii_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSii_itype) {
        return (MarshalSii*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSii_castToMarshal(MarshalSii *self) {
    return (Marshal*)self;
}
static inline MarshalSs *MarshalSs_castFromMarshal(Marshal *self) {
    if (self->itype == MarshalSs_itype) {
        return (MarshalSs*)self;
    }
    return NULL;
}
static inline Marshal *MarshalSs_castToMarshal(MarshalSs *self) {
    return (Marshal*)self;
}
static inline MidiFileDropDispatch *MidiFileDropDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == MidiFileDropDispatch_itype) {
        return (MidiFileDropDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *MidiFileDropDispatch_castToDispatch(MidiFileDropDispatch *self) {
    return (Dispatch*)self;
}
static inline bool Midiseq_useMasterClock(Midiseq *self){return self->useMasterClock;}
static inline void Midiseq_setUseMasterClock(Midiseq *self, bool value){self->useMasterClock = value;}
static inline Ticks Midiseq_sequenceLength(Midiseq *self){return self->sequenceLength;}
static inline void Midiseq_setSequenceLength(Midiseq *self, Ticks value){self->sequenceLength = value;}
static inline MEventAr Midiseq_events(Midiseq *self){return self->events;}
static inline void Midiseq_setEvents(Midiseq *self, MEventAr value){self->events = value;}
static inline Ticks Midiseq_startTime(Midiseq *self){return self->startTime;}
static inline void Midiseq_setStartTime(Midiseq *self, Ticks value){self->startTime = value;}
static inline int Midiseq_ptr(Midiseq *self){return self->ptr;}
static inline void Midiseq_setPtr(Midiseq *self, int value){self->ptr = value;}
static inline Ticks MusicalContext_ticksPerQuarterNote(MusicalContext *self){return self->ticksPerQuarterNote;}
static inline void MusicalContext_setTicksPerQuarterNote(MusicalContext *self, Ticks value){self->ticksPerQuarterNote = value;}
static inline Ticks MusicalContext_quarterNotesPerMeasure(MusicalContext *self){return self->quarterNotesPerMeasure;}
static inline void MusicalContext_setQuarterNotesPerMeasure(MusicalContext *self, Ticks value){self->quarterNotesPerMeasure = value;}
static inline uint8_t NoteEvent_pitch(NoteEvent *self){return self->pitch;}
static inline void NoteEvent_setPitch(NoteEvent *self, uint8_t value){self->pitch = value;}
static inline uint8_t NoteEvent_velocity(NoteEvent *self){return self->velocity;}
static inline void NoteEvent_setVelocity(NoteEvent *self, uint8_t value){self->velocity = value;}
static inline Ticks NoteEvent_stime(NoteEvent *self){return self->stime;}
static inline void NoteEvent_setStime(NoteEvent *self, Ticks value){self->stime = value;}
static inline Ticks NoteEvent_duration(NoteEvent *self){return self->duration;}
static inline void NoteEvent_setDuration(NoteEvent *self, Ticks value){self->duration = value;}
static inline void NoteEventAr_changeLength(NoteEventAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void NoteEventAr_clear(NoteEventAr *arr) {
    Array_clear((Array*)arr);
    NoteEventAr zero = {0};
    *arr = zero;
}

#define NoteEventAr_each(it, arr) for (NoteEvent* it = arr->data; it < arr->data + arr->len; it++)

static inline void NoteEventAr_fit(NoteEventAr *arr) {
    Array_fit((Array*)arr);
}

#define NoteEventAr_foreach(var, arr)                for (NoteEventArFIt_declare(var, arr, 0); NoteEventArFIt_next(&var); )
#define NoteEventAr_foreachOffset(var, arr, offset)  for (NoteEventArFIt_declare(var, arr, offset); NoteEventArFIt_next(&var); )            

static inline void NoteEventAr_free(NoteEventAr *arr) {
    Array_free((Array*)arr);
}

static inline NoteEvent NoteEventAr_get(NoteEventAr *arr, int index, Error *err) {
    NoteEvent v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline NoteEvent *NoteEventAr_getp(NoteEventAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (NoteEvent *)Array_get((Array*)arr, index);
}

static inline void NoteEventAr_init(NoteEventAr *arr, int nelems) {
   void (*clearer)(NoteEvent *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(NoteEvent), (Array_clearElement)clearer);
}

static inline void NoteEventAr_insert(NoteEventAr *arr, int index, NoteEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    NoteEvent *p = (NoteEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void NoteEventAr_insertp(NoteEventAr *arr, int index, NoteEvent *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    NoteEvent *p = (NoteEvent *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int NoteEventAr_last(NoteEventAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int NoteEventAr_len(NoteEventAr *arr) {
    return Array_len((Array*)arr);
}

#define NoteEventAr_loop(var) while (NoteEventArFIt_next(&var)) 

static inline NoteEventAr *NoteEventAr_new(int nelems) {
    void (*clearer)(NoteEvent *) = NULL;
    return (NoteEventAr*)Array_new(nelems, sizeof(NoteEvent), (Array_clearElement)clearer);
}

static inline void NoteEventAr_pop(NoteEventAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void NoteEventAr_push(NoteEventAr *arr, NoteEvent elem) {
    NoteEvent *p = (NoteEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void NoteEventAr_pushp(NoteEventAr *arr, NoteEvent *elem) {
    NoteEvent *p = (NoteEvent *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define NoteEventAr_reach(it, arr) for (NoteEvent* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void NoteEventAr_remove(NoteEventAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void NoteEventAr_removeN(NoteEventAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define NoteEventAr_rforeach(var, arr)                for (NoteEventArRIt_declare(var, arr, 0); NoteEventArRIt_next(&var); )
#define NoteEventAr_rforeachOffset(var, arr, offset)  for (NoteEventArRIt_declare(var, arr, offset); NoteEventArRIt_next(&var); )

#define NoteEventAr_rloop(var) while (NoteEventArRIt_next(&var))             

static inline void NoteEventAr_set(NoteEventAr *arr, int index, NoteEvent elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void NoteEventAr_setp(NoteEventAr *arr, int index, NoteEvent *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void NoteEventAr_truncate(NoteEventAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool NoteEventArFIt_atEnd(NoteEventArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define NoteEventArFIt_declare(var, arr, offset)  NoteEventArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define NoteEventArFIt_declare0(var)  NoteEventArFIt var = {0}

static inline bool NoteEventArFIt_next(NoteEventArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool NoteEventArFIt_remove(NoteEventArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool NoteEventArRIt_atEnd(NoteEventArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define NoteEventArRIt_declare(var, arr, offset)  NoteEventArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define NoteEventArRIt_declare0(var)  NoteEventArRIt var = {0}

static inline bool NoteEventArRIt_next(NoteEventArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool NoteEventArRIt_remove(NoteEventArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void NoteEventAr_binInsert(NoteEventAr *arr, NoteEvent elem) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void NoteEventAr_binRemove(NoteEventAr *arr, NoteEvent elem) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline NoteEvent *NoteEventAr_binSearch(NoteEventAr *arr, NoteEvent elem) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
    return (NoteEvent *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline NoteEvent *NoteEventAr_pqPeek(NoteEventAr *arr) {
   return (NoteEvent *)Array_pqPeek((Array*)arr);
}

static inline bool NoteEventAr_pqPop(NoteEventAr *arr, NoteEvent *elem) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void NoteEventAr_pqPush(NoteEventAr *arr, NoteEvent elem) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void NoteEventAr_pqSort(NoteEventAr *arr) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void NoteEventAr_sort(NoteEventAr *arr) {
    int (*compare)(NoteEvent *, NoteEvent *) = NoteEvent_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline TimedOffAr NoteManager_pending(NoteManager *self){return self->pending;}
static inline void NoteManager_setPending(NoteManager *self, TimedOffAr value){self->pending = value;}
static inline IndexedOffAr NoteManager_endgroups(NoteManager *self){return self->endgroups;}
static inline void NoteManager_setEndgroups(NoteManager *self, IndexedOffAr value){self->endgroups = value;}
static inline Port *NoteManager_output(NoteManager *self){return self->output;}
static inline void NoteManager_setOutput(NoteManager *self, Port *value){self->output = value;}
static inline Atom *NoteManager_atoms(NoteManager *self){return self->atoms;}
static inline void NoteManager_setAtoms(NoteManager *self, Atom *value){self->atoms = value;}
static inline AtomAr NoteOutlet_atoms(NoteOutlet *self){return self->atoms;}
static inline void NoteOutlet_setAtoms(NoteOutlet *self, AtomAr value){self->atoms = value;}
static inline Port *NoteOutlet_port(NoteOutlet *self){return self->port;}
static inline void NoteOutlet_setPort(NoteOutlet *self, Port *value){self->port = value;}
static inline NoteOutlet *NoteOutlet_castFromOutlet(Outlet *self) {
    if (self->itype == NoteOutlet_itype) {
        return (NoteOutlet*)self;
    }
    return NULL;
}
static inline Outlet *NoteOutlet_castToOutlet(NoteOutlet *self) {
    return (Outlet*)self;
}
static inline long NoteSequence_version(NoteSequence *self){return self->version;}
static inline void NoteSequence_setVersion(NoteSequence *self, long value){self->version = value;}
static inline Ticks NoteSequence_startTime(NoteSequence *self){return self->startTime;}
static inline void NoteSequence_setStartTime(NoteSequence *self, Ticks value){self->startTime = value;}
static inline Ticks NoteSequence_sequenceLength(NoteSequence *self){return self->sequenceLength;}
static inline void NoteSequence_setSequenceLength(NoteSequence *self, Ticks value){self->sequenceLength = value;}
static inline OutletSpecifier NoteSequence_outletSpecifier(NoteSequence *self){return self->outletSpecifier;}
static inline void NoteSequence_setOutletSpecifier(NoteSequence *self, OutletSpecifier value){self->outletSpecifier = value;}
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
static inline void NoteSequence_setOutlet(NoteSequence *self, Outlet *value){self->outlet = value;}
static inline NoteSequence *NoteSequence_recordingSeq(NoteSequence *self){return self->recordingSeq;}
static inline void NoteSequence_setRecordingSeq(NoteSequence *self, NoteSequence *value){self->recordingSeq = value;}
static inline TimedOffAr NoteSequence_offs(NoteSequence *self){return self->offs;}
static inline void NoteSequence_setOffs(NoteSequence *self, TimedOffAr value){self->offs = value;}
static inline NoteEventAr NoteSequence_events(NoteSequence *self){return self->events;}
static inline void NoteSequence_setEvents(NoteSequence *self, NoteEventAr value){self->events = value;}
static inline NoteSequence *NoteSequence_castFromSequence(Sequence *self) {
    if (self->itype == NoteSequence_itype) {
        return (NoteSequence*)self;
    }
    return NULL;
}
static inline Sequence *NoteSequence_castToSequence(NoteSequence *self) {
    return (Sequence*)self;
}
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
static inline int Outlet_nthIType(int n, int *itype) {
    static int itypes[] = {
        BendOutlet_itype, CcOutlet_itype, NoteOutlet_itype, NullOutlet_itype, VstOutlet_itype
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Outlet_foreachIType(itype) for (int __##itype = 0, itype = 0; Outlet_nthIType(__##itype, &itype); __##itype++)
static inline Symbol *OutletSpecifier_track(OutletSpecifier *self){return self->track;}
static inline void OutletSpecifier_setTrack(OutletSpecifier *self, Symbol *value){self->track = value;}
static inline int OutletSpecifier_pluginIndex(OutletSpecifier *self){return self->pluginIndex;}
static inline void OutletSpecifier_setPluginIndex(OutletSpecifier *self, int value){self->pluginIndex = value;}
static inline Symbol *OutletSpecifier_parameter(OutletSpecifier *self){return self->parameter;}
static inline void OutletSpecifier_setParameter(OutletSpecifier *self, Symbol *value){self->parameter = value;}
static inline int OutletSpecifier_paramIndex(OutletSpecifier *self){return self->paramIndex;}
static inline void OutletSpecifier_setParamIndex(OutletSpecifier *self, int value){self->paramIndex = value;}
static inline Symbol *Pad_trackName(Pad *self){return self->trackName;}
static inline void Pad_setTrackName(Pad *self, Symbol *value){self->trackName = value;}
static inline int Pad_padIndex(Pad *self){return self->padIndex;}
static inline void Pad_setPadIndex(Pad *self, int value){self->padIndex = value;}
static inline Midiseq *Pad_sequence(Pad *self){return self->sequence;}
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
static inline void Pad_setTrack(Pad *self, Track *value){self->track = value;}
static inline bool Pad_useMasterClock(Pad *self){return self->useMasterClock;}
static inline void Pad_setUseMasterClock(Pad *self, bool value){self->useMasterClock = value;}
static inline void PadAr_changeLength(PadAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PadAr_clear(PadAr *arr) {
    Array_clear((Array*)arr);
    PadAr zero = {0};
    *arr = zero;
}

#define PadAr_each(it, arr) for (Pad* it = arr->data; it < arr->data + arr->len; it++)

static inline void PadAr_fit(PadAr *arr) {
    Array_fit((Array*)arr);
}

#define PadAr_foreach(var, arr)                for (PadArFIt_declare(var, arr, 0); PadArFIt_next(&var); )
#define PadAr_foreachOffset(var, arr, offset)  for (PadArFIt_declare(var, arr, offset); PadArFIt_next(&var); )            

static inline void PadAr_free(PadAr *arr) {
    Array_free((Array*)arr);
}

static inline Pad PadAr_get(PadAr *arr, int index, Error *err) {
    Pad v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad *PadAr_getp(PadAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad *)Array_get((Array*)arr, index);
}

static inline void PadAr_init(PadAr *arr, int nelems) {
   void (*clearer)(Pad *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Pad), (Array_clearElement)clearer);
}

static inline void PadAr_insert(PadAr *arr, int index, Pad elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadAr_insertp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad *p = (Pad *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int PadAr_last(PadAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int PadAr_len(PadAr *arr) {
    return Array_len((Array*)arr);
}

#define PadAr_loop(var) while (PadArFIt_next(&var)) 

static inline PadAr *PadAr_new(int nelems) {
    void (*clearer)(Pad *) = NULL;
    return (PadAr*)Array_new(nelems, sizeof(Pad), (Array_clearElement)clearer);
}

static inline void PadAr_pop(PadAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadAr_push(PadAr *arr, Pad elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PadAr_pushp(PadAr *arr, Pad *elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define PadAr_reach(it, arr) for (Pad* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void PadAr_remove(PadAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void PadAr_removeN(PadAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define PadAr_rforeach(var, arr)                for (PadArRIt_declare(var, arr, 0); PadArRIt_next(&var); )
#define PadAr_rforeachOffset(var, arr, offset)  for (PadArRIt_declare(var, arr, offset); PadArRIt_next(&var); )

#define PadAr_rloop(var) while (PadArRIt_next(&var))             

static inline void PadAr_set(PadAr *arr, int index, Pad elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadAr_setp(PadAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadAr_truncate(PadAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool PadArFIt_atEnd(PadArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define PadArFIt_declare(var, arr, offset)  PadArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define PadArFIt_declare0(var)  PadArFIt var = {0}

static inline bool PadArFIt_next(PadArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool PadArFIt_remove(PadArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool PadArRIt_atEnd(PadArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define PadArRIt_declare(var, arr, offset)  PadArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define PadArRIt_declare0(var)  PadArRIt var = {0}

static inline bool PadArRIt_next(PadArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool PadArRIt_remove(PadArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline PadAr *PadList_pads(PadList *self){return &self->pads;}
static inline PadPtrAr *PadList_running(PadList *self){return &self->running;}
static inline void PadPtrAr_changeLength(PadPtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PadPtrAr_clear(PadPtrAr *arr) {
    Array_clear((Array*)arr);
    PadPtrAr zero = {0};
    *arr = zero;
}

#define PadPtrAr_each(it, arr) for (Pad ** it = arr->data; it < arr->data + arr->len; it++)

static inline void PadPtrAr_fit(PadPtrAr *arr) {
    Array_fit((Array*)arr);
}

#define PadPtrAr_foreach(var, arr)                for (PadPtrArFIt_declare(var, arr, 0); PadPtrArFIt_next(&var); )
#define PadPtrAr_foreachOffset(var, arr, offset)  for (PadPtrArFIt_declare(var, arr, offset); PadPtrArFIt_next(&var); )            

static inline void PadPtrAr_free(PadPtrAr *arr) {
    Array_free((Array*)arr);
}

static inline Pad *PadPtrAr_get(PadPtrAr *arr, int index, Error *err) {
    Pad * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Pad **PadPtrAr_getp(PadPtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad **)Array_get((Array*)arr, index);
}

static inline void PadPtrAr_init(PadPtrAr *arr, int nelems) {
   void (*clearer)(Pad **) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Pad *), (Array_clearElement)clearer);
}

static inline void PadPtrAr_insert(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PadPtrAr_insertp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Pad * *p = (Pad **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int PadPtrAr_last(PadPtrAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int PadPtrAr_len(PadPtrAr *arr) {
    return Array_len((Array*)arr);
}

#define PadPtrAr_loop(var) while (PadPtrArFIt_next(&var)) 

static inline PadPtrAr *PadPtrAr_new(int nelems) {
    void (*clearer)(Pad **) = NULL;
    return (PadPtrAr*)Array_new(nelems, sizeof(Pad *), (Array_clearElement)clearer);
}

static inline void PadPtrAr_pop(PadPtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PadPtrAr_push(PadPtrAr *arr, Pad *elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PadPtrAr_pushp(PadPtrAr *arr, Pad **elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define PadPtrAr_reach(it, arr) for (Pad ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void PadPtrAr_remove(PadPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void PadPtrAr_removeN(PadPtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define PadPtrAr_rforeach(var, arr)                for (PadPtrArRIt_declare(var, arr, 0); PadPtrArRIt_next(&var); )
#define PadPtrAr_rforeachOffset(var, arr, offset)  for (PadPtrArRIt_declare(var, arr, offset); PadPtrArRIt_next(&var); )

#define PadPtrAr_rloop(var) while (PadPtrArRIt_next(&var))             

static inline void PadPtrAr_set(PadPtrAr *arr, int index, Pad *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PadPtrAr_setp(PadPtrAr *arr, int index, Pad **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PadPtrAr_truncate(PadPtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool PadPtrArFIt_atEnd(PadPtrArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define PadPtrArFIt_declare(var, arr, offset)  PadPtrArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define PadPtrArFIt_declare0(var)  PadPtrArFIt var = {0}

static inline bool PadPtrArFIt_next(PadPtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool PadPtrArFIt_remove(PadPtrArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool PadPtrArRIt_atEnd(PadPtrArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define PadPtrArRIt_declare(var, arr, offset)  PadPtrArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define PadPtrArRIt_declare0(var)  PadPtrArRIt var = {0}

static inline bool PadPtrArRIt_next(PadPtrArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool PadPtrArRIt_remove(PadPtrArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline MaxObject Port_obj(Port *self){return self->obj;}
static inline void Port_setObj(Port *self, MaxObject value){self->obj = value;}
static inline long Port_inletnum(Port *self){return self->inletnum;}
static inline void Port_setInletnum(Port *self, long value){self->inletnum = value;}
static inline PtrAr Port_proxy(Port *self){return self->proxy;}
static inline void Port_setProxy(Port *self, PtrAr value){self->proxy = value;}
static inline PtrAr Port_outlet(Port *self){return self->outlet;}
static inline void Port_setOutlet(Port *self, PtrAr value){self->outlet = value;}
static inline Symbol *Port_track(Port *self){return self->track;}
static inline void Port_setTrack(Port *self, Symbol *value){self->track = value;}
static inline Symbol *Port_id(Port *self){return self->id;}
static inline void Port_setId(Port *self, Symbol *value){self->id = value;}
static inline long Port_intInlets(Port *self){return self->intInlets;}
static inline void Port_setIntInlets(Port *self, long value){self->intInlets = value;}
static inline long Port_intOutlets(Port *self){return self->intOutlets;}
static inline void Port_setIntOutlets(Port *self, long value){self->intOutlets = value;}
static inline void *Port_hub(Port *self){return self->hub;}
static inline void Port_setHub(Port *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc Port_anythingDispatch(Port *self){return self->anythingDispatch;}
static inline void Port_setAnythingDispatch(Port *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc Port_intDispatch(Port *self){return self->intDispatch;}
static inline void Port_setIntDispatch(Port *self, Port_intDispatchFunc value){self->intDispatch = value;}
static inline PortFindCellAr PortFind_objects(PortFind *self){return self->objects;}
static inline void PortFind_setObjects(PortFind *self, PortFindCellAr value){self->objects = value;}
static inline void *PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
static inline Port *PortFindCell_reciever(PortFindCell *self){return self->reciever;}
static inline void PortFindCell_setReciever(PortFindCell *self, Port *value){self->reciever = value;}
static inline Symbol *PortFindCell_varname(PortFindCell *self){return self->varname;}
static inline void PortFindCell_setVarname(PortFindCell *self, Symbol *value){self->varname = value;}
static inline void PortFindCellAr_changeLength(PortFindCellAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PortFindCellAr_clear(PortFindCellAr *arr) {
    Array_clear((Array*)arr);
    PortFindCellAr zero = {0};
    *arr = zero;
}

#define PortFindCellAr_each(it, arr) for (PortFindCell* it = arr->data; it < arr->data + arr->len; it++)

static inline void PortFindCellAr_fit(PortFindCellAr *arr) {
    Array_fit((Array*)arr);
}

#define PortFindCellAr_foreach(var, arr)                for (PortFindCellArFIt_declare(var, arr, 0); PortFindCellArFIt_next(&var); )
#define PortFindCellAr_foreachOffset(var, arr, offset)  for (PortFindCellArFIt_declare(var, arr, offset); PortFindCellArFIt_next(&var); )            

static inline void PortFindCellAr_free(PortFindCellAr *arr) {
    Array_free((Array*)arr);
}

static inline PortFindCell PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err) {
    PortFindCell v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline PortFindCell *PortFindCellAr_getp(PortFindCellAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (PortFindCell *)Array_get((Array*)arr, index);
}

static inline void PortFindCellAr_init(PortFindCellAr *arr, int nelems) {
   void (*clearer)(PortFindCell *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(PortFindCell), (Array_clearElement)clearer);
}

static inline void PortFindCellAr_insert(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PortFindCellAr_insertp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    PortFindCell *p = (PortFindCell *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int PortFindCellAr_last(PortFindCellAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int PortFindCellAr_len(PortFindCellAr *arr) {
    return Array_len((Array*)arr);
}

#define PortFindCellAr_loop(var) while (PortFindCellArFIt_next(&var)) 

static inline PortFindCellAr *PortFindCellAr_new(int nelems) {
    void (*clearer)(PortFindCell *) = NULL;
    return (PortFindCellAr*)Array_new(nelems, sizeof(PortFindCell), (Array_clearElement)clearer);
}

static inline void PortFindCellAr_pop(PortFindCellAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PortFindCellAr_pushp(PortFindCellAr *arr, PortFindCell *elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define PortFindCellAr_reach(it, arr) for (PortFindCell* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void PortFindCellAr_remove(PortFindCellAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void PortFindCellAr_removeN(PortFindCellAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define PortFindCellAr_rforeach(var, arr)                for (PortFindCellArRIt_declare(var, arr, 0); PortFindCellArRIt_next(&var); )
#define PortFindCellAr_rforeachOffset(var, arr, offset)  for (PortFindCellArRIt_declare(var, arr, offset); PortFindCellArRIt_next(&var); )

#define PortFindCellAr_rloop(var) while (PortFindCellArRIt_next(&var))             

static inline void PortFindCellAr_set(PortFindCellAr *arr, int index, PortFindCell elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PortFindCellAr_setp(PortFindCellAr *arr, int index, PortFindCell *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PortFindCellAr_truncate(PortFindCellAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool PortFindCellArFIt_atEnd(PortFindCellArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define PortFindCellArFIt_declare(var, arr, offset)  PortFindCellArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define PortFindCellArFIt_declare0(var)  PortFindCellArFIt var = {0}

static inline bool PortFindCellArFIt_next(PortFindCellArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool PortFindCellArFIt_remove(PortFindCellArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool PortFindCellArRIt_atEnd(PortFindCellArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define PortFindCellArRIt_declare(var, arr, offset)  PortFindCellArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define PortFindCellArRIt_declare0(var)  PortFindCellArRIt var = {0}

static inline bool PortFindCellArRIt_next(PortFindCellArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool PortFindCellArRIt_remove(PortFindCellArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline Port *PortRef_port(PortRef *self){return self->port;}
static inline void PortRef_setPort(PortRef *self, Port *value){self->port = value;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}
static inline void PortRef_setOutlet(PortRef *self, int value){self->outlet = value;}
static inline void PtrAr_changeLength(PtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PtrAr_clear(PtrAr *arr) {
    Array_clear((Array*)arr);
    PtrAr zero = {0};
    *arr = zero;
}

#define PtrAr_each(it, arr) for (void ** it = arr->data; it < arr->data + arr->len; it++)

static inline void PtrAr_fit(PtrAr *arr) {
    Array_fit((Array*)arr);
}

#define PtrAr_foreach(var, arr)                for (PtrArFIt_declare(var, arr, 0); PtrArFIt_next(&var); )
#define PtrAr_foreachOffset(var, arr, offset)  for (PtrArFIt_declare(var, arr, offset); PtrArFIt_next(&var); )            

static inline void PtrAr_free(PtrAr *arr) {
    Array_free((Array*)arr);
}

static inline void *PtrAr_get(PtrAr *arr, int index, Error *err) {
    void * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void **PtrAr_getp(PtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (void **)Array_get((Array*)arr, index);
}

static inline void PtrAr_init(PtrAr *arr, int nelems) {
   void (*clearer)(void **) = NULL;
    Array_init((Array*)arr, nelems, sizeof(void *), (Array_clearElement)clearer);
}

static inline void PtrAr_insert(PtrAr *arr, int index, void *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    void * *p = (void **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void PtrAr_insertp(PtrAr *arr, int index, void **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    void * *p = (void **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int PtrAr_last(PtrAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int PtrAr_len(PtrAr *arr) {
    return Array_len((Array*)arr);
}

#define PtrAr_loop(var) while (PtrArFIt_next(&var)) 

static inline PtrAr *PtrAr_new(int nelems) {
    void (*clearer)(void **) = NULL;
    return (PtrAr*)Array_new(nelems, sizeof(void *), (Array_clearElement)clearer);
}

static inline void PtrAr_pop(PtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void PtrAr_push(PtrAr *arr, void *elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PtrAr_pushp(PtrAr *arr, void **elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define PtrAr_reach(it, arr) for (void ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void PtrAr_remove(PtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void PtrAr_removeN(PtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define PtrAr_rforeach(var, arr)                for (PtrArRIt_declare(var, arr, 0); PtrArRIt_next(&var); )
#define PtrAr_rforeachOffset(var, arr, offset)  for (PtrArRIt_declare(var, arr, offset); PtrArRIt_next(&var); )

#define PtrAr_rloop(var) while (PtrArRIt_next(&var))             

static inline void PtrAr_set(PtrAr *arr, int index, void *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void PtrAr_setp(PtrAr *arr, int index, void **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void PtrAr_truncate(PtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool PtrArFIt_atEnd(PtrArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define PtrArFIt_declare(var, arr, offset)  PtrArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define PtrArFIt_declare0(var)  PtrArFIt var = {0}

static inline bool PtrArFIt_next(PtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool PtrArFIt_remove(PtrArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool PtrArRIt_atEnd(PtrArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define PtrArRIt_declare(var, arr, offset)  PtrArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define PtrArRIt_declare0(var)  PtrArRIt var = {0}

static inline bool PtrArRIt_next(PtrArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool PtrArRIt_remove(PtrArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline Ticks RecordBuffer_recordStart(RecordBuffer *self){return self->recordStart;}
static inline void RecordBuffer_setRecordStart(RecordBuffer *self, Ticks value){self->recordStart = value;}
static inline SequenceAr RecordBuffer_sequences(RecordBuffer *self){return self->sequences;}
static inline void RecordBuffer_setSequences(RecordBuffer *self, SequenceAr value){self->sequences = value;}
static inline SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == SelectNextPushedPadDispatch_itype) {
        return (SelectNextPushedPadDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *SelectNextPushedPadDispatch_castToDispatch(SelectNextPushedPadDispatch *self) {
    return (Dispatch*)self;
}
static inline int Sequence_nthIType(int n, int *itype) {
    static int itypes[] = {
        FloatSequence_itype, NoteSequence_itype
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Sequence_foreachIType(itype) for (int __##itype = 0, itype = 0; Sequence_nthIType(__##itype, &itype); __##itype++)
static inline long Sequence_version(Sequence *self){return self->version;}
static inline void Sequence_setVersion(Sequence *self, long value){self->version = value;}
static inline void SequenceAr_changeLength(SequenceAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void SequenceAr_clear(SequenceAr *arr) {
    Array_clear((Array*)arr);
    SequenceAr zero = {0};
    *arr = zero;
}

#define SequenceAr_each(it, arr) for (Sequence ** it = arr->data; it < arr->data + arr->len; it++)

static inline void SequenceAr_fit(SequenceAr *arr) {
    Array_fit((Array*)arr);
}

#define SequenceAr_foreach(var, arr)                for (SequenceArFIt_declare(var, arr, 0); SequenceArFIt_next(&var); )
#define SequenceAr_foreachOffset(var, arr, offset)  for (SequenceArFIt_declare(var, arr, offset); SequenceArFIt_next(&var); )            

static inline void SequenceAr_free(SequenceAr *arr) {
    Array_free((Array*)arr);
}

static inline Sequence *SequenceAr_get(SequenceAr *arr, int index, Error *err) {
    Sequence * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Sequence **SequenceAr_getp(SequenceAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Sequence **)Array_get((Array*)arr, index);
}

static inline void SequenceAr_init(SequenceAr *arr, int nelems) {
   void (*clearer)(Sequence **) = Sequence_freePpErrless;
    Array_init((Array*)arr, nelems, sizeof(Sequence *), (Array_clearElement)clearer);
}

static inline void SequenceAr_insert(SequenceAr *arr, int index, Sequence *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Sequence * *p = (Sequence **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void SequenceAr_insertp(SequenceAr *arr, int index, Sequence **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Sequence * *p = (Sequence **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int SequenceAr_last(SequenceAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int SequenceAr_len(SequenceAr *arr) {
    return Array_len((Array*)arr);
}

#define SequenceAr_loop(var) while (SequenceArFIt_next(&var)) 

static inline SequenceAr *SequenceAr_new(int nelems) {
    void (*clearer)(Sequence **) = Sequence_freePpErrless;
    return (SequenceAr*)Array_new(nelems, sizeof(Sequence *), (Array_clearElement)clearer);
}

static inline void SequenceAr_pop(SequenceAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void SequenceAr_push(SequenceAr *arr, Sequence *elem) {
    Sequence * *p = (Sequence **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void SequenceAr_pushp(SequenceAr *arr, Sequence **elem) {
    Sequence * *p = (Sequence **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define SequenceAr_reach(it, arr) for (Sequence ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void SequenceAr_remove(SequenceAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void SequenceAr_removeN(SequenceAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define SequenceAr_rforeach(var, arr)                for (SequenceArRIt_declare(var, arr, 0); SequenceArRIt_next(&var); )
#define SequenceAr_rforeachOffset(var, arr, offset)  for (SequenceArRIt_declare(var, arr, offset); SequenceArRIt_next(&var); )

#define SequenceAr_rloop(var) while (SequenceArRIt_next(&var))             

static inline void SequenceAr_set(SequenceAr *arr, int index, Sequence *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void SequenceAr_setp(SequenceAr *arr, int index, Sequence **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void SequenceAr_truncate(SequenceAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool SequenceArFIt_atEnd(SequenceArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define SequenceArFIt_declare(var, arr, offset)  SequenceArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define SequenceArFIt_declare0(var)  SequenceArFIt var = {0}

static inline bool SequenceArFIt_next(SequenceArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool SequenceArFIt_remove(SequenceArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool SequenceArRIt_atEnd(SequenceArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define SequenceArRIt_declare(var, arr, offset)  SequenceArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define SequenceArRIt_declare0(var)  SequenceArRIt var = {0}

static inline bool SequenceArRIt_next(SequenceArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool SequenceArRIt_remove(SequenceArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void SequenceAr_binInsert(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void SequenceAr_binRemove(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Sequence **SequenceAr_binSearch(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
    return (Sequence **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline Sequence **SequenceAr_pqPeek(SequenceAr *arr) {
   return (Sequence **)Array_pqPeek((Array*)arr);
}

static inline bool SequenceAr_pqPop(SequenceAr *arr, Sequence **elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void SequenceAr_pqPush(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void SequenceAr_pqSort(SequenceAr *arr) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void SequenceAr_sort(SequenceAr *arr) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void SequenceAr_binInsertPointer(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void SequenceAr_binRemovePointer(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Sequence **SequenceAr_binSearchPointer(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
    return (Sequence **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline Sequence **SequenceAr_pqPeekPointer(SequenceAr *arr) {
   return (Sequence **)Array_pqPeek((Array*)arr);
}

static inline bool SequenceAr_pqPopPointer(SequenceAr *arr, Sequence **elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void SequenceAr_pqPushPointer(SequenceAr *arr, Sequence *elem) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void SequenceAr_pqSortPointer(SequenceAr *arr) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void SequenceAr_sortPointer(SequenceAr *arr) {
    int (*compare)(Sequence **, Sequence **) = Sequence_cmpPointerPp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void StringPtAr_changeLength(StringPtAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void StringPtAr_clear(StringPtAr *arr) {
    Array_clear((Array*)arr);
    StringPtAr zero = {0};
    *arr = zero;
}

#define StringPtAr_each(it, arr) for (String ** it = arr->data; it < arr->data + arr->len; it++)

static inline void StringPtAr_fit(StringPtAr *arr) {
    Array_fit((Array*)arr);
}

#define StringPtAr_foreach(var, arr)                for (StringPtArFIt_declare(var, arr, 0); StringPtArFIt_next(&var); )
#define StringPtAr_foreachOffset(var, arr, offset)  for (StringPtArFIt_declare(var, arr, offset); StringPtArFIt_next(&var); )            

static inline void StringPtAr_free(StringPtAr *arr) {
    Array_free((Array*)arr);
}

static inline String *StringPtAr_get(StringPtAr *arr, int index, Error *err) {
    String * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline String **StringPtAr_getp(StringPtAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (String **)Array_get((Array*)arr, index);
}

static inline void StringPtAr_init(StringPtAr *arr, int nelems) {
   void (*clearer)(String **) = String_freep;
    Array_init((Array*)arr, nelems, sizeof(String *), (Array_clearElement)clearer);
}

static inline void StringPtAr_insert(StringPtAr *arr, int index, String *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    String * *p = (String **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void StringPtAr_insertp(StringPtAr *arr, int index, String **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    String * *p = (String **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int StringPtAr_last(StringPtAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int StringPtAr_len(StringPtAr *arr) {
    return Array_len((Array*)arr);
}

#define StringPtAr_loop(var) while (StringPtArFIt_next(&var)) 

static inline StringPtAr *StringPtAr_new(int nelems) {
    void (*clearer)(String **) = String_freep;
    return (StringPtAr*)Array_new(nelems, sizeof(String *), (Array_clearElement)clearer);
}

static inline void StringPtAr_pop(StringPtAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void StringPtAr_push(StringPtAr *arr, String *elem) {
    String * *p = (String **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void StringPtAr_pushp(StringPtAr *arr, String **elem) {
    String * *p = (String **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define StringPtAr_reach(it, arr) for (String ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void StringPtAr_remove(StringPtAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void StringPtAr_removeN(StringPtAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define StringPtAr_rforeach(var, arr)                for (StringPtArRIt_declare(var, arr, 0); StringPtArRIt_next(&var); )
#define StringPtAr_rforeachOffset(var, arr, offset)  for (StringPtArRIt_declare(var, arr, offset); StringPtArRIt_next(&var); )

#define StringPtAr_rloop(var) while (StringPtArRIt_next(&var))             

static inline void StringPtAr_set(StringPtAr *arr, int index, String *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void StringPtAr_setp(StringPtAr *arr, int index, String **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void StringPtAr_truncate(StringPtAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool StringPtArFIt_atEnd(StringPtArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define StringPtArFIt_declare(var, arr, offset)  StringPtArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define StringPtArFIt_declare0(var)  StringPtArFIt var = {0}

static inline bool StringPtArFIt_next(StringPtArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool StringPtArFIt_remove(StringPtArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool StringPtArRIt_atEnd(StringPtArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define StringPtArRIt_declare(var, arr, offset)  StringPtArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define StringPtArRIt_declare0(var)  StringPtArRIt var = {0}

static inline bool StringPtArRIt_next(StringPtArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool StringPtArRIt_remove(StringPtArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void SymbolPtAr_changeLength(SymbolPtAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void SymbolPtAr_clear(SymbolPtAr *arr) {
    Array_clear((Array*)arr);
    SymbolPtAr zero = {0};
    *arr = zero;
}

#define SymbolPtAr_each(it, arr) for (Symbol ** it = arr->data; it < arr->data + arr->len; it++)

static inline void SymbolPtAr_fit(SymbolPtAr *arr) {
    Array_fit((Array*)arr);
}

#define SymbolPtAr_foreach(var, arr)                for (SymbolPtArFIt_declare(var, arr, 0); SymbolPtArFIt_next(&var); )
#define SymbolPtAr_foreachOffset(var, arr, offset)  for (SymbolPtArFIt_declare(var, arr, offset); SymbolPtArFIt_next(&var); )            

static inline void SymbolPtAr_free(SymbolPtAr *arr) {
    Array_free((Array*)arr);
}

static inline Symbol *SymbolPtAr_get(SymbolPtAr *arr, int index, Error *err) {
    Symbol * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Symbol **SymbolPtAr_getp(SymbolPtAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Symbol **)Array_get((Array*)arr, index);
}

static inline void SymbolPtAr_init(SymbolPtAr *arr, int nelems) {
   void (*clearer)(Symbol **) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Symbol *), (Array_clearElement)clearer);
}

static inline void SymbolPtAr_insert(SymbolPtAr *arr, int index, Symbol *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void SymbolPtAr_insertp(SymbolPtAr *arr, int index, Symbol **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int SymbolPtAr_last(SymbolPtAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int SymbolPtAr_len(SymbolPtAr *arr) {
    return Array_len((Array*)arr);
}

#define SymbolPtAr_loop(var) while (SymbolPtArFIt_next(&var)) 

static inline SymbolPtAr *SymbolPtAr_new(int nelems) {
    void (*clearer)(Symbol **) = NULL;
    return (SymbolPtAr*)Array_new(nelems, sizeof(Symbol *), (Array_clearElement)clearer);
}

static inline void SymbolPtAr_pop(SymbolPtAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void SymbolPtAr_push(SymbolPtAr *arr, Symbol *elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void SymbolPtAr_pushp(SymbolPtAr *arr, Symbol **elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define SymbolPtAr_reach(it, arr) for (Symbol ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void SymbolPtAr_remove(SymbolPtAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void SymbolPtAr_removeN(SymbolPtAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define SymbolPtAr_rforeach(var, arr)                for (SymbolPtArRIt_declare(var, arr, 0); SymbolPtArRIt_next(&var); )
#define SymbolPtAr_rforeachOffset(var, arr, offset)  for (SymbolPtArRIt_declare(var, arr, offset); SymbolPtArRIt_next(&var); )

#define SymbolPtAr_rloop(var) while (SymbolPtArRIt_next(&var))             

static inline void SymbolPtAr_set(SymbolPtAr *arr, int index, Symbol *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void SymbolPtAr_setp(SymbolPtAr *arr, int index, Symbol **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void SymbolPtAr_truncate(SymbolPtAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool SymbolPtArFIt_atEnd(SymbolPtArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define SymbolPtArFIt_declare(var, arr, offset)  SymbolPtArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define SymbolPtArFIt_declare0(var)  SymbolPtArFIt var = {0}

static inline bool SymbolPtArFIt_next(SymbolPtArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool SymbolPtArFIt_remove(SymbolPtArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool SymbolPtArRIt_atEnd(SymbolPtArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define SymbolPtArRIt_declare(var, arr, offset)  SymbolPtArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define SymbolPtArRIt_declare0(var)  SymbolPtArRIt var = {0}

static inline bool SymbolPtArRIt_next(SymbolPtArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool SymbolPtArRIt_remove(SymbolPtArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void SymbolPtAr_binInsertUnderlying(SymbolPtAr *arr, Symbol *elem) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void SymbolPtAr_binRemoveUnderlying(SymbolPtAr *arr, Symbol *elem) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Symbol **SymbolPtAr_binSearchUnderlying(SymbolPtAr *arr, Symbol *elem) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
    return (Symbol **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline Symbol **SymbolPtAr_pqPeekUnderlying(SymbolPtAr *arr) {
   return (Symbol **)Array_pqPeek((Array*)arr);
}

static inline bool SymbolPtAr_pqPopUnderlying(SymbolPtAr *arr, Symbol **elem) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void SymbolPtAr_pqPushUnderlying(SymbolPtAr *arr, Symbol *elem) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void SymbolPtAr_pqSortUnderlying(SymbolPtAr *arr) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void SymbolPtAr_sortUnderlying(SymbolPtAr *arr) {
    int (*compare)(Symbol **, Symbol **) = Symbol_cmpUnderlying;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void SymbolPtrAr_changeLength(SymbolPtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void SymbolPtrAr_clear(SymbolPtrAr *arr) {
    Array_clear((Array*)arr);
    SymbolPtrAr zero = {0};
    *arr = zero;
}

#define SymbolPtrAr_each(it, arr) for (Symbol ** it = arr->data; it < arr->data + arr->len; it++)

static inline void SymbolPtrAr_fit(SymbolPtrAr *arr) {
    Array_fit((Array*)arr);
}

#define SymbolPtrAr_foreach(var, arr)                for (SymbolPtrArFIt_declare(var, arr, 0); SymbolPtrArFIt_next(&var); )
#define SymbolPtrAr_foreachOffset(var, arr, offset)  for (SymbolPtrArFIt_declare(var, arr, offset); SymbolPtrArFIt_next(&var); )            

static inline void SymbolPtrAr_free(SymbolPtrAr *arr) {
    Array_free((Array*)arr);
}

static inline Symbol *SymbolPtrAr_get(SymbolPtrAr *arr, int index, Error *err) {
    Symbol * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Symbol **SymbolPtrAr_getp(SymbolPtrAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Symbol **)Array_get((Array*)arr, index);
}

static inline void SymbolPtrAr_init(SymbolPtrAr *arr, int nelems) {
   void (*clearer)(Symbol **) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Symbol *), (Array_clearElement)clearer);
}

static inline void SymbolPtrAr_insert(SymbolPtrAr *arr, int index, Symbol *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void SymbolPtrAr_insertp(SymbolPtrAr *arr, int index, Symbol **elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Symbol * *p = (Symbol **)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int SymbolPtrAr_last(SymbolPtrAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int SymbolPtrAr_len(SymbolPtrAr *arr) {
    return Array_len((Array*)arr);
}

#define SymbolPtrAr_loop(var) while (SymbolPtrArFIt_next(&var)) 

static inline SymbolPtrAr *SymbolPtrAr_new(int nelems) {
    void (*clearer)(Symbol **) = NULL;
    return (SymbolPtrAr*)Array_new(nelems, sizeof(Symbol *), (Array_clearElement)clearer);
}

static inline void SymbolPtrAr_pop(SymbolPtrAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void SymbolPtrAr_push(SymbolPtrAr *arr, Symbol *elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void SymbolPtrAr_pushp(SymbolPtrAr *arr, Symbol **elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define SymbolPtrAr_reach(it, arr) for (Symbol ** it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void SymbolPtrAr_remove(SymbolPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void SymbolPtrAr_removeN(SymbolPtrAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define SymbolPtrAr_rforeach(var, arr)                for (SymbolPtrArRIt_declare(var, arr, 0); SymbolPtrArRIt_next(&var); )
#define SymbolPtrAr_rforeachOffset(var, arr, offset)  for (SymbolPtrArRIt_declare(var, arr, offset); SymbolPtrArRIt_next(&var); )

#define SymbolPtrAr_rloop(var) while (SymbolPtrArRIt_next(&var))             

static inline void SymbolPtrAr_set(SymbolPtrAr *arr, int index, Symbol *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void SymbolPtrAr_setp(SymbolPtrAr *arr, int index, Symbol **elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void SymbolPtrAr_truncate(SymbolPtrAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool SymbolPtrArFIt_atEnd(SymbolPtrArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define SymbolPtrArFIt_declare(var, arr, offset)  SymbolPtrArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define SymbolPtrArFIt_declare0(var)  SymbolPtrArFIt var = {0}

static inline bool SymbolPtrArFIt_next(SymbolPtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool SymbolPtrArFIt_remove(SymbolPtrArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool SymbolPtrArRIt_atEnd(SymbolPtrArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define SymbolPtrArRIt_declare(var, arr, offset)  SymbolPtrArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define SymbolPtrArRIt_declare0(var)  SymbolPtrArRIt var = {0}

static inline bool SymbolPtrArRIt_next(SymbolPtrArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool SymbolPtrArRIt_remove(SymbolPtrArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline Ticks Timed_time(Timed *self){return self->time;}
static inline void Timed_setTime(Timed *self, Ticks value){self->time = value;}
static inline int Timed_version(Timed *self){return self->version;}
static inline void Timed_setVersion(Timed *self, int value){self->version = value;}
static inline Sequence *Timed_sequence(Timed *self){return self->sequence;}
static inline void Timed_setSequence(Timed *self, Sequence *value){self->sequence = value;}
static inline Ticks TimedOff_time(TimedOff *self){return self->time;}
static inline void TimedOff_setTime(TimedOff *self, Ticks value){self->time = value;}
static inline int TimedOff_pitch(TimedOff *self){return self->pitch;}
static inline void TimedOff_setPitch(TimedOff *self, int value){self->pitch = value;}
#define TimedOff_declare(name, time, pitch) TimedOff name = {(time), (pitch)}
static inline void TimedOffAr_changeLength(TimedOffAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void TimedOffAr_clear(TimedOffAr *arr) {
    Array_clear((Array*)arr);
    TimedOffAr zero = {0};
    *arr = zero;
}

#define TimedOffAr_each(it, arr) for (TimedOff* it = arr->data; it < arr->data + arr->len; it++)

static inline void TimedOffAr_fit(TimedOffAr *arr) {
    Array_fit((Array*)arr);
}

#define TimedOffAr_foreach(var, arr)                for (TimedOffArFIt_declare(var, arr, 0); TimedOffArFIt_next(&var); )
#define TimedOffAr_foreachOffset(var, arr, offset)  for (TimedOffArFIt_declare(var, arr, offset); TimedOffArFIt_next(&var); )            

static inline void TimedOffAr_free(TimedOffAr *arr) {
    Array_free((Array*)arr);
}

static inline TimedOff TimedOffAr_get(TimedOffAr *arr, int index, Error *err) {
    TimedOff v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline TimedOff *TimedOffAr_getp(TimedOffAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (TimedOff *)Array_get((Array*)arr, index);
}

static inline void TimedOffAr_init(TimedOffAr *arr, int nelems) {
   void (*clearer)(TimedOff *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(TimedOff), (Array_clearElement)clearer);
}

static inline void TimedOffAr_insert(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TimedOffAr_insertp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    TimedOff *p = (TimedOff *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int TimedOffAr_last(TimedOffAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int TimedOffAr_len(TimedOffAr *arr) {
    return Array_len((Array*)arr);
}

#define TimedOffAr_loop(var) while (TimedOffArFIt_next(&var)) 

static inline TimedOffAr *TimedOffAr_new(int nelems) {
    void (*clearer)(TimedOff *) = NULL;
    return (TimedOffAr*)Array_new(nelems, sizeof(TimedOff), (Array_clearElement)clearer);
}

static inline void TimedOffAr_pop(TimedOffAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TimedOffAr_push(TimedOffAr *arr, TimedOff elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void TimedOffAr_pushp(TimedOffAr *arr, TimedOff *elem) {
    TimedOff *p = (TimedOff *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define TimedOffAr_reach(it, arr) for (TimedOff* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void TimedOffAr_removeN(TimedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define TimedOffAr_rforeach(var, arr)                for (TimedOffArRIt_declare(var, arr, 0); TimedOffArRIt_next(&var); )
#define TimedOffAr_rforeachOffset(var, arr, offset)  for (TimedOffArRIt_declare(var, arr, offset); TimedOffArRIt_next(&var); )

#define TimedOffAr_rloop(var) while (TimedOffArRIt_next(&var))             

static inline void TimedOffAr_set(TimedOffAr *arr, int index, TimedOff elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TimedOffAr_setp(TimedOffAr *arr, int index, TimedOff *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TimedOffAr_truncate(TimedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool TimedOffArFIt_atEnd(TimedOffArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define TimedOffArFIt_declare(var, arr, offset)  TimedOffArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define TimedOffArFIt_declare0(var)  TimedOffArFIt var = {0}

static inline bool TimedOffArFIt_next(TimedOffArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool TimedOffArFIt_remove(TimedOffArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool TimedOffArRIt_atEnd(TimedOffArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define TimedOffArRIt_declare(var, arr, offset)  TimedOffArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define TimedOffArRIt_declare0(var)  TimedOffArRIt var = {0}

static inline bool TimedOffArRIt_next(TimedOffArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool TimedOffArRIt_remove(TimedOffArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}            

static inline void TimedOffAr_binRemoveTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, true);
}        

static inline TimedOffArFIt TimedOffAr_binSearchTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    TimedOffArFIt it = {0};
   if (Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, (ArrayFIt*)&it) != NULL) {
       return it;
    }
   it.index  = arr->len;
   it.uBound = 0;
    return it;
}

static inline TimedOff *TimedOffAr_pqPeekTime(TimedOffAr *arr) {
   return (TimedOff *)Array_pqPeek((Array*)arr);
}

static inline bool TimedOffAr_pqPopTime(TimedOffAr *arr, TimedOff *elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void TimedOffAr_pqPushTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void TimedOffAr_pqSortTime(TimedOffAr *arr) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void TimedOffAr_sortTime(TimedOffAr *arr) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void TimedPq_changeLength(TimedPq *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void TimedPq_clear(TimedPq *arr) {
    Array_clear((Array*)arr);
    TimedPq zero = {0};
    *arr = zero;
}

#define TimedPq_each(it, arr) for (Timed* it = arr->data; it < arr->data + arr->len; it++)

static inline void TimedPq_fit(TimedPq *arr) {
    Array_fit((Array*)arr);
}

#define TimedPq_foreach(var, arr)                for (TimedPqFIt_declare(var, arr, 0); TimedPqFIt_next(&var); )
#define TimedPq_foreachOffset(var, arr, offset)  for (TimedPqFIt_declare(var, arr, offset); TimedPqFIt_next(&var); )            

static inline void TimedPq_free(TimedPq *arr) {
    Array_free((Array*)arr);
}

static inline Timed TimedPq_get(TimedPq *arr, int index, Error *err) {
    Timed v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Timed *TimedPq_getp(TimedPq *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Timed *)Array_get((Array*)arr, index);
}

static inline void TimedPq_init(TimedPq *arr, int nelems) {
   void (*clearer)(Timed *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Timed), (Array_clearElement)clearer);
}

static inline void TimedPq_insert(TimedPq *arr, int index, Timed elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Timed *p = (Timed *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TimedPq_insertp(TimedPq *arr, int index, Timed *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Timed *p = (Timed *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int TimedPq_last(TimedPq *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int TimedPq_len(TimedPq *arr) {
    return Array_len((Array*)arr);
}

#define TimedPq_loop(var) while (TimedPqFIt_next(&var)) 

static inline TimedPq *TimedPq_new(int nelems) {
    void (*clearer)(Timed *) = NULL;
    return (TimedPq*)Array_new(nelems, sizeof(Timed), (Array_clearElement)clearer);
}

static inline void TimedPq_pop(TimedPq *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TimedPq_push(TimedPq *arr, Timed elem) {
    Timed *p = (Timed *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void TimedPq_pushp(TimedPq *arr, Timed *elem) {
    Timed *p = (Timed *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define TimedPq_reach(it, arr) for (Timed* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void TimedPq_remove(TimedPq *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void TimedPq_removeN(TimedPq *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define TimedPq_rforeach(var, arr)                for (TimedPqRIt_declare(var, arr, 0); TimedPqRIt_next(&var); )
#define TimedPq_rforeachOffset(var, arr, offset)  for (TimedPqRIt_declare(var, arr, offset); TimedPqRIt_next(&var); )

#define TimedPq_rloop(var) while (TimedPqRIt_next(&var))             

static inline void TimedPq_set(TimedPq *arr, int index, Timed elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TimedPq_setp(TimedPq *arr, int index, Timed *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TimedPq_truncate(TimedPq *arr) {
    Array_truncate((Array*)arr);
}

static inline bool TimedPqFIt_atEnd(TimedPqFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define TimedPqFIt_declare(var, arr, offset)  TimedPqFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define TimedPqFIt_declare0(var)  TimedPqFIt var = {0}

static inline bool TimedPqFIt_next(TimedPqFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool TimedPqFIt_remove(TimedPqFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool TimedPqRIt_atEnd(TimedPqRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define TimedPqRIt_declare(var, arr, offset)  TimedPqRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define TimedPqRIt_declare0(var)  TimedPqRIt var = {0}

static inline bool TimedPqRIt_next(TimedPqRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool TimedPqRIt_remove(TimedPqRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void TimedPq_binInsert(TimedPq *arr, Timed elem) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void TimedPq_binRemove(TimedPq *arr, Timed elem) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline Timed *TimedPq_binSearch(TimedPq *arr, Timed elem) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
    return (Timed *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline Timed *TimedPq_pqPeek(TimedPq *arr) {
   return (Timed *)Array_pqPeek((Array*)arr);
}

static inline bool TimedPq_pqPop(TimedPq *arr, Timed *elem) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void TimedPq_pqPush(TimedPq *arr, Timed elem) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void TimedPq_pqSort(TimedPq *arr) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void TimedPq_sort(TimedPq *arr) {
    int (*compare)(Timed *, Timed *) = Timed_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline Symbol *Track_name(Track *self){return self->name;}
static inline void Track_setName(Track *self, Symbol *value){self->name = value;}
static inline NoteManager *Track_noteManager(Track *self){return self->noteManager;}
static inline void Track_setNoteManager(Track *self, NoteManager *value){self->noteManager = value;}
static inline void TrackAr_changeLength(TrackAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void TrackAr_clear(TrackAr *arr) {
    Array_clear((Array*)arr);
    TrackAr zero = {0};
    *arr = zero;
}

#define TrackAr_each(it, arr) for (Track* it = arr->data; it < arr->data + arr->len; it++)

static inline void TrackAr_fit(TrackAr *arr) {
    Array_fit((Array*)arr);
}

#define TrackAr_foreach(var, arr)                for (TrackArFIt_declare(var, arr, 0); TrackArFIt_next(&var); )
#define TrackAr_foreachOffset(var, arr, offset)  for (TrackArFIt_declare(var, arr, offset); TrackArFIt_next(&var); )            

static inline void TrackAr_free(TrackAr *arr) {
    Array_free((Array*)arr);
}

static inline Track TrackAr_get(TrackAr *arr, int index, Error *err) {
    Track v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline Track *TrackAr_getp(TrackAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Track *)Array_get((Array*)arr, index);
}

static inline void TrackAr_init(TrackAr *arr, int nelems) {
   void (*clearer)(Track *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(Track), (Array_clearElement)clearer);
}

static inline void TrackAr_insert(TrackAr *arr, int index, Track elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void TrackAr_insertp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    Track *p = (Track *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int TrackAr_last(TrackAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int TrackAr_len(TrackAr *arr) {
    return Array_len((Array*)arr);
}

#define TrackAr_loop(var) while (TrackArFIt_next(&var)) 

static inline TrackAr *TrackAr_new(int nelems) {
    void (*clearer)(Track *) = NULL;
    return (TrackAr*)Array_new(nelems, sizeof(Track), (Array_clearElement)clearer);
}

static inline void TrackAr_pop(TrackAr *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void TrackAr_push(TrackAr *arr, Track elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void TrackAr_pushp(TrackAr *arr, Track *elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define TrackAr_reach(it, arr) for (Track* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void TrackAr_remove(TrackAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void TrackAr_removeN(TrackAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define TrackAr_rforeach(var, arr)                for (TrackArRIt_declare(var, arr, 0); TrackArRIt_next(&var); )
#define TrackAr_rforeachOffset(var, arr, offset)  for (TrackArRIt_declare(var, arr, offset); TrackArRIt_next(&var); )

#define TrackAr_rloop(var) while (TrackArRIt_next(&var))             

static inline void TrackAr_set(TrackAr *arr, int index, Track elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void TrackAr_setp(TrackAr *arr, int index, Track *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void TrackAr_truncate(TrackAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool TrackArFIt_atEnd(TrackArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define TrackArFIt_declare(var, arr, offset)  TrackArFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define TrackArFIt_declare0(var)  TrackArFIt var = {0}

static inline bool TrackArFIt_next(TrackArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool TrackArFIt_remove(TrackArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool TrackArRIt_atEnd(TrackArRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define TrackArRIt_declare(var, arr, offset)  TrackArRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define TrackArRIt_declare0(var)  TrackArRIt var = {0}

static inline bool TrackArRIt_next(TrackArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool TrackArRIt_remove(TrackArRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline TrackAr *TrackList_list(TrackList *self){return &self->list;}
static inline AtomAr VstOutlet_atoms(VstOutlet *self){return self->atoms;}
static inline void VstOutlet_setAtoms(VstOutlet *self, AtomAr value){self->atoms = value;}
static inline Port *VstOutlet_port(VstOutlet *self){return self->port;}
static inline void VstOutlet_setPort(VstOutlet *self, Port *value){self->port = value;}
static inline VstOutlet *VstOutlet_castFromOutlet(Outlet *self) {
    if (self->itype == VstOutlet_itype) {
        return (VstOutlet*)self;
    }
    return NULL;
}
static inline Outlet *VstOutlet_castToOutlet(VstOutlet *self) {
    return (Outlet*)self;
}
void Arguments_init(Arguments *self)
{
    self->s1 = NULL;
    self->i1 = 0;
    self->i2 = 0;
    self->ivalue = 0;
    self->inlet = 0;
    return;
}
void Arguments_clear(Arguments *self)
{
    return;
}
void Arguments_free(Arguments *self)
{
   if (self != NULL) {
        Arguments_clear(self);
        Mem_free(self);
   }
}
Arguments *Arguments_new()
{
    Arguments *self = Mem_malloc(sizeof(Arguments));
    Arguments_init(self);
    return self;
}
void BendOutlet_init(BendOutlet *self)
{
    self->itype = BendOutlet_itype;
    AtomAr_init(&self->atoms, 0);
    self->port = Port_new();
    return;
}
void BendOutlet_clear(BendOutlet *self)
{
    AtomAr_clear(&self->atoms);
    Port_free(self->port);
    return;
}
void BendOutlet_free(BendOutlet *self)
{
   if (self != NULL) {
        BendOutlet_clear(self);
        Mem_free(self);
   }
}
BendOutlet *BendOutlet_new()
{
    BendOutlet *self = Mem_malloc(sizeof(BendOutlet));
    BendOutlet_init(self);
    return self;
}
void BinFile_init(BinFile *self)
{
    self->version = 0;
    self->filename = String_empty();
    self->buffer = String_empty();
    self->stream = NULL;
    self->payload = BinFilePayload_new();
    return;
}
void BinFile_clear(BinFile *self)
{
    BinFile_userClear(self);
    String_free(self->filename);         
    String_free(self->buffer);         
    BinFilePayload_free(self->payload);
    return;
}
void BinFile_free(BinFile *self)
{
   if (self != NULL) {
        BinFile_clear(self);
        Mem_free(self);
   }
}
BinFile *BinFile_new()
{
    BinFile *self = Mem_malloc(sizeof(BinFile));
    BinFile_init(self);
    return self;
}
void BinFilePayload_init(BinFilePayload *self)
{
    self->portFind = PortFind_new();
    return;
}
void BinFilePayload_clear(BinFilePayload *self)
{
    PortFind_free(self->portFind);
    return;
}
void BinFilePayload_free(BinFilePayload *self)
{
   if (self != NULL) {
        BinFilePayload_clear(self);
        Mem_free(self);
   }
}
BinFilePayload *BinFilePayload_new()
{
    BinFilePayload *self = Mem_malloc(sizeof(BinFilePayload));
    BinFilePayload_init(self);
    return self;
}
void CcOutlet_init(CcOutlet *self)
{
    self->itype = CcOutlet_itype;
    self->cc = 0;
    AtomAr_init(&self->atoms, 0);
    self->port = Port_new();
    return;
}
void CcOutlet_clear(CcOutlet *self)
{
    AtomAr_clear(&self->atoms);
    Port_free(self->port);
    return;
}
void CcOutlet_free(CcOutlet *self)
{
   if (self != NULL) {
        CcOutlet_clear(self);
        Mem_free(self);
   }
}
CcOutlet *CcOutlet_new()
{
    CcOutlet *self = Mem_malloc(sizeof(CcOutlet));
    CcOutlet_init(self);
    return self;
}
void DecrementFrameDispatch_init(DecrementFrameDispatch *self)
{
    self->itype = DecrementFrameDispatch_itype;
    return;
}
void DecrementFrameDispatch_clear(DecrementFrameDispatch *self)
{
    return;
}
void DecrementFrameDispatch_free(DecrementFrameDispatch *self)
{
   if (self != NULL) {
        DecrementFrameDispatch_clear(self);
        Mem_free(self);
   }
}
DecrementFrameDispatch *DecrementFrameDispatch_new()
{
    DecrementFrameDispatch *self = Mem_malloc(sizeof(DecrementFrameDispatch));
    DecrementFrameDispatch_init(self);
    return self;
}
void DropDown_init(DropDown *self)
{
    SymbolPtrAr_init(&self->table, 0);
    self->selected = 0;
    PortRef_init(&self->portRef);            
    return;
}
void DropDown_clear(DropDown *self)
{
    SymbolPtrAr_clear(&self->table);
    PortRef_clear(&self->portRef);
    return;
}
void DropDown_free(DropDown *self)
{
   if (self != NULL) {
        DropDown_clear(self);
        Mem_free(self);
   }
}
DropDown *DropDown_new()
{
    DropDown *self = Mem_malloc(sizeof(DropDown));
    DropDown_init(self);
    return self;
}
void FloatEvent_init(FloatEvent *self)
{
    self->stime = 0;
    self->value = 0;
    return;
}
void FloatEvent_clear(FloatEvent *self)
{
    return;
}
void FloatEvent_free(FloatEvent *self)
{
   if (self != NULL) {
        FloatEvent_clear(self);
        Mem_free(self);
   }
}
FloatEvent *FloatEvent_new()
{
    FloatEvent *self = Mem_malloc(sizeof(FloatEvent));
    FloatEvent_init(self);
    return self;
}
void FloatSequence_init(FloatSequence *self)
{
    self->itype = FloatSequence_itype;
    self->version = 0;
    self->startTime = 0;
    self->sequenceLength = 0;
    OutletSpecifier_init(&self->outletSpecifier);            
    self->cursor = 0;
    self->cycle = 0;
    self->inEndgroup = 0;
    self->outlet = NULL;
    self->recordingSeq = NULL;
    FloatEventAr_init(&self->events, 0);
    self->restoreValue = 0;
    return;
}
void FloatSequence_clear(FloatSequence *self)
{
    OutletSpecifier_clear(&self->outletSpecifier);
    FloatEventAr_clear(&self->events);
    return;
}
void FloatSequence_free(FloatSequence *self)
{
   if (self != NULL) {
        FloatSequence_clear(self);
        Mem_free(self);
   }
}
FloatSequence *FloatSequence_new()
{
    FloatSequence *self = Mem_malloc(sizeof(FloatSequence));
    FloatSequence_init(self);
    return self;
}
void Foo_init(Foo *self)
{
    self->i = 0;
    self->d = 0;
    return;
}
void Foo_clear(Foo *self)
{
    return;
}
void Foo_free(Foo *self)
{
   if (self != NULL) {
        Foo_clear(self);
        Mem_free(self);
   }
}
Foo *Foo_new()
{
    Foo *self = Mem_malloc(sizeof(Foo));
    Foo_init(self);
    return self;
}
void Hub_init(Hub *self)
{
    self->padList = PadList_new();
    self->trackList = TrackList_new();
    self->currBankPort = Port_new();
    self->currFramePort = Port_new();
    self->selBankPort = Port_new();
    self->selFramePort = Port_new();
    self->selPadPort = Port_new();
    self->chokeGroupPort = Port_new();
    DropDown_init(&self->cgLocalGlobalMenu);            
    DropDown_init(&self->cgInstrumentMenu);            
    DropDown_init(&self->cgIndexMenu);            
    self->bank = 0;
    self->frame = 0;
    self->grabNextTappedPad = 0;
    self->selectedPad = 0;
    Arguments_init(&self->arguments);            
    DispatchPtAr_init(&self->dispatcher, 0);
    self->masterClock = 0;
    return;
}
void Hub_clear(Hub *self)
{
    PadList_free(self->padList);
    TrackList_free(self->trackList);
    Port_free(self->currBankPort);
    Port_free(self->currFramePort);
    Port_free(self->selBankPort);
    Port_free(self->selFramePort);
    Port_free(self->selPadPort);
    Port_free(self->chokeGroupPort);
    DropDown_clear(&self->cgLocalGlobalMenu);
    DropDown_clear(&self->cgInstrumentMenu);
    DropDown_clear(&self->cgIndexMenu);
    Arguments_clear(&self->arguments);
    DispatchPtAr_clear(&self->dispatcher);
    return;
}
void Hub_free(Hub *self)
{
   if (self != NULL) {
        Hub_clear(self);
        Mem_free(self);
   }
}
Hub *Hub_new()
{
    Hub *self = Mem_malloc(sizeof(Hub));
    Hub_init(self);
    return self;
}
void IncrementFrameDispatch_init(IncrementFrameDispatch *self)
{
    self->itype = IncrementFrameDispatch_itype;
    return;
}
void IncrementFrameDispatch_clear(IncrementFrameDispatch *self)
{
    return;
}
void IncrementFrameDispatch_free(IncrementFrameDispatch *self)
{
   if (self != NULL) {
        IncrementFrameDispatch_clear(self);
        Mem_free(self);
   }
}
IncrementFrameDispatch *IncrementFrameDispatch_new()
{
    IncrementFrameDispatch *self = Mem_malloc(sizeof(IncrementFrameDispatch));
    IncrementFrameDispatch_init(self);
    return self;
}
void IndexedOff_init(IndexedOff *self)
{
    self->padIndex = 0;
    self->pitch = 0;
    return;
}
void IndexedOff_clear(IndexedOff *self)
{
    return;
}
void IndexedOff_free(IndexedOff *self)
{
   if (self != NULL) {
        IndexedOff_clear(self);
        Mem_free(self);
   }
}
IndexedOff *IndexedOff_new()
{
    IndexedOff *self = Mem_malloc(sizeof(IndexedOff));
    IndexedOff_init(self);
    return self;
}
void ManageChokeGroupsDispatch_init(ManageChokeGroupsDispatch *self)
{
    self->itype = ManageChokeGroupsDispatch_itype;
    return;
}
void ManageChokeGroupsDispatch_clear(ManageChokeGroupsDispatch *self)
{
    return;
}
void ManageChokeGroupsDispatch_free(ManageChokeGroupsDispatch *self)
{
   if (self != NULL) {
        ManageChokeGroupsDispatch_clear(self);
        Mem_free(self);
   }
}
ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_new()
{
    ManageChokeGroupsDispatch *self = Mem_malloc(sizeof(ManageChokeGroupsDispatch));
    ManageChokeGroupsDispatch_init(self);
    return self;
}
void MarshalSi_init(MarshalSi *self)
{
    self->itype = MarshalSi_itype;
    return;
}
void MarshalSi_clear(MarshalSi *self)
{
    return;
}
void MarshalSi_free(MarshalSi *self)
{
   if (self != NULL) {
        MarshalSi_clear(self);
        Mem_free(self);
   }
}
MarshalSi *MarshalSi_new()
{
    MarshalSi *self = Mem_malloc(sizeof(MarshalSi));
    MarshalSi_init(self);
    return self;
}
void MarshalSii_init(MarshalSii *self)
{
    self->itype = MarshalSii_itype;
    return;
}
void MarshalSii_clear(MarshalSii *self)
{
    return;
}
void MarshalSii_free(MarshalSii *self)
{
   if (self != NULL) {
        MarshalSii_clear(self);
        Mem_free(self);
   }
}
MarshalSii *MarshalSii_new()
{
    MarshalSii *self = Mem_malloc(sizeof(MarshalSii));
    MarshalSii_init(self);
    return self;
}
void MarshalSs_init(MarshalSs *self)
{
    self->itype = MarshalSs_itype;
    return;
}
void MarshalSs_clear(MarshalSs *self)
{
    return;
}
void MarshalSs_free(MarshalSs *self)
{
   if (self != NULL) {
        MarshalSs_clear(self);
        Mem_free(self);
   }
}
MarshalSs *MarshalSs_new()
{
    MarshalSs *self = Mem_malloc(sizeof(MarshalSs));
    MarshalSs_init(self);
    return self;
}
void MidiFileDropDispatch_init(MidiFileDropDispatch *self)
{
    self->itype = MidiFileDropDispatch_itype;
    return;
}
void MidiFileDropDispatch_clear(MidiFileDropDispatch *self)
{
    return;
}
void MidiFileDropDispatch_free(MidiFileDropDispatch *self)
{
   if (self != NULL) {
        MidiFileDropDispatch_clear(self);
        Mem_free(self);
   }
}
MidiFileDropDispatch *MidiFileDropDispatch_new()
{
    MidiFileDropDispatch *self = Mem_malloc(sizeof(MidiFileDropDispatch));
    MidiFileDropDispatch_init(self);
    return self;
}
void Midiseq_init(Midiseq *self)
{
    self->useMasterClock = 0;
    self->sequenceLength = 0;
    MEventAr_init(&self->events, 0);
    self->startTime = 0;
    self->ptr = 0;
    Midiseq_userInit(self);
    return;
}
void Midiseq_clear(Midiseq *self)
{
    MEventAr_clear(&self->events);
    return;
}
void Midiseq_free(Midiseq *self)
{
   if (self != NULL) {
        Midiseq_clear(self);
        Mem_free(self);
   }
}
Midiseq *Midiseq_new()
{
    Midiseq *self = Mem_malloc(sizeof(Midiseq));
    Midiseq_init(self);
    return self;
}
void MusicalContext_init(MusicalContext *self)
{
    self->ticksPerQuarterNote = 0;
    self->quarterNotesPerMeasure = 0;
    return;
}
void MusicalContext_clear(MusicalContext *self)
{
    return;
}
void MusicalContext_free(MusicalContext *self)
{
   if (self != NULL) {
        MusicalContext_clear(self);
        Mem_free(self);
   }
}
MusicalContext *MusicalContext_new()
{
    MusicalContext *self = Mem_malloc(sizeof(MusicalContext));
    MusicalContext_init(self);
    return self;
}
void NoteEvent_init(NoteEvent *self)
{
    self->pitch = 0;
    self->velocity = 0;
    self->stime = 0;
    self->duration = 0;
    return;
}
void NoteEvent_clear(NoteEvent *self)
{
    return;
}
void NoteEvent_free(NoteEvent *self)
{
   if (self != NULL) {
        NoteEvent_clear(self);
        Mem_free(self);
   }
}
NoteEvent *NoteEvent_new()
{
    NoteEvent *self = Mem_malloc(sizeof(NoteEvent));
    NoteEvent_init(self);
    return self;
}
void NoteManager_init(NoteManager *self)
{
    TimedOffAr_init(&self->pending, 0);
    IndexedOffAr_init(&self->endgroups, 0);
    self->output = Port_new();
    self->atoms = NULL;
    NoteManager_userInit(self);
    return;
}
void NoteManager_clear(NoteManager *self)
{
    NoteManager_userClear(self);
    TimedOffAr_clear(&self->pending);
    IndexedOffAr_clear(&self->endgroups);
    Port_free(self->output);
    return;
}
void NoteManager_free(NoteManager *self)
{
   if (self != NULL) {
        NoteManager_clear(self);
        Mem_free(self);
   }
}
NoteManager *NoteManager_new()
{
    NoteManager *self = Mem_malloc(sizeof(NoteManager));
    NoteManager_init(self);
    return self;
}
void NoteOutlet_init(NoteOutlet *self)
{
    self->itype = NoteOutlet_itype;
    AtomAr_init(&self->atoms, 0);
    self->port = Port_new();
    return;
}
void NoteOutlet_clear(NoteOutlet *self)
{
    AtomAr_clear(&self->atoms);
    Port_free(self->port);
    return;
}
void NoteOutlet_free(NoteOutlet *self)
{
   if (self != NULL) {
        NoteOutlet_clear(self);
        Mem_free(self);
   }
}
NoteOutlet *NoteOutlet_new()
{
    NoteOutlet *self = Mem_malloc(sizeof(NoteOutlet));
    NoteOutlet_init(self);
    return self;
}
void NoteSequence_init(NoteSequence *self)
{
    self->itype = NoteSequence_itype;
    self->version = 0;
    self->startTime = 0;
    self->sequenceLength = 0;
    OutletSpecifier_init(&self->outletSpecifier);            
    self->cursor = 0;
    self->cycle = 0;
    self->nextOffEvent = 0;
    self->nextOnEvent = 0;
    self->inEndgroup = 0;
    self->outlet = NULL;
    self->recordingSeq = NULL;
    TimedOffAr_init(&self->offs, 0);
    NoteEventAr_init(&self->events, 0);
    return;
}
void NoteSequence_clear(NoteSequence *self)
{
    OutletSpecifier_clear(&self->outletSpecifier);
    TimedOffAr_clear(&self->offs);
    NoteEventAr_clear(&self->events);
    return;
}
void NoteSequence_free(NoteSequence *self)
{
   if (self != NULL) {
        NoteSequence_clear(self);
        Mem_free(self);
   }
}
NoteSequence *NoteSequence_new()
{
    NoteSequence *self = Mem_malloc(sizeof(NoteSequence));
    NoteSequence_init(self);
    return self;
}
void NullOutlet_init(NullOutlet *self)
{
    self->itype = NullOutlet_itype;
    self->unused = 0;
    return;
}
void NullOutlet_clear(NullOutlet *self)
{
    return;
}
void NullOutlet_free(NullOutlet *self)
{
   if (self != NULL) {
        NullOutlet_clear(self);
        Mem_free(self);
   }
}
NullOutlet *NullOutlet_new()
{
    NullOutlet *self = Mem_malloc(sizeof(NullOutlet));
    NullOutlet_init(self);
    return self;
}
void OutletSpecifier_init(OutletSpecifier *self)
{
    self->track = NULL;
    self->pluginIndex = 0;
    self->parameter = NULL;
    self->paramIndex = 0;
    return;
}
void OutletSpecifier_clear(OutletSpecifier *self)
{
    return;
}
void OutletSpecifier_free(OutletSpecifier *self)
{
   if (self != NULL) {
        OutletSpecifier_clear(self);
        Mem_free(self);
   }
}
OutletSpecifier *OutletSpecifier_new()
{
    OutletSpecifier *self = Mem_malloc(sizeof(OutletSpecifier));
    OutletSpecifier_init(self);
    return self;
}
void Pad_init(Pad *self)
{
    self->trackName = NULL;
    self->padIndex = 0;
    self->sequence = Midiseq_new();
    self->chokeGroupGlobal = 0;
    self->chokeGroupInstrument = 0;
    self->chokeGroupIndex = 0;
    self->chokeGroup = 0;
    self->noteReleasePending = 0;
    self->inEndgroup = 0;
    self->track = Track_new();
    self->useMasterClock = 0;
    return;
}
void Pad_clear(Pad *self)
{
    Midiseq_free(self->sequence);
    Track_free(self->track);
    return;
}
void Pad_free(Pad *self)
{
   if (self != NULL) {
        Pad_clear(self);
        Mem_free(self);
   }
}
Pad *Pad_new()
{
    Pad *self = Mem_malloc(sizeof(Pad));
    Pad_init(self);
    return self;
}
void PadList_init(PadList *self)
{
    PadAr_init(&self->pads, 0);
    PadPtrAr_init(&self->running, 0);
    return;
}
void PadList_clear(PadList *self)
{
    PadAr_clear(&self->pads);
    PadPtrAr_clear(&self->running);
    return;
}
void PadList_free(PadList *self)
{
   if (self != NULL) {
        PadList_clear(self);
        Mem_free(self);
   }
}
PadList *PadList_new()
{
    PadList *self = Mem_malloc(sizeof(PadList));
    PadList_init(self);
    return self;
}
void PortFind_init(PortFind *self)
{
    PortFindCellAr_init(&self->objects, 0);
    self->hub = NULL;
    self->anythingDispatch = 0;
    self->intDispatch = 0;
    return;
}
void PortFind_clear(PortFind *self)
{
    PortFind_userClear(self);
    PortFindCellAr_clear(&self->objects);
    return;
}
void PortFind_free(PortFind *self)
{
   if (self != NULL) {
        PortFind_clear(self);
        Mem_free(self);
   }
}
PortFind *PortFind_new()
{
    PortFind *self = Mem_malloc(sizeof(PortFind));
    PortFind_init(self);
    return self;
}
void PortFindCell_init(PortFindCell *self)
{
    self->reciever = Port_new();
    self->varname = NULL;
    return;
}
void PortFindCell_clear(PortFindCell *self)
{
    Port_free(self->reciever);
    return;
}
void PortFindCell_free(PortFindCell *self)
{
   if (self != NULL) {
        PortFindCell_clear(self);
        Mem_free(self);
   }
}
PortFindCell *PortFindCell_new()
{
    PortFindCell *self = Mem_malloc(sizeof(PortFindCell));
    PortFindCell_init(self);
    return self;
}
void PortRef_init(PortRef *self)
{
    self->port = NULL;
    self->outlet = 0;
    return;
}
void PortRef_clear(PortRef *self)
{
    return;
}
void PortRef_free(PortRef *self)
{
   if (self != NULL) {
        PortRef_clear(self);
        Mem_free(self);
   }
}
PortRef *PortRef_new()
{
    PortRef *self = Mem_malloc(sizeof(PortRef));
    PortRef_init(self);
    return self;
}
void RecordBuffer_init(RecordBuffer *self)
{
    self->recordStart = 0;
    SequenceAr_init(&self->sequences, 0);
    return;
}
void RecordBuffer_clear(RecordBuffer *self)
{
    SequenceAr_clear(&self->sequences);
    return;
}
void RecordBuffer_free(RecordBuffer *self)
{
   if (self != NULL) {
        RecordBuffer_clear(self);
        Mem_free(self);
   }
}
RecordBuffer *RecordBuffer_new()
{
    RecordBuffer *self = Mem_malloc(sizeof(RecordBuffer));
    RecordBuffer_init(self);
    return self;
}
void SelectNextPushedPadDispatch_init(SelectNextPushedPadDispatch *self)
{
    self->itype = SelectNextPushedPadDispatch_itype;
    return;
}
void SelectNextPushedPadDispatch_clear(SelectNextPushedPadDispatch *self)
{
    return;
}
void SelectNextPushedPadDispatch_free(SelectNextPushedPadDispatch *self)
{
   if (self != NULL) {
        SelectNextPushedPadDispatch_clear(self);
        Mem_free(self);
   }
}
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_new()
{
    SelectNextPushedPadDispatch *self = Mem_malloc(sizeof(SelectNextPushedPadDispatch));
    SelectNextPushedPadDispatch_init(self);
    return self;
}
void Timed_init(Timed *self)
{
    self->time = 0;
    self->version = 0;
    self->sequence = NULL;
    return;
}
void Timed_clear(Timed *self)
{
    return;
}
void Timed_free(Timed *self)
{
   if (self != NULL) {
        Timed_clear(self);
        Mem_free(self);
   }
}
Timed *Timed_new()
{
    Timed *self = Mem_malloc(sizeof(Timed));
    Timed_init(self);
    return self;
}
void TimedOff_init(TimedOff *self)
{
    self->time = 0;
    self->pitch = 0;
    return;
}
void TimedOff_clear(TimedOff *self)
{
    return;
}
void TimedOff_free(TimedOff *self)
{
   if (self != NULL) {
        TimedOff_clear(self);
        Mem_free(self);
   }
}
TimedOff *TimedOff_new()
{
    TimedOff *self = Mem_malloc(sizeof(TimedOff));
    TimedOff_init(self);
    return self;
}
void Track_init(Track *self)
{
    self->name = NULL;
    self->noteManager = NoteManager_new();
    return;
}
void Track_clear(Track *self)
{
    NoteManager_free(self->noteManager);
    return;
}
void Track_free(Track *self)
{
   if (self != NULL) {
        Track_clear(self);
        Mem_free(self);
   }
}
Track *Track_new()
{
    Track *self = Mem_malloc(sizeof(Track));
    Track_init(self);
    return self;
}
void TrackList_init(TrackList *self)
{
    TrackAr_init(&self->list, 0);
    return;
}
void TrackList_clear(TrackList *self)
{
    TrackAr_clear(&self->list);
    return;
}
void TrackList_free(TrackList *self)
{
   if (self != NULL) {
        TrackList_clear(self);
        Mem_free(self);
   }
}
TrackList *TrackList_new()
{
    TrackList *self = Mem_malloc(sizeof(TrackList));
    TrackList_init(self);
    return self;
}
void VstOutlet_init(VstOutlet *self)
{
    self->itype = VstOutlet_itype;
    AtomAr_init(&self->atoms, 0);
    self->port = Port_new();
    return;
}
void VstOutlet_clear(VstOutlet *self)
{
    AtomAr_clear(&self->atoms);
    Port_free(self->port);
    return;
}
void VstOutlet_free(VstOutlet *self)
{
   if (self != NULL) {
        VstOutlet_clear(self);
        Mem_free(self);
   }
}
VstOutlet *VstOutlet_new()
{
    VstOutlet *self = Mem_malloc(sizeof(VstOutlet));
    VstOutlet_init(self);
    return self;
}
#define Hub_padsPerFrame           24
#define Hub_framesPerBank           8
#define Hub_padsPerBank            (Hub_padsPerFrame*Hub_framesPerBank)
#define Hub_firstMidiNote          48

#define hub_padIndexToBank(index)         (index / Hub_padsPerBank)
#define hub_padIndexToFrame(index)        (index / Hub_framesPerBank)
#define hub_padIndexToRelativePad(index)  (index % Hub_padsPerFrame)

#define Hub_selectedBank(hub)        hub_padIndexToBank(Hub_selectedPad(hub))
#define Hub_selectedFrame(hub)       hub_padIndexToFrame(Hub_selectedPad(hub))
#define Hub_relativeSelectedPad(hub) hub_padIndexToRelativePad(Hub_selectedPad(hub))

#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*Hub_padsPerBank + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))

void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err)
{
    switch(self->itype) {
        case DecrementFrameDispatch_itype:
            DecrementFrameDispatch_exec((DecrementFrameDispatch*)self, a1, a2, err);
            return;
        case IncrementFrameDispatch_itype:
            IncrementFrameDispatch_exec((IncrementFrameDispatch*)self, a1, a2, err);
            return;
        case ManageChokeGroupsDispatch_itype:
            ManageChokeGroupsDispatch_exec((ManageChokeGroupsDispatch*)self, a1, a2, err);
            return;
        case MidiFileDropDispatch_itype:
            MidiFileDropDispatch_exec((MidiFileDropDispatch*)self, a1, a2, err);
            return;
        case SelectNextPushedPadDispatch_itype:
            SelectNextPushedPadDispatch_exec((SelectNextPushedPadDispatch*)self, a1, a2, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_exec: found type %s", Interface_toString(self->itype));
    }
    return;
}

Dispatch *Dispatch_create(int itype, Error *err)
{
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

void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err)
{
    switch(itype) {
        case DecrementFrameDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case IncrementFrameDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case ManageChokeGroupsDispatch_itype:
            ManageChokeGroupsDispatch_initDispatchPtAr(itype, a1, err);
            return;
        case MidiFileDropDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case SelectNextPushedPadDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_initDispatchPtAr: found type %s", Interface_toString(itype));
    }
    return;
}

void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err)
{
    switch(self->itype) {
        case MarshalSi_itype:
            MarshalSi_process((MarshalSi*)self, a1, a2, a3, err);
            return;
        case MarshalSii_itype:
            MarshalSii_process((MarshalSii*)self, a1, a2, a3, err);
            return;
        case MarshalSs_itype:
            MarshalSs_process((MarshalSs*)self, a1, a2, a3, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in MarshalSs_process: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err)
{
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

void Outlet_sendNote(Outlet *self, uint8_t a1, uint8_t a2, Error *err)
{
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

void Sequence_start(Sequence *self, Ticks a1, Ticks a2, TimedPq *a3, RecordBuffer *a4, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            FloatSequence_start((FloatSequence*)self, a1, a2, a3, a4, err);
            return;
        case NoteSequence_itype:
            NoteSequence_start((NoteSequence*)self, a1, a2, a3, a4, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_start: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_drive(Sequence *self, Ticks a1, TimedPq *a2, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            FloatSequence_drive((FloatSequence*)self, a1, a2, err);
            return;
        case NoteSequence_itype:
            NoteSequence_drive((NoteSequence*)self, a1, a2, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_drive: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_stop(Sequence *self, Ticks a1, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            FloatSequence_stop((FloatSequence*)self, a1, err);
            return;
        case NoteSequence_itype:
            NoteSequence_stop((NoteSequence*)self, a1, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_stop: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_padNoteOff(Sequence *self, int a1, Ticks a2, Error *err)
{
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

OutletSpecifier *Sequence_outSpec(Sequence *self, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            return FloatSequence_outSpec((FloatSequence*)self);
        case NoteSequence_itype:
            return NoteSequence_outSpec((NoteSequence*)self);
        default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_outSpec: found type %s", Interface_toString(self->itype));
    }
    return NULL;
}

const char *Interface_toString(int itype)
{
    switch(itype) {
        case Undefined_itype:
            return "Undefined";
        case BendOutlet_itype:
            return "BendOutlet";
        case CcOutlet_itype:
            return "CcOutlet";
        case DecrementFrameDispatch_itype:
            return "DecrementFrameDispatch";
        case FloatSequence_itype:
            return "FloatSequence";
        case IncrementFrameDispatch_itype:
            return "IncrementFrameDispatch";
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
        case NoteOutlet_itype:
            return "NoteOutlet";
        case NoteSequence_itype:
            return "NoteSequence";
        case NullOutlet_itype:
            return "NullOutlet";
        case SelectNextPushedPadDispatch_itype:
            return "SelectNextPushedPadDispatch";
        case VstOutlet_itype:
            return "VstOutlet";
    }
    return "Unknown";
}

#line 15 "src/dispatch.in.c"

#line 34 "src/dispatch.in.c"

#line 42 "src/dispatch.in.c"

#line 50 "src/dispatch.in.c"

#line 58 "src/dispatch.in.c"

#line 120 "src/dispatch.in.c"

#line 128 "src/dispatch.in.c"

#line 136 "src/dispatch.in.c"

#line 144 "src/dispatch.in.c"

#line 152 "src/dispatch.in.c"

#line 160 "src/dispatch.in.c"





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

APIF void ManageChokeGroupsDispatch_initDispatchPtAr(int itype, DispatchPtAr *disPtAr, Error *ignored) {
   for (int i = 0; i < 3; i++) {
      Dispatch *dis = ManageChokeGroupsDispatch_create(itype);
      dis->inlet    = i;
      DispatchPtAr_push(disPtAr, dis);
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

APIF void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr, Error *err) {
   Dispatch *dis = Dispatch_create(itype, err);
   Error_returnVoidOnError(err);
   DispatchPtAr_push(disPtAr, dis);
}

APIF void DispatchPtAr_populate(DispatchPtAr *self, Error *err) {
   DispatchPtAr_truncate(self);
   Dispatch_foreachIType(itype) {
      Dispatch_initDispatchPtAr(itype, self, err);
      Error_maypost(err);
   }
   DispatchPtAr_sort(self);
}



#define APIF /**/
String *stripBaseName(const char *path);

#line 13 "src/midiseq.in.c"

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

#line 46 "src/midiseq.in.c"

APIF int Symbol_cmpUnderlying(Symbol **left, Symbol **right) 
{
    return strcmp(Symbol_cstr(*left), Symbol_cstr(*right)); 
}

#ifdef TEST_BUILD
SymbolPtAr *gSymbols = NULL;

Symbol *Symbol_gen(const char *word) 
{
    if (gSymbols == NULL) {
        gSymbols = SymbolPtAr_new(0);
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

void Symbol_freeAll() 
{
    SymbolPtAr_foreach(it, gSymbols) {
        Mem_free(*it.var);
    }
    SymbolPtAr_truncate(gSymbols);
}

#endif

#line 88 "src/midiseq.in.c"

#line 97 "src/midiseq.in.c"

#line 117 "src/midiseq.in.c"


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

    Symbol *selector = Atom_toSymbol(argv + 0);
    void *out = PtrAr_get(&self->outlet, outletIndex, err);
    Error_returnVoidOnError(err);
#ifndef TEST_BUILD
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

APIF void Port_sendInteger(Port *self, int outlet, long value) 
{
    if (self == Port_null) {
        return;
    }

    Error_declare(err);
    void *out = PtrAr_get(&self->outlet, outlet, err);
    if (Error_maypost(err)) {
        return;
    } 
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

#line 223 "src/midiseq.in.c"

#line 231 "src/midiseq.in.c"

#line 239 "src/midiseq.in.c"

#line 247 "src/midiseq.in.c"



#line 263 "src/midiseq.in.c"

#line 293 "src/midiseq.in.c"
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)
static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

#line 340 "src/midiseq.in.c"


#line 406 "src/midiseq.in.c"


#line 434 "src/midiseq.in.c"

#line 461 "src/midiseq.in.c"

#line 485 "src/midiseq.in.c"


#line 506 "src/midiseq.in.c"

#line 531 "src/midiseq.in.c"


#line 546 "src/midiseq.in.c"

#line 563 "src/midiseq.in.c"

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
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



#line 619 "src/midiseq.in.c"

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

//
// D R O P   D O W N
//

APIF void DropDown_build(DropDown *dd, const char **table, PortRef *pr) {
    SymbolPtrAr_init(&dd->table, 0);
    const char **ptr = table;
    while (*ptr) {
        Symbol *s = Symbol_gen(*ptr);
        SymbolPtrAr_push(&dd->table, s);
        ptr++;
    }
    DropDown_setPortRef(dd, pr);
    return;
}

APIF void DropDown_buildCGLocalGlobal(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "local",
        "global",
        NULL
    };
    DropDown_build(dd, t, pr);
}

APIF void DropDown_buildCGInstrument(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "none",
        "lead",
        "rhythm",
        "piano",
        "bass",
        "drums",
        NULL,
    };
    DropDown_build(dd, t, pr);
}

APIF void DropDown_buildCGIndex(DropDown *dd, PortRef *pr) {
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
    DropDown_build(dd, t, pr);
}

// APIF void DropDown_clear(DropDown *dd) {
//     SymbolPtrAr_clear(&dd->table);
// }

// APIF void DropDown_free(DropDown *dd) {
//     DropDown_clear(dd);
//     Mem_free(dd);
// }

APIF void DropDown_updateSelected(DropDown *dd, Error *err) {
    Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
    Error_returnVoidOnError(err);
    Atom a[2] = {
        Atom_fromSymbol(Symbol_gen("set")),
        Atom_fromSymbol(s)
    };
    PortRef_send(DropDown_portRef(dd), 2, a, err);
}

APIF void DropDown_setSelected(DropDown *dd, int selected, Error *err) {
    if (selected < 0 || selected >= SymbolPtrAr_len(&dd->table)) {
        Error_format(err, "Index out of range (%d, %d)", selected, SymbolPtrAr_len(&dd->table));
        return;
    }
    dd->selected = selected;
}

APIF void DropDown_initializeMenu(DropDown *dd, Error *err) {
    Atom clear = Atom_fromSymbol(Symbol_gen("clear"));
    Atom append = Atom_fromSymbol(Symbol_gen("append"));

    PortRef_send(&dd->portRef, 1, &clear, err);
    Error_returnVoidOnError(err);

    SymbolPtrAr_foreach(it, &dd->table) {
        Atom a[2] = {append, Atom_fromSymbol(*it.var)};
        PortRef_send(&dd->portRef, 2, a, err);
        Error_returnVoidOnError(err);        
    }
}
#line 842 "src/midiseq.in.c"

#line 860 "src/midiseq.in.c"

//
// Memory allocation Notes. These are the functions that are used in sdsalloc.h
//

// malloc
//          t_ptr sysmem_newptr	(long size)
// realloc
//          t_ptr sysmem_resizeptr	(void *ptr, long newsize)
// calloc
//          t_ptr sysmem_newptrclear(long size)
// free
//          void sysmem_freeptr	(	void * 	ptr	)

//
// U t i l i t y
//
APIF int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line)
{
    errno = 0;
    long v = strtol(src, NULL, 10);
    if (errno != 0) {
        Error_formatFileLine(err, function, file, line,
            String_fmt("Failed to convert int error code %s",
            (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));

    }
    return v;
}


#define Midiseq_convertInt(src, err) Midiseq_convertIntFileLine(src, err, __func__, __FILE__, __LINE__)

//
// M I D I S E Q
//
#define Midiseq_maxLineLength 1024

// Create new empty midi sequence

APIF void Midiseq_userInit(Midiseq *self)
{
    self->sequenceLength = 480*4;

    MEvent cell = {0};
    cell.t = 0;
    cell.type = Midiseq_endgrptype;
    MEventAr_push(&self->events, cell);
    
    cell.t = self->sequenceLength;
    cell.type = Midiseq_cycletype;
    MEventAr_push(&self->events, cell);

    MEventAr_fit(&self->events);
}



APIF void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    BinFile_writeBool(bf, Midiseq_useMasterClock(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeTicks(bf, Midiseq_sequenceLength(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, MEventAr_len(&mseq->events), err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    MEventAr_foreach(it, &mseq->events) {
        MEvent cell = *it.var;
        if (fprintf(BinFile_stream(bf), " %u %u %lld", MEvent_type(cell), MEvent_bendValue(cell), MEvent_t(cell)) < 0) {
            Error_format(err, "Midiseq_toBinFile failed at fprintf[1] while writing %s", BinFile_filename(bf));
            return;
        }

        if (MEvent_type(cell) == Midiseq_notetype) {
            if (fprintf(BinFile_stream(bf), " %lld", MEvent_noteDuration(cell)) < 0) {
                Error_format(err, "Midiseq_toBinFile failed at fprintf[2] while writing %s", BinFile_filename(bf));
                return;       
            }
        }
    }
    BinFile_writeTag(bf, "midiseq_end_data", err);
    Error_returnVoidOnError(err);
}


APIF Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err) {
    Midiseq *mseq = Midiseq_new();
    Midiseq_fromBinFileUnititialized(mseq, bf, err);
    if (Error_iserror(err)) {
        Mem_free(mseq);
        return NULL;
    }
    return mseq;
}

APIF void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    Midiseq_setUseMasterClock(mseq, BinFile_readBool(bf, err));
    Error_returnVoidOnError(err);

    Midiseq_setSequenceLength(mseq, BinFile_readTicks(bf,  err));
    Error_returnVoidOnError(err);

    long length = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    MEventAr_init(&mseq->events, 0);
    for (int i = 0; i < length; i++) {
        MEvent cell = {0};
        unsigned int type = 0, bendVal = 0;
        if (fscanf(BinFile_stream(bf), " %u %u %lld", &type, &bendVal, &MEvent_t(cell)) != 3) {
            Error_format(err, "Midiseq_fromBinFile failed at fscanf[1] while reading %s", BinFile_filename(bf));
            goto END;
        }
        MEvent_type(cell)      = type;
        MEvent_bendValue(cell) = bendVal;

        if (MEvent_type(cell) == Midiseq_notetype) {
            if (fscanf(BinFile_stream(bf), " %lld", &MEvent_noteDuration(cell)) != 1) {
                Error_format(err, "Midiseq_fromBinFile failed at fscanf[2] while reading %s", BinFile_filename(bf));
                goto END;
            }
        }
        MEventAr_push(&mseq->events, cell);
    }
    MEventAr_fit(&mseq->events);
    BinFile_verifyTag(bf, "midiseq_end_data", err);
    Error_gotoLabelOnError(err, END);
    return;

  END:
    MEventAr_clear(&mseq->events);
    return;
}

APIF Midiseq *Midiseq_newNote(int pitch)
{
    Midiseq *mseq = Midiseq_new();
    MEventAr_truncate(&mseq->events);

    mseq->sequenceLength = 480*4;
    
    MEvent zero = {
        0
    }
    , cell = {
        0
    };

    MEvent_t(cell)    = 0;
    MEvent_type(cell) = Midiseq_endgrptype;
    MEventAr_push(&mseq->events, cell);

    cell = zero;
    MEvent_t(cell)            = 0;
    MEvent_type(cell)         = Midiseq_notetype;
    MEvent_notePitch(cell)    = pitch;
    MEvent_noteVelocity(cell) = 90;
    MEvent_noteDuration(cell) = 480;
    MEventAr_push(&mseq->events, cell);

    cell              = zero;
    MEvent_t(cell)    = mseq->sequenceLength;
    MEvent_type(cell) = Midiseq_cycletype;
    MEventAr_push(&mseq->events, cell);

    MEventAr_fit(&mseq->events);

    return mseq;
}

APIF int Midiseq_len(Midiseq *mseq)
{
    // REMEMBER: because of cycle and endgroup, every midi sequence has at least 2 elements.
    return MEventAr_len(&mseq->events);
}


APIF void Midiseq_push(Midiseq *mseq, MEvent cell)
{
    MEventAr_push(&mseq->events, cell);
}


APIF MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err)
{
    return MEventAr_getp(&mseq->events, index, err);
}


bool Midiseq_pathsAllocated = false;
String *Midiseq_midiCsvExecPath = NULL;
String *Midiseq_csvMidiExecPath = NULL;

APIF void Midiseq_setMidicsvExecPath()
{
    if (!Midiseq_pathsAllocated) {
        Midiseq_midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
        Midiseq_csvMidiExecPath = String_fmt("%s/packages/midicsv-1.1/csvmidi", CSEQ_HOME);
        Midiseq_pathsAllocated = true;
    }
}


APIF void Midiseq_dblog(Midiseq *mseq)
{
    dblog("Midiseq %p", mseq);
    MEventAr_foreach(it, &mseq->events) {
        MEvent cell = *it.var;
        switch (MEvent_type(cell)) {
            case Midiseq_notetype:
                dblog("    %15lld note %15ld %15ld %15ld", MEvent_t(cell),
                    (long)MEvent_notePitch(cell), (long)MEvent_noteVelocity(cell), (long)MEvent_noteDuration(cell));
                break;
            case Midiseq_bendtype:
                dblog("    %15lld bend", MEvent_t(cell));
                break;
            case Midiseq_cctype:
                dblog("    %15lld cc", MEvent_t(cell));
                break;
            case Midiseq_endgrptype:
                dblog("    %15lld endgroup", MEvent_t(cell));
                break;
            case Midiseq_cycletype:
                dblog("    %15lld cycle", MEvent_t(cell));
                break;
        }
    }
    return;
}

//
// F R O M     F I L E
//
APIF int midiseq_tokenize(FILE *fd, StringPtAr **ret, Error *err)
{
    static String *buffer       = NULL;
    static StringPtAr *arBuffer = NULL;
    if (buffer == NULL) {
        buffer   = String_empty();
        arBuffer = StringPtAr_new(0);
    }
    if (!String_readline(&buffer, fd, err)) {
        return 0;
    }
    String_split(buffer, ",", arBuffer);
    StringPtAr_foreach(it, arBuffer) {
        String_trim(it.var);
    }
    *ret = arBuffer;
    return 1;
}


APIF int Midiseq_assignLength(Midiseq *mseq)
{
    const long ppqn = 480;
    const long measureLength = ppqn*4;
    if (Midiseq_len(mseq) == 0) {
        mseq->sequenceLength = measureLength;
        return 0;
    }

    Ticks end = 0;
    MEventAr_foreach(it, &mseq->events) {
        long t = it.var->t;
        if (it.var->type == Midiseq_notetype) {
            t += it.var->duration;
        }
        if (t > end) {
            end = t;
        }
    }

    mseq->sequenceLength = (end/measureLength)*measureLength + (end % measureLength == 0 ? 0 : measureLength);
    return 0;
}


APIF int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err)
{
    MEventAr_insert(&mseq->events, index, cell, err);
    if (Error_iserror(err)) {
        return 1;
    }
    return 0;
}


APIF void Midiseq_insertEndgroup(Midiseq *mseq, Error *err)
{
    MEvent cell = {0};
    cell.type = Midiseq_endgrptype;

    if (MEventAr_len(&mseq->events) < 2) {
        cell.t = mseq->sequenceLength;
        MEventAr_rforeach(it, &mseq->events) {
            if (it.var->type == Midiseq_notetype) {
                cell.t = it.var->t;
                MEventAr_insert(&mseq->events, 0, cell, err);
                return;   
            }
        }
        MEventAr_push(&mseq->events, cell);
        return;
    }

    MEventAr_rforeach(it, &mseq->events) {
        if (it.var->type == Midiseq_notetype) {
            cell.t = it.var->t;
            int index = it.index;
            while (MEventArRIt_next(&it)) {
                if (cell.t != it.var->t) {
                    break;
                }
                index++;
            }
            if (index < 0) {
                index = 0;
            }
            Midiseq_insertCell(mseq, cell, index, err);
            return;
        }
    }

    MEvent e = MEventAr_get(&mseq->events, 0, err);
    Error_returnVoidOnError(err);
    cell.t = e.t;
    Midiseq_insertCell(mseq, cell, 0, err);
    Error_returnVoidOnError(err);
    return;
}


APIF int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    if (startTime > currentTime) {
        Error_format0(err, "INTERNAL ERROR");
        return 1;
    }
    Ticks adj            = mseq->sequenceLength*((currentTime-startTime)/mseq->sequenceLength);
    mseq->startTime      = startTime + adj;
    mseq->useMasterClock = useMasterClock;
    mseq->ptr            = 0;
    if (useMasterClock) {
        if (Midiseq_fastfwrd(mseq, currentTime, err)) {
            return 1;
        }
    }
    return 0;
}


APIF void Midiseq_stop(Midiseq *mseq)
{
    mseq->startTime = 0;
    return;
}


enum
{
    Midiseq_nextEventErrored  = 1,
    Midiseq_nextEventComplete = 2,
    Midiseq_nextEventContinue = 3,
    Midiseq_nextEventBreak    = 4,
};

// Midiseq_nextevent always writes the current cell into the cell pointer. If the event
// stored in cell happened before until, then (a) the sequence is advanced and (b) the
// function returns 1. Otherwise 0 is returned and the sequence is left alone.
APIF int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err)
{
    if (mseq->startTime == 0) {
        Error_format0(err, "Called nextevent on stoped sequence");
        return Midiseq_nextEventErrored;
    }
    if (mseq->ptr >= Midiseq_len(mseq)) {
        // This is the case when the entire sequence has been played, and this
        // is NOT a useMasterClock sequence. If useMasterClock is true mseq->ptr should
        // never satisfy the if criterion.
        *cell = MEventAr_get(&mseq->events, MEventAr_last(&mseq->events), err);
        if (Error_iserror(err)) {
            return Midiseq_nextEventErrored;
        }
        return Midiseq_nextEventComplete;
    }

    MEvent c = MEventAr_get(&mseq->events, mseq->ptr, err);
    if (Error_iserror(err)) {
        return Midiseq_nextEventErrored;
    }

    Ticks t = c.t + mseq->startTime;
    Ticks diff = t-until >= 0 ? t-until : until-t;

    if ( (diff-1)/mseq->sequenceLength > 0) {
        Error_format(err, "INTERNAL ERROR %lld %lld %lld", diff, mseq->sequenceLength, diff/mseq->sequenceLength);
        return Midiseq_nextEventErrored;
    }

    *cell = c;
    cell->t = t;
    if (t > until) {
        return Midiseq_nextEventBreak;
    }

    mseq->ptr++;
    if (mseq->ptr >= Midiseq_len(mseq) && mseq->useMasterClock) {
        mseq->ptr        = 0;
        mseq->startTime += mseq->sequenceLength;
    }
    return Midiseq_nextEventContinue;
}


APIF int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err)
{
    if (mseq->startTime == 0) {
        return 1;
    }

    MEventAr_foreach(it, &mseq->events) {
        if (it.var->t + mseq->startTime >= t) {
            mseq->ptr = it.index;
            return 0;
        }
    }

    mseq->ptr = 0;
    return 0;
}


APIF Midiseq *Midiseq_fromfile(const char *fullpath, Error *err)
{
    char tempfile[] = "/tmp/MidiseqMaxMSPXXXXXX";
    FILE *fd = NULL;
    bool allOK = false;
    Midiseq *mseq = (Midiseq*)Mem_calloc(sizeof(Midiseq));
    Midiseq_init(mseq);
    MEventAr_truncate(&mseq->events);

    // Call midicsv. To do this we create a new destination file, then route our output to it
    String *buffer = NULL;
    int tempFd = mkstemp(tempfile);
    if (tempFd < 0) {
        Error_format0(err, "Failed to create temp file");
        goto END;
    }
    close(tempFd);

    buffer = String_fmt("'%s' '%s' > '%s'", Midiseq_midiCsvExecPath, fullpath, tempfile);    
    int exitCode = system(buffer);
    if (exitCode != 0) {
        Error_format(err, "Failed '%s' with exit code %d", buffer, exitCode);
        goto END;
    }

    // Open the result file and parse away
    fd = fopen(tempfile, "r");
    if (fd == NULL) {
        Error_format(err, "Failed to open temp file '%s'", tempfile);
        goto END;
    }

    int desiredPPQN = 480;
    float tickFactor = 1.0;

    // ons[i] holds the index-1 of the last note-on of pitch i. Or zero if there is no pending note-on
    int ons[128] = {0};
    int linenum = 0;
    while (true) {
        StringPtAr *fieldsAr = NULL;
        if (!midiseq_tokenize(fd, &fieldsAr, err)) {
            if (Error_iserror(err)) {
                goto END;
            }
            break;
        }
        linenum++;

        if (StringPtAr_len(fieldsAr) < 3) {
            Error_format(err, "Not enough fields in midicsv file '%s' line %d", tempfile, linenum);
            goto END;
        }

        int nfields   = StringPtAr_len(fieldsAr);

        // THIS IS AWEFUL. IMPORTANT you can't touch fields after you call _push or any other method that might reallocate.
        char **fields = (char**)fieldsAr->data;
        if (Error_iserror(err)) {
            goto END;
        }

        MEvent cell = {0};
        cell.t = (long)(tickFactor*Midiseq_convertInt(fields[1], err));
        if (Error_iserror(err)) {
            goto END;
        }

        const char *typ = fields[2];

        bool isOn = strcmp(typ, "Note_on_c") == 0;
        bool isOff = strcmp(typ, "Note_off_c") == 0;
        if ( isOn || isOff ) {
            if (nfields < 6) {
                Error_format(err, "Bad Note_on_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long pitch    = Midiseq_convertInt(fields[4], err);
            long velocity = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            if (velocity == 0) {
                isOn = false;
                isOff = true;
            }

            if (isOn) {
                cell.type = Midiseq_notetype;
                cell.b.b[0]  = (uint8_t)pitch;
                cell.b.b[1]  = (uint8_t)velocity;
                if (ons[pitch] != 0) {
                    Error_format(err, "Found an unbalanced NOTE-ON: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                Midiseq_push(mseq, cell);
                ons[pitch] = Midiseq_len(mseq);
            }
            else {
                if (ons[pitch] == 0) {
                    Error_format(err, "Found an unmatched note-off: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                int index = ons[pitch]-1;
                if (index >= Midiseq_len(mseq)) {
                    Error_format0(err, "INTERNAL ERROR");
                    goto END;
                }
                MEvent *c = Midiseq_get(mseq, index, err);
                if (Error_iserror(err)) {
                    goto END;
                }
                c->duration = cell.t - c->t;
                ons[pitch] = 0;
            }
        }
        else if (strcmp(typ, "Pitch_bend_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Pitch_bend_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long value = Midiseq_convertInt(fields[4], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type   = Midiseq_bendtype;
            cell.b.bend = value;
            Midiseq_push(mseq, cell);
        }
        else if (strcmp(typ, "Control_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Control_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long cc = Midiseq_convertInt(fields[4], err);
            long val  = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type = Midiseq_cctype;
            cell.b.b[0]  = (uint8_t)cc;
            cell.b.b[1]  = (uint8_t)val;
            Midiseq_push(mseq, cell);
        }
        else if (strcmp(typ, "Header") == 0) {
            if (nfields < 6) {
                Error_format(err, "Bad Header file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long ppqn = Midiseq_convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            tickFactor = (float)(desiredPPQN)/(float)(ppqn);
        }
        fields = NULL;
        nfields = 0;
    }

    // Compute length and install cycle and end group
    Midiseq_assignLength(mseq);
    MEvent cycle = {0};
    cycle.t = mseq->sequenceLength;
    cycle.type = Midiseq_cycletype;
    Midiseq_push(mseq, cycle);
    Midiseq_insertEndgroup(mseq, err);
    if (Error_iserror(err)) {
        Error_clear(err);
        goto END;
    }
    allOK = true;

    END:
    if (buffer != NULL) {
        String_free(buffer);
    }
    if (fd != NULL) {
        fclose(fd);
    }
    
    unlink(tempfile);

    if (allOK) {
        return mseq;
    }


    // Error state
    Midiseq_free(mseq);
    return NULL;
}

//
// P A T C H E R    F I N D
//
#line 1523 "src/midiseq.in.c"

#line 1547 "src/midiseq.in.c"

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

APIF void Pad_setSequence(Pad *pad, Midiseq *midi)
{
    if (Pad_sequence(pad) != NULL) {
        Midiseq_free(Pad_sequence(pad));
    }
    pad->sequence = midi;
}

APIF void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err) {
    BinFile_writeSymbol(bf, Pad_trackName(pad), err);
    Error_returnVoidOnError(err);    

    BinFile_writeInteger(bf, Pad_padIndex(pad), err);
    Error_returnVoidOnError(err);    

    Midiseq_toBinFile(Pad_sequence(pad), bf, err);
    Error_returnVoidOnError(err);

    BinFile_writeBool(bf, Pad_chokeGroupGlobal(pad), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, Pad_chokeGroupInstrument(pad), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, Pad_chokeGroupIndex(pad), err);
    Error_returnVoidOnError(err);
}

APIF Pad *Pad_fromBinFile(BinFile *bf, Error *err) {
    Pad *pad = Pad_new();
    Pad_fromBinFileUninitialized(pad, bf, err);
    if (Error_iserror(err)) {
        Mem_free(pad);
        return NULL;
    }
    return pad;
}

APIF void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err) {
    Pad_setTrackName(pad, BinFile_readSymbol(bf, err));
    Error_returnVoidOnError(err);

    Pad_setPadIndex(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);

    Pad_setSequence(pad, Midiseq_fromBinFile(bf, err));
    Error_returnVoidOnError(err);    

    Pad_setChokeGroupGlobal(pad, BinFile_readBool(bf, err));
    Error_returnVoidOnError(err);

    Pad_setChokeGroupInstrument(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);

    Pad_setChokeGroupIndex(pad, BinFile_readInteger(bf, err));
    Error_returnVoidOnError(err);
}

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

APIF void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, PadAr_len(&pl->pads), err);
    Error_returnVoidOnError(err);

    PadAr_foreach(it, &pl->pads) {
        Pad_toBinFile(it.var, bf, err);
        Error_returnVoidOnError(err);                
    }

    BinFile_writeTag(bf, "padlist_end", err);
    Error_returnVoidOnError(err);
}

APIF PadList *PadList_fromBinFile(BinFile *bf, Error *err) {
    PadList *pl = PadList_newN(0);
    PadList_fromBinFileInitialized(pl, bf, err);
    if (Error_iserror(err)) {
        PadList_free(pl);
        return NULL;
    }
    return pl;
}

// Remember the rul is that if there is an error, the PadList passed in remains uninitialized.
APIF void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    long len = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);
            
    for (int i = 0; i < len; i++) {
        Pad pad = {0};
        Pad_fromBinFileUninitialized(&pad, bf, err);
        Error_returnVoidOnError(err);
        PadAr_push(&pl->pads, pad);
    }
    BinFile_verifyTag(bf, "padlist_end", err);
    PadAr_fit(&pl->pads);
}

//
// T R A C K
//

APIF TrackList *TrackList_newBuild(PortFind *pf)
{
    TrackList *tl = TrackList_new();
    TrackList_build(tl, pf);
    return tl;
}

APIF void TrackList_build(TrackList *tl, PortFind *pf) {

    {
        // Insert the null track at position 1 of the tracklist
        Track t = {0};
        t.name  = Symbol_gen("null");
        t.noteManager = NoteManager_newFromPort(Port_null);
        TrackAr_push(&tl->list, t);
    }

    Error_declare(err);
    for (int i = 0; i < PortFind_portCount(pf); i++) {
        // Notice I don't handle any error that occures. I assume none do since I bound findByIndex by portCount
        Port *p = PortFind_findByIndex(pf, i, err);
        if (Error_maypost(err)) {
            continue;
        }
        Track t = {0};
        Track_setName(&t, Port_track(p));
        Track_setNoteManager(&t, NoteManager_newFromPort(p));
        TrackAr_push(&tl->list, t);
    }
    Error_clear(err);
    return;
}

APIF Track *TrackList_findTrackByName(TrackList *tl, Symbol *name)
{
    TrackAr_foreach(it, &tl->list) {
        if (it.var->name == name) {
            return it.var;
        }
    }

    // Always return the Null track if didn't find.
    Error_declare(err);
    Track *t = TrackAr_getp(&tl->list, 0, err);
    Error_clear(err);
    return t;        
}


APIF int TrackList_count(TrackList *tl)
{
    return TrackAr_len(&tl->list);
}


APIF Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err)
{
    return TrackAr_getp(&tl->list, index, err);
}

// NOTE: currently nothing is actually stored in the output file. The complete tracklist comes from a port find payload in the BinFile instance.
APIF TrackList *TrackList_fromBinFile(BinFile *bf, Error *err)
{
    PortFind *pf = BinFile_portFindPayload(bf);
    if (pf == NULL) {
        Error_format0(err, "Expected portFindPayload on BinFile, but didn't see one");
        return NULL;
    }

    return TrackList_newBuild(pf);
}

APIF void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err) {
    // NO-op since nothing in the tracklist is written to file.
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
// N O T E   M A N A G E R
//

const int NoteManager_atomcount = 4;


APIF NoteManager *NoteManager_newFromPort(Port *port)
{
    NoteManager *self = NoteManager_new();
    self->output      = port;
    return self;
}

APIF void NoteManager_userInit(NoteManager *self)
{
    self->atoms = Mem_calloc(sizeof(Atom) * NoteManager_atomcount);    
}

APIF void NoteManager_userClear(NoteManager *self) 
{
    Mem_free(self->atoms);
    self->atoms = NULL;
}

// insert a note off, and remove any single pitch that is already there. Return true if a note-off was removed
APIF bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup)
{
    Error_declare(ignored);
    bool q = false;
    IndexedOffAr_foreach(it, &manager->endgroups) {
        if (it.var->pitch == pitch) {
            IndexedOffAr_remove(&manager->endgroups, it.index, ignored);
            q = true;
            break;
        }
    }

    TimedOffAr_foreach(it, &manager->pending) {
        if (it.var->pitch == pitch) {
            TimedOffAr_remove(&manager->pending, it.index, ignored);
            q = true;
            break;
        }   
    }


    if (padIndexForEndgroup >= 0) {
        // Mark this pitch as endgroup
        IndexedOff_declare(off, padIndexForEndgroup, pitch);
        IndexedOffAr_binInsertPadIndex(&manager->endgroups, off);
    }
    else {
        TimedOff_declare(off, timestamp, pitch);
        TimedOffAr_binInsertTime(&manager->pending, off);
    }

    Error_maypost(ignored);

    return q;
}


// This is 10010000 which is a note-on (1001), on channel 0 (0000)
const int NOTEON_COMMAND = 144;

APIF void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity)
{
    Atom *av = manager->atoms;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(NOTEON_COMMAND);
    av[2] = Atom_fromInteger(pitch);
    av[3] = Atom_fromInteger(velocity);
    Error_declare(err);
    Port_send(manager->output, 0, 4, av, err);
    Error_maypost(err);
}


APIF void NoteManager_flushOffs(NoteManager *manager)
{
    IndexedOffAr_foreach(it, &manager->endgroups) {
        NoteManager_sendNoteOn(manager, it.var->pitch, 0);
    }
    IndexedOffAr_truncate(&manager->endgroups);

    TimedOffAr_foreach(it, &manager->pending) {
        NoteManager_sendNoteOn(manager, it.var->pitch, 0);   
    }
    TimedOffAr_truncate(&manager->pending);
}

APIF void NoteManager_allOff(NoteManager *manager)
{
    for (int i = 0; i < 128; i++) {
        NoteManager_sendNoteOn(manager, i, 0);      
    }
}

APIF void NoteManager_dblogPending(NoteManager *manager, Ticks current)
{
    dblog("dbPending %lld:", current);
    TimedOffAr_foreach(it, &manager->pending) {
        dblog("  %lld %d", it.var->time-current, it.var->pitch); 
    }
}


APIF Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current)
{
    Error_declare(err);
    int count = 0;
    TimedOffAr_foreach(it, &manager->pending) {
        if (it.var->time > current) {
            break;
        }
        NoteManager_sendNoteOn(manager, it.var->pitch , 0);
        count++;
    }
    if (count > 0) {
        TimedOffAr_removeN(&manager->pending, 0, count, err);
        Error_maypost(err);
    }
    
    TimedOffAr_foreach(it, &manager->pending) {
        return it.var->time-current;
    }

    return -1;
}


// padIndexForEndgroup should be -1 if this cell is not in an endgroup
APIF void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup)
{
    if (MEvent_type(cell) == Midiseq_notetype) {
        int pitch     = MEvent_notePitch(cell);
        int velocity  = MEvent_noteVelocity(cell);
        Ticks offtime = MEvent_t(cell) + MEvent_noteDuration(cell);

        if (NoteManager_insertNoteOff(manager, offtime, pitch, padIndexForEndgroup)) {
            NoteManager_sendNoteOn(manager, pitch, 0);
        }
        NoteManager_sendNoteOn(manager, pitch, velocity);
    }
}


APIF void NoteManager_padNoteOff(NoteManager *manager, int padIndex)
{
    IndexedOff_declare(off, padIndex, 0);
    IndexedOffArFIt_declare0(slice);
    slice = IndexedOffAr_binSearchPadIndex(&manager->endgroups, off);
    if (IndexedOffArFIt_atEnd(&slice)) {
        return;
    }
    IndexedOffAr_loop(slice) {
        NoteManager_sendNoteOn(manager, slice.var->pitch, 0);
    }
    IndexedOffAr_binRemovePadIndex(&manager->endgroups, off);
    return;
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

    Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
    PortRef_declare(portRef, cg, 0);
    DropDown_buildCGLocalGlobal(Hub_cgLocalGlobalMenu(hub), portRef);

    PortRef_set(portRef, cg, 1);
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
}

APIF void Hub_updateGuiCurrentCoordinates(Hub *hub) 
{
    Port_sendInteger(Hub_currBankPort(hub),  0, Hub_bank(hub));
    Port_sendInteger(Hub_currFramePort(hub), 0, Hub_frame(hub));
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
    Port_sendInteger(Hub_selBankPort(hub),  0, (long)Hub_selectedBank(hub));
    Port_sendInteger(Hub_selFramePort(hub), 0, (long)Hub_selectedFrame(hub));  
    Port_sendInteger(Hub_selPadPort(hub),   0, (long)Hub_relativeSelectedPad(hub));
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

    /*
    Hub *hub = (Hub*)hub_in;
    int ev = port_parseEvSymbol(Port_id(port));
    if (ev >= 0) {
        dblog("Ev sent to %d: inlet %ld", ev, inlet);
    } else if (Port_id(port) == Symbol_gen("chokeGroup")) {
        Error_declare(err);
        Hub_manageChokeGroups(hub, value, inlet, err);
        if (Error_maypost(err)) {
            // Reset pad b/c the drop down is now not consistent with the Pad
            Hub_changeSelectedPad(hub, Hub_selectedPad(hub), err);
            Error_maypost(err);
        }
    }
    */
}

APIF void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    PadList_toBinFile(Hub_padList(hub), bf, err);
    Error_returnVoidOnError(err);

    TrackList_toBinFile(Hub_trackList(hub), bf, err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}

APIF Hub *Hub_fromBinFile(BinFile *bf, Error *err) {
    // Hub *hub = Hub_newUninitialized();
    // Hub_fromBinFileUninitialized(hub, bf, err);
    // if (Error_iserror(err)) {
    //     Hub_free(hub);
    //     return NULL;
    // }
    // return hub;
    return NULL;
}

APIF void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    Hub_setPadList(hub, PadList_fromBinFile(bf, err));
    Error_returnVoidOnError(err);
    
    Hub_setTrackList(hub, TrackList_fromBinFile(bf, err));
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}


//
// B I N    F I L E
//

// APIF BinFile *BinFile_new() {
//     BinFile *bf = Mem_calloc(sizeof(BinFile));
//     bf->filename = String_empty();
//     bf->buffer   = String_empty();
//     return bf;
// }

APIF BinFile *BinFile_newWriter(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_setStream(bf, fopen(file, "w"));
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    String_free(bf->filename);
    bf->filename = String_fmt("%s", file);

    if (fprintf(BinFile_stream(bf), "%d ", BinFile_version(bf)) < 0) {
        Error_format(err, "Failed to write version number to file %s", file);
        BinFile_free(bf);
        return NULL;
    }

    return bf;
}

APIF BinFile *BinFile_newReader(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_setStream(bf, fopen(file, "r"));
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    bf->filename = String_fmt("%s", file);
    if (fscanf(BinFile_stream(bf), "%d ", &bf->version)) {
        Error_format(err, "Failed to read version number from file  %s", file);
        BinFile_free(bf);
        return NULL;
    }
    return bf;
}

// APIF void BinFile_free(BinFile *bf) {
//     if (BinFile_stream(bf) != NULL) {
//         fclose(BinFile_stream(bf));
//         BinFile_setStream(bf, NULL);
//     }
//     String_free(bf->filename);
//     String_free(bf->buffer);
//     Mem_free(bf);
// }

APIF void BinFile_userClear(BinFile *bf) {
    if (BinFile_stream(bf) != NULL) {
        fclose(BinFile_stream(bf));
        BinFile_setStream(bf, NULL);
    }
}


APIF int binFile_hexDigitToInt(char hex) {
    switch (hex) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
    }
    return 0;
}
APIF char binFile_intToHexDigit(int digit) {
    switch (digit) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
    }
    return 0;
}

APIF off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err) {
    errno = 0;
    off_t start = BinFile_tell(bf, err);
    Error_returnZeroOnError(err);

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "s ");
    if (fprintf(BinFile_stream(bf), format, "") < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return 0;
    }
    if (spaceForFlags) {
        if (fprintf(BinFile_stream(bf), "0000 ") < 0) {
            Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
            return 0;
        }
    }
    return start;
} 

APIF void BinFile_writeFlags(BinFile *bf, long flags, Error *err) {
    char hex[4] = {
        binFile_intToHexDigit((flags)       & 0xFF),
        binFile_intToHexDigit((flags >> 8)  & 0xFF),
        binFile_intToHexDigit((flags >> 16) & 0xFF),
        binFile_intToHexDigit((flags >> 24) & 0xFF),
    };
    if (fprintf(BinFile_stream(bf), "%c%c%c%c ", hex[0], hex[1], hex[2], hex[3]) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err) {
    off_t end = BinFile_tell(bf, err);
    Error_returnVoidOnError(err);

    long length = (long)(end-location);
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (fseeko(BinFile_stream(bf), location, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[1] while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        length = -length;
    }

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "ld ");
    if (fprintf(BinFile_stream(bf), format, length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

    if (fseeko(BinFile_stream(bf), end, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[2] while writing %s", BinFile_filename(bf));
        return;
    }
    
    return;
}

APIF void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err) {
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        length = -length;
    }
    if (fprintf(BinFile_stream(bf), "%ld ", length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

}

APIF long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err) {
    long length;
    char space;
    if (fscanf(BinFile_stream(bf), " %ld%c", &length, &space) != 2 || space != ' ') {
        Error_format(err, "Failed sscanf[1] while reading %s", BinFile_filename(bf));
        return 0;   
    }
    if (length < 0) {
        length = -length;
        char f[4] = "\0\0\0\0";
        if (fscanf(BinFile_stream(bf), "%c%c%c%c%c", f+0, f+1, f+2, f+3, &space) != 5 || space != ' ') {
            Error_format(err, "Failed sscanf[2] while reading %s", BinFile_filename(bf));
            return 0;   
        }   
        if (flags != NULL) {
            *flags = 0;
            for (int i = 0; i < 4; i++) {
                int v = binFile_hexDigitToInt(f[i]) << i*8;
                *flags = *flags | v;
            }
        }
    }
    return length;
}

APIF off_t BinFile_tell(BinFile *bf, Error *err) {
    errno = 0;
    off_t location = ftello(BinFile_stream(bf));
    if (errno != 0) {
        Error_format(err, "Failed ftello while working with %s", BinFile_filename(bf));
        return 0;
    }
    return location;
}

APIF void BinFile_fillBuffer(BinFile *bf, long size, Error *err) {
    // Want buffer to contain size+1 characters INCLUDING the null byte
    if (String_len(bf->buffer) < size) {
        // NOTE: I verified that this call DOES NOT shrink the buffer.
        // NOTE: sdsMakeRoomFor always allocates sdslen()+1 bytes  
        String_resize(&bf->buffer, size);
    }
    
    if (fread((char*)bf->buffer, size, 1, BinFile_stream(bf)) != size) {
        Error_format(err, "Failed fread while working with %s", BinFile_filename(bf));
        return;   
    }
    // NOTE: this means that the buffer can be used like a string in the correct context. IT DOES NOT say that there aren't
    // other nulls embedded in the string. I think that the way I'm preparing this string, there might be 2 nulls at the end
    // of it. 
    char *p = (char*)bf->buffer;
    p[size] = '\0';
}

APIF void BinFile_writeInteger(BinFile *bf, long value, Error *err) {
    // XXX: BORKEN
    // sdsclear(BinFile_buffer(bf));
    // sdscatprintf(BinFile_buffer(bf), "%ld", value);
    


    BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 0, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF long BinFile_readInteger(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    long value = 0;
    if (sscanf(BinFile_buffer(bf), "%ld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

APIF void BinFile_writeString(BinFile *bf, String *value, Error *err) {
    BinFile_writeLength(bf, String_len(value), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

}

// must call sdsfree on any non-NULL return value
APIF String *BinFile_readString(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);    
    
    return String_dup(BinFile_buffer(bf));
}

APIF void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err) {
    BinFile_writeString(bf, Symbol_cstr(value), err);
    return;
}

APIF Symbol *BinFile_readSymbol(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);
    
    return Symbol_gen(BinFile_buffer(bf));
}

APIF void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err) {
    // XXX: BORKEN
    // sdsclear(BinFile_buffer(bf));
    // sdscatprintf(BinFile_buffer(bf), "%lld", value);

    BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF Ticks BinFile_readTicks(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    Ticks value = 0;
    if (sscanf(BinFile_buffer(bf), "%lld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

APIF void BinFile_writeBool(BinFile *bf, bool value, Error *err) {
    BinFile_writeInteger(bf, value ? 1 : 0, err);
}

APIF bool BinFile_readBool(BinFile *bf, Error *err) {
    return BinFile_readInteger(bf, err) ? true : false;
}

APIF void BinFile_writeTag(BinFile *bf, const char *tag, Error *err) {
    int len = strlen(tag);
    BinFile_writeLengthFlags(bf, len, BinFileFlag_tag, err);
    Error_returnVoidOnError(err);

    if (fwrite(tag, len, 1, BinFile_stream(bf)) != len) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

APIF void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err) {
    long flags  = 0;
    long length = BinFile_readLengthFlags(bf, &flags, err);
    Error_returnVoidOnError(err);
    if (flags & BinFileFlag_tag) {
        Error_format0(err, "Expected flag marked with BinFileFlag_tag");
        return;
    }
    BinFile_fillBuffer(bf, length, err);
    if (strcmp(tag, BinFile_buffer(bf)) != 0) {
        Error_format(err, "Expected tag '%s', but found '%s'", tag, BinFile_buffer(bf));
        return;
    }
    return;
}






#line 17 "src/sequence.in.c"

#define MusicalContext_declareDefault(name) MusicalContext name = {.ticksPerQuarterNote = 480, .quarterNotesPerMeasure = 4}

#line 36 "src/sequence.in.c"

// This is the decimal representation of binary 10010000
#define NOTEON_COMMAND 144

#ifdef TEST_BUILD
Ticks Ticks_dbCurrent = 0;
NoteEventAr *NoteOutlet_dbSent = NULL;
APIF void NoteOutlet_dbRewindSent() 
{
    if (NoteOutlet_dbSent != NULL) {
        NoteEventAr_truncate(NoteOutlet_dbSent);    
    }
}
#endif

APIF void NoteOutlet_sendNote(NoteOutlet *self, uint8_t pitch, uint8_t velocity)
{
#   ifdef TEST_BUILD
    if (NoteOutlet_dbSent == NULL) {
        NoteOutlet_dbSent = NoteEventAr_new(0);
    }
    NoteEvent e = {.pitch = pitch, .velocity = velocity, .stime = Ticks_dbCurrent, .duration = 0};
    NoteEventAr_push(NoteOutlet_dbSent, e);
#   else
    Atom *av = self->atoms.data;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(NOTEON_COMMAND);
    av[2] = Atom_fromInteger(pitch);
    av[3] = Atom_fromInteger(velocity);
    Error_declare(err);
    Port_send(self->port, 0, 4, av, err);
    Error_maypost(err);
#   endif
}

APIF NoteOutlet *NoteOutlet_newBuild(Port *port)
{
    NoteOutlet *self = NoteOutlet_new();
    self->port       = port;
    AtomAr_changeLength(&self->atoms, 4);
    return self;
}

#line 99 "src/sequence.in.c"

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
    Atom *av = self->atoms;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(CC_COMMAND);
    av[2] = Atom_fromInteger(self->cc);
    av[3] = Atom_fromInteger(v);
    Error_declare(err);
    PortRef_send(ref, 0, 4, av, err);
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

#line 158 "src/sequence.in.c"

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
    Atom *av = self->atoms;
    av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
    av[1] = Atom_fromInteger(BEND_COMMAND);
    av[2] = Atom_fromInteger(msb);
    av[3] = Atom_fromInteger(lsb);
    Error_declare(err);
    PortRef_send(ref, 0, 4, av, err);
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


#line 218 "src/sequence.in.c"

APIF void VstOutlet_sendFloat(VstOutlet *self, double value)
{
}

#line 235 "src/sequence.in.c"


#line 258 "src/sequence.in.c"

#line 270 "src/sequence.in.c"

OutletSpecifier OutletSpecifier_makeCC(Symbol *track, int cc) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*cc");
    self->paramIndex  = cc;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeBend(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*bend");
    self->paramIndex  = 0;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeNote(Symbol *track) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = 0;
    self->parameter   = Symbol_gen("*note");
    self->paramIndex  = 0;
    return selfValue;
}

OutletSpecifier OutletSpecifier_makeVst(Symbol *track, int pluginIndex, Symbol *parameter) {
    OutletSpecifier selfValue = {0}, *self = &selfValue;
    OutletSpecifier_init(self);
    self->track       = track;
    self->pluginIndex = pluginIndex;
    self->parameter   = parameter;
    self->paramIndex  = 0;
    return selfValue;
}


#line 332 "src/sequence.in.c"

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



#line 407 "src/sequence.in.c"

APIF int NoteEvent_cmp(NoteEvent *left, NoteEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    } else if (left->pitch < right->pitch) {
        return -1;
    } else if (left->pitch > right->pitch) {
        return 1;
    }
    return 0;
}

#line 484 "src/sequence.in.c"

APIF NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind)
{
    NoteSequence *self    = NoteSequence_new();
    self->outletSpecifier = OutletSpecifier_makeNote(track);
    self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
    return self;
}

APIF NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv)
{
    NoteSequence *self = NoteSequence_newTrack(track, portFind);
    NoteEventAr_truncate(&self->events);
    for (int i = 0; i < argc; i++) {
        NoteEventAr_push(&self->events, argv[i]);
    }
    NoteSequence_makeConsistent(self);
    NoteEventAr_rforeach(it, &self->events) {
        self->sequenceLength = it.var->stime;
        break;
    }
    return self;
}

Ticks NoteSequence_cycleDuration      = -1;
Ticks NoteSequence_endgDuration       = -2;
Ticks NoteSequence_noteOffDuration    = -3;
#define NoteSequence_isMarkerValue(v) (v < 0)
#define NoteSequence_minSequenceLength 5
static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOffEvent = -1;
    int nremoves = 0;
    TimedOffAr_foreach(it, &self->offs) {
        if (it.var->time > current) {
            self->nextOffEvent = it.var->time;
            break;
        }
        Outlet_sendNote(self->outlet, it.var->pitch, 0, err);
        nremoves++;
    }
    if (nremoves > 0) {
        TimedOffAr_removeN(&self->offs, 0, nremoves, err);
        Error_maypost(err);
    }
}

static inline void NoteSequence_playNoteOns(NoteSequence *self, Ticks current, Error *err) 
{
    self->nextOnEvent = -1;
    for (;;) {
        NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
            NoteEvent *ne = it.var;
            if (ne->stime + self->startTime > current) {
                self->nextOnEvent = ne->stime + self->startTime;
                return;
            }
            if (!NoteSequence_isMarkerValue(ne->duration)) {
                TimedOff off = {.time = self->startTime + ne->stime + ne->duration, .pitch = ne->pitch};
                TimedOffAr_binInsertTime(&self->offs, off);
                Outlet_sendNote(self->outlet, ne->pitch, ne->velocity, err);
            } else if (ne->duration == NoteSequence_endgDuration) {
                self->inEndgroup = true;
            } 

            if (self->recordingSeq != NULL && !NoteSequence_isMarkerValue(ne->duration)) {
                NoteEvent e = *ne;
                e.stime     = self->recordingSeq->startTime + ne->stime;
                NoteEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= NoteSequence_minSequenceLength) {
               self->sequenceLength = NoteSequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
        } else {
            return;
        }
    }
}

static inline Ticks NoteSequence_nextEvent(NoteSequence *self) {
    if (self->nextOnEvent < 0 && self->nextOffEvent < 0) {
        return -1;
    } else if (self->nextOffEvent < 0) {
        return self->nextOnEvent;
    } else if (self->nextOnEvent < 0) {
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
        if (self->sequenceLength <= NoteSequence_minSequenceLength) {
            self->sequenceLength = NoteSequence_minSequenceLength;
        }
        while (current - self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        NoteEventAr_foreach(it, &self->events) {
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
        NoteEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }

    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        NoteSequence *other = NoteSequence_recordClone(self);
        other->startTime    = self->startTime;
        self->recordingSeq  = other; 
        RecordBuffer_push(recordBuffer, NoteSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
}

APIF void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err) {
    self->cursor       = NoteEventAr_len(&self->events);
    self->version++;

    if (self->recordingSeq != NULL) {
        // In the recording sequence Adjust the duration of all the pending note-offs
        TimedOffAr_foreach(offIt, &self->offs) {
            NoteEventAr_rforeach(noteIt, &self->recordingSeq->events) {
                if (noteIt.var->pitch == offIt.var->pitch) {
                    noteIt.var->duration = current - noteIt.var->stime;
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
    NoteSequence_playNoteOns(self, current, err);
    Ticks nextEvent = NoteSequence_nextEvent(self);
    if (nextEvent >= 0) {
        TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
    }
}

APIF void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current, Error *err) 
{
    if (self->inEndgroup && !self->cycle) {
        NoteSequence_stop(self, current, err);
    }
}

APIF OutletSpecifier *NoteSequence_outSpec(NoteSequence *self)
{
    return &self->outletSpecifier;
}

APIF NoteSequence *NoteSequence_recordClone(NoteSequence *self)
{
    NoteSequence *other    = NoteSequence_new();
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = NullOutlet_castToOutlet(NullOutlet_new());
    return other;
}   

APIF void NoteSequence_makeConsistent(NoteSequence *self)
{
    int timeNextNoteStart[128] = {0};
    for (int i = 0; i < 128; i++) {
        timeNextNoteStart[i] = INT_MAX;
    }
    NoteEventAr_sort(&self->events);
    NoteEventAr_rforeach(it, &self->events) {
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
}

#line 731 "src/sequence.in.c"

APIF int FloatEvent_cmp(FloatEvent *left, FloatEvent *right)
{
    if (left->stime < right->stime) {
        return -1;
    } else if (left->stime > right->stime) {
        return 1;
    }
    return 0;
}

#line 795 "src/sequence.in.c"

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
    FloatEventAr_truncate(&self->events);
    for (int i = 0; i < argc; i++) {
        FloatEventAr_push(&self->events, argv[i]);
    }
    FloatSequence_makeConsistent(self);
    return self;
}


double FloatSequence_endgMarker  = -1.0e40;
double FloatSequence_cycleMarker = -1.0e41;
#define FloatSequence_isMarkerValue(v) (v < 1e10)

APIF void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) {
    int nevents = FloatEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    Ticks nextEvent    = 0;
    if (self->cycle) {
        if (self->sequenceLength <= NoteSequence_minSequenceLength) {
            self->sequenceLength = NoteSequence_minSequenceLength;
        }
        while (current-self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        FloatEventAr_foreach(it, &self->events) {
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
        FloatEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }

    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        FloatSequence *other = FloatSequence_recordClone(self);
        other->startTime    = self->startTime;
        self->recordingSeq  = other;    
        RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
    }

    TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
}

APIF void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err) {
    self->cursor       = FloatEventAr_len(&self->events);
    self->recordingSeq = NULL;
    Outlet_sendFloat(self->outlet, self->restoreValue, err);
}

APIF void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err) {
    Ticks nextEvent = -1;
    for (;;) {
        FloatEventAr_foreachOffset(it, &self->events, self->cursor) {
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
                FloatEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= NoteSequence_minSequenceLength) {
                self->sequenceLength = NoteSequence_minSequenceLength;
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

APIF void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current, Error *err) {
    if (self->inEndgroup) {
        Outlet_sendFloat(self->outlet, self->restoreValue, err);
    }
}

APIF OutletSpecifier *FloatSequence_outSpec(FloatSequence *self)
{
    return &self->outletSpecifier;
}

APIF FloatSequence *FloatSequence_recordClone(FloatSequence *self)
{
    FloatSequence *other   = FloatSequence_new();
    other->outletSpecifier = self->outletSpecifier;
    other->outlet          = NullOutlet_castToOutlet(NullOutlet_new());
    return other;
}

APIF void FloatSequence_makeConsistent(FloatSequence *self)
{
    FloatEventAr_sort(&self->events);
    double seen = -1;
    FloatEventAr_rforeach(it, &self->events) {
        if (seen == it.var->stime) {
            FloatEventArRIt_remove(&it);
        }
        seen = it.var->stime;
    }
}


#line 1029 "src/sequence.in.c"

APIF void Sequence_freePpErrless(Sequence **s)
{
    Error_declare(err);
    Sequence_free(*s, err);
    Error_maypost(err);
}

APIF int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq) {
    Error_declare(err);
    OutletSpecifier *left  = Sequence_outSpec(leftSeq, err);
    OutletSpecifier *right = Sequence_outSpec(rightSeq, err);
    Error_clear(err);

    int q = Symbol_cmp(OutletSpecifier_track(left), OutletSpecifier_track(right));
    if (q) {
        return q;
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

#line 1110 "src/sequence.in.c"

APIF void RecordBuffer_push(RecordBuffer *self, Sequence *sequence)
{
    SequenceAr_push(&self->sequences, sequence);
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

MidiEvent Midi_getNextEvent(FILE *pipe, Error *err)
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
//NullOutlet_castToOutlet(NullOutlet_new());
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
                    NoteEventAr_rforeach(it, &noteSeq->events) {
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
                    NoteEventAr_push(&noteSeq->events, newEv);
                }
                break;
            }
            case Midi_bendEventType: {
                if (bendSeq == NULL) {
                    bendSeq = FloatSequence_newBend(defaultTrack, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg1};
                FloatEventAr_push(&bendSeq->events, newEv);
                break;
            }
            case Midi_ccEventType: {
                if (ccSeqs[ev.arg1] == NULL) {
                    ccSeqs[ev.arg1] = FloatSequence_newCc(defaultTrack, ev.arg1, portFind);
                }
                FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg2};
                FloatEventAr_push(&(ccSeqs[ev.arg1])->events, newEv);
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
    Ticks endGroupTime = 0;
    if (noteSeq != NULL) {
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (it.var->duration == NoteSequence_noteOffDuration) {
                Error_format(err, "Unpaired note-on at %lld", it.var->stime);
                goto END;
            }
        }

        // Install endgroup
        Ticks endTime = -1;
        int endIndex  = -1;
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (endTime < 0) {
                endTime  = it.var->stime;
                endIndex = it.index;
                continue;
            } else if (it.var->stime != endTime) {
                break;
            } else {
                endIndex = it.index;
            }
        }
        if (endTime >= 0) {
            NoteEvent newEv = {.stime = endTime, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
            NoteEventAr_insert(&noteSeq->events, endIndex, newEv, err);
            Error_gotoLabelOnError(err, END);
            endGroupTime = endTime;
        } 
    }

    
    if (bendSeq != NULL) {
        int insertIndex = 0;
        FloatEventAr_rforeach(it, &bendSeq->events) {
            if (it.var->stime > endGroupTime) {
                insertIndex = it.index;
            } else {
                break;
            }
        }
        FloatEvent newEv = {.stime = endGroupTime, .value = FloatSequence_endgMarker};
        FloatEventAr_insert(&bendSeq->events, insertIndex, newEv, err);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            int insertIndex = 0;
            FloatEventAr_rforeach(it, &bendSeq->events) {
                if (it.var->stime > endGroupTime) {
                    insertIndex = it.index;
                } else {
                    break;
                }
            }
            FloatEvent newEv = {.stime = endGroupTime, .value = FloatSequence_endgMarker};
            FloatEventAr_insert(&(ccSeqs[i]->events), insertIndex, newEv, err);
            Error_gotoLabelOnError(err, END);       
        }
    }


    //
    // Compute length
    //
    Ticks lastTime = 0;
    if (noteSeq != NULL) {
        NoteEventAr_rforeach(it, &noteSeq->events) {
            if (it.var->stime > lastTime) {
                lastTime = it.var->stime;
            }
            break;
        }
    }
    if (bendSeq != NULL) {
        FloatEventAr_rforeach(it, &bendSeq->events) {
            if (it.var->stime > lastTime) {
                lastTime = it.var->stime;
            }
            break;
        }
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatEventAr_rforeach(it, &(ccSeqs[i]->events)) {
                if (it.var->stime > lastTime) {
                    lastTime = it.var->stime;
                }
                break;
            }       
        }
    }

    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < NoteSequence_minSequenceLength) {
        seqLen = NoteSequence_minSequenceLength;
    }
    //
    // Set each sequence length
    //
    if (noteSeq != NULL) {
        noteSeq->sequenceLength = seqLen;
        NoteEvent newEv = {.stime = seqLen, .duration = NoteSequence_cycleDuration, .pitch = 0, .velocity = 0};
        NoteEventAr_push(&noteSeq->events, newEv);
    }
    if (bendSeq != NULL) {
        bendSeq->sequenceLength = seqLen;
        FloatEvent newEv = {.stime = seqLen, .value = FloatSequence_cycleMarker};
        FloatEventAr_push(&bendSeq->events, newEv);
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            ccSeqs[i]->sequenceLength = seqLen;
            FloatEvent newEv = {.stime = seqLen, .value = FloatSequence_cycleMarker};
            FloatEventAr_push(&(ccSeqs[i]->events), newEv);       
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
        NoteSequence_makeConsistent(noteSeq);
        SequenceAr_push(output, NoteSequence_castToSequence(noteSeq));
    }
    if (bendSeq != NULL) {
        FloatSequence_makeConsistent(bendSeq);
        SequenceAr_push(output, FloatSequence_castToSequence(bendSeq));
    }
    for (int i = 0; i < 128; i++) {
        if (ccSeqs[i] != NULL) {
            FloatSequence_makeConsistent(ccSeqs[i]);
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
#line 24 "test/for_tarray.in.c"

#line 32 "test/for_tarray.in.c"

const int maxNumRecorded = 10;
int numRecorded          = 0;
Foo recorded[maxNumRecorded] = {0};

APIF void Foo_recorder(Foo *self)
{
	if (numRecorded < maxNumRecorded) {
		recorded[numRecorded++] = *self;
	}
}

APIF int Foo_cmp(Foo *left, Foo *right) 
{
	if (left->i < right->i) {
		return -1;
	} else if (left->i > right->i) {
		return 1;
	}
	return 0;
}

APIF int Foo_cmpBoth(Foo *left, Foo *right) 
{
	int q = Foo_cmp(left, right);
	if (q) {
		return q;
	}

	if (left->d < right->d) {
		return -1;
	} else if (left->d > right->d) {
		return 1;
	}

	return 0;
}


void Foo_zeroRecord() {
	numRecorded = 0;
	memset(recorded, 0, sizeof(Foo)*maxNumRecorded);
}





APIF Port *Port_newTrackId(Symbol *track, Symbol *id)
{
	Port *self = Mem_calloc(sizeof(Port));
	self->obj.utilityPointer = AtomArAr_new(0);
	self->track              = track;
	self->id                 = id;
	return self;
}

APIF void Port_free(Port *self)
{
	if (self->obj.utilityPointer != NULL) {
		AtomArAr_free(self->obj.utilityPointer);
	}
	Mem_free(self);
}

APIF PortFind *PortFind_newFromTable(int argc, PortFindCell *cells)
{
    PortFind *self = PortFind_new();
    for (int i = 0; i < argc; i++) {
        PortFindCellAr_push(&self->objects, cells[i]);       
    }
    return self;
}

APIF PortFind *PortFind_createStandardSpoof()
{
	const int ncells = 3;
	PortFindCell cells[ncells] = {
		{.reciever = Port_newTrackId(Symbol_gen("piano"),  Symbol_gen("idPiano")),  .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("guitar"), Symbol_gen("idGuitar")), .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("drums"),  Symbol_gen("idDrums")),  .varname = Symbol_gen("unknown")},
	};
	return PortFind_newFromTable(ncells, cells);
}

APIF void PortFind_userClear(PortFind *self)
{
	PortFindCellAr_foreach(it, &self->objects) {
		Port_free(it.var->reciever);
	}
}
