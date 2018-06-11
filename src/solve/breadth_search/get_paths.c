/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Recuperates the paths from the end to the start.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "lemin.h"

static void add_path(path_t **paths, path_t *to_add)
{
	path_t *current = *paths;

	if (*paths == NULL) {
		*paths = to_add;
		return;
	}
	while (current->next)
		current = current->next;
	current->next = to_add;
}

static bool find_path(room_t *end, path_t **paths, int numero_path)
{
	path_t *new_path = malloc(sizeof(path_t));
	room_t *tested = end;

	new_path->size = 0;
	new_path->nb_ants = 0;
	new_path->numero = numero_path;
	new_path->next = NULL;
	while (tested->flag != START) {
		++new_path->size;
		if (!get_next_room(&tested, numero_path)) {
			free(new_path);
			return (false);
		}
	}
	add_path(paths, new_path);
	return (true);
}

path_t *get_paths(room_t *end)
{
	path_t *paths = NULL;
	int numero_path = 1;

	while (find_path(end, &paths, numero_path))
		++numero_path;
	return (paths);
}