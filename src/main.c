/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of minishell
*/

#include "../inc/my.h"

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_putstr(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        my_putchar(str[i]);
}

int main(int ac, char **av, char **env)
{
    char **my_env = env;
    char **path = NULL;
    char *buffer = NULL;
    size_t len = 0;

    while (1) {
        my_putstr("$> ");
        getline(&buffer, &len, stdin);
        my_putstr(search_path(my_env));
    }
    return (0);
}
