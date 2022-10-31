#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *result = (unsigned char*)s + (int)n - 1;
    for (size_t i = 0; i < n; i++) {
        if (*result == c)
            return result;
        result--;
    }
    return NULL;
}

