/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Solves the maze and moves the ants.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

int solve(resources_t *resources)
{
	path_t *paths = breadth_search(resources->rooms);

	if (paths == NULL)
		return (MY_EXIT_FAILURE);
	my_putstr("#moves\n");
	share_ants_paths(paths, resources->ants);
	move_ants(resources->ants);
	return (MY_EXIT_SUCCESS);
}