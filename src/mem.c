#include <stdlib.h>


#ifdef TEST_SEQUENCER
// 
// T e s t i n g   M e m o r y  F u n c t i o n s
//

void *Mem_reallocFull(void *ptr, size_t size, const char *file, int line) {
	void *raw           = NULL;
	size_t previousSize = 0;
	if (ptr != NULL) {
		raw          = ptr-sizeof(size_t);
		previousSize = *((size_t*)raw);
	}

	raw = realloc(raw, size + sizeof(size_t));
	if (raw == NULL) {
		return NULL;
	}

	// NOTE: size DOES not include the size of the capacity
	*((size_t*)raw) = size;
	if (size > previousSize) {
		memset(raw+sizeof(size_t)+previousSize, 0, size-previousSize);
	}

	return raw + sizeof(size_t);
}

void Mem_freeFull(void *ptr, const char *file, int line) {
	if (ptr != NULL) {
		void *raw = ptr-sizeof(size_t);
		free(raw);
	}
}

#define Mem_realloc(ptr, size) Mem_reallocFull((ptr), (size), __FILE__, __LINE__)
#define Mem_malloc(size)       Mem_reallocFull(NULL,  (size), __FILE__, __LINE__)
#define Mem_free(ptr)          Mem_freeFull((ptr), __FILE__, __LINE__)

#else

//
// M a x   M e m o r y   F u n c t i o n s 
//
#define Mem_malloc(size)       (void*)sysmem_newptr(size)
#define Mem_realloc(ptr, size) (void*)sysmem_resizeptr((ptr), (size))
#define Mem_free(ptr)          sysmem_freeptr(ptr)
#endif 