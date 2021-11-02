/*
** EPITECH PROJECT, 2021
** MY_SHOWSTR
** File description:
** Prints a string
*/
#include "my.h"

static int my_strlen_show(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static int my_putnbr_base_show(int nbr, char const *base)
{
    int base_len = my_strlen_show(base);
    int modulo = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    modulo = nbr % base_len;
    nbr /= base_len;
    if (nbr != 0) {
        my_putnbr_base_show(nbr, base);
    }
    my_putchar(base[modulo]);
    return 0;
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 127) {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base_show(str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return 0;
}
