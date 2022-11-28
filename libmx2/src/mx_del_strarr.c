#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
    for (int i = 0; (*arr)[i] != NULL; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free(*arr);
    *arr = NULL;
}

