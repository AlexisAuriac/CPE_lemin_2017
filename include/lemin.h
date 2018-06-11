/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef LEMIN_H
#define LEMIN_H

#include "const.h"
#include "struct.h"
#include "macro.h"
#include "error.h"
#include "get_resources.h"
#include "solve.h"

//utilities.c
void clean_str(char *str);

//ants.c
void ants_set_start(ant_t **ants, room_t *rooms);

//rooms.c
void delete_rooms(room_t *room);
void display_room(room_t *rooms);

//tunnels.c
void delete_tunnels(tunnel_t *tunnels);
void display_tunnels(tunnel_t *tunnels);

#endif