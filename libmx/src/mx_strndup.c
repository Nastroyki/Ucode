#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *result;
    if (s1 == 0)
        return 0;
    result = mx_strnew(n);
    for(unsigned long counter = 0; counter < n; counter++) {
        result[counter] = s1[counter];
    }
    return result;
}

