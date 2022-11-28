#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *result;
    if (!str || str[0] == '\0') {
        return NULL;
    }
    result = mx_strnew(mx_strlen(str));
    return mx_strcpy(result, str);
}

