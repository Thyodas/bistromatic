/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Function that find a substring in another
*/

static int my_strlen_str(char const *s1)
{
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    return i;
}

static int my_strncmp_str(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1) {
        i++;
    }
    return s1[i] - s2[i];
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int length = my_strlen_str(to_find);

    if (my_strlen_str(to_find) == 0)
        return str;
    while (str[i] != '\0') {
        if (my_strncmp_str(&str[i], to_find, length) == 0) {
            return &str[i];
        }
        i++;
    }
    return 0;
}
