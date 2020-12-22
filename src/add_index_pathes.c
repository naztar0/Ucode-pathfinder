#include "../inc/pathfinder.h"

int add_index_pathes(t_pathdata **path) {
    t_pathdata *indexed = *path;
    t_pathdata *bonds = NULL;
    int i = 0;

    for (; indexed; indexed = indexed->forpath) {
        bonds = indexed;
        while (bonds) {
            bonds->pos = i;
            bonds = bonds->link;
        }
        i++;
    }
    return i;
}
