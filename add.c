/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** main.c
*/
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

void check_if_swap(char *nb1, char *nb2)
{
    if (my_strcmp(&nb1[1], &nb2[1]))
        my_swap_ptr(&nb1, &nb2);
}

char *add(char *nb1, char *nb2)
{
    int len_nb1wn = (nb1[0] == '-') ? my_strlen(nb1) - 1 : my_strlen(nb1);
    int len_nb2wn = (nb2[0] == '-') ? my_strlen(nb2) - 1 : my_strlen(nb2);
    if (len_nb1wn > len_nb2wn)
        my_swap_ptr(&nb1, &nb2);
    else if (len_nb1wn == len_nb2wn) {
        check_if_swap(nb1, nb2);
    }
    len_nb1wn = (nb1[0] == '-') ? my_strlen(nb1) - 1 : my_strlen(nb1);
    len_nb2wn = (nb2[0] == '-') ? my_strlen(nb2) - 1 : my_strlen(nb2);
    return (add_classic(nb1, nb2, 1));
}
