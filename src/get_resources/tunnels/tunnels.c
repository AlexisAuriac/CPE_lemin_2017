/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Handles the tunnels.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

void delete_tunnels(tunnel_t *tunnels)
{
	tunnel_t *to_del = tunnels;

	while (tunnels) {
		to_del = tunnels;
		tunnels = tunnels->next;
		free(to_del);
	}
}