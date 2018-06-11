/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles rooms.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

void delete_rooms(room_t *rooms)
{
	room_t *to_del = rooms;

	while (rooms) {
		to_del = rooms;
		rooms = rooms->next;
		free(to_del->name);
		delete_tunnels(to_del->tunnels);
		free(to_del);
	}
}

void display_room(room_t *rooms)
{
	if (rooms->flag == START)
		my_putstr("##start\n");
	else if (rooms->flag == END)
		my_putstr("##end\n");
	my_printf("%s %d %d\n", rooms->name, rooms->x, rooms->y);
}