
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

