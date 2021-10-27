/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Check conditions
*/

int EQUAL(char *a, char *b)
{
    char *str1 = absolute_cleaning(a);
    char *str2 = absolute_cleaning(b);

    if (my_strcmp(str1, str2) == 0)
        return (1);
    return (0);
}

int GREATER_EQUALS(char *a, char *b)
{
    char *str1 = absolute_cleaning(a);
    char *str2 = absolute_cleaning(b);

    if (my_strcmp(str1, str2) >= 0)
        return (1);
    return (0);
}

int GREATER(char *a, char *b)
{
    char *str1 = absolute_cleaning(a);
    char *str2 = absolute_cleaning(b);

    if (my_strcmp(str1, str2) >= 1)
        return (1);
    return (0);
}

int LOWER(char *a, char *b)
{
    char *str1 = absolute_cleaning(a);
    char *str2 = absolute_cleaning(b);

    if (my_strcmp(str1, str2) <= -1)
        return (1);
    return (0);
}

int LOWER_EQUALS(char *a, char *b)
{
    char *str1 = absolute_cleaning(a);
    char *str2 = absolute_cleaning(b);

    if (my_strcmp(str1, str2) <= 0)
        return (1);
    return (0);
}
