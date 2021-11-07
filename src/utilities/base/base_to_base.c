/*
** EPITECH PROJECT, 2021
** BASE_TO_BASE
** File description:
** Convert from a base to another
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

char *my_getnbr_base_str(char *number, char *base_from, char *operators);
stack_base *fill_stack_nbr(char *nbr, char *base, char *operators);
char *compute_stack(stack_base *stack, char *base_to);

char *base_to_base(char *nb, char *base_from, char *base_to, char *operators)
{
    char *decimal = my_getnbr_base_str(nb, base_from, operators);
    stack_base *list = fill_stack_nbr(decimal, base_to, operators);
    return (compute_stack(list, base_to));
}
