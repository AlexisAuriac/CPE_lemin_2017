/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Gets the rooms to link from the line the user gave.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

static char **get_link_stats(const char *line)
{
	char **stats = NULL;

	if (my_ccount_str('-', line) != 1) {
		ERROR_TUNNEL;
		return (NULL);
	}
	stats = my_str_split(line, "-");
	if (stats == NULL)
		ERROR_MALLOC;
	return (stats);
}

static bool tunnel_already_exists(tunnel_t *tunnels, const char *room_name)
{
	while (tunnels) {
		if (my_strcmp(tunnels->dest->name, room_name) == 0)
			return (true);
		tunnels = tunnels->next;
	}
	return (false);
}

static bool error_links(room_t **to_link, char **stats)
{
	if (to_link[0] == NULL) {
		ERROR_TUNNEL_INEXISTANT(stats[0]);
		return (true);
	}
	else if (to_link[1] == NULL) {
		ERROR_TUNNEL_INEXISTANT(stats[1]);
		return (true);
	}
	return (false);
}

static bool try_to_link(room_t *room, char *start, char *end, room_t **link)
{
	if (my_strcmp(start, room->name) == 0) {
		if (!tunnel_already_exists(room->tunnels, end))
			*link = room;
	}
	return (true);
}

bool get_rooms_to_link(room_t *rooms, const char *line, room_t **to_link)
{
	char **stats = get_link_stats(line);
	bool success = true;

	if (stats == NULL)
		return (false);
	while (success && rooms) {
		success = try_to_link(rooms, stats[0], stats[1], &to_link[0]);
		if (!success)
			break;
		success = try_to_link(rooms, stats[1], stats[0], &to_link[1]);
		rooms = rooms->next;
	}
	if (success)
		success = !error_links(to_link, stats);
	my_free_array((void **) stats);
	return (success);
}