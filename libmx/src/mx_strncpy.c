#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	int f = 0;
    int a;
    int dlen = mx_strlen(dst);
    for (a = 0; a < len; a++) {
        if (f == 0) {
            if (src[a] == '\0')
                f = 1;
            dst[a] = src[a];
        }
        else
            dst[a] = '\0';
    }
    for (int i = a; i < dlen; i++) {
        dst[i] = '\0';
    }
    return dst;
}

