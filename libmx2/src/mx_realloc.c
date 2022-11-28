#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (!size) {
        return NULL;
    }
	if (size <= malloc_size(ptr))
	    return ptr;
    void *new_data;
	if(!ptr)
		return (void *)malloc(size);
	new_data = (void *)malloc(size);
	if(new_data) {
		mx_memcpy(new_data, ptr, size);
		free(ptr);
	}
    return new_data;
}

