/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by libmy.a.
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdbool.h>

#define ALLOW "abcdefghijklmnopqrstuvwxyz"
#define ALUP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"

#define READ_SIZE 5

//write
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_printf(const char *str, ...);

//conversion
int my_getnbr(char const *str);

//files
char *get_next_line(int fd);
void my_fputs(int fd, const char *str);

//alloc
void *my_realloc(void *ptr, int const size);
void my_free_array(void **arr);

//my_str
int my_strlen(char const *str);
int my_strlen_tab(void * const *arr);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_ccount_str(const char c, const char *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strdup(char const *str);
char *my_append(char *str, char const *cat);
bool in_str(char const c, char const *str);
int my_index(const char c, const char *str);
bool my_str_is(const char *str, const char *allowed);
bool my_str_is_signednum(char *str);
char **my_str_split(const char *str, const char *seps);
void my_strip(char *str, const char *strip);
void my_rstrip(char *str, const char *strip);
void my_clean_str(char *str, const char *strip);
void my_sprintf(char *str, const char *format, ...);

#endif
