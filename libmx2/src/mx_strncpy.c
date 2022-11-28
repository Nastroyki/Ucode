#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int a = 0; a < len; a++) {
        dst[a] = src[a];
        if (src[a] == '\0')
            return dst;
    }
    return dst;
}

