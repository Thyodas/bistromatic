/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** formatting str
*/

#include "bistromatic.h"
#include "my.h"

char *remove_signs(char *input, char *signs)
{
    char *out = malloc(sizeof(char) * my_strlen(input) + 1);
    int index = 0;
    int detected = 0;
    int counter = 0;

    for (int i = 0; i < my_strlen(input); i++) {
        if (input[i] == signs[OP_SUB_IDX] || input[i] == signs[OP_PLUS_IDX]) {
            detected = 1;
            input[i] == signs[OP_SUB_IDX] ? counter++ : i;
        } else if (detected) {
            out[index++] = counter % 2 == 0 ? '+' : '-';
            out[index] = input[i];
            counter = 0;
            detected = 0;
        } else
            out[index] = input[i];
        index += detected ? 0 : 1;
    }
    out[index] = '\0';
    return (out);
}
