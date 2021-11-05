/*
** EPITECH PROJECT, 2021
** INFIN_DIV
** File description:
** division for infinite numbers
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_operators.h"

char *my_add(char *a, char *b);
int my_lower(char *a, char *b);
int my_greater_equals(char *a, char *b);
int my_strlen(char const *str);
int my_getnbr(char const *str);

char *my_arr_sum(char **array)
{
    int count = 0;
    char *result = NULL;
    int i;
    int index = 0;

    for (i = 0; array[i] != 0; i++)
        count += my_strlen(array[i]);
    result = malloc(sizeof(char) * (count + 2));
    result = "0";
    index = i;
    for (i = 0; i < index; i++)
        result = my_add(result, array[i]);
    result[count] = '\0';
    return (result);
}

char *infin_div_two(char *dividend, char ***table, int index_table, int modulo)
{
    char **values = malloc(sizeof(char *) * (index_table + 1));
    char *result = malloc(sizeof(char) * my_strlen(dividend));
    int value = 1;

    values[0] = table[index_table - 1][1];
    result = my_add(result, table[index_table - 1][0]);
    for (int i = index_table - 1; i >= 0; i--)
        if (my_lower(my_add(my_arr_sum(values), table[i][1]), dividend)) {
            values[value] = table[i][1];
            value++;
            result = my_add(result, table[i][0]);
        }
    return modulo ? (my_sub(dividend, my_arr_sum(values))) : (result);
}

char *infin_div(char *dividend, char *divisor, int modulo)
{
    char ***table = malloc(sizeof(char **) * 100);
    char **lines = NULL;
    char *temp_value = malloc(sizeof(char) * my_strlen(divisor));
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
