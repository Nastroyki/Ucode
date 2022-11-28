#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (!list) return list;
    int count = 1;
    t_list *cur = list;
    while (cur->next != NULL) {
        cur = cur->next;
        count++;
    }
    int f = 1;
    while (1) {
        f = 0;
        cur = list;
        if(cmp(list->data, list->next->data)) {
            list = list->next;
            cur->next = list->next;
            list->next = cur;
            f = 1;
        }
        cur = list;
        for (int a = 0; a < count - 2; a++) {
            if (cmp(cur->next->data, cur->next->next->data)) {
                t_list *buff = cur->next;
                cur->next = buff->next;
                buff->next = cur->next->next;
                cur->next->next = buff;
                f = 1;
            }
            cur = cur->next;
        }
        if (f == 0)
            break;
    }
    return list;
}

