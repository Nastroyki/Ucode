#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char* b = (unsigned char*)big;
    unsigned char* l = (unsigned char*)little;
    if(big_len < little_len || big_len <= 0 || little_len <= 0) {
        return NULL;
    }
    while (*b) {
        if (mx_memcmp(b, l, little_len - 1) == 0)
            return b;
        b++;
    }
    return NULL;
}

