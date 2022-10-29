#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!arr)
        return -1;
    int min = 0;
    int max = size - 1;
    while (min <= max) {
        (*count)++;
        if (mx_strcmp(arr[(min + max) / 2], s) == 0)
            return (min + max) / 2;
        else if (mx_strcmp(arr[(min + max) / 2], s) < 0)
            min = (min + max) / 2 + 1;
        else if (mx_strcmp(arr[(min + max) / 2], s) > 0)
            max = (min + max) / 2 - 1;
    }
    *count = 0;
    return -1;
}

