#include "../inc/pathfinder.h"

t_pathdata *create_path(int isl, int dist) {
	t_pathdata *node = (t_pathdata *)malloc(1 * sizeof(t_pathdata));

	node->num = isl;
	node->range = dist;
	node->link = NULL;
	node->forpath = NULL;

	return node;
}
