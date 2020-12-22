#include "../inc/pathfinder.h"

t_pathlist *create_l() {
    t_pathlist *l = malloc(sizeof(t_pathlist));

    l->un = NULL;
    l->v = NULL;
    l->now = NULL;
    l->sh = NULL;

    return l;
}
