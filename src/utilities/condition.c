/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Check conditions
*/

int my_equal(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;

    if (cmp_gt(str1, str2) == 0)
        return (1);
    return (0);
}

int my_greater_equals(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;

    if (cmp_gt(str1, str2) >= 0)
        return (1);
    return (0);
}

int my_greater(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;

    if (cmp_gt(str1, str2) >= 1)
        return (1);
    return (0);
}

int my_lower(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;

    if (cmp_gt(str1, str2) <= -1)
        return (1);
    return (0);
}

int my_lower_equals(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;

    if (cmp_gt(str1, str2) <= 0)
        return (1);
    return (0);
}
