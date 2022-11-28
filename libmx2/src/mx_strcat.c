#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int l1 = mx_strlen(s1);
    int l2 = mx_strlen(s2);
    for(int a = l1; a < l1 + l2 + 1; a++)
        s1[a] = s2[a - l1];
    return s1;
}

