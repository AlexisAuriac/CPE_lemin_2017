/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Recuperate the rooms from the user's input.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

static bool line_is_tunnel(const char *line)
{
	if (!in_str(' ', line) && !in_str('\t', line) && in_str('-', line))
		return (true);
	return (false);
}

static quit_t add_room(room_t **first, const char *line, flag_t flag)
{
	room_t *new_room = NULL;
	char **stats = get_stats(line);

	if (stats == NULL)
		return (FAILURE);
	new_room = malloc(sizeof(room_t));
	if (new_room == NULL) {
		ERROR_MALLOC;
		my_free_array((void **) stats);
		return (FAILURE);
	}
	else if (!load_stats(first, new_room, stats, flag)) {
		free(new_room->name);
		free(new_room);
		return (FAILURE);
	}
	display_room(new_room);
	return (CONTINUE);
}

static quit_t parse_line(room_t **rooms, char *line, flag_t *flag)
{
	quit_t error = CONTINUE;

	clean_str(line);
	if (my_strlen(line) != 0 && !my_str_is(line, " \t")) {
		if (my_strncmp(line, "##", 2) == 0)
			error = handle_commands(*rooms, line, flag);
		else if (line_is_tunnel(line))
			error = SUCCESS;
		else {
			error = add_room(rooms, line, *flag);
			*flag = FREE;
		}
	}
	return (error);
}

room_t *get_rooms(void)
{
	room_t *rooms = NULL;
	char *line = NULL;
	flag_t flag = FREE;
	quit_t error = CONTINUE;

	my_putstr("#rooms\n");
	do {
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			continue;
		error = parse_line(&rooms, line, &flag);
		if (error == CONTINUE)
			free(line);
	} while (error == CONTINUE && line != NULL);
	if (error_rooms(rooms, error, line))
		return (NULL);
	else if (!get_tunnels(rooms, line)) {
		delete_rooms(rooms);
		return (NULL);
	}
	return (rooms);
}