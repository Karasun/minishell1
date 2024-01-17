/*
** EPITECH PROJECT, 2018
** main
** File description:
** main_of_minishell_1
*/

#include "../inc/my.h"

int is_separator(char c, char *seps)
{
    while (*seps) {
        if (c == *seps)
            return (1);
        seps++;
    }
    return (0);
}

int count_required_chars(char *str, int *nb_words, char *seps)
{
    int	i = 0;
    int	count = 0;
    int	nb_words_tmp = 1;

    while (is_separator(str[i], seps))
        i++;
    while (str[i]) {
        if (is_separator(str[i], seps)) {
            while (is_separator(str[i], seps))
                i++;
            if (str[i] != 0)
                nb_words_tmp++;
        }
        else
            i++;
        count++;
    }
    *nb_words = nb_words_tmp;
    return (count + 1);
}

void    fill_word_array(char **wt, char *words, char *str, char *seps)
{
    int	wt_i = 0;
    int	words_i = 0;
    int	str_i = 0;

    while (is_separator(str[str_i], seps))
        str_i++;
    while (str[str_i]) {
        while (is_separator(str[str_i], seps))
            str_i++;
        if (!is_separator(str[str_i], seps) && str[str_i]) {
            wt[wt_i] = words + words_i;
            wt_i++;
            while (!is_separator(str[str_i], seps) && str[str_i])
                words[words_i++] = str[str_i++];
            words[words_i] = 0;
            words_i++;
        }
    }
    wt[wt_i] = NULL;
}

char    **my_str_to_word_array(char *str, char *separators)
{
    int	count;
    int	nb_words;
    char *word_array;

    if (!str)
        return (NULL);
    count = count_required_chars(str, &nb_words, separators);
    if (count == 0)
        return (NULL);
    if (!(word_array = malloc((sizeof(char*) * (nb_words + 1)) + count)))
        return (NULL);
    fill_word_array((char **)word_array,
        word_array + (sizeof(char*) * (nb_words + 1)), str, separators);
    return ((char **)word_array);
}
