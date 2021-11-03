/*
** EPITECH PROJECT, 2021
** ADD
** File description:
** Function for the addition
*/
#include "include/my.h"
#include <stdlib.h>

int helper_add(char *new_number, int total, int *counter, int *carry)
{
    *carry = total / 10;
    new_number[*counter] = (total % 10) + '0';
    *counter = *counter + 1;
    return 1;
}

char *add_classic(char *number1, char *number2, int sign)
{
    int len_nb1 = my_strlen(number1);
    int len_nb2 = my_strlen(number2);
    char *new_number = malloc(sizeof(char) * len_nb2 + 2);
    initialize(new_number, len_nb2 + 2);
    int carry = 0;
    int counter = 0;
    for (int i = len_nb1 - 1; i >= 0 && number1[i] != '-'; i--) {
        int total = (number1[i] - '0') + (number2[len_nb2 - 1] - '0') + carry;
        len_nb2 -= helper_add(new_number, total, &counter, &carry);
    }
    for (int i = len_nb2 - 1; i >= 0 && number2[i] != '-'; i--) {
        int total = (number2[i] - '0') + carry;
        helper_add(new_number, total, &counter, &carry);
    }
    if (carry != 0)
        new_number[counter++] = '1';
    if (sign == -1)
        new_number[counter] = '-';
    my_revstr(new_number);
    return (new_number);
}
