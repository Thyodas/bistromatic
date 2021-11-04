/*
** EPITECH PROJECT, 2021
** B-CPE-101-STG-1-1-evalexpr-noah.gosciniak
** File description:
** utils.c
*/

#include "my.h"
#include "my_operators.h"
#include <unistd.h>

operator_t *get_op(operator_t *array, char *str)
{
    int i = 0;

    for (; my_strstr(array[i].symbols, str) == NULL &&
    array[i].weight != 0; i++);
    return (&array[i]);
}

static void find_nbr(char const *str, int *is_neg, int *start_end, char *base)
{
    int i = 0;
    char temp[2] = "a";

    start_end[0] = i;
    if (str[i] == '-') {
        *is_neg = 1;
        i = 1;
    } else if (str[i] == '+') {
        *is_neg = 0;
        i = 1;
    }
    temp[0] = str[i];
    while (str[i] != '\0' && my_strstr(base, temp) != 0) {
        i++;
        temp[0] = str[i];
    }
    start_end[1] = i;
}

char *my_slicenbr_base(char const *str, char *base)
{
    int is_neg = 0;
    int start_end[2] = {0, 0};
    char *return_str = NULL;
    int len = 0;

    find_nbr(str, &is_neg, start_end, base);
    len = start_end[1] - start_end[0];
    return_str = malloc(sizeof(char) * (len + 1));
    if (len == 0) {
        return_str[0] = '\0';
        return (return_str);
    }
    for (int i = start_end[0] ; i < start_end[1] ; i++)
        return_str[i] = str[i];
    return_str[len] = '\0';
    return (return_str);
}

