#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!*head || !head) {
        return;
    }
    t_list *cur = *head;
    if (cur->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    while (cur->next->next != NULL)
        cur = cur->next;
    free(cur->next);
    cur->next = NULL;
}

