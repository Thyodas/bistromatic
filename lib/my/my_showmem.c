/*
** EPITECH PROJECT, 2021
** MY_SHOWMEM
** File description:
** Prints a memory dump
*/
#include <unistd.h>
#include "my.h"

static int my_strlen_mem(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static void print_hexacontent(char const *str, int position)
{
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 0 && i != 0)
            my_putchar(' ');
        if (str[i + position] < 16)
            my_putchar('0');
        my_putnbr_base(str[i + position], "O123456789ABCDEF");
    }
    my_putchar(' ');
}

static void print_content(char const *str, int position)
{
    for (int i = 0; i < 16; i++) {
        if (str[i + position] < 32 || str[i + position] > 127)
            my_putchar('.');
        else
            my_putchar(str[i + position]);
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        my_putnbr_base(str[i], "0123456789ABCDEF");
        write(1, ": ", 2);
        print_hexacontent(str, i);
        print_content(str, i);
    }
}
