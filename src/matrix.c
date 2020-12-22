#include "../inc/pathfinder.h"

static void crfill(char **set, char **arrarr, int ***matrix, t_params *in) {
    int **mat = *matrix;
    int k = 0;
    int i = in->extent;
    int j = in->base;

    if (mx_isdigit(arrarr[j + 1][0])) {
        while (mx_strcmp(set[k], arrarr[j - 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j + 1]))
            mat[i][k] = mx_atoi(arrarr[j + 1]);
    } 
    else {
        while (mx_strcmp(set[k], arrarr[j + 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j + 2]))
            mat[i][k] = mx_atoi(arrarr[j + 2]);
    }
}

static void mx_mat(char **set, char **arrarr, int ***matrix) {
    t_params *i = malloc(sizeof(t_params));
    
    i->extent = 0;
    while (set[i->extent]) {
        i->base = 0;
        while (arrarr[i->base]) {
            if (mx_strcmp(set[i->extent], arrarr[i->base]) == 0) {
                crfill(set, arrarr, &(*matrix), i);
            }
            i->base += 1;
        }
        i->extent += 1;
    }
    free(i);
    i = NULL;
}

int **create_matrix(char **set, char ***arrarr) {
    int **matrix = NULL;
    int i = 0;
    int k = 0;

    while (set[i]) 
        i++;
    k = i;
    matrix = malloc(sizeof(int*) * i);
    while (k >= 0) {
        matrix[k] = malloc(sizeof(int) * i);
        k--;
    }

    mx_mat(set, *arrarr, &matrix);
    return matrix;
}
