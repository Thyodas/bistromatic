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
char *inf_mul(char *number1, char *number2, int sign);

char *my_mul(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_mul(s1, s2, neg_a == neg_b);
    return (result);
}

char *my_div(char *a, char *b)
{
    int minus = 0;
    char *s1 = malloc(sizeof(char) * (remove_sign(my_strlen(a)) + 1));
    char *s2 = malloc(sizeof(char) * (remove_sign(my_strlen(b)) + 1));
    char *modulo = NULL;
    char *result = NULL;

    if (a[0] == '-')
        minus++;
    if (b[0] == '-')
        minus++;
    s1 = my_strcpy(s1, a);
    s2 = my_strcpy(s2, b);
    modulo = infin_div(s1, s2, 0);
    if (minus == 1) {
        result = malloc(sizeof(char) * (my_strlen(result) + 2));
        result[0] = '-';
        my_strcpy(result, modulo);
        return (result);
    }
    return (modulo);
}

char *my_sub(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_add_sub(neg_a ? &s1[1] : s1,
    neg_b ? &s2[1] : s2, neg_a, !neg_b);
    free(s1);
    free(s2);
    return (result);
}

char *my_add(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_add_sub(neg_a ? &s1[1] : s1,
    neg_b ? &s2[1] : s2, neg_a, neg_b);
    free(s1);
    free(s2);
    return (result);
}

char *my_mod(char *a, char *b)
{
    int minus = 0;
    char *s1 = malloc(sizeof(char) * (remove_sign(my_strlen(a)) + 1));
    char *s2 = malloc(sizeof(char) * (remove_sign(my_strlen(b)) + 1));
    char *modulo = NULL;
    char *result = NULL;

    if (a[0] == '-')
        minus++;
    if (b[0] == '-')
        minus++;
    s1 = my_strcpy(s1, a);
    s2 = my_strcpy(s2, b);
    modulo = infin_div(s1, s2, 1);
    if (minus == 1) {
        result = malloc(sizeof(char) * (my_strlen(result) + 2));
        result[0] = '-';
        my_strcpy(result, modulo);
        return (result);
    }
    return (modulo);
}
