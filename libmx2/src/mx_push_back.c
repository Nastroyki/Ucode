#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list *cur = *list;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = mx_create_node(data);
}

