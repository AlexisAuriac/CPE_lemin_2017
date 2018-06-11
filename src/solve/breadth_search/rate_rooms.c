/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Finds the distance to the start of each room.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

static void add_to_search_list(search_list_t *first, room_t *to_add)
{
	search_list_t *new_search = malloc(sizeof(search_list_t));
	int dist = first->room->dist + 1;

	if (new_search == NULL) {
		ERROR_MALLOC;
		return;
	}
	new_search->room = to_add;
	new_search->next = NULL;
	while (first->next)
		first = first->next;
	first->next = new_search;
	new_search->room->dist = dist;
}

static void add_rooms_around(search_list_t *first)
{
	tunnel_t *tunnel = first->room->tunnels;

	while (tunnel) {
		if (tunnel->dest->dist == -1 && tunnel->dest->flag != END)
			add_to_search_list(first, tunnel->dest);
		tunnel = tunnel->next;
	}
}

static bool cycle_search_list(search_list_t **first)
{
	search_list_t *to_del = *first;

	if ((*first)->next == NULL) {
		free(to_del);
		return (false);
	}
	*first = (*first)->next;
	free(to_del);
	return (true);
}

bool rate_rooms(room_t *start)
{
	search_list_t *search_list = malloc(sizeof(search_list_t));

	if (search_list == NULL) {
		ERROR_MALLOC;
		return (false);
	}
	search_list->room = start;
	search_list->next = NULL;
	do {
		add_rooms_around(search_list);
	} while (cycle_search_list(&search_list));
	return (true);
}