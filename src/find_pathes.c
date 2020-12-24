#include "../inc/pathfinder.h"

static void st(t_islandst **un, t_islandst **cur, t_islandst **v, t_params *in) {
    *un = NULL;
    *v = NULL;

    for (int i = 0; i < in->extent; i++)
        pbi(&(*un), NULL, i, 0);
    *cur = *un;
    while ((*cur)->num != in->base)
        *cur = (*cur)->next;
    (*cur)->path = create_path(in->base, 0);
    pbi(&(*v), &(*cur)->path, (*cur)->num, (*cur)->target);
    island_pop_middle(&(*un), in->base);
    *cur = *v;
}

static void md (t_islandst **un, t_islandst **cur, int **mat) {
    t_islandst *h = *un;
    int sum = 0;
    int i1, i2, median;

    while (h != NULL) {
        i1 = (*cur)->num;
        i2 = h->num;
        median = mat[i1][i2];
        if (median != 0 && h->target == 0) {
            h->target = (*cur)->target + median;

            sum += h->target;
            if (sum < 0) { 
                err_length_of_bridges_big();
            } 

            h->path = add_path(&(*cur)->path, i2, median);
        } else if (median != 0) {
            if ((*cur)->target + median == h->target)
            path_push_back(&h->path, &(*cur)->path, i2, median);
            if ((*cur)->target + median < h->target) {
                h->target = (*cur)->target + median;
                delete_path(&h->path);
                h->path = add_path(&(*cur)->path, i2, median);
            }
        }
        h = h->next;
    }
}

static void lt(t_islandst **now, t_islandst **s, t_islandst **o, t_islandst **p, int **matrix, char **set) {
    *s = shortest_distance(o);
    pbi(p, &(*s)->path, (*s)->num, (*s)->target);
    island_pop_middle(o, (*s)->num);
    *now = (*now)->next;
    if ((*now)->path == NULL) {
        delete_mat(&matrix, set);
        err_invalid_number_of_islands();
        exit(0);
    }
}

static void main_algo(int **matrix, char **set, t_params *in) {
    t_islandst *now = NULL, *s = NULL, *o = NULL, *p = NULL;

    st(&o, &now, &p, in);
    while (o && o != NULL) {
        md(&o, &now, matrix);
        lt(&now, &s, &o, &p, matrix, set);
    }
    print_output(&p, in->base+1, in->extent, set);
    while (p != NULL) {
        delete_path(&p->path);
        island_pop_front(&p);
    }
}

void algoritm(int **matrix, char **set) {
    int size = 0;
    int i = 0;
    t_params *in = malloc(sizeof(t_params));

    while (set[size]) 
        size++;
    in->extent = size;
    while (i < size - 1) {
        in->base = i;
        main_algo(matrix, set, in);
        i++;
    }
    free(in);
    in = NULL;
}
