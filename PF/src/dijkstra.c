#include "../inc/header.h"

void dijkstra(int s_point, t_node *nodes, int *map, int count_of_nodes) {
    bool block[count_of_nodes];
    for (int i = 0; i < count_of_nodes; i++) {
        nodes[i].len = 2147483647;
        block[i] = false;
    }
    nodes[s_point].len = 0;
    int current = s_point;
    for (int a = 0; a < count_of_nodes; a++) {
        block[current] = true;
        for (int i = 0; i < count_of_nodes; i++) {
            if (map[current * count_of_nodes + i] != -1) {
                if (nodes[i].len > map[current * count_of_nodes + i] + nodes[current].len && !block[i]) {
                    nodes[i].len = map[current * count_of_nodes + i] + nodes[current].len;
                }
            }
        }
        int min = 2147483647;
        for (int i = 0; i < count_of_nodes; i++) {
            if (nodes[i].len < min && !block[i]) {
                current = i;
                min = nodes[i].len;
            }
        }
    }
}

