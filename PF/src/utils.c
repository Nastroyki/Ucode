#include "../inc/header.h"

void del_nodes(t_node *nodes, int count_of_nodes) {
    for (int i = 0; i < count_of_nodes; i++)
		mx_strdel(&(nodes[i].name));
}

int atoi_mod(const char *str, int len) {
    if (str == 0)
        return -1;
    int result = 0;
    for (int a = 0; a < len ; a++) {
        if ((str[a] >= 48) && (str[a] <= 57)) {
            result *= 10;
            if (result % 10 != 0) {
                return -1;
            }
            result += (int)str[a] - 48;
        }
        else {
            return -1;
        }
    }
    return result;
}

void line_err(int line) {
    mx_printerr("error: line ");
    mx_printerr_int(line);
    mx_printerr(" is not valid\n");
}

bool is_wrong(char *str) {
    bool delim1 = false; // '-'
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!(((str[i] >= 65) && (str[i] <= 90)) 
            || ((str[i] >= 97) && (str[i] <= 122)))) {
            if ((!delim1) && str[i] == '-') {
                delim1 = true;
            }
            else if (str[i] == ',') {
                return false;
            }
            else {
                return true;
            }
        }
    }
    return false;
}

void mx_del_names(char **arr) {
    for (int i = 0; arr[i] != NULL; i++)
		mx_strdel(&arr[i]);
}

