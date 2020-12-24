#include "../inc/pathfinder.h"

static void print_line(t_outstr **prd) {
    char *string = mx_strdup("========================================");

    mx_printstr(string);
    mx_printchar('\n');
    mx_printstr((*prd)->path);
    mx_printstr((*prd)->route);
    mx_printstr((*prd)->distance);
    mx_printstr(string);
    mx_printchar('\n');
    mx_strdel(&(*prd)->path);
    mx_strdel(&(*prd)->route);
    mx_strdel(&(*prd)->distance);
    mx_strdel(&string);
    free(*prd);
    *prd = NULL;
}

static t_outstr *createprd(t_pathdata *bond, char **set) {
    t_outstr *prd = malloc(1 * sizeof(t_outstr));
    int i = 0;

    prd->path = mx_strdup("Path: ");
    join(&(*prd).path, set[bond->num]);
    prd->route = mx_strdup("Route: ");
    join(&(*prd).route, set[bond->num]);
    prd->distance = mx_strdup("Distance: ");
    for (; bond; bond = bond->link)
        i++;
    prd->com = i;
    return prd;
}

static void add_next_bond(t_outstr **prd, t_pathdata *bond, char *distTo, char **set) {
    char *dist = mx_itoa(bond->range);
    
    join(&(*prd)->route, " -> ");
    join(&(*prd)->route, set[bond->num]);
    if (mx_strlen((*prd)->distance) != 10)
        join(&(*prd)->distance, " + ");
    join(&(*prd)->distance, dist);
    mx_strdel(&dist);

    if (bond->link == NULL) {
        join(&(*prd)->path, " -> ");
        join(&(*prd)->path, set[bond->num]);
        if ((*prd)->com != 2) {
            join(&(*prd)->distance, " = ");
            join(&(*prd)->distance, distTo);
        }
        join(&(*prd)->route, "\n");
        join(&(*prd)->path, "\n");
        join(&(*prd)->distance, "\n");
    }
}

static void display_path(t_pathdata **disp, int distTo, char **set) {
    t_pathdata *bond = *disp;
    t_outstr *prd = NULL;
    char *dist = mx_itoa(distTo);

    while (bond) {
        prd = createprd(bond, set);
        bond = bond->link;
        while (bond->link) {
            add_next_bond(&prd, bond, dist, set);
            bond = bond->link;
        }
        add_next_bond(&prd, bond, dist, set);
        print_line(&prd);
        bond = bond->forpath;
    }
    mx_strdel(&dist);
}

void print_output(t_islandst **visited, int root, int size, char **set) {
    t_islandst *current = NULL;

    for (int i = 0; root < size; root++) {
        current = *visited;
        while (current->num != root)
            current = current->next;

        t_pathdata *indexed = current->path;
        t_pathdata *conns = NULL;
        
        int j;
        for (j = 0; indexed; j++) {
            conns = indexed;
            while (conns) {
                conns->pos = j;
                conns = conns->link;
            }
            indexed = indexed->forpath;
        }
        i = j;

        sort_path(&current->path, i);
        display_path(&current->path, current->target, set);
    }
}
