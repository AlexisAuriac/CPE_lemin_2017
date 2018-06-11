/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** General error messages.
*/

#ifndef ERROR_H
#define ERROR_H

#define ERROR_MALLOC		\
my_fputs(STDERR_FILENO, "Malloc failed\n")
#define ERROR_NB_PARAMS		\
my_putstr("Invalid number of parameters\n")

#endif