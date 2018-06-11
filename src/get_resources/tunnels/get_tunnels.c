/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Recuperates the tunnels from the user's input.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

static tunnel_t *add_tunnel(tunnel_t *first, room_t *dest)
{
	tunnel_t *new_tunnel = malloc(sizeof(tunnel_t));

	if (new_tunnel == NULL) {
		ERROR_MALLOC;
		delete_tunnels(first);
		return (NULL);
	}
	new_tunnel->path = 0;
	new_tunnel->dest = dest;
	new_tunnel->next = first;
	return (new_tunnel);
}

static bool link_rooms(room_t *room1, room_t *room2)
{
	room1->tunnels = add_tunnel(room1->tunnels, room2);
	if (room1->tunnels == NULL)
		return (false);
	room2->tunnels = add_tunnel(room2->tunnels, room1);
	if (room2->tunnels == NULL)
		return (false);
	return (true);
}

bool get_tunnels(room_t *rooms, char *line)
{
	room_t *to_link[2] = {NULL};
	bool error = false;

	my_putstr("#tunnels\n");
	while (line) {
		clean_str(line);
		if (my_strlen(line) != 0) {
			error = !get_rooms_to_link(rooms, line, to_link);
			if (!error)
				error = !link_rooms(to_link[0], to_link[1]);
		}
		if (error) {
			free(line);
			return (false);
		} else if (my_strlen(line) != 0)
			my_printf("%s\n", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (true);
}