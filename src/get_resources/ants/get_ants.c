/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** Recuperate the ant array from the users input.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lemin.h"

static char *get_nb_ant_line(void)
{
	char *line = NULL;

	do {
		if (line != NULL)
			free(line);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			return (NULL);
		clean_str(line);
	} while (my_strlen(line) == 0);
	if (!my_str_is(line, NUM)) {
		ERROR_INVALID_ANT_NBR(line);
		free(line);
		return (NULL);
	}
	return (line);
}

static int get_nb_ants(void)
{
	char *line = get_nb_ant_line();
	int nb_ants = 0;

	if (line == NULL)
		return (0);
	nb_ants = my_getnbr(line);
	free(line);
	if (nb_ants == 0)
		ERROR_NO_ANTS;
	return (nb_ants);
}

static bool create_ants(ant_t **ants, int nb_ants)
{
	for (int i = 0 ; i < nb_ants ; ++i) {
		ants[i] = malloc(sizeof(ant_t));
		if (ants[i] == NULL) {
			ERROR_MALLOC;
			while (i--)
				free(ants[i]);
			free(ants);
			return (false);
		}
		ants[i]->room = NULL;
		ants[i]->arrived = false;
		ants[i]->path = 0;
	}
	return (true);
}

ant_t **get_ants(void)
{
	int nb_ants = 0;
	ant_t **ants = NULL;

	my_putstr("#number_of_ants\n");
	nb_ants = get_nb_ants();
	if (nb_ants == 0)
		return (NULL);
	ants = malloc(sizeof(ant_t *) * (nb_ants + 1));
	if (ants == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	ants[nb_ants] = NULL;
	if (!create_ants(ants, nb_ants))
		return (NULL);
	my_printf("%d\n", nb_ants);
	return (ants);
}