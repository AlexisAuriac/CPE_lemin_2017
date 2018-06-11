/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Header containing the get_resources functions' prototypes.
*/

#ifndef GET_RESOURCES_H
#define GET_RESOURCES_H

#include "error_resources.h"


typedef struct resources {
	ant_t **ants;
	room_t *rooms;
} resources_t;


//ressources.c
bool get_resources(resources_t *resources);
void delete_resources(resources_t *resources);

//get_ants.c
ant_t **get_ants(void);

//get_rooms.c
room_t *get_rooms(void);

//get_stats_room.c
char **get_stats(const char *line);
bool load_stats(room_t **first, room_t *new_room, char **stats, flag_t flag);

//commands.c
quit_t handle_commands(room_t *rooms, const char *line, flag_t *flag);

//error_rooms.c
bool no_start_or_end(room_t *rooms);
bool error_rooms(room_t *rooms, quit_t error, char *last_line);

//get_tunnels.c
bool get_tunnels(room_t *rooms, char *line);

//get_links.c
bool get_rooms_to_link(room_t *rooms, const char *line, room_t **to_link);

#endif