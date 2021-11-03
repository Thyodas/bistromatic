/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Cleaning strings before
*/

#include "include/my.h"

char *remove_sign(char *input)
{
    int len = my_strlen(input);
    char *output = NULL;

    if (input[0] != '-')
        return (input);
    output = malloc(sizeof(char) * (len + 1));
    initialize(output, len + 1);
    for (int i = 1; i < len; i++)
        output[i - 1] = input[i];
    free(input);
    return (output);
}

char *clean_sign(char *input)
{
    int len = my_strlen(input);
    char *output = malloc(sizeof(char) * (len + 1));
    initialize(output, len + 1);
    int minus = 0;
    int temp_index = 0;

    for (int i = 0; i < len; i++)
        if (input[i] == '-')
            minus++;
    minus = minus % 2 == 0 ? 0 : 1;
    for (int i = 0; i < len; i++) {
        if (minus == 1) {
            output[0] = '-';
            minus = 99;
            i++;
            temp_index++;
        }
        if (my_char_is_nbr(input[i]))
            output[temp_index++] = input[i];
    }
    return (output);
}

char *clean_zero_before(char *input)
{
    int len = my_strlen(input);
    char *output = malloc(sizeof(char) * (len + 1));
    initialize(output, len + 1);
    int i = 0;
    int temp_index = 0;
    int passed = 0;

    if (input[0] == '-') {
        output[0] = '-';
        i = 1;
        temp_index = 1;
    }
    for (; i < len; i++)
        if (input[i] != '0' || passed) {
            passed = 1;
            output[temp_index++] = input[i];
        }
    free(input);
    return (output);
}

char *turbo_cleaning(char *input)
{
    int len = my_strlen(input);
    char *output = malloc(sizeof(char) * (len + 1));
    initialize(output, len + 1);

    output = clean_sign(input);
    output = clean_zero_before(output);
    return (output);
}
