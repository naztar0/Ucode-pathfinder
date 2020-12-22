#include "../inc/pathfinder.h"

static void firs_if(t_islandst *temp, t_islandst *leftOne, int index) {
    if (temp && temp->num == index) {
        if (temp->next)
            leftOne->next = temp->next;
        else
            leftOne->next = NULL;
        delete_path(&temp->path);
        free(temp);
        temp = NULL;
    }
}

void island_pop_middle(t_islandst **unvisited, int index) {
    t_islandst *temp = NULL;
    t_islandst *leftOne = NULL;

    if (!unvisited || !(*unvisited)) 
        return;

    if ((*unvisited)->num == index) {
        delete_path(&((*unvisited)->path));
        island_pop_front(&(*unvisited));
    }
    else {
        temp = *unvisited;
        leftOne = temp;
        while (temp != NULL && temp->num != index) {
            leftOne = temp;
            temp = temp->next;
        }
        firs_if(temp, leftOne, index);
    }
}
