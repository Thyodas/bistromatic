/*
** EPITECH PROJECT, 2021
** Infin_div & Infin_mod
** File description:
** infin_div
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_operators.h"

char *my_add(char *a, char *b);
int my_lower(char *a, char *b);
int my_greater_equals(char *a, char *b);
int my_strlen(char const *str);
int my_getnbr(char const *str);

char *infin_div_two(char *dividend, char ***table, int index_table, int modulo)
{
    char *sum = NULL;
    char *tmp_sum = NULL;
    char *result = malloc(sizeof(char) * my_strlen(dividend));

    sum = "0";
    sum = my_add(sum, table[index_table - 1][1]);
    result[0] = '0';
    result[1] = '\0';
    result = my_add(result, table[index_table - 1][0]);
    free(table[index_table - 1][0]);
    for (int i = index_table - 1; i >= 0; i--)
        if (my_lower(my_add(sum, table[i][1]), dividend)) {
            tmp_sum = sum;
            sum = my_add(tmp_sum, table[i][1]);
            free(tmp_sum);
            result = my_add(result, table[i][0]);
        }
    return modulo ? (my_sub(dividend, sum)) : (result);
}

char *infin_div(char *dividend, char *divisor, int modulo)
{
    char ***table = malloc(sizeof(char **) * 100);
    char **lines = NULL;
    char *temp_value = NULL;
    char *temp_key = "1";
    int index_table = 0;

    while (1) {
        temp_value = my_mul(temp_key, divisor);
        if (my_greater_equals(temp_value, dividend))
            break;
        lines = malloc(sizeof(char *) * 3);
        lines[0] = temp_key;
        lines[1] = temp_value;
        table[index_table] = lines;
        index_table++;
        temp_key = my_mul(temp_key, "2");
    }
    return (infin_div_two(dividend, table, index_table, modulo));
}
