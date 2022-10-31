#include "../inc/header.h"

int input_count_of_nodes(int argc, char *argv[]) {
    if (argc != 2){
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
    int f = open(argv[1], O_RDONLY);
    if (f < 0) {
        close(f);
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
		exit(0);
    }
    int result = 0;
    int len = 0;
    int len_digits = 0;
    bool digits = true;
    char c;
    int info = read(f, &c, 1);
    while (info > 0) {
        if (digits) {
            if (c == '\n') {
                digits = false;
            } else {
                len_digits++;
            }
        }
        info = read(f, &c, 1);
        len++;
    }
    close(f);
    if (len == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
		exit(0);
    }
    if (len_digits == 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    f = open(argv[1], O_RDONLY);
    char str[len_digits];
    read(f, str, len_digits);
    close(f);

    result = atoi_mod(str, len_digits);
    if (result < 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    return result;
}

char *read_str(char *file_n, int n, bool *final) {
    char c;
    int f = open(file_n, O_RDONLY);
    int len = 0;
    for (int i = 1; i < n; i++) {
        read(f, &c, 1);
        while (c != '\n') {
            read(f, &c, 1);
        }
    }
    int info = read(f, &c, 1);
    while (info > 0) {
        if (c == '\n') {
            break;
        }
        info = read(f, &c, 1);
        len++;
    }
    if (read(f, &c, 1) <= 0) {
        *final = true;
    }
    close(f);
    char *result = mx_strnew(len);
    f = open(file_n, O_RDONLY);
    len = 0;
    for (int i = 1; i < n; i++) {
        read(f, &c, 1);
        while (c != '\n') {
            read(f, &c, 1);
        }
    }
    read(f, &c, 1);
    while (c != '\n') {
        result[len] = c;
        len++;
        int info = read(f, &c, 1);
        if (info <= 0) {
            break;
        }
    }
    close(f);
    return result;
}

void input_map(char *file_n, t_node *nodes, int *map, int count_of_nodes) {
    int sum_bridges = 0;
    int line = 2;
    bool final = false;
    char *names[count_of_nodes + 1];
    for (int i = 0; i <= count_of_nodes; i++) {
        names[i] = NULL;
    }
    for (int i = 0; i < count_of_nodes * count_of_nodes; i++) {
        map[i] = -1;
    }
    // filling names:
    int empty = 0;
    while (!final) {
        char *str = read_str(file_n, line, &final); // whithout \n (whith \0) dinamic!!!
        int name1_len = mx_get_char_index(str, '-');
        int name2_len = mx_get_char_index(str, ',');
        name2_len -= name1_len + 1;
        if (name1_len < 1 || name2_len < 1 || is_wrong(str)
            || mx_strncmp(&(str[name1_len + 1]), str, name1_len) == 0) {
            line_err(line);
            mx_strdel(&str);
            mx_del_names((char**)names);
            exit(0);
        }
        // name1 check:
        bool nothing = true;
        for (int i = 0; i < count_of_nodes; i++) {
            if (names[i] != NULL) {
                if (mx_strncmp(str, names[i], name1_len) == 0) {
                    nothing = false;
                    break;
                }
            }
        }
        if (nothing) {
            if (empty < count_of_nodes) {
                names[empty] = mx_strndup(str, name1_len);
                empty ++;
            }
            else {
                mx_printerr("error: invalid number of islands\n");
                mx_strdel(&str);
                mx_del_names((char**)names);
                exit(0);
            }
        }
        // name2 check:
        nothing = true;
        for (int i = 0; i < count_of_nodes; i++) {
            if (names[i] != NULL) {
                if (mx_strncmp(&(str[name1_len + 1]), names[i], name2_len) == 0) {
                    nothing = false;
                    break;
                }
            }
        }
        if (nothing) {
            if (empty < count_of_nodes) {
                names[empty] = mx_strndup(&(str[name1_len + 1]), name2_len);
                empty ++;
            }
            else {
                mx_printerr("error: invalid number of islands\n");
                mx_strdel(&str);
                mx_del_names((char**)names);
                exit(0);
            }
        }
        mx_strdel(&str);
        line++;
    }
    //mx_bubble_sort(names, count_of_nodes); if you need not FIFO
    for (int i = 0; i < count_of_nodes; i++) {
        nodes[i].name = names[i];
    }
    // filing the map
    line = 2;
    final = false;
    while (!final) {
        int bridge;
        int node1;
        int node2;
        char *str = read_str(file_n, line, &final); // whithout \n (whith \0) dinamic!!!
        int name1_len = mx_get_char_index(str, '-');
        int name2_len = mx_get_char_index(str, ',');
        int num_index = mx_get_char_index(str, ',') + 1;
        int num_len = mx_strlen(str) - num_index;
        name2_len -= name1_len + 1;
        if (num_len < 1) {
            line_err(line);
            mx_strdel(&str);
            del_nodes(nodes, count_of_nodes);
            exit(0);
        }
        bridge = atoi_mod(&(str[num_index]), num_len);
        if (bridge < 0) {
            line_err(line);
            mx_strdel(&str);
            del_nodes(nodes, count_of_nodes);
            exit(0);
        }

        if (sum_bridges >= 0) {
            sum_bridges += bridge;
        }

        for (node1 = 0; node1 < count_of_nodes; node1++) {
            if (mx_strncmp(str, nodes[node1].name, name1_len) == 0) {
                break;
            }
        }
        for (node2 = 0; node2 < count_of_nodes; node2++) {
            if (mx_strncmp(&(str[name1_len + 1]), nodes[node2].name, name2_len) == 0) {
                break;
            }
        }
        if (map[node1 * count_of_nodes + node2] == -1) {
            map[node1 * count_of_nodes + node2] = bridge;
            map[node2 * count_of_nodes + node1] = bridge;
        }
        else {
            del_nodes(nodes, count_of_nodes);
            mx_printerr("error: duplicate bridges\n");
            mx_strdel(&str);
            exit(0);
        }
        mx_strdel(&str);
        line++;
    }
    if (sum_bridges < 0) {
        del_nodes(nodes, count_of_nodes);
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
}

