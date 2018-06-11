/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles rooms' commands.
*/

#include "my.h"
#include "lemin.h"

static bool error_command(room_t *rooms, flag_t flag)
{
	while (rooms) {
		if (rooms->flag == flag) {
			if (flag == START)
				ERROR_TWO_STARTS;
			else if (flag == END)
				ERROR_TWO_ENDS;
			return (true);
		}
		rooms = rooms->next;
	}
	return (false);
}

static flag_t get_command(const char *line)
{
	if (my_strcmp(line, "##start") == 0)
		return (START);
	else if (my_strcmp(line, "##end") == 0)
		return (END);
	return (FREE);
}

quit_t handle_commands(room_t *rooms, const char *line, flag_t *flag)
{
	*flag = get_command(line);
	if (*flag == FREE)
		return (CONTINUE);
	else if (error_command(rooms, *flag))
		return (FAILURE);
	return (CONTINUE);
}