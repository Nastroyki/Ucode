#include "../inc/header.h"

int main(int argc, char *argv[]) {
    int count_of_nodes = input_count_of_nodes(argc, argv);

    int map[count_of_nodes * count_of_nodes];
    t_node nodes[count_of_nodes];
    
    input_map(argv[1], nodes, (int*)map, count_of_nodes);

    for (int p_from = 0; p_from < count_of_nodes; p_from++) {
        for (int p_to = p_from + 1; p_to < count_of_nodes; p_to++) {

            char *info_PR = mx_strnew(59 + (mx_strlen(nodes[p_from].name) * 2) + mx_strlen(nodes[p_to].name));
            mx_strcpy(info_PR, "========================================\nPath: ");
            mx_strcat(info_PR, nodes[p_from].name);
            mx_strcat(info_PR, " -> ");
            mx_strcat(info_PR, nodes[p_to].name);
            mx_strcat(info_PR, "\nRoute: ");
            mx_strcat(info_PR, nodes[p_from].name);
            char *info_D = mx_strnew(11);
            mx_strcpy(info_D, "\nDistance: ");

            dijkstra(p_to, nodes, (int*)map, count_of_nodes);

            t_info info;
            info.count_of_nodes = count_of_nodes;
            info.p_from = p_from;
            info.p_to = p_to;
            info.sum = nodes[p_from].len;
            info_PR = find_path(info_PR, info_D, nodes, (int*)map, info);
            mx_printstr(info_PR);
            
            mx_strdel(&info_PR);
        }
    }
    del_nodes(nodes, count_of_nodes);
    return 0;
}

