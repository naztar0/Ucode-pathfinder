#include "pathfinder.h"

typedef struct  s_pathdata {
    int pos, range, num;
    struct s_pathdata
    *link, *forpath;
} t_pathdata;

typedef struct  s_islandst {
    int num, target;
    struct s_islandst *next;
    struct s_pathdata *path;
} t_islandst;

typedef struct  s_outstr {
    int com;
    char *path, *route, *distance;
} t_outstr;

typedef struct  s_params {
    int base, extent;
} t_params;

//delete
typedef struct  s_median {
    int isl1;
    int isl2;
    int mat;
} t_median;

//delete
typedef struct  s_pathlist {
    t_islandst *now, *sh, *un, *v;
} t_pathlist;
