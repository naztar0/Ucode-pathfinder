#include "../inc/pathfinder.h"

static t_pathdata *add_one(t_pathdata **previous) {
    t_pathdata *new = NULL;
    t_pathdata *last = *previous;
    t_pathdata *res = NULL;

    res = create_path(last->num, last->range);
    new = res;
    last = last->link;
    while (last) {
        new->link = create_path(last->num, last->range);
        last = last->link;
        new = new->link;
    }
    return res;
}

t_pathdata *copy_path(t_pathdata **data) {
    t_pathdata *cur = NULL;
    t_pathdata *res = NULL;
    t_pathdata *new = NULL;
    t_pathdata *fast = NULL;

    if (*data)
        cur = *data;
    res = add_one(&cur);
    fast = res;
    cur = cur->forpath;

    while (cur) {
        new = add_one(&cur);
        add_link(&fast, &new);
        fast = fast->forpath;
        cur = cur->forpath;
    }
    return res;
}
