/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles the creating and deleting of the programs' resources.
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

bool get_resources(resources_t *resources)
{
	resources->ants = get_ants();
	if (resources->ants == NULL)
		return (false);
	resources->rooms = get_rooms();
	if (resources->rooms == NULL)
		return (false);
	else if (no_start_or_end(resources->rooms))
		return (false);
	ants_set_start(resources->ants, resources->rooms);
	return (true);
}

void delete_resources(resources_t *resources)
{
	if (resources->ants != NULL)
		my_free_array((void *) resources->ants);
	if (resources->rooms != NULL)
		delete_rooms(resources->rooms);
}