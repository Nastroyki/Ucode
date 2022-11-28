#include "../inc/libmx.h"

void mx_foreach_list(t_list *list, void(*f)(t_list *node)) {
    if (!list) return;
    while (list->next != NULL) {
        f(list);
        list = list->next;
    }
    f(list);
}

