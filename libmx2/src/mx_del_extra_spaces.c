#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str || str[0] == '\0') {
        return NULL;
    }
    char *result;
    int counter = 0;
    char *trim = mx_strtrim(str);
    int len = 0;
    if (trim == NULL)
        return 0;
    for (int a = 0; a < mx_strlen(trim); a++)
        if ((mx_isspace(trim[a]) 
             && !mx_isspace(trim[a + 1])) 
             || !mx_isspace(trim[a]))
            len++;
    result = mx_strnew(len);
    for (int a = 0; a < mx_strlen(trim); a++) {
        if (mx_isspace(trim[a]) 
            && !mx_isspace(trim[a + 1]))
            result[counter++] = ' ';
        if (!mx_isspace(trim[a]))
            result[counter++] = trim[a];
    }
    mx_strdel(&trim);
    return result;
}

