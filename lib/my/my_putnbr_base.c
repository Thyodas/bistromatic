/*
** EPITECH PROJECT, 2021
** MY_PUTNBR_BASE
** File description:
** Convert a decimal into a given base
*/
#include "my.h"

static int my_strlen_put(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen_put(base);
    int modulo = 0;
    long int bigger_nbr = nbr;

    if (bigger_nbr < 0) {
        my_putchar('-');
        bigger_nbr *= -1;
    }
    modulo = bigger_nbr % base_len;
    bigger_nbr /= base_len;
    if (bigger_nbr != 0) {
        my_putnbr_base(bigger_nbr, base);
    }
    my_putchar(base[modulo]);
    return 0;
}
