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

static void md (t_islandst **un, t_islandst **cur, int **mat, t_median **m) {
    t_islandst *h = *un;
    int sum = 0;

    while (h != NULL) {
        (*m)->isl1 = (*cur)->num;
        (*m)->isl2 = h->num;
        (*m)->mat = mat[(*m)->isl1][(*m)->isl2];
        if ((*m)->mat != 0 && h->target == 0) {
            h->target = (*cur)->target + (*m)->mat;

            sum += h->target;
            if (sum < 0) { 
                err_length_of_bridges_big();
            } 

            h->path = add_path(&(*cur)->path, (*m)->isl2, (*m)->mat);
        } else if ((*m)->mat != 0) {
            if ((*cur)->target + (*m)->mat == h->target)
            path_push_back(&h->path, &(*cur)->path, (*m)->isl2, (*m)->mat);
            if ((*cur)->target + (*m)->mat < h->target) {
                h->target = (*cur)->target + (*m)->mat;
                delete_path(&h->path);
                h->path = add_path(&(*cur)->path, (*m)->isl2, (*m)->mat);
            }
        }
        h = h->next;
    }
}

static void lt(t_pathlist **l, int **matrix, char **set) {
    (*l)->sh = shortest_distance(&(*l)->un);
    pbi(&(*l)->v, &(*l)->sh->path, (*l)->sh->num, (*l)->sh->target);
    island_pop_middle(&(*l)->un, (*l)->sh->num);
    (*l)->now = (*l)->now->next;
    if ((*l)->now->path == NULL) {
        delete_mat(&matrix, set);
        err_invalid_number_of_islands();
        exit(0);
    }
}

static void main_algo(int **matrix, char **set, t_params *in) {
    t_pathlist *l = create_l();
    t_median *m	= NULL;

    st(&l->un, &l->now, &l->v, in);
    while (l->un && l->un != NULL) {
        m = malloc(sizeof(t_median));
        md(&l->un, &l->now, matrix, &m);
        free(m);
        m = NULL;
        lt(&l, matrix, set);
    }
    print_output(&l->v, in->base+1, in->extent, set);
    while (l->v != NULL) {
        delete_path(&l->v->path);
        island_pop_front(&l->v);
    }
    free(l);
    l = NULL;
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
