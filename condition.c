/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Check conditions
*/

int EQUAL(char *a, char *b)
{
    char *str1 = clean_sign(a);
    char *str2 = clean_sign(b);

    if (my_strcmp(str1, str2) == 0)
        return (1);
    return (0);
}
