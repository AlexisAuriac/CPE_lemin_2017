/*
** EPITECH PROJECT, 2017
** lemin
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef enum {
	CONTINUE,
	SUCCESS,
	FAILURE
} quit_t;

typedef enum {
	FREE=0,
	OCCUPIED=1,
	START=2,
	END=4
} flag_t;

typedef struct tunnel tunnel_t;

typedef struct room {
	char *name;
	int x;
	int y;
	int path;
	int dist;
	flag_t flag;
	tunnel_t *tunnels;
	struct room *next;
} room_t;

struct tunnel {
	room_t *dest;
	int path;
	tunnel_t *next;
};

typedef struct ant {
	room_t *prev_room;
	room_t *room;
	int path;
	bool arrived;
} ant_t;

#endif