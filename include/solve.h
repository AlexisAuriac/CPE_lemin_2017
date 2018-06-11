/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Header containing the solution's functions prototypes.
*/

#ifndef SOLVE_H
#define SOLVE_H

typedef struct search_list {
	room_t *room;
	struct search_list *next;
} search_list_t;

typedef struct path {
	int numero;
	int size;
	int nb_ants;
	struct path *next;
} path_t;


//solve.c
int solve(resources_t *resources);

//path.c
bool delete_last_path(path_t *paths);
void print_paths(path_t *paths);

//breadth_search/breadth_search.c
bool delete_last_path(path_t *paths);
path_t *breadth_search(room_t *rooms);

//breadth_search/rate_rooms.c
bool rate_rooms(room_t *start);

//breadth_search/get_paths.c
path_t *get_paths(room_t *end);

//breadth_search/get_next_room.c
bool get_next_room(room_t **tested, int numero_path);

//move_ants/share_ants.c
void share_ants_paths(path_t *paths, ant_t **ants);

//move_ants/move_ants.c
void move_ants(ant_t **ants);


#define ERROR_NO_PATH		\
my_printf("No path found\n")

#endif