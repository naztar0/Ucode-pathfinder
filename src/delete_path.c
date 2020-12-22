#include "../inc/pathfinder.h"

static void pop_all_bond(t_pathdata **head) {
    t_pathdata *p = NULL;

    if (!head || !(*head)) 
        return;
    while ((*head)->link) {
        p = (*head)->link;
        free(*head);
        *head = p;
    }
    if (!(*head)->link && !(*head)->forpath) {
        free(*head);
        *head = NULL;
        return;
    }
}

static void pop_next_path(t_pathdata **head) {
    t_pathdata *p = NULL;

    if (!head || !(*head)) 
        return;
    if ((*head)->forpath == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = (*head)->forpath;
        free(*head);
        *head = p;
    }
}

void delete_path(t_pathdata **head) {
    if (!head || !(*head)) 
        return;

    while(*head) {
        pop_all_bond(&(*head));
        pop_next_path(&(*head));
    }
}
