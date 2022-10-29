#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *result;
    if (str == 0)
        return 0;
    result = mx_strnew(mx_strlen(str));
    return mx_strcpy(result, str);
}

