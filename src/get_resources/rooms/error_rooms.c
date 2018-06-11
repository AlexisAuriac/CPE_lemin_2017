/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles errors that may have occured during the creation of the rooms.
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

bool no_start_or_end(room_t *rooms)
{
	flag_t flags = FREE;

	while (rooms) {
		flags |= rooms->flag;
		rooms = rooms->next;
	}
	if (!(flags & START)) {
		ERROR_NO_START;
		return (true);
	}
	else if (!(flags & END)) {
		ERROR_NO_END;
		return (true);
	}
	return (false);
}

bool error_rooms(room_t *rooms, quit_t error, char *last_line)
{
	if (error == FAILURE) {
		free(last_line);
		delete_rooms(rooms);
		return (true);
	}
	return (false);
}