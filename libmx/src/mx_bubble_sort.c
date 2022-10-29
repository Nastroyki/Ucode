#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int result = 0;
    int f = 1;
    char *buff;
    while (1 > 0) {
        f = 0;
        for (int a = 0; a < size - 1; a++) {
            if (mx_strcmp(arr[a], arr[a + 1]) > 0) {
                buff = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = buff;
                result++;
                f = 1;
            }
        }
        if (f == 0)
            break;
    }
    return result;
}

