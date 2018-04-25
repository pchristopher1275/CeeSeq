// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
// *** DO NOT MODIFY THIS FILE generated 04/24/2018 23:08:52 ***
const bool Coverage_activated = true;
const char **Coverage_array   = NULL;
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
struct Resource_t;
typedef struct Resource_t Resource;
typedef struct Dispatch_t SelectNextPushedPadDispatch;
struct Sequence_t;
typedef struct Sequence_t Sequence;
struct SequenceAr_t;
typedef struct SequenceAr_t SequenceAr;
struct SequenceDrive_t;
typedef struct SequenceDrive_t SequenceDrive;
struct SequenceDriveDirective_t;
typedef struct SequenceDriveDirective_t SequenceDriveDirective;
struct SequenceDriveDirectivePq_t;
typedef struct SequenceDriveDirectivePq_t SequenceDriveDirectivePq;
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

struct SequenceDriveDirective_t
{
    Ticks time;
    int directive;
    SequenceAr *sequences;
};
typedef struct SequenceDriveDirectivePq_t {
   int len;
   int cap;
   int elemSize;
   void (*clearer)(SequenceDriveDirective*);
   SequenceDriveDirective *data;
} SequenceDriveDirectivePq;

typedef struct SequenceDriveDirectivePqFIt_t {
   SequenceDriveDirectivePq *arr;
   int lBound;
   int uBound;

   int index;
   SequenceDriveDirective *var;
} SequenceDriveDirectivePqFIt;

typedef struct SequenceDriveDirectivePqRIt_t {
   SequenceDriveDirectivePq *arr;
   int lBound;
   int uBound;

   int index;
   SequenceDriveDirective *var;
} SequenceDriveDirectivePqRIt;

struct SequenceDrive_t
{
    SequenceDriveDirectivePq directives;
    TimedPq *queue;
    Ticks timeStop;
    Ticks timeDelta;
    int maxIterations;
};
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

struct OutletSpecifier_t
{
    Symbol *track;
    int pluginIndex;
    Symbol *parameter;
    int paramIndex;
};
struct Sequence_t
{
    int itype;
    long version;
    Ticks startTime;
    OutletSpecifier outletSpecifier;
};
struct SelectNextPushedPadDispatch_t
{
    int itype;
};
struct Resource_t
{
    String *songLibrary;
    String *songName;
    time_t lastTime;
    int batchIndex;
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
    OutletSpecifier outletSpecifier;
    Ticks sequenceLength;
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
struct DropDown_t
{
    SymbolPtrAr table;
    int selected;
    PortRef portRef;
};
struct Arguments_t
{
    Symbol *s1;
    long i1;
    long i2;
    long ivalue;
    long inlet;
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
    OutletSpecifier outletSpecifier;
    Ticks sequenceLength;
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
Symbol *Symbol_gen(const char *word);
void Symbol_freeAll();
Port *Port_new();
void Port_init(Port *p);
void Port_free(Port *p);
void Port_clear(Port *p);
int port_parseEvSymbol(Symbol *id);
void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err);
void Port_sendInteger(Port *self, int outlet, long value, Error *err);
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
NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv, Error *err);
void NoteSequence_start(NoteSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err);
void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err);
void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err);
void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current, Error *err);
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
void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current, Error *err);
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
void RecordBuffer_push(RecordBuffer *self, Sequence *sequence);
void RecordBuffer_compact(RecordBuffer *self, SequenceAr *output, Error *err);
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
PortFind *PortFind_createStandardSpoof(void);
void PortFind_userClear(PortFind *self);
void NoteOutlet_dbRewindSent();
void NoteOutlet_dbRecordEvent(int pitch, int velocity);
void NoteOutlet_dbGetResults(NoteEventAr *arr);
void NoteOutlet_dbReportNoteOffs(NoteEventAr *arr);
int SequenceDriveDirective_cmp(SequenceDriveDirective *left, SequenceDriveDirective *right);
void SequenceDrive_toCompletion(SequenceDrive *self, Error *err);
void Resource_listDirectory(Resource *self, String *path, Error *err);
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
void Resource_clear(Resource *self);
void Resource_free(Resource *self);
void Resource_init(Resource *self);
Resource *Resource_new();
void SelectNextPushedPadDispatch_clear(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_free(SelectNextPushedPadDispatch *self);
void SelectNextPushedPadDispatch_init(SelectNextPushedPadDispatch *self);
SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_new();
void SequenceDrive_clear(SequenceDrive *self);
void SequenceDrive_free(SequenceDrive *self);
void SequenceDrive_init(SequenceDrive *self);
SequenceDrive *SequenceDrive_new();
void SequenceDriveDirective_clear(SequenceDriveDirective *self);
void SequenceDriveDirective_free(SequenceDriveDirective *self);
void SequenceDriveDirective_init(SequenceDriveDirective *self);
SequenceDriveDirective *SequenceDriveDirective_new();
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
#define Interface_itype(self) (self->itype) 
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
Sequence *Sequence_compactNew(Sequence *self, Ticks a1, Error *err);
void Sequence_compactConcat(Sequence *self, Sequence *a1, Error *err);
void Sequence_compactSortEvents(Sequence *self, Error *err);
Ticks Sequence_compactComputeSequenceLength(Sequence *self, Error *err);
void Sequence_compactFinish(Sequence *self, Ticks a1, Ticks a2, Error *err);
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
static inline OutletSpecifier FloatSequence_outletSpecifier(FloatSequence *self){return self->outletSpecifier;}
static inline void FloatSequence_setOutletSpecifier(FloatSequence *self, OutletSpecifier value){self->outletSpecifier = value;}
static inline Ticks FloatSequence_sequenceLength(FloatSequence *self){return self->sequenceLength;}
static inline void FloatSequence_setSequenceLength(FloatSequence *self, Ticks value){self->sequenceLength = value;}
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
static inline OutletSpecifier NoteSequence_outletSpecifier(NoteSequence *self){return self->outletSpecifier;}
static inline void NoteSequence_setOutletSpecifier(NoteSequence *self, OutletSpecifier value){self->outletSpecifier = value;}
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
static inline String *Resource_songLibrary(Resource *self){return self->songLibrary;}
static inline void Resource_setSongLibrary(Resource *self, String *value){self->songLibrary = value;}
static inline String *Resource_songName(Resource *self){return self->songName;}
static inline time_t Resource_lastTime(Resource *self){return self->lastTime;}
static inline void Resource_setLastTime(Resource *self, time_t value){self->lastTime = value;}
static inline int Resource_batchIndex(Resource *self){return self->batchIndex;}
static inline void Resource_setBatchIndex(Resource *self, int value){self->batchIndex = value;}
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
static inline Ticks Sequence_startTime(Sequence *self){return self->startTime;}
static inline void Sequence_setStartTime(Sequence *self, Ticks value){self->startTime = value;}
static inline OutletSpecifier Sequence_outletSpecifier(Sequence *self){return self->outletSpecifier;}
static inline void Sequence_setOutletSpecifier(Sequence *self, OutletSpecifier value){self->outletSpecifier = value;}
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

static inline SequenceDriveDirectivePq SequenceDrive_directives(SequenceDrive *self){return self->directives;}
static inline void SequenceDrive_setDirectives(SequenceDrive *self, SequenceDriveDirectivePq value){self->directives = value;}
static inline TimedPq *SequenceDrive_queue(SequenceDrive *self){return self->queue;}
static inline void SequenceDrive_setQueue(SequenceDrive *self, TimedPq *value){self->queue = value;}
static inline Ticks SequenceDrive_timeStop(SequenceDrive *self){return self->timeStop;}
static inline void SequenceDrive_setTimeStop(SequenceDrive *self, Ticks value){self->timeStop = value;}
static inline Ticks SequenceDrive_timeDelta(SequenceDrive *self){return self->timeDelta;}
static inline void SequenceDrive_setTimeDelta(SequenceDrive *self, Ticks value){self->timeDelta = value;}
static inline int SequenceDrive_maxIterations(SequenceDrive *self){return self->maxIterations;}
static inline void SequenceDrive_setMaxIterations(SequenceDrive *self, int value){self->maxIterations = value;}
static inline Ticks SequenceDriveDirective_time(SequenceDriveDirective *self){return self->time;}
static inline void SequenceDriveDirective_setTime(SequenceDriveDirective *self, Ticks value){self->time = value;}
static inline int SequenceDriveDirective_directive(SequenceDriveDirective *self){return self->directive;}
static inline void SequenceDriveDirective_setDirective(SequenceDriveDirective *self, int value){self->directive = value;}
static inline SequenceAr *SequenceDriveDirective_sequences(SequenceDriveDirective *self){return self->sequences;}
static inline void SequenceDriveDirective_setSequences(SequenceDriveDirective *self, SequenceAr *value){self->sequences = value;}
static inline void SequenceDriveDirectivePq_changeLength(SequenceDriveDirectivePq *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void SequenceDriveDirectivePq_clear(SequenceDriveDirectivePq *arr) {
    Array_clear((Array*)arr);
    SequenceDriveDirectivePq zero = {0};
    *arr = zero;
}

#define SequenceDriveDirectivePq_each(it, arr) for (SequenceDriveDirective* it = arr->data; it < arr->data + arr->len; it++)

static inline void SequenceDriveDirectivePq_fit(SequenceDriveDirectivePq *arr) {
    Array_fit((Array*)arr);
}

#define SequenceDriveDirectivePq_foreach(var, arr)                for (SequenceDriveDirectivePqFIt_declare(var, arr, 0); SequenceDriveDirectivePqFIt_next(&var); )
#define SequenceDriveDirectivePq_foreachOffset(var, arr, offset)  for (SequenceDriveDirectivePqFIt_declare(var, arr, offset); SequenceDriveDirectivePqFIt_next(&var); )            

static inline void SequenceDriveDirectivePq_free(SequenceDriveDirectivePq *arr) {
    Array_free((Array*)arr);
}

static inline SequenceDriveDirective SequenceDriveDirectivePq_get(SequenceDriveDirectivePq *arr, int index, Error *err) {
    SequenceDriveDirective v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline SequenceDriveDirective *SequenceDriveDirectivePq_getp(SequenceDriveDirectivePq *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (SequenceDriveDirective *)Array_get((Array*)arr, index);
}

static inline void SequenceDriveDirectivePq_init(SequenceDriveDirectivePq *arr, int nelems) {
   void (*clearer)(SequenceDriveDirective *) = NULL;
    Array_init((Array*)arr, nelems, sizeof(SequenceDriveDirective), (Array_clearElement)clearer);
}

static inline void SequenceDriveDirectivePq_insert(SequenceDriveDirectivePq *arr, int index, SequenceDriveDirective elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    SequenceDriveDirective *p = (SequenceDriveDirective *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline void SequenceDriveDirectivePq_insertp(SequenceDriveDirectivePq *arr, int index, SequenceDriveDirective *elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    SequenceDriveDirective *p = (SequenceDriveDirective *)Array_insertN((Array*)arr, index, 1);
    *p = *elem;
}            

static inline int SequenceDriveDirectivePq_last(SequenceDriveDirectivePq *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int SequenceDriveDirectivePq_len(SequenceDriveDirectivePq *arr) {
    return Array_len((Array*)arr);
}

#define SequenceDriveDirectivePq_loop(var) while (SequenceDriveDirectivePqFIt_next(&var)) 

static inline SequenceDriveDirectivePq *SequenceDriveDirectivePq_new(int nelems) {
    void (*clearer)(SequenceDriveDirective *) = NULL;
    return (SequenceDriveDirectivePq*)Array_new(nelems, sizeof(SequenceDriveDirective), (Array_clearElement)clearer);
}

static inline void SequenceDriveDirectivePq_pop(SequenceDriveDirectivePq *arr, Error *err) {
    Array_popNCheck(arr, 1, err);
    Array_popN((Array*)arr, 1);
}

static inline void SequenceDriveDirectivePq_push(SequenceDriveDirectivePq *arr, SequenceDriveDirective elem) {
    SequenceDriveDirective *p = (SequenceDriveDirective *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void SequenceDriveDirectivePq_pushp(SequenceDriveDirectivePq *arr, SequenceDriveDirective *elem) {
    SequenceDriveDirective *p = (SequenceDriveDirective *)Array_pushN((Array*)arr, 1);
    *p = *elem;
    return; 
}

#define SequenceDriveDirectivePq_reach(it, arr) for (SequenceDriveDirective* it = arr->data+arr->len-1; it >= arr->data; it--)

static inline void SequenceDriveDirectivePq_remove(SequenceDriveDirectivePq *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void SequenceDriveDirectivePq_removeN(SequenceDriveDirectivePq *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

#define SequenceDriveDirectivePq_rforeach(var, arr)                for (SequenceDriveDirectivePqRIt_declare(var, arr, 0); SequenceDriveDirectivePqRIt_next(&var); )
#define SequenceDriveDirectivePq_rforeachOffset(var, arr, offset)  for (SequenceDriveDirectivePqRIt_declare(var, arr, offset); SequenceDriveDirectivePqRIt_next(&var); )

#define SequenceDriveDirectivePq_rloop(var) while (SequenceDriveDirectivePqRIt_next(&var))             

static inline void SequenceDriveDirectivePq_set(SequenceDriveDirectivePq *arr, int index, SequenceDriveDirective elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

static inline void SequenceDriveDirectivePq_setp(SequenceDriveDirectivePq *arr, int index, SequenceDriveDirective *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)elem);
}

static inline void SequenceDriveDirectivePq_truncate(SequenceDriveDirectivePq *arr) {
    Array_truncate((Array*)arr);
}

static inline bool SequenceDriveDirectivePqFIt_atEnd(SequenceDriveDirectivePqFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define SequenceDriveDirectivePqFIt_declare(var, arr, offset)  SequenceDriveDirectivePqFIt var = {arr, 0, (arr)->len, offset-1, NULL}

#define SequenceDriveDirectivePqFIt_declare0(var)  SequenceDriveDirectivePqFIt var = {0}

static inline bool SequenceDriveDirectivePqFIt_next(SequenceDriveDirectivePqFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool SequenceDriveDirectivePqFIt_remove(SequenceDriveDirectivePqFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline bool SequenceDriveDirectivePqRIt_atEnd(SequenceDriveDirectivePqRIt *iterator) {
    return iterator->index-1 < iterator->lBound;
}

#define SequenceDriveDirectivePqRIt_declare(var, arr, offset)  SequenceDriveDirectivePqRIt var = {arr, 0, (arr)->len, (arr)->len-offset, NULL}

#define SequenceDriveDirectivePqRIt_declare0(var)  SequenceDriveDirectivePqRIt var = {0}

static inline bool SequenceDriveDirectivePqRIt_next(SequenceDriveDirectivePqRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline bool SequenceDriveDirectivePqRIt_remove(SequenceDriveDirectivePqRIt *iterator) {
    return ArrayRIt_remove((ArrayRIt*)iterator);
}

static inline void SequenceDriveDirectivePq_binInsert(SequenceDriveDirectivePq *arr, SequenceDriveDirective elem) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void SequenceDriveDirectivePq_binRemove(SequenceDriveDirectivePq *arr, SequenceDriveDirective elem) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline SequenceDriveDirective *SequenceDriveDirectivePq_binSearch(SequenceDriveDirectivePq *arr, SequenceDriveDirective elem) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
    return (SequenceDriveDirective *)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline SequenceDriveDirective *SequenceDriveDirectivePq_pqPeek(SequenceDriveDirectivePq *arr) {
   return (SequenceDriveDirective *)Array_pqPeek((Array*)arr);
}

static inline bool SequenceDriveDirectivePq_pqPop(SequenceDriveDirectivePq *arr, SequenceDriveDirective *elem) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void SequenceDriveDirectivePq_pqPush(SequenceDriveDirectivePq *arr, SequenceDriveDirective elem) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void SequenceDriveDirectivePq_pqSort(SequenceDriveDirectivePq *arr) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void SequenceDriveDirectivePq_sort(SequenceDriveDirectivePq *arr) {
    int (*compare)(SequenceDriveDirective *, SequenceDriveDirective *) = SequenceDriveDirective_cmp;
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

static inline void StringPtAr_binInsert(StringPtAr *arr, String *elem) {
    int (*compare)(String **, String **) = String_cmpPp;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void StringPtAr_binRemove(StringPtAr *arr, String *elem) {
    int (*compare)(String **, String **) = String_cmpPp;
    Array_binRemove((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}        

static inline String **StringPtAr_binSearch(StringPtAr *arr, String *elem) {
    int (*compare)(String **, String **) = String_cmpPp;
    return (String **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline String **StringPtAr_pqPeek(StringPtAr *arr) {
   return (String **)Array_pqPeek((Array*)arr);
}

static inline bool StringPtAr_pqPop(StringPtAr *arr, String **elem) {
    int (*compare)(String **, String **) = String_cmpPp;
   return Array_pqPop((Array*)arr, (char*)elem, (Array_compare)compare);
}

static inline void StringPtAr_pqPush(StringPtAr *arr, String *elem) {
    int (*compare)(String **, String **) = String_cmpPp;
   Array_pqPush((Array*)arr, (char*)&elem, (Array_compare)compare);
}

static inline void StringPtAr_pqSort(StringPtAr *arr) {
    int (*compare)(String **, String **) = String_cmpPp;
   Array_pqSort((Array*)arr, (Array_compare)compare);
}

static inline void StringPtAr_sort(StringPtAr *arr) {
    int (*compare)(String **, String **) = String_cmpPp;
    Array_sort((Array*)arr, (Array_compare)compare);
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
    OutletSpecifier_init(&self->outletSpecifier);            
    self->sequenceLength = 0;
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
    OutletSpecifier_init(&self->outletSpecifier);            
    self->sequenceLength = 0;
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
void Resource_init(Resource *self)
{
    self->songLibrary = String_empty();
    self->songName = String_empty();
    self->lastTime = 0;
    self->batchIndex = 0;
    return;
}
void Resource_clear(Resource *self)
{
    String_free(self->songLibrary);         
    String_free(self->songName);         
    return;
}
void Resource_free(Resource *self)
{
   if (self != NULL) {
        Resource_clear(self);
        Mem_free(self);
   }
}
Resource *Resource_new()
{
    Resource *self = Mem_malloc(sizeof(Resource));
    Resource_init(self);
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
void SequenceDrive_init(SequenceDrive *self)
{
    SequenceDriveDirectivePq_init(&self->directives, 0);
    self->queue = TimedPq_new(0);
    self->timeStop = 0;
    self->timeDelta = 0;
    self->maxIterations = 0;
    return;
}
void SequenceDrive_clear(SequenceDrive *self)
{
    SequenceDriveDirectivePq_clear(&self->directives);
    TimedPq_free(self->queue);
    return;
}
void SequenceDrive_free(SequenceDrive *self)
{
   if (self != NULL) {
        SequenceDrive_clear(self);
        Mem_free(self);
   }
}
SequenceDrive *SequenceDrive_new()
{
    SequenceDrive *self = Mem_malloc(sizeof(SequenceDrive));
    SequenceDrive_init(self);
    return self;
}
void SequenceDriveDirective_init(SequenceDriveDirective *self)
{
    self->time = 0;
    self->directive = 0;
    self->sequences = SequenceAr_new(0);
    return;
}
void SequenceDriveDirective_clear(SequenceDriveDirective *self)
{
    SequenceAr_free(self->sequences);
    return;
}
void SequenceDriveDirective_free(SequenceDriveDirective *self)
{
   if (self != NULL) {
        SequenceDriveDirective_clear(self);
        Mem_free(self);
   }
}
SequenceDriveDirective *SequenceDriveDirective_new()
{
    SequenceDriveDirective *self = Mem_malloc(sizeof(SequenceDriveDirective));
    SequenceDriveDirective_init(self);
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

Sequence *Sequence_compactNew(Sequence *self, Ticks a1, Error *err)
{
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

void Sequence_compactConcat(Sequence *self, Sequence *a1, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            FloatSequence_compactConcat((FloatSequence*)self, a1, err);
            return;
        case NoteSequence_itype:
            NoteSequence_compactConcat((NoteSequence*)self, a1, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_compactConcat: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Sequence_compactSortEvents(Sequence *self, Error *err)
{
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

void Sequence_compactFinish(Sequence *self, Ticks a1, Ticks a2, Error *err)
{
    switch(self->itype) {
        case FloatSequence_itype:
            FloatSequence_compactFinish((FloatSequence*)self, a1, a2, err);
            return;
        case NoteSequence_itype:
            NoteSequence_compactFinish((NoteSequence*)self, a1, a2, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in NoteSequence_compactFinish: found type %s", Interface_toString(self->itype));
    }
    return;
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
#line 1 "src/dispatch.in.c"

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
Coverage_array[0] = "dispatch.in.c 167";                  if (argc != 1) {
Coverage_array[1] = "dispatch.in.c 168";                     Error_format(err, "MarshalSi expected 1 additional argument, found %d", (int)argc);
Coverage_array[2] = "dispatch.in.c 169";                     return;
Coverage_array[3] = "dispatch.in.c 170";                  }
Coverage_array[4] = "dispatch.in.c 171";                  if (!Atom_isNumber(argv + 0)) {
Coverage_array[5] = "dispatch.in.c 172";                     Error_format0(err, "MarshalSi second argument should be an integer");
Coverage_array[6] = "dispatch.in.c 173";                     return;  
Coverage_array[7] = "dispatch.in.c 174";                  }
Coverage_array[8] = "dispatch.in.c 175";                  Arguments_setI1(args, Atom_toInteger(argv + 0));
Coverage_array[9] = "dispatch.in.c 176";               }

                                                       APIF void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args) {
Coverage_array[10] = "dispatch.in.c 179";                 Arguments_setI1(args, 0);
Coverage_array[11] = "dispatch.in.c 180";              }

                                                       APIF void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err)
                                                       {
Coverage_array[12] = "dispatch.in.c 184";                 if (argc != 2) {
Coverage_array[13] = "dispatch.in.c 185";                    Error_format(err, "MarshalSii expected 2 additional arguments, found %d", (int)argc);
Coverage_array[14] = "dispatch.in.c 186";                    return;
Coverage_array[15] = "dispatch.in.c 187";                 }
Coverage_array[16] = "dispatch.in.c 188";                 if (!Atom_isNumber(argv + 0)) {
Coverage_array[17] = "dispatch.in.c 189";                    Error_format0(err, "MarshalSii second argument should be an integer");
Coverage_array[18] = "dispatch.in.c 190";                    return;  
Coverage_array[19] = "dispatch.in.c 191";                 }
Coverage_array[20] = "dispatch.in.c 192";                 if (!Atom_isNumber(argv + 1)) {
Coverage_array[21] = "dispatch.in.c 193";                    Error_format0(err, "MarshalSii third argument should be an integer");
Coverage_array[22] = "dispatch.in.c 194";                    return;  
Coverage_array[23] = "dispatch.in.c 195";                 }
Coverage_array[24] = "dispatch.in.c 196";                 Arguments_setI1(args, Atom_toInteger(argv + 0));
Coverage_array[25] = "dispatch.in.c 197";                 Arguments_setI2(args, Atom_toInteger(argv + 1));
Coverage_array[26] = "dispatch.in.c 198";              }

                                                       APIF void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args) {
Coverage_array[27] = "dispatch.in.c 201";                 Arguments_setI1(args, 0);
Coverage_array[28] = "dispatch.in.c 202";                 Arguments_setI2(args, 0);
Coverage_array[29] = "dispatch.in.c 203";              }

                                                       APIF void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err)
                                                       {
Coverage_array[30] = "dispatch.in.c 207";                 if (argc != 1) {
Coverage_array[31] = "dispatch.in.c 208";                    Error_format(err, "MarshalSs expected 1 additional arguments, found %d", (int)argc);
Coverage_array[32] = "dispatch.in.c 209";                    return;
Coverage_array[33] = "dispatch.in.c 210";                 }
Coverage_array[34] = "dispatch.in.c 211";                 if (!Atom_isSymbol(argv + 0)) {
Coverage_array[35] = "dispatch.in.c 212";                    Error_format0(err, "MarshalSs second argument should be an symbol");
Coverage_array[36] = "dispatch.in.c 213";                    return;  
Coverage_array[37] = "dispatch.in.c 214";                 }
Coverage_array[38] = "dispatch.in.c 215";                 Arguments_setS1(args, Atom_toSymbol(argv + 0));
Coverage_array[39] = "dispatch.in.c 216";              }

                                                       APIF void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args) {
Coverage_array[40] = "dispatch.in.c 219";                 Arguments_setS1(args, NULL);
Coverage_array[41] = "dispatch.in.c 220";              }

                                                       APIF Marshal *Marshal_create(int itype) {
Coverage_array[42] = "dispatch.in.c 223";                 Marshal *self = (Marshal*)Mem_malloc(itype);
Coverage_array[43] = "dispatch.in.c 224";                 self->itype = itype;
Coverage_array[44] = "dispatch.in.c 225";                 return self;
Coverage_array[45] = "dispatch.in.c 226";              }

                                                       APIF void Marshal_free(Marshal *self) {
Coverage_array[46] = "dispatch.in.c 229";                 Mem_free(self);
Coverage_array[47] = "dispatch.in.c 230";              }

                                                       APIF Dispatch *IncrementFrameDispatch_create(int itype) {
Coverage_array[48] = "dispatch.in.c 233";                 Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
Coverage_array[49] = "dispatch.in.c 234";                 memset(self, 0, sizeof(Dispatch));
Coverage_array[50] = "dispatch.in.c 235";                 self->itype    = itype;
Coverage_array[51] = "dispatch.in.c 236";                 self->selector = Symbol_gen("incrementFrame");
Coverage_array[52] = "dispatch.in.c 237";                 self->portId   = Symbol_gen("guiBottom");
Coverage_array[53] = "dispatch.in.c 238";                 self->inlet    = 0;
Coverage_array[54] = "dispatch.in.c 239";                 self->marshal  = NULL;
Coverage_array[55] = "dispatch.in.c 240";                 return self;
Coverage_array[56] = "dispatch.in.c 241";              }

                                                       APIF void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
Coverage_array[57] = "dispatch.in.c 244";                    if (Hub_frame(hub) >= (Hub_framesPerBank-1)) {
Coverage_array[58] = "dispatch.in.c 245";                      return;
Coverage_array[59] = "dispatch.in.c 246";                  }
Coverage_array[60] = "dispatch.in.c 247";              
Coverage_array[61] = "dispatch.in.c 248";                  Hub_setFrame(hub, Hub_frame(hub)+1);
Coverage_array[62] = "dispatch.in.c 249";                  Hub_updateGuiCurrentCoordinates(hub);
Coverage_array[63] = "dispatch.in.c 250";              }

                                                       APIF Dispatch *DecrementFrameDispatch_create(int itype) {
Coverage_array[64] = "dispatch.in.c 253";                 Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
Coverage_array[65] = "dispatch.in.c 254";                 memset(self, 0, sizeof(Dispatch));
Coverage_array[66] = "dispatch.in.c 255";                 self->itype    = itype;
Coverage_array[67] = "dispatch.in.c 256";                 self->selector = Symbol_gen("decrementFrame");
Coverage_array[68] = "dispatch.in.c 257";                 self->portId   = Symbol_gen("guiBottom");
Coverage_array[69] = "dispatch.in.c 258";                 self->inlet    = 0;
Coverage_array[70] = "dispatch.in.c 259";                 self->marshal  = NULL;
Coverage_array[71] = "dispatch.in.c 260";                 return self;
Coverage_array[72] = "dispatch.in.c 261";              }

                                                       APIF void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
Coverage_array[73] = "dispatch.in.c 264";                  if (Hub_frame(hub) <= 0) {
Coverage_array[74] = "dispatch.in.c 265";                      return;
Coverage_array[75] = "dispatch.in.c 266";                  }
Coverage_array[76] = "dispatch.in.c 267";              
Coverage_array[77] = "dispatch.in.c 268";                  Hub_setFrame(hub, Hub_frame(hub)-1);
Coverage_array[78] = "dispatch.in.c 269";                  Hub_updateGuiCurrentCoordinates(hub);
Coverage_array[79] = "dispatch.in.c 270";              }


                                                       APIF Dispatch *SelectNextPushedPadDispatch_create(int itype) {
Coverage_array[80] = "dispatch.in.c 274";                 Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
Coverage_array[81] = "dispatch.in.c 275";                 memset(self, 0, sizeof(Dispatch));
Coverage_array[82] = "dispatch.in.c 276";                 self->itype    = itype;
Coverage_array[83] = "dispatch.in.c 277";                 self->selector = Symbol_gen("selectNextPushedPad");
Coverage_array[84] = "dispatch.in.c 278";                 self->portId   = Symbol_gen("guiBottom");
Coverage_array[85] = "dispatch.in.c 279";                 self->inlet    = 0;
Coverage_array[86] = "dispatch.in.c 280";                 self->marshal  = NULL;
Coverage_array[87] = "dispatch.in.c 281";                 return self;
Coverage_array[88] = "dispatch.in.c 282";              }

                                                       APIF void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err) {
Coverage_array[89] = "dispatch.in.c 285";                 Hub_setGrabNextTappedPad(hub, true);
Coverage_array[90] = "dispatch.in.c 286";              }


                                                       APIF Dispatch *MidiFileDropDispatch_create(int itype) {
Coverage_array[91] = "dispatch.in.c 290";                 Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
Coverage_array[92] = "dispatch.in.c 291";                 memset(self, 0, sizeof(Dispatch));
Coverage_array[93] = "dispatch.in.c 292";                 self->itype    = itype;
Coverage_array[94] = "dispatch.in.c 293";                 self->selector = Symbol_gen("midiFileDrop");
Coverage_array[95] = "dispatch.in.c 294";                 self->portId   = Symbol_gen("guiBottom");
Coverage_array[96] = "dispatch.in.c 295";                 self->inlet    = 0;
Coverage_array[97] = "dispatch.in.c 296";                 self->marshal  = Marshal_create(MarshalSs_itype); 
Coverage_array[98] = "dispatch.in.c 297";                 return self;
Coverage_array[99] = "dispatch.in.c 298";              }

                                                       APIF void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err) {
Coverage_array[100] = "dispatch.in.c 301";                Symbol *path = Arguments_s1(args);
Coverage_array[101] = "dispatch.in.c 302";                
Coverage_array[102] = "dispatch.in.c 303";                const char *colon = strchr(Symbol_cstr(path), ':');
Coverage_array[103] = "dispatch.in.c 304";                if (colon == NULL) {
Coverage_array[104] = "dispatch.in.c 305";                  Error_format0(err, "midiFileDrop expected to find colon (:) in filename");
Coverage_array[105] = "dispatch.in.c 306";                  return;
Coverage_array[106] = "dispatch.in.c 307";                }
Coverage_array[107] = "dispatch.in.c 308";                String *filename = String_fmt("%s", colon+1);
Coverage_array[108] = "dispatch.in.c 309";                Midiseq *mseq = Midiseq_fromfile(filename, err);
Coverage_array[109] = "dispatch.in.c 310";                if (Error_iserror(err)) {
Coverage_array[110] = "dispatch.in.c 311";                  return;
Coverage_array[111] = "dispatch.in.c 312";                }
Coverage_array[112] = "dispatch.in.c 313";                String_free(filename);
Coverage_array[113] = "dispatch.in.c 314";                Pad *pad = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
Coverage_array[114] = "dispatch.in.c 315";                if (Error_iserror(err)) {
Coverage_array[115] = "dispatch.in.c 316";                  Midiseq_free(mseq);
Coverage_array[116] = "dispatch.in.c 317";                  return;
Coverage_array[117] = "dispatch.in.c 318";                }
Coverage_array[118] = "dispatch.in.c 319";                Pad_setSequence(pad, mseq);
Coverage_array[119] = "dispatch.in.c 320";             }

                                                       APIF Dispatch *ManageChokeGroupsDispatch_create(int itype) {
Coverage_array[120] = "dispatch.in.c 323";                Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
Coverage_array[121] = "dispatch.in.c 324";                memset(self, 0, sizeof(Dispatch));
Coverage_array[122] = "dispatch.in.c 325";                self->itype    = itype;
Coverage_array[123] = "dispatch.in.c 326";                self->selector = NULL;
Coverage_array[124] = "dispatch.in.c 327";                self->portId   = Symbol_gen("chokeGroup");
Coverage_array[125] = "dispatch.in.c 328";                self->inlet    = 0;
Coverage_array[126] = "dispatch.in.c 329";                self->marshal  = NULL;
Coverage_array[127] = "dispatch.in.c 330";                return self;
Coverage_array[128] = "dispatch.in.c 331";             }

                                                       APIF void ManageChokeGroupsDispatch_initDispatchPtAr(int itype, DispatchPtAr *disPtAr, Error *ignored) {
Coverage_array[129] = "dispatch.in.c 334";                for (int i = 0; i < 3; i++) {
Coverage_array[130] = "dispatch.in.c 335";                   Dispatch *dis = ManageChokeGroupsDispatch_create(itype);
Coverage_array[131] = "dispatch.in.c 336";                   dis->inlet    = i;
Coverage_array[132] = "dispatch.in.c 337";                   DispatchPtAr_push(disPtAr, dis);
Coverage_array[133] = "dispatch.in.c 338";                }
Coverage_array[134] = "dispatch.in.c 339";                return;
Coverage_array[135] = "dispatch.in.c 340";             }

                                                       APIF void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err) {
Coverage_array[136] = "dispatch.in.c 343";                Pad *pad   = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
Coverage_array[137] = "dispatch.in.c 344";                long value = Arguments_ivalue(args);
Coverage_array[138] = "dispatch.in.c 345";                switch (self->inlet) {
                                                             case 0:
Coverage_array[139] = "dispatch.in.c 347";                      DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), value, err);
Coverage_array[140] = "dispatch.in.c 348";                      Error_returnVoidOnError(err);
Coverage_array[141] = "dispatch.in.c 349";                      Pad_setChokeGroupGlobal(pad, value ? true : false);
Coverage_array[142] = "dispatch.in.c 350";                      break;
                                                             case 1:
Coverage_array[143] = "dispatch.in.c 352";                      DropDown_setSelected(Hub_cgInstrumentMenu(hub), value, err);
Coverage_array[144] = "dispatch.in.c 353";                      Error_returnVoidOnError(err);
Coverage_array[145] = "dispatch.in.c 354";                      Pad_setChokeGroupInstrument(pad, value);
Coverage_array[146] = "dispatch.in.c 355";                      break;
                                                             case 2:
Coverage_array[147] = "dispatch.in.c 357";                      DropDown_setSelected(Hub_cgIndexMenu(hub), value, err);
Coverage_array[148] = "dispatch.in.c 358";                      Error_returnVoidOnError(err);
Coverage_array[149] = "dispatch.in.c 359";                      Pad_setChokeGroupIndex(pad, value);
Coverage_array[150] = "dispatch.in.c 360";                      break;
Coverage_array[151] = "dispatch.in.c 361";                   default:
Coverage_array[152] = "dispatch.in.c 362";                      Error_format(err, "INTERNAL ERROR: bad inlet %d", self->inlet);
Coverage_array[153] = "dispatch.in.c 363";                      return;
Coverage_array[154] = "dispatch.in.c 364";                }
Coverage_array[155] = "dispatch.in.c 365";                Pad_computeChokeGroup(pad);
Coverage_array[156] = "dispatch.in.c 366";             }

                                                       APIF int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp) 
                                                       {
Coverage_array[157] = "dispatch.in.c 370";                Dispatch *left = *leftp;
Coverage_array[158] = "dispatch.in.c 371";                Dispatch *right = *rightp;
Coverage_array[159] = "dispatch.in.c 372";                if (left->selector < right->selector) {
Coverage_array[160] = "dispatch.in.c 373";                   return -1;
Coverage_array[161] = "dispatch.in.c 374";                } else if (left->selector > right->selector) {
Coverage_array[162] = "dispatch.in.c 375";                   return 1;
Coverage_array[163] = "dispatch.in.c 376";                } else if (left->portId < right->portId) {
Coverage_array[164] = "dispatch.in.c 377";                   return -1;
Coverage_array[165] = "dispatch.in.c 378";                } else if (left->portId > right->portId) {
Coverage_array[166] = "dispatch.in.c 379";                   return 1;
Coverage_array[167] = "dispatch.in.c 380";                } else if (left->inlet < right->inlet) {
Coverage_array[168] = "dispatch.in.c 381";                   return -1;
Coverage_array[169] = "dispatch.in.c 382";                } else if (left->inlet > right->inlet) {
Coverage_array[170] = "dispatch.in.c 383";                   return 1;
Coverage_array[171] = "dispatch.in.c 384";                }
Coverage_array[172] = "dispatch.in.c 385";                return 0;
Coverage_array[173] = "dispatch.in.c 386";             }

                                                       APIF void Dispatch_freeDefault(Dispatch *d) {
Coverage_array[174] = "dispatch.in.c 389";                Marshal_free(d->marshal);
Coverage_array[175] = "dispatch.in.c 390";                Mem_free(d);
Coverage_array[176] = "dispatch.in.c 391";             }

                                                       APIF void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr, Error *err) {
Coverage_array[177] = "dispatch.in.c 394";                Dispatch *dis = Dispatch_create(itype, err);
Coverage_array[178] = "dispatch.in.c 395";                Error_returnVoidOnError(err);
Coverage_array[179] = "dispatch.in.c 396";                DispatchPtAr_push(disPtAr, dis);
Coverage_array[180] = "dispatch.in.c 397";             }

                                                       APIF void DispatchPtAr_populate(DispatchPtAr *self, Error *err) {
Coverage_array[181] = "dispatch.in.c 400";                DispatchPtAr_truncate(self);
Coverage_array[182] = "dispatch.in.c 401";                Dispatch_foreachIType(itype) {
Coverage_array[183] = "dispatch.in.c 402";                   Dispatch_initDispatchPtAr(itype, self, err);
Coverage_array[184] = "dispatch.in.c 403";                   Error_maypost(err);
Coverage_array[185] = "dispatch.in.c 404";                }
Coverage_array[186] = "dispatch.in.c 405";                DispatchPtAr_sort(self);
Coverage_array[187] = "dispatch.in.c 406";             }


#line 1 "src/midiseq.in.c"

#define APIF /**/
String *stripBaseName(const char *path);

#line 17 "src/midiseq.in.c"

                                                       APIF void String_split(String *src, const char *delim, StringPtAr *stringPtAr)
                                                       {
Coverage_array[188] = "midiseq.in.c 20";                   static StringBody *buffer = NULL;
Coverage_array[189] = "midiseq.in.c 21";                   if (buffer == NULL) {
Coverage_array[190] = "midiseq.in.c 22";                       buffer = String_toStringBody(String_empty());
Coverage_array[191] = "midiseq.in.c 23";                   }
Coverage_array[192] = "midiseq.in.c 24";                   StringBody *body = String_toStringBody(src);
Coverage_array[193] = "midiseq.in.c 25";                   if (buffer->len < body->len) {
Coverage_array[194] = "midiseq.in.c 26";                       String *s = buffer->ch;
Coverage_array[195] = "midiseq.in.c 27";                       String_resize(&s, body->len);
Coverage_array[196] = "midiseq.in.c 28";                       buffer = String_toStringBody(s);
Coverage_array[197] = "midiseq.in.c 29";                   }
Coverage_array[198] = "midiseq.in.c 30";                   strncpy(buffer->ch, body->ch, body->len+1);
Coverage_array[199] = "midiseq.in.c 31";                   StringPtAr_truncate(stringPtAr);   
Coverage_array[200] = "midiseq.in.c 32";                   char *string = buffer->ch;
Coverage_array[201] = "midiseq.in.c 33";                   char *token  = NULL;
Coverage_array[202] = "midiseq.in.c 34";                   while ((token = strsep(&string, delim)) != NULL) {
Coverage_array[203] = "midiseq.in.c 35";                       StringPtAr_push(stringPtAr, String_fmt("%s", token));
Coverage_array[204] = "midiseq.in.c 36";                   }
Coverage_array[205] = "midiseq.in.c 37";                   return;
Coverage_array[206] = "midiseq.in.c 38";               }

#line 50 "src/midiseq.in.c"

                                                       APIF int Symbol_cmpUnderlying(Symbol **left, Symbol **right) 
                                                       {
Coverage_array[207] = "midiseq.in.c 53";                   return strcmp(Symbol_cstr(*left), Symbol_cstr(*right)); 
Coverage_array[208] = "midiseq.in.c 54";               }

#ifdef TEST_BUILD
SymbolPtAr *gSymbols = NULL;

                                                       APIF Symbol *Symbol_gen(const char *word) 
                                                       {
Coverage_array[209] = "midiseq.in.c 61";                   if (gSymbols == NULL) {
Coverage_array[210] = "midiseq.in.c 62";                       gSymbols = SymbolPtAr_new(0);
Coverage_array[211] = "midiseq.in.c 63";                   }
Coverage_array[212] = "midiseq.in.c 64";                   Symbol s  = {word};
Coverage_array[213] = "midiseq.in.c 65";                   Symbol **rp = SymbolPtAr_binSearchUnderlying(gSymbols, &s);
Coverage_array[214] = "midiseq.in.c 66";                   if (rp != NULL) {
Coverage_array[215] = "midiseq.in.c 67";                       return *rp;
Coverage_array[216] = "midiseq.in.c 68";                   }
Coverage_array[217] = "midiseq.in.c 69";                   Symbol *n = Mem_calloc(sizeof(Symbol));
Coverage_array[218] = "midiseq.in.c 70";                   n->name = strdup(word);
Coverage_array[219] = "midiseq.in.c 71";                   SymbolPtAr_binInsertUnderlying(gSymbols, n);
Coverage_array[220] = "midiseq.in.c 72";                   return n;
Coverage_array[221] = "midiseq.in.c 73";               }

                                                       APIF void Symbol_freeAll() 
                                                       {
Coverage_array[222] = "midiseq.in.c 77";                   SymbolPtAr_foreach(it, gSymbols) {
Coverage_array[223] = "midiseq.in.c 78";                       Mem_free(*it.var);
Coverage_array[224] = "midiseq.in.c 79";                   }
Coverage_array[225] = "midiseq.in.c 80";                   SymbolPtAr_truncate(gSymbols);
Coverage_array[226] = "midiseq.in.c 81";               }

#endif

#line 92 "src/midiseq.in.c"

#line 101 "src/midiseq.in.c"

#line 121 "src/midiseq.in.c"


Port Port_nullImpl =
{
    {
        0
    }
};

#define Port_null (&Port_nullImpl)


                                                       APIF Port *Port_new() 
                                                       {
Coverage_array[227] = "midiseq.in.c 135";                  return Port_null;
Coverage_array[228] = "midiseq.in.c 136";              }
                                                       APIF void Port_init(Port *p)
                                                       {
Coverage_array[229] = "midiseq.in.c 139";                  *p = Port_nullImpl;
Coverage_array[230] = "midiseq.in.c 140";              }

#ifndef TEST_BUILD
                                                       APIF void Port_free(Port *p)
                                                       {
Coverage_array[231] = "midiseq.in.c 145";              }

                                                       APIF void Port_clear(Port *p)
                                                       {
Coverage_array[232] = "midiseq.in.c 149";              }
#endif

// Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
                                                       APIF int port_parseEvSymbol(Symbol *id)
                                                       {
Coverage_array[233] = "midiseq.in.c 155";                  int r = -1;
Coverage_array[234] = "midiseq.in.c 156";                  int consumed = 0;
Coverage_array[235] = "midiseq.in.c 157";                  if (id == NULL) {
Coverage_array[236] = "midiseq.in.c 158";                      return -1;
Coverage_array[237] = "midiseq.in.c 159";                  }
Coverage_array[238] = "midiseq.in.c 160";              
Coverage_array[239] = "midiseq.in.c 161";                  if (sscanf(Symbol_cstr(id), "ev%d%n", &r, &consumed) != 1) {
Coverage_array[240] = "midiseq.in.c 162";                      return -1;
Coverage_array[241] = "midiseq.in.c 163";                  }
Coverage_array[242] = "midiseq.in.c 164";                  if (strlen(Symbol_cstr(id)) != consumed) {
Coverage_array[243] = "midiseq.in.c 165";                      return -1;
Coverage_array[244] = "midiseq.in.c 166";                  }
Coverage_array[245] = "midiseq.in.c 167";                  return r;
Coverage_array[246] = "midiseq.in.c 168";              }

                                                       APIF void Port_send(Port *self, int outletIndex, short argc, Atom *argv, Error *err)
                                                       {   
Coverage_array[247] = "midiseq.in.c 172";                  if (self == Port_null) {
Coverage_array[248] = "midiseq.in.c 173";                      return;
Coverage_array[249] = "midiseq.in.c 174";                  }
Coverage_array[250] = "midiseq.in.c 175";                  
#                                                      ifndef TEST_BUILD
Coverage_array[251] = "midiseq.in.c 177";                  Symbol *selector = Atom_toSymbol(argv + 0);
Coverage_array[252] = "midiseq.in.c 178";                  void *out = PtrAr_get(&self->outlet, outletIndex, err);
Coverage_array[253] = "midiseq.in.c 179";                  Error_returnVoidOnError(err);
Coverage_array[254] = "midiseq.in.c 180";                  outlet_anything(out, selector, argc-1, argv+1);  
#                                                      else
Coverage_array[255] = "midiseq.in.c 182";                  AtomArAr *arr = self->obj.utilityPointer;
Coverage_array[256] = "midiseq.in.c 183";                  if (arr != NULL) {
Coverage_array[257] = "midiseq.in.c 184";                      AtomAr subAr;
Coverage_array[258] = "midiseq.in.c 185";                      AtomAr_init(&subAr, 0);
Coverage_array[259] = "midiseq.in.c 186";                      for (int i = 0; i < argc; i++){
Coverage_array[260] = "midiseq.in.c 187";                          AtomAr_push(&subAr, argv[i]);
Coverage_array[261] = "midiseq.in.c 188";                      }
Coverage_array[262] = "midiseq.in.c 189";                      AtomArAr_push(arr, subAr);
Coverage_array[263] = "midiseq.in.c 190";                      // Explicitly DO NOT deallocate subAr
Coverage_array[264] = "midiseq.in.c 191";                  }
#                                                      endif
Coverage_array[265] = "midiseq.in.c 193";              }

                                                       APIF void Port_sendInteger(Port *self, int outlet, long value, Error *err) 
                                                       {
Coverage_array[266] = "midiseq.in.c 197";                  if (self == Port_null) {
Coverage_array[267] = "midiseq.in.c 198";                      return;
Coverage_array[268] = "midiseq.in.c 199";                  }
Coverage_array[269] = "midiseq.in.c 200";              
Coverage_array[270] = "midiseq.in.c 201";                  void *out = PtrAr_get(&self->outlet, outlet, err);
Coverage_array[271] = "midiseq.in.c 202";                  Error_returnVoidOnError(err); 
#                                                      ifndef TEST_BUILD
Coverage_array[272] = "midiseq.in.c 204";                  outlet_int(out, value);  
#                                                      else
Coverage_array[273] = "midiseq.in.c 206";                  AtomArAr *arr = self->obj.utilityPointer;
Coverage_array[274] = "midiseq.in.c 207";                  if (arr != NULL) {
Coverage_array[275] = "midiseq.in.c 208";                      AtomAr subAr;
Coverage_array[276] = "midiseq.in.c 209";                      AtomAr_init(&subAr, 0);
Coverage_array[277] = "midiseq.in.c 210";                      AtomAr_push(&subAr, Atom_fromInteger(value));
Coverage_array[278] = "midiseq.in.c 211";                      AtomArAr_push(arr, subAr);
Coverage_array[279] = "midiseq.in.c 212";                      // Explicitly DO NOT deallocate subAr
Coverage_array[280] = "midiseq.in.c 213";                  }
#                                                      endif
Coverage_array[281] = "midiseq.in.c 215";              }

#line 224 "src/midiseq.in.c"

#line 232 "src/midiseq.in.c"

#line 240 "src/midiseq.in.c"

#line 248 "src/midiseq.in.c"



#line 264 "src/midiseq.in.c"

#line 294 "src/midiseq.in.c"
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)
NOCOVER static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
NOCOVER static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

#line 341 "src/midiseq.in.c"


#line 407 "src/midiseq.in.c"


#line 435 "src/midiseq.in.c"

#line 462 "src/midiseq.in.c"

#line 486 "src/midiseq.in.c"


#line 507 "src/midiseq.in.c"

#line 532 "src/midiseq.in.c"


#line 547 "src/midiseq.in.c"

#line 564 "src/midiseq.in.c"

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
                                                       COVER static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
Coverage_array[282] = "midiseq.in.c 567";                 pr->port   = port;
Coverage_array[283] = "midiseq.in.c 568";                 pr->outlet = outlet;
Coverage_array[284] = "midiseq.in.c 569";              }
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)
PortRef PortRef_nullImpl = {Port_null, 0};
#define PortRef_null  &PortRef_nullImpl
                                                       APIF static inline Symbol *PortRef_track(PortRef *self)
                                                       { 
Coverage_array[285] = "midiseq.in.c 576";                  return Port_track(self->port);
Coverage_array[286] = "midiseq.in.c 577";              }


                                                       APIF int PortRef_cmp(PortRef *left, PortRef *right) 
                                                       {
Coverage_array[287] = "midiseq.in.c 582";                  if (left->port < right->port) {
Coverage_array[288] = "midiseq.in.c 583";                      return -1;
Coverage_array[289] = "midiseq.in.c 584";                  } else if (left->port > right->port) {
Coverage_array[290] = "midiseq.in.c 585";                      return 1;
Coverage_array[291] = "midiseq.in.c 586";                  } else if (left->outlet < right->outlet) {
Coverage_array[292] = "midiseq.in.c 587";                      return -1;
Coverage_array[293] = "midiseq.in.c 588";                  } else if (left->outlet > right->outlet) {
Coverage_array[294] = "midiseq.in.c 589";                      return 1;
Coverage_array[295] = "midiseq.in.c 590";                  }
Coverage_array[296] = "midiseq.in.c 591";                  return 0;
Coverage_array[297] = "midiseq.in.c 592";              }



#line 620 "src/midiseq.in.c"

                                                       COVER static inline PortRef *DropDown_portRef(DropDown *dd) {
Coverage_array[298] = "midiseq.in.c 622";                  return &dd->portRef;
Coverage_array[299] = "midiseq.in.c 623";              }

                                                       COVER static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
Coverage_array[300] = "midiseq.in.c 626";                 dd->portRef = *pr;
Coverage_array[301] = "midiseq.in.c 627";              }

//
// D R O P   D O W N
//

                                                       APIF void DropDown_build(DropDown *dd, const char **table, PortRef *pr) {
Coverage_array[302] = "midiseq.in.c 634";                  SymbolPtrAr_init(&dd->table, 0);
Coverage_array[303] = "midiseq.in.c 635";                  const char **ptr = table;
Coverage_array[304] = "midiseq.in.c 636";                  while (*ptr) {
Coverage_array[305] = "midiseq.in.c 637";                      Symbol *s = Symbol_gen(*ptr);
Coverage_array[306] = "midiseq.in.c 638";                      SymbolPtrAr_push(&dd->table, s);
Coverage_array[307] = "midiseq.in.c 639";                      ptr++;
Coverage_array[308] = "midiseq.in.c 640";                  }
Coverage_array[309] = "midiseq.in.c 641";                  DropDown_setPortRef(dd, pr);
Coverage_array[310] = "midiseq.in.c 642";                  return;
Coverage_array[311] = "midiseq.in.c 643";              }

                                                       APIF void DropDown_buildCGLocalGlobal(DropDown *dd, PortRef *pr) {
Coverage_array[312] = "midiseq.in.c 646";                  Coverage_off;
                                                           const char *t[] = {
                                                               "local",
                                                               "global",
                                                               NULL
                                                           };
                                                           Coverage_on;
Coverage_array[313] = "midiseq.in.c 653";                  DropDown_build(dd, t, pr);
Coverage_array[314] = "midiseq.in.c 654";              }

                                                       APIF void DropDown_buildCGInstrument(DropDown *dd, PortRef *pr) {
Coverage_array[315] = "midiseq.in.c 657";                  Coverage_off;
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
Coverage_array[316] = "midiseq.in.c 668";                  DropDown_build(dd, t, pr);
Coverage_array[317] = "midiseq.in.c 669";              }

                                                       APIF void DropDown_buildCGIndex(DropDown *dd, PortRef *pr) {
Coverage_array[318] = "midiseq.in.c 672";                  Coverage_off;
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
Coverage_array[319] = "midiseq.in.c 694";                  DropDown_build(dd, t, pr);
Coverage_array[320] = "midiseq.in.c 695";              }

// APIF void DropDown_clear(DropDown *dd) {
//     SymbolPtrAr_clear(&dd->table);
// }

// APIF void DropDown_free(DropDown *dd) {
//     DropDown_clear(dd);
//     Mem_free(dd);
// }

                                                       APIF void DropDown_updateSelected(DropDown *dd, Error *err) {
Coverage_array[321] = "midiseq.in.c 707";                  Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
Coverage_array[322] = "midiseq.in.c 708";                  Error_returnVoidOnError(err);
Coverage_array[323] = "midiseq.in.c 709";              
Coverage_array[324] = "midiseq.in.c 710";                  Atom a[2] = {Atom_fromSymbol(Symbol_gen("set")), Atom_fromSymbol(s)};
Coverage_array[325] = "midiseq.in.c 711";                  PortRef_send(DropDown_portRef(dd), 2, a, err);
Coverage_array[326] = "midiseq.in.c 712";              }

                                                       APIF void DropDown_setSelected(DropDown *dd, int selected, Error *err) {
Coverage_array[327] = "midiseq.in.c 715";                  if (selected < 0 || selected >= SymbolPtrAr_len(&dd->table)) {
Coverage_array[328] = "midiseq.in.c 716";                      Error_format(err, "Index out of range (%d, %d)", selected, SymbolPtrAr_len(&dd->table));
Coverage_array[329] = "midiseq.in.c 717";                      return;
Coverage_array[330] = "midiseq.in.c 718";                  }
Coverage_array[331] = "midiseq.in.c 719";                  dd->selected = selected;
Coverage_array[332] = "midiseq.in.c 720";              }

                                                       APIF void DropDown_initializeMenu(DropDown *dd, Error *err) {
Coverage_array[333] = "midiseq.in.c 723";                  Atom clear = Atom_fromSymbol(Symbol_gen("clear"));
Coverage_array[334] = "midiseq.in.c 724";                  Atom append = Atom_fromSymbol(Symbol_gen("append"));
Coverage_array[335] = "midiseq.in.c 725";              
Coverage_array[336] = "midiseq.in.c 726";                  PortRef_send(&dd->portRef, 1, &clear, err);
Coverage_array[337] = "midiseq.in.c 727";                  Error_returnVoidOnError(err);
Coverage_array[338] = "midiseq.in.c 728";              
Coverage_array[339] = "midiseq.in.c 729";                  SymbolPtrAr_foreach(it, &dd->table) {
Coverage_array[340] = "midiseq.in.c 730";                      Atom a[2] = {append, Atom_fromSymbol(*it.var)};
Coverage_array[341] = "midiseq.in.c 731";                      PortRef_send(&dd->portRef, 2, a, err);
Coverage_array[342] = "midiseq.in.c 732";                      Error_returnVoidOnError(err);        
Coverage_array[343] = "midiseq.in.c 733";                  }
Coverage_array[344] = "midiseq.in.c 734";              }
#line 847 "src/midiseq.in.c"

#line 865 "src/midiseq.in.c"

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
Coverage_array[345] = "midiseq.in.c 884";                  errno = 0;
Coverage_array[346] = "midiseq.in.c 885";                  long v = strtol(src, NULL, 10);
Coverage_array[347] = "midiseq.in.c 886";                  if (errno != 0) {
Coverage_array[348] = "midiseq.in.c 887";                      Coverage_off;
                                                               Error_formatFileLine(err, function, file, line, String_fmt("Failed to convert int error code %s", 
                                                                 (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));
                                                               Coverage_on;
Coverage_array[349] = "midiseq.in.c 891";              
Coverage_array[350] = "midiseq.in.c 892";                  }
Coverage_array[351] = "midiseq.in.c 893";                  return v;
Coverage_array[352] = "midiseq.in.c 894";              }


#define Midiseq_convertInt(src, err) Midiseq_convertIntFileLine(src, err, __func__, __FILE__, __LINE__)

//
// M I D I S E Q
//
#define Midiseq_maxLineLength 1024

// Create new empty midi sequence

                                                       APIF void Midiseq_userInit(Midiseq *self)
                                                       {
Coverage_array[353] = "midiseq.in.c 908";                  self->sequenceLength = 480*4;
Coverage_array[354] = "midiseq.in.c 909";              
Coverage_array[355] = "midiseq.in.c 910";                  MEvent cell = {0};
Coverage_array[356] = "midiseq.in.c 911";                  cell.t = 0;
Coverage_array[357] = "midiseq.in.c 912";                  cell.type = Midiseq_endgrptype;
Coverage_array[358] = "midiseq.in.c 913";                  MEventAr_push(&self->events, cell);
Coverage_array[359] = "midiseq.in.c 914";                  
Coverage_array[360] = "midiseq.in.c 915";                  cell.t = self->sequenceLength;
Coverage_array[361] = "midiseq.in.c 916";                  cell.type = Midiseq_cycletype;
Coverage_array[362] = "midiseq.in.c 917";                  MEventAr_push(&self->events, cell);
Coverage_array[363] = "midiseq.in.c 918";              
Coverage_array[364] = "midiseq.in.c 919";                  MEventAr_fit(&self->events);
Coverage_array[365] = "midiseq.in.c 920";              }



                                                       APIF void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err) {
Coverage_array[366] = "midiseq.in.c 925";                  BinFile_writeTag(bf, "midiseq", err);
Coverage_array[367] = "midiseq.in.c 926";                  Error_returnVoidOnError(err);
Coverage_array[368] = "midiseq.in.c 927";              
Coverage_array[369] = "midiseq.in.c 928";                  BinFile_writeBool(bf, Midiseq_useMasterClock(mseq), err);
Coverage_array[370] = "midiseq.in.c 929";                  Error_returnVoidOnError(err);
Coverage_array[371] = "midiseq.in.c 930";              
Coverage_array[372] = "midiseq.in.c 931";                  BinFile_writeTicks(bf, Midiseq_sequenceLength(mseq), err);
Coverage_array[373] = "midiseq.in.c 932";                  Error_returnVoidOnError(err);
Coverage_array[374] = "midiseq.in.c 933";              
Coverage_array[375] = "midiseq.in.c 934";                  BinFile_writeInteger(bf, MEventAr_len(&mseq->events), err);
Coverage_array[376] = "midiseq.in.c 935";                  Error_returnVoidOnError(err);
Coverage_array[377] = "midiseq.in.c 936";              
Coverage_array[378] = "midiseq.in.c 937";                  BinFile_writeTag(bf, "midiseq_start_data", err);
Coverage_array[379] = "midiseq.in.c 938";                  Error_returnVoidOnError(err);
Coverage_array[380] = "midiseq.in.c 939";              
Coverage_array[381] = "midiseq.in.c 940";                  MEventAr_foreach(it, &mseq->events) {
Coverage_array[382] = "midiseq.in.c 941";                      MEvent cell = *it.var;
Coverage_array[383] = "midiseq.in.c 942";                      if (fprintf(BinFile_stream(bf), " %u %u %lld", MEvent_type(cell), MEvent_bendValue(cell), MEvent_t(cell)) < 0) {
Coverage_array[384] = "midiseq.in.c 943";                          Error_format(err, "Midiseq_toBinFile failed at fprintf[1] while writing %s", BinFile_filename(bf));
Coverage_array[385] = "midiseq.in.c 944";                          return;
Coverage_array[386] = "midiseq.in.c 945";                      }
Coverage_array[387] = "midiseq.in.c 946";              
Coverage_array[388] = "midiseq.in.c 947";                      if (MEvent_type(cell) == Midiseq_notetype) {
Coverage_array[389] = "midiseq.in.c 948";                          if (fprintf(BinFile_stream(bf), " %lld", MEvent_noteDuration(cell)) < 0) {
Coverage_array[390] = "midiseq.in.c 949";                              Error_format(err, "Midiseq_toBinFile failed at fprintf[2] while writing %s", BinFile_filename(bf));
Coverage_array[391] = "midiseq.in.c 950";                              return;       
Coverage_array[392] = "midiseq.in.c 951";                          }
Coverage_array[393] = "midiseq.in.c 952";                      }
Coverage_array[394] = "midiseq.in.c 953";                  }
Coverage_array[395] = "midiseq.in.c 954";                  BinFile_writeTag(bf, "midiseq_end_data", err);
Coverage_array[396] = "midiseq.in.c 955";                  Error_returnVoidOnError(err);
Coverage_array[397] = "midiseq.in.c 956";              }


                                                       APIF Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err) {
Coverage_array[398] = "midiseq.in.c 960";                  Midiseq *mseq = Midiseq_new();
Coverage_array[399] = "midiseq.in.c 961";                  Midiseq_fromBinFileUnititialized(mseq, bf, err);
Coverage_array[400] = "midiseq.in.c 962";                  if (Error_iserror(err)) {
Coverage_array[401] = "midiseq.in.c 963";                      Mem_free(mseq);
Coverage_array[402] = "midiseq.in.c 964";                      return NULL;
Coverage_array[403] = "midiseq.in.c 965";                  }
Coverage_array[404] = "midiseq.in.c 966";                  return mseq;
Coverage_array[405] = "midiseq.in.c 967";              }

                                                       APIF void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err) {
Coverage_array[406] = "midiseq.in.c 970";                  BinFile_verifyTag(bf, "midiseq", err);
Coverage_array[407] = "midiseq.in.c 971";                  Error_returnVoidOnError(err);
Coverage_array[408] = "midiseq.in.c 972";              
Coverage_array[409] = "midiseq.in.c 973";                  Midiseq_setUseMasterClock(mseq, BinFile_readBool(bf, err));
Coverage_array[410] = "midiseq.in.c 974";                  Error_returnVoidOnError(err);
Coverage_array[411] = "midiseq.in.c 975";              
Coverage_array[412] = "midiseq.in.c 976";                  Midiseq_setSequenceLength(mseq, BinFile_readTicks(bf,  err));
Coverage_array[413] = "midiseq.in.c 977";                  Error_returnVoidOnError(err);
Coverage_array[414] = "midiseq.in.c 978";              
Coverage_array[415] = "midiseq.in.c 979";                  long length = BinFile_readInteger(bf, err);
Coverage_array[416] = "midiseq.in.c 980";                  Error_returnVoidOnError(err);
Coverage_array[417] = "midiseq.in.c 981";              
Coverage_array[418] = "midiseq.in.c 982";                  BinFile_verifyTag(bf, "midiseq_start_data", err);
Coverage_array[419] = "midiseq.in.c 983";                  Error_returnVoidOnError(err);
Coverage_array[420] = "midiseq.in.c 984";              
Coverage_array[421] = "midiseq.in.c 985";                  MEventAr_init(&mseq->events, 0);
Coverage_array[422] = "midiseq.in.c 986";                  for (int i = 0; i < length; i++) {
Coverage_array[423] = "midiseq.in.c 987";                      MEvent cell = {0};
Coverage_array[424] = "midiseq.in.c 988";                      unsigned int type = 0, bendVal = 0;
Coverage_array[425] = "midiseq.in.c 989";                      if (fscanf(BinFile_stream(bf), " %u %u %lld", &type, &bendVal, &MEvent_t(cell)) != 3) {
Coverage_array[426] = "midiseq.in.c 990";                          Error_format(err, "Midiseq_fromBinFile failed at fscanf[1] while reading %s", BinFile_filename(bf));
Coverage_array[427] = "midiseq.in.c 991";                          goto END;
Coverage_array[428] = "midiseq.in.c 992";                      }
Coverage_array[429] = "midiseq.in.c 993";                      MEvent_type(cell)      = type;
Coverage_array[430] = "midiseq.in.c 994";                      MEvent_bendValue(cell) = bendVal;
Coverage_array[431] = "midiseq.in.c 995";              
Coverage_array[432] = "midiseq.in.c 996";                      if (MEvent_type(cell) == Midiseq_notetype) {
Coverage_array[433] = "midiseq.in.c 997";                          if (fscanf(BinFile_stream(bf), " %lld", &MEvent_noteDuration(cell)) != 1) {
Coverage_array[434] = "midiseq.in.c 998";                              Error_format(err, "Midiseq_fromBinFile failed at fscanf[2] while reading %s", BinFile_filename(bf));
Coverage_array[435] = "midiseq.in.c 999";                              goto END;
Coverage_array[436] = "midiseq.in.c 1000";                         }
Coverage_array[437] = "midiseq.in.c 1001";                     }
Coverage_array[438] = "midiseq.in.c 1002";                     MEventAr_push(&mseq->events, cell);
Coverage_array[439] = "midiseq.in.c 1003";                 }
Coverage_array[440] = "midiseq.in.c 1004";                 MEventAr_fit(&mseq->events);
Coverage_array[441] = "midiseq.in.c 1005";                 BinFile_verifyTag(bf, "midiseq_end_data", err);
Coverage_array[442] = "midiseq.in.c 1006";                 Error_gotoLabelOnError(err, END);
Coverage_array[443] = "midiseq.in.c 1007";                 return;
Coverage_array[444] = "midiseq.in.c 1008";             
Coverage_array[445] = "midiseq.in.c 1009";               END:
Coverage_array[446] = "midiseq.in.c 1010";                 MEventAr_clear(&mseq->events);
Coverage_array[447] = "midiseq.in.c 1011";                 return;
Coverage_array[448] = "midiseq.in.c 1012";             }

                                                       APIF Midiseq *Midiseq_newNote(int pitch)
                                                       {
Coverage_array[449] = "midiseq.in.c 1016";                 Midiseq *mseq = Midiseq_new();
Coverage_array[450] = "midiseq.in.c 1017";                 MEventAr_truncate(&mseq->events);
Coverage_array[451] = "midiseq.in.c 1018";             
Coverage_array[452] = "midiseq.in.c 1019";                 mseq->sequenceLength = 480*4;
Coverage_array[453] = "midiseq.in.c 1020";                 
Coverage_array[454] = "midiseq.in.c 1021";                 MEvent zero = {0}, cell = {0};
Coverage_array[455] = "midiseq.in.c 1022";             
Coverage_array[456] = "midiseq.in.c 1023";                 MEvent_t(cell)    = 0;
Coverage_array[457] = "midiseq.in.c 1024";                 MEvent_type(cell) = Midiseq_endgrptype;
Coverage_array[458] = "midiseq.in.c 1025";                 MEventAr_push(&mseq->events, cell);
Coverage_array[459] = "midiseq.in.c 1026";             
Coverage_array[460] = "midiseq.in.c 1027";                 cell = zero;
Coverage_array[461] = "midiseq.in.c 1028";                 MEvent_t(cell)            = 0;
Coverage_array[462] = "midiseq.in.c 1029";                 MEvent_type(cell)         = Midiseq_notetype;
Coverage_array[463] = "midiseq.in.c 1030";                 MEvent_notePitch(cell)    = pitch;
Coverage_array[464] = "midiseq.in.c 1031";                 MEvent_noteVelocity(cell) = 90;
Coverage_array[465] = "midiseq.in.c 1032";                 MEvent_noteDuration(cell) = 480;
Coverage_array[466] = "midiseq.in.c 1033";                 MEventAr_push(&mseq->events, cell);
Coverage_array[467] = "midiseq.in.c 1034";             
Coverage_array[468] = "midiseq.in.c 1035";                 cell              = zero;
Coverage_array[469] = "midiseq.in.c 1036";                 MEvent_t(cell)    = mseq->sequenceLength;
Coverage_array[470] = "midiseq.in.c 1037";                 MEvent_type(cell) = Midiseq_cycletype;
Coverage_array[471] = "midiseq.in.c 1038";                 MEventAr_push(&mseq->events, cell);
Coverage_array[472] = "midiseq.in.c 1039";             
Coverage_array[473] = "midiseq.in.c 1040";                 MEventAr_fit(&mseq->events);
Coverage_array[474] = "midiseq.in.c 1041";             
Coverage_array[475] = "midiseq.in.c 1042";                 return mseq;
Coverage_array[476] = "midiseq.in.c 1043";             }

                                                       APIF int Midiseq_len(Midiseq *mseq)
                                                       {
Coverage_array[477] = "midiseq.in.c 1047";                 // REMEMBER: because of cycle and endgroup, every midi sequence has at least 2 elements.
Coverage_array[478] = "midiseq.in.c 1048";                 return MEventAr_len(&mseq->events);
Coverage_array[479] = "midiseq.in.c 1049";             }


                                                       APIF void Midiseq_push(Midiseq *mseq, MEvent cell)
                                                       {
Coverage_array[480] = "midiseq.in.c 1054";                 MEventAr_push(&mseq->events, cell);
Coverage_array[481] = "midiseq.in.c 1055";             }


                                                       APIF MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err)
                                                       {
Coverage_array[482] = "midiseq.in.c 1060";                 return MEventAr_getp(&mseq->events, index, err);
Coverage_array[483] = "midiseq.in.c 1061";             }


bool Midiseq_pathsAllocated = false;
String *Midiseq_midiCsvExecPath = NULL;
String *Midiseq_csvMidiExecPath = NULL;

                                                       APIF void Midiseq_setMidicsvExecPath()
                                                       {
Coverage_array[484] = "midiseq.in.c 1070";                 if (!Midiseq_pathsAllocated) {
Coverage_array[485] = "midiseq.in.c 1071";                     Midiseq_midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
Coverage_array[486] = "midiseq.in.c 1072";                     Midiseq_csvMidiExecPath = String_fmt("%s/packages/midicsv-1.1/csvmidi", CSEQ_HOME);
Coverage_array[487] = "midiseq.in.c 1073";                     Midiseq_pathsAllocated = true;
Coverage_array[488] = "midiseq.in.c 1074";                 }
Coverage_array[489] = "midiseq.in.c 1075";             }


                                                       APIF void Midiseq_dblog(Midiseq *mseq)
                                                       {
Coverage_array[490] = "midiseq.in.c 1080";                 dblog("Midiseq %p", mseq);
Coverage_array[491] = "midiseq.in.c 1081";                 MEventAr_foreach(it, &mseq->events) {
Coverage_array[492] = "midiseq.in.c 1082";                     MEvent cell = *it.var;
Coverage_array[493] = "midiseq.in.c 1083";                     switch (MEvent_type(cell)) {
                                                                   case Midiseq_notetype:
Coverage_array[494] = "midiseq.in.c 1085";                             dblog("    %15lld note %15ld %15ld %15ld", MEvent_t(cell), (long)MEvent_notePitch(cell), (long)MEvent_noteVelocity(cell), (long)MEvent_noteDuration(cell));
Coverage_array[495] = "midiseq.in.c 1086";                             break;
                                                                   case Midiseq_bendtype:
Coverage_array[496] = "midiseq.in.c 1088";                             dblog("    %15lld bend", MEvent_t(cell));
Coverage_array[497] = "midiseq.in.c 1089";                             break;
                                                                   case Midiseq_cctype:
Coverage_array[498] = "midiseq.in.c 1091";                             dblog("    %15lld cc", MEvent_t(cell));
Coverage_array[499] = "midiseq.in.c 1092";                             break;
                                                                   case Midiseq_endgrptype:
Coverage_array[500] = "midiseq.in.c 1094";                             dblog("    %15lld endgroup", MEvent_t(cell));
Coverage_array[501] = "midiseq.in.c 1095";                             break;
                                                                   case Midiseq_cycletype:
Coverage_array[502] = "midiseq.in.c 1097";                             dblog("    %15lld cycle", MEvent_t(cell));
Coverage_array[503] = "midiseq.in.c 1098";                             break;
Coverage_array[504] = "midiseq.in.c 1099";                     }
Coverage_array[505] = "midiseq.in.c 1100";                 }
Coverage_array[506] = "midiseq.in.c 1101";                 return;
Coverage_array[507] = "midiseq.in.c 1102";             }

//
// F R O M     F I L E
//
                                                       APIF int midiseq_tokenize(FILE *fd, StringPtAr **ret, Error *err)
                                                       {
Coverage_array[508] = "midiseq.in.c 1109";                 static String *buffer       = NULL;
Coverage_array[509] = "midiseq.in.c 1110";                 static StringPtAr *arBuffer = NULL;
Coverage_array[510] = "midiseq.in.c 1111";                 if (buffer == NULL) {
Coverage_array[511] = "midiseq.in.c 1112";                     buffer   = String_empty();
Coverage_array[512] = "midiseq.in.c 1113";                     arBuffer = StringPtAr_new(0);
Coverage_array[513] = "midiseq.in.c 1114";                 }
Coverage_array[514] = "midiseq.in.c 1115";                 if (!String_readline(&buffer, fd, err)) {
Coverage_array[515] = "midiseq.in.c 1116";                     return 0;
Coverage_array[516] = "midiseq.in.c 1117";                 }
Coverage_array[517] = "midiseq.in.c 1118";                 String_split(buffer, ",", arBuffer);
Coverage_array[518] = "midiseq.in.c 1119";                 StringPtAr_foreach(it, arBuffer) {
Coverage_array[519] = "midiseq.in.c 1120";                     String_trim(it.var);
Coverage_array[520] = "midiseq.in.c 1121";                 }
Coverage_array[521] = "midiseq.in.c 1122";                 *ret = arBuffer;
Coverage_array[522] = "midiseq.in.c 1123";                 return 1;
Coverage_array[523] = "midiseq.in.c 1124";             }


                                                       APIF int Midiseq_assignLength(Midiseq *mseq)
                                                       {
Coverage_array[524] = "midiseq.in.c 1129";                 const long ppqn = 480;
Coverage_array[525] = "midiseq.in.c 1130";                 const long measureLength = ppqn*4;
Coverage_array[526] = "midiseq.in.c 1131";                 if (Midiseq_len(mseq) == 0) {
Coverage_array[527] = "midiseq.in.c 1132";                     mseq->sequenceLength = measureLength;
Coverage_array[528] = "midiseq.in.c 1133";                     return 0;
Coverage_array[529] = "midiseq.in.c 1134";                 }
Coverage_array[530] = "midiseq.in.c 1135";             
Coverage_array[531] = "midiseq.in.c 1136";                 Ticks end = 0;
Coverage_array[532] = "midiseq.in.c 1137";                 MEventAr_foreach(it, &mseq->events) {
Coverage_array[533] = "midiseq.in.c 1138";                     long t = it.var->t;
Coverage_array[534] = "midiseq.in.c 1139";                     if (it.var->type == Midiseq_notetype) {
Coverage_array[535] = "midiseq.in.c 1140";                         t += it.var->duration;
Coverage_array[536] = "midiseq.in.c 1141";                     }
Coverage_array[537] = "midiseq.in.c 1142";                     if (t > end) {
Coverage_array[538] = "midiseq.in.c 1143";                         end = t;
Coverage_array[539] = "midiseq.in.c 1144";                     }
Coverage_array[540] = "midiseq.in.c 1145";                 }
Coverage_array[541] = "midiseq.in.c 1146";             
Coverage_array[542] = "midiseq.in.c 1147";                 mseq->sequenceLength = (end/measureLength)*measureLength + (end % measureLength == 0 ? 0 : measureLength);
Coverage_array[543] = "midiseq.in.c 1148";                 return 0;
Coverage_array[544] = "midiseq.in.c 1149";             }


                                                       APIF int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err)
                                                       {
Coverage_array[545] = "midiseq.in.c 1154";                 MEventAr_insert(&mseq->events, index, cell, err);
Coverage_array[546] = "midiseq.in.c 1155";                 if (Error_iserror(err)) {
Coverage_array[547] = "midiseq.in.c 1156";                     return 1;
Coverage_array[548] = "midiseq.in.c 1157";                 }
Coverage_array[549] = "midiseq.in.c 1158";                 return 0;
Coverage_array[550] = "midiseq.in.c 1159";             }


                                                       APIF void Midiseq_insertEndgroup(Midiseq *mseq, Error *err)
                                                       {
Coverage_array[551] = "midiseq.in.c 1164";                 MEvent cell = {0};
Coverage_array[552] = "midiseq.in.c 1165";                 cell.type = Midiseq_endgrptype;
Coverage_array[553] = "midiseq.in.c 1166";             
Coverage_array[554] = "midiseq.in.c 1167";                 if (MEventAr_len(&mseq->events) < 2) {
Coverage_array[555] = "midiseq.in.c 1168";                     cell.t = mseq->sequenceLength;
Coverage_array[556] = "midiseq.in.c 1169";                     MEventAr_rforeach(it, &mseq->events) {
Coverage_array[557] = "midiseq.in.c 1170";                         if (it.var->type == Midiseq_notetype) {
Coverage_array[558] = "midiseq.in.c 1171";                             cell.t = it.var->t;
Coverage_array[559] = "midiseq.in.c 1172";                             MEventAr_insert(&mseq->events, 0, cell, err);
Coverage_array[560] = "midiseq.in.c 1173";                             return;   
Coverage_array[561] = "midiseq.in.c 1174";                         }
Coverage_array[562] = "midiseq.in.c 1175";                     }
Coverage_array[563] = "midiseq.in.c 1176";                     MEventAr_push(&mseq->events, cell);
Coverage_array[564] = "midiseq.in.c 1177";                     return;
Coverage_array[565] = "midiseq.in.c 1178";                 }
Coverage_array[566] = "midiseq.in.c 1179";             
Coverage_array[567] = "midiseq.in.c 1180";                 MEventAr_rforeach(it, &mseq->events) {
Coverage_array[568] = "midiseq.in.c 1181";                     if (it.var->type == Midiseq_notetype) {
Coverage_array[569] = "midiseq.in.c 1182";                         cell.t = it.var->t;
Coverage_array[570] = "midiseq.in.c 1183";                         int index = it.index;
Coverage_array[571] = "midiseq.in.c 1184";                         while (MEventArRIt_next(&it)) {
Coverage_array[572] = "midiseq.in.c 1185";                             if (cell.t != it.var->t) {
Coverage_array[573] = "midiseq.in.c 1186";                                 break;
Coverage_array[574] = "midiseq.in.c 1187";                             }
Coverage_array[575] = "midiseq.in.c 1188";                             index++;
Coverage_array[576] = "midiseq.in.c 1189";                         }
Coverage_array[577] = "midiseq.in.c 1190";                         if (index < 0) {
Coverage_array[578] = "midiseq.in.c 1191";                             index = 0;
Coverage_array[579] = "midiseq.in.c 1192";                         }
Coverage_array[580] = "midiseq.in.c 1193";                         Midiseq_insertCell(mseq, cell, index, err);
Coverage_array[581] = "midiseq.in.c 1194";                         return;
Coverage_array[582] = "midiseq.in.c 1195";                     }
Coverage_array[583] = "midiseq.in.c 1196";                 }
Coverage_array[584] = "midiseq.in.c 1197";             
Coverage_array[585] = "midiseq.in.c 1198";                 MEvent e = MEventAr_get(&mseq->events, 0, err);
Coverage_array[586] = "midiseq.in.c 1199";                 Error_returnVoidOnError(err);
Coverage_array[587] = "midiseq.in.c 1200";                 cell.t = e.t;
Coverage_array[588] = "midiseq.in.c 1201";                 Midiseq_insertCell(mseq, cell, 0, err);
Coverage_array[589] = "midiseq.in.c 1202";                 Error_returnVoidOnError(err);
Coverage_array[590] = "midiseq.in.c 1203";                 return;
Coverage_array[591] = "midiseq.in.c 1204";             }


                                                       APIF int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
                                                       {
Coverage_array[592] = "midiseq.in.c 1209";                 if (startTime > currentTime) {
Coverage_array[593] = "midiseq.in.c 1210";                     Error_format0(err, "INTERNAL ERROR");
Coverage_array[594] = "midiseq.in.c 1211";                     return 1;
Coverage_array[595] = "midiseq.in.c 1212";                 }
Coverage_array[596] = "midiseq.in.c 1213";                 Ticks adj            = mseq->sequenceLength*((currentTime-startTime)/mseq->sequenceLength);
Coverage_array[597] = "midiseq.in.c 1214";                 mseq->startTime      = startTime + adj;
Coverage_array[598] = "midiseq.in.c 1215";                 mseq->useMasterClock = useMasterClock;
Coverage_array[599] = "midiseq.in.c 1216";                 mseq->ptr            = 0;
Coverage_array[600] = "midiseq.in.c 1217";                 if (useMasterClock) {
Coverage_array[601] = "midiseq.in.c 1218";                     if (Midiseq_fastfwrd(mseq, currentTime, err)) {
Coverage_array[602] = "midiseq.in.c 1219";                         return 1;
Coverage_array[603] = "midiseq.in.c 1220";                     }
Coverage_array[604] = "midiseq.in.c 1221";                 }
Coverage_array[605] = "midiseq.in.c 1222";                 return 0;
Coverage_array[606] = "midiseq.in.c 1223";             }


                                                       APIF void Midiseq_stop(Midiseq *mseq)
                                                       {
Coverage_array[607] = "midiseq.in.c 1228";                 mseq->startTime = 0;
Coverage_array[608] = "midiseq.in.c 1229";                 return;
Coverage_array[609] = "midiseq.in.c 1230";             }


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
Coverage_array[610] = "midiseq.in.c 1246";                 if (mseq->startTime == 0) {
Coverage_array[611] = "midiseq.in.c 1247";                     Error_format0(err, "Called nextevent on stoped sequence");
Coverage_array[612] = "midiseq.in.c 1248";                     return Midiseq_nextEventErrored;
Coverage_array[613] = "midiseq.in.c 1249";                 }
Coverage_array[614] = "midiseq.in.c 1250";                 if (mseq->ptr >= Midiseq_len(mseq)) {
Coverage_array[615] = "midiseq.in.c 1251";                     // This is the case when the entire sequence has been played, and this
Coverage_array[616] = "midiseq.in.c 1252";                     // is NOT a useMasterClock sequence. If useMasterClock is true mseq->ptr should
Coverage_array[617] = "midiseq.in.c 1253";                     // never satisfy the if criterion.
Coverage_array[618] = "midiseq.in.c 1254";                     *cell = MEventAr_get(&mseq->events, MEventAr_last(&mseq->events), err);
Coverage_array[619] = "midiseq.in.c 1255";                     if (Error_iserror(err)) {
Coverage_array[620] = "midiseq.in.c 1256";                         return Midiseq_nextEventErrored;
Coverage_array[621] = "midiseq.in.c 1257";                     }
Coverage_array[622] = "midiseq.in.c 1258";                     return Midiseq_nextEventComplete;
Coverage_array[623] = "midiseq.in.c 1259";                 }
Coverage_array[624] = "midiseq.in.c 1260";             
Coverage_array[625] = "midiseq.in.c 1261";                 MEvent c = MEventAr_get(&mseq->events, mseq->ptr, err);
Coverage_array[626] = "midiseq.in.c 1262";                 if (Error_iserror(err)) {
Coverage_array[627] = "midiseq.in.c 1263";                     return Midiseq_nextEventErrored;
Coverage_array[628] = "midiseq.in.c 1264";                 }
Coverage_array[629] = "midiseq.in.c 1265";             
Coverage_array[630] = "midiseq.in.c 1266";                 Ticks t = c.t + mseq->startTime;
Coverage_array[631] = "midiseq.in.c 1267";                 Ticks diff = t-until >= 0 ? t-until : until-t;
Coverage_array[632] = "midiseq.in.c 1268";             
Coverage_array[633] = "midiseq.in.c 1269";                 if ( (diff-1)/mseq->sequenceLength > 0) {
Coverage_array[634] = "midiseq.in.c 1270";                     Error_format(err, "INTERNAL ERROR %lld %lld %lld", diff, mseq->sequenceLength, diff/mseq->sequenceLength);
Coverage_array[635] = "midiseq.in.c 1271";                     return Midiseq_nextEventErrored;
Coverage_array[636] = "midiseq.in.c 1272";                 }
Coverage_array[637] = "midiseq.in.c 1273";             
Coverage_array[638] = "midiseq.in.c 1274";                 *cell = c;
Coverage_array[639] = "midiseq.in.c 1275";                 cell->t = t;
Coverage_array[640] = "midiseq.in.c 1276";                 if (t > until) {
Coverage_array[641] = "midiseq.in.c 1277";                     return Midiseq_nextEventBreak;
Coverage_array[642] = "midiseq.in.c 1278";                 }
Coverage_array[643] = "midiseq.in.c 1279";             
Coverage_array[644] = "midiseq.in.c 1280";                 mseq->ptr++;
Coverage_array[645] = "midiseq.in.c 1281";                 if (mseq->ptr >= Midiseq_len(mseq) && mseq->useMasterClock) {
Coverage_array[646] = "midiseq.in.c 1282";                     mseq->ptr        = 0;
Coverage_array[647] = "midiseq.in.c 1283";                     mseq->startTime += mseq->sequenceLength;
Coverage_array[648] = "midiseq.in.c 1284";                 }
Coverage_array[649] = "midiseq.in.c 1285";                 return Midiseq_nextEventContinue;
Coverage_array[650] = "midiseq.in.c 1286";             }


                                                       APIF int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err)
                                                       {
Coverage_array[651] = "midiseq.in.c 1291";                 if (mseq->startTime == 0) {
Coverage_array[652] = "midiseq.in.c 1292";                     return 1;
Coverage_array[653] = "midiseq.in.c 1293";                 }
Coverage_array[654] = "midiseq.in.c 1294";             
Coverage_array[655] = "midiseq.in.c 1295";                 MEventAr_foreach(it, &mseq->events) {
Coverage_array[656] = "midiseq.in.c 1296";                     if (it.var->t + mseq->startTime >= t) {
Coverage_array[657] = "midiseq.in.c 1297";                         mseq->ptr = it.index;
Coverage_array[658] = "midiseq.in.c 1298";                         return 0;
Coverage_array[659] = "midiseq.in.c 1299";                     }
Coverage_array[660] = "midiseq.in.c 1300";                 }
Coverage_array[661] = "midiseq.in.c 1301";             
Coverage_array[662] = "midiseq.in.c 1302";                 mseq->ptr = 0;
Coverage_array[663] = "midiseq.in.c 1303";                 return 0;
Coverage_array[664] = "midiseq.in.c 1304";             }


                                                       APIF Midiseq *Midiseq_fromfile(const char *fullpath, Error *err)
                                                       {
Coverage_array[665] = "midiseq.in.c 1309";                 char tempfile[] = "/tmp/MidiseqMaxMSPXXXXXX";
Coverage_array[666] = "midiseq.in.c 1310";                 FILE *fd = NULL;
Coverage_array[667] = "midiseq.in.c 1311";                 bool allOK = false;
Coverage_array[668] = "midiseq.in.c 1312";                 Midiseq *mseq = (Midiseq*)Mem_calloc(sizeof(Midiseq));
Coverage_array[669] = "midiseq.in.c 1313";                 Midiseq_init(mseq);
Coverage_array[670] = "midiseq.in.c 1314";                 MEventAr_truncate(&mseq->events);
Coverage_array[671] = "midiseq.in.c 1315";             
Coverage_array[672] = "midiseq.in.c 1316";                 // Call midicsv. To do this we create a new destination file, then route our output to it
Coverage_array[673] = "midiseq.in.c 1317";                 String *buffer = NULL;
Coverage_array[674] = "midiseq.in.c 1318";                 int tempFd = mkstemp(tempfile);
Coverage_array[675] = "midiseq.in.c 1319";                 if (tempFd < 0) {
Coverage_array[676] = "midiseq.in.c 1320";                     Error_format0(err, "Failed to create temp file");
Coverage_array[677] = "midiseq.in.c 1321";                     goto END;
Coverage_array[678] = "midiseq.in.c 1322";                 }
Coverage_array[679] = "midiseq.in.c 1323";                 close(tempFd);
Coverage_array[680] = "midiseq.in.c 1324";             
Coverage_array[681] = "midiseq.in.c 1325";                 buffer = String_fmt("'%s' '%s' > '%s'", Midiseq_midiCsvExecPath, fullpath, tempfile);    
Coverage_array[682] = "midiseq.in.c 1326";                 int exitCode = system(buffer);
Coverage_array[683] = "midiseq.in.c 1327";                 if (exitCode != 0) {
Coverage_array[684] = "midiseq.in.c 1328";                     Error_format(err, "Failed '%s' with exit code %d", buffer, exitCode);
Coverage_array[685] = "midiseq.in.c 1329";                     goto END;
Coverage_array[686] = "midiseq.in.c 1330";                 }
Coverage_array[687] = "midiseq.in.c 1331";             
Coverage_array[688] = "midiseq.in.c 1332";                 // Open the result file and parse away
Coverage_array[689] = "midiseq.in.c 1333";                 fd = fopen(tempfile, "r");
Coverage_array[690] = "midiseq.in.c 1334";                 if (fd == NULL) {
Coverage_array[691] = "midiseq.in.c 1335";                     Error_format(err, "Failed to open temp file '%s'", tempfile);
Coverage_array[692] = "midiseq.in.c 1336";                     goto END;
Coverage_array[693] = "midiseq.in.c 1337";                 }
Coverage_array[694] = "midiseq.in.c 1338";             
Coverage_array[695] = "midiseq.in.c 1339";                 int desiredPPQN = 480;
Coverage_array[696] = "midiseq.in.c 1340";                 float tickFactor = 1.0;
Coverage_array[697] = "midiseq.in.c 1341";             
Coverage_array[698] = "midiseq.in.c 1342";                 // ons[i] holds the index-1 of the last note-on of pitch i. Or zero if there is no pending note-on
Coverage_array[699] = "midiseq.in.c 1343";                 int ons[128] = {0};
Coverage_array[700] = "midiseq.in.c 1344";                 int linenum = 0;
Coverage_array[701] = "midiseq.in.c 1345";                 while (true) {
Coverage_array[702] = "midiseq.in.c 1346";                     StringPtAr *fieldsAr = NULL;
Coverage_array[703] = "midiseq.in.c 1347";                     if (!midiseq_tokenize(fd, &fieldsAr, err)) {
Coverage_array[704] = "midiseq.in.c 1348";                         if (Error_iserror(err)) {
Coverage_array[705] = "midiseq.in.c 1349";                             goto END;
Coverage_array[706] = "midiseq.in.c 1350";                         }
Coverage_array[707] = "midiseq.in.c 1351";                         break;
Coverage_array[708] = "midiseq.in.c 1352";                     }
Coverage_array[709] = "midiseq.in.c 1353";                     linenum++;
Coverage_array[710] = "midiseq.in.c 1354";             
Coverage_array[711] = "midiseq.in.c 1355";                     if (StringPtAr_len(fieldsAr) < 3) {
Coverage_array[712] = "midiseq.in.c 1356";                         Error_format(err, "Not enough fields in midicsv file '%s' line %d", tempfile, linenum);
Coverage_array[713] = "midiseq.in.c 1357";                         goto END;
Coverage_array[714] = "midiseq.in.c 1358";                     }
Coverage_array[715] = "midiseq.in.c 1359";             
Coverage_array[716] = "midiseq.in.c 1360";                     int nfields   = StringPtAr_len(fieldsAr);
Coverage_array[717] = "midiseq.in.c 1361";             
Coverage_array[718] = "midiseq.in.c 1362";                     // THIS IS AWEFUL. IMPORTANT you can't touch fields after you call _push or any other method that might reallocate.
Coverage_array[719] = "midiseq.in.c 1363";                     char **fields = (char**)fieldsAr->data;
Coverage_array[720] = "midiseq.in.c 1364";                     if (Error_iserror(err)) {
Coverage_array[721] = "midiseq.in.c 1365";                         goto END;
Coverage_array[722] = "midiseq.in.c 1366";                     }
Coverage_array[723] = "midiseq.in.c 1367";             
Coverage_array[724] = "midiseq.in.c 1368";                     MEvent cell = {0};
Coverage_array[725] = "midiseq.in.c 1369";                     cell.t = (long)(tickFactor*Midiseq_convertInt(fields[1], err));
Coverage_array[726] = "midiseq.in.c 1370";                     if (Error_iserror(err)) {
Coverage_array[727] = "midiseq.in.c 1371";                         goto END;
Coverage_array[728] = "midiseq.in.c 1372";                     }
Coverage_array[729] = "midiseq.in.c 1373";             
Coverage_array[730] = "midiseq.in.c 1374";                     const char *typ = fields[2];
Coverage_array[731] = "midiseq.in.c 1375";             
Coverage_array[732] = "midiseq.in.c 1376";                     bool isOn = strcmp(typ, "Note_on_c") == 0;
Coverage_array[733] = "midiseq.in.c 1377";                     bool isOff = strcmp(typ, "Note_off_c") == 0;
Coverage_array[734] = "midiseq.in.c 1378";                     if ( isOn || isOff ) {
Coverage_array[735] = "midiseq.in.c 1379";                         if (nfields < 6) {
Coverage_array[736] = "midiseq.in.c 1380";                             Error_format(err, "Bad Note_on_c file '%s' line %d", tempfile, linenum);
Coverage_array[737] = "midiseq.in.c 1381";                             goto END;
Coverage_array[738] = "midiseq.in.c 1382";                         }
Coverage_array[739] = "midiseq.in.c 1383";                         long pitch    = Midiseq_convertInt(fields[4], err);
Coverage_array[740] = "midiseq.in.c 1384";                         long velocity = Midiseq_convertInt(fields[5], err);
Coverage_array[741] = "midiseq.in.c 1385";                         if (Error_iserror(err)) {
Coverage_array[742] = "midiseq.in.c 1386";                             goto END;
Coverage_array[743] = "midiseq.in.c 1387";                         }
Coverage_array[744] = "midiseq.in.c 1388";                         if (velocity == 0) {
Coverage_array[745] = "midiseq.in.c 1389";                             isOn = false;
Coverage_array[746] = "midiseq.in.c 1390";                             isOff = true;
Coverage_array[747] = "midiseq.in.c 1391";                         }
Coverage_array[748] = "midiseq.in.c 1392";             
Coverage_array[749] = "midiseq.in.c 1393";                         if (isOn) {
Coverage_array[750] = "midiseq.in.c 1394";                             cell.type = Midiseq_notetype;
Coverage_array[751] = "midiseq.in.c 1395";                             cell.b.b[0]  = (uint8_t)pitch;
Coverage_array[752] = "midiseq.in.c 1396";                             cell.b.b[1]  = (uint8_t)velocity;
Coverage_array[753] = "midiseq.in.c 1397";                             if (ons[pitch] != 0) {
Coverage_array[754] = "midiseq.in.c 1398";                                 Error_format(err, "Found an unbalanced NOTE-ON: while working on` file '%s' line %d", tempfile, linenum);
Coverage_array[755] = "midiseq.in.c 1399";                                 goto END;
Coverage_array[756] = "midiseq.in.c 1400";                             }
Coverage_array[757] = "midiseq.in.c 1401";                             Midiseq_push(mseq, cell);
Coverage_array[758] = "midiseq.in.c 1402";                             ons[pitch] = Midiseq_len(mseq);
Coverage_array[759] = "midiseq.in.c 1403";                         } else {
Coverage_array[760] = "midiseq.in.c 1404";                             if (ons[pitch] == 0) {
Coverage_array[761] = "midiseq.in.c 1405";                                 Error_format(err, "Found an unmatched note-off: while working on` file '%s' line %d", tempfile, linenum);
Coverage_array[762] = "midiseq.in.c 1406";                                 goto END;
Coverage_array[763] = "midiseq.in.c 1407";                             }
Coverage_array[764] = "midiseq.in.c 1408";                             int index = ons[pitch]-1;
Coverage_array[765] = "midiseq.in.c 1409";                             if (index >= Midiseq_len(mseq)) {
Coverage_array[766] = "midiseq.in.c 1410";                                 Error_format0(err, "INTERNAL ERROR");
Coverage_array[767] = "midiseq.in.c 1411";                                 goto END;
Coverage_array[768] = "midiseq.in.c 1412";                             }
Coverage_array[769] = "midiseq.in.c 1413";                             MEvent *c = Midiseq_get(mseq, index, err);
Coverage_array[770] = "midiseq.in.c 1414";                             if (Error_iserror(err)) {
Coverage_array[771] = "midiseq.in.c 1415";                                 goto END;
Coverage_array[772] = "midiseq.in.c 1416";                             }
Coverage_array[773] = "midiseq.in.c 1417";                             c->duration = cell.t - c->t;
Coverage_array[774] = "midiseq.in.c 1418";                             ons[pitch] = 0;
Coverage_array[775] = "midiseq.in.c 1419";                         }
Coverage_array[776] = "midiseq.in.c 1420";                     } else if (strcmp(typ, "Pitch_bend_c") == 0) {
Coverage_array[777] = "midiseq.in.c 1421";                         if (nfields < 5) {
Coverage_array[778] = "midiseq.in.c 1422";                             Error_format(err, "Bad Pitch_bend_c file '%s' line %d", tempfile, linenum);
Coverage_array[779] = "midiseq.in.c 1423";                             goto END;
Coverage_array[780] = "midiseq.in.c 1424";                         }
Coverage_array[781] = "midiseq.in.c 1425";                         long value = Midiseq_convertInt(fields[4], err);
Coverage_array[782] = "midiseq.in.c 1426";                         if (Error_iserror(err)) {
Coverage_array[783] = "midiseq.in.c 1427";                             goto END;
Coverage_array[784] = "midiseq.in.c 1428";                         }
Coverage_array[785] = "midiseq.in.c 1429";                         cell.type   = Midiseq_bendtype;
Coverage_array[786] = "midiseq.in.c 1430";                         cell.b.bend = value;
Coverage_array[787] = "midiseq.in.c 1431";                         Midiseq_push(mseq, cell);
Coverage_array[788] = "midiseq.in.c 1432";                     } else if (strcmp(typ, "Control_c") == 0) {
Coverage_array[789] = "midiseq.in.c 1433";                         if (nfields < 5) {
Coverage_array[790] = "midiseq.in.c 1434";                             Error_format(err, "Bad Control_c file '%s' line %d", tempfile, linenum);
Coverage_array[791] = "midiseq.in.c 1435";                             goto END;
Coverage_array[792] = "midiseq.in.c 1436";                         }
Coverage_array[793] = "midiseq.in.c 1437";                         long cc = Midiseq_convertInt(fields[4], err);
Coverage_array[794] = "midiseq.in.c 1438";                         long val  = Midiseq_convertInt(fields[5], err);
Coverage_array[795] = "midiseq.in.c 1439";                         if (Error_iserror(err)) {
Coverage_array[796] = "midiseq.in.c 1440";                             goto END;
Coverage_array[797] = "midiseq.in.c 1441";                         }
Coverage_array[798] = "midiseq.in.c 1442";                         cell.type = Midiseq_cctype;
Coverage_array[799] = "midiseq.in.c 1443";                         cell.b.b[0]  = (uint8_t)cc;
Coverage_array[800] = "midiseq.in.c 1444";                         cell.b.b[1]  = (uint8_t)val;
Coverage_array[801] = "midiseq.in.c 1445";                         Midiseq_push(mseq, cell);
Coverage_array[802] = "midiseq.in.c 1446";                     } else if (strcmp(typ, "Header") == 0) {
Coverage_array[803] = "midiseq.in.c 1447";                         if (nfields < 6) {
Coverage_array[804] = "midiseq.in.c 1448";                             Error_format(err, "Bad Header file '%s' line %d", tempfile, linenum);
Coverage_array[805] = "midiseq.in.c 1449";                             goto END;
Coverage_array[806] = "midiseq.in.c 1450";                         }
Coverage_array[807] = "midiseq.in.c 1451";                         long ppqn = Midiseq_convertInt(fields[5], err);
Coverage_array[808] = "midiseq.in.c 1452";                         if (Error_iserror(err)) {
Coverage_array[809] = "midiseq.in.c 1453";                             goto END;
Coverage_array[810] = "midiseq.in.c 1454";                         }
Coverage_array[811] = "midiseq.in.c 1455";                         tickFactor = (float)(desiredPPQN)/(float)(ppqn);
Coverage_array[812] = "midiseq.in.c 1456";                     }
Coverage_array[813] = "midiseq.in.c 1457";                     fields = NULL;
Coverage_array[814] = "midiseq.in.c 1458";                     nfields = 0;
Coverage_array[815] = "midiseq.in.c 1459";                 }
Coverage_array[816] = "midiseq.in.c 1460";             
Coverage_array[817] = "midiseq.in.c 1461";                 // Compute length and install cycle and end group
Coverage_array[818] = "midiseq.in.c 1462";                 Midiseq_assignLength(mseq);
Coverage_array[819] = "midiseq.in.c 1463";                 MEvent cycle = {0};
Coverage_array[820] = "midiseq.in.c 1464";                 cycle.t = mseq->sequenceLength;
Coverage_array[821] = "midiseq.in.c 1465";                 cycle.type = Midiseq_cycletype;
Coverage_array[822] = "midiseq.in.c 1466";                 Midiseq_push(mseq, cycle);
Coverage_array[823] = "midiseq.in.c 1467";                 Midiseq_insertEndgroup(mseq, err);
Coverage_array[824] = "midiseq.in.c 1468";                 if (Error_iserror(err)) {
Coverage_array[825] = "midiseq.in.c 1469";                     Error_clear(err);
Coverage_array[826] = "midiseq.in.c 1470";                     goto END;
Coverage_array[827] = "midiseq.in.c 1471";                 }
Coverage_array[828] = "midiseq.in.c 1472";                 allOK = true;
Coverage_array[829] = "midiseq.in.c 1473";             
Coverage_array[830] = "midiseq.in.c 1474";                 END:
Coverage_array[831] = "midiseq.in.c 1475";                 if (buffer != NULL) {
Coverage_array[832] = "midiseq.in.c 1476";                     String_free(buffer);
Coverage_array[833] = "midiseq.in.c 1477";                 }
Coverage_array[834] = "midiseq.in.c 1478";                 if (fd != NULL) {
Coverage_array[835] = "midiseq.in.c 1479";                     fclose(fd);
Coverage_array[836] = "midiseq.in.c 1480";                 }
Coverage_array[837] = "midiseq.in.c 1481";                 
Coverage_array[838] = "midiseq.in.c 1482";                 unlink(tempfile);
Coverage_array[839] = "midiseq.in.c 1483";             
Coverage_array[840] = "midiseq.in.c 1484";                 if (allOK) {
Coverage_array[841] = "midiseq.in.c 1485";                     return mseq;
Coverage_array[842] = "midiseq.in.c 1486";                 }
Coverage_array[843] = "midiseq.in.c 1487";             
Coverage_array[844] = "midiseq.in.c 1488";             
Coverage_array[845] = "midiseq.in.c 1489";                 // Error state
Coverage_array[846] = "midiseq.in.c 1490";                 Midiseq_free(mseq);
Coverage_array[847] = "midiseq.in.c 1491";                 return NULL;
Coverage_array[848] = "midiseq.in.c 1492";             }

//
// P A T C H E R    F I N D
//
#line 1519 "src/midiseq.in.c"

#line 1543 "src/midiseq.in.c"

#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


#ifndef TEST_BUILD
                                                       APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
                                                       {
Coverage_array[849] = "midiseq.in.c 1550";                 MaxObject *obj = jbox_get_object(targetBox);
Coverage_array[850] = "midiseq.in.c 1551";                 if (Symbol_gen("Port") != object_classname(obj)) {
Coverage_array[851] = "midiseq.in.c 1552";                     return 0;
Coverage_array[852] = "midiseq.in.c 1553";                 }
Coverage_array[853] = "midiseq.in.c 1554";             
Coverage_array[854] = "midiseq.in.c 1555";                 Symbol *varname = object_attr_getsym(targetBox, Symbol_gen("varname"));
Coverage_array[855] = "midiseq.in.c 1556";                 if (varname == NULL) {
Coverage_array[856] = "midiseq.in.c 1557";                     varname = Symbol_gen("unknown");
Coverage_array[857] = "midiseq.in.c 1558";                 }
Coverage_array[858] = "midiseq.in.c 1559";             
Coverage_array[859] = "midiseq.in.c 1560";                 PortFindCell pfc = {0};
Coverage_array[860] = "midiseq.in.c 1561";                 Port *port          = (Port*)obj;
Coverage_array[861] = "midiseq.in.c 1562";                 pfc.reciever        = port;
Coverage_array[862] = "midiseq.in.c 1563";                 pfc.varname         = varname;
Coverage_array[863] = "midiseq.in.c 1564";                 PortFindCellAr_push(&pf->objects, pfc);
Coverage_array[864] = "midiseq.in.c 1565";             
Coverage_array[865] = "midiseq.in.c 1566";                 Port_setHub(port, PortFind_hub(pf));
Coverage_array[866] = "midiseq.in.c 1567";                 Port_setAnythingDispatch(port, PortFind_anythingDispatch(pf));
Coverage_array[867] = "midiseq.in.c 1568";                 Port_setIntDispatch(port, PortFind_intDispatch(pf));
Coverage_array[868] = "midiseq.in.c 1569";             
Coverage_array[869] = "midiseq.in.c 1570";                 return 0;
Coverage_array[870] = "midiseq.in.c 1571";             }

                                                       APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
                                                       {
Coverage_array[871] = "midiseq.in.c 1575";                 PortFind_setHub(pf, hub);
Coverage_array[872] = "midiseq.in.c 1576";                 PortFind_setAnythingDispatch(pf, (Port_anythingDispatchFunc)Hub_anythingDispatch);
Coverage_array[873] = "midiseq.in.c 1577";                 PortFind_setIntDispatch(pf, (Port_intDispatchFunc)Hub_intDispatch);
Coverage_array[874] = "midiseq.in.c 1578";             
Coverage_array[875] = "midiseq.in.c 1579";                 MaxObject *patcher = NULL;
Coverage_array[876] = "midiseq.in.c 1580";                 long result       = 0;
Coverage_array[877] = "midiseq.in.c 1581";                 t_max_err maxErr = object_obex_lookup(sourceMaxObject, Symbol_gen("#P"), &patcher);
Coverage_array[878] = "midiseq.in.c 1582";                 if (maxErr != MAX_ERR_NONE) {
Coverage_array[879] = "midiseq.in.c 1583";                     Error_format(err, "Failed object_obex_lookup (%s)", Error_maxErrToString(maxErr));
Coverage_array[880] = "midiseq.in.c 1584";                     return 0;
Coverage_array[881] = "midiseq.in.c 1585";                 }
Coverage_array[882] = "midiseq.in.c 1586";                 object_method(patcher, Symbol_gen("iterate"), PortFind_iterator, (void *)pf, PI_WANTBOX | PI_DEEP, &result);
Coverage_array[883] = "midiseq.in.c 1587";             
Coverage_array[884] = "midiseq.in.c 1588";                 PortFind_setHub(pf, NULL);
Coverage_array[885] = "midiseq.in.c 1589";                 PortFind_setAnythingDispatch(pf, NULL);
Coverage_array[886] = "midiseq.in.c 1590";                 PortFind_setIntDispatch(pf, NULL);
Coverage_array[887] = "midiseq.in.c 1591";             
Coverage_array[888] = "midiseq.in.c 1592";                 return 0;
Coverage_array[889] = "midiseq.in.c 1593";             }

#else 
                                                       APIF long PortFind_iterator(PortFind *pf, MaxObject *targetBox)
                                                       {
Coverage_array[890] = "midiseq.in.c 1598";                 return 0;
Coverage_array[891] = "midiseq.in.c 1599";             }
                                                       APIF int PortFind_discover(PortFind *pf, MaxObject *sourceMaxObject, void *hub, Error *err)
                                                       {
Coverage_array[892] = "midiseq.in.c 1602";                 return 0;
Coverage_array[893] = "midiseq.in.c 1603";             }
#endif

                                                       APIF Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol)
                                                       {
Coverage_array[894] = "midiseq.in.c 1608";                 PortFindCellAr_foreach(it, &pf->objects) {
Coverage_array[895] = "midiseq.in.c 1609";                     if (it.var->varname == symbol) {
Coverage_array[896] = "midiseq.in.c 1610";                         return it.var->reciever;
Coverage_array[897] = "midiseq.in.c 1611";                     }
Coverage_array[898] = "midiseq.in.c 1612";                 }
Coverage_array[899] = "midiseq.in.c 1613";                 return Port_null;
Coverage_array[900] = "midiseq.in.c 1614";             }


                                                       APIF Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol)
                                                       {
Coverage_array[901] = "midiseq.in.c 1619";                 PortFindCellAr_foreach(it, &pf->objects){
Coverage_array[902] = "midiseq.in.c 1620";                     if (it.var->reciever->track == symbol) {
Coverage_array[903] = "midiseq.in.c 1621";                         return it.var->reciever;
Coverage_array[904] = "midiseq.in.c 1622";                     }
Coverage_array[905] = "midiseq.in.c 1623";                 }
Coverage_array[906] = "midiseq.in.c 1624";                 return Port_null;
Coverage_array[907] = "midiseq.in.c 1625";             }


                                                       APIF Port *PortFind_findById(PortFind *pf, Symbol *symbol)
                                                       {
Coverage_array[908] = "midiseq.in.c 1630";                 PortFindCellAr_foreach(it, &pf->objects){
Coverage_array[909] = "midiseq.in.c 1631";                     if (Port_id(it.var->reciever) == symbol) {
Coverage_array[910] = "midiseq.in.c 1632";                         return it.var->reciever;
Coverage_array[911] = "midiseq.in.c 1633";                     }
Coverage_array[912] = "midiseq.in.c 1634";                 }
Coverage_array[913] = "midiseq.in.c 1635";                 return Port_null;
Coverage_array[914] = "midiseq.in.c 1636";             }


                                                       APIF int PortFind_portCount(PortFind *pf)
                                                       {
Coverage_array[915] = "midiseq.in.c 1641";                 return PortFindCellAr_len(&pf->objects);
Coverage_array[916] = "midiseq.in.c 1642";             }


                                                       APIF Port *PortFind_findByIndex(PortFind *pf, int index, Error *err)
                                                       {
Coverage_array[917] = "midiseq.in.c 1647";                 PortFindCell cell = PortFindCellAr_get(&pf->objects, index, err);
Coverage_array[918] = "midiseq.in.c 1648";                 if (Error_iserror(err)) {
Coverage_array[919] = "midiseq.in.c 1649";                     return Port_null;
Coverage_array[920] = "midiseq.in.c 1650";                 }
Coverage_array[921] = "midiseq.in.c 1651";                 
Coverage_array[922] = "midiseq.in.c 1652";                 return cell.reciever;
Coverage_array[923] = "midiseq.in.c 1653";             }

                                                       APIF Outlet *PortFind_createOutlet(PortFind *self, OutletSpecifier *spec) 
                                                       {
Coverage_array[924] = "midiseq.in.c 1657";                 Port *port = PortFind_findByTrack(self, spec->track);
Coverage_array[925] = "midiseq.in.c 1658";             
Coverage_array[926] = "midiseq.in.c 1659";                 if (spec->parameter == Symbol_gen("*note")) {
Coverage_array[927] = "midiseq.in.c 1660";                     NoteOutlet *outlet = NoteOutlet_newBuild(port);
Coverage_array[928] = "midiseq.in.c 1661";                     return NoteOutlet_castToOutlet(outlet);
Coverage_array[929] = "midiseq.in.c 1662";                 } else if (spec->parameter == Symbol_gen("*bend")) {
Coverage_array[930] = "midiseq.in.c 1663";                     BendOutlet *outlet = BendOutlet_newBuild(port);
Coverage_array[931] = "midiseq.in.c 1664";                     return BendOutlet_castToOutlet(outlet);
Coverage_array[932] = "midiseq.in.c 1665";                 } else if (spec->parameter == Symbol_gen("*cc")) {
Coverage_array[933] = "midiseq.in.c 1666";                     CcOutlet *outlet = CcOutlet_newBuild(port, spec->paramIndex);
Coverage_array[934] = "midiseq.in.c 1667";                     return CcOutlet_castToOutlet(outlet);
Coverage_array[935] = "midiseq.in.c 1668";                 }
Coverage_array[936] = "midiseq.in.c 1669";                 
Coverage_array[937] = "midiseq.in.c 1670";                 return NullOutlet_castToOutlet(NullOutlet_new());
Coverage_array[938] = "midiseq.in.c 1671";             }


//
// P A D
//

                                                       APIF void Pad_setSequence(Pad *pad, Midiseq *midi)
                                                       {
Coverage_array[939] = "midiseq.in.c 1680";                 if (Pad_sequence(pad) != NULL) {
Coverage_array[940] = "midiseq.in.c 1681";                     Midiseq_free(Pad_sequence(pad));
Coverage_array[941] = "midiseq.in.c 1682";                 }
Coverage_array[942] = "midiseq.in.c 1683";                 pad->sequence = midi;
Coverage_array[943] = "midiseq.in.c 1684";             }

                                                       APIF void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err) {
Coverage_array[944] = "midiseq.in.c 1687";                 BinFile_writeSymbol(bf, Pad_trackName(pad), err);
Coverage_array[945] = "midiseq.in.c 1688";                 Error_returnVoidOnError(err);    
Coverage_array[946] = "midiseq.in.c 1689";             
Coverage_array[947] = "midiseq.in.c 1690";                 BinFile_writeInteger(bf, Pad_padIndex(pad), err);
Coverage_array[948] = "midiseq.in.c 1691";                 Error_returnVoidOnError(err);    
Coverage_array[949] = "midiseq.in.c 1692";             
Coverage_array[950] = "midiseq.in.c 1693";                 Midiseq_toBinFile(Pad_sequence(pad), bf, err);
Coverage_array[951] = "midiseq.in.c 1694";                 Error_returnVoidOnError(err);
Coverage_array[952] = "midiseq.in.c 1695";             
Coverage_array[953] = "midiseq.in.c 1696";                 BinFile_writeBool(bf, Pad_chokeGroupGlobal(pad), err);
Coverage_array[954] = "midiseq.in.c 1697";                 Error_returnVoidOnError(err);
Coverage_array[955] = "midiseq.in.c 1698";             
Coverage_array[956] = "midiseq.in.c 1699";                 BinFile_writeInteger(bf, Pad_chokeGroupInstrument(pad), err);
Coverage_array[957] = "midiseq.in.c 1700";                 Error_returnVoidOnError(err);
Coverage_array[958] = "midiseq.in.c 1701";             
Coverage_array[959] = "midiseq.in.c 1702";                 BinFile_writeInteger(bf, Pad_chokeGroupIndex(pad), err);
Coverage_array[960] = "midiseq.in.c 1703";                 Error_returnVoidOnError(err);
Coverage_array[961] = "midiseq.in.c 1704";             }

                                                       APIF Pad *Pad_fromBinFile(BinFile *bf, Error *err) {
Coverage_array[962] = "midiseq.in.c 1707";                 Pad *pad = Pad_new();
Coverage_array[963] = "midiseq.in.c 1708";                 Pad_fromBinFileUninitialized(pad, bf, err);
Coverage_array[964] = "midiseq.in.c 1709";                 if (Error_iserror(err)) {
Coverage_array[965] = "midiseq.in.c 1710";                     Mem_free(pad);
Coverage_array[966] = "midiseq.in.c 1711";                     return NULL;
Coverage_array[967] = "midiseq.in.c 1712";                 }
Coverage_array[968] = "midiseq.in.c 1713";                 return pad;
Coverage_array[969] = "midiseq.in.c 1714";             }

                                                       APIF void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err) {
Coverage_array[970] = "midiseq.in.c 1717";                 Pad_setTrackName(pad, BinFile_readSymbol(bf, err));
Coverage_array[971] = "midiseq.in.c 1718";                 Error_returnVoidOnError(err);
Coverage_array[972] = "midiseq.in.c 1719";             
Coverage_array[973] = "midiseq.in.c 1720";                 Pad_setPadIndex(pad, BinFile_readInteger(bf, err));
Coverage_array[974] = "midiseq.in.c 1721";                 Error_returnVoidOnError(err);
Coverage_array[975] = "midiseq.in.c 1722";             
Coverage_array[976] = "midiseq.in.c 1723";                 Pad_setSequence(pad, Midiseq_fromBinFile(bf, err));
Coverage_array[977] = "midiseq.in.c 1724";                 Error_returnVoidOnError(err);    
Coverage_array[978] = "midiseq.in.c 1725";             
Coverage_array[979] = "midiseq.in.c 1726";                 Pad_setChokeGroupGlobal(pad, BinFile_readBool(bf, err));
Coverage_array[980] = "midiseq.in.c 1727";                 Error_returnVoidOnError(err);
Coverage_array[981] = "midiseq.in.c 1728";             
Coverage_array[982] = "midiseq.in.c 1729";                 Pad_setChokeGroupInstrument(pad, BinFile_readInteger(bf, err));
Coverage_array[983] = "midiseq.in.c 1730";                 Error_returnVoidOnError(err);
Coverage_array[984] = "midiseq.in.c 1731";             
Coverage_array[985] = "midiseq.in.c 1732";                 Pad_setChokeGroupIndex(pad, BinFile_readInteger(bf, err));
Coverage_array[986] = "midiseq.in.c 1733";                 Error_returnVoidOnError(err);
Coverage_array[987] = "midiseq.in.c 1734";             }

                                                       APIF void Pad_computeChokeGroup(Pad *pad) {
Coverage_array[988] = "midiseq.in.c 1737";                 if (!Pad_chokeGroupGlobal(pad) && Pad_chokeGroupInstrument(pad) == 0 && Pad_chokeGroupIndex(pad) == 0) {
Coverage_array[989] = "midiseq.in.c 1738";                     Pad_setChokeGroup(pad, 0);
Coverage_array[990] = "midiseq.in.c 1739";                     return;    
Coverage_array[991] = "midiseq.in.c 1740";                 }
Coverage_array[992] = "midiseq.in.c 1741";             
Coverage_array[993] = "midiseq.in.c 1742";                 int64_t value = 0;
Coverage_array[994] = "midiseq.in.c 1743";                 if (!Pad_chokeGroupGlobal(pad)) {
Coverage_array[995] = "midiseq.in.c 1744";             
Coverage_array[996] = "midiseq.in.c 1745";                     int64_t bank  = hub_padIndexToBank(Pad_padIndex(pad));
Coverage_array[997] = "midiseq.in.c 1746";                     int64_t frame = hub_padIndexToFrame(Pad_padIndex(pad));
Coverage_array[998] = "midiseq.in.c 1747";             
Coverage_array[999] = "midiseq.in.c 1748";                     //Hubbank;
Coverage_array[1000] = "midiseq.in.c 1749";                    value |= bank & 0x7FFFFFFF;        // 32 bit for bank
Coverage_array[1001] = "midiseq.in.c 1750";                    value |= (frame & 0xFF) << 32;     // 8 bit for frame
Coverage_array[1002] = "midiseq.in.c 1751";                }
Coverage_array[1003] = "midiseq.in.c 1752";                int64_t instrument = Pad_chokeGroupInstrument(pad);
Coverage_array[1004] = "midiseq.in.c 1753";                int64_t index      = Pad_chokeGroupIndex(pad);
Coverage_array[1005] = "midiseq.in.c 1754";            
Coverage_array[1006] = "midiseq.in.c 1755";                value |= (instrument & 0xFF) << 40; // 8 bits for instrument
Coverage_array[1007] = "midiseq.in.c 1756";                value |= (index & 0xFF)      << 48; // 8 bits for index
Coverage_array[1008] = "midiseq.in.c 1757";                Pad_setChokeGroup(pad, value);
Coverage_array[1009] = "midiseq.in.c 1758";            }

//
// P A D   L I S T
//
                                                       APIF PadList *PadList_newN(int npads)
                                                       {
Coverage_array[1010] = "midiseq.in.c 1765";                PadList *self = PadList_new();
Coverage_array[1011] = "midiseq.in.c 1766";                PadAr_changeLength(&self->pads, npads);
Coverage_array[1012] = "midiseq.in.c 1767";                PadAr_foreach(it, &self->pads) {
Coverage_array[1013] = "midiseq.in.c 1768";                    Pad_init(it.var);
Coverage_array[1014] = "midiseq.in.c 1769";                }
Coverage_array[1015] = "midiseq.in.c 1770";                return self;
Coverage_array[1016] = "midiseq.in.c 1771";            }

                                                       APIF void PadList_play(PadList *self, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
                                                       {
Coverage_array[1017] = "midiseq.in.c 1775";                Pad *pad = PadAr_getp(&self->pads, padIndex, err);
Coverage_array[1018] = "midiseq.in.c 1776";                Error_returnVoidOnError(err);
Coverage_array[1019] = "midiseq.in.c 1777";            
Coverage_array[1020] = "midiseq.in.c 1778";                // Since we're starting to play, we just recieved a Note-on for this pad. Reset the pad
Coverage_array[1021] = "midiseq.in.c 1779";                Pad_setInEndgroup(pad, false);
Coverage_array[1022] = "midiseq.in.c 1780";                Pad_setNoteReleasePending(pad, true);
Coverage_array[1023] = "midiseq.in.c 1781";            
Coverage_array[1024] = "midiseq.in.c 1782";                // Now let's find a place to stick this pad into the running array
Coverage_array[1025] = "midiseq.in.c 1783";                PadPtrAr_foreach(it, &self->running) {
Coverage_array[1026] = "midiseq.in.c 1784";                    Pad *p = *it.var;
Coverage_array[1027] = "midiseq.in.c 1785";                    if (Pad_chokeGroup(pad) != 0 && Pad_chokeGroup(pad) == Pad_chokeGroup(p)) {
Coverage_array[1028] = "midiseq.in.c 1786";                        PadPtrAr_remove(&self->running, it.index, err);
Coverage_array[1029] = "midiseq.in.c 1787";                        Error_returnVoidOnError(err);
Coverage_array[1030] = "midiseq.in.c 1788";                        break;
Coverage_array[1031] = "midiseq.in.c 1789";                    }
Coverage_array[1032] = "midiseq.in.c 1790";                }
Coverage_array[1033] = "midiseq.in.c 1791";            
Coverage_array[1034] = "midiseq.in.c 1792";                PadPtrAr_push(&self->running, pad);
Coverage_array[1035] = "midiseq.in.c 1793";            
Coverage_array[1036] = "midiseq.in.c 1794";               Midiseq_start(Pad_sequence(pad), startTime, currentTime, false, err);
Coverage_array[1037] = "midiseq.in.c 1795";            }


                                                       APIF void PadList_markReleasePending(PadList *self, int padIndex, bool pending, Error *err)
                                                       {
Coverage_array[1038] = "midiseq.in.c 1800";                Pad *pad = PadAr_getp(&self->pads, padIndex, err);
Coverage_array[1039] = "midiseq.in.c 1801";                Error_returnVoidOnError(err);
Coverage_array[1040] = "midiseq.in.c 1802";                Pad_setNoteReleasePending(pad, pending);
Coverage_array[1041] = "midiseq.in.c 1803";                if (!pending) {
Coverage_array[1042] = "midiseq.in.c 1804";                    // We recieved a note-off. So cancel any pending endgroups
Coverage_array[1043] = "midiseq.in.c 1805";                    NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
Coverage_array[1044] = "midiseq.in.c 1806";                }
Coverage_array[1045] = "midiseq.in.c 1807";            }

                                                       APIF Pad *PadList_pad(PadList *pl, int index, Error *err)
                                                       {
Coverage_array[1046] = "midiseq.in.c 1811";                return PadAr_getp(&pl->pads, index, err);
Coverage_array[1047] = "midiseq.in.c 1812";            }


                                                       APIF void PadList_assignTrack(PadList *pl, TrackList *tl)
                                                       {
Coverage_array[1048] = "midiseq.in.c 1817";                PadAr_foreach(it, &pl->pads) {
Coverage_array[1049] = "midiseq.in.c 1818";                    Pad *pad = it.var;
Coverage_array[1050] = "midiseq.in.c 1819";                    Pad_setTrack(pad, TrackList_findTrackByName(tl, Pad_trackName(pad)));
Coverage_array[1051] = "midiseq.in.c 1820";                }
Coverage_array[1052] = "midiseq.in.c 1821";            }

                                                       APIF void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err) {
Coverage_array[1053] = "midiseq.in.c 1824";                BinFile_writeTag(bf, "padlist_start", err);
Coverage_array[1054] = "midiseq.in.c 1825";                Error_returnVoidOnError(err);
Coverage_array[1055] = "midiseq.in.c 1826";            
Coverage_array[1056] = "midiseq.in.c 1827";                BinFile_writeInteger(bf, PadAr_len(&pl->pads), err);
Coverage_array[1057] = "midiseq.in.c 1828";                Error_returnVoidOnError(err);
Coverage_array[1058] = "midiseq.in.c 1829";            
Coverage_array[1059] = "midiseq.in.c 1830";                PadAr_foreach(it, &pl->pads) {
Coverage_array[1060] = "midiseq.in.c 1831";                    Pad_toBinFile(it.var, bf, err);
Coverage_array[1061] = "midiseq.in.c 1832";                    Error_returnVoidOnError(err);                
Coverage_array[1062] = "midiseq.in.c 1833";                }
Coverage_array[1063] = "midiseq.in.c 1834";            
Coverage_array[1064] = "midiseq.in.c 1835";                BinFile_writeTag(bf, "padlist_end", err);
Coverage_array[1065] = "midiseq.in.c 1836";                Error_returnVoidOnError(err);
Coverage_array[1066] = "midiseq.in.c 1837";            }

                                                       APIF PadList *PadList_fromBinFile(BinFile *bf, Error *err) {
Coverage_array[1067] = "midiseq.in.c 1840";                PadList *pl = PadList_newN(0);
Coverage_array[1068] = "midiseq.in.c 1841";                PadList_fromBinFileInitialized(pl, bf, err);
Coverage_array[1069] = "midiseq.in.c 1842";                if (Error_iserror(err)) {
Coverage_array[1070] = "midiseq.in.c 1843";                    PadList_free(pl);
Coverage_array[1071] = "midiseq.in.c 1844";                    return NULL;
Coverage_array[1072] = "midiseq.in.c 1845";                }
Coverage_array[1073] = "midiseq.in.c 1846";                return pl;
Coverage_array[1074] = "midiseq.in.c 1847";            }

// Remember the rul is that if there is an error, the PadList passed in remains uninitialized.
                                                       APIF void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err) {
Coverage_array[1075] = "midiseq.in.c 1851";                BinFile_verifyTag(bf, "padlist_start", err);
Coverage_array[1076] = "midiseq.in.c 1852";                Error_returnVoidOnError(err);
Coverage_array[1077] = "midiseq.in.c 1853";            
Coverage_array[1078] = "midiseq.in.c 1854";                long len = BinFile_readInteger(bf, err);
Coverage_array[1079] = "midiseq.in.c 1855";                Error_returnVoidOnError(err);
Coverage_array[1080] = "midiseq.in.c 1856";                        
Coverage_array[1081] = "midiseq.in.c 1857";                for (int i = 0; i < len; i++) {
Coverage_array[1082] = "midiseq.in.c 1858";                    Pad pad = {0};
Coverage_array[1083] = "midiseq.in.c 1859";                    Pad_fromBinFileUninitialized(&pad, bf, err);
Coverage_array[1084] = "midiseq.in.c 1860";                    Error_returnVoidOnError(err);
Coverage_array[1085] = "midiseq.in.c 1861";                    PadAr_push(&pl->pads, pad);
Coverage_array[1086] = "midiseq.in.c 1862";                }
Coverage_array[1087] = "midiseq.in.c 1863";                BinFile_verifyTag(bf, "padlist_end", err);
Coverage_array[1088] = "midiseq.in.c 1864";                PadAr_fit(&pl->pads);
Coverage_array[1089] = "midiseq.in.c 1865";            }

//
// T R A C K
//

                                                       APIF TrackList *TrackList_newBuild(PortFind *pf)
                                                       {
Coverage_array[1090] = "midiseq.in.c 1873";                TrackList *tl = TrackList_new();
Coverage_array[1091] = "midiseq.in.c 1874";                TrackList_build(tl, pf);
Coverage_array[1092] = "midiseq.in.c 1875";                return tl;
Coverage_array[1093] = "midiseq.in.c 1876";            }

                                                       APIF void TrackList_build(TrackList *tl, PortFind *pf) {
Coverage_array[1094] = "midiseq.in.c 1879";            
Coverage_array[1095] = "midiseq.in.c 1880";                {
Coverage_array[1096] = "midiseq.in.c 1881";                    // Insert the null track at position 1 of the tracklist
Coverage_array[1097] = "midiseq.in.c 1882";                    Track t = {0};
Coverage_array[1098] = "midiseq.in.c 1883";                    t.name  = Symbol_gen("null");
Coverage_array[1099] = "midiseq.in.c 1884";                    t.noteManager = NoteManager_newFromPort(Port_null);
Coverage_array[1100] = "midiseq.in.c 1885";                    TrackAr_push(&tl->list, t);
Coverage_array[1101] = "midiseq.in.c 1886";                }
Coverage_array[1102] = "midiseq.in.c 1887";            
Coverage_array[1103] = "midiseq.in.c 1888";                Error_declare(err);
Coverage_array[1104] = "midiseq.in.c 1889";                for (int i = 0; i < PortFind_portCount(pf); i++) {
Coverage_array[1105] = "midiseq.in.c 1890";                    // Notice I don't handle any error that occures. I assume none do since I bound findByIndex by portCount
Coverage_array[1106] = "midiseq.in.c 1891";                    Port *p = PortFind_findByIndex(pf, i, err);
Coverage_array[1107] = "midiseq.in.c 1892";                    if (Error_maypost(err)) {
Coverage_array[1108] = "midiseq.in.c 1893";                        continue;
Coverage_array[1109] = "midiseq.in.c 1894";                    }
Coverage_array[1110] = "midiseq.in.c 1895";                    Track t = {0};
Coverage_array[1111] = "midiseq.in.c 1896";                    Track_setName(&t, Port_track(p));
Coverage_array[1112] = "midiseq.in.c 1897";                    Track_setNoteManager(&t, NoteManager_newFromPort(p));
Coverage_array[1113] = "midiseq.in.c 1898";                    TrackAr_push(&tl->list, t);
Coverage_array[1114] = "midiseq.in.c 1899";                }
Coverage_array[1115] = "midiseq.in.c 1900";                Error_clear(err);
Coverage_array[1116] = "midiseq.in.c 1901";                return;
Coverage_array[1117] = "midiseq.in.c 1902";            }

                                                       APIF Track *TrackList_findTrackByName(TrackList *tl, Symbol *name)
                                                       {
Coverage_array[1118] = "midiseq.in.c 1906";                TrackAr_foreach(it, &tl->list) {
Coverage_array[1119] = "midiseq.in.c 1907";                    if (it.var->name == name) {
Coverage_array[1120] = "midiseq.in.c 1908";                        return it.var;
Coverage_array[1121] = "midiseq.in.c 1909";                    }
Coverage_array[1122] = "midiseq.in.c 1910";                }
Coverage_array[1123] = "midiseq.in.c 1911";            
Coverage_array[1124] = "midiseq.in.c 1912";                // Always return the Null track if didn't find.
Coverage_array[1125] = "midiseq.in.c 1913";                Error_declare(err);
Coverage_array[1126] = "midiseq.in.c 1914";                Track *t = TrackAr_getp(&tl->list, 0, err);
Coverage_array[1127] = "midiseq.in.c 1915";                Error_clear(err);
Coverage_array[1128] = "midiseq.in.c 1916";                return t;        
Coverage_array[1129] = "midiseq.in.c 1917";            }


                                                       APIF int TrackList_count(TrackList *tl)
                                                       {
Coverage_array[1130] = "midiseq.in.c 1922";                return TrackAr_len(&tl->list);
Coverage_array[1131] = "midiseq.in.c 1923";            }


                                                       APIF Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err)
                                                       {
Coverage_array[1132] = "midiseq.in.c 1928";                return TrackAr_getp(&tl->list, index, err);
Coverage_array[1133] = "midiseq.in.c 1929";            }

// NOTE: currently nothing is actually stored in the output file. The complete tracklist comes from a port find payload in the BinFile instance.
                                                       APIF TrackList *TrackList_fromBinFile(BinFile *bf, Error *err)
                                                       {
Coverage_array[1134] = "midiseq.in.c 1934";                PortFind *pf = BinFile_portFindPayload(bf);
Coverage_array[1135] = "midiseq.in.c 1935";                if (pf == NULL) {
Coverage_array[1136] = "midiseq.in.c 1936";                    Error_format0(err, "Expected portFindPayload on BinFile, but didn't see one");
Coverage_array[1137] = "midiseq.in.c 1937";                    return NULL;
Coverage_array[1138] = "midiseq.in.c 1938";                }
Coverage_array[1139] = "midiseq.in.c 1939";            
Coverage_array[1140] = "midiseq.in.c 1940";                return TrackList_newBuild(pf);
Coverage_array[1141] = "midiseq.in.c 1941";            }

                                                       APIF void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err) {
Coverage_array[1142] = "midiseq.in.c 1944";                // NO-op since nothing in the tracklist is written to file.
Coverage_array[1143] = "midiseq.in.c 1945";            }



//
// I N D E X E D   AND   T I M E D   O F F
//

                                                       APIF int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right) {
Coverage_array[1144] = "midiseq.in.c 1954";                if (left->padIndex < right->padIndex) {
Coverage_array[1145] = "midiseq.in.c 1955";                    return -1;
Coverage_array[1146] = "midiseq.in.c 1956";                } else if (left->padIndex > right->padIndex) {
Coverage_array[1147] = "midiseq.in.c 1957";                    return 1;
Coverage_array[1148] = "midiseq.in.c 1958";                }
Coverage_array[1149] = "midiseq.in.c 1959";                return 0;
Coverage_array[1150] = "midiseq.in.c 1960";            }

                                                       APIF int TimedOff_cmpTime(TimedOff *left, TimedOff *right) {
Coverage_array[1151] = "midiseq.in.c 1963";                if (left->time < right->time) {
Coverage_array[1152] = "midiseq.in.c 1964";                    return -1;
Coverage_array[1153] = "midiseq.in.c 1965";                } else if (left->time > right->time) {
Coverage_array[1154] = "midiseq.in.c 1966";                    return 1;
Coverage_array[1155] = "midiseq.in.c 1967";                }
Coverage_array[1156] = "midiseq.in.c 1968";                return 0;   
Coverage_array[1157] = "midiseq.in.c 1969";            }



//
// N O T E   M A N A G E R
//

const int NoteManager_atomcount = 4;


                                                       APIF NoteManager *NoteManager_newFromPort(Port *port)
                                                       {
Coverage_array[1158] = "midiseq.in.c 1982";                NoteManager *self = NoteManager_new();
Coverage_array[1159] = "midiseq.in.c 1983";                self->output      = port;
Coverage_array[1160] = "midiseq.in.c 1984";                return self;
Coverage_array[1161] = "midiseq.in.c 1985";            }

                                                       APIF void NoteManager_userInit(NoteManager *self)
                                                       {
Coverage_array[1162] = "midiseq.in.c 1989";                self->atoms = Mem_calloc(sizeof(Atom) * NoteManager_atomcount);    
Coverage_array[1163] = "midiseq.in.c 1990";            }

                                                       APIF void NoteManager_userClear(NoteManager *self) 
                                                       {
Coverage_array[1164] = "midiseq.in.c 1994";                Mem_free(self->atoms);
Coverage_array[1165] = "midiseq.in.c 1995";                self->atoms = NULL;
Coverage_array[1166] = "midiseq.in.c 1996";            }

// insert a note off, and remove any single pitch that is already there. Return true if a note-off was removed
                                                       APIF bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup)
                                                       {
Coverage_array[1167] = "midiseq.in.c 2001";                Error_declare(ignored);
Coverage_array[1168] = "midiseq.in.c 2002";                bool q = false;
Coverage_array[1169] = "midiseq.in.c 2003";                IndexedOffAr_foreach(it, &manager->endgroups) {
Coverage_array[1170] = "midiseq.in.c 2004";                    if (it.var->pitch == pitch) {
Coverage_array[1171] = "midiseq.in.c 2005";                        IndexedOffAr_remove(&manager->endgroups, it.index, ignored);
Coverage_array[1172] = "midiseq.in.c 2006";                        q = true;
Coverage_array[1173] = "midiseq.in.c 2007";                        break;
Coverage_array[1174] = "midiseq.in.c 2008";                    }
Coverage_array[1175] = "midiseq.in.c 2009";                }
Coverage_array[1176] = "midiseq.in.c 2010";            
Coverage_array[1177] = "midiseq.in.c 2011";                TimedOffAr_foreach(it, &manager->pending) {
Coverage_array[1178] = "midiseq.in.c 2012";                    if (it.var->pitch == pitch) {
Coverage_array[1179] = "midiseq.in.c 2013";                        TimedOffAr_remove(&manager->pending, it.index, ignored);
Coverage_array[1180] = "midiseq.in.c 2014";                        q = true;
Coverage_array[1181] = "midiseq.in.c 2015";                        break;
Coverage_array[1182] = "midiseq.in.c 2016";                    }   
Coverage_array[1183] = "midiseq.in.c 2017";                }
Coverage_array[1184] = "midiseq.in.c 2018";            
Coverage_array[1185] = "midiseq.in.c 2019";            
Coverage_array[1186] = "midiseq.in.c 2020";                if (padIndexForEndgroup >= 0) {
Coverage_array[1187] = "midiseq.in.c 2021";                    // Mark this pitch as endgroup
Coverage_array[1188] = "midiseq.in.c 2022";                    IndexedOff_declare(off, padIndexForEndgroup, pitch);
Coverage_array[1189] = "midiseq.in.c 2023";                    IndexedOffAr_binInsertPadIndex(&manager->endgroups, off);
Coverage_array[1190] = "midiseq.in.c 2024";                } else {
Coverage_array[1191] = "midiseq.in.c 2025";                    TimedOff_declare(off, timestamp, pitch);
Coverage_array[1192] = "midiseq.in.c 2026";                    TimedOffAr_binInsertTime(&manager->pending, off);
Coverage_array[1193] = "midiseq.in.c 2027";                }
Coverage_array[1194] = "midiseq.in.c 2028";            
Coverage_array[1195] = "midiseq.in.c 2029";                Error_maypost(ignored);
Coverage_array[1196] = "midiseq.in.c 2030";            
Coverage_array[1197] = "midiseq.in.c 2031";                return q;
Coverage_array[1198] = "midiseq.in.c 2032";            }


// This is 10010000 which is a note-on (1001), on channel 0 (0000)
const int NOTEON_COMMAND = 144;

                                                       APIF void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity)
                                                       {
Coverage_array[1199] = "midiseq.in.c 2040";                Atom *av = manager->atoms;
Coverage_array[1200] = "midiseq.in.c 2041";                av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
Coverage_array[1201] = "midiseq.in.c 2042";                av[1] = Atom_fromInteger(NOTEON_COMMAND);
Coverage_array[1202] = "midiseq.in.c 2043";                av[2] = Atom_fromInteger(pitch);
Coverage_array[1203] = "midiseq.in.c 2044";                av[3] = Atom_fromInteger(velocity);
Coverage_array[1204] = "midiseq.in.c 2045";                Error_declare(err);
Coverage_array[1205] = "midiseq.in.c 2046";                Port_send(manager->output, 0, 4, av, err);
Coverage_array[1206] = "midiseq.in.c 2047";                Error_maypost(err);
Coverage_array[1207] = "midiseq.in.c 2048";            }


                                                       APIF void NoteManager_flushOffs(NoteManager *manager)
                                                       {
Coverage_array[1208] = "midiseq.in.c 2053";                IndexedOffAr_foreach(it, &manager->endgroups) {
Coverage_array[1209] = "midiseq.in.c 2054";                    NoteManager_sendNoteOn(manager, it.var->pitch, 0);
Coverage_array[1210] = "midiseq.in.c 2055";                }
Coverage_array[1211] = "midiseq.in.c 2056";                IndexedOffAr_truncate(&manager->endgroups);
Coverage_array[1212] = "midiseq.in.c 2057";            
Coverage_array[1213] = "midiseq.in.c 2058";                TimedOffAr_foreach(it, &manager->pending) {
Coverage_array[1214] = "midiseq.in.c 2059";                    NoteManager_sendNoteOn(manager, it.var->pitch, 0);   
Coverage_array[1215] = "midiseq.in.c 2060";                }
Coverage_array[1216] = "midiseq.in.c 2061";                TimedOffAr_truncate(&manager->pending);
Coverage_array[1217] = "midiseq.in.c 2062";            }

                                                       APIF void NoteManager_allOff(NoteManager *manager)
                                                       {
Coverage_array[1218] = "midiseq.in.c 2066";                for (int i = 0; i < 128; i++) {
Coverage_array[1219] = "midiseq.in.c 2067";                    NoteManager_sendNoteOn(manager, i, 0);      
Coverage_array[1220] = "midiseq.in.c 2068";                }
Coverage_array[1221] = "midiseq.in.c 2069";            }

                                                       APIF void NoteManager_dblogPending(NoteManager *manager, Ticks current)
                                                       {
Coverage_array[1222] = "midiseq.in.c 2073";                dblog("dbPending %lld:", current);
Coverage_array[1223] = "midiseq.in.c 2074";                TimedOffAr_foreach(it, &manager->pending) {
Coverage_array[1224] = "midiseq.in.c 2075";                    dblog("  %lld %d", it.var->time-current, it.var->pitch); 
Coverage_array[1225] = "midiseq.in.c 2076";                }
Coverage_array[1226] = "midiseq.in.c 2077";            }


                                                       APIF Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current)
                                                       {
Coverage_array[1227] = "midiseq.in.c 2082";                Error_declare(err);
Coverage_array[1228] = "midiseq.in.c 2083";                int count = 0;
Coverage_array[1229] = "midiseq.in.c 2084";                TimedOffAr_foreach(it, &manager->pending) {
Coverage_array[1230] = "midiseq.in.c 2085";                    if (it.var->time > current) {
Coverage_array[1231] = "midiseq.in.c 2086";                        break;
Coverage_array[1232] = "midiseq.in.c 2087";                    }
Coverage_array[1233] = "midiseq.in.c 2088";                    NoteManager_sendNoteOn(manager, it.var->pitch , 0);
Coverage_array[1234] = "midiseq.in.c 2089";                    count++;
Coverage_array[1235] = "midiseq.in.c 2090";                }
Coverage_array[1236] = "midiseq.in.c 2091";                if (count > 0) {
Coverage_array[1237] = "midiseq.in.c 2092";                    TimedOffAr_removeN(&manager->pending, 0, count, err);
Coverage_array[1238] = "midiseq.in.c 2093";                    Error_maypost(err);
Coverage_array[1239] = "midiseq.in.c 2094";                }
Coverage_array[1240] = "midiseq.in.c 2095";                
Coverage_array[1241] = "midiseq.in.c 2096";                TimedOffAr_foreach(it, &manager->pending) {
Coverage_array[1242] = "midiseq.in.c 2097";                    return it.var->time-current;
Coverage_array[1243] = "midiseq.in.c 2098";                }
Coverage_array[1244] = "midiseq.in.c 2099";            
Coverage_array[1245] = "midiseq.in.c 2100";                return -1;
Coverage_array[1246] = "midiseq.in.c 2101";            }


// padIndexForEndgroup should be -1 if this cell is not in an endgroup
                                                       APIF void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup)
                                                       {
Coverage_array[1247] = "midiseq.in.c 2107";                if (MEvent_type(cell) == Midiseq_notetype) {
Coverage_array[1248] = "midiseq.in.c 2108";                    int pitch     = MEvent_notePitch(cell);
Coverage_array[1249] = "midiseq.in.c 2109";                    int velocity  = MEvent_noteVelocity(cell);
Coverage_array[1250] = "midiseq.in.c 2110";                    Ticks offtime = MEvent_t(cell) + MEvent_noteDuration(cell);
Coverage_array[1251] = "midiseq.in.c 2111";            
Coverage_array[1252] = "midiseq.in.c 2112";                    if (NoteManager_insertNoteOff(manager, offtime, pitch, padIndexForEndgroup)) {
Coverage_array[1253] = "midiseq.in.c 2113";                        NoteManager_sendNoteOn(manager, pitch, 0);
Coverage_array[1254] = "midiseq.in.c 2114";                    }
Coverage_array[1255] = "midiseq.in.c 2115";                    NoteManager_sendNoteOn(manager, pitch, velocity);
Coverage_array[1256] = "midiseq.in.c 2116";                }
Coverage_array[1257] = "midiseq.in.c 2117";            }


                                                       APIF void NoteManager_padNoteOff(NoteManager *manager, int padIndex)
                                                       {
Coverage_array[1258] = "midiseq.in.c 2122";                IndexedOff_declare(off, padIndex, 0);
Coverage_array[1259] = "midiseq.in.c 2123";                IndexedOffArFIt_declare0(slice);
Coverage_array[1260] = "midiseq.in.c 2124";                slice = IndexedOffAr_binSearchPadIndex(&manager->endgroups, off);
Coverage_array[1261] = "midiseq.in.c 2125";                if (IndexedOffArFIt_atEnd(&slice)) {
Coverage_array[1262] = "midiseq.in.c 2126";                    return;
Coverage_array[1263] = "midiseq.in.c 2127";                }
Coverage_array[1264] = "midiseq.in.c 2128";                IndexedOffAr_loop(slice) {
Coverage_array[1265] = "midiseq.in.c 2129";                    NoteManager_sendNoteOn(manager, slice.var->pitch, 0);
Coverage_array[1266] = "midiseq.in.c 2130";                }
Coverage_array[1267] = "midiseq.in.c 2131";                IndexedOffAr_binRemovePadIndex(&manager->endgroups, off);
Coverage_array[1268] = "midiseq.in.c 2132";                return;
Coverage_array[1269] = "midiseq.in.c 2133";            }

//
// H U B
//

                                                       APIF Hub *Hub_newBuild(PortFind *pf, Error *err) {
Coverage_array[1270] = "midiseq.in.c 2140";                Hub *self = Hub_new();
Coverage_array[1271] = "midiseq.in.c 2141";                Hub_build(self, pf, err);
Coverage_array[1272] = "midiseq.in.c 2142";                if (Error_iserror(err)) {
Coverage_array[1273] = "midiseq.in.c 2143";                    Hub_free(self);
Coverage_array[1274] = "midiseq.in.c 2144";                    return NULL;
Coverage_array[1275] = "midiseq.in.c 2145";                }
Coverage_array[1276] = "midiseq.in.c 2146";                return self;
Coverage_array[1277] = "midiseq.in.c 2147";            }

                                                       APIF void Hub_build(Hub *hub, PortFind *pf, Error *err) {
Coverage_array[1278] = "midiseq.in.c 2150";                Hub_setCurrBankPort(hub, PortFind_findById(pf, Symbol_gen("currBank")));
Coverage_array[1279] = "midiseq.in.c 2151";                Hub_setCurrFramePort(hub, PortFind_findById(pf, Symbol_gen("currFrame")));
Coverage_array[1280] = "midiseq.in.c 2152";                Hub_setSelBankPort(hub, PortFind_findById(pf, Symbol_gen("selBank")));
Coverage_array[1281] = "midiseq.in.c 2153";                Hub_setSelFramePort(hub, PortFind_findById(pf, Symbol_gen("selFrame")));
Coverage_array[1282] = "midiseq.in.c 2154";                Hub_setSelPadPort(hub, PortFind_findById(pf, Symbol_gen("selPad")));
Coverage_array[1283] = "midiseq.in.c 2155";            
Coverage_array[1284] = "midiseq.in.c 2156";                Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
Coverage_array[1285] = "midiseq.in.c 2157";                PortRef_declare(portRef, cg, 0);
Coverage_array[1286] = "midiseq.in.c 2158";                DropDown_buildCGLocalGlobal(Hub_cgLocalGlobalMenu(hub), portRef);
Coverage_array[1287] = "midiseq.in.c 2159";            
Coverage_array[1288] = "midiseq.in.c 2160";                PortRef_set(portRef, cg, 1);
Coverage_array[1289] = "midiseq.in.c 2161";                DropDown_buildCGInstrument(Hub_cgInstrumentMenu(hub), portRef);
Coverage_array[1290] = "midiseq.in.c 2162";            
Coverage_array[1291] = "midiseq.in.c 2163";                PortRef_set(portRef, cg, 2);
Coverage_array[1292] = "midiseq.in.c 2164";                DropDown_buildCGIndex(Hub_cgIndexMenu(hub), portRef);
Coverage_array[1293] = "midiseq.in.c 2165";            
Coverage_array[1294] = "midiseq.in.c 2166";                DropDown_initializeMenu(Hub_cgLocalGlobalMenu(hub), err);
Coverage_array[1295] = "midiseq.in.c 2167";                Error_returnVoidOnError(err);
Coverage_array[1296] = "midiseq.in.c 2168";            
Coverage_array[1297] = "midiseq.in.c 2169";                DropDown_initializeMenu(Hub_cgInstrumentMenu(hub), err);
Coverage_array[1298] = "midiseq.in.c 2170";                Error_returnVoidOnError(err);
Coverage_array[1299] = "midiseq.in.c 2171";            
Coverage_array[1300] = "midiseq.in.c 2172";                DropDown_initializeMenu(Hub_cgIndexMenu(hub), err);
Coverage_array[1301] = "midiseq.in.c 2173";                Error_returnVoidOnError(err);    
Coverage_array[1302] = "midiseq.in.c 2174";            
Coverage_array[1303] = "midiseq.in.c 2175";                Atom a[2] = {Atom_fromSymbol(Symbol_gen("cantchange")), Atom_fromInteger(1)};
Coverage_array[1304] = "midiseq.in.c 2176";                Port_send(Hub_currBankPort(hub), 0, 2, a, err);
Coverage_array[1305] = "midiseq.in.c 2177";                Error_returnVoidOnError(err);
Coverage_array[1306] = "midiseq.in.c 2178";            
Coverage_array[1307] = "midiseq.in.c 2179";                Port_send(Hub_currFramePort(hub), 0, 2, a, err);
Coverage_array[1308] = "midiseq.in.c 2180";                Error_returnVoidOnError(err);
Coverage_array[1309] = "midiseq.in.c 2181";                
Coverage_array[1310] = "midiseq.in.c 2182";                Port_send(Hub_selBankPort(hub), 0, 2, a, err);
Coverage_array[1311] = "midiseq.in.c 2183";                Error_returnVoidOnError(err);
Coverage_array[1312] = "midiseq.in.c 2184";                
Coverage_array[1313] = "midiseq.in.c 2185";                Port_send(Hub_selFramePort(hub), 0, 2, a, err);
Coverage_array[1314] = "midiseq.in.c 2186";                Error_returnVoidOnError(err);
Coverage_array[1315] = "midiseq.in.c 2187";            
Coverage_array[1316] = "midiseq.in.c 2188";                Port_send(Hub_selPadPort(hub), 0, 2, a, err);
Coverage_array[1317] = "midiseq.in.c 2189";                Error_returnVoidOnError(err);
Coverage_array[1318] = "midiseq.in.c 2190";            
Coverage_array[1319] = "midiseq.in.c 2191";                DispatchPtAr_init(&hub->dispatcher, 0);
Coverage_array[1320] = "midiseq.in.c 2192";                DispatchPtAr_populate(&hub->dispatcher, err);
Coverage_array[1321] = "midiseq.in.c 2193";                Error_returnVoidOnError(err);
Coverage_array[1322] = "midiseq.in.c 2194";            }

                                                       APIF void Hub_updateGuiCurrentCoordinates(Hub *hub) 
                                                       {
Coverage_array[1323] = "midiseq.in.c 2198";                Error_declare(err);
Coverage_array[1324] = "midiseq.in.c 2199";                Port_sendInteger(Hub_currBankPort(hub),  0, Hub_bank(hub), err);
Coverage_array[1325] = "midiseq.in.c 2200";                Error_maypost(err);
Coverage_array[1326] = "midiseq.in.c 2201";                Port_sendInteger(Hub_currFramePort(hub), 0, Hub_frame(hub), err);
Coverage_array[1327] = "midiseq.in.c 2202";                Error_maypost(err);
Coverage_array[1328] = "midiseq.in.c 2203";            }

                                                       APIF void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err) {
Coverage_array[1329] = "midiseq.in.c 2206";                Hub_setSelectedPad(hub, selectedPadIndex);
Coverage_array[1330] = "midiseq.in.c 2207";                Pad *pad = PadList_pad(Hub_padList(hub), selectedPadIndex, err);
Coverage_array[1331] = "midiseq.in.c 2208";                Error_returnVoidOnError(err);
Coverage_array[1332] = "midiseq.in.c 2209";            
Coverage_array[1333] = "midiseq.in.c 2210";                // choke group set
Coverage_array[1334] = "midiseq.in.c 2211";                DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), Pad_chokeGroupGlobal(pad) ? 1 : 0, err);
Coverage_array[1335] = "midiseq.in.c 2212";                Error_returnVoidOnError(err);
Coverage_array[1336] = "midiseq.in.c 2213";                DropDown_setSelected(Hub_cgInstrumentMenu(hub), Pad_chokeGroupInstrument(pad), err);
Coverage_array[1337] = "midiseq.in.c 2214";                Error_returnVoidOnError(err);
Coverage_array[1338] = "midiseq.in.c 2215";                DropDown_setSelected(Hub_cgIndexMenu(hub), Pad_chokeGroupIndex(pad), err);
Coverage_array[1339] = "midiseq.in.c 2216";                Error_returnVoidOnError(err);
Coverage_array[1340] = "midiseq.in.c 2217";            
Coverage_array[1341] = "midiseq.in.c 2218";                // Choke Group GUI
Coverage_array[1342] = "midiseq.in.c 2219";                DropDown_updateSelected(Hub_cgLocalGlobalMenu(hub), err);
Coverage_array[1343] = "midiseq.in.c 2220";                Error_returnVoidOnError(err);
Coverage_array[1344] = "midiseq.in.c 2221";                DropDown_updateSelected(Hub_cgInstrumentMenu(hub), err);
Coverage_array[1345] = "midiseq.in.c 2222";                Error_returnVoidOnError(err);
Coverage_array[1346] = "midiseq.in.c 2223";                DropDown_updateSelected(Hub_cgIndexMenu(hub), err);
Coverage_array[1347] = "midiseq.in.c 2224";                Error_returnVoidOnError(err);
Coverage_array[1348] = "midiseq.in.c 2225";            
Coverage_array[1349] = "midiseq.in.c 2226";                // Selected coordinates
Coverage_array[1350] = "midiseq.in.c 2227";                Port_sendInteger(Hub_selBankPort(hub),  0, (long)Hub_selectedBank(hub), err);
Coverage_array[1351] = "midiseq.in.c 2228";                Error_returnVoidOnError(err);
Coverage_array[1352] = "midiseq.in.c 2229";                Port_sendInteger(Hub_selFramePort(hub), 0, (long)Hub_selectedFrame(hub), err);  
Coverage_array[1353] = "midiseq.in.c 2230";                Error_returnVoidOnError(err);
Coverage_array[1354] = "midiseq.in.c 2231";                Port_sendInteger(Hub_selPadPort(hub),   0, (long)Hub_relativeSelectedPad(hub), err);
Coverage_array[1355] = "midiseq.in.c 2232";                Error_returnVoidOnError(err);
Coverage_array[1356] = "midiseq.in.c 2233";            }

                                                       APIF void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv)
                                                       {
Coverage_array[1357] = "midiseq.in.c 2237";            
Coverage_array[1358] = "midiseq.in.c 2238";                Error_declare(err);
Coverage_array[1359] = "midiseq.in.c 2239";            
Coverage_array[1360] = "midiseq.in.c 2240";                Dispatch_declare(cell, Undefined_itype, selector, Port_id(port), 0, NULL);
Coverage_array[1361] = "midiseq.in.c 2241";                Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);
Coverage_array[1362] = "midiseq.in.c 2242";            
Coverage_array[1363] = "midiseq.in.c 2243";                if (dis == NULL) {
Coverage_array[1364] = "midiseq.in.c 2244";                    return;
Coverage_array[1365] = "midiseq.in.c 2245";                }
Coverage_array[1366] = "midiseq.in.c 2246";                
Coverage_array[1367] = "midiseq.in.c 2247";                Marshal *marshal = Dispatch_marshal(*dis);
Coverage_array[1368] = "midiseq.in.c 2248";                if (marshal != NULL) {
Coverage_array[1369] = "midiseq.in.c 2249";                    Marshal_process(marshal, &hub->arguments, argc, argv, err);
Coverage_array[1370] = "midiseq.in.c 2250";                    if (Error_maypost(err)) {
Coverage_array[1371] = "midiseq.in.c 2251";                        return;
Coverage_array[1372] = "midiseq.in.c 2252";                    }
Coverage_array[1373] = "midiseq.in.c 2253";                }
Coverage_array[1374] = "midiseq.in.c 2254";                
Coverage_array[1375] = "midiseq.in.c 2255";                Dispatch_exec(*dis, hub, &hub->arguments, err);
Coverage_array[1376] = "midiseq.in.c 2256";                if (Error_maypost(err)) {
Coverage_array[1377] = "midiseq.in.c 2257";                    return;
Coverage_array[1378] = "midiseq.in.c 2258";                }
Coverage_array[1379] = "midiseq.in.c 2259";                if (marshal != NULL) {
Coverage_array[1380] = "midiseq.in.c 2260";                    Marshal_zeroArgs(marshal, &hub->arguments, err);
Coverage_array[1381] = "midiseq.in.c 2261";                    if (Error_maypost(err)) {
Coverage_array[1382] = "midiseq.in.c 2262";                        return;
Coverage_array[1383] = "midiseq.in.c 2263";                    }
Coverage_array[1384] = "midiseq.in.c 2264";                }
Coverage_array[1385] = "midiseq.in.c 2265";            
Coverage_array[1386] = "midiseq.in.c 2266";                return;
Coverage_array[1387] = "midiseq.in.c 2267";            }



                                                       APIF void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet)
                                                       {
Coverage_array[1388] = "midiseq.in.c 2273";                Error_declare(err);
Coverage_array[1389] = "midiseq.in.c 2274";                Dispatch_declare(cell, Undefined_itype, NULL, Port_id(port), (int)inlet, NULL);
Coverage_array[1390] = "midiseq.in.c 2275";                Dispatch **dis = DispatchPtAr_binSearch(&hub->dispatcher, &cell);
Coverage_array[1391] = "midiseq.in.c 2276";                if (dis == NULL) {
Coverage_array[1392] = "midiseq.in.c 2277";                    return;
Coverage_array[1393] = "midiseq.in.c 2278";                }
Coverage_array[1394] = "midiseq.in.c 2279";            
Coverage_array[1395] = "midiseq.in.c 2280";                Arguments_setIvalue(&hub->arguments, value);
Coverage_array[1396] = "midiseq.in.c 2281";                Arguments_setInlet(&hub->arguments, inlet);
Coverage_array[1397] = "midiseq.in.c 2282";                Dispatch_exec(*dis, hub, &hub->arguments, err);
Coverage_array[1398] = "midiseq.in.c 2283";                if (Error_maypost(err)) {
Coverage_array[1399] = "midiseq.in.c 2284";                    return;
Coverage_array[1400] = "midiseq.in.c 2285";                }
Coverage_array[1401] = "midiseq.in.c 2286";                Arguments_setIvalue(&hub->arguments, 0);
Coverage_array[1402] = "midiseq.in.c 2287";                Arguments_setInlet(&hub->arguments, 0);
Coverage_array[1403] = "midiseq.in.c 2288";            
Coverage_array[1404] = "midiseq.in.c 2289";                /*
Coverage_array[1405] = "midiseq.in.c 2290";                Hub *hub = (Hub*)hub_in;
Coverage_array[1406] = "midiseq.in.c 2291";                int ev = port_parseEvSymbol(Port_id(port));
Coverage_array[1407] = "midiseq.in.c 2292";                if (ev >= 0) {
Coverage_array[1408] = "midiseq.in.c 2293";                    dblog("Ev sent to %d: inlet %ld", ev, inlet);
Coverage_array[1409] = "midiseq.in.c 2294";                } else if (Port_id(port) == Symbol_gen("chokeGroup")) {
Coverage_array[1410] = "midiseq.in.c 2295";                    Error_declare(err);
Coverage_array[1411] = "midiseq.in.c 2296";                    Hub_manageChokeGroups(hub, value, inlet, err);
Coverage_array[1412] = "midiseq.in.c 2297";                    if (Error_maypost(err)) {
Coverage_array[1413] = "midiseq.in.c 2298";                        // Reset pad b/c the drop down is now not consistent with the Pad
Coverage_array[1414] = "midiseq.in.c 2299";                        Hub_changeSelectedPad(hub, Hub_selectedPad(hub), err);
Coverage_array[1415] = "midiseq.in.c 2300";                        Error_maypost(err);
Coverage_array[1416] = "midiseq.in.c 2301";                    }
Coverage_array[1417] = "midiseq.in.c 2302";                }
Coverage_array[1418] = "midiseq.in.c 2303";                */
Coverage_array[1419] = "midiseq.in.c 2304";            }

                                                       APIF void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err) {
Coverage_array[1420] = "midiseq.in.c 2307";                BinFile_writeTag(bf, "hub_start", err);
Coverage_array[1421] = "midiseq.in.c 2308";                Error_returnVoidOnError(err);
Coverage_array[1422] = "midiseq.in.c 2309";            
Coverage_array[1423] = "midiseq.in.c 2310";                PadList_toBinFile(Hub_padList(hub), bf, err);
Coverage_array[1424] = "midiseq.in.c 2311";                Error_returnVoidOnError(err);
Coverage_array[1425] = "midiseq.in.c 2312";            
Coverage_array[1426] = "midiseq.in.c 2313";                TrackList_toBinFile(Hub_trackList(hub), bf, err);
Coverage_array[1427] = "midiseq.in.c 2314";                Error_returnVoidOnError(err);
Coverage_array[1428] = "midiseq.in.c 2315";            
Coverage_array[1429] = "midiseq.in.c 2316";                BinFile_writeTag(bf, "hub_end", err);    
Coverage_array[1430] = "midiseq.in.c 2317";                Error_returnVoidOnError(err);
Coverage_array[1431] = "midiseq.in.c 2318";            }

                                                       APIF Hub *Hub_fromBinFile(BinFile *bf, Error *err) {
Coverage_array[1432] = "midiseq.in.c 2321";                // Hub *hub = Hub_newUninitialized();
Coverage_array[1433] = "midiseq.in.c 2322";                // Hub_fromBinFileUninitialized(hub, bf, err);
Coverage_array[1434] = "midiseq.in.c 2323";                // if (Error_iserror(err)) {
Coverage_array[1435] = "midiseq.in.c 2324";                //     Hub_free(hub);
Coverage_array[1436] = "midiseq.in.c 2325";                //     return NULL;
Coverage_array[1437] = "midiseq.in.c 2326";                // }
Coverage_array[1438] = "midiseq.in.c 2327";                // return hub;
Coverage_array[1439] = "midiseq.in.c 2328";                return NULL;
Coverage_array[1440] = "midiseq.in.c 2329";            }

                                                       APIF void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err) {
Coverage_array[1441] = "midiseq.in.c 2332";                BinFile_verifyTag(bf, "hub_start", err);
Coverage_array[1442] = "midiseq.in.c 2333";                Error_returnVoidOnError(err);
Coverage_array[1443] = "midiseq.in.c 2334";            
Coverage_array[1444] = "midiseq.in.c 2335";                Hub_setPadList(hub, PadList_fromBinFile(bf, err));
Coverage_array[1445] = "midiseq.in.c 2336";                Error_returnVoidOnError(err);
Coverage_array[1446] = "midiseq.in.c 2337";                
Coverage_array[1447] = "midiseq.in.c 2338";                Hub_setTrackList(hub, TrackList_fromBinFile(bf, err));
Coverage_array[1448] = "midiseq.in.c 2339";                Error_returnVoidOnError(err);
Coverage_array[1449] = "midiseq.in.c 2340";            
Coverage_array[1450] = "midiseq.in.c 2341";                BinFile_verifyTag(bf, "hub_end", err);    
Coverage_array[1451] = "midiseq.in.c 2342";                Error_returnVoidOnError(err);
Coverage_array[1452] = "midiseq.in.c 2343";            }


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
Coverage_array[1453] = "midiseq.in.c 2358";                BinFile *bf =  BinFile_new();
Coverage_array[1454] = "midiseq.in.c 2359";                BinFile_setStream(bf, fopen(file, "w"));
Coverage_array[1455] = "midiseq.in.c 2360";                if (BinFile_stream(bf) == NULL) {
Coverage_array[1456] = "midiseq.in.c 2361";                    Error_format(err, "Failed to open file %s", file);
Coverage_array[1457] = "midiseq.in.c 2362";                    BinFile_free(bf);
Coverage_array[1458] = "midiseq.in.c 2363";                    return NULL;
Coverage_array[1459] = "midiseq.in.c 2364";                }
Coverage_array[1460] = "midiseq.in.c 2365";                String_free(bf->filename);
Coverage_array[1461] = "midiseq.in.c 2366";                bf->filename = String_fmt("%s", file);
Coverage_array[1462] = "midiseq.in.c 2367";            
Coverage_array[1463] = "midiseq.in.c 2368";                if (fprintf(BinFile_stream(bf), "%d ", BinFile_version(bf)) < 0) {
Coverage_array[1464] = "midiseq.in.c 2369";                    Error_format(err, "Failed to write version number to file %s", file);
Coverage_array[1465] = "midiseq.in.c 2370";                    BinFile_free(bf);
Coverage_array[1466] = "midiseq.in.c 2371";                    return NULL;
Coverage_array[1467] = "midiseq.in.c 2372";                }
Coverage_array[1468] = "midiseq.in.c 2373";            
Coverage_array[1469] = "midiseq.in.c 2374";                return bf;
Coverage_array[1470] = "midiseq.in.c 2375";            }

                                                       APIF BinFile *BinFile_newReader(const char *file, Error *err) {
Coverage_array[1471] = "midiseq.in.c 2378";                BinFile *bf =  BinFile_new();
Coverage_array[1472] = "midiseq.in.c 2379";                BinFile_setStream(bf, fopen(file, "r"));
Coverage_array[1473] = "midiseq.in.c 2380";                if (BinFile_stream(bf) == NULL) {
Coverage_array[1474] = "midiseq.in.c 2381";                    Error_format(err, "Failed to open file %s", file);
Coverage_array[1475] = "midiseq.in.c 2382";                    BinFile_free(bf);
Coverage_array[1476] = "midiseq.in.c 2383";                    return NULL;
Coverage_array[1477] = "midiseq.in.c 2384";                }
Coverage_array[1478] = "midiseq.in.c 2385";                bf->filename = String_fmt("%s", file);
Coverage_array[1479] = "midiseq.in.c 2386";                if (fscanf(BinFile_stream(bf), "%d ", &bf->version)) {
Coverage_array[1480] = "midiseq.in.c 2387";                    Error_format(err, "Failed to read version number from file  %s", file);
Coverage_array[1481] = "midiseq.in.c 2388";                    BinFile_free(bf);
Coverage_array[1482] = "midiseq.in.c 2389";                    return NULL;
Coverage_array[1483] = "midiseq.in.c 2390";                }
Coverage_array[1484] = "midiseq.in.c 2391";                return bf;
Coverage_array[1485] = "midiseq.in.c 2392";            }

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
Coverage_array[1486] = "midiseq.in.c 2405";                if (BinFile_stream(bf) != NULL) {
Coverage_array[1487] = "midiseq.in.c 2406";                    fclose(BinFile_stream(bf));
Coverage_array[1488] = "midiseq.in.c 2407";                    BinFile_setStream(bf, NULL);
Coverage_array[1489] = "midiseq.in.c 2408";                }
Coverage_array[1490] = "midiseq.in.c 2409";            }


                                                       APIF int binFile_hexDigitToInt(char hex) {
Coverage_array[1491] = "midiseq.in.c 2413";                switch (hex) {
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
Coverage_array[1492] = "midiseq.in.c 2430";                }
Coverage_array[1493] = "midiseq.in.c 2431";                return 0;
Coverage_array[1494] = "midiseq.in.c 2432";            }
                                                       APIF char binFile_intToHexDigit(int digit) {
Coverage_array[1495] = "midiseq.in.c 2434";                switch (digit) {
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
Coverage_array[1496] = "midiseq.in.c 2451";                }
Coverage_array[1497] = "midiseq.in.c 2452";                return 0;
Coverage_array[1498] = "midiseq.in.c 2453";            }

                                                       APIF off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err) {
Coverage_array[1499] = "midiseq.in.c 2456";                errno = 0;
Coverage_array[1500] = "midiseq.in.c 2457";                off_t start = BinFile_tell(bf, err);
Coverage_array[1501] = "midiseq.in.c 2458";                Error_returnZeroOnError(err);
Coverage_array[1502] = "midiseq.in.c 2459";            
Coverage_array[1503] = "midiseq.in.c 2460";                const char *format = ("%" BinFile_nullLengthFieldSizeStr "s ");
Coverage_array[1504] = "midiseq.in.c 2461";                if (fprintf(BinFile_stream(bf), format, "") < 0) {
Coverage_array[1505] = "midiseq.in.c 2462";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1506] = "midiseq.in.c 2463";                    return 0;
Coverage_array[1507] = "midiseq.in.c 2464";                }
Coverage_array[1508] = "midiseq.in.c 2465";                if (spaceForFlags) {
Coverage_array[1509] = "midiseq.in.c 2466";                    if (fprintf(BinFile_stream(bf), "0000 ") < 0) {
Coverage_array[1510] = "midiseq.in.c 2467";                        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1511] = "midiseq.in.c 2468";                        return 0;
Coverage_array[1512] = "midiseq.in.c 2469";                    }
Coverage_array[1513] = "midiseq.in.c 2470";                }
Coverage_array[1514] = "midiseq.in.c 2471";                return start;
Coverage_array[1515] = "midiseq.in.c 2472";            } 

                                                       APIF void BinFile_writeFlags(BinFile *bf, long flags, Error *err) {
Coverage_array[1516] = "midiseq.in.c 2475";                Coverage_off;
                                                           char hex[4] = {
                                                               binFile_intToHexDigit((flags)       & 0xFF),
                                                               binFile_intToHexDigit((flags >> 8)  & 0xFF),
                                                               binFile_intToHexDigit((flags >> 16) & 0xFF),
                                                               binFile_intToHexDigit((flags >> 24) & 0xFF),
                                                           };
                                                           Coverage_on;
Coverage_array[1517] = "midiseq.in.c 2483";                if (fprintf(BinFile_stream(bf), "%c%c%c%c ", hex[0], hex[1], hex[2], hex[3]) < 0) {
Coverage_array[1518] = "midiseq.in.c 2484";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1519] = "midiseq.in.c 2485";                    return;
Coverage_array[1520] = "midiseq.in.c 2486";                }
Coverage_array[1521] = "midiseq.in.c 2487";            }

                                                       APIF void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err) {
Coverage_array[1522] = "midiseq.in.c 2490";                off_t end = BinFile_tell(bf, err);
Coverage_array[1523] = "midiseq.in.c 2491";                Error_returnVoidOnError(err);
Coverage_array[1524] = "midiseq.in.c 2492";            
Coverage_array[1525] = "midiseq.in.c 2493";                long length = (long)(end-location);
Coverage_array[1526] = "midiseq.in.c 2494";                if (length > BinFile_maxLength) {
Coverage_array[1527] = "midiseq.in.c 2495";                    Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
Coverage_array[1528] = "midiseq.in.c 2496";                    return;
Coverage_array[1529] = "midiseq.in.c 2497";                }
Coverage_array[1530] = "midiseq.in.c 2498";                if (fseeko(BinFile_stream(bf), location, SEEK_SET) != 0){
Coverage_array[1531] = "midiseq.in.c 2499";                    Error_format(err, "Failed fseeko[1] while writing %s", BinFile_filename(bf));
Coverage_array[1532] = "midiseq.in.c 2500";                    return;
Coverage_array[1533] = "midiseq.in.c 2501";                }
Coverage_array[1534] = "midiseq.in.c 2502";            
Coverage_array[1535] = "midiseq.in.c 2503";                if (flags >= 0) {
Coverage_array[1536] = "midiseq.in.c 2504";                    length = -length;
Coverage_array[1537] = "midiseq.in.c 2505";                }
Coverage_array[1538] = "midiseq.in.c 2506";            
Coverage_array[1539] = "midiseq.in.c 2507";                const char *format = ("%" BinFile_nullLengthFieldSizeStr "ld ");
Coverage_array[1540] = "midiseq.in.c 2508";                if (fprintf(BinFile_stream(bf), format, length) < 0) {
Coverage_array[1541] = "midiseq.in.c 2509";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1542] = "midiseq.in.c 2510";                    return;
Coverage_array[1543] = "midiseq.in.c 2511";                }
Coverage_array[1544] = "midiseq.in.c 2512";            
Coverage_array[1545] = "midiseq.in.c 2513";                if (flags >= 0) {
Coverage_array[1546] = "midiseq.in.c 2514";                    BinFile_writeFlags(bf, flags, err);
Coverage_array[1547] = "midiseq.in.c 2515";                }
Coverage_array[1548] = "midiseq.in.c 2516";            
Coverage_array[1549] = "midiseq.in.c 2517";                if (fseeko(BinFile_stream(bf), end, SEEK_SET) != 0){
Coverage_array[1550] = "midiseq.in.c 2518";                    Error_format(err, "Failed fseeko[2] while writing %s", BinFile_filename(bf));
Coverage_array[1551] = "midiseq.in.c 2519";                    return;
Coverage_array[1552] = "midiseq.in.c 2520";                }
Coverage_array[1553] = "midiseq.in.c 2521";                
Coverage_array[1554] = "midiseq.in.c 2522";                return;
Coverage_array[1555] = "midiseq.in.c 2523";            }

                                                       APIF void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err) {
Coverage_array[1556] = "midiseq.in.c 2526";                if (length > BinFile_maxLength) {
Coverage_array[1557] = "midiseq.in.c 2527";                    Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
Coverage_array[1558] = "midiseq.in.c 2528";                    return;
Coverage_array[1559] = "midiseq.in.c 2529";                }
Coverage_array[1560] = "midiseq.in.c 2530";                if (flags >= 0) {
Coverage_array[1561] = "midiseq.in.c 2531";                    length = -length;
Coverage_array[1562] = "midiseq.in.c 2532";                }
Coverage_array[1563] = "midiseq.in.c 2533";                if (fprintf(BinFile_stream(bf), "%ld ", length) < 0) {
Coverage_array[1564] = "midiseq.in.c 2534";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1565] = "midiseq.in.c 2535";                    return;
Coverage_array[1566] = "midiseq.in.c 2536";                }
Coverage_array[1567] = "midiseq.in.c 2537";                if (flags >= 0) {
Coverage_array[1568] = "midiseq.in.c 2538";                    BinFile_writeFlags(bf, flags, err);
Coverage_array[1569] = "midiseq.in.c 2539";                }
Coverage_array[1570] = "midiseq.in.c 2540";            
Coverage_array[1571] = "midiseq.in.c 2541";            }

                                                       APIF long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err) {
Coverage_array[1572] = "midiseq.in.c 2544";                long length;
Coverage_array[1573] = "midiseq.in.c 2545";                char space;
Coverage_array[1574] = "midiseq.in.c 2546";                if (fscanf(BinFile_stream(bf), " %ld%c", &length, &space) != 2 || space != ' ') {
Coverage_array[1575] = "midiseq.in.c 2547";                    Error_format(err, "Failed sscanf[1] while reading %s", BinFile_filename(bf));
Coverage_array[1576] = "midiseq.in.c 2548";                    return 0;   
Coverage_array[1577] = "midiseq.in.c 2549";                }
Coverage_array[1578] = "midiseq.in.c 2550";                if (length < 0) {
Coverage_array[1579] = "midiseq.in.c 2551";                    length = -length;
Coverage_array[1580] = "midiseq.in.c 2552";                    char f[4] = "\0\0\0\0";
Coverage_array[1581] = "midiseq.in.c 2553";                    if (fscanf(BinFile_stream(bf), "%c%c%c%c%c", f+0, f+1, f+2, f+3, &space) != 5 || space != ' ') {
Coverage_array[1582] = "midiseq.in.c 2554";                        Error_format(err, "Failed sscanf[2] while reading %s", BinFile_filename(bf));
Coverage_array[1583] = "midiseq.in.c 2555";                        return 0;   
Coverage_array[1584] = "midiseq.in.c 2556";                    }   
Coverage_array[1585] = "midiseq.in.c 2557";                    if (flags != NULL) {
Coverage_array[1586] = "midiseq.in.c 2558";                        *flags = 0;
Coverage_array[1587] = "midiseq.in.c 2559";                        for (int i = 0; i < 4; i++) {
Coverage_array[1588] = "midiseq.in.c 2560";                            int v = binFile_hexDigitToInt(f[i]) << i*8;
Coverage_array[1589] = "midiseq.in.c 2561";                            *flags = *flags | v;
Coverage_array[1590] = "midiseq.in.c 2562";                        }
Coverage_array[1591] = "midiseq.in.c 2563";                    }
Coverage_array[1592] = "midiseq.in.c 2564";                }
Coverage_array[1593] = "midiseq.in.c 2565";                return length;
Coverage_array[1594] = "midiseq.in.c 2566";            }

                                                       APIF off_t BinFile_tell(BinFile *bf, Error *err) {
Coverage_array[1595] = "midiseq.in.c 2569";                errno = 0;
Coverage_array[1596] = "midiseq.in.c 2570";                off_t location = ftello(BinFile_stream(bf));
Coverage_array[1597] = "midiseq.in.c 2571";                if (errno != 0) {
Coverage_array[1598] = "midiseq.in.c 2572";                    Error_format(err, "Failed ftello while working with %s", BinFile_filename(bf));
Coverage_array[1599] = "midiseq.in.c 2573";                    return 0;
Coverage_array[1600] = "midiseq.in.c 2574";                }
Coverage_array[1601] = "midiseq.in.c 2575";                return location;
Coverage_array[1602] = "midiseq.in.c 2576";            }

                                                       APIF void BinFile_fillBuffer(BinFile *bf, long size, Error *err) {
Coverage_array[1603] = "midiseq.in.c 2579";                // Want buffer to contain size+1 characters INCLUDING the null byte
Coverage_array[1604] = "midiseq.in.c 2580";                if (String_len(bf->buffer) < size) {
Coverage_array[1605] = "midiseq.in.c 2581";                    // NOTE: I verified that this call DOES NOT shrink the buffer.
Coverage_array[1606] = "midiseq.in.c 2582";                    // NOTE: sdsMakeRoomFor always allocates sdslen()+1 bytes  
Coverage_array[1607] = "midiseq.in.c 2583";                    String_resize(&bf->buffer, size);
Coverage_array[1608] = "midiseq.in.c 2584";                }
Coverage_array[1609] = "midiseq.in.c 2585";                
Coverage_array[1610] = "midiseq.in.c 2586";                if (fread((char*)bf->buffer, size, 1, BinFile_stream(bf)) != size) {
Coverage_array[1611] = "midiseq.in.c 2587";                    Error_format(err, "Failed fread while working with %s", BinFile_filename(bf));
Coverage_array[1612] = "midiseq.in.c 2588";                    return;   
Coverage_array[1613] = "midiseq.in.c 2589";                }
Coverage_array[1614] = "midiseq.in.c 2590";                // NOTE: this means that the buffer can be used like a string in the correct context. IT DOES NOT say that there aren't
Coverage_array[1615] = "midiseq.in.c 2591";                // other nulls embedded in the string. I think that the way I'm preparing this string, there might be 2 nulls at the end
Coverage_array[1616] = "midiseq.in.c 2592";                // of it. 
Coverage_array[1617] = "midiseq.in.c 2593";                char *p = (char*)bf->buffer;
Coverage_array[1618] = "midiseq.in.c 2594";                p[size] = '\0';
Coverage_array[1619] = "midiseq.in.c 2595";            }

                                                       APIF void BinFile_writeInteger(BinFile *bf, long value, Error *err) {
Coverage_array[1620] = "midiseq.in.c 2598";                // XXX: BORKEN
Coverage_array[1621] = "midiseq.in.c 2599";                // sdsclear(BinFile_buffer(bf));
Coverage_array[1622] = "midiseq.in.c 2600";                // sdscatprintf(BinFile_buffer(bf), "%ld", value);
Coverage_array[1623] = "midiseq.in.c 2601";                
Coverage_array[1624] = "midiseq.in.c 2602";            
Coverage_array[1625] = "midiseq.in.c 2603";            
Coverage_array[1626] = "midiseq.in.c 2604";                BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
Coverage_array[1627] = "midiseq.in.c 2605";                Error_returnVoidOnError(err);
Coverage_array[1628] = "midiseq.in.c 2606";            
Coverage_array[1629] = "midiseq.in.c 2607";                if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 0, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
Coverage_array[1630] = "midiseq.in.c 2608";                    Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
Coverage_array[1631] = "midiseq.in.c 2609";                    return;
Coverage_array[1632] = "midiseq.in.c 2610";                }
Coverage_array[1633] = "midiseq.in.c 2611";            }

                                                       APIF long BinFile_readInteger(BinFile *bf, Error *err) {
Coverage_array[1634] = "midiseq.in.c 2614";                long length = BinFile_readLength(bf, err);
Coverage_array[1635] = "midiseq.in.c 2615";                Error_returnZeroOnError(err);
Coverage_array[1636] = "midiseq.in.c 2616";                
Coverage_array[1637] = "midiseq.in.c 2617";                BinFile_fillBuffer(bf, length, err);
Coverage_array[1638] = "midiseq.in.c 2618";                Error_returnZeroOnError(err);
Coverage_array[1639] = "midiseq.in.c 2619";                
Coverage_array[1640] = "midiseq.in.c 2620";                long value = 0;
Coverage_array[1641] = "midiseq.in.c 2621";                if (sscanf(BinFile_buffer(bf), "%ld", &value) != 1) {
Coverage_array[1642] = "midiseq.in.c 2622";                    Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
Coverage_array[1643] = "midiseq.in.c 2623";                    return 0;
Coverage_array[1644] = "midiseq.in.c 2624";                }
Coverage_array[1645] = "midiseq.in.c 2625";                return value;
Coverage_array[1646] = "midiseq.in.c 2626";            }

                                                       APIF void BinFile_writeString(BinFile *bf, String *value, Error *err) {
Coverage_array[1647] = "midiseq.in.c 2629";                BinFile_writeLength(bf, String_len(value), err);
Coverage_array[1648] = "midiseq.in.c 2630";                Error_returnVoidOnError(err);
Coverage_array[1649] = "midiseq.in.c 2631";            
Coverage_array[1650] = "midiseq.in.c 2632";                if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
Coverage_array[1651] = "midiseq.in.c 2633";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1652] = "midiseq.in.c 2634";                    return;
Coverage_array[1653] = "midiseq.in.c 2635";                }
Coverage_array[1654] = "midiseq.in.c 2636";            
Coverage_array[1655] = "midiseq.in.c 2637";            }

// must call sdsfree on any non-NULL return value
                                                       APIF String *BinFile_readString(BinFile *bf, Error *err) {
Coverage_array[1656] = "midiseq.in.c 2641";                uint32_t length = BinFile_readLength(bf, err);
Coverage_array[1657] = "midiseq.in.c 2642";                Error_returnNullOnError(err);
Coverage_array[1658] = "midiseq.in.c 2643";            
Coverage_array[1659] = "midiseq.in.c 2644";                BinFile_fillBuffer(bf, length, err);
Coverage_array[1660] = "midiseq.in.c 2645";                Error_returnNullOnError(err);    
Coverage_array[1661] = "midiseq.in.c 2646";                
Coverage_array[1662] = "midiseq.in.c 2647";                return String_dup(BinFile_buffer(bf));
Coverage_array[1663] = "midiseq.in.c 2648";            }

                                                       APIF void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err) {
Coverage_array[1664] = "midiseq.in.c 2651";                BinFile_writeString(bf, Symbol_cstr(value), err);
Coverage_array[1665] = "midiseq.in.c 2652";                return;
Coverage_array[1666] = "midiseq.in.c 2653";            }

                                                       APIF Symbol *BinFile_readSymbol(BinFile *bf, Error *err) {
Coverage_array[1667] = "midiseq.in.c 2656";                long length = BinFile_readLength(bf, err);
Coverage_array[1668] = "midiseq.in.c 2657";                Error_returnNullOnError(err);
Coverage_array[1669] = "midiseq.in.c 2658";            
Coverage_array[1670] = "midiseq.in.c 2659";                BinFile_fillBuffer(bf, length, err);
Coverage_array[1671] = "midiseq.in.c 2660";                Error_returnNullOnError(err);
Coverage_array[1672] = "midiseq.in.c 2661";                
Coverage_array[1673] = "midiseq.in.c 2662";                return Symbol_gen(BinFile_buffer(bf));
Coverage_array[1674] = "midiseq.in.c 2663";            }

                                                       APIF void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err) {
Coverage_array[1675] = "midiseq.in.c 2666";                // XXX: BORKEN
Coverage_array[1676] = "midiseq.in.c 2667";                // sdsclear(BinFile_buffer(bf));
Coverage_array[1677] = "midiseq.in.c 2668";                // sdscatprintf(BinFile_buffer(bf), "%lld", value);
Coverage_array[1678] = "midiseq.in.c 2669";            
Coverage_array[1679] = "midiseq.in.c 2670";                BinFile_writeLength(bf, String_len(BinFile_buffer(bf)), err);
Coverage_array[1680] = "midiseq.in.c 2671";                Error_returnVoidOnError(err);
Coverage_array[1681] = "midiseq.in.c 2672";            
Coverage_array[1682] = "midiseq.in.c 2673";                if (fwrite(BinFile_buffer(bf), String_len(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != String_len(BinFile_buffer(bf))) {
Coverage_array[1683] = "midiseq.in.c 2674";                    Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
Coverage_array[1684] = "midiseq.in.c 2675";                    return;
Coverage_array[1685] = "midiseq.in.c 2676";                }
Coverage_array[1686] = "midiseq.in.c 2677";            }

                                                       APIF Ticks BinFile_readTicks(BinFile *bf, Error *err) {
Coverage_array[1687] = "midiseq.in.c 2680";                uint32_t length = BinFile_readLength(bf, err);
Coverage_array[1688] = "midiseq.in.c 2681";                Error_returnZeroOnError(err);
Coverage_array[1689] = "midiseq.in.c 2682";                
Coverage_array[1690] = "midiseq.in.c 2683";                BinFile_fillBuffer(bf, length, err);
Coverage_array[1691] = "midiseq.in.c 2684";                Error_returnZeroOnError(err);
Coverage_array[1692] = "midiseq.in.c 2685";                
Coverage_array[1693] = "midiseq.in.c 2686";                Ticks value = 0;
Coverage_array[1694] = "midiseq.in.c 2687";                if (sscanf(BinFile_buffer(bf), "%lld", &value) != 1) {
Coverage_array[1695] = "midiseq.in.c 2688";                    Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
Coverage_array[1696] = "midiseq.in.c 2689";                    return 0;
Coverage_array[1697] = "midiseq.in.c 2690";                }
Coverage_array[1698] = "midiseq.in.c 2691";                return value;
Coverage_array[1699] = "midiseq.in.c 2692";            }

                                                       APIF void BinFile_writeBool(BinFile *bf, bool value, Error *err) {
Coverage_array[1700] = "midiseq.in.c 2695";                BinFile_writeInteger(bf, value ? 1 : 0, err);
Coverage_array[1701] = "midiseq.in.c 2696";            }

                                                       APIF bool BinFile_readBool(BinFile *bf, Error *err) {
Coverage_array[1702] = "midiseq.in.c 2699";                return BinFile_readInteger(bf, err) ? true : false;
Coverage_array[1703] = "midiseq.in.c 2700";            }

                                                       APIF void BinFile_writeTag(BinFile *bf, const char *tag, Error *err) {
Coverage_array[1704] = "midiseq.in.c 2703";                int len = strlen(tag);
Coverage_array[1705] = "midiseq.in.c 2704";                BinFile_writeLengthFlags(bf, len, BinFileFlag_tag, err);
Coverage_array[1706] = "midiseq.in.c 2705";                Error_returnVoidOnError(err);
Coverage_array[1707] = "midiseq.in.c 2706";            
Coverage_array[1708] = "midiseq.in.c 2707";                if (fwrite(tag, len, 1, BinFile_stream(bf)) != len) {
Coverage_array[1709] = "midiseq.in.c 2708";                    Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
Coverage_array[1710] = "midiseq.in.c 2709";                    return;
Coverage_array[1711] = "midiseq.in.c 2710";                }
Coverage_array[1712] = "midiseq.in.c 2711";            }

                                                       APIF void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err) {
Coverage_array[1713] = "midiseq.in.c 2714";                long flags  = 0;
Coverage_array[1714] = "midiseq.in.c 2715";                long length = BinFile_readLengthFlags(bf, &flags, err);
Coverage_array[1715] = "midiseq.in.c 2716";                Error_returnVoidOnError(err);
Coverage_array[1716] = "midiseq.in.c 2717";                if (flags & BinFileFlag_tag) {
Coverage_array[1717] = "midiseq.in.c 2718";                    Error_format0(err, "Expected flag marked with BinFileFlag_tag");
Coverage_array[1718] = "midiseq.in.c 2719";                    return;
Coverage_array[1719] = "midiseq.in.c 2720";                }
Coverage_array[1720] = "midiseq.in.c 2721";                BinFile_fillBuffer(bf, length, err);
Coverage_array[1721] = "midiseq.in.c 2722";                if (strcmp(tag, BinFile_buffer(bf)) != 0) {
Coverage_array[1722] = "midiseq.in.c 2723";                    Error_format(err, "Expected tag '%s', but found '%s'", tag, BinFile_buffer(bf));
Coverage_array[1723] = "midiseq.in.c 2724";                    return;
Coverage_array[1724] = "midiseq.in.c 2725";                }
Coverage_array[1725] = "midiseq.in.c 2726";                return;
Coverage_array[1726] = "midiseq.in.c 2727";            }





#line 1 "src/sequence.in.c"

#line 17 "src/sequence.in.c"

#define MusicalContext_declareDefault(name) MusicalContext name = {.ticksPerQuarterNote = 480, .quarterNotesPerMeasure = 4}

#line 36 "src/sequence.in.c"

// This is the decimal representation of binary 10010000
#define NOTEON_COMMAND 144


                                                       APIF void NoteOutlet_sendNote(NoteOutlet *self, uint8_t pitch, uint8_t velocity)
                                                       {
#                                                         ifdef TEST_BUILD
Coverage_array[1727] = "sequence.in.c 44";                 // printf("OUTLET pitch=%d velocity=%d\n", pitch, velocity);
Coverage_array[1728] = "sequence.in.c 45";                 NoteOutlet_dbRecordEvent(pitch, velocity);
#                                                         endif
Coverage_array[1729] = "sequence.in.c 47";             
Coverage_array[1730] = "sequence.in.c 48";                 AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1731] = "sequence.in.c 49";                 Atom *av = self->atoms.data;
Coverage_array[1732] = "sequence.in.c 50";                 av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
Coverage_array[1733] = "sequence.in.c 51";                 av[1] = Atom_fromInteger(NOTEON_COMMAND);
Coverage_array[1734] = "sequence.in.c 52";                 av[2] = Atom_fromInteger(pitch);
Coverage_array[1735] = "sequence.in.c 53";                 av[3] = Atom_fromInteger(velocity);
Coverage_array[1736] = "sequence.in.c 54";                 Error_declare(err);
Coverage_array[1737] = "sequence.in.c 55";                 Port_send(self->port, 0, 4, av, err);
Coverage_array[1738] = "sequence.in.c 56";                 Error_maypost(err);
Coverage_array[1739] = "sequence.in.c 57";             }

                                                       APIF NoteOutlet *NoteOutlet_newBuild(Port *port)
                                                       {
Coverage_array[1740] = "sequence.in.c 61";                 NoteOutlet *self = NoteOutlet_new();
Coverage_array[1741] = "sequence.in.c 62";                 self->port       = port;
Coverage_array[1742] = "sequence.in.c 63";                 AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1743] = "sequence.in.c 64";                 return self;
Coverage_array[1744] = "sequence.in.c 65";             }

#line 87 "src/sequence.in.c"

#ifdef TEST_BUILD
FloatEventAr *CcOutlet_dbSent = NULL;
                                                       APIF void CcOutlet_dbRewindSent() 
                                                       {
Coverage_array[1745] = "sequence.in.c 92";                 if (CcOutlet_dbSent != NULL) {
Coverage_array[1746] = "sequence.in.c 93";                     FloatEventAr_truncate(CcOutlet_dbSent);    
Coverage_array[1747] = "sequence.in.c 94";                 }
Coverage_array[1748] = "sequence.in.c 95";             }
#endif

// This is a decimal version of the binary number 10110000
#define CC_COMMAND 176
                                                       APIF void CcOutlet_sendFloat(CcOutlet *self, double value) 
                                                       {
#                                                         ifdef TEST_BUILD
Coverage_array[1749] = "sequence.in.c 103";                if (CcOutlet_dbSent == NULL) {
Coverage_array[1750] = "sequence.in.c 104";                    CcOutlet_dbSent = FloatEventAr_new(0);
Coverage_array[1751] = "sequence.in.c 105";                }
Coverage_array[1752] = "sequence.in.c 106";                FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
Coverage_array[1753] = "sequence.in.c 107";                FloatEventAr_push(CcOutlet_dbSent, e);
#                                                         else
Coverage_array[1754] = "sequence.in.c 109";                int v = (int)value;
Coverage_array[1755] = "sequence.in.c 110";                AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1756] = "sequence.in.c 111";                Atom *av = self->atoms.data;
Coverage_array[1757] = "sequence.in.c 112";                av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
Coverage_array[1758] = "sequence.in.c 113";                av[1] = Atom_fromInteger(CC_COMMAND);
Coverage_array[1759] = "sequence.in.c 114";                av[2] = Atom_fromInteger(self->cc);
Coverage_array[1760] = "sequence.in.c 115";                av[3] = Atom_fromInteger(v);
Coverage_array[1761] = "sequence.in.c 116";                Error_declare(err);
Coverage_array[1762] = "sequence.in.c 117";                Port_send(self->port, 0, 4, av, err);
Coverage_array[1763] = "sequence.in.c 118";                Error_maypost(err);   
#                                                         endif
Coverage_array[1764] = "sequence.in.c 120";            }

                                                       APIF CcOutlet *CcOutlet_newBuild(Port *port, int cc)
                                                       {
Coverage_array[1765] = "sequence.in.c 124";                CcOutlet *self = CcOutlet_new();
Coverage_array[1766] = "sequence.in.c 125";                self->port = port;
Coverage_array[1767] = "sequence.in.c 126";                self->cc   = cc;
Coverage_array[1768] = "sequence.in.c 127";                AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1769] = "sequence.in.c 128";                return self;
Coverage_array[1770] = "sequence.in.c 129";            }

#line 147 "src/sequence.in.c"

#ifdef TEST_BUILD
FloatEventAr *BendOutlet_dbSent = NULL;
                                                       APIF void BendOutlet_dbRewindSent() 
                                                       {
Coverage_array[1771] = "sequence.in.c 152";                if (BendOutlet_dbSent != NULL) {
Coverage_array[1772] = "sequence.in.c 153";                    FloatEventAr_truncate(BendOutlet_dbSent);    
Coverage_array[1773] = "sequence.in.c 154";                }
Coverage_array[1774] = "sequence.in.c 155";            }
#endif

#define BEND_COMMAND 224
                                                       APIF void BendOutlet_sendFloat(BendOutlet *self, double value)
                                                       {
#                                                         ifdef TEST_BUILD
Coverage_array[1775] = "sequence.in.c 162";                if (BendOutlet_dbSent == NULL) {
Coverage_array[1776] = "sequence.in.c 163";                    BendOutlet_dbSent = FloatEventAr_new(0);
Coverage_array[1777] = "sequence.in.c 164";                }
Coverage_array[1778] = "sequence.in.c 165";                FloatEvent e = {.stime = Ticks_dbCurrent, .value = value};
Coverage_array[1779] = "sequence.in.c 166";                FloatEventAr_push(BendOutlet_dbSent, e);
#                                                         else
Coverage_array[1780] = "sequence.in.c 168";                int v = (int)value;
Coverage_array[1781] = "sequence.in.c 169";                int lsb = v & 0x7F;
Coverage_array[1782] = "sequence.in.c 170";                int msb = (v >> 7) & 0x7F;
Coverage_array[1783] = "sequence.in.c 171";                AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1784] = "sequence.in.c 172";                Atom *av = self->atoms.data;
Coverage_array[1785] = "sequence.in.c 173";                av[0] = Atom_fromSymbol(Symbol_gen("midievent"));
Coverage_array[1786] = "sequence.in.c 174";                av[1] = Atom_fromInteger(BEND_COMMAND);
Coverage_array[1787] = "sequence.in.c 175";                av[2] = Atom_fromInteger(msb);
Coverage_array[1788] = "sequence.in.c 176";                av[3] = Atom_fromInteger(lsb);
Coverage_array[1789] = "sequence.in.c 177";                Error_declare(err);
Coverage_array[1790] = "sequence.in.c 178";                Port_send(self->port, 0, 4, av, err);
Coverage_array[1791] = "sequence.in.c 179";                Error_maypost(err);   
#                                                         endif
Coverage_array[1792] = "sequence.in.c 181";            }

                                                       APIF BendOutlet *BendOutlet_newBuild(Port *port)
                                                       {
Coverage_array[1793] = "sequence.in.c 185";                BendOutlet *self = BendOutlet_new();
Coverage_array[1794] = "sequence.in.c 186";                self->port = port;
Coverage_array[1795] = "sequence.in.c 187";                AtomAr_changeLength(&self->atoms, 4);
Coverage_array[1796] = "sequence.in.c 188";                return self;
Coverage_array[1797] = "sequence.in.c 189";            }


#line 208 "src/sequence.in.c"

                                                       APIF void VstOutlet_sendFloat(VstOutlet *self, double value)
                                                       {
Coverage_array[1798] = "sequence.in.c 211";            }

#line 225 "src/sequence.in.c"


#line 248 "src/sequence.in.c"

#line 260 "src/sequence.in.c"

                                                       COVER OutletSpecifier OutletSpecifier_makeCC(Symbol *track, int cc) {
Coverage_array[1799] = "sequence.in.c 262";                OutletSpecifier selfValue = {0}, *self = &selfValue;
Coverage_array[1800] = "sequence.in.c 263";                OutletSpecifier_init(self);
Coverage_array[1801] = "sequence.in.c 264";                self->track       = track;
Coverage_array[1802] = "sequence.in.c 265";                self->pluginIndex = 0;
Coverage_array[1803] = "sequence.in.c 266";                self->parameter   = Symbol_gen("*cc");
Coverage_array[1804] = "sequence.in.c 267";                self->paramIndex  = cc;
Coverage_array[1805] = "sequence.in.c 268";                return selfValue;
Coverage_array[1806] = "sequence.in.c 269";            }

                                                       COVER OutletSpecifier OutletSpecifier_makeBend(Symbol *track) {
Coverage_array[1807] = "sequence.in.c 272";                OutletSpecifier selfValue = {0}, *self = &selfValue;
Coverage_array[1808] = "sequence.in.c 273";                OutletSpecifier_init(self);
Coverage_array[1809] = "sequence.in.c 274";                self->track       = track;
Coverage_array[1810] = "sequence.in.c 275";                self->pluginIndex = 0;
Coverage_array[1811] = "sequence.in.c 276";                self->parameter   = Symbol_gen("*bend");
Coverage_array[1812] = "sequence.in.c 277";                self->paramIndex  = 0;
Coverage_array[1813] = "sequence.in.c 278";                return selfValue;
Coverage_array[1814] = "sequence.in.c 279";            }

                                                       COVER OutletSpecifier OutletSpecifier_makeNote(Symbol *track) {
Coverage_array[1815] = "sequence.in.c 282";                OutletSpecifier selfValue = {0}, *self = &selfValue;
Coverage_array[1816] = "sequence.in.c 283";                OutletSpecifier_init(self);
Coverage_array[1817] = "sequence.in.c 284";                self->track       = track;
Coverage_array[1818] = "sequence.in.c 285";                self->pluginIndex = 0;
Coverage_array[1819] = "sequence.in.c 286";                self->parameter   = Symbol_gen("*note");
Coverage_array[1820] = "sequence.in.c 287";                self->paramIndex  = 0;
Coverage_array[1821] = "sequence.in.c 288";                return selfValue;
Coverage_array[1822] = "sequence.in.c 289";            }

                                                       COVER OutletSpecifier OutletSpecifier_makeVst(Symbol *track, int pluginIndex, Symbol *parameter) {
Coverage_array[1823] = "sequence.in.c 292";                OutletSpecifier selfValue = {0}, *self = &selfValue;
Coverage_array[1824] = "sequence.in.c 293";                OutletSpecifier_init(self);
Coverage_array[1825] = "sequence.in.c 294";                self->track       = track;
Coverage_array[1826] = "sequence.in.c 295";                self->pluginIndex = pluginIndex;
Coverage_array[1827] = "sequence.in.c 296";                self->parameter   = parameter;
Coverage_array[1828] = "sequence.in.c 297";                self->paramIndex  = 0;
Coverage_array[1829] = "sequence.in.c 298";                return selfValue;
Coverage_array[1830] = "sequence.in.c 299";            }

                                                       COVER OutletSpecifier OutletSpecifier_makeAudio() {
Coverage_array[1831] = "sequence.in.c 302";                // Every audio sequence sorts equal. So every audio sequence shares the same config for OutletSpecifier
Coverage_array[1832] = "sequence.in.c 303";                OutletSpecifier selfValue = {0}, *self = &selfValue;
Coverage_array[1833] = "sequence.in.c 304";                OutletSpecifier_init(self);
Coverage_array[1834] = "sequence.in.c 305";                self->track       = Symbol_gen("*audio");
Coverage_array[1835] = "sequence.in.c 306";                self->pluginIndex = 0;
Coverage_array[1836] = "sequence.in.c 307";                self->parameter   = Symbol_gen("*audio");
Coverage_array[1837] = "sequence.in.c 308";                self->paramIndex  = 0;
Coverage_array[1838] = "sequence.in.c 309";                return selfValue;
Coverage_array[1839] = "sequence.in.c 310";            }


#line 333 "src/sequence.in.c"

                                                       APIF int Timed_cmp(Timed *left, Timed *right)
                                                       {
Coverage_array[1840] = "sequence.in.c 336";                if (left->time < right->time) {
Coverage_array[1841] = "sequence.in.c 337";                    return -1;
Coverage_array[1842] = "sequence.in.c 338";                } else if (left->time > right->time) {
Coverage_array[1843] = "sequence.in.c 339";                    return 1;
Coverage_array[1844] = "sequence.in.c 340";                }
Coverage_array[1845] = "sequence.in.c 341";                return 0;
Coverage_array[1846] = "sequence.in.c 342";            }

                                                       APIF void TimedPq_enqueue(TimedPq *self, Ticks time, Sequence *s) {
Coverage_array[1847] = "sequence.in.c 345";                Sequence_incVersion(s);
Coverage_array[1848] = "sequence.in.c 346";                Timed cell = {.time = time, .version = Sequence_version(s), .sequence = s};
Coverage_array[1849] = "sequence.in.c 347";                TimedPq_pqPush(self, cell);
Coverage_array[1850] = "sequence.in.c 348";            }

                                                       APIF Sequence *TimedPq_dequeue(TimedPq *self, Ticks current) {
Coverage_array[1851] = "sequence.in.c 351";                Timed *peeked = TimedPq_pqPeek(self);
Coverage_array[1852] = "sequence.in.c 352";            
Coverage_array[1853] = "sequence.in.c 353";                while (peeked != NULL) {
Coverage_array[1854] = "sequence.in.c 354";                    if (Timed_time(peeked) > current) {
Coverage_array[1855] = "sequence.in.c 355";                        break;
Coverage_array[1856] = "sequence.in.c 356";                    } 
Coverage_array[1857] = "sequence.in.c 357";            
Coverage_array[1858] = "sequence.in.c 358";                    Timed timed = {0};
Coverage_array[1859] = "sequence.in.c 359";                    TimedPq_pqPop(self, &timed);
Coverage_array[1860] = "sequence.in.c 360";                    Sequence *seq = Timed_sequence(&timed);
Coverage_array[1861] = "sequence.in.c 361";                    if (seq != NULL && Timed_version(&timed) == Sequence_version(seq)) {
Coverage_array[1862] = "sequence.in.c 362";                        return Timed_sequence(&timed);
Coverage_array[1863] = "sequence.in.c 363";                    }       
Coverage_array[1864] = "sequence.in.c 364";                    peeked = TimedPq_pqPeek(self);
Coverage_array[1865] = "sequence.in.c 365";                }
Coverage_array[1866] = "sequence.in.c 366";            
Coverage_array[1867] = "sequence.in.c 367";                return NULL;
Coverage_array[1868] = "sequence.in.c 368";            }

                                                       APIF void TimedPq_invalidateSequence(TimedPq *self, SequenceAr *removes) 
                                                       {
Coverage_array[1869] = "sequence.in.c 372";                SequenceAr_sortPointer(removes);
Coverage_array[1870] = "sequence.in.c 373";                TimedPq_foreach(it, self) {
Coverage_array[1871] = "sequence.in.c 374";                    Sequence *seq = Timed_sequence(it.var);
Coverage_array[1872] = "sequence.in.c 375";                    if (seq == NULL) {
Coverage_array[1873] = "sequence.in.c 376";                        continue;
Coverage_array[1874] = "sequence.in.c 377";                    }
Coverage_array[1875] = "sequence.in.c 378";                    if (SequenceAr_binSearchPointer(removes, seq) != NULL) {
Coverage_array[1876] = "sequence.in.c 379";                        Timed_setSequence(it.var, NULL);
Coverage_array[1877] = "sequence.in.c 380";                    }
Coverage_array[1878] = "sequence.in.c 381";                }
Coverage_array[1879] = "sequence.in.c 382";            }



#line 408 "src/sequence.in.c"

Ticks NoteSequence_cycleDuration   = -1;
Ticks NoteSequence_endgDuration    = -2;
Ticks NoteSequence_noteOffDuration = -3;

                                                       APIF int NoteEvent_cmp(NoteEvent *left, NoteEvent *right)
                                                       {
Coverage_array[1880] = "sequence.in.c 415";                if (left->stime < right->stime) {
Coverage_array[1881] = "sequence.in.c 416";                    return -1;
Coverage_array[1882] = "sequence.in.c 417";                } else if (left->stime > right->stime) {
Coverage_array[1883] = "sequence.in.c 418";                    return 1;
Coverage_array[1884] = "sequence.in.c 419";                } 
Coverage_array[1885] = "sequence.in.c 420";            
Coverage_array[1886] = "sequence.in.c 421";                // This sorts cycle to the end of equal time, and endgroup to the begining of equal time.
Coverage_array[1887] = "sequence.in.c 422";                Coverage_off;
                                                           Ticks leftDuration = left->duration >= 0 ? left->duration : 
                                                                                left->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                                                                                left->duration == NoteSequence_endgDuration ? -Ticks_maxTime : left->duration;
                                                           Ticks rightDuration = right->duration >= 0 ? right->duration : 
                                                                                 right->duration == NoteSequence_cycleDuration ? Ticks_maxTime :
                                                                                 right->duration == NoteSequence_endgDuration ? -Ticks_maxTime : right->duration;
                                                           Coverage_on;
Coverage_array[1888] = "sequence.in.c 430";                if (leftDuration < rightDuration) {
Coverage_array[1889] = "sequence.in.c 431";                    return -1;
Coverage_array[1890] = "sequence.in.c 432";                } else if (leftDuration > rightDuration) {
Coverage_array[1891] = "sequence.in.c 433";                    return 1;
Coverage_array[1892] = "sequence.in.c 434";                }
Coverage_array[1893] = "sequence.in.c 435";            
Coverage_array[1894] = "sequence.in.c 436";                if (left->pitch < right->pitch) {
Coverage_array[1895] = "sequence.in.c 437";                    return -1;
Coverage_array[1896] = "sequence.in.c 438";                } else if (left->pitch > right->pitch) {
Coverage_array[1897] = "sequence.in.c 439";                    return 1;
Coverage_array[1898] = "sequence.in.c 440";                }
Coverage_array[1899] = "sequence.in.c 441";                return 0;
Coverage_array[1900] = "sequence.in.c 442";            }

#line 506 "src/sequence.in.c"

#define NoteSequence_isMarkerValue(v) (v < 0)
#define Sequence_minSequenceLength 5

                                                       APIF NoteSequence *NoteSequence_newTrack(Symbol *track, PortFind *portFind)
                                                       {
Coverage_array[1901] = "sequence.in.c 512";                // XXX: I don't know if this should be a legal new! 
Coverage_array[1902] = "sequence.in.c 513";                NoteSequence *self    = NoteSequence_new();
Coverage_array[1903] = "sequence.in.c 514";                self->outletSpecifier = OutletSpecifier_makeNote(track);
Coverage_array[1904] = "sequence.in.c 515";                self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
Coverage_array[1905] = "sequence.in.c 516";                return self;
Coverage_array[1906] = "sequence.in.c 517";            }

                                                       APIF NoteSequence *NoteSequence_newFromEvents(Symbol *track, PortFind *portFind, int argc, NoteEvent *argv, Error *err)
                                                       {
Coverage_array[1907] = "sequence.in.c 521";                if (argc <= 0) {
Coverage_array[1908] = "sequence.in.c 522";                    Error_format0(err, "Bad argc passed to newFromEvents");
Coverage_array[1909] = "sequence.in.c 523";                    goto END;
Coverage_array[1910] = "sequence.in.c 524";                }
Coverage_array[1911] = "sequence.in.c 525";            
Coverage_array[1912] = "sequence.in.c 526";                NoteSequence *self = NoteSequence_newTrack(track, portFind);
Coverage_array[1913] = "sequence.in.c 527";                NoteEventAr_truncate(&self->events);
Coverage_array[1914] = "sequence.in.c 528";                for (int i = 0; i < argc; i++) {
Coverage_array[1915] = "sequence.in.c 529";                    NoteEventAr_push(&self->events, argv[i]);
Coverage_array[1916] = "sequence.in.c 530";                }
Coverage_array[1917] = "sequence.in.c 531";                NoteEventAr_sort(&self->events);
Coverage_array[1918] = "sequence.in.c 532";            
Coverage_array[1919] = "sequence.in.c 533";                NoteEvent last = NoteEventAr_get(&self->events, NoteEventAr_last(&self->events), err);
Coverage_array[1920] = "sequence.in.c 534";                Error_returnNullOnError(err);
Coverage_array[1921] = "sequence.in.c 535";            
Coverage_array[1922] = "sequence.in.c 536";                if (last.duration != NoteSequence_cycleDuration) {
Coverage_array[1923] = "sequence.in.c 537";                    Error_format0(err, "Called newFromEvents without proper cycle marker");
Coverage_array[1924] = "sequence.in.c 538";                    goto END;
Coverage_array[1925] = "sequence.in.c 539";                }
Coverage_array[1926] = "sequence.in.c 540";                self->sequenceLength = last.stime;
Coverage_array[1927] = "sequence.in.c 541";                NoteSequence_makeConsistent(self, err);
Coverage_array[1928] = "sequence.in.c 542";            
Coverage_array[1929] = "sequence.in.c 543";              END:
Coverage_array[1930] = "sequence.in.c 544";                if (Error_iserror(err)) {
Coverage_array[1931] = "sequence.in.c 545";                    NoteSequence_free(self);
Coverage_array[1932] = "sequence.in.c 546";                    return NULL;
Coverage_array[1933] = "sequence.in.c 547";                }
Coverage_array[1934] = "sequence.in.c 548";                return self;
Coverage_array[1935] = "sequence.in.c 549";            }

                                                       COVER static inline void NoteSequence_playNoteOffs(NoteSequence *self, Ticks current, Error *err) 
                                                       {
Coverage_array[1936] = "sequence.in.c 553";                self->nextOffEvent = Ticks_maxTime;
Coverage_array[1937] = "sequence.in.c 554";                int nremoves = 0;
Coverage_array[1938] = "sequence.in.c 555";                TimedOffAr_foreach(it, &self->offs) {
Coverage_array[1939] = "sequence.in.c 556";                    if (it.var->time > current) {
Coverage_array[1940] = "sequence.in.c 557";                        self->nextOffEvent = it.var->time;
Coverage_array[1941] = "sequence.in.c 558";                        break;
Coverage_array[1942] = "sequence.in.c 559";                    }
Coverage_array[1943] = "sequence.in.c 560";                    Outlet_sendNote(self->outlet, it.var->pitch, 0, err);
Coverage_array[1944] = "sequence.in.c 561";                    nremoves++;
Coverage_array[1945] = "sequence.in.c 562";                }
Coverage_array[1946] = "sequence.in.c 563";                if (nremoves > 0) {
Coverage_array[1947] = "sequence.in.c 564";                    TimedOffAr_removeN(&self->offs, 0, nremoves, err);
Coverage_array[1948] = "sequence.in.c 565";                    Error_maypost(err);
Coverage_array[1949] = "sequence.in.c 566";                }
Coverage_array[1950] = "sequence.in.c 567";            }

                                                       COVER static inline void NoteSequence_playEvents(NoteSequence *self, Ticks current, Error *err) 
                                                       {
Coverage_array[1951] = "sequence.in.c 571";                self->nextOnEvent = Ticks_maxTime;
Coverage_array[1952] = "sequence.in.c 572";                for (;;) {
Coverage_array[1953] = "sequence.in.c 573";                    NoteEventAr_foreachOffset(it, &self->events, self->cursor) {
Coverage_array[1954] = "sequence.in.c 574";                        NoteEvent *ne = it.var;
Coverage_array[1955] = "sequence.in.c 575";                        if (ne->stime + self->startTime > current) {
Coverage_array[1956] = "sequence.in.c 576";                            self->nextOnEvent = ne->stime + self->startTime;
Coverage_array[1957] = "sequence.in.c 577";                            return;
Coverage_array[1958] = "sequence.in.c 578";                        }
Coverage_array[1959] = "sequence.in.c 579";                        if (!NoteSequence_isMarkerValue(ne->duration)) {
Coverage_array[1960] = "sequence.in.c 580";                            // Queue the note off
Coverage_array[1961] = "sequence.in.c 581";                            TimedOff off = {.time = self->startTime + ne->stime + ne->duration, .pitch = ne->pitch};
Coverage_array[1962] = "sequence.in.c 582";                            TimedOffAr_binInsertTime(&self->offs, off);
Coverage_array[1963] = "sequence.in.c 583";                            if (self->nextOffEvent > off.time) {
Coverage_array[1964] = "sequence.in.c 584";                                self->nextOffEvent = off.time;
Coverage_array[1965] = "sequence.in.c 585";                            }
Coverage_array[1966] = "sequence.in.c 586";            
Coverage_array[1967] = "sequence.in.c 587";                            // Play the note on
Coverage_array[1968] = "sequence.in.c 588";                            Outlet_sendNote(self->outlet, ne->pitch, ne->velocity, err);
Coverage_array[1969] = "sequence.in.c 589";                        } else if (ne->duration == NoteSequence_endgDuration && !self->cycle) {
Coverage_array[1970] = "sequence.in.c 590";                            self->inEndgroup = true;
Coverage_array[1971] = "sequence.in.c 591";                        } 
Coverage_array[1972] = "sequence.in.c 592";            
Coverage_array[1973] = "sequence.in.c 593";                        if (self->recordingSeq != NULL && !NoteSequence_isMarkerValue(ne->duration)) {
Coverage_array[1974] = "sequence.in.c 594";                            NoteEvent e = *ne;
Coverage_array[1975] = "sequence.in.c 595";                            e.stime     = self->recordingSeq->startTime + ne->stime;
Coverage_array[1976] = "sequence.in.c 596";                            NoteEventAr_push(&self->recordingSeq->events, e);
Coverage_array[1977] = "sequence.in.c 597";                        }
Coverage_array[1978] = "sequence.in.c 598";                        self->cursor++;
Coverage_array[1979] = "sequence.in.c 599";                    }
Coverage_array[1980] = "sequence.in.c 600";                    if (self->cycle) {
Coverage_array[1981] = "sequence.in.c 601";                        if (self->sequenceLength <= Sequence_minSequenceLength) {
Coverage_array[1982] = "sequence.in.c 602";                           self->sequenceLength = Sequence_minSequenceLength;
Coverage_array[1983] = "sequence.in.c 603";                        }
Coverage_array[1984] = "sequence.in.c 604";                        self->startTime += self->sequenceLength;
Coverage_array[1985] = "sequence.in.c 605";                        self->cursor     = 0;
Coverage_array[1986] = "sequence.in.c 606";                    } else {
Coverage_array[1987] = "sequence.in.c 607";                        return;
Coverage_array[1988] = "sequence.in.c 608";                    }
Coverage_array[1989] = "sequence.in.c 609";                }
Coverage_array[1990] = "sequence.in.c 610";            }

                                                       COVER static inline Ticks NoteSequence_nextEvent(NoteSequence *self) {
Coverage_array[1991] = "sequence.in.c 613";                bool maxOff = self->nextOffEvent == Ticks_maxTime;
Coverage_array[1992] = "sequence.in.c 614";                bool maxOn  = self->nextOnEvent  == Ticks_maxTime;
Coverage_array[1993] = "sequence.in.c 615";                if (maxOff && maxOn) {
Coverage_array[1994] = "sequence.in.c 616";                    return -1;
Coverage_array[1995] = "sequence.in.c 617";                } else if (maxOff) {
Coverage_array[1996] = "sequence.in.c 618";                    return self->nextOnEvent;
Coverage_array[1997] = "sequence.in.c 619";                } else if (maxOn) {
Coverage_array[1998] = "sequence.in.c 620";                    return self->nextOffEvent;
Coverage_array[1999] = "sequence.in.c 621";                } else {
Coverage_array[2000] = "sequence.in.c 622";                    return self->nextOffEvent < self->nextOnEvent ? self->nextOffEvent : self->nextOnEvent;
Coverage_array[2001] = "sequence.in.c 623";                }
Coverage_array[2002] = "sequence.in.c 624";            }

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
Coverage_array[2003] = "sequence.in.c 640";                int nevents = NoteEventAr_len(&self->events);
Coverage_array[2004] = "sequence.in.c 641";                if (nevents <= 0) {
Coverage_array[2005] = "sequence.in.c 642";                    return;
Coverage_array[2006] = "sequence.in.c 643";                }
Coverage_array[2007] = "sequence.in.c 644";            
Coverage_array[2008] = "sequence.in.c 645";                self->startTime    = self->cycle ? clockStart : current;
Coverage_array[2009] = "sequence.in.c 646";                self->cursor       = 0;
Coverage_array[2010] = "sequence.in.c 647";                self->inEndgroup   = false;
Coverage_array[2011] = "sequence.in.c 648";                Ticks nextEvent    = 0;
Coverage_array[2012] = "sequence.in.c 649";                if (self->cycle) {
Coverage_array[2013] = "sequence.in.c 650";                    if (self->sequenceLength <= Sequence_minSequenceLength) {
Coverage_array[2014] = "sequence.in.c 651";                        self->sequenceLength = Sequence_minSequenceLength;
Coverage_array[2015] = "sequence.in.c 652";                    }
Coverage_array[2016] = "sequence.in.c 653";                    while (current - self->startTime > self->sequenceLength) {
Coverage_array[2017] = "sequence.in.c 654";                        self->startTime += self->sequenceLength;
Coverage_array[2018] = "sequence.in.c 655";                    }
Coverage_array[2019] = "sequence.in.c 656";            
Coverage_array[2020] = "sequence.in.c 657";                    NoteEventAr_foreach(it, &self->events) {
Coverage_array[2021] = "sequence.in.c 658";                        if (it.var->stime + self->startTime >= current) {
Coverage_array[2022] = "sequence.in.c 659";                            nextEvent = it.var->stime + self->startTime;
Coverage_array[2023] = "sequence.in.c 660";                            break;
Coverage_array[2024] = "sequence.in.c 661";                        }
Coverage_array[2025] = "sequence.in.c 662";                        self->cursor++;
Coverage_array[2026] = "sequence.in.c 663";                    }
Coverage_array[2027] = "sequence.in.c 664";                    if (self->cursor >= nevents) {
Coverage_array[2028] = "sequence.in.c 665";                        Error_format0(err, "INTERNAL ERROR: cursor found to be >= nevents");
Coverage_array[2029] = "sequence.in.c 666";                        return;
Coverage_array[2030] = "sequence.in.c 667";                    }
Coverage_array[2031] = "sequence.in.c 668";                } else {
Coverage_array[2032] = "sequence.in.c 669";                    NoteEventAr_foreach(it, &self->events) {
Coverage_array[2033] = "sequence.in.c 670";                        nextEvent = it.var->stime + self->startTime;
Coverage_array[2034] = "sequence.in.c 671";                        break;
Coverage_array[2035] = "sequence.in.c 672";                    }
Coverage_array[2036] = "sequence.in.c 673";                }
Coverage_array[2037] = "sequence.in.c 674";                self->recordingSeq = NULL;
Coverage_array[2038] = "sequence.in.c 675";                if (recordBuffer != NULL) {
Coverage_array[2039] = "sequence.in.c 676";                    NoteSequence *other = NoteSequence_castFromSequence(NoteSequence_compactNew(self, self->startTime));
Coverage_array[2040] = "sequence.in.c 677";                    self->recordingSeq  = other; 
Coverage_array[2041] = "sequence.in.c 678";                    RecordBuffer_push(recordBuffer, NoteSequence_castToSequence(other));
Coverage_array[2042] = "sequence.in.c 679";                }
Coverage_array[2043] = "sequence.in.c 680";                TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
Coverage_array[2044] = "sequence.in.c 681";            }

                                                       APIF void NoteSequence_stop(NoteSequence *self, Ticks current, Error *err) {
Coverage_array[2045] = "sequence.in.c 684";                self->cursor       = NoteEventAr_len(&self->events);
Coverage_array[2046] = "sequence.in.c 685";                self->version++;
Coverage_array[2047] = "sequence.in.c 686";            
Coverage_array[2048] = "sequence.in.c 687";                if (self->recordingSeq != NULL) {
Coverage_array[2049] = "sequence.in.c 688";                    // In the recording sequence Adjust the duration of all the pending note-offs
Coverage_array[2050] = "sequence.in.c 689";                    TimedOffAr_foreach(offIt, &self->offs) {
Coverage_array[2051] = "sequence.in.c 690";                        NoteEventAr_rforeach(noteIt, &self->recordingSeq->events) {
Coverage_array[2052] = "sequence.in.c 691";                            if (noteIt.var->pitch == offIt.var->pitch) {
Coverage_array[2053] = "sequence.in.c 692";                                noteIt.var->duration = current - noteIt.var->stime;
Coverage_array[2054] = "sequence.in.c 693";                                break;
Coverage_array[2055] = "sequence.in.c 694";                            }
Coverage_array[2056] = "sequence.in.c 695";                        }
Coverage_array[2057] = "sequence.in.c 696";                    } 
Coverage_array[2058] = "sequence.in.c 697";                    self->recordingSeq = NULL;
Coverage_array[2059] = "sequence.in.c 698";                }
Coverage_array[2060] = "sequence.in.c 699";                
Coverage_array[2061] = "sequence.in.c 700";                NoteSequence_playNoteOffs(self, Ticks_maxTime, err);
Coverage_array[2062] = "sequence.in.c 701";            }

                                                       APIF void NoteSequence_drive(NoteSequence *self, Ticks current, TimedPq *queue, Error *err) 
                                                       {
Coverage_array[2063] = "sequence.in.c 705";                NoteSequence_playNoteOffs(self, current, err);
Coverage_array[2064] = "sequence.in.c 706";                NoteSequence_playEvents(self, current, err);
Coverage_array[2065] = "sequence.in.c 707";                Ticks nextEvent = NoteSequence_nextEvent(self);
Coverage_array[2066] = "sequence.in.c 708";                if (nextEvent >= 0) {
Coverage_array[2067] = "sequence.in.c 709";                    TimedPq_enqueue(queue, nextEvent, NoteSequence_castToSequence(self));
Coverage_array[2068] = "sequence.in.c 710";                }
Coverage_array[2069] = "sequence.in.c 711";            }

                                                       APIF void NoteSequence_padNoteOff(NoteSequence *self, int padIndex, Ticks current, Error *err) 
                                                       {
Coverage_array[2070] = "sequence.in.c 715";                if (self->inEndgroup && !self->cycle) {
Coverage_array[2071] = "sequence.in.c 716";                    NoteSequence_stop(self, current, err);
Coverage_array[2072] = "sequence.in.c 717";                }
Coverage_array[2073] = "sequence.in.c 718";            }

                                                       APIF void NoteSequence_makeConsistent(NoteSequence *self, Error *err)
                                                       {
Coverage_array[2074] = "sequence.in.c 722";                if (NoteEventAr_len(&self->events) < 1) {
Coverage_array[2075] = "sequence.in.c 723";                    Error_format0(err, "Called makeConsistent on empty sequence");
Coverage_array[2076] = "sequence.in.c 724";                    return;
Coverage_array[2077] = "sequence.in.c 725";                }
Coverage_array[2078] = "sequence.in.c 726";            
Coverage_array[2079] = "sequence.in.c 727";                NoteEventAr_sort(&self->events);
Coverage_array[2080] = "sequence.in.c 728";            
Coverage_array[2081] = "sequence.in.c 729";                NoteEvent last = NoteEventAr_get(&self->events, NoteEventAr_last(&self->events), err);
Coverage_array[2082] = "sequence.in.c 730";                Error_returnVoidOnError(err);
Coverage_array[2083] = "sequence.in.c 731";            
Coverage_array[2084] = "sequence.in.c 732";                if (last.duration != NoteSequence_cycleDuration) {
Coverage_array[2085] = "sequence.in.c 733";                    Error_format0(err, "Called makeConsistent without proper cycle marker");
Coverage_array[2086] = "sequence.in.c 734";                    return;
Coverage_array[2087] = "sequence.in.c 735";                }
Coverage_array[2088] = "sequence.in.c 736";            
Coverage_array[2089] = "sequence.in.c 737";                if (last.stime != self->sequenceLength) {
Coverage_array[2090] = "sequence.in.c 738";                    Error_format0(err, "Called cycle marker and sequenceLength are inconsistent");
Coverage_array[2091] = "sequence.in.c 739";                    return;
Coverage_array[2092] = "sequence.in.c 740";                }
Coverage_array[2093] = "sequence.in.c 741";            
Coverage_array[2094] = "sequence.in.c 742";                int timeNextNoteStart[128] = {0};
Coverage_array[2095] = "sequence.in.c 743";                for (int i = 0; i < 128; i++) {
Coverage_array[2096] = "sequence.in.c 744";                    timeNextNoteStart[i] = INT_MAX;
Coverage_array[2097] = "sequence.in.c 745";                }
Coverage_array[2098] = "sequence.in.c 746";                NoteEventAr_rforeach(it, &self->events) {
Coverage_array[2099] = "sequence.in.c 747";                    if (it.var->stime + it.var->duration > timeNextNoteStart[it.var->pitch]) {
Coverage_array[2100] = "sequence.in.c 748";                        it.var->duration = timeNextNoteStart[it.var->pitch] - it.var->stime;
Coverage_array[2101] = "sequence.in.c 749";                        if (it.var->duration <= 0) {
Coverage_array[2102] = "sequence.in.c 750";                            // This is the case when the same note is played at the same time. Notice we
Coverage_array[2103] = "sequence.in.c 751";                            NoteEventArRIt_remove(&it);
Coverage_array[2104] = "sequence.in.c 752";                            continue;        
Coverage_array[2105] = "sequence.in.c 753";                        }
Coverage_array[2106] = "sequence.in.c 754";                    }
Coverage_array[2107] = "sequence.in.c 755";                    timeNextNoteStart[it.var->pitch] = it.var->stime;
Coverage_array[2108] = "sequence.in.c 756";                }
Coverage_array[2109] = "sequence.in.c 757";                return;
Coverage_array[2110] = "sequence.in.c 758";            }

                                                       APIF Sequence *NoteSequence_compactNew(NoteSequence *self, Ticks recordStart)
                                                       {
Coverage_array[2111] = "sequence.in.c 762";                NoteSequence *other    = NoteSequence_new();
Coverage_array[2112] = "sequence.in.c 763";                // WHen we create a compact sequence, we always set it's startTime to the recordStart which is <= than all the startTimes in the RecordBuffer
Coverage_array[2113] = "sequence.in.c 764";                other->startTime       = recordStart;
Coverage_array[2114] = "sequence.in.c 765";                other->outletSpecifier = self->outletSpecifier;
Coverage_array[2115] = "sequence.in.c 766";                other->outlet          = self->outlet;
Coverage_array[2116] = "sequence.in.c 767";                return NoteSequence_castToSequence(other);
Coverage_array[2117] = "sequence.in.c 768";            }

                                                       APIF void NoteSequence_compactConcat(NoteSequence *self, Sequence *otherSeq, Error *err)
                                                       {
Coverage_array[2118] = "sequence.in.c 772";                NoteSequence *other = NoteSequence_castFromSequence(otherSeq);
Coverage_array[2119] = "sequence.in.c 773";                if (other == NULL) {
Coverage_array[2120] = "sequence.in.c 774";                    Error_format(err, "NoteSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
Coverage_array[2121] = "sequence.in.c 775";                    return;
Coverage_array[2122] = "sequence.in.c 776";                }
Coverage_array[2123] = "sequence.in.c 777";                NoteEventAr_foreach(it, &other->events) {
Coverage_array[2124] = "sequence.in.c 778";                    NoteEvent e = *it.var;
Coverage_array[2125] = "sequence.in.c 779";                    if (NoteSequence_isMarkerValue(e.duration)) {
Coverage_array[2126] = "sequence.in.c 780";                        continue;
Coverage_array[2127] = "sequence.in.c 781";                    }
Coverage_array[2128] = "sequence.in.c 782";                    // Rememver in RecordBuffer_compact we're gauranteed that self->startTime < other->startTime
Coverage_array[2129] = "sequence.in.c 783";                    e.stime += (other->startTime - self->startTime);
Coverage_array[2130] = "sequence.in.c 784";                    NoteEventAr_push(&self->events, e); 
Coverage_array[2131] = "sequence.in.c 785";                }
Coverage_array[2132] = "sequence.in.c 786";            }

                                                       APIF void NoteSequence_compactSortEvents(NoteSequence *self)
                                                       {
Coverage_array[2133] = "sequence.in.c 790";                NoteEventAr_sort(&self->events);
Coverage_array[2134] = "sequence.in.c 791";            }

// Return the time that endgroup should be inserted, or -1 if no endgroup applies.
// Note we return absolute time.
                                                       APIF Ticks NoteSequence_computeEndgroupTime(NoteSequence *self)
                                                       {
Coverage_array[2135] = "sequence.in.c 797";                NoteEventAr_sort(&self->events);
Coverage_array[2136] = "sequence.in.c 798";            
Coverage_array[2137] = "sequence.in.c 799";                // Endgroup is the 
Coverage_array[2138] = "sequence.in.c 800";                Ticks endgroupTime = -1;
Coverage_array[2139] = "sequence.in.c 801";                NoteEventAr_rforeach(it, &self->events) {
Coverage_array[2140] = "sequence.in.c 802";                    if (NoteSequence_isMarkerValue(it.var->duration)) {
Coverage_array[2141] = "sequence.in.c 803";                        continue;
Coverage_array[2142] = "sequence.in.c 804";                    }
Coverage_array[2143] = "sequence.in.c 805";                    endgroupTime = self->startTime + it.var->stime;
Coverage_array[2144] = "sequence.in.c 806";                    break;
Coverage_array[2145] = "sequence.in.c 807";                }
Coverage_array[2146] = "sequence.in.c 808";                return endgroupTime;
Coverage_array[2147] = "sequence.in.c 809";            }

                                                       APIF Ticks NoteSequence_compactComputeSequenceLength(NoteSequence *self)
                                                       {
Coverage_array[2148] = "sequence.in.c 813";                Ticks lastTime = Sequence_minSequenceLength;
Coverage_array[2149] = "sequence.in.c 814";                NoteEventAr_rforeach(it, &self->events) {
Coverage_array[2150] = "sequence.in.c 815";                    if (NoteSequence_isMarkerValue(it.var->duration)) {
Coverage_array[2151] = "sequence.in.c 816";                        continue;
Coverage_array[2152] = "sequence.in.c 817";                    }
Coverage_array[2153] = "sequence.in.c 818";                    Ticks end = it.var->stime + it.var->duration;
Coverage_array[2154] = "sequence.in.c 819";                    if (end > lastTime) {
Coverage_array[2155] = "sequence.in.c 820";                        lastTime = end;
Coverage_array[2156] = "sequence.in.c 821";                    }
Coverage_array[2157] = "sequence.in.c 822";                }
Coverage_array[2158] = "sequence.in.c 823";            
Coverage_array[2159] = "sequence.in.c 824";                MusicalContext_declareDefault(musicalContext);
Coverage_array[2160] = "sequence.in.c 825";                Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
Coverage_array[2161] = "sequence.in.c 826";                Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
Coverage_array[2162] = "sequence.in.c 827";                if (seqLen < Sequence_minSequenceLength) {
Coverage_array[2163] = "sequence.in.c 828";                    seqLen = Sequence_minSequenceLength;
Coverage_array[2164] = "sequence.in.c 829";                }
Coverage_array[2165] = "sequence.in.c 830";                return seqLen;
Coverage_array[2166] = "sequence.in.c 831";            }

                                                       APIF void NoteSequence_compactFinish(NoteSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
                                                       {
Coverage_array[2167] = "sequence.in.c 835";                if (endgroupTime >= 0) {
Coverage_array[2168] = "sequence.in.c 836";                    int index = NoteEventAr_len(&self->events) > 0 ? 0 : -1;
Coverage_array[2169] = "sequence.in.c 837";                    NoteEventAr_rforeach(it, &self->events) {
Coverage_array[2170] = "sequence.in.c 838";                        if (NoteSequence_isMarkerValue(it.var->duration)) {
Coverage_array[2171] = "sequence.in.c 839";                            continue;
Coverage_array[2172] = "sequence.in.c 840";                        }
Coverage_array[2173] = "sequence.in.c 841";                        if (self->startTime + it.var->stime < endgroupTime) {
Coverage_array[2174] = "sequence.in.c 842";                            index = it.index + 1;
Coverage_array[2175] = "sequence.in.c 843";                            break;
Coverage_array[2176] = "sequence.in.c 844";                        }
Coverage_array[2177] = "sequence.in.c 845";                    }
Coverage_array[2178] = "sequence.in.c 846";                    if (index >= 0) {
Coverage_array[2179] = "sequence.in.c 847";                        Error_declare(err);
Coverage_array[2180] = "sequence.in.c 848";                        NoteEvent newEv = {.stime = endgroupTime, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
Coverage_array[2181] = "sequence.in.c 849";                        NoteEventAr_insert(&self->events, index, newEv, err);
Coverage_array[2182] = "sequence.in.c 850";                        Error_maypost(err);
Coverage_array[2183] = "sequence.in.c 851";                    }
Coverage_array[2184] = "sequence.in.c 852";                }
Coverage_array[2185] = "sequence.in.c 853";            
Coverage_array[2186] = "sequence.in.c 854";            
Coverage_array[2187] = "sequence.in.c 855";                self->sequenceLength = sequenceLength;
Coverage_array[2188] = "sequence.in.c 856";                NoteEvent newEv = {.stime = sequenceLength, .duration = NoteSequence_endgDuration, .pitch = 0, .velocity = 0};
Coverage_array[2189] = "sequence.in.c 857";                NoteEventAr_push(&self->events, newEv);
Coverage_array[2190] = "sequence.in.c 858";            
Coverage_array[2191] = "sequence.in.c 859";                NoteSequence_makeConsistent(self, err);
Coverage_array[2192] = "sequence.in.c 860";                return;
Coverage_array[2193] = "sequence.in.c 861";            }

#line 883 "src/sequence.in.c"

                                                       APIF int FloatEvent_cmp(FloatEvent *left, FloatEvent *right)
                                                       {
Coverage_array[2194] = "sequence.in.c 886";                if (left->stime < right->stime) {
Coverage_array[2195] = "sequence.in.c 887";                    return -1;
Coverage_array[2196] = "sequence.in.c 888";                } else if (left->stime > right->stime) {
Coverage_array[2197] = "sequence.in.c 889";                    return 1;
Coverage_array[2198] = "sequence.in.c 890";                }
Coverage_array[2199] = "sequence.in.c 891";                return 0;
Coverage_array[2200] = "sequence.in.c 892";            }

#line 947 "src/sequence.in.c"

                                                       APIF FloatSequence *FloatSequence_newCc(Symbol *track, int cc, PortFind *portFind) 
                                                       {
Coverage_array[2201] = "sequence.in.c 950";                FloatSequence *self   = FloatSequence_new();
Coverage_array[2202] = "sequence.in.c 951";                self->outletSpecifier = OutletSpecifier_makeCC(track, cc);
Coverage_array[2203] = "sequence.in.c 952";                self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
Coverage_array[2204] = "sequence.in.c 953";                return self;
Coverage_array[2205] = "sequence.in.c 954";            }

                                                       APIF FloatSequence *FloatSequence_newBend(Symbol *track, PortFind *portFind) 
                                                       {
Coverage_array[2206] = "sequence.in.c 958";                FloatSequence *self   = FloatSequence_new();
Coverage_array[2207] = "sequence.in.c 959";                self->outletSpecifier = OutletSpecifier_makeBend(track);
Coverage_array[2208] = "sequence.in.c 960";                self->outlet          = PortFind_createOutlet(portFind, &self->outletSpecifier);
Coverage_array[2209] = "sequence.in.c 961";                return self;
Coverage_array[2210] = "sequence.in.c 962";            }

                                                       APIF FloatSequence *FloatSequence_newFromEvents(Symbol *track, int ccOrNegForBend, PortFind *portFind, int argc, FloatEvent *argv) 
                                                       {
Coverage_array[2211] = "sequence.in.c 966";                FloatSequence *self = NULL;
Coverage_array[2212] = "sequence.in.c 967";                if (ccOrNegForBend >= 0) {
Coverage_array[2213] = "sequence.in.c 968";                    self = FloatSequence_newCc(track, ccOrNegForBend, portFind);
Coverage_array[2214] = "sequence.in.c 969";                } else {
Coverage_array[2215] = "sequence.in.c 970";                    self = FloatSequence_newBend(track, portFind);
Coverage_array[2216] = "sequence.in.c 971";                }
Coverage_array[2217] = "sequence.in.c 972";                FloatEventAr_truncate(&self->events);
Coverage_array[2218] = "sequence.in.c 973";                for (int i = 0; i < argc; i++) {
Coverage_array[2219] = "sequence.in.c 974";                    FloatEventAr_push(&self->events, argv[i]);
Coverage_array[2220] = "sequence.in.c 975";                }
Coverage_array[2221] = "sequence.in.c 976";                FloatSequence_makeConsistent(self);
Coverage_array[2222] = "sequence.in.c 977";                return self;
Coverage_array[2223] = "sequence.in.c 978";            }


double FloatSequence_endgMarker  = -1.0e40;
double FloatSequence_cycleMarker = -1.0e41;
#define FloatSequence_isMarkerValue(v) (v < -1.0e10)

                                                       APIF void FloatSequence_start(FloatSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) {
Coverage_array[2224] = "sequence.in.c 986";                int nevents = FloatEventAr_len(&self->events);
Coverage_array[2225] = "sequence.in.c 987";                if (nevents <= 0) {
Coverage_array[2226] = "sequence.in.c 988";                    return;
Coverage_array[2227] = "sequence.in.c 989";                }
Coverage_array[2228] = "sequence.in.c 990";            
Coverage_array[2229] = "sequence.in.c 991";                self->startTime    = self->cycle ? clockStart : current;
Coverage_array[2230] = "sequence.in.c 992";                self->cursor       = 0;
Coverage_array[2231] = "sequence.in.c 993";                self->inEndgroup   = false;
Coverage_array[2232] = "sequence.in.c 994";                Ticks nextEvent    = 0;
Coverage_array[2233] = "sequence.in.c 995";                if (self->cycle) {
Coverage_array[2234] = "sequence.in.c 996";                    if (self->sequenceLength <= Sequence_minSequenceLength) {
Coverage_array[2235] = "sequence.in.c 997";                        self->sequenceLength = Sequence_minSequenceLength;
Coverage_array[2236] = "sequence.in.c 998";                    }
Coverage_array[2237] = "sequence.in.c 999";                    while (current-self->startTime > self->sequenceLength) {
Coverage_array[2238] = "sequence.in.c 1000";                       self->startTime += self->sequenceLength;
Coverage_array[2239] = "sequence.in.c 1001";                   }
Coverage_array[2240] = "sequence.in.c 1002";           
Coverage_array[2241] = "sequence.in.c 1003";                   FloatEventAr_foreach(it, &self->events) {
Coverage_array[2242] = "sequence.in.c 1004";                       if (it.var->stime + self->startTime > current) {
Coverage_array[2243] = "sequence.in.c 1005";                           nextEvent = it.var->stime + self->startTime;
Coverage_array[2244] = "sequence.in.c 1006";                           break;
Coverage_array[2245] = "sequence.in.c 1007";                       }
Coverage_array[2246] = "sequence.in.c 1008";                       self->cursor++;
Coverage_array[2247] = "sequence.in.c 1009";                   }
Coverage_array[2248] = "sequence.in.c 1010";                   if (self->cursor >= nevents) {
Coverage_array[2249] = "sequence.in.c 1011";                       self->startTime += self->sequenceLength;
Coverage_array[2250] = "sequence.in.c 1012";                       nextEvent        = self->startTime;
Coverage_array[2251] = "sequence.in.c 1013";                       self->cursor     = 0;
Coverage_array[2252] = "sequence.in.c 1014";                   }
Coverage_array[2253] = "sequence.in.c 1015";               } else {
Coverage_array[2254] = "sequence.in.c 1016";                   FloatEventAr_foreach(it, &self->events) {
Coverage_array[2255] = "sequence.in.c 1017";                       nextEvent = it.var->stime + self->startTime;
Coverage_array[2256] = "sequence.in.c 1018";                       break;
Coverage_array[2257] = "sequence.in.c 1019";                   }
Coverage_array[2258] = "sequence.in.c 1020";               }
Coverage_array[2259] = "sequence.in.c 1021";           
Coverage_array[2260] = "sequence.in.c 1022";               self->recordingSeq = NULL;
Coverage_array[2261] = "sequence.in.c 1023";               if (recordBuffer != NULL) {
Coverage_array[2262] = "sequence.in.c 1024";                   FloatSequence *other = FloatSequence_castFromSequence(FloatSequence_compactNew(self, self->startTime));        
Coverage_array[2263] = "sequence.in.c 1025";                   self->recordingSeq  = other;    
Coverage_array[2264] = "sequence.in.c 1026";                   RecordBuffer_push(recordBuffer, FloatSequence_castToSequence(other));
Coverage_array[2265] = "sequence.in.c 1027";               }
Coverage_array[2266] = "sequence.in.c 1028";           
Coverage_array[2267] = "sequence.in.c 1029";               TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
Coverage_array[2268] = "sequence.in.c 1030";           }

                                                       APIF void FloatSequence_drive(FloatSequence *self, Ticks current, TimedPq *queue, Error *err) {
Coverage_array[2269] = "sequence.in.c 1033";               Ticks nextEvent = -1;
Coverage_array[2270] = "sequence.in.c 1034";               for (;;) {
Coverage_array[2271] = "sequence.in.c 1035";                   FloatEventAr_foreachOffset(it, &self->events, self->cursor) {
Coverage_array[2272] = "sequence.in.c 1036";                       FloatEvent *fe = it.var;
Coverage_array[2273] = "sequence.in.c 1037";                       if (fe->stime + self->startTime > current) {
Coverage_array[2274] = "sequence.in.c 1038";                           nextEvent = fe->stime + self->startTime;
Coverage_array[2275] = "sequence.in.c 1039";                           goto DONE;
Coverage_array[2276] = "sequence.in.c 1040";                       }
Coverage_array[2277] = "sequence.in.c 1041";                       if (fe->value == FloatSequence_endgMarker) {
Coverage_array[2278] = "sequence.in.c 1042";                           self->inEndgroup = true;
Coverage_array[2279] = "sequence.in.c 1043";                       } else if (fe->value == FloatSequence_cycleMarker) {
Coverage_array[2280] = "sequence.in.c 1044";                           // Do nothing
Coverage_array[2281] = "sequence.in.c 1045";                       } else {
Coverage_array[2282] = "sequence.in.c 1046";                           Outlet_sendFloat(self->outlet, fe->value, err);
Coverage_array[2283] = "sequence.in.c 1047";                       }
Coverage_array[2284] = "sequence.in.c 1048";           
Coverage_array[2285] = "sequence.in.c 1049";                       if (self->recordingSeq != NULL && !FloatSequence_isMarkerValue(fe->value)) {
Coverage_array[2286] = "sequence.in.c 1050";                           FloatEvent e = *fe;
Coverage_array[2287] = "sequence.in.c 1051";                           e.stime      = self->recordingSeq->startTime + fe->stime;
Coverage_array[2288] = "sequence.in.c 1052";                           FloatEventAr_push(&self->recordingSeq->events, e);
Coverage_array[2289] = "sequence.in.c 1053";                       }
Coverage_array[2290] = "sequence.in.c 1054";                       self->cursor++;
Coverage_array[2291] = "sequence.in.c 1055";                   }
Coverage_array[2292] = "sequence.in.c 1056";                   if (self->cycle) {
Coverage_array[2293] = "sequence.in.c 1057";                       if (self->sequenceLength <= Sequence_minSequenceLength) {
Coverage_array[2294] = "sequence.in.c 1058";                           self->sequenceLength = Sequence_minSequenceLength;
Coverage_array[2295] = "sequence.in.c 1059";                       }
Coverage_array[2296] = "sequence.in.c 1060";                       self->startTime += self->sequenceLength;
Coverage_array[2297] = "sequence.in.c 1061";                       self->cursor     = 0;
Coverage_array[2298] = "sequence.in.c 1062";                   } else {
Coverage_array[2299] = "sequence.in.c 1063";                       goto DONE;
Coverage_array[2300] = "sequence.in.c 1064";                   }
Coverage_array[2301] = "sequence.in.c 1065";               }
Coverage_array[2302] = "sequence.in.c 1066";              DONE:
Coverage_array[2303] = "sequence.in.c 1067";               if (nextEvent >= 0) {
Coverage_array[2304] = "sequence.in.c 1068";                   TimedPq_enqueue(queue, nextEvent, FloatSequence_castToSequence(self));
Coverage_array[2305] = "sequence.in.c 1069";               }
Coverage_array[2306] = "sequence.in.c 1070";           }

                                                       APIF void FloatSequence_stop(FloatSequence *self, Ticks current, Error *err) {
Coverage_array[2307] = "sequence.in.c 1073";               self->cursor       = FloatEventAr_len(&self->events);
Coverage_array[2308] = "sequence.in.c 1074";               self->version++;
Coverage_array[2309] = "sequence.in.c 1075";               self->recordingSeq = NULL;
Coverage_array[2310] = "sequence.in.c 1076";               Outlet_sendFloat(self->outlet, self->restoreValue, err);
Coverage_array[2311] = "sequence.in.c 1077";           }

                                                       APIF void FloatSequence_padNoteOff(FloatSequence *self, int padIndex, Ticks current, Error *err) {
Coverage_array[2312] = "sequence.in.c 1080";               if (self->inEndgroup && !self->cycle) {
Coverage_array[2313] = "sequence.in.c 1081";                   FloatSequence_stop(self, current, err);
Coverage_array[2314] = "sequence.in.c 1082";               }
Coverage_array[2315] = "sequence.in.c 1083";           }

                                                       APIF void FloatSequence_makeConsistent(FloatSequence *self)
                                                       {
Coverage_array[2316] = "sequence.in.c 1087";               FloatEventAr_sort(&self->events);
Coverage_array[2317] = "sequence.in.c 1088";               double seen = -1;
Coverage_array[2318] = "sequence.in.c 1089";               FloatEventAr_rforeach(it, &self->events) {
Coverage_array[2319] = "sequence.in.c 1090";                   if (seen == it.var->stime) {
Coverage_array[2320] = "sequence.in.c 1091";                       FloatEventArRIt_remove(&it);
Coverage_array[2321] = "sequence.in.c 1092";                   }
Coverage_array[2322] = "sequence.in.c 1093";                   seen = it.var->stime;
Coverage_array[2323] = "sequence.in.c 1094";               }
Coverage_array[2324] = "sequence.in.c 1095";           }

                                                       APIF Sequence *FloatSequence_compactNew(FloatSequence *self, Ticks recordStart)
                                                       {
Coverage_array[2325] = "sequence.in.c 1099";               FloatSequence *other   = FloatSequence_new();
Coverage_array[2326] = "sequence.in.c 1100";               other->startTime       = recordStart;
Coverage_array[2327] = "sequence.in.c 1101";               other->outletSpecifier = self->outletSpecifier;
Coverage_array[2328] = "sequence.in.c 1102";               other->outlet          = self->outlet;
Coverage_array[2329] = "sequence.in.c 1103";               return FloatSequence_castToSequence(other);
Coverage_array[2330] = "sequence.in.c 1104";           }

                                                       APIF void FloatSequence_compactConcat(FloatSequence *self, Sequence *otherSeq, Error *err)
                                                       {
Coverage_array[2331] = "sequence.in.c 1108";               FloatSequence *other = FloatSequence_castFromSequence(otherSeq);
Coverage_array[2332] = "sequence.in.c 1109";               if (other == NULL) {
Coverage_array[2333] = "sequence.in.c 1110";                   Error_format(err, "FloatSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
Coverage_array[2334] = "sequence.in.c 1111";                   return;
Coverage_array[2335] = "sequence.in.c 1112";               }
Coverage_array[2336] = "sequence.in.c 1113";               FloatEventAr_foreach(it, &other->events) {
Coverage_array[2337] = "sequence.in.c 1114";                   FloatEvent e = *it.var;
Coverage_array[2338] = "sequence.in.c 1115";                   if (FloatSequence_isMarkerValue(e.value)) {
Coverage_array[2339] = "sequence.in.c 1116";                       continue;
Coverage_array[2340] = "sequence.in.c 1117";                   }
Coverage_array[2341] = "sequence.in.c 1118";                   // Remember that self->startTime == recordStart
Coverage_array[2342] = "sequence.in.c 1119";                   e.stime += (other->startTime - self->startTime);
Coverage_array[2343] = "sequence.in.c 1120";                   FloatEventAr_push(&self->events, e); 
Coverage_array[2344] = "sequence.in.c 1121";               }
Coverage_array[2345] = "sequence.in.c 1122";               return;
Coverage_array[2346] = "sequence.in.c 1123";           }

                                                       APIF void FloatSequence_compactSortEvents(FloatSequence *self)
                                                       {
Coverage_array[2347] = "sequence.in.c 1127";               FloatEventAr_sort(&self->events);
Coverage_array[2348] = "sequence.in.c 1128";           }

                                                       APIF Ticks FloatSequence_compactComputeSequenceLength(FloatSequence *self)
                                                       {
Coverage_array[2349] = "sequence.in.c 1132";               Ticks lastTime = -1;
Coverage_array[2350] = "sequence.in.c 1133";               FloatEventAr_rforeach(it, &self->events) {
Coverage_array[2351] = "sequence.in.c 1134";                   lastTime = it.var->stime;
Coverage_array[2352] = "sequence.in.c 1135";                   break;
Coverage_array[2353] = "sequence.in.c 1136";               }
Coverage_array[2354] = "sequence.in.c 1137";           
Coverage_array[2355] = "sequence.in.c 1138";               MusicalContext_declareDefault(musicalContext);
Coverage_array[2356] = "sequence.in.c 1139";               Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
Coverage_array[2357] = "sequence.in.c 1140";               Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
Coverage_array[2358] = "sequence.in.c 1141";               if (seqLen < Sequence_minSequenceLength) {
Coverage_array[2359] = "sequence.in.c 1142";                   seqLen = Sequence_minSequenceLength;
Coverage_array[2360] = "sequence.in.c 1143";               }
Coverage_array[2361] = "sequence.in.c 1144";               return seqLen;
Coverage_array[2362] = "sequence.in.c 1145";           }

                                                       APIF void FloatSequence_compactFinish(FloatSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
                                                       {
Coverage_array[2363] = "sequence.in.c 1149";               if (endgroupTime >= 0) {
Coverage_array[2364] = "sequence.in.c 1150";                   int index = FloatEventAr_len(&self->events) > 0 ? 0 : -1;
Coverage_array[2365] = "sequence.in.c 1151";                   FloatEventAr_rforeach(it, &self->events) {
Coverage_array[2366] = "sequence.in.c 1152";                       if (FloatSequence_isMarkerValue(it.var->value)) {
Coverage_array[2367] = "sequence.in.c 1153";                           continue;
Coverage_array[2368] = "sequence.in.c 1154";                       }
Coverage_array[2369] = "sequence.in.c 1155";                       if (self->startTime + it.var->stime < endgroupTime) {
Coverage_array[2370] = "sequence.in.c 1156";                           index = it.index + 1;
Coverage_array[2371] = "sequence.in.c 1157";                           break;
Coverage_array[2372] = "sequence.in.c 1158";                       }
Coverage_array[2373] = "sequence.in.c 1159";                   }
Coverage_array[2374] = "sequence.in.c 1160";                   if (index >= 0) {
Coverage_array[2375] = "sequence.in.c 1161";                       FloatEvent newEv = {.stime = endgroupTime, .value = FloatSequence_endgMarker};
Coverage_array[2376] = "sequence.in.c 1162";                       FloatEventAr_insert(&self->events, index, newEv, err);
Coverage_array[2377] = "sequence.in.c 1163";                       Error_returnVoidOnError(err);
Coverage_array[2378] = "sequence.in.c 1164";                   }
Coverage_array[2379] = "sequence.in.c 1165";               }
Coverage_array[2380] = "sequence.in.c 1166";           
Coverage_array[2381] = "sequence.in.c 1167";               self->sequenceLength = sequenceLength;
Coverage_array[2382] = "sequence.in.c 1168";               FloatEvent newEv = {.stime = sequenceLength, .value = FloatSequence_cycleMarker};
Coverage_array[2383] = "sequence.in.c 1169";               FloatEventAr_push(&self->events, newEv);
Coverage_array[2384] = "sequence.in.c 1170";               FloatSequence_makeConsistent(self);
Coverage_array[2385] = "sequence.in.c 1171";               return;
Coverage_array[2386] = "sequence.in.c 1172";           }

#line 1287 "src/sequence.in.c"

// APIF void SequenceAr_truncateNoClear(SequenceAr *self) {
//     SequenceAr_foreach(it, self) {
//         *it.var = NULL;
//     }
//     SequenceAr_truncate(self);
// }

                                                       APIF void Sequence_freePpErrless(Sequence **s)
                                                       {
Coverage_array[2387] = "sequence.in.c 1297";               Error_declare(err);
Coverage_array[2388] = "sequence.in.c 1298";               Sequence_free(*s, err);
Coverage_array[2389] = "sequence.in.c 1299";               Error_maypost(err);
Coverage_array[2390] = "sequence.in.c 1300";           }

// Sort into unique OutletSpecifiers, and sort by startTime within the same OutletSpecifier.
                                                       APIF int Sequence_cmp(Sequence *leftSeq, Sequence *rightSeq) {
Coverage_array[2391] = "sequence.in.c 1304";               OutletSpecifier *left  = &leftSeq->outletSpecifier;
Coverage_array[2392] = "sequence.in.c 1305";               OutletSpecifier *right = &rightSeq->outletSpecifier;
Coverage_array[2393] = "sequence.in.c 1306";               int q = Symbol_cmp(OutletSpecifier_track(left), OutletSpecifier_track(right));
Coverage_array[2394] = "sequence.in.c 1307";               if (q) {
Coverage_array[2395] = "sequence.in.c 1308";                   return q;
Coverage_array[2396] = "sequence.in.c 1309";               }
Coverage_array[2397] = "sequence.in.c 1310";           
Coverage_array[2398] = "sequence.in.c 1311";               // Want to sort NoteSequence to the front of the array. We could do this by looking for *note in parameter name, but I like this better.
Coverage_array[2399] = "sequence.in.c 1312";               bool noteLeft  = Interface_itype(leftSeq)  == NoteSequence_itype;
Coverage_array[2400] = "sequence.in.c 1313";               bool noteRight = Interface_itype(rightSeq) == NoteSequence_itype;
Coverage_array[2401] = "sequence.in.c 1314";               if (noteLeft && !noteRight) {
Coverage_array[2402] = "sequence.in.c 1315";                   return -1;
Coverage_array[2403] = "sequence.in.c 1316";               } else if (!noteLeft && noteRight) {
Coverage_array[2404] = "sequence.in.c 1317";                   return 1;
Coverage_array[2405] = "sequence.in.c 1318";               }
Coverage_array[2406] = "sequence.in.c 1319";               
Coverage_array[2407] = "sequence.in.c 1320";           
Coverage_array[2408] = "sequence.in.c 1321";               int leftPi  = OutletSpecifier_pluginIndex(left);
Coverage_array[2409] = "sequence.in.c 1322";               int rightPi = OutletSpecifier_pluginIndex(right);
Coverage_array[2410] = "sequence.in.c 1323";               if (leftPi < rightPi) {
Coverage_array[2411] = "sequence.in.c 1324";                   return -1;
Coverage_array[2412] = "sequence.in.c 1325";               } else if (leftPi > rightPi) {
Coverage_array[2413] = "sequence.in.c 1326";                   return 1;
Coverage_array[2414] = "sequence.in.c 1327";               }
Coverage_array[2415] = "sequence.in.c 1328";           
Coverage_array[2416] = "sequence.in.c 1329";               q = Symbol_cmp(OutletSpecifier_parameter(left), OutletSpecifier_parameter(right));
Coverage_array[2417] = "sequence.in.c 1330";               if (q) {
Coverage_array[2418] = "sequence.in.c 1331";                   return q;
Coverage_array[2419] = "sequence.in.c 1332";               }    
Coverage_array[2420] = "sequence.in.c 1333";           
Coverage_array[2421] = "sequence.in.c 1334";               leftPi  = OutletSpecifier_paramIndex(left);
Coverage_array[2422] = "sequence.in.c 1335";               rightPi = OutletSpecifier_paramIndex(right);
Coverage_array[2423] = "sequence.in.c 1336";               if (leftPi < rightPi) {
Coverage_array[2424] = "sequence.in.c 1337";                   return -1;
Coverage_array[2425] = "sequence.in.c 1338";               } else if (leftPi > rightPi) {
Coverage_array[2426] = "sequence.in.c 1339";                   return 1;
Coverage_array[2427] = "sequence.in.c 1340";               }    
Coverage_array[2428] = "sequence.in.c 1341";           
Coverage_array[2429] = "sequence.in.c 1342";               if (leftSeq->startTime < rightSeq->startTime) {
Coverage_array[2430] = "sequence.in.c 1343";                   return -1;
Coverage_array[2431] = "sequence.in.c 1344";               } else if (leftSeq->startTime > rightSeq->startTime) {
Coverage_array[2432] = "sequence.in.c 1345";                   return 1;
Coverage_array[2433] = "sequence.in.c 1346";               }
Coverage_array[2434] = "sequence.in.c 1347";           
Coverage_array[2435] = "sequence.in.c 1348";               return 0;
Coverage_array[2436] = "sequence.in.c 1349";           }

                                                       APIF int Sequence_cmpPointer(Sequence *leftSeq, Sequence *rightSeq) {
Coverage_array[2437] = "sequence.in.c 1352";               if (leftSeq < rightSeq) {
Coverage_array[2438] = "sequence.in.c 1353";                   return -1;
Coverage_array[2439] = "sequence.in.c 1354";               }  else if (leftSeq > rightSeq) {
Coverage_array[2440] = "sequence.in.c 1355";                   return 1;
Coverage_array[2441] = "sequence.in.c 1356";               }
Coverage_array[2442] = "sequence.in.c 1357";           
Coverage_array[2443] = "sequence.in.c 1358";               return 0;
Coverage_array[2444] = "sequence.in.c 1359";           }

                                                       APIF int Sequence_cmpPp(Sequence **left, Sequence **right) {
Coverage_array[2445] = "sequence.in.c 1362";               return Sequence_cmp(*left, *right);
Coverage_array[2446] = "sequence.in.c 1363";           }

                                                       APIF int Sequence_cmpPointerPp(Sequence **left, Sequence **right)
                                                       {
Coverage_array[2447] = "sequence.in.c 1367";               return Sequence_cmpPointer(*left, *right);
Coverage_array[2448] = "sequence.in.c 1368";           }

                                                       APIF void Sequence_incVersion(Sequence *seq) {
Coverage_array[2449] = "sequence.in.c 1371";               seq->version++;
Coverage_array[2450] = "sequence.in.c 1372";           }

#line 1394 "src/sequence.in.c"

                                                       APIF void RecordBuffer_push(RecordBuffer *self, Sequence *sequence)
                                                       {
Coverage_array[2451] = "sequence.in.c 1397";               SequenceAr_push(&self->sequences, sequence);
Coverage_array[2452] = "sequence.in.c 1398";           }

                                                       APIF void RecordBuffer_compact(RecordBuffer *self, SequenceAr *output, Error *err)
                                                       {
Coverage_array[2453] = "sequence.in.c 1402";               SequenceAr_sort(&self->sequences);
Coverage_array[2454] = "sequence.in.c 1403";               SequenceAr_truncate(output);
Coverage_array[2455] = "sequence.in.c 1404";           
Coverage_array[2456] = "sequence.in.c 1405";               // Compact all the sequences we can
Coverage_array[2457] = "sequence.in.c 1406";               Sequence *current = NULL;
Coverage_array[2458] = "sequence.in.c 1407";               SequenceAr_foreach(it, &self->sequences) {
Coverage_array[2459] = "sequence.in.c 1408";                   if (current == NULL || Sequence_cmp(*it.var, current) != 0) {
Coverage_array[2460] = "sequence.in.c 1409";                       current = Sequence_compactNew(*it.var, self->recordStart, err);
Coverage_array[2461] = "sequence.in.c 1410";                       Error_gotoLabelOnError(err, END);
Coverage_array[2462] = "sequence.in.c 1411";                       SequenceAr_push(output, current);
Coverage_array[2463] = "sequence.in.c 1412";                   } 
Coverage_array[2464] = "sequence.in.c 1413";                   Sequence_compactConcat(current, *it.var, err);
Coverage_array[2465] = "sequence.in.c 1414";                   Error_gotoLabelOnError(err, END); 
Coverage_array[2466] = "sequence.in.c 1415";               }
Coverage_array[2467] = "sequence.in.c 1416";           
Coverage_array[2468] = "sequence.in.c 1417";               Ticks sequenceLength = -1;
Coverage_array[2469] = "sequence.in.c 1418";               SequenceAr_foreach(it, output) {
Coverage_array[2470] = "sequence.in.c 1419";                   Sequence *s = *it.var;
Coverage_array[2471] = "sequence.in.c 1420";                   Sequence_compactSortEvents(s, err);
Coverage_array[2472] = "sequence.in.c 1421";                   Error_gotoLabelOnError(err, END); 
Coverage_array[2473] = "sequence.in.c 1422";                   Ticks len = Sequence_compactComputeSequenceLength(s, err);
Coverage_array[2474] = "sequence.in.c 1423";                   Error_gotoLabelOnError(err, END);
Coverage_array[2475] = "sequence.in.c 1424";                   if (len > sequenceLength) {
Coverage_array[2476] = "sequence.in.c 1425";                       len = sequenceLength;
Coverage_array[2477] = "sequence.in.c 1426";                   }
Coverage_array[2478] = "sequence.in.c 1427";               }
Coverage_array[2479] = "sequence.in.c 1428";           
Coverage_array[2480] = "sequence.in.c 1429";               // We assign the endgroup for a collection of sequences by looking at the first and only noteSequence for a given track. If no noteSequence
Coverage_array[2481] = "sequence.in.c 1430";               // exists for this track, endgroup is unassigned.
Coverage_array[2482] = "sequence.in.c 1431";               Ticks currentEndgroupTime = -1;
Coverage_array[2483] = "sequence.in.c 1432";               Symbol *track = NULL;
Coverage_array[2484] = "sequence.in.c 1433";               SequenceAr_foreach(it, output) {
Coverage_array[2485] = "sequence.in.c 1434";                   Sequence *s = *it.var;
Coverage_array[2486] = "sequence.in.c 1435";           
Coverage_array[2487] = "sequence.in.c 1436";                   if (track != s->outletSpecifier.track) {
Coverage_array[2488] = "sequence.in.c 1437";                       track = s->outletSpecifier.track;
Coverage_array[2489] = "sequence.in.c 1438";                       NoteSequence *ns = NoteSequence_castFromSequence(s);
Coverage_array[2490] = "sequence.in.c 1439";                       if (ns == NULL) {
Coverage_array[2491] = "sequence.in.c 1440";                           currentEndgroupTime = -1;
Coverage_array[2492] = "sequence.in.c 1441";                       } else {
Coverage_array[2493] = "sequence.in.c 1442";                           currentEndgroupTime = NoteSequence_computeEndgroupTime(ns);
Coverage_array[2494] = "sequence.in.c 1443";                       }
Coverage_array[2495] = "sequence.in.c 1444";                   }
Coverage_array[2496] = "sequence.in.c 1445";                   Sequence_compactFinish(s, currentEndgroupTime, sequenceLength, err);
Coverage_array[2497] = "sequence.in.c 1446";                   Error_gotoLabelOnError(err, END);
Coverage_array[2498] = "sequence.in.c 1447";               }
Coverage_array[2499] = "sequence.in.c 1448";           
Coverage_array[2500] = "sequence.in.c 1449";             END:
Coverage_array[2501] = "sequence.in.c 1450";               if (Error_iserror(err)) {
Coverage_array[2502] = "sequence.in.c 1451";                   SequenceAr_truncate(output);
Coverage_array[2503] = "sequence.in.c 1452";               }
Coverage_array[2504] = "sequence.in.c 1453";               return;
Coverage_array[2505] = "sequence.in.c 1454";           }


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
Coverage_array[2506] = "sequence.in.c 1474";               static String *buffer       = NULL;
Coverage_array[2507] = "sequence.in.c 1475";               static StringPtAr *arBuffer = NULL;
Coverage_array[2508] = "sequence.in.c 1476";               if (buffer == NULL) {
Coverage_array[2509] = "sequence.in.c 1477";                   buffer   = String_empty();
Coverage_array[2510] = "sequence.in.c 1478";                   arBuffer = StringPtAr_new(0);
Coverage_array[2511] = "sequence.in.c 1479";               }
Coverage_array[2512] = "sequence.in.c 1480";               
Coverage_array[2513] = "sequence.in.c 1481";               MidiEvent event = {0}, zero = {0};
Coverage_array[2514] = "sequence.in.c 1482";               for (;;) {
Coverage_array[2515] = "sequence.in.c 1483";                   event      = zero;
Coverage_array[2516] = "sequence.in.c 1484";                   event.type = Midi_eofEventType;
Coverage_array[2517] = "sequence.in.c 1485";                   if (!String_readline(&buffer, pipe, err)) {
Coverage_array[2518] = "sequence.in.c 1486";                       return event;
Coverage_array[2519] = "sequence.in.c 1487";                   }
Coverage_array[2520] = "sequence.in.c 1488";           
Coverage_array[2521] = "sequence.in.c 1489";                   String_split(buffer, ",", arBuffer);
Coverage_array[2522] = "sequence.in.c 1490";                   StringPtAr_foreach(it, arBuffer) {
Coverage_array[2523] = "sequence.in.c 1491";                       String_trim(it.var);
Coverage_array[2524] = "sequence.in.c 1492";                   }
Coverage_array[2525] = "sequence.in.c 1493";           
Coverage_array[2526] = "sequence.in.c 1494";                   if (StringPtAr_len(arBuffer) < 3) {
Coverage_array[2527] = "sequence.in.c 1495";                       Error_format0(err, "Not enough fields in midicsv file");
Coverage_array[2528] = "sequence.in.c 1496";                       return event;
Coverage_array[2529] = "sequence.in.c 1497";                   }
Coverage_array[2530] = "sequence.in.c 1498";           
Coverage_array[2531] = "sequence.in.c 1499";                   String *timeString = StringPtAr_get(arBuffer, 1, err);
Coverage_array[2532] = "sequence.in.c 1500";                   Error_returnValueOnError(err, event);
Coverage_array[2533] = "sequence.in.c 1501";                   event.time = String_toInteger(timeString, err);
Coverage_array[2534] = "sequence.in.c 1502";                   Error_returnValueOnError(err, event);
Coverage_array[2535] = "sequence.in.c 1503";           
Coverage_array[2536] = "sequence.in.c 1504";                   String *type = StringPtAr_get(arBuffer, 2, err);
Coverage_array[2537] = "sequence.in.c 1505";                   Error_returnValueOnError(err, event);
Coverage_array[2538] = "sequence.in.c 1506";           
Coverage_array[2539] = "sequence.in.c 1507";                   if (String_cequal(type, "Note_off_c") || String_cequal(type, "Note_on_c")) {
Coverage_array[2540] = "sequence.in.c 1508";                       event.type = Midi_noteEventType;
Coverage_array[2541] = "sequence.in.c 1509";                       if (StringPtAr_len(arBuffer) < 6) {
Coverage_array[2542] = "sequence.in.c 1510";                           Error_format0(err, "Bad Note_off/on_c");
Coverage_array[2543] = "sequence.in.c 1511";                           return event;
Coverage_array[2544] = "sequence.in.c 1512";                       }
Coverage_array[2545] = "sequence.in.c 1513";                   } else if (String_cequal(type, "Pitch_bend_c")) {
Coverage_array[2546] = "sequence.in.c 1514";                       event.type = Midi_bendEventType;
Coverage_array[2547] = "sequence.in.c 1515";                       if (StringPtAr_len(arBuffer) < 5) {
Coverage_array[2548] = "sequence.in.c 1516";                           Error_format0(err, "Bad Pitch_bend_c");
Coverage_array[2549] = "sequence.in.c 1517";                           return event;
Coverage_array[2550] = "sequence.in.c 1518";                       }
Coverage_array[2551] = "sequence.in.c 1519";                   } else if (String_cequal(type, "Control_c")) {
Coverage_array[2552] = "sequence.in.c 1520";                       event.type = Midi_ccEventType;
Coverage_array[2553] = "sequence.in.c 1521";                       if (StringPtAr_len(arBuffer) < 6) {
Coverage_array[2554] = "sequence.in.c 1522";                           Error_format0(err, "Bad Control_c");
Coverage_array[2555] = "sequence.in.c 1523";                           return event;
Coverage_array[2556] = "sequence.in.c 1524";                       }
Coverage_array[2557] = "sequence.in.c 1525";                   } else if (String_cequal(type, "Header")) {
Coverage_array[2558] = "sequence.in.c 1526";                       if (StringPtAr_len(arBuffer) < 6) {
Coverage_array[2559] = "sequence.in.c 1527";                           Error_format0(err, "Bad Control_c");
Coverage_array[2560] = "sequence.in.c 1528";                           return event;
Coverage_array[2561] = "sequence.in.c 1529";                       }
Coverage_array[2562] = "sequence.in.c 1530";                   } else {
Coverage_array[2563] = "sequence.in.c 1531";                       continue;
Coverage_array[2564] = "sequence.in.c 1532";                   }
Coverage_array[2565] = "sequence.in.c 1533";           
Coverage_array[2566] = "sequence.in.c 1534";                   break;
Coverage_array[2567] = "sequence.in.c 1535";               }
Coverage_array[2568] = "sequence.in.c 1536";               
Coverage_array[2569] = "sequence.in.c 1537";               String *arg1 = StringPtAr_get(arBuffer, 4, err);
Coverage_array[2570] = "sequence.in.c 1538";               Error_returnValueOnError(err, event);
Coverage_array[2571] = "sequence.in.c 1539";               event.arg1 = String_toInteger(arg1, err); 
Coverage_array[2572] = "sequence.in.c 1540";               
Coverage_array[2573] = "sequence.in.c 1541";               if (event.type != Midi_bendEventType) {
Coverage_array[2574] = "sequence.in.c 1542";                   String *arg2 = StringPtAr_get(arBuffer, 5, err);
Coverage_array[2575] = "sequence.in.c 1543";                   Error_returnValueOnError(err, event);
Coverage_array[2576] = "sequence.in.c 1544";                   event.arg2 = String_toInteger(arg2, err); 
Coverage_array[2577] = "sequence.in.c 1545";               }
Coverage_array[2578] = "sequence.in.c 1546";           
Coverage_array[2579] = "sequence.in.c 1547";               return event;
Coverage_array[2580] = "sequence.in.c 1548";           }

                                                       APIF void Midi_fromfile(const char *midiFilePath, SequenceAr *output, Symbol *defaultTrack, PortFind *portFind, Error *err)
                                                       {
Coverage_array[2581] = "sequence.in.c 1552";               static String *midiCsvExecPath = NULL;
Coverage_array[2582] = "sequence.in.c 1553";               if (midiCsvExecPath == NULL) {
Coverage_array[2583] = "sequence.in.c 1554";                   midiCsvExecPath = String_fmt("%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
Coverage_array[2584] = "sequence.in.c 1555";               }
Coverage_array[2585] = "sequence.in.c 1556";           
Coverage_array[2586] = "sequence.in.c 1557";               String *buffer = String_fmt("'%s' '%s'", midiCsvExecPath, midiFilePath);    
Coverage_array[2587] = "sequence.in.c 1558";               FILE *pipe = popen(buffer, "r");
Coverage_array[2588] = "sequence.in.c 1559";               if (pipe == NULL) {
Coverage_array[2589] = "sequence.in.c 1560";                   Error_format(err, "Failed to create pipe for command `%s`", midiCsvExecPath);
Coverage_array[2590] = "sequence.in.c 1561";                   return;
Coverage_array[2591] = "sequence.in.c 1562";               }
Coverage_array[2592] = "sequence.in.c 1563";           
Coverage_array[2593] = "sequence.in.c 1564";               //
Coverage_array[2594] = "sequence.in.c 1565";               // Loop and collect events. Write them into each sequence type
Coverage_array[2595] = "sequence.in.c 1566";               //
Coverage_array[2596] = "sequence.in.c 1567";               MusicalContext_declareDefault(musicalContext);
Coverage_array[2597] = "sequence.in.c 1568";               float tickFactor = 1.0;
Coverage_array[2598] = "sequence.in.c 1569";               NoteSequence *noteSeq   = NULL;
Coverage_array[2599] = "sequence.in.c 1570";               FloatSequence *bendSeq   = NULL;
Coverage_array[2600] = "sequence.in.c 1571";               FloatSequence *ccSeqs[128] = {NULL};
Coverage_array[2601] = "sequence.in.c 1572";               for (;;) {
Coverage_array[2602] = "sequence.in.c 1573";                   MidiEvent ev = Midi_getNextEvent(pipe, err);
Coverage_array[2603] = "sequence.in.c 1574";                   Error_returnVoidOnError(err);
Coverage_array[2604] = "sequence.in.c 1575";           
Coverage_array[2605] = "sequence.in.c 1576";                   if (ev.type == Midi_eofEventType) {
Coverage_array[2606] = "sequence.in.c 1577";                       break;
Coverage_array[2607] = "sequence.in.c 1578";                   }
Coverage_array[2608] = "sequence.in.c 1579";           
Coverage_array[2609] = "sequence.in.c 1580";                   switch (ev.type) {
                                                                   case Midi_noteEventType: {
Coverage_array[2610] = "sequence.in.c 1582";                           if (noteSeq == NULL) {
Coverage_array[2611] = "sequence.in.c 1583";                               noteSeq = NoteSequence_newTrack(defaultTrack, portFind);
Coverage_array[2612] = "sequence.in.c 1584";                           }
Coverage_array[2613] = "sequence.in.c 1585";                           if (ev.arg2 == 0) {
Coverage_array[2614] = "sequence.in.c 1586";                               bool found = false;
Coverage_array[2615] = "sequence.in.c 1587";                               NoteEventAr_rforeach(it, &noteSeq->events) {
Coverage_array[2616] = "sequence.in.c 1588";                                   if (it.var->pitch == ev.arg1) {
Coverage_array[2617] = "sequence.in.c 1589";                                       if (it.var->duration != NoteSequence_noteOffDuration) {
Coverage_array[2618] = "sequence.in.c 1590";                                           Error_format(err, "Found unpaired note-off at %lld", ev.time);
Coverage_array[2619] = "sequence.in.c 1591";                                           goto END;
Coverage_array[2620] = "sequence.in.c 1592";                                       }
Coverage_array[2621] = "sequence.in.c 1593";                                       it.var->duration = ev.time-it.var->stime;
Coverage_array[2622] = "sequence.in.c 1594";                                       found            = true;
Coverage_array[2623] = "sequence.in.c 1595";                                       break;
Coverage_array[2624] = "sequence.in.c 1596";                                   }
Coverage_array[2625] = "sequence.in.c 1597";                               }
Coverage_array[2626] = "sequence.in.c 1598";                               if (!found) {
Coverage_array[2627] = "sequence.in.c 1599";                                   Error_format(err, "Failed to find paired note-on for note-off at %lld", ev.time);
Coverage_array[2628] = "sequence.in.c 1600";                                   goto END;
Coverage_array[2629] = "sequence.in.c 1601";                               }
Coverage_array[2630] = "sequence.in.c 1602";                           } else {
Coverage_array[2631] = "sequence.in.c 1603";                               NoteEvent newEv = {.pitch = ev.arg1, .velocity = ev.arg2, .stime = ev.time, .duration = NoteSequence_noteOffDuration};
Coverage_array[2632] = "sequence.in.c 1604";                               NoteEventAr_push(&noteSeq->events, newEv);
Coverage_array[2633] = "sequence.in.c 1605";                           }
Coverage_array[2634] = "sequence.in.c 1606";                           break;
Coverage_array[2635] = "sequence.in.c 1607";                       }
                                                                   case Midi_bendEventType: {
Coverage_array[2636] = "sequence.in.c 1609";                           if (bendSeq == NULL) {
Coverage_array[2637] = "sequence.in.c 1610";                               bendSeq = FloatSequence_newBend(defaultTrack, portFind);
Coverage_array[2638] = "sequence.in.c 1611";                           }
Coverage_array[2639] = "sequence.in.c 1612";                           FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg1};
Coverage_array[2640] = "sequence.in.c 1613";                           FloatEventAr_push(&bendSeq->events, newEv);
Coverage_array[2641] = "sequence.in.c 1614";                           break;
Coverage_array[2642] = "sequence.in.c 1615";                       }
                                                                   case Midi_ccEventType: {
Coverage_array[2643] = "sequence.in.c 1617";                           if (ccSeqs[ev.arg1] == NULL) {
Coverage_array[2644] = "sequence.in.c 1618";                               ccSeqs[ev.arg1] = FloatSequence_newCc(defaultTrack, ev.arg1, portFind);
Coverage_array[2645] = "sequence.in.c 1619";                           }
Coverage_array[2646] = "sequence.in.c 1620";                           FloatEvent newEv = {.stime = ev.time, .value = (double)ev.arg2};
Coverage_array[2647] = "sequence.in.c 1621";                           FloatEventAr_push(&(ccSeqs[ev.arg1])->events, newEv);
Coverage_array[2648] = "sequence.in.c 1622";                           break;
Coverage_array[2649] = "sequence.in.c 1623";                       }
                                                                   case Midi_headerEventType: {
Coverage_array[2650] = "sequence.in.c 1625";                           long ppqn = ev.arg2;
Coverage_array[2651] = "sequence.in.c 1626";                           tickFactor = (float)(musicalContext.ticksPerQuarterNote)/(float)(ppqn);
Coverage_array[2652] = "sequence.in.c 1627";                           break;    
Coverage_array[2653] = "sequence.in.c 1628";                       }
Coverage_array[2654] = "sequence.in.c 1629";                   }
Coverage_array[2655] = "sequence.in.c 1630";               }
Coverage_array[2656] = "sequence.in.c 1631";           
Coverage_array[2657] = "sequence.in.c 1632";           
Coverage_array[2658] = "sequence.in.c 1633";               //
Coverage_array[2659] = "sequence.in.c 1634";               // Try and compute endgroup
Coverage_array[2660] = "sequence.in.c 1635";               //
Coverage_array[2661] = "sequence.in.c 1636";               Ticks endgroupTime = -1;
Coverage_array[2662] = "sequence.in.c 1637";               if (noteSeq != NULL) {
Coverage_array[2663] = "sequence.in.c 1638";                   endgroupTime = NoteSequence_computeEndgroupTime(noteSeq);  
Coverage_array[2664] = "sequence.in.c 1639";               }
Coverage_array[2665] = "sequence.in.c 1640";           
Coverage_array[2666] = "sequence.in.c 1641";               //
Coverage_array[2667] = "sequence.in.c 1642";               // Compute length
Coverage_array[2668] = "sequence.in.c 1643";               //
Coverage_array[2669] = "sequence.in.c 1644";               Ticks sequenceLength = -1;
Coverage_array[2670] = "sequence.in.c 1645";               if (noteSeq != NULL) {
Coverage_array[2671] = "sequence.in.c 1646";                   sequenceLength = NoteSequence_compactComputeSequenceLength(noteSeq);
Coverage_array[2672] = "sequence.in.c 1647";               }
Coverage_array[2673] = "sequence.in.c 1648";               if (bendSeq != NULL) {
Coverage_array[2674] = "sequence.in.c 1649";                   Ticks len = FloatSequence_compactComputeSequenceLength(bendSeq);
Coverage_array[2675] = "sequence.in.c 1650";                   if (sequenceLength < len) {
Coverage_array[2676] = "sequence.in.c 1651";                       sequenceLength = len;
Coverage_array[2677] = "sequence.in.c 1652";                   }
Coverage_array[2678] = "sequence.in.c 1653";               }
Coverage_array[2679] = "sequence.in.c 1654";               for (int i = 0; i < 128; i++) {
Coverage_array[2680] = "sequence.in.c 1655";                   if (ccSeqs[i] != NULL) {
Coverage_array[2681] = "sequence.in.c 1656";                       Ticks len = FloatSequence_compactComputeSequenceLength(ccSeqs[i]);
Coverage_array[2682] = "sequence.in.c 1657";                       if (sequenceLength < len) {
Coverage_array[2683] = "sequence.in.c 1658";                           sequenceLength = len;
Coverage_array[2684] = "sequence.in.c 1659";                       }       
Coverage_array[2685] = "sequence.in.c 1660";                   }
Coverage_array[2686] = "sequence.in.c 1661";               }
Coverage_array[2687] = "sequence.in.c 1662";           
Coverage_array[2688] = "sequence.in.c 1663";               //
Coverage_array[2689] = "sequence.in.c 1664";               // Finish sequences off
Coverage_array[2690] = "sequence.in.c 1665";               //
Coverage_array[2691] = "sequence.in.c 1666";               if (noteSeq != NULL) {
Coverage_array[2692] = "sequence.in.c 1667";                   NoteSequence_compactFinish(noteSeq, endgroupTime, sequenceLength, err);
Coverage_array[2693] = "sequence.in.c 1668";                   Error_gotoLabelOnError(err, END);
Coverage_array[2694] = "sequence.in.c 1669";               }
Coverage_array[2695] = "sequence.in.c 1670";               if (bendSeq != NULL) {
Coverage_array[2696] = "sequence.in.c 1671";                   FloatSequence_compactFinish(bendSeq, endgroupTime, sequenceLength, err);
Coverage_array[2697] = "sequence.in.c 1672";                   Error_gotoLabelOnError(err, END);
Coverage_array[2698] = "sequence.in.c 1673";               }
Coverage_array[2699] = "sequence.in.c 1674";               for (int i = 0; i < 128; i++) {
Coverage_array[2700] = "sequence.in.c 1675";                   if (ccSeqs[i] != NULL) {
Coverage_array[2701] = "sequence.in.c 1676";                       FloatSequence_compactFinish(ccSeqs[i], endgroupTime, sequenceLength, err);
Coverage_array[2702] = "sequence.in.c 1677";                       Error_gotoLabelOnError(err, END);
Coverage_array[2703] = "sequence.in.c 1678";                   }
Coverage_array[2704] = "sequence.in.c 1679";               }
Coverage_array[2705] = "sequence.in.c 1680";           
Coverage_array[2706] = "sequence.in.c 1681";             END:
Coverage_array[2707] = "sequence.in.c 1682";               if (pipe != NULL) {
Coverage_array[2708] = "sequence.in.c 1683";                   pclose(pipe);
Coverage_array[2709] = "sequence.in.c 1684";               }
Coverage_array[2710] = "sequence.in.c 1685";               if (Error_iserror(err)) {
Coverage_array[2711] = "sequence.in.c 1686";                   if (noteSeq != NULL) {
Coverage_array[2712] = "sequence.in.c 1687";                       NoteSequence_free(noteSeq);
Coverage_array[2713] = "sequence.in.c 1688";                   }
Coverage_array[2714] = "sequence.in.c 1689";                   if (bendSeq != NULL) {
Coverage_array[2715] = "sequence.in.c 1690";                       FloatSequence_free(bendSeq);
Coverage_array[2716] = "sequence.in.c 1691";                   }
Coverage_array[2717] = "sequence.in.c 1692";                   for (int i = 0; i < 128; i++) {
Coverage_array[2718] = "sequence.in.c 1693";                       if (ccSeqs[i] != NULL) {
Coverage_array[2719] = "sequence.in.c 1694";                           FloatSequence_free(ccSeqs[i]);
Coverage_array[2720] = "sequence.in.c 1695";                       }
Coverage_array[2721] = "sequence.in.c 1696";                   }
Coverage_array[2722] = "sequence.in.c 1697";                   return;
Coverage_array[2723] = "sequence.in.c 1698";               }
Coverage_array[2724] = "sequence.in.c 1699";           
Coverage_array[2725] = "sequence.in.c 1700";               //
Coverage_array[2726] = "sequence.in.c 1701";               // Populate output array
Coverage_array[2727] = "sequence.in.c 1702";               //
Coverage_array[2728] = "sequence.in.c 1703";               SequenceAr_truncate(output);
Coverage_array[2729] = "sequence.in.c 1704";               if (noteSeq != NULL) {
Coverage_array[2730] = "sequence.in.c 1705";                   SequenceAr_push(output, NoteSequence_castToSequence(noteSeq));
Coverage_array[2731] = "sequence.in.c 1706";               }
Coverage_array[2732] = "sequence.in.c 1707";               if (bendSeq != NULL) {
Coverage_array[2733] = "sequence.in.c 1708";                   SequenceAr_push(output, FloatSequence_castToSequence(bendSeq));
Coverage_array[2734] = "sequence.in.c 1709";               }
Coverage_array[2735] = "sequence.in.c 1710";               for (int i = 0; i < 128; i++) {
Coverage_array[2736] = "sequence.in.c 1711";                   if (ccSeqs[i] != NULL) {
Coverage_array[2737] = "sequence.in.c 1712";                       SequenceAr_push(output, FloatSequence_castToSequence(ccSeqs[i]));
Coverage_array[2738] = "sequence.in.c 1713";                   }
Coverage_array[2739] = "sequence.in.c 1714";               }
Coverage_array[2740] = "sequence.in.c 1715";               SequenceAr_sort(output);
Coverage_array[2741] = "sequence.in.c 1716";           }

//
//
//
/*
                                                       APIF void Frontend_recievedPadHit(Hub *hub, long pitchIn, long velocityIn){
Coverage_array[2742] = "sequence.in.c 1723";               Error_declare(err);
Coverage_array[2743] = "sequence.in.c 1724";               int padIndex = Hub_padIndexFromInNote(hub, pitchIn);
Coverage_array[2744] = "sequence.in.c 1725";               if (padIndex >= PadAr_len(PadList_pads(Hub_padList(hub)))) {
Coverage_array[2745] = "sequence.in.c 1726";                   post("Bad padIndex %d", padIndex);
Coverage_array[2746] = "sequence.in.c 1727";                   return;
Coverage_array[2747] = "sequence.in.c 1728";               }
Coverage_array[2748] = "sequence.in.c 1729";           
Coverage_array[2749] = "sequence.in.c 1730";               if (velocityIn == 0) {
Coverage_array[2750] = "sequence.in.c 1731";                   Pad *pad = PadList_pad(Hub_padList(x), padIndex, err);
Coverage_array[2751] = "sequence.in.c 1732";                   if (Error_maypost(err)) {
Coverage_array[2752] = "sequence.in.c 1733";                       return;
Coverage_array[2753] = "sequence.in.c 1734";                   }
Coverage_array[2754] = "sequence.in.c 1735";                   Pad_setNoteReleasePending(pad, false);
Coverage_array[2755] = "sequence.in.c 1736";                   SequenceAr_foreach(it, Pad_sequenceList(pad)) {
Coverage_array[2756] = "sequence.in.c 1737";                   Sequence_padNoteOff(it.var);
Coverage_array[2757] = "sequence.in.c 1738";               }
Coverage_array[2758] = "sequence.in.c 1739";               return;
Coverage_array[2759] = "sequence.in.c 1740";               }
Coverage_array[2760] = "sequence.in.c 1741";           
Coverage_array[2761] = "sequence.in.c 1742";               if (Hub_grabNextTappedPad(hub)) {
Coverage_array[2762] = "sequence.in.c 1743";                 Hub_setGrabNextTappedPad(hub, false); 
Coverage_array[2763] = "sequence.in.c 1744";                 Hub_changeSelectedPad(hub, padIndex, err);
Coverage_array[2764] = "sequence.in.c 1745";                 Error_maypost(err);
Coverage_array[2765] = "sequence.in.c 1746";               }
Coverage_array[2766] = "sequence.in.c 1747";           
Coverage_array[2767] = "sequence.in.c 1748";           
Coverage_array[2768] = "sequence.in.c 1749";               Ticks now = Ticks_now();
Coverage_array[2769] = "sequence.in.c 1750";               Ticks clockStart = Pad_useMasterClock(pad) ? Hub_masterClock(hub) : now;
Coverage_array[2770] = "sequence.in.c 1751";               SequenceAr_foreach(it, Pad_sequenceList(pad)) {
Coverage_array[2771] = "sequence.in.c 1752";                  SequenceAr_binInsertSeqPt(Hub_runningSequences(hub), it.var);
Coverage_array[2772] = "sequence.in.c 1753";                  Sequence_start(it.var, clockStart, now, Hub_queue(hub), Hub_recordBuffer(hub));
Coverage_array[2773] = "sequence.in.c 1754";               }
Coverage_array[2774] = "sequence.in.c 1755";           
Coverage_array[2775] = "sequence.in.c 1756";               Error_clear(err);
Coverage_array[2776] = "sequence.in.c 1757";           }

                                                       APIF void Frontend_drive(Hub *hub) {
Coverage_array[2777] = "sequence.in.c 1760";               Ticks now = Ticks_now();
Coverage_array[2778] = "sequence.in.c 1761";               TimedPq *queue = Hub_queue(hub);
Coverage_array[2779] = "sequence.in.c 1762";               Sequence *seq = TimedPq_dequeue(queue);
Coverage_array[2780] = "sequence.in.c 1763";               while (seq != NULL) {
Coverage_array[2781] = "sequence.in.c 1764";                   Sequence_drive(seq, now, queue);
Coverage_array[2782] = "sequence.in.c 1765";                   seq = TimedPq_dequeue(queue);
Coverage_array[2783] = "sequence.in.c 1766";               }
Coverage_array[2784] = "sequence.in.c 1767";           }

                                                       APIF void Frontend_stop(Hub *hub) {
Coverage_array[2785] = "sequence.in.c 1770";               SequenceAr_foreach(it, Hub_runningSequences(hub)) {
Coverage_array[2786] = "sequence.in.c 1771";                   Sequence_stop(it.var);
Coverage_array[2787] = "sequence.in.c 1772";               }
Coverage_array[2788] = "sequence.in.c 1773";           }
*/
#line 1 "test/for_tarray.in.c"
#line 24 "test/for_tarray.in.c"

#line 32 "test/for_tarray.in.c"

const int maxNumRecorded = 10;
int numRecorded          = 0;
Foo recorded[maxNumRecorded] = {0};

                                                       APIF void Foo_recorder(Foo *self)
                                                       {
Coverage_array[2789] = "for_tarray.in.c 39";               if (numRecorded < maxNumRecorded) {
Coverage_array[2790] = "for_tarray.in.c 40";                   recorded[numRecorded++] = *self;
Coverage_array[2791] = "for_tarray.in.c 41";               }
Coverage_array[2792] = "for_tarray.in.c 42";           }

                                                       APIF int Foo_cmp(Foo *left, Foo *right) 
                                                       {
Coverage_array[2793] = "for_tarray.in.c 46";               if (left->i < right->i) {
Coverage_array[2794] = "for_tarray.in.c 47";                   return -1;
Coverage_array[2795] = "for_tarray.in.c 48";               } else if (left->i > right->i) {
Coverage_array[2796] = "for_tarray.in.c 49";                   return 1;
Coverage_array[2797] = "for_tarray.in.c 50";               }
Coverage_array[2798] = "for_tarray.in.c 51";               return 0;
Coverage_array[2799] = "for_tarray.in.c 52";           }

                                                       APIF int Foo_cmpBoth(Foo *left, Foo *right) 
                                                       {
Coverage_array[2800] = "for_tarray.in.c 56";               int q = Foo_cmp(left, right);
Coverage_array[2801] = "for_tarray.in.c 57";               if (q) {
Coverage_array[2802] = "for_tarray.in.c 58";                   return q;
Coverage_array[2803] = "for_tarray.in.c 59";               }
Coverage_array[2804] = "for_tarray.in.c 60";           
Coverage_array[2805] = "for_tarray.in.c 61";               if (left->d < right->d) {
Coverage_array[2806] = "for_tarray.in.c 62";                   return -1;
Coverage_array[2807] = "for_tarray.in.c 63";               } else if (left->d > right->d) {
Coverage_array[2808] = "for_tarray.in.c 64";                   return 1;
Coverage_array[2809] = "for_tarray.in.c 65";               }
Coverage_array[2810] = "for_tarray.in.c 66";           
Coverage_array[2811] = "for_tarray.in.c 67";               return 0;
Coverage_array[2812] = "for_tarray.in.c 68";           }


NOCOVER void Foo_zeroRecord() {
	numRecorded = 0;
	memset(recorded, 0, sizeof(Foo)*maxNumRecorded);
}



#line 1 "test/for_tsequence.in.c"


                                                       APIF Port *Port_newTrackId(Symbol *track, Symbol *id)
                                                       {
Coverage_array[2813] = "for_tsequence.in.c 5";             Port *self = Mem_calloc(sizeof(Port));
Coverage_array[2814] = "for_tsequence.in.c 6";             self->obj.utilityPointer = AtomArAr_new(0);
Coverage_array[2815] = "for_tsequence.in.c 7";             self->track              = track;
Coverage_array[2816] = "for_tsequence.in.c 8";             self->id                 = id;
Coverage_array[2817] = "for_tsequence.in.c 9";             return self;
Coverage_array[2818] = "for_tsequence.in.c 10";        }

                                                       APIF void Port_free(Port *self)
                                                       {
Coverage_array[2819] = "for_tsequence.in.c 14";            if (self->obj.utilityPointer != NULL) {
Coverage_array[2820] = "for_tsequence.in.c 15";                AtomArAr_free(self->obj.utilityPointer);
Coverage_array[2821] = "for_tsequence.in.c 16";            }
Coverage_array[2822] = "for_tsequence.in.c 17";            Mem_free(self);
Coverage_array[2823] = "for_tsequence.in.c 18";        }

                                                       APIF PortFind *PortFind_newFromTable(int argc, PortFindCell *cells)
                                                       {
Coverage_array[2824] = "for_tsequence.in.c 22";            PortFind *self = PortFind_new();
Coverage_array[2825] = "for_tsequence.in.c 23";            for (int i = 0; i < argc; i++) {
Coverage_array[2826] = "for_tsequence.in.c 24";                PortFindCellAr_push(&self->objects, cells[i]);       
Coverage_array[2827] = "for_tsequence.in.c 25";            }
Coverage_array[2828] = "for_tsequence.in.c 26";            return self;
Coverage_array[2829] = "for_tsequence.in.c 27";        }

                                                       APIF PortFind *PortFind_createStandardSpoof(void)
                                                       {
Coverage_array[2830] = "for_tsequence.in.c 31";            const int ncells = 3;
Coverage_array[2831] = "for_tsequence.in.c 32";            Coverage_off;
                                                           PortFindCell cells[ncells] = {
                                                               {.reciever = Port_newTrackId(Symbol_gen("piano"),  Symbol_gen("idPiano")),  .varname = Symbol_gen("unknown")},
                                                               {.reciever = Port_newTrackId(Symbol_gen("guitar"), Symbol_gen("idGuitar")), .varname = Symbol_gen("unknown")},
                                                               {.reciever = Port_newTrackId(Symbol_gen("drums"),  Symbol_gen("idDrums")),  .varname = Symbol_gen("unknown")},
                                                           };
                                                           Coverage_on;
Coverage_array[2832] = "for_tsequence.in.c 39";            return PortFind_newFromTable(ncells, cells);
Coverage_array[2833] = "for_tsequence.in.c 40";        }

                                                       APIF void PortFind_userClear(PortFind *self)
                                                       {
Coverage_array[2834] = "for_tsequence.in.c 44";            PortFindCellAr_foreach(it, &self->objects) {
Coverage_array[2835] = "for_tsequence.in.c 45";                Port_free(it.var->reciever);
Coverage_array[2836] = "for_tsequence.in.c 46";            }
Coverage_array[2837] = "for_tsequence.in.c 47";        }

NoteEventAr *NoteOutlet_dbSent = NULL;

                                                       APIF void NoteOutlet_dbRewindSent() 
                                                       {
Coverage_array[2838] = "for_tsequence.in.c 53";            if (NoteOutlet_dbSent != NULL) {
Coverage_array[2839] = "for_tsequence.in.c 54";                NoteEventAr_truncate(NoteOutlet_dbSent);    
Coverage_array[2840] = "for_tsequence.in.c 55";            }
Coverage_array[2841] = "for_tsequence.in.c 56";        }

                                                       APIF void NoteOutlet_dbRecordEvent(int pitch, int velocity) 
                                                       {
Coverage_array[2842] = "for_tsequence.in.c 60";               if (NoteOutlet_dbSent == NULL) {
Coverage_array[2843] = "for_tsequence.in.c 61";                NoteOutlet_dbSent = NoteEventAr_new(0);
Coverage_array[2844] = "for_tsequence.in.c 62";            }
Coverage_array[2845] = "for_tsequence.in.c 63";            NoteEvent e = {.pitch = pitch, .velocity = velocity, .stime = Ticks_dbCurrent, .duration = 0};
Coverage_array[2846] = "for_tsequence.in.c 64";            NoteEventAr_push(NoteOutlet_dbSent, e);
Coverage_array[2847] = "for_tsequence.in.c 65";        }
                                                       APIF void NoteOutlet_dbGetResults(NoteEventAr *arr)
                                                       {
Coverage_array[2848] = "for_tsequence.in.c 68";            if (NoteOutlet_dbSent == NULL) {
Coverage_array[2849] = "for_tsequence.in.c 69";                return;
Coverage_array[2850] = "for_tsequence.in.c 70";            }
Coverage_array[2851] = "for_tsequence.in.c 71";            NoteEventAr_truncate(arr);
Coverage_array[2852] = "for_tsequence.in.c 72";        
Coverage_array[2853] = "for_tsequence.in.c 73";            Ticks offTime[128] = {0};
Coverage_array[2854] = "for_tsequence.in.c 74";            NoteEventAr_rforeach(it, NoteOutlet_dbSent) {
Coverage_array[2855] = "for_tsequence.in.c 75";                if (it.var->velocity == 0) {
Coverage_array[2856] = "for_tsequence.in.c 76";                    offTime[it.var->pitch] = it.var->stime;
Coverage_array[2857] = "for_tsequence.in.c 77";                } else {
Coverage_array[2858] = "for_tsequence.in.c 78";                    NoteEvent e = *it.var;
Coverage_array[2859] = "for_tsequence.in.c 79";                    if (offTime[e.pitch] == 0) {
Coverage_array[2860] = "for_tsequence.in.c 80";                        // This is the case when we have a note-on without a closing note-off. For better or worse
Coverage_array[2861] = "for_tsequence.in.c 81";                        // I handle this case by ignoring all notes that don't have a note off.
Coverage_array[2862] = "for_tsequence.in.c 82";                        continue;
Coverage_array[2863] = "for_tsequence.in.c 83";                    }
Coverage_array[2864] = "for_tsequence.in.c 84";                    e.duration  = offTime[e.pitch] - e.stime;
Coverage_array[2865] = "for_tsequence.in.c 85";                    NoteEventAr_push(arr, e);
Coverage_array[2866] = "for_tsequence.in.c 86";                }
Coverage_array[2867] = "for_tsequence.in.c 87";            }
Coverage_array[2868] = "for_tsequence.in.c 88";            // reverse arr
Coverage_array[2869] = "for_tsequence.in.c 89";            int N = NoteEventAr_len(arr);
Coverage_array[2870] = "for_tsequence.in.c 90";            NoteEvent *d = arr->data;
Coverage_array[2871] = "for_tsequence.in.c 91";            for (int i = 0; i < N/2; i++) {
Coverage_array[2872] = "for_tsequence.in.c 92";                NoteEvent h = d[i];
Coverage_array[2873] = "for_tsequence.in.c 93";                d[i] = d[N-i-1];
Coverage_array[2874] = "for_tsequence.in.c 94";                d[N-i-1] = h;
Coverage_array[2875] = "for_tsequence.in.c 95";            }
Coverage_array[2876] = "for_tsequence.in.c 96";            NoteOutlet_dbRewindSent();
Coverage_array[2877] = "for_tsequence.in.c 97";        }

                                                       APIF void NoteOutlet_dbReportNoteOffs(NoteEventAr *arr)
                                                       {
Coverage_array[2878] = "for_tsequence.in.c 101";           if (NoteOutlet_dbSent == NULL) {
Coverage_array[2879] = "for_tsequence.in.c 102";               return;
Coverage_array[2880] = "for_tsequence.in.c 103";           }
Coverage_array[2881] = "for_tsequence.in.c 104";           NoteEventAr_truncate(arr);
Coverage_array[2882] = "for_tsequence.in.c 105";       
Coverage_array[2883] = "for_tsequence.in.c 106";           NoteEventAr_foreach(it, NoteOutlet_dbSent) {
Coverage_array[2884] = "for_tsequence.in.c 107";               if (it.var->velocity == 0) {
Coverage_array[2885] = "for_tsequence.in.c 108";                   NoteEvent e = *it.var;
Coverage_array[2886] = "for_tsequence.in.c 109";                   NoteEventAr_push(arr, e);
Coverage_array[2887] = "for_tsequence.in.c 110";               }
Coverage_array[2888] = "for_tsequence.in.c 111";           }
Coverage_array[2889] = "for_tsequence.in.c 112";           // reverse arr
Coverage_array[2890] = "for_tsequence.in.c 113";           int N = NoteEventAr_len(arr);
Coverage_array[2891] = "for_tsequence.in.c 114";           NoteEvent *d = arr->data;
Coverage_array[2892] = "for_tsequence.in.c 115";           for (int i = 0; i < N/2; i++) {
Coverage_array[2893] = "for_tsequence.in.c 116";               NoteEvent h = d[i];
Coverage_array[2894] = "for_tsequence.in.c 117";               d[i] = d[N-i-1];
Coverage_array[2895] = "for_tsequence.in.c 118";               d[N-i-1] = h;
Coverage_array[2896] = "for_tsequence.in.c 119";           }
Coverage_array[2897] = "for_tsequence.in.c 120";           NoteOutlet_dbRewindSent();
Coverage_array[2898] = "for_tsequence.in.c 121";       }


#line 144 "test/for_tsequence.in.c"

                                                       APIF int SequenceDriveDirective_cmp(SequenceDriveDirective *left, SequenceDriveDirective *right)
                                                       {
Coverage_array[2899] = "for_tsequence.in.c 147";           if (left->time < right->time) {
Coverage_array[2900] = "for_tsequence.in.c 148";               return -1;
Coverage_array[2901] = "for_tsequence.in.c 149";           } else if (left->time > right->time) {
Coverage_array[2902] = "for_tsequence.in.c 150";               return 1;
Coverage_array[2903] = "for_tsequence.in.c 151";           }
Coverage_array[2904] = "for_tsequence.in.c 152";           return 0;
Coverage_array[2905] = "for_tsequence.in.c 153";       }

#line 168 "test/for_tsequence.in.c"

#define SequenceDrive_stop 1
#define SequenceDrive_padNoteOff 2


                                                       APIF void SequenceDrive_toCompletion(SequenceDrive *self, Error *err)
                                                       {
Coverage_array[2906] = "for_tsequence.in.c 175";       
Coverage_array[2907] = "for_tsequence.in.c 176";           SequenceDriveDirectivePq_pqSort(&self->directives);
Coverage_array[2908] = "for_tsequence.in.c 177";           if (self->maxIterations <= 0) {
Coverage_array[2909] = "for_tsequence.in.c 178";               self->maxIterations = 1000;
Coverage_array[2910] = "for_tsequence.in.c 179";           }
Coverage_array[2911] = "for_tsequence.in.c 180";           if (self->timeStop <= 0) {
Coverage_array[2912] = "for_tsequence.in.c 181";               self->timeStop = Ticks_maxTime;
Coverage_array[2913] = "for_tsequence.in.c 182";           }
Coverage_array[2914] = "for_tsequence.in.c 183";           if (self->timeDelta <= 0) {
Coverage_array[2915] = "for_tsequence.in.c 184";               self->timeDelta = 480/8; // 32nd note resolution
Coverage_array[2916] = "for_tsequence.in.c 185";           } 
Coverage_array[2917] = "for_tsequence.in.c 186";       
Coverage_array[2918] = "for_tsequence.in.c 187";           Ticks now     = 0;
Coverage_array[2919] = "for_tsequence.in.c 188";           int iteration = 0;
Coverage_array[2920] = "for_tsequence.in.c 189";           for (;;) {
Coverage_array[2921] = "for_tsequence.in.c 190";       
Coverage_array[2922] = "for_tsequence.in.c 191";               // Grab directives
Coverage_array[2923] = "for_tsequence.in.c 192";               SequenceDriveDirective *peeked = SequenceDriveDirectivePq_pqPeek(&self->directives);
Coverage_array[2924] = "for_tsequence.in.c 193";               while (peeked != NULL) {
Coverage_array[2925] = "for_tsequence.in.c 194";                   if (SequenceDriveDirective_time(peeked) > now) {
Coverage_array[2926] = "for_tsequence.in.c 195";                       break;
Coverage_array[2927] = "for_tsequence.in.c 196";                   } 
Coverage_array[2928] = "for_tsequence.in.c 197";       
Coverage_array[2929] = "for_tsequence.in.c 198";                   SequenceDriveDirective timed = {0};
Coverage_array[2930] = "for_tsequence.in.c 199";                   SequenceDriveDirectivePq_pqPop(&self->directives, &timed);
Coverage_array[2931] = "for_tsequence.in.c 200";                   int directive = SequenceDriveDirective_directive(&timed);
Coverage_array[2932] = "for_tsequence.in.c 201";                   if (directive == SequenceDrive_stop) {
Coverage_array[2933] = "for_tsequence.in.c 202";                       SequenceAr *seqAr = SequenceDriveDirective_sequences(&timed);
Coverage_array[2934] = "for_tsequence.in.c 203";                       SequenceAr_foreach(it, seqAr) {
Coverage_array[2935] = "for_tsequence.in.c 204";                           Sequence_stop(*it.var, timed.time, err);
Coverage_array[2936] = "for_tsequence.in.c 205";                           Error_returnVoidOnError(err);
Coverage_array[2937] = "for_tsequence.in.c 206";                       }
Coverage_array[2938] = "for_tsequence.in.c 207";                   } else if (directive == SequenceDrive_padNoteOff) {
Coverage_array[2939] = "for_tsequence.in.c 208";                       SequenceAr *seqAr = SequenceDriveDirective_sequences(&timed);
Coverage_array[2940] = "for_tsequence.in.c 209";                       SequenceAr_foreach(it, seqAr) {
Coverage_array[2941] = "for_tsequence.in.c 210";                           Sequence_padNoteOff(*it.var, 0, now, err);
Coverage_array[2942] = "for_tsequence.in.c 211";                           Error_returnVoidOnError(err);
Coverage_array[2943] = "for_tsequence.in.c 212";                       }
Coverage_array[2944] = "for_tsequence.in.c 213";                   } else {
Coverage_array[2945] = "for_tsequence.in.c 214";                       Error_format(err, "Unknown directive %d\n", directive);
Coverage_array[2946] = "for_tsequence.in.c 215";                   }
Coverage_array[2947] = "for_tsequence.in.c 216";         
Coverage_array[2948] = "for_tsequence.in.c 217";                   peeked = SequenceDriveDirectivePq_pqPeek(&self->directives);
Coverage_array[2949] = "for_tsequence.in.c 218";               }
Coverage_array[2950] = "for_tsequence.in.c 219";       
Coverage_array[2951] = "for_tsequence.in.c 220";               // Drive 
Coverage_array[2952] = "for_tsequence.in.c 221";               for (;;) {
Coverage_array[2953] = "for_tsequence.in.c 222";                   Sequence *seq = TimedPq_dequeue(self->queue, now);
Coverage_array[2954] = "for_tsequence.in.c 223";                   if (seq == NULL) {
Coverage_array[2955] = "for_tsequence.in.c 224";                       break;
Coverage_array[2956] = "for_tsequence.in.c 225";                   }
Coverage_array[2957] = "for_tsequence.in.c 226";                   Sequence_drive(seq, now, self->queue, err);
Coverage_array[2958] = "for_tsequence.in.c 227";                   Error_returnVoidOnError(err);
Coverage_array[2959] = "for_tsequence.in.c 228";               }
Coverage_array[2960] = "for_tsequence.in.c 229";       
Coverage_array[2961] = "for_tsequence.in.c 230";               // Time book keeping
Coverage_array[2962] = "for_tsequence.in.c 231";               if (iteration > self->maxIterations) {
Coverage_array[2963] = "for_tsequence.in.c 232";                   Error_format(err, "Exceeded maxIterations (%d)", iteration);
Coverage_array[2964] = "for_tsequence.in.c 233";                   return;
Coverage_array[2965] = "for_tsequence.in.c 234";               }
Coverage_array[2966] = "for_tsequence.in.c 235";               now += self->timeDelta;
Coverage_array[2967] = "for_tsequence.in.c 236";               if (now > self->timeStop) {
Coverage_array[2968] = "for_tsequence.in.c 237";                   return;
Coverage_array[2969] = "for_tsequence.in.c 238";               }
Coverage_array[2970] = "for_tsequence.in.c 239";       
Coverage_array[2971] = "for_tsequence.in.c 240";               if (TimedPq_len(self->queue) == 0 && SequenceDriveDirectivePq_len(&self->directives) == 0) {
Coverage_array[2972] = "for_tsequence.in.c 241";                   return;
Coverage_array[2973] = "for_tsequence.in.c 242";               }
Coverage_array[2974] = "for_tsequence.in.c 243";           }
Coverage_array[2975] = "for_tsequence.in.c 244";       }

#line 261 "test/for_tsequence.in.c"

                                                       APIF void Resource_listDirectory(Resource *self, String *path, Error *err)
                                                       {
Coverage_array[2976] = "for_tsequence.in.c 264";           const char *paths[2] = {path, NULL};
Coverage_array[2977] = "for_tsequence.in.c 265";           // FTS *tree = fts_open((char *const *)paths, FTS_PHYSICAL | FTS_NOCHDIR | FTS_NOSTAT, NULL);
Coverage_array[2978] = "for_tsequence.in.c 266";           FTS *tree = fts_open((char *const *)paths, FTS_PHYSICAL | FTS_NOCHDIR, NULL);
Coverage_array[2979] = "for_tsequence.in.c 267";           if(tree == NULL) {
Coverage_array[2980] = "for_tsequence.in.c 268";               Error_format0(err, "Failed fts_open");
Coverage_array[2981] = "for_tsequence.in.c 269";               return;
Coverage_array[2982] = "for_tsequence.in.c 270";           }
Coverage_array[2983] = "for_tsequence.in.c 271";       
Coverage_array[2984] = "for_tsequence.in.c 272";           for (;;) {
Coverage_array[2985] = "for_tsequence.in.c 273";               FTSENT *ent = fts_read(tree); // get next entry (could be file or directory).
Coverage_array[2986] = "for_tsequence.in.c 274";               if(ent == NULL) {
Coverage_array[2987] = "for_tsequence.in.c 275";                   if(errno == 0) {
Coverage_array[2988] = "for_tsequence.in.c 276";                       break; // No more items, bail out of while loop
Coverage_array[2989] = "for_tsequence.in.c 277";                   }
Coverage_array[2990] = "for_tsequence.in.c 278";                   
Coverage_array[2991] = "for_tsequence.in.c 279";                   Error_format0(err, "Failed fts_read");
Coverage_array[2992] = "for_tsequence.in.c 280";                   return;
Coverage_array[2993] = "for_tsequence.in.c 281";               }
Coverage_array[2994] = "for_tsequence.in.c 282";                   
Coverage_array[2995] = "for_tsequence.in.c 283";                if (ent->fts_info == FTS_F) {
Coverage_array[2996] = "for_tsequence.in.c 284";                    printf("FILE: %s '%s'\n", ent->fts_path, ent->fts_name);
Coverage_array[2997] = "for_tsequence.in.c 285";                } else if (ent->fts_info == FTS_DP) {
Coverage_array[2998] = "for_tsequence.in.c 286";                    printf("DP:   %s\n", ent->fts_path);
Coverage_array[2999] = "for_tsequence.in.c 287";                    
Coverage_array[3000] = "for_tsequence.in.c 288";                } else if (ent->fts_info == FTS_DC) {
Coverage_array[3001] = "for_tsequence.in.c 289";                   Error_format0(err, "Unexpected directory cycle in fts call chain");
Coverage_array[3002] = "for_tsequence.in.c 290";                   goto END;
Coverage_array[3003] = "for_tsequence.in.c 291";               }
Coverage_array[3004] = "for_tsequence.in.c 292";           }
Coverage_array[3005] = "for_tsequence.in.c 293";        
Coverage_array[3006] = "for_tsequence.in.c 294";           /* fts_read() sets errno = 0 unless it has error. */
Coverage_array[3007] = "for_tsequence.in.c 295";           if (errno != 0) {
Coverage_array[3008] = "for_tsequence.in.c 296";               Error_format0(err, "Failed fts_read");
Coverage_array[3009] = "for_tsequence.in.c 297";               goto END;
Coverage_array[3010] = "for_tsequence.in.c 298";           }
Coverage_array[3011] = "for_tsequence.in.c 299";        
Coverage_array[3012] = "for_tsequence.in.c 300";         END:
Coverage_array[3013] = "for_tsequence.in.c 301";           if(fts_close(tree) == -1) {
Coverage_array[3014] = "for_tsequence.in.c 302";               if (!Error_iserror(err)) {
Coverage_array[3015] = "for_tsequence.in.c 303";                   Error_format0(err, "Failed fts_close");
Coverage_array[3016] = "for_tsequence.in.c 304";               }
Coverage_array[3017] = "for_tsequence.in.c 305";           }
Coverage_array[3018] = "for_tsequence.in.c 306";       }
#line 1 "**coverage**" 
void Coverage_initialize()
{
    Coverage_array = Mem_calloc(sizeof(const char *) * 3019);    
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
    fprintf(out, "*totalSize %d\n", 3019);
    for (int i = 0; i < 3019; i++) {
        if (Coverage_array[i] != NULL) {
            fprintf(out, "%s\n", Coverage_array[i]);
        }
    }
    fclose(out);
    String_free(coverFile);
}
