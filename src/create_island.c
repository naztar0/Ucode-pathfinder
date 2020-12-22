#include "../inc/pathfinder.h"

t_islandst *create_island(int isl, int dist) {
    t_islandst *node = (t_islandst *)malloc(1 * sizeof(t_islandst));

    node->num = isl;
    node->target = dist;
    node->path = NULL;
    node->next = NULL;

    return node;
}
