/*
** EPITECH PROJECT, 2021
** MY_STR_ISALPHA
** File description:
** Check is strings contains alpha num
*/

static int is_alpha_num_str(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alpha_num_str(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
