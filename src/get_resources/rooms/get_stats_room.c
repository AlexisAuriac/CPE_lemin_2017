/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** Gets the stats of a room.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

char **get_stats(const char *line)
{
	char **stats = my_str_split(line, " \t");

	if (stats == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	else if (my_strlen_tab((void **) stats) != 3 || in_str('-', stats[0])) {
		ERROR_ROOM;
		my_free_array((void **) stats);
		return (NULL);
	}
	for (int i = 1 ; i < 3 ; ++i) {
		if (!my_str_is(stats[i], NUM)) {
			ERROR_ROOM;
			my_free_array((void **) stats);
			return (NULL);
		}
	}
	return (stats);
}

static bool overlap(room_t *new_room, room_t *first)
{
	while (first) {
		if (new_room->x == first->x && new_room->y == first->y) {
			ERROR_SAME_COORDINATES;
			return (true);
		}
		else if (my_strcmp(new_room->name, first->name) == 0) {
			ERROR_SAME_NAMES;
			return (true);
		}
		first = first->next;
	}
	return (false);
}

static bool error_stats_room(room_t *new_room, room_t *rooms)
{
	if (new_room->x == 0) {
		ERROR_ROOM;
		return (true);
	}
	else if (overlap(new_room, rooms))
		return (true);
	return (false);
}

bool load_stats(room_t **first, room_t *new_room, char **stats, flag_t flag)
{
	room_t *current = *first;

	new_room->name = my_strdup(stats[0]);
	new_room->x = my_getnbr(stats[1]);
	new_room->y = my_getnbr(stats[2]);
	my_free_array((void **) stats);
	if (error_stats_room(new_room, *first))
		return (false);
	new_room->flag = flag;
	new_room->path = (flag == END) ? 0 : -1;
	new_room->dist = (flag == START) ? 0 : -1;
	new_room->tunnels = NULL;
	new_room->next = NULL;
	if (*first == NULL)
		*first = new_room;
	else {
		while (current->next)
			current = current->next;
		current->next = new_room;
	}
	return (true);
}