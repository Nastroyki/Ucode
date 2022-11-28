#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int f = 0;
    int a;
    for (a = 0; haystack[a] != '\0'; a++) {
        f = 1;
        for(int b = 0; needle[b] != '\0'; b++) {
            if (haystack[a + b] != needle[b])
                f = 0;
        }
        if (f == 1)
            return (char*)&haystack[a];
    }
    return (char*)&haystack[a];
}

