// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
// *** DO NOT MODIFY THIS FILE generated 03/29/2018 19:44:15 ***
struct Arguments_t;
typedef struct Arguments_t Arguments;
struct Marshal_t;
typedef struct Marshal_t Marshal;
typedef struct Marshal_t MarshalSi;
typedef struct Marshal_t MarshalSii;
typedef struct Marshal_t MarshalSs;
struct Dispatch_t;
typedef struct Dispatch_t Dispatch;
typedef struct Dispatch_t IncrementFrameDispatch;
typedef struct Dispatch_t DecrementFrameDispatch;
typedef struct Dispatch_t SelectNextPushedPadDispatch;
typedef struct Dispatch_t MidiFileDropDispatch;
typedef struct Dispatch_t ManageChokeGroupsDispatch;
struct Port_t;
typedef struct Port_t Port;
struct MEventAr_t;
typedef struct MEventAr_t MEventAr;
struct PtrAr_t;
typedef struct PtrAr_t PtrAr;
struct SymbolPtrAr_t;
typedef struct SymbolPtrAr_t SymbolPtrAr;
struct IntAr_t;
typedef struct IntAr_t IntAr;
struct BinFilePayload_t;
typedef struct BinFilePayload_t BinFilePayload;
struct BinFile_t;
typedef struct BinFile_t BinFile;
struct Midiseq_t;
typedef struct Midiseq_t Midiseq;
struct Pad_t;
typedef struct Pad_t Pad;
struct IndexedOff_t;
typedef struct IndexedOff_t IndexedOff;
struct TimedOff_t;
typedef struct TimedOff_t TimedOff;
struct NoteManager_t;
typedef struct NoteManager_t NoteManager;
struct PortFindCell_t;
typedef struct PortFindCell_t PortFindCell;
struct PortFind_t;
typedef struct PortFind_t PortFind;
struct PadList_t;
typedef struct PadList_t PadList;
struct Track_t;
typedef struct Track_t Track;
struct TrackList_t;
typedef struct TrackList_t TrackList;
struct PortRef_t;
typedef struct PortRef_t PortRef;
struct DropDown_t;
typedef struct DropDown_t DropDown;
struct Hub_t;
typedef struct Hub_t Hub;
struct DispatchPtAr_t;
typedef struct DispatchPtAr_t DispatchPtAr;
struct PadAr_t;
typedef struct PadAr_t PadAr;
struct PadPtrAr_t;
typedef struct PadPtrAr_t PadPtrAr;
struct IndexedOffAr_t;
typedef struct IndexedOffAr_t IndexedOffAr;
struct TimedOffAr_t;
typedef struct TimedOffAr_t TimedOffAr;
struct PortFindCellAr_t;
typedef struct PortFindCellAr_t PortFindCellAr;
struct TrackAr_t;
typedef struct TrackAr_t TrackAr;
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

void Array_pqUp(Array *arr, int j, int (*comparer)(char *, char*)) 
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
bool Array_pqDown(Array *arr, int i0, int n, int (*comparer)(char *, char*)) {
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
      if (PQ_LESS(j, i)) {
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

void Array_pqSort(Array *arr, int (*comparer)(char *, char*)) 
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

void Array_pqPush(Array *arr, char *elem, int (*comparer)(char *, char*))
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

void Array_pqPop(Array *arr, char *elem, int (*comparer)(char *, char*)) 
{

   int n = Array_len(arr)-1;
   memmove(elem, arr->data, arr->elemSize);
   PQ_SWAP(0, n);
   Array_pqDown(arr, 0, n, comparer);
   // XXX: how to handle the clearer in this??
   Array_popN(arr, 1);
}

char *Array_pqPeek(Array *arr) {
   if (Array_len(arr) > 0) {
      return arr->data;
   }
   return NULL;
}

#undef PQ_LESS
#undef PQ_SWAP
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

typedef struct IndexedOffArSlice_t {
    int len;
    IndexedOff *data;
    int index;
    IndexedOff *var;
} IndexedOffArSlice;

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

struct PortRef_t
{
    Port *port;
    int outlet;
};
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
struct TrackList_t
{
    TrackAr list;
};
struct PadList_t
{
    PadAr pads;
    PadPtrAr running;
};
struct PortFind_t
{
    PortFindCellAr objects;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
};
struct NoteManager_t
{
    TimedOffAr pending;
    IndexedOffAr endgroups;
    Port *output;
    Atom *atoms;
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
struct BinFile_t
{
    int version;
    sds filename;
    sds buffer;
    FILE *stream;
    BinFilePayload *payload;
};
struct BinFilePayload_t
{
    PortFind *portFind;
};
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

struct Port_t
{
    t_object d_obj;
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
struct ManageChokeGroupsDispatch_t
{
    int itype;
};
struct MidiFileDropDispatch_t
{
    int itype;
};
struct SelectNextPushedPadDispatch_t
{
    int itype;
};
struct DecrementFrameDispatch_t
{
    int itype;
};
struct IncrementFrameDispatch_t
{
    int itype;
};
struct Dispatch_t
{
    int itype;
    Symbol *selector;
    Symbol *portId;
    int inlet;
    Marshal *marshal;
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
int port_parseEvSymbol(Symbol *id);
void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err);
void Port_sendInteger(Port *p, int outlet, long value);
int Midiseq_convertIntFileLine(const char *src, Error *err, const char *function, const char *file, int line);
Midiseq *Midiseq_new();
void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err);
void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err);
Midiseq *Midiseq_newNote(int pitch);
void Midiseq_init(Midiseq *mseq);
void Midiseq_clear(Midiseq *mseq);
void Midiseq_free(Midiseq *midi);
int Midiseq_len(Midiseq *mseq);
void Midiseq_push(Midiseq *mseq, MEvent cell);
MEvent *Midiseq_get(Midiseq *mseq, int index, Error *err);
void Midiseq_setMidicsvExecPath();
void Midiseq_dblog(Midiseq *mseq);
int midiseq_tokenize(FILE *fd, int *nfields, sds **fields, Error *err);
int Midiseq_assignLength(Midiseq *mseq);
int Midiseq_insertCell(Midiseq *mseq, MEvent cell, int index, Error *err);
void Midiseq_insertEndgroup(Midiseq *mseq, Error *err);
int Midiseq_start(Midiseq *mseq, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void Midiseq_stop(Midiseq *mseq);
int Midiseq_nextevent(Midiseq *mseq, Ticks until, MEvent *cell, Error *err);
int Midiseq_fastfwrd(Midiseq *mseq, long t, Error *err);
Midiseq *Midiseq_fromfile(const char *fullpath, Error *err);
void PortFind_init(PortFind *pf);
long PortFind_iterator(PortFind *pf, t_object *targetBox);
int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err);
void PortFind_clear(PortFind *pf);
Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol);
Port *PortFind_findByTrack(PortFind *pf, Symbol *symbol);
Port *PortFind_findById(PortFind *pf, Symbol *symbol);
int PortFind_portCount(PortFind *pf);
Port *PortFind_findByIndex(PortFind *pf, int index, Error *err);
Pad *Pad_new();
void Pad_init(Pad *pad);
void Pad_free(Pad *pad);
void Pad_clear(Pad *pad);
void Pad_setSequence(Pad *pad, Midiseq *midi);
void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err);
Pad *Pad_fromBinFile(BinFile *bf, Error *err);
void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err);
void Pad_computeChokeGroup(Pad *pad);
PadList *PadList_new(int npads);
void PadList_init(PadList *pl, int npads);
void PadList_clear(PadList *pl);
void PadList_free(PadList *pl);
void PadList_play(PadList *pl, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err);
void PadList_markReleasePending(PadList *pl, int padIndex, bool pending, Error *err);
Pad *PadList_pad(PadList *pl, int index, Error *err);
void PadList_assignTrack(PadList *pl, TrackList *tl);
void PadList_toBinFile(PadList *pl, BinFile *bf, Error *err);
PadList *PadList_fromBinFile(BinFile *bf, Error *err);
void PadList_fromBinFileInitialized(PadList *pl, BinFile *bf, Error *err);
TrackList *TrackList_new(PortFind *pf);
void TrackList_init(TrackList *tl, PortFind *pf);
void TrackList_clear(TrackList *tl);
void TrackList_free(TrackList *tl);
Track *TrackList_findTrackByName(TrackList *tl, Symbol *name);
int TrackList_count(TrackList *tl);
Track *TrackList_findTrackByIndex(TrackList *tl, int index, Error *err);
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err);
void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err);
DropDown *DropDown_new(const char **table, PortRef *pr);
void DropDown_init(DropDown *dd, const char **table, PortRef *pr);
void DropDown_initCGLocalGlobal(DropDown *dd, PortRef *pr);
void DropDown_initCGInstrument(DropDown *dd, PortRef *pr);
void DropDown_initCGIndex(DropDown *dd, PortRef *pr);
void DropDown_clear(DropDown *dd);
void DropDown_free(DropDown *dd);
void DropDown_updateSelected(DropDown *dd, Error *err);
void DropDown_setSelected(DropDown *dd, int selected, Error *err);
void DropDown_initializeMenu(DropDown *dd, Error *err);
int IndexedOff_cmpPadIndex(IndexedOff *left, IndexedOff *right);
int TimedOff_cmpTime(TimedOff *left, TimedOff *right);
NoteManager *NoteManager_new(Port *port);
void NoteManager_free(NoteManager *nm);
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup);
void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity);
void NoteManager_flushOffs(NoteManager *manager);
void NoteManager_dblogPending(NoteManager *manager, Ticks current);
Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current);
void NoteManager_midievent(NoteManager *manager, MEvent cell, int padIndexForEndgroup);
void NoteManager_padNoteOff(NoteManager *manager, int padIndex);
Hub *Hub_new(PortFind *pf, Error *err);
void Hub_init(Hub *hub, PortFind *pf, Error *err);
void Hub_free(Hub *hub);
void Hub_updateGuiCurrentCoordinates(Hub *hub);
void Hub_changeSelectedPad(Hub *hub, int selectedPadIndex, Error *err);
void Hub_anythingDispatch(Hub *hub, Port *port, Symbol *selector, long argc, Atom *argv);
void Hub_intDispatch(Hub *hub, Port *port, long value, long inlet);
void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err);
Hub *Hub_fromBinFile(BinFile *bf, Error *err);
void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err);
BinFile *BinFile_new();
BinFile *BinFile_newWriter(const char *file, Error *err);
BinFile *BinFile_newReader(const char *file, Error *err);
void BinFile_free(BinFile *bf);
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
void BinFile_writeString(BinFile *bf, sds value, Error *err);
sds BinFile_readString(BinFile *bf, Error *err);
void BinFile_writeSymbol(BinFile *bf, Symbol *value, Error *err);
Symbol *BinFile_readSymbol(BinFile *bf, Error *err);
void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err);
Ticks BinFile_readTicks(BinFile *bf, Error *err);
void BinFile_writeBool(BinFile *bf, bool value, Error *err);
bool BinFile_readBool(BinFile *bf, Error *err);
void BinFile_writeTag(BinFile *bf, const char *tag, Error *err);
void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err);
typedef struct Undefined_t {
    int itype;
    char buffer[1024];
} Undefined;
#define Undefined_itype 10
Undefined Undefined_instance = {Undefined_itype, {0}};
#define Undefined_ptr(typeName) ((typeName*)&Undefined_instance)
#define MarshalSi_itype 11
#define MarshalSii_itype 12
#define MarshalSs_itype 13
#define IncrementFrameDispatch_itype 14
#define DecrementFrameDispatch_itype 15
#define SelectNextPushedPadDispatch_itype 16
#define MidiFileDropDispatch_itype 17
#define ManageChokeGroupsDispatch_itype 18
void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err);
void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err);
void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err);
Dispatch *Dispatch_create(int itype, Error *err);
void Dispatch_free(Dispatch *self, Error *err);
void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err);
static inline Symbol *Arguments_s1(Arguments *self){return self->s1;}
static inline void Arguments_setS1(Arguments *self, Symbol *value){self->s1 = value;}
static inline void Arguments_setI1(Arguments *self, long value){self->i1 = value;}
static inline void Arguments_setI2(Arguments *self, long value){self->i2 = value;}
static inline long Arguments_ivalue(Arguments *self){return self->ivalue;}
static inline void Arguments_setIvalue(Arguments *self, long value){self->ivalue = value;}
static inline void Arguments_setInlet(Arguments *self, long value){self->inlet = value;}
static inline int Marshal_nthIType(int n, int *itype) {
    static int itypes[] = {
        MarshalSii_itype, MarshalSi_itype, MarshalSs_itype
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
static inline int Dispatch_nthIType(int n, int *itype) {
    static int itypes[] = {
        MidiFileDropDispatch_itype, ManageChokeGroupsDispatch_itype, DecrementFrameDispatch_itype, SelectNextPushedPadDispatch_itype, IncrementFrameDispatch_itype
    };
    static int len = sizeof(itypes)/sizeof(int);
    if (n < 0 || n >= len) {
        return 0;
    }
    *itype = itypes[n];
    return 1;
}
#define Dispatch_foreachIType(itype) for (int __##itype = 0, itype = 0; Dispatch_nthIType(__##itype, &itype); __##itype++)
static inline Marshal *Dispatch_marshal(Dispatch *self){return self->marshal;}
#define Dispatch_declare(name, itype, selector, portId, inlet, marshal) Dispatch name = {(itype), (selector), (portId), (inlet), (marshal)}
static inline IncrementFrameDispatch *IncrementFrameDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == IncrementFrameDispatch_itype) {
        return (IncrementFrameDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *IncrementFrameDispatch_castToDispatch(IncrementFrameDispatch *self) {
    return (Dispatch*)self;
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
static inline SelectNextPushedPadDispatch *SelectNextPushedPadDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == SelectNextPushedPadDispatch_itype) {
        return (SelectNextPushedPadDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *SelectNextPushedPadDispatch_castToDispatch(SelectNextPushedPadDispatch *self) {
    return (Dispatch*)self;
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
static inline ManageChokeGroupsDispatch *ManageChokeGroupsDispatch_castFromDispatch(Dispatch *self) {
    if (self->itype == ManageChokeGroupsDispatch_itype) {
        return (ManageChokeGroupsDispatch*)self;
    }
    return NULL;
}
static inline Dispatch *ManageChokeGroupsDispatch_castToDispatch(ManageChokeGroupsDispatch *self) {
    return (Dispatch*)self;
}
static inline long Port_inletnum(Port *self){return self->inletnum;}
static inline PtrAr Port_proxy(Port *self){return self->proxy;}
static inline PtrAr Port_outlet(Port *self){return self->outlet;}
static inline Symbol *Port_track(Port *self){return self->track;}
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
static inline void MEventAr_clear(MEventAr *arr) {
    Array_clear((Array*)arr);
    MEventAr zero = {0};
    *arr = zero;
}

static inline void MEventAr_fit(MEventAr *arr) {
    Array_fit((Array*)arr);
}

#define MEventAr_foreach(var, arr)  for (MEventArFIt_declare(var, arr); MEventArFIt_next(&var); )            

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
    Array_init((Array*)arr, nelems, sizeof(MEvent), (Array_clearElement)NULL);
}

static inline void MEventAr_insert(MEventAr *arr, int index, MEvent elem, Error *err) {
    Array_insertNCheck(arr, index, 1, err);
    MEvent *p = (MEvent *)Array_insertN((Array*)arr, index, 1);
    *p = elem;
}

static inline int MEventAr_last(MEventAr *arr) {
    return Array_len((Array*)arr)-1;
}            

static inline int MEventAr_len(MEventAr *arr) {
    return Array_len((Array*)arr);
}

static inline void MEventAr_push(MEventAr *arr, MEvent elem) {
    MEvent *p = (MEvent *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define MEventAr_rforeach(var, arr)  for (MEventArRIt_declare(var, arr); MEventArRIt_next(&var); )            

#define MEventArFIt_declare(var, arr)  MEventArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool MEventArFIt_next(MEventArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

#define MEventArRIt_declare(var, arr)  MEventArRIt var = {arr, 0, (arr)->len, (arr)->len, NULL}

static inline bool MEventArRIt_next(MEventArRIt *iterator) {
    return ArrayRIt_next((ArrayRIt*)iterator);
}

static inline void PtrAr_changeLength(PtrAr *arr, int newLength) {
    Array_changeLength((Array*)arr, newLength);
}                        

static inline void PtrAr_clear(PtrAr *arr) {
    Array_clear((Array*)arr);
    PtrAr zero = {0};
    *arr = zero;
}

#define PtrAr_foreach(var, arr)  for (PtrArFIt_declare(var, arr); PtrArFIt_next(&var); )            

static inline void *PtrAr_get(PtrAr *arr, int index, Error *err) {
    void * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void PtrAr_init(PtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(void *), (Array_clearElement)NULL);
}

static inline void PtrAr_push(PtrAr *arr, void *elem) {
    void * *p = (void **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PtrAr_set(PtrAr *arr, int index, void *elem, Error *err) {
    Array_setCheck(arr, index, err);
    Array_set((Array*)arr, index, (char*)&elem);
}

#define PtrArFIt_declare(var, arr)  PtrArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool PtrArFIt_next(PtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline void SymbolPtrAr_clear(SymbolPtrAr *arr) {
    Array_clear((Array*)arr);
    SymbolPtrAr zero = {0};
    *arr = zero;
}

#define SymbolPtrAr_foreach(var, arr)  for (SymbolPtrArFIt_declare(var, arr); SymbolPtrArFIt_next(&var); )            

static inline Symbol *SymbolPtrAr_get(SymbolPtrAr *arr, int index, Error *err) {
    Symbol * v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void SymbolPtrAr_init(SymbolPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Symbol *), (Array_clearElement)NULL);
}

static inline int SymbolPtrAr_len(SymbolPtrAr *arr) {
    return Array_len((Array*)arr);
}

static inline void SymbolPtrAr_push(SymbolPtrAr *arr, Symbol *elem) {
    Symbol * *p = (Symbol **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define SymbolPtrArFIt_declare(var, arr)  SymbolPtrArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool SymbolPtrArFIt_next(SymbolPtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline int BinFile_version(BinFile *self){return self->version;}
static inline sds BinFile_filename(BinFile *self){return self->filename;}
static inline void BinFile_setFilename(BinFile *self, sds value){self->filename = value;}
static inline sds BinFile_buffer(BinFile *self){return self->buffer;}
static inline void BinFile_setBuffer(BinFile *self, sds value){self->buffer = value;}
static inline FILE *BinFile_stream(BinFile *self){return self->stream;}
static inline void BinFile_setStream(BinFile *self, FILE *value){self->stream = value;}
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))        
static inline bool Midiseq_useMasterClock(Midiseq *self){return self->useMasterClock;}
static inline void Midiseq_setUseMasterClock(Midiseq *self, bool value){self->useMasterClock = value;}
static inline Ticks Midiseq_sequenceLength(Midiseq *self){return self->sequenceLength;}
static inline void Midiseq_setSequenceLength(Midiseq *self, Ticks value){self->sequenceLength = value;}
#define Pad_newUninitialized() ((Pad*)sysmem_newptrclear(sizeof(Pad)))        
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
#define IndexedOff_declare(name, padIndex, pitch) IndexedOff name = {(padIndex), (pitch)}
#define TimedOff_declare(name, time, pitch) TimedOff name = {(time), (pitch)}
static inline void *PortFind_hub(PortFind *self){return self->hub;}
static inline void PortFind_setHub(PortFind *self, void *value){self->hub = value;}
static inline Port_anythingDispatchFunc PortFind_anythingDispatch(PortFind *self){return self->anythingDispatch;}
static inline void PortFind_setAnythingDispatch(PortFind *self, Port_anythingDispatchFunc value){self->anythingDispatch = value;}
static inline Port_intDispatchFunc PortFind_intDispatch(PortFind *self){return self->intDispatch;}
static inline void PortFind_setIntDispatch(PortFind *self, Port_intDispatchFunc value){self->intDispatch = value;}
#define PadList_newUninitialized() ((PadList*)sysmem_newptrclear(sizeof(PadList)))        
static inline PadAr *PadList_pads(PadList *self){return &self->pads;}
static inline PadPtrAr *PadList_running(PadList *self){return &self->running;}
static inline void Track_setName(Track *self, Symbol *value){self->name = value;}
static inline NoteManager *Track_noteManager(Track *self){return self->noteManager;}
static inline void Track_setNoteManager(Track *self, NoteManager *value){self->noteManager = value;}
#define TrackList_newUninitialized() ((TrackList*)sysmem_newptrclear(sizeof(TrackList)))        
static inline Port *PortRef_port(PortRef *self){return self->port;}
static inline int PortRef_outlet(PortRef *self){return self->outlet;}
#define Hub_newUninitialized() ((Hub*)sysmem_newptrclear(sizeof(Hub)))        
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
static inline DropDown *Hub_cgLocalGlobalMenu(Hub *self){return &self->cgLocalGlobalMenu;}
static inline DropDown *Hub_cgInstrumentMenu(Hub *self){return &self->cgInstrumentMenu;}
static inline DropDown *Hub_cgIndexMenu(Hub *self){return &self->cgIndexMenu;}
static inline int Hub_bank(Hub *self){return self->bank;}
static inline int Hub_frame(Hub *self){return self->frame;}
static inline void Hub_setFrame(Hub *self, int value){self->frame = value;}
static inline bool Hub_grabNextTappedPad(Hub *self){return self->grabNextTappedPad;}
static inline void Hub_setGrabNextTappedPad(Hub *self, bool value){self->grabNextTappedPad = value;}
static inline int Hub_selectedPad(Hub *self){return self->selectedPad;}
static inline void Hub_setSelectedPad(Hub *self, int value){self->selectedPad = value;}
static inline void DispatchPtAr_init(DispatchPtAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Dispatch *), (Array_clearElement)NULL);
}

static inline void DispatchPtAr_push(DispatchPtAr *arr, Dispatch *elem) {
    Dispatch * *p = (Dispatch **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void DispatchPtAr_truncate(DispatchPtAr *arr) {
    Array_truncate((Array*)arr);
}

static inline Dispatch **DispatchPtAr_binSearch(DispatchPtAr *arr, Dispatch *elem) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    return (Dispatch **)Array_binSearch((Array*)arr, (char*)&elem, (Array_compare)compare, NULL);
}

static inline void DispatchPtAr_sort(DispatchPtAr *arr) {
    int (*compare)(Dispatch **, Dispatch **) = Dispatch_cmp;
    Array_sort((Array*)arr, (Array_compare)compare);
}                

static inline void PadAr_clear(PadAr *arr) {
    Array_clear((Array*)arr);
    PadAr zero = {0};
    *arr = zero;
}

static inline void PadAr_fit(PadAr *arr) {
    Array_fit((Array*)arr);
}

#define PadAr_foreach(var, arr)  for (PadArFIt_declare(var, arr); PadArFIt_next(&var); )            

static inline Pad *PadAr_getp(PadAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Pad *)Array_get((Array*)arr, index);
}

static inline void PadAr_init(PadAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad), (Array_clearElement)NULL);
}

static inline int PadAr_len(PadAr *arr) {
    return Array_len((Array*)arr);
}

static inline void PadAr_push(PadAr *arr, Pad elem) {
    Pad *p = (Pad *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define PadArFIt_declare(var, arr)  PadArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool PadArFIt_next(PadArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline void PadPtrAr_clear(PadPtrAr *arr) {
    Array_clear((Array*)arr);
    PadPtrAr zero = {0};
    *arr = zero;
}

#define PadPtrAr_foreach(var, arr)  for (PadPtrArFIt_declare(var, arr); PadPtrArFIt_next(&var); )            

static inline void PadPtrAr_init(PadPtrAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Pad *), (Array_clearElement)NULL);
}

static inline void PadPtrAr_push(PadPtrAr *arr, Pad *elem) {
    Pad * *p = (Pad **)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

static inline void PadPtrAr_remove(PadPtrAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

#define PadPtrArFIt_declare(var, arr)  PadPtrArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool PadPtrArFIt_next(PadPtrArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline bool PadPtrArFIt_remove(PadPtrArFIt *iterator) {
    return ArrayFIt_remove((ArrayFIt*)iterator);
}

static inline void IndexedOffAr_clear(IndexedOffAr *arr) {
    Array_clear((Array*)arr);
    IndexedOffAr zero = {0};
    *arr = zero;
}

#define IndexedOffAr_foreach(var, arr)  for (IndexedOffArFIt_declare(var, arr); IndexedOffArFIt_next(&var); )            

static inline void IndexedOffAr_init(IndexedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(IndexedOff), (Array_clearElement)NULL);
}

#define IndexedOffAr_loop(var) while (IndexedOffArFIt_next(&var)) 

static inline void IndexedOffAr_remove(IndexedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void IndexedOffAr_truncate(IndexedOffAr *arr) {
    Array_truncate((Array*)arr);
}

static inline bool IndexedOffArFIt_atEnd(IndexedOffArFIt *iterator) {
    return iterator->index+1 >= iterator->uBound;
}

#define IndexedOffArFIt_declare(var, arr)  IndexedOffArFIt var = {arr, 0, (arr)->len, -1, NULL}

#define IndexedOffArFIt_declare0(var)  IndexedOffArFIt var = {0}

static inline bool IndexedOffArFIt_next(IndexedOffArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
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

static inline void TimedOffAr_clear(TimedOffAr *arr) {
    Array_clear((Array*)arr);
    TimedOffAr zero = {0};
    *arr = zero;
}

#define TimedOffAr_foreach(var, arr)  for (TimedOffArFIt_declare(var, arr); TimedOffArFIt_next(&var); )            

static inline void TimedOffAr_init(TimedOffAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(TimedOff), (Array_clearElement)NULL);
}

static inline void TimedOffAr_remove(TimedOffAr *arr, int index, Error *err) {
    Array_removeNCheck(arr, index, 1, err);
    Array_removeN((Array*)arr, index, 1);
}    

static inline void TimedOffAr_removeN(TimedOffAr *arr, int index, int N, Error *err) {
    Array_removeNCheck(arr, index, N, err);
    Array_removeN((Array*)arr, index, N);
}

static inline void TimedOffAr_truncate(TimedOffAr *arr) {
    Array_truncate((Array*)arr);
}

#define TimedOffArFIt_declare(var, arr)  TimedOffArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool TimedOffArFIt_next(TimedOffArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

static inline void TimedOffAr_binInsertTime(TimedOffAr *arr, TimedOff elem) {
    int (*compare)(TimedOff *, TimedOff *) = TimedOff_cmpTime;
    Array_binInsert((Array*)arr, (char*)&elem, (Array_compare)compare, false);
}            

static inline void PortFindCellAr_clear(PortFindCellAr *arr) {
    Array_clear((Array*)arr);
    PortFindCellAr zero = {0};
    *arr = zero;
}

#define PortFindCellAr_foreach(var, arr)  for (PortFindCellArFIt_declare(var, arr); PortFindCellArFIt_next(&var); )            

static inline PortFindCell PortFindCellAr_get(PortFindCellAr *arr, int index, Error *err) {
    PortFindCell v = {0};
    Array_getCheck(arr, index, v, err);
    memmove(&v, Array_get((Array*)arr, index), Array_elemSize((Array*)arr));
    return v;
}

static inline void PortFindCellAr_init(PortFindCellAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(PortFindCell), (Array_clearElement)NULL);
}

static inline int PortFindCellAr_len(PortFindCellAr *arr) {
    return Array_len((Array*)arr);
}

static inline void PortFindCellAr_push(PortFindCellAr *arr, PortFindCell elem) {
    PortFindCell *p = (PortFindCell *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define PortFindCellArFIt_declare(var, arr)  PortFindCellArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool PortFindCellArFIt_next(PortFindCellArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
}

#define TrackAr_foreach(var, arr)  for (TrackArFIt_declare(var, arr); TrackArFIt_next(&var); )            

static inline Track *TrackAr_getp(TrackAr *arr, int index, Error *err) {
    Array_getCheck(arr, index, NULL, err);
    return (Track *)Array_get((Array*)arr, index);
}

static inline void TrackAr_init(TrackAr *arr, int nelems) {
    Array_init((Array*)arr, nelems, sizeof(Track), (Array_clearElement)NULL);
}

static inline int TrackAr_len(TrackAr *arr) {
    return Array_len((Array*)arr);
}

static inline void TrackAr_push(TrackAr *arr, Track elem) {
    Track *p = (Track *)Array_pushN((Array*)arr, 1);
    *p = elem;
    return; 
}            

#define TrackArFIt_declare(var, arr)  TrackArFIt var = {arr, 0, (arr)->len, -1, NULL}

static inline bool TrackArFIt_next(TrackArFIt *iterator) {
    return ArrayFIt_next((ArrayFIt*)iterator);
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

const char *Interface_toString(int itype)
{
    switch(itype) {
        case Undefined_itype:
            return "Undefined";
        case MarshalSi_itype:
            return "MarshalSi";
        case MarshalSii_itype:
            return "MarshalSii";
        case MarshalSs_itype:
            return "MarshalSs";
        case IncrementFrameDispatch_itype:
            return "IncrementFrameDispatch";
        case DecrementFrameDispatch_itype:
            return "DecrementFrameDispatch";
        case SelectNextPushedPadDispatch_itype:
            return "SelectNextPushedPadDispatch";
        case MidiFileDropDispatch_itype:
            return "MidiFileDropDispatch";
        case ManageChokeGroupsDispatch_itype:
            return "ManageChokeGroupsDispatch";
    }
    return "Unknown";
}

#line 14 "src/dispatch.in.c"

#line 33 "src/dispatch.in.c"

#line 41 "src/dispatch.in.c"

#line 49 "src/dispatch.in.c"

#line 57 "src/dispatch.in.c"

#line 119 "src/dispatch.in.c"

#line 127 "src/dispatch.in.c"

#line 135 "src/dispatch.in.c"

#line 143 "src/dispatch.in.c"

#line 151 "src/dispatch.in.c"

#line 159 "src/dispatch.in.c"





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
   sds filename = sdsnew(colon+1);
   Midiseq *mseq = Midiseq_fromfile(filename, err);
   if (Error_iserror(err)) {
     return;
   }
   sdsfree(filename);
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
sds stripBaseName(const char *path);

#line 22 "src/midiseq.in.c"


Port PORT_NULL_IMPL =
{
    {
        0
    }
};

#define Port_null (&PORT_NULL_IMPL)

#line 40 "src/midiseq.in.c"

#line 48 "src/midiseq.in.c"

#line 56 "src/midiseq.in.c"

#line 64 "src/midiseq.in.c"



#line 80 "src/midiseq.in.c"

#line 110 "src/midiseq.in.c"
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

#line 158 "src/midiseq.in.c"


#line 223 "src/midiseq.in.c"


#line 251 "src/midiseq.in.c"

#line 278 "src/midiseq.in.c"

#line 302 "src/midiseq.in.c"

#line 325 "src/midiseq.in.c"

#line 349 "src/midiseq.in.c"
#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


#line 371 "src/midiseq.in.c"

#line 394 "src/midiseq.in.c"


#line 409 "src/midiseq.in.c"

#line 426 "src/midiseq.in.c"

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)


#line 460 "src/midiseq.in.c"

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

#line 581 "src/midiseq.in.c"



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

APIF void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err)
{   
    Symbol *selector = Atom_toSymbol(argv + 0);
    void *out = PtrAr_get(&port->outlet, outletIndex, err);
    Error_returnVoidOnError(err);
    outlet_anything(out, selector, argc-1, argv+1);  
}

APIF void Port_sendInteger(Port *p, int outlet, long value) 
{
    Error_declare(err);
    void *out = PtrAr_get(&p->outlet, outlet, err);
    if (Error_maypost(err)) {
        return;
    }
    outlet_int(out, value);   
}


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
            sdscatprintf(sdsempty(), "Failed to convert int error code %s",
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
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))
APIF Midiseq *Midiseq_new()
{
    Midiseq *midi = Midiseq_newUninitialized();
    midi->sequenceLength = 480*4;
    MEventAr_init(&midi->events, 0);

    MEvent cell = {0};
    cell.t = 0;
    cell.type = Midiseq_endgrptype;
    MEventAr_push(&midi->events, cell);
    
    cell.t = midi->sequenceLength;
    cell.type = Midiseq_cycletype;
    MEventAr_push(&midi->events, cell);

    MEventAr_fit(&midi->events);

    return midi;
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
    Midiseq *mseq = Midiseq_newUninitialized();
    Midiseq_fromBinFileUnititialized(mseq, bf, err);
    if (Error_iserror(err)) {
        sysmem_freeptr(mseq);
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
    Midiseq *mseq = Midiseq_newUninitialized();
    mseq->sequenceLength = 480*4;
    MEventAr_init(&mseq->events, 0);
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


APIF void Midiseq_init(Midiseq *mseq)
{
    if (mseq != NULL) {
        Midiseq zero = {0};
        *mseq = zero;
        MEventAr_init(&mseq->events, 0);
    }
}


APIF void Midiseq_clear(Midiseq *mseq)
{
    if (mseq != NULL) {
        MEventAr_clear(&mseq->events);
        Midiseq zero = {0};
        *mseq = zero;
    }
}


APIF void Midiseq_free(Midiseq *midi)
{
    if (midi != NULL) {
        Midiseq_clear(midi);
        Mem_free(midi);
    }
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
sds Midiseq_midiCsvExecPath = NULL;
sds Midiseq_csvMidiExecPath = NULL;

APIF void Midiseq_setMidicsvExecPath()
{
    if (!Midiseq_pathsAllocated) {
        Midiseq_midiCsvExecPath = sdscatprintf(sdsempty(), "%s/packages/midicsv-1.1/midicsv", CSEQ_HOME);
        Midiseq_csvMidiExecPath = sdscatprintf(sdsempty(), "%s/packages/midicsv-1.1/csvmidi", CSEQ_HOME);
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
APIF int midiseq_tokenize(FILE *fd, int *nfields, sds **fields, Error *err)
{
    char line[Midiseq_maxLineLength] = "";
    char *flag = fgets(line, Midiseq_maxLineLength, fd);
    if (flag == NULL) {
        if (!feof(fd)) {
            Error_format0(err, "Bad IO");
            return 1;
        }
        return -1;
    }
    *fields = sdssplitlen(line, strlen(line), ",", 1, nfields);
    for (int i = 0; i < *nfields; i++) {
        (*fields)[i] = sdstrim((*fields)[i], " ");
    }
    return 0;
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
            while (MEventArRIt_next(&it)) {
                if (cell.t != it.var->t) {
                    break;
                }
            }
            int index = it.index;
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
    sds buffer = sdsempty();
    FILE *fd = NULL;
    int nfields = 0;
    sds *fields = NULL;
    bool allOK = false;
    Midiseq *mseq = (Midiseq*)sysmem_newptrclear(sizeof(Midiseq));
    Midiseq_init(mseq);

    // Call midicsv. To do this we create a new destination file, then route our output to it
    int tempFd = mkstemp(tempfile);
    if (tempFd < 0) {
        Error_format0(err, "Failed to create temp file");
        goto END;
    }
    close(tempFd);

    buffer = sdscatprintf(buffer, "'%s' '%s' > '%s'", Midiseq_midiCsvExecPath, fullpath, tempfile);
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
        int q = midiseq_tokenize(fd, &nfields, &fields, err);
        if (q != 0) {
            if (Error_iserror(err)) {
                goto END;
            }
            break;
        }
        linenum++;

        if (nfields < 3) {
            Error_format(err, "Not enough fields in midicsv file '%s' line %d", tempfile, linenum);
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
                cell.b.b[0]  = (uint8)pitch;
                cell.b.b[1]  = (uint8)velocity;
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
            cell.b.b[0]  = (uint8)cc;
            cell.b.b[1]  = (uint8)val;
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

        // Free anything left over from tokenization
        sdsfreesplitres(fields, nfields);
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
        sdsfree(buffer);
    }
    if (fields != NULL) {
        sdsfreesplitres(fields, nfields);
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

APIF void PortFind_init(PortFind *pf) {
    PortFindCellAr_init(&pf->objects, 0);
}

APIF long PortFind_iterator(PortFind *pf, t_object *targetBox)
{
    t_object *obj = jbox_get_object(targetBox);
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


APIF int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err)
{
    PortFind_setHub(pf, hub);
    PortFind_setAnythingDispatch(pf, (Port_anythingDispatchFunc)Hub_anythingDispatch);
    PortFind_setIntDispatch(pf, (Port_intDispatchFunc)Hub_intDispatch);

    t_object *patcher = NULL;
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

APIF void PortFind_clear(PortFind *pf)
{
    PortFindCellAr_clear(&pf->objects);
}


APIF Port *PortFind_findByVarname(PortFind *pf, Symbol *symbol)
{
    PortFindCellAr_foreach(it, &pf->objects){
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

//
// P A D
//
APIF Pad *Pad_new(){
    Pad *pad = Pad_newUninitialized();
    Pad_init(pad);
    return pad;
}

APIF void Pad_init(Pad *pad)
{
    if (pad != NULL) {
        Pad p = {0};
        *pad = p;
        pad->sequence = Midiseq_new();
        // SequenceAr_init(&pad->sequenceList, 0);
    }
}

APIF void Pad_free(Pad *pad) {
    if (pad != NULL) {
        Pad_clear(pad);
        sysmem_freeptr(pad);
    }
}

APIF void Pad_clear(Pad *pad)
{
    if (pad != NULL) {
        Midiseq_free(pad->sequence);
        // SequenceAr_clear(&pad->sequenceList);
        memset(pad, 0, sizeof(Pad));
    }
}



APIF  void Pad_setSequence(Pad *pad, Midiseq *midi)
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
    Pad *pad = Pad_newUninitialized();
    Pad_fromBinFileUninitialized(pad, bf, err);
    if (Error_iserror(err)) {
        sysmem_freeptr(pad);
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
APIF PadList *PadList_new(int npads)
{
    PadList *pl = PadList_newUninitialized();
    PadList_init(pl, npads);
    return pl;
}

APIF void PadList_init(PadList *pl, int npads) {
    PadAr_init(&pl->pads, npads);
    PadAr_foreach(it, &pl->pads) {
        Pad_init(it.var);
    }
    PadPtrAr_init(&pl->running, 0);
}

APIF void PadList_clear(PadList *pl) {
    if (pl != NULL) {
        PadAr_foreach(it, &pl->pads) {
            Pad_clear(it.var);
        }
        PadAr_clear(&pl->pads);
        PadPtrAr_clear(&pl->running);
    }   
}

APIF void PadList_free(PadList *pl)
{
    if (pl != NULL) {
        PadList_clear(pl);
        Mem_free(pl);
    }
}


APIF void PadList_play(PadList *pl, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    Pad *pad = PadAr_getp(&pl->pads, padIndex, err);
    Error_returnVoidOnError(err);

    // Since we're starting to play, we just recieved a Note-on for this pad. Reset the pad
    Pad_setInEndgroup(pad, false);
    Pad_setNoteReleasePending(pad, true);

    // Now let's find a place to stick this pad into the running array
    PadPtrAr_foreach(it, &pl->running) {
        Pad *p = *it.var;
        if (Pad_chokeGroup(pad) != 0 && Pad_chokeGroup(pad) == Pad_chokeGroup(p)) {
            PadPtrAr_remove(&pl->running, it.index, err);
            Error_returnVoidOnError(err);
            break;
        }
    }

    PadPtrAr_push(&pl->running, pad);

   Midiseq_start(Pad_sequence(pad), startTime, currentTime, false, err);
}


APIF void PadList_markReleasePending(PadList *pl, int padIndex, bool pending, Error *err)
{
    Pad *pad = PadAr_getp(&pl->pads, padIndex, err);
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
    PadList *pl = PadList_new(0);
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

APIF TrackList *TrackList_new(PortFind *pf)
{
    TrackList *tl = TrackList_newUninitialized();
    TrackList_init(tl, pf);
    return tl;
}

APIF void TrackList_init(TrackList *tl, PortFind *pf) {

    TrackAr_init(&tl->list, 0);

    {
        // Insert the null track at position 1 of the tracklist
        Track t = {0};
        t.name  = Symbol_gen("null");
        t.noteManager = NoteManager_new(Port_null);
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
        Track_setNoteManager(&t, NoteManager_new(p));
        TrackAr_push(&tl->list, t);
    }
    Error_clear(err);
    return;
}


APIF void TrackList_clear(TrackList *tl)
{
    TrackAr_foreach(it, &tl->list) {
        NoteManager_free(it.var->noteManager);
    }
    TrackList zero;
    memset(&zero, 0, sizeof(TrackList));
    *tl = zero;
    return;
}

APIF void TrackList_free(TrackList *tl) {
    TrackList_clear(tl);
    Mem_free(tl);
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

    return TrackList_new(pf);
}

APIF void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err) {
    // NO-op since nothing in the tracklist is written to file.
}

//
// D R O P   D O W N
//
#define DropDown_newUnitialized() (DropDown*)sysmem_newptrclear(sizeof(DropDown));

APIF DropDown *DropDown_new(const char **table, PortRef *pr) {
    DropDown *dd = DropDown_newUnitialized();
    DropDown_init(dd, table, pr);
    return dd;
}

APIF void DropDown_init(DropDown *dd, const char **table, PortRef *pr) {
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

APIF void DropDown_initCGLocalGlobal(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "local",
        "global",
        NULL
    };
    DropDown_init(dd, t, pr);
}

APIF void DropDown_initCGInstrument(DropDown *dd, PortRef *pr) {
    const char *t[] = {
        "none",
        "lead",
        "rhythm",
        "piano",
        "bass",
        "drums",
        NULL,
    };
    DropDown_init(dd, t, pr);
}

APIF void DropDown_initCGIndex(DropDown *dd, PortRef *pr) {
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
    DropDown_init(dd, t, pr);
}

APIF void DropDown_clear(DropDown *dd) {
    SymbolPtrAr_clear(&dd->table);
}

APIF void DropDown_free(DropDown *dd) {
    DropDown_clear(dd);
    Mem_free(dd);
}

APIF void DropDown_updateSelected(DropDown *dd, Error *err) {
    Symbol *s = SymbolPtrAr_get(&dd->table, dd->selected, err);
    Error_returnVoidOnError(err);

    Atom a[2] = {{0}};
    atom_setsym(a + 0, Symbol_gen("set"));
    atom_setsym(a + 1, s);
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
    // Atom clear  = {0};
    // Atom append = {0};
    // atom_setsym(&clear, Symbol_gen("clear"));
    // atom_setsym(&append, Symbol_gen("append"));
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

APIF NoteManager *NoteManager_new(Port *port)
{
    NoteManager *nm = (NoteManager*)Mem_malloc(sizeof(NoteManager));
    nm->atoms       = (Atom*)Mem_malloc(sizeof(Atom) * NoteManager_atomcount);
    nm->output      = port;
    TimedOffAr_init(&nm->pending, 0);
    IndexedOffAr_init(&nm->endgroups, 0);
    return nm;
}


APIF void NoteManager_free(NoteManager *nm)
{
    TimedOffAr_clear(&nm->pending);
    IndexedOffAr_clear(&nm->endgroups);
    Mem_free(nm->atoms);
    NoteManager zero; memset(&zero, 0, sizeof(NoteManager));
    *nm = zero;
    Mem_free(nm);
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

APIF Hub *Hub_new(PortFind *pf, Error *err) {
    Hub *hub = Hub_newUninitialized();
    Hub_init(hub, pf, err);
    Error_gotoLabelOnError(err, END);

    return hub;

    END:
    sysmem_freeptr(hub);
    return NULL;
}

APIF void Hub_init(Hub *hub, PortFind *pf, Error *err) {
    Hub_setCurrBankPort(hub, PortFind_findById(pf, Symbol_gen("currBank")));
    Hub_setCurrFramePort(hub, PortFind_findById(pf, Symbol_gen("currFrame")));
    Hub_setSelBankPort(hub, PortFind_findById(pf, Symbol_gen("selBank")));
    Hub_setSelFramePort(hub, PortFind_findById(pf, Symbol_gen("selFrame")));
    Hub_setSelPadPort(hub, PortFind_findById(pf, Symbol_gen("selPad")));


    Port *cg = PortFind_findById(pf, Symbol_gen("chokeGroup"));
    PortRef_declare(portRef, cg, 0);
    DropDown_initCGLocalGlobal(Hub_cgLocalGlobalMenu(hub), portRef);

    PortRef_set(portRef, cg, 1);
    DropDown_initCGInstrument(Hub_cgInstrumentMenu(hub), portRef);

    PortRef_set(portRef, cg, 2);
    DropDown_initCGIndex(Hub_cgIndexMenu(hub), portRef);

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

APIF void Hub_free(Hub *hub) {
    PadList_free(Hub_padList(hub));
    TrackList_free(Hub_trackList(hub));
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
    Hub *hub = Hub_newUninitialized();
    Hub_fromBinFileUninitialized(hub, bf, err);
    if (Error_iserror(err)) {
        Hub_free(hub);
        return NULL;
    }
    return hub;
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

APIF BinFile *BinFile_new() {
    BinFile *bf = (BinFile*)sysmem_newptrclear(sizeof(BinFile));
    BinFile_setFilename(bf, sdsempty());
    BinFile_setBuffer(bf, sdsempty());
    return bf;
}

APIF BinFile *BinFile_newWriter(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_setStream(bf, fopen(file, "w"));
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    sdsfree(BinFile_filename(bf));
    BinFile_setFilename(bf, sdsnew(file));

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
    BinFile_setFilename(bf, sdsnew(file));
    if (fscanf(BinFile_stream(bf), "%d ", &bf->version)) {
        Error_format(err, "Failed to read version number from file  %s", file);
        BinFile_free(bf);
        return NULL;
    }
    return bf;
}

APIF void BinFile_free(BinFile *bf) {
    if (BinFile_stream(bf) != NULL) {
        fclose(BinFile_stream(bf));
        BinFile_setStream(bf, NULL);
    }
    
    sdsfree(BinFile_filename(bf));
    BinFile_setFilename(bf, NULL);
    sdsfree(BinFile_buffer(bf));
    BinFile_setBuffer(bf, NULL);
    sysmem_freeptr(bf);
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
    if (sdslen(BinFile_buffer(bf)) < size) {
        // NOTE: I verified that this call DOES NOT shrink the buffer.
        // NOTE: sdsMakeRoomFor always allocates sdslen()+1 bytes  
        BinFile_setBuffer(bf, sdsgrowzero(BinFile_buffer(bf), (size_t)size));
    }
    sdssetlen(BinFile_buffer(bf), size);
    if (fread(BinFile_buffer(bf), size, 1, BinFile_stream(bf)) != size) {
        Error_format(err, "Failed fread while working with %s", BinFile_filename(bf));
        return;   
    }
    // NOTE: this means that the buffer can be used like a string in the correct context. IT DOES NOT say that there aren't
    // other nulls embedded in the string. I think that the way I'm preparing this string, there might be 2 nulls at the end
    // of it. 
    BinFile_buffer(bf)[size] = '\0';
}

APIF void BinFile_writeInteger(BinFile *bf, long value, Error *err) {
    sdsclear(BinFile_buffer(bf));
    sdscatprintf(BinFile_buffer(bf), "%ld", value);
    
    BinFile_writeLength(bf, sdslen(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 0, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
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

APIF void BinFile_writeString(BinFile *bf, sds value, Error *err) {
    BinFile_writeLength(bf, sdslen(value), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

}

// must call sdsfree on any non-NULL return value
APIF sds BinFile_readString(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);    
    
    return sdsdup(BinFile_buffer(bf));
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
    sdsclear(BinFile_buffer(bf));
    sdscatprintf(BinFile_buffer(bf), "%lld", value);

    BinFile_writeLength(bf, sdslen(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
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





