#include "../inc/header.h"

int get_index_current_path(char *str) {
    int len = 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\n') {
            len++;
        }
    }
    if (len == 1) return 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\n') {
            len--;
            if (len == 2) {
                return i + 1;
            }
        }
    }
    return 0;
}

char *find_path(char *PR, char *D,
               t_node *nodes, int *map, t_info info) {
    if (info.p_from == info.p_to) {
        int cnbr = info.sum;
        int len;
        for (len = 0; cnbr > 0; len++)
            cnbr /= 10;
        cnbr = info.sum;
        char sum[len + 1];
        sum[len] = '\0';
        for (int a = 1; cnbr > 0; a++) {
            sum[len - a] = cnbr % 10 + 48;
            cnbr /= 10;
        }
        char *new_PR;
        new_PR = mx_strnew(mx_strlen(PR) + mx_strlen(D) + len + 42);
        mx_strcpy(new_PR, PR);
        mx_strcat(new_PR, D);
        mx_strcat(new_PR, sum);
        mx_strcat(new_PR, "\n========================================\n");
        mx_strdel(&PR);
        mx_strdel(&D);
        return new_PR;
    }
    char *old_PR = mx_strdup(&(PR[get_index_current_path(PR)]));

    bool first_iter = true;
    for (int i = 0; i < info.count_of_nodes; i++) {
        
        if (nodes[info.p_from].len - nodes[i].len == 
            map[info.p_from * info.count_of_nodes + i]
            && map[info.p_from * info.count_of_nodes + i] != -1) {
            if (!first_iter) {
                char *buf_PR = mx_strjoin(PR, old_PR);
                mx_strdel(&PR);
                PR = buf_PR;
            }
            char *new_PR;
            new_PR = mx_strnew(4 + mx_strlen(nodes[i].name) + mx_strlen(PR));
            mx_strcpy(new_PR, PR);
            mx_strcat(new_PR, " -> ");
            mx_strcat(new_PR, nodes[i].name);
            mx_strdel(&PR);

            int cnbr = map[info.p_from * info.count_of_nodes + i];
            int len;
            for (len = 0; cnbr > 0; len++)
                cnbr /= 10;
            cnbr = map[info.p_from * info.count_of_nodes + i];
            char bridge[len + 1];
            bridge[len] = '\0';
            for (int a = 1; cnbr > 0; a++) {
                bridge[len - a] = cnbr % 10 + 48;
                cnbr /= 10;
            }
            char *new_D;
            if (i == info.p_to && info.sum == nodes[info.p_from].len) {
                new_D = mx_strdup(D);
            }
            else {
                new_D = mx_strnew(3 + len + mx_strlen(D));
                mx_strcpy(new_D, D);
                mx_strcat(new_D, bridge);
                if (i == info.p_to)
                    mx_strcat(new_D, " = ");
                else
                    mx_strcat(new_D, " + ");
            }
            t_info new_info;
            new_info.sum = info.sum;
            new_info.count_of_nodes = info.count_of_nodes;
            new_info.p_from = i;
            new_info.p_to = info.p_to;
            PR = find_path(new_PR, new_D, nodes, map, new_info);
            first_iter = false;
        }
    }
    mx_strdel(&old_PR);
    mx_strdel(&D);
    return PR;
}

