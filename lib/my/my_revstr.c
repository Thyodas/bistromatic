/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** Function that reverses a string
*/

static void my_swap_rev(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

static int my_strlen_rev(char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        i++;
    }

    return i;
}

char *my_revstr(char *str)
{
    int length = my_strlen_rev(str);

    for (int i = 0; i < length / 2; i++) {
        my_swap_rev(&str[i], &str[length - i - 1]);
    }

    return str;
}
