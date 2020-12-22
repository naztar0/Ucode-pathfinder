#include "../inc/pathfinder.h"

static int cmp(t_pathdata *bond, t_pathdata *fast) {
    while (bond && fast) {
        if (bond->num > fast->num)
            return 1;
        if (bond->num < fast->num)
            return 0;
        bond = bond->link;
        fast = fast->link;
    }
    if (bond && !fast)
        return 1;
    return 0;
}

static void swp_d(t_pathdata **disp, t_pathdata **bond, t_pathdata **fast) {
    t_pathdata *temp = (*fast)->forpath;
    t_pathdata *cur = *disp;

    while(cur->forpath != *fast)
        cur = cur->forpath;
    add_link(&cur, &(*bond));
    cur = *disp;
    if (*disp == *bond)
        *disp = *fast;
    else {
        while (cur && cur->forpath != *bond)
            cur = cur->forpath;
        add_link(&cur, &(*fast));
    }
    add_link(&(*fast), &(*bond)->forpath);
    add_link(&(*bond), &temp);
}

static void swp(t_pathdata **disp, t_pathdata **bond, t_pathdata **fast) {
    t_pathdata *temp = (*fast)->forpath;
    t_pathdata *cur = *disp;

    if ((*bond)->forpath == *fast) {
            add_link(&(*fast), &(*bond));
            add_link(&(*bond), &temp);
        if (*disp == *bond)
            *disp = *fast;
        else {
            while (cur && cur->forpath != *bond)
                cur = cur->forpath;
            add_link(&cur, &(*fast));
        }
    }
    else 
        swp_d(&(*disp), &(*bond), &(*fast));
}

void sort_path(t_pathdata **disp, int sizeP) {
    t_pathdata *bond = *disp;
    t_pathdata *fast = (*disp)->forpath;

    for (int i = 0; i < sizeP; i++) {
        bond = *disp;
        fast = bond->forpath;
        for (; bond->pos != i; bond = bond->forpath)
            fast = bond->forpath;

        while (fast) {
            if (cmp(bond, fast) == 1) {
                swp(&(*disp), &bond, &fast);
                for (bond = *disp; bond->pos != i; bond = bond->forpath)
                    fast = bond->forpath;
            }
            else 
                fast = fast->forpath;
        }
    }
}
