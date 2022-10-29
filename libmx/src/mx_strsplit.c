#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    char **result;
    int countword = -1;
    int beg;
    int end = 0;
    if (s == NULL)
        return NULL;
    result = malloc((mx_count_words(s, c) + 1) * sizeof(char*));
    while (1) {
        for(beg = end; s[beg] == c; beg++) {}
        for(end = beg; s[end] != c && s[end] != '\0'; end++) {}
        if (s[beg] == '\0')
            break;
        countword++;
        result[countword] = mx_strnew(end - beg);
        mx_strncpy(result[countword], &s[beg], end - beg);
    }
    countword++;
    result[countword] = NULL;
    return result;
}

