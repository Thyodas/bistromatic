/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

char *inf_add_sub(char *a, char *b, int neg_a, int neg_b);
void check_error(int argc, char **argv, int *err_code);
char *strip_zeros(char *str);

int main(int argc, char **argv)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    int err_code = 0;

    check_error(argc, argv, &err_code);
    if (err_code != 0)
        return (err_code);

    neg_a = argv[1][0] == '-';
    neg_b = argv[2][0] == '-';
    result = inf_add_sub(neg_a ? &argv[1][1] : argv[1],
    neg_b ? &argv[2][1] : argv[2], neg_a, neg_b);
    my_putstr(strip_zeros(result));
    my_putstr("\n");
    free(result);
    return (err_code);
}