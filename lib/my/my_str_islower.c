/*
** EPITECH PROJECT, 2021
** MY_STR_ISLOWER
** File description:
** Checks if a string contains only lowercase
*/

static int is_lower_str(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_lower_str(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
