#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (!str || str[0] == '\0') {
        return NULL;
    }
    int beg;
    int end;
    char *result;
    for (beg = 0; beg < mx_strlen(str); beg++)
        if (!mx_isspace(str[beg]))
            break;
    for (end = mx_strlen(str) - 1; end >= 0; end--)
        if (!mx_isspace(str[end]))
            break;
    if (beg > end)
        return NULL;
    result = mx_strnew(end - beg + 1);
    mx_strncpy(result, &str[beg], end - beg + 1);
    return result;
}
