#include "../inc/pathfinder.h"

static void compare(t_pathdata **newOne, t_pathdata **curOne, int *flag) {
    if (*newOne && *curOne) {
        if ((*newOne)->num != (*curOne)->num)
            *flag = 1;
        if ((*newOne)->range != (*curOne)->range)
            *flag = 1;
    }

    if (!(*newOne) || !(*curOne))
        *flag = 1;
}

static void step(t_pathdata **oldOne, t_pathdata **path, t_pathdata **new) {
    *path = *new;
    *oldOne = (*oldOne)->forpath;
}

int unique_path(t_pathdata **new, t_pathdata **current) {
    t_pathdata *path = *new;
    t_pathdata *oldOne = *current;
    int flag = -1;

    while (oldOne) {
        if (oldOne->link == NULL || !path) {
            compare(&path, &oldOne, &flag);
            step(&oldOne, &path, &(*new));
            if (flag == -1)
                return -1;
            if (oldOne)
                flag = -1;
            continue;
        }
        compare(&path, &oldOne, &flag);
        path = path->link;
        oldOne = oldOne->link;
    }
    return flag;
}
