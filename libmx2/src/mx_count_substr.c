#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }
    if (sub[0] == '\0')
        return 0;
    int result = 0;
    char *a = (char*)&str[0];
    while (1 > 0) {
        if (*mx_strstr(a, sub) != '\0') {
            result++;
            a = mx_strstr(a, sub) + 1;
        }
        else
            break;
    }
    return result;
}

