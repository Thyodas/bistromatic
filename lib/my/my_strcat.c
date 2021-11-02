/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Function that concatenates two strings
*/

static int my_strlen_cat(char *dest)
{
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }

    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen_cat(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';

    return dest;
}
