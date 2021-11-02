/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Main for the bistromatic
*/

#include "include/my.h"

int error_handling(int error)
{
    if (error == 0)
        write(2, "Wrong arguments\n", 16);
    if (error == 1)
        write(2, "Wrong number of arguments\n", 26);
    return (84);
}

int main(int argc, char **av)
{
    if (av[1] == 0 || av[2] == 0)
        return (error_handling(0));
    if (!my_isnum(av[1]) || !my_isnum(av[2]))
        return (error_handling(0));
    if (argc != 3)
        return (error_handling(1));
    char *number1 = turbo_cleaning(av[1]);
    char *number2 = turbo_cleaning(av[2]);
    int sign_nb1 = (number1[0] == '-') ? -1 : 1;
    int sign_nb2 = (number2[0] == '-') ? -1 : 1;
    number1 = remove_sign(number1);
    number2 = remove_sign(number2);
    int sign_tot = 1;
    if (sign_nb1 != sign_nb2)
        sign_tot = -1;
    inf_mul(number1, number2, sign_tot);
}
