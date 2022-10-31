#include "../inc/libmx.h"

void mx_print_arr_int(const int *arr, int size) {
    for (int a = 0; a < size; a++) {
        mx_printint(arr[a]);
        mx_printchar('\n');
    }
}

