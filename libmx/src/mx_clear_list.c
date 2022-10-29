#include "../inc/libmx.h"

void mx_clear_list(t_list **list) {
    while (1) {
        t_list *cur = *list;
        if(!cur->next) {
            free(cur);
            *list = NULL;
            return;
        }
        *list = cur->next;
        free(cur);
    }
}

