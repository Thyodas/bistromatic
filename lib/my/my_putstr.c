/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Prints a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
