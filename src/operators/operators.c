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

char *my_add(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = malloc(sizeof(char) * (my_strlen(a) + 1));
    char *s2 = malloc(sizeof(char) * (my_strlen(b) + 1));

    s1 = my_strcpy(s1, a);
    s2 = my_strcpy(s2, b);
    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_add_sub(neg_a ? &s1[1] : s1,
    neg_b ? &s2[1] : s2, neg_a, neg_b);
    return (result);
}

char *my_mod(char *a, char *b)
{
    int temp = my_getnbr(a) % my_getnbr(b);

    return (int_to_str(temp));
}
