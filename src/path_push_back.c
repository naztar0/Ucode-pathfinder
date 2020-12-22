#include "../inc/pathfinder.h"

void path_push_back(t_pathdata **path, t_pathdata **previous, int isl, int dist) {
    t_pathdata *last = *path;
    t_pathdata *cur = *previous;
    t_pathdata *new = NULL;

    while (last->forpath != NULL)
        last = last->forpath;

    while (cur) {
        new = add_one_path(&cur, isl, dist);
        if (unique_path(&new, &(*path)) == 1) {
            add_link(&last, &new);
            last = last->forpath;
        }
        cur = cur->forpath;
    }
}
