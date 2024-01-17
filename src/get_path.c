/*
** EPITECH PROJECT, 2018
** get_path.c
** File description:
** get_path_for_minishell1
*/

#include "../inc/my.h"

char *search_path(char **env)
{
	int i = 0;

    if (env == NULL)
        return (NULL);
	while (env[i] != NULL && env[i][0] != 'P' && env[i][1] != 'A' &&
        env[i][2] != 'T' && env[i][3] != 'H') {
            i++;
	}
    return (env[i + 5]);
}

control_t *create_list(void)
{
    control_t *nl = malloc(sizeof(*nl));

    if (nl != NULL) {
        nl->begin = NULL;
        nl->end = NULL;
    }
    return (nl);
}

node_t *create_node(control_t *l, char *str)
{
    node_t *elem = malloc(sizeof(*elem));

    elem->str = str;

    if (!l->begin) {
        l->begin = elem;
        l->end = elem;
    } else
        elem->prev = l->end;
        l->end->next = elem;

    elem->next = NULL;
    l->end = elem;
}

control_t *my_list_add(void* data, control_t *list)
{
	control_t* l;

	l = malloc(sizeof(control_t));
	l->data = data;
	l->next = list;
	return (l);
}

control_t *my_params_in_list(int ac, char **av)
{
	control_t* l = 0;
	int i = 0;

	while(i < ac) {
		l = my_list_add(av[i], l);
		i = i + 1;
	}
	return (l);
}

/*linked_list **list = malloc(sizeof(linked_list *));
*list = NULL;

create_list(linked_list **node, ...)
{
    linked_list *new_node = malloc(sizeof(linked_list));
    linked_list *move = *list;

    new_node = remplir_node_de _data(...);
    new_node->next = NULL;
    if (*node == NULL) {
        move->prev = NULL;
        *node = new_node;
    } else {
        while (move)
            move = move->next;
        move->next = new_node;
        new_node->prev = move;
    }
}

void parcour(linked_list **my_list)
{
    linked_list *tmp = *my_list;

    while (tmp) {
        printf(ressource);
        tmp = tmp->next;
    }
}
*/
