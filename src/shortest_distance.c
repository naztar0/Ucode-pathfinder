#include "../inc/pathfinder.h"

t_islandst *shortest_distance(t_islandst **unvisited) {
    t_islandst *head = NULL;
    t_islandst *shortest = NULL;

    if (unvisited || *unvisited) {
        head = *unvisited;
        shortest = *unvisited;
        while (head) {
            if (head->target != 0) {
                if (shortest->target > head->target || !shortest->target)
                    shortest = head;
            }
            head = head->next;
        }
    }

    return shortest;
}
