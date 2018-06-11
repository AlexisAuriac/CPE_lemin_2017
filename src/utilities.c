/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Useful functions.
*/

#include "my.h"

void clean_str(char *str)
{
	int comment = my_index('#', str);

	if (comment != -1 && str[comment + 1] != '#')
		str[comment] = '\0';
	my_strip(str, " \t");
	my_rstrip(str, " \t");
}