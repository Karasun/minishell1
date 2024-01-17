/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h_of_minishell_1
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "gnl.h"

typedef struct env_s
{
    char **env;
	char **tab;

}env_t;

typedef struct node_s
{
    struct node_s *next;
    struct node_s *prev;
    char *str;
}node_t;

typedef struct control_s
{
    node_t *begin;
    node_t *end;
}control_t;

int is_separator(char c, char *seps);
int count_required_chars(char *str, int *nb_words, char *seps);
void    fill_word_array(char **wt, char *words, char *str, char *seps);
char    **my_str_to_word_array(char *str, char *separators);
int infinite_while(env_t *my_env);
char *search_path(char **env);
int main(int ac, char **av, char **env);
void my_putchar(char c);
void my_putstr(char *str);

#endif
