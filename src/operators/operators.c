/*
** EPITECH PROJECT, 2021
** evalxpr
** File description:
** operators.c
*/

#include <unistd.h>
#include "my.h"
#include "my_operators.h"

char *inf_add_sub(char *a, char *b, int neg_a, int neg_b);
char *int_to_str(int nb);

char *my_mul(char *a, char *b)
{
    int temp = my_getnbr(a) * my_getnbr(b);

    return (int_to_str(temp));
}

char *my_div(char *a, char *b)
{
    int temp = my_getnbr(a) / my_getnbr(b);

    return (int_to_str(temp));
}

char *my_sub(char *a, char *b)
{
    int temp = my_getnbr(a) - my_getnbr(b);

    return (int_to_str(temp));
}

/*char *my_add(char *a, char *b)
{
    char *neg_a = 0;
    char *neg_b = 0;
    char *result = NULL;
    char *err_code = 0;

    neg_a = a[0] == '-';
    neg_b = b[0] == '-';
    result = inf_add_sub(neg_a ? &a[1] : a,
    neg_b ? &b[1] : b, neg_a, neg_b);
    return (result);
}*/
char *my_add(char *a, char *b)
{
    int temp = my_getnbr(a) + my_getnbr(b);

    return (int_to_str(temp));
}

char *my_mod(char *a, char *b)
{
    int temp = my_getnbr(a) % my_getnbr(b);

    return (int_to_str(temp));
}
