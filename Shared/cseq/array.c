

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

typedef void (*Array_clearElement)(void *);
typedef struct Array_t {
   int len;
   int cap;
   int elemSize;
   Array_clearElement clearer;
   char *data;
} Array;

typedef struct ArrayIter {
   Array *arr;
   int index;
   char *element;
} ArrayIter;

ArrayIter ArrayIter_create(Array *arr) {
   ArrayIter iter = {arr, 0, NULL};
   return iter;
}



bool ArrayIter_continue(ArrayIter *iterator) {
   if (iterator->index < 0 || iterator->index >= Array_len(iterator->arr)) {
      return false;
   }
   iterator->elem = Array_get(iterator->arr, iterator->index);
   iterator->index++;
   return true;
}

#define ArrayIter_declare(name) ArrayIter _##name = {0}; ArrayIter *name = &_##name
#define Array_foreach(variableName, arr) 
   for (ArrayIter variableName = ArrayIter_create(arr); ArrayIter_continue(&variableName);)
   
typedef struct FooArrIter {
   Array *arr;
   int index;
   Foo *element;
} FooArrIter;

#define FooArr_foreach(variableName, arr) for (FooArrIter variableName = (FooArrIter)ArrayIter_create(arr); ArrayIter_continue(&variableName);)



  


// REMEMBER: when you specify a range of elements to operate on, always select the range as
// [start, end) : here start is the first index of the subsequence, and end is ONE-PAST the last
// index of the subsequence. With this, the number of elements in the subsequence is end-start.

#define Array_formatIndexError(err, m, n, o) Error_format((err), "Index out of range (%d, %d, %d)", (m), (n), (o))

Array *Array_new(int nelems, int elemSize, Array_clearElement clearer) {
   Array *arr = (Array*)sysmem_newptrclear(sizeof(Array));
   Array_init(arr, nelems, elemSize, clearer);
   return arr;
}

void Array_init(Array *arr, int nelems, int elemSize, Array_clearElement clearer) {
   a->elemSize = elemSize;
   a->len      = nelems;
   a->cap      = nelems;
   a->clearer  = clearer;
   if (nelems > 0) {
      a->data = (char*)sysmem_newptrclear(nelems*elemSize); 
   } 
}

void Array_clear(Array *arr) {
   Array_truncate(arr);
   sysmem_freeptr(arr->data);
}

void Array_free(Array *arr) {
   Array_clear(arr);
   sysmem_freeptr(arr);
}

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



void Array_truncate(Array *arr) {
   if (arr->clearer != NULL) {
      char *start = arr->data;
      char *end   = arr->data + arr->len;
      for (char *p = start; p != end; p += arr->elemSize) {
         arr->clearer(p);
      }
   }
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
   
   if (arr->clearer != NULL) {
      for (char *p = subStart; p != subEnd; p += arr->elemSize) {
            arr->clearer(p);
      }
   }

   memmove(subStart, subEnd, (size_t)(arrayEnd-subEnd));
   memset(arrayStart, 0,     (size_t)(arrayEnd-arrayStart))
   return;
}

void Array_fit(Array *arr) {
   int szBytes       = arr->len*arr->elemSize;
   arr->data         = (char*)sysmem_resizeptrclear(arr->data, szBytes);
   arr->cap          = arr->len;
}


//
// Tree is not a binary tree! It's a binary searchable array. But, it has the interface that looks like a tree
//
typedef int (*Tree_compare)(void *left, void *right);
typedef int (*Tree_freeFunction)(void *);
typedef struct Tree_t {
   int keySize;
   int valueSize;
   Tree_compare comparer;
   Tree_freeFunction keyFree;
   Tree_freeFunction valueFree;
   Array arr;
} Tree;

Tree *Tree_new(int keySize, int valueSize, Tree_compare comparer, Tree_freeFunction keyFree, Tree_freeFunction valueFree) {
   Tree *t      = (Tree*)sysmem_newptrclear(sizeof(Tree))
   t->keySize   = keySize;
   t->valSize   = valueSize;
   t->comparer  = comparer
   t->keyFree   = keyFree;
   t->valueFree = valueFree
   Array_init(&t->arr, 0, t->keySize+t->valSize, NULL);
   return t;
}

void Tree_free(Tree *tree) {
   if (tree->keyFree != NULL || tree->valueFree != NULL) {
      for (int i = 0; i < Array_len(tree->arr); i++) {
         char *p = Array_get(&tree->arr, i);
         if (tree->keyFree != NULL) {
            tree->keyFree(p);
            p += tree->keySize;
         }
         if (tree->valueFree != NULL) {
            tree->valueFree(p);
         }
      }
   }
   Array_free(&tree->arr);
}

#define Tree_setInsert(value) do {\
   if (insert != NULL) {\
      *insert = (value);\
   }\
} while (0)

int Tree_searchIndex(Tree *tree, char *keyTarget, int *insert) {
   if (Array_len(&tree->arr) <= 0) {
      Tree_setInsert(0);
      return -1
   } 

   if (Array_len(&tree->arr) == 1) {
      int oneRes = arr->comparer(keyTarget, Array_get(&tree->arr, 0));
      if (oneRes < 0) {
         Tree_setInsert(0);
         return -1  
      }  else if (oneRes > 0) {
         Tree_setInsert(1);
         return -1  
      } else {
         return 0;
      }
   }

   int low    = 0;
   int lowRes = arr->comparer(keyTarget, Array_get(&tree->arr, low));
   if (lowRes <= 0) {
      if (lowRes < 0) {
         Tree_setInsert(0);         
         return -1;
      } else { // lowRes == 0
         return low;
      }
   }

   int hgh = Array_len(&tree->arr) - 1;
   int hghRes = arr->comparer(keyTarget, Array_get(&tree->arr, hgh));
   if (hghRes >= 0) {
      if (hghRes > 0) { 
         Tree_setInsert(Array_len(&tree->arr));
         return -1;
      } else { // hghRes == 0
         return hgh;
      }
   }

   // At this point we have >= 2 elements in the array, and we've bracketed the solution from below and above.
   int mid    = 0;
   while(low <= hgh) {
      mid       = (low + hgh)/2;
      char *key = Array_get(&tree->arr, mid);
      int res   = arr->comparer(keyTarget, key);
      if (res == 0) {
         return mid;
      } else if (res > 0) {
         // keyTarget > key
         hgh = mid-1;
      } else {// res < 0
         // keyTarget < key
         low = mid+1;
      }
   }
   Tree_setInsert(hgh+1);
   return -1;
}
#undef Tree_setInsert


// Returns the value associated with key, or NULL
char *Tree_get(Tree *tree, char *key) {
   int index = Tree_searchIndex(tree, key, NULL);
   if (index < 0) {
      return NULL;
   }
   return Array_get(&tree->arr, index) + tree->keySize;
}

void Tree_set(Tree *tree, char *key, char *value) {
   int insert = -1;
   int index  = Tree_searchIndex(tree, key, &insert);
   if (index < 0) {
      char *p = Array_insertN(&tree->arr, insert);
      if (tree->keySize > 0) {
         memmove(p, key, tree->keySize);
         p += tree->keySize;
      }
      if (tree->valueSize > 0) {
         memmove(p, value, tree->valueSize)
      }
   } else {
      char *p = Array_get(&tree->arr, index) + tree->valueSize;
      if (tree->valueFree != NULL) {
         tree->valueFree(p);
      }
      memmove(p, value, tree->valueSize);
   }
}

void Tree_pushUnsorted(Tree *tree, char *key, char *value) {
   // char *Array_pushN(Array *arr, int N) {
   char *p = Array_pushN(&tree->arr, 1);
   if (tree->keySize > 0) {
      memmove(p, key, tree->keySize);
      p += tree->keySize;
   }
   if (tree->valueSize > 0) {
      memmove(p, value, tree->valueSize);
   }
}

void Tree_sort(Tree *tree, Error *err) {
   qsort(Array_data(&tree->arr), Array_len(&tree->arr), tree->keySize + tree->valueSize, tree->comparer);
   for (int i = 1; i < Array_len(&tree->arr); i++) {
      char *m = Array_get(&tree->arr, i-1);
      char *n = Array_get(&tree->arr, i);
      if (tree->comparer(m, n) >= 0) {
         Error_format(err, "Tree_sort found inconsistant array");
         return;
      }
   }
}

#define Tree_foreach(keyName, valueName, tree) \
   char *keyName = NULL, *valueName = NULL; ArrayIter_declare(keyName##valueName##iterator); while (Tree_nextIterator(tree, iteratorName, &keyName, &valueName))


bool Tree_nextIterator(Tree *tree, ArrayIter *iterator, char **key, char **value) {
   char *p = NULL;
   if (!Array_nextIterator(tree->arr, iterator, &p)) {
      *key   = NULL;
      *value = NULL;
      return false;
   }

   *key   = p;
   *value = p + tree->keySize;
   return true;
}

