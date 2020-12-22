#include "../inc/pathfinder.h"

t_pathdata *add_path(t_pathdata **previous, int isl, int dist) {
    t_pathdata *cur = NULL;
    t_pathdata *res = NULL;
    t_pathdata *new = NULL;
    t_pathdata *fast = NULL;

    if (*previous)
        cur = *previous;
    res = add_one_path(&cur, isl, dist);
    fast = res;
    if (cur)
        cur = cur->forpath;
    while (cur) {
        new = add_one_path(&cur, isl, dist);
        add_link(&fast, &new);
        fast = fast->forpath;
        cur = cur->forpath;
    }
    return res;
}
