/*
** EPITECH PROJECT, 2021
** MY_STR_ISUPPER
** File description:
** Checks if a string contains only uppercase
*/

static int is_upper_str(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_upper_str(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
