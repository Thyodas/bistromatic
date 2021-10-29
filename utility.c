/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** c'est dans le titre
*/

int my_char_is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_arr_size(char **arr)
{
    int i = 0;

    for (; arr[i] != 0; i++);
    return (i);
}
