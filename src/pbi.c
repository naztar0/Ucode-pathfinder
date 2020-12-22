#include "../inc/pathfinder.h"

void pbi(t_islandst **island, t_pathdata **path, int isl, int dist) {
    t_islandst *new = create_island(isl, dist);
    t_islandst *last = *island;

    if (path && *path)
        new->path = copy_path(&(*path));
    if (*island == NULL) {
        *island = new;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
}
