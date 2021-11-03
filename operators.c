/*
** EPITECH PROJECT, 2021
** evalxpr
** File description:
** operators.c
*/

#include <unistd.h>
#include "my.h"
#include "my_operators.h"

int my_mul(int a, int b)
{
    int temp = a * b;

    return (temp);
}

int my_div(int a, int b)
{
    int temp = a / b;

    return (temp);
}

int my_sub(int a, int b)
{
    int temp = a - b;

    return (temp);
}

int my_add(int a, int b)
{
    int temp = a + b;

    return (temp);
}

int my_mod(int a, int b)
{
    int temp = a % b;

    return (temp);
}
