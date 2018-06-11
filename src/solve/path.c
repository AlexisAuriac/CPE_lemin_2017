/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Contains the path struct basic functions.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

bool delete_last_path(path_t *paths)
{
	path_t *prev = paths;
	path_t *current = paths;

	if (paths->next == NULL) {
		free(paths);
		return (false);
	}
	while (current->next) {
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	free(current);
	return (true);
}

void print_paths(path_t *paths)
{
	while (paths) {
		my_printf("%d: size = %d", paths->numero, paths->size);
		my_printf(", nb_ants = %d\n", paths->nb_ants);
		paths = paths->next;
	}
}