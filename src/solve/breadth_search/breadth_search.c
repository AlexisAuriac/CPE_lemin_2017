/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Searches for all the path from the start to the end.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

path_t *breadth_search(room_t *rooms)
{
	path_t *paths = NULL;
	room_t *start = NULL;
	room_t *end = NULL;

	while (rooms) {
		if (rooms->flag == START)
			start = rooms;
		else if (rooms->flag == END)
			end = rooms;
		rooms = rooms->next;
	}
	if (!rate_rooms(start))
		return (NULL);
	paths = get_paths(end);
	if (paths == NULL)
		ERROR_NO_PATH;
	return (paths);
}