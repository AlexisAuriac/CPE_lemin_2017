/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Finds the room to be added to the path.
*/

#include <stdbool.h>
#include "my.h"
#include "lemin.h"

static bool eval_tunnel(room_t *best, tunnel_t *test)
{
	if (test->dest->path != -1 || test->path || test->dest->flag == END)
		return (false);
	else if (best != NULL &&
		(test->dest->dist == -1 || test->dest->dist >= best->dist))
		return (false);
	return (true);
}

static void set_tunnels_path(room_t *room1, room_t *room2, int numero_path)
{
	tunnel_t *current = room1->tunnels;

	while (current) {
		if (my_strcmp(current->dest->name, room2->name) == 0) {
			current->path = numero_path;
			break;
		}
		current = current->next;
	}
	current = room2->tunnels;
	while (current) {
		if (my_strcmp(current->dest->name, room1->name) == 0) {
			current->path = numero_path;
			break;
		}
		current = current->next;
	}
}

bool get_next_room(room_t **tested, int numero_path)
{
	tunnel_t *current = (*tested)->tunnels;
	room_t *best = NULL;

	while (current) {
		if (eval_tunnel(best, current))
			best = current->dest;
		current = current->next;
	}
	if (best == NULL)
		return (false);
	set_tunnels_path(*tested, best, numero_path);
	if (best->flag != START)
		best->path = numero_path;
	*tested = best;
	return (true);
}