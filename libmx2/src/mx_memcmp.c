#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n == 0) return 0;
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;
    size_t i;
    for (i = 0; i < n && str1[i] == str2[i]; i++) {
        if (str1[i] == '\0' && str2[i] == '\0')
            return 0;
    }
    return str1[i] - str2[i];
}

