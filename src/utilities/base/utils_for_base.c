/*
** EPITECH PROJECT, 2021
** UTILS_FOR_BASE
** File description:
** Utilitary functions for base
*/

#include <stdlib.h>
#include "my.h"

char *str_initialize_alloc(char *input, int size);

int is_operator_minus_plus(char c, char *operators)
{
    if (c == operators[2] || c == operators[3])
        return 1;
    return 0;
}

int size_nbr(int nb)
{
    int size = 1;
    while (nb / 10 != 0) {
        nb /= 10;
        size++;
    }
    return size;
}

int search_base(char *base_from, char to_search)
{
    for (int i = 0; base_from[i] != '\0'; ++i) {
        if (base_from[i] == to_search) {
            return i;
        }
    }
    return -1;
}

int find_sign(char *number, char *operators, int *nb_of_sign)
{
    int nb_minus = 0;
    for (int i = 0; is_operator_minus_plus(number[i], operators); ++i) {
        if (number[i] == operators[3])
            nb_minus++;
        (*nb_of_sign)++;
    }
    if (nb_minus % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}

char *handle_sign(int sign, char *new_number)
{
    if (sign == 1)
        return new_number;
    int len = my_strlen(new_number);
    char *number_with_sign = malloc(sizeof(char) * len + 2);
    str_initialize_alloc(number_with_sign, len + 2);
    number_with_sign[0] = '-';
    my_strcpy(&number_with_sign[1], new_number);
    return number_with_sign;
}
