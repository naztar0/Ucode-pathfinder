#include "pathfinder.h"

//errors
void err_dublicate_bridges();
void err_file_empty(char *filename);
void err_file_not_exist(char *filename);
void err_first_line_invalid();
void err_invalid_args();
void err_invalid_line(int number_of_line);
void err_invalid_number_of_islands();
void err_length_of_bridges_big();

//nessesary functions
void test_err(int argc, char *file, char **argv);
void parsing(char *fd, int ***matrix, char ***set);
int **create_matrix(char **set, char ***arrarr);
void print_matrix(int **matrix, char **set);
void algoritm(int **matrix, char **set);
void check_spaces(char **src, char *file);
void create_arr(char **src, char ***arrarr);
void create_set(char ***set, char ***arrarr, char *numOfIsland);
void delete_mat(int ***matrix, char **set);
t_islandst *shortest_distance(t_islandst **unvisited);
t_pathdata *create_path(int isl, int dist);
void path_push_back(t_pathdata **path, t_pathdata **previous, int isl, int dist);
void add_link(t_pathdata **cur, t_pathdata **new);
t_pathdata *add_path(t_pathdata **previous, int isl, int dist);
void delete_path(t_pathdata **head);
t_pathdata *copy_path(t_pathdata **data);
int unique_path(t_pathdata **new, t_pathdata **pre);
void join(char **res, char *s2);
void print_output(t_islandst **visited, int root, int size, char **set);
void add_link(t_pathdata **cur, t_pathdata **new);
t_pathdata *add_one_path(t_pathdata **previous, int isl, int dist);
t_islandst *create_island(int isl, int dist);
void pbi(t_islandst **island, t_pathdata **path, int isl, int dist);
void island_pop_front(t_islandst **head);
void island_pop_middle(t_islandst **unvisited, int index);
void sort_path(t_pathdata **disp, int sizeP);
int add_index_pathes(t_pathdata **path);
t_pathlist *create_l();
