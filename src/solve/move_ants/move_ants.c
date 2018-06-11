/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Moves the ants from the start to the end according to their predefined path.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

bool can_move(ant_t *ant, room_t *dest)
{
	if (dest->path != ant->path && dest->flag != END)
		return (false);
	else if (dest == ant->prev_room || dest->flag == OCCUPIED)
		return (false);
	return (true);
}

int get_new_size_moves(char *moves, int numero, char *room)
{
	int new_size = my_strlen(room) + 4;

	if (moves != NULL)
		new_size += my_strlen(moves);
	while (numero) {
		++new_size;
		numero /= 10;
	}
	return (new_size);
}

char *add_move(char *moves, int numero, char *room)
{
	int new_size = get_new_size_moves(moves, numero, room);
	char *cpy = NULL;

	cpy = malloc(sizeof(char) * new_size);
	if (cpy == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	my_sprintf(cpy, "%sP%d-%s ", (moves) ? moves : "", numero, room);
	free(moves);
	return (cpy);
}

bool move_ant(ant_t *ant, char **moves, int numero)
{
	tunnel_t *current = ant->room->tunnels;

	while (current) {
		if (can_move(ant, current->dest)) {
			ant->prev_room = ant->room;
			if (ant->room->flag != START)
				ant->room->flag = FREE;
			ant->room = current->dest;
			if (ant->room->flag == END)
				ant->arrived = true;
			else
				ant->room->flag = OCCUPIED;
			*moves = add_move(*moves, numero, ant->room->name);
			return (true);
		}
		current = current->next;
	}
	return (false);
}

void move_ants(ant_t **ants)
{
	int moved = 0;
	char *moves = NULL;

	do {
		moved = 0;
		for (int i = 0 ; ants[i] ; ++i) {
			if (!ants[i]->arrived)
				moved += move_ant(ants[i], &moves, i + 1);
		}
		if (moved && my_strlen(moves))
			moves[my_strlen(moves) - 1] = '\n';
	} while (moved);
	my_putstr(moves);
	free(moves);
}