/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Cleaning strings before
*/

char *remove_sign(char *input)
{
    char *output;

    if (input[0] != '-')
        return (input);
    output = malloc(sizeof(char) * (my_strlen(input) + 1));
    for (int i = 1; i < my_strlen(input); i++)
        output[i - 1] = input[i];
    return (output);
}

char *clean_sign(char *input)
{
    char *output = malloc(sizeof(char) * (my_strlen(input) + 1));
    int minus = 0;
    int temp_index = 0;

    for (int i = 0; i < my_strlen(input); i++)
        if (input[i] == '-')
            minus++;
    minus = minus % 2 == 0 ? 0 : 1;
    for (int i = 0; i < my_strlen(input); i++) {
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
    char *output = malloc(sizeof(char) * (my_strlen(input) + 1));
    int i = 0;
    int temp_index = 0;
    int passed = 0;

    if (input[0] == '-') {
        output[0] = '-';
        i = 1;
        temp_index = 1;
    }
    for (; i < my_strlen(input); i++)
        if (input[i] != '0' || passed) {
            passed = 1;
            output[temp_index++] = input[i];
        }
    return (output);
}

char *turbo_cleaning(char *input)
{
    char *output = malloc(sizeof(char) * (my_strlen(input) + 1));

    output = clean_sign(input);
    output = clean_zero_before(output);
    return (output);
}
