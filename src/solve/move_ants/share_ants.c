/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Shares the ants on all paths.
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

static int get_nb_paths(path_t *paths)
{
	int i = 0;

	while (paths) {
		++i;
		paths = paths->next;
	}
	return (i);
}

static int get_size_last_path(path_t *paths, int pos)
{
	for (int i = 1 ; i < pos ; ++i)
		paths = paths->next;
	return (paths->size);
}

static int share_ants(path_t *paths, int to_share, int last_size)
{
	path_t *current = paths;
	int sum = 0;
	int coef = 0;

	if (paths->size > to_share) {
		paths->nb_ants += to_share;
		return (0);
	}
	while (current) {
		sum += last_size / current->size;
		current = current->next;
	}
	coef = to_share / sum;
	current = paths;
	while (current) {
		current->nb_ants += coef * (last_size / current->size);
		current = current->next;
	}
	return (to_share - sum * coef);
}

static void assign_paths(path_t *paths, ant_t **ants)
{
	int nb_ants = my_strlen_tab((void *) ants);
	path_t *current = paths;

	for (int i = 0 ; i < nb_ants ; ++i) {
		ants[i]->path = current->numero;
		--current->nb_ants;
		if (!current->nb_ants) {
			if (current == paths) {
				paths = paths->next;
				free(current);
			} else
				delete_last_path(paths);
			current = paths;
			continue;
		}
		current = current->next;
		if (!current)
			current = paths;
	}
}

void share_ants_paths(path_t *paths, ant_t **ants)
{
	int to_share = my_strlen_tab((void *) ants);
	int pos_last_size = get_nb_paths(paths);
	int last_size = 0;

	do {
		last_size = get_size_last_path(paths, pos_last_size--);
		to_share = share_ants(paths, to_share, last_size);
	} while (to_share);
	assign_paths(paths, ants);
}