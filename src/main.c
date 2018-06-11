/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** Main file.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

int main(int ac, UNUSED char **av)
{
	__attribute__((cleanup (delete_resources)))
	resources_t resources = {NULL};

	if (ac != 1) {
		ERROR_NB_PARAMS;
		return (MY_EXIT_FAILURE);
	} else if (!get_resources(&resources))
		return (MY_EXIT_FAILURE);
	return (solve(&resources));
}