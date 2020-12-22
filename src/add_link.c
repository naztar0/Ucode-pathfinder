#include "../inc/pathfinder.h"

void add_link(t_pathdata **cur, t_pathdata **new) {
    t_pathdata *current = *cur;

    while (current->link) {
        current->forpath = *new;
        current = current->link;
    }
    current->forpath = *new;
}
