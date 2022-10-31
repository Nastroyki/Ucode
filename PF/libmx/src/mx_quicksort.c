#include "../inc/libmx.h"

static void swap_elem(char **arr, int a, int b) {
    char *t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }
    int swaps = 0;
    if (left < right) {
        int l = left;
        int r = right;
        int piv = left + right / 2;
        while (l < r) {
            while (mx_strlen(arr[l]) < mx_strlen(arr[piv])) l++;
            while (r > left && mx_strlen(arr[r]) >= mx_strlen(arr[piv])) r--;
            if (l < r) {
                swap_elem(arr, l, r);
                swaps++;
            }
        }
        if (l != piv) {
            swap_elem(arr, l, piv);
            swaps++;
        }
        swaps += mx_quicksort(arr, left, l - 1);
        swaps += mx_quicksort(arr, l + 1, right);
    }
    return swaps;
}

