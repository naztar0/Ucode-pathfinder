#include "../inc/pathfinder.h"

t_pathdata *add_one_path(t_pathdata **previous, int isl, int dist) {
    t_pathdata *new = NULL;
    t_pathdata *last = *previous;
    t_pathdata *res = NULL;

    if (!last)
        return res = create_path(isl, dist);

    res = create_path(last->num, last->range);
    new = res;
    last = last->link;
    while (last) {
        new->link = create_path(last->num, last->range);
        last = last->link;
        new = new->link;
    }
    new->link = create_path(isl, dist);

    return res;
}
