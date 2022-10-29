#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    if (!list) return 0;
    int result = 1;
    while (list->next != NULL) {
        list = list->next;
        result++;
    }
    return result;
}

