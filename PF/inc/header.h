#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"

typedef struct s_node {
    char *name;
    int len;
}              t_node;

typedef struct s_info {
    int sum;
    int p_from;
    int p_to;
    int count_of_nodes;
}              t_info;

int input_count_of_nodes(int argc, char *argv[]);
void input_map(char *file_n, t_node *nodes, int *map, int count_of_nodes);
void dijkstra(int s_point, t_node *nodes, int *map, int count_of_nodes);
char *find_path(char *PR, char *D, t_node *nodes, int *map, t_info info);

//Utils
void del_nodes(t_node *nodes, int count_of_nodes);
int atoi_mod(const char *str, int len);
void line_err(int line);
bool is_wrong(char *str);
void mx_del_names(char **arr);

#endif

