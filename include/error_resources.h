/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Contains error messages for the program.
*/

#ifndef ERROR_RESOURCES_H
#define ERROR_RESOURCES_H

//ants
#define ERROR_INVALID_ANT_NBR(nb_ants)		\
my_printf("Error: invalid number of ants: '%s'\n", nb_ants)
#define ERROR_NO_ANTS		\
my_putstr("Error: there must be at least 1 ant\n")

//room
#define ERROR_ROOM		\
my_putstr("Error: invalid room\n")
#define ERROR_SAME_COORDINATES		\
my_putstr("Error: two rooms have the same coordinates\n")
#define ERROR_SAME_NAMES		\
my_putstr("Error: two rooms have the same names\n")
#define ERROR_TWO_STARTS		\
my_putstr("Error: there is already a start\n")
#define ERROR_TWO_ENDS		\
my_putstr("Error: there is already an end\n")
#define ERROR_NO_START		\
my_putstr("Error: no start room\n")
#define ERROR_NO_END		\
my_putstr("Error: no end room\n")

//tunnel
#define ERROR_TUNNEL		\
my_putstr("Error: invalid tunnel\n")
#define ERROR_TUNNEL_INEXISTANT(room)		\
my_printf("Error: room doesn't exist: '%s'\n", room)

#endif