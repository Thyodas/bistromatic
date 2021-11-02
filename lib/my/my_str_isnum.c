/*
** EPITECH PROJECT, 2021
** MY_STR_ISNUM
** File description:
** Checks if a string contains only num
*/

static int is_num_str(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_num_str(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
