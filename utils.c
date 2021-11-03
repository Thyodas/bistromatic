/*
** EPITECH PROJECT, 2021
** UTILS
** File description:
** Utilitary function
*/
#include "include/my.h"
#include <stdlib.h>

void check_if_zero_neg(char *number)
{
    if (number[0] == '-' && number[1] == '0') {
        number[0] = '0';
        number[1] = '\0';
    }
}

void my_swap_ptr(char **str1_ptr, char **str2_ptr)
{
    char *temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

int my_char_is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_char_is_op(char c)
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int my_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_nbr(str[i]) == 0 && my_char_is_op(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
