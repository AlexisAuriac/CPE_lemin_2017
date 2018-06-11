/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles ants.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

void ants_set_start(ant_t **ants, room_t *rooms)
{
	while (rooms->flag != START)
		rooms = rooms->next;
	for (int i = 0 ; ants[i] ; ++i) {
		ants[i]->prev_room = rooms;
		ants[i]->room = rooms;
	}
}