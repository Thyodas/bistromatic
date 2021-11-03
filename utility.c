/*
** EPITECH PROJECT, 2021
** Utility
** File description:
** utility
*/

void my_rev_str(char *src)
{
    int ln;
    int temp;

    ln = my_strlen(src);
    for (int i = 0; i < ln / 2; i++) {
        temp = src[i];
        src[i] = src[ln - i - 1];
        src[ln - i - 1] = temp;
    }
}

int my_char_isnum(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

void reverse_strings(char *a, char *b)
{
    my_rev_str(a);
    my_rev_str(b);
}
