#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *result;
    if (s1 == 0 && s2 == 0)
        return 0;
    if (s1 == 0)
        return mx_strdup(s2);
    if (s2 == 0)
        return mx_strdup(s1);
    result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcpy(result, s1);
    mx_strcat(result, s2);
    return result;
}

