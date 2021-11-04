/*
** EPITECH PROJECT, 2021
** Format
** File description:
** Format(str, operators) to clean extra signs
*/

#include <stdlib.h>

int my_strlen(char *str);

int format_counter(char *str)
{
    int counter = my_strlen(str);

    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == '-' && str[i + 1] == '(')
            counter++;
    return (counter);
}

char *format_one(char *str, char *signs)
{
    char *output = malloc(sizeof(char) * (format_counter(str)));
    int output_index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == signs[3] && str[i + 1] == signs[0]) {
            output[output_index] = signs[3];
            output[output_index + 1] = '1';
            output[output_index + 2] = signs[0];
            output[output_index + 3] = signs[4];
            output_index += 4;
            i++;
        } else if (str[i] == signs[2] && str[i + 1] == signs[0]) {
            output[output_index] = signs[0];
            output_index++;
            i++;
        } else
            output[output_index++] = str[i];
    }
    return (output);
}

char *format(char *input, char *signs)
{
    char *out = malloc(sizeof(char) * my_strlen(input) + 1);
    int index = 0;
    int detected = 0;
    int counter = 0;

    for (int i = 0; i < my_strlen(input); i++) {
        if (input[i] == signs[3] || input[i] == signs[2]) {
            detected = 1;
            input[i] == signs[3] ? counter++ : i;
            continue;
        } else if (detected) {
            out[index++] = counter % 2 == 0 ? '+' : '-';
            out[index++] = input[i];
            counter = 0;
            detected = 0;
            continue;
        } else {
            out[index] = input[i];
            index++;
        }
    }
    return (format_one(out, signs));
}
