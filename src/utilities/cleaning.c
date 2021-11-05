/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Cleaning strings before
*/

#include <stdlib.h>
#include "bistromatic.h"

int my_strlen(char *input);

char *remove_sign(char *input)
{
    char *output = NULL;
    int i = 0;

    if (input[0] != '-')
        return (input);
    output = malloc(sizeof(char) * (my_strlen(input) + 1));
    for (i = 1; i < my_strlen(input); i++)
        output[i - 1] = input[i];
    output[i - 1] = '\0';
    return (output);
}

char *add_minus(char *input)
{
    char *output = malloc(sizeof(char) * (my_strlen(input) + 2));
    int index = 0;

    output[0] = '-';
    for (int i = 1; i <= my_strlen(input); i++) {
        if (i == 0)
            continue;
        output[i] = input[index];
        index++;
    }
    return (output);
}

char *clean_zero_before(char *input, char zero_c, char sub_c, char plus_c)
{
    char *output = malloc(sizeof(char) * (my_strlen(input) + 1));
    int i = 0;
    int temp_index = 0;
    int passed = 0;

    if (input[0] == sub_c || input[0] == plus_c) {
        output[0] = input[0];
        i = 1;
        temp_index = 1;
    }
    for (; i < my_strlen(input); i++)
        if (input[i] != zero_c || passed) {
            passed = 1;
            output[temp_index++] = input[i];
        }
    free(input);
    output[0] = zero_c;
    output[temp_index] = '\0';
    return (output);
}
