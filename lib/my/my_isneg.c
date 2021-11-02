/*
** EPITECH PROJECT, 2021
** MY_ISNEG
** File description:
** Function that checks if a number is positive or negative
*/
#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}
