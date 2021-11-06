/*
** EPITECH PROJECT, 2021
** DECIMAL_TO_BASE
** File description:
** Convert a decimal in a base
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

int stack_base_size(stack_base *begin);

char *compute_stack(stack_base *stack, char *base_to)
{
    int list_size = stack_base_size(stack);
    char *output = malloc(sizeof(char) * list_size + 1);
    int index = 0;

    while (stack != NULL) {
        char mod = my_getnbr(stack->nbr);
        free(stack->nbr);
        char to_push = base_to[mod];
        output[index++] = to_push;
    }
    output[index] = '\0';
    return output;
}

stack_base *fill_stack_nbr(char *nbr, char *base)
{
    stack_base *stack = NULL;
    int len_base = my_strlen(base);
    int size = size_nbr(len_base);
    char *len_base_in_str = malloc(sizeof(char) * size + 1);
    str_initialize_alloc(len_base_in_str, size + 1);
    my_putnbr_base_str(len_base, "0123456789", len_base_in_str);

    while (nbr[0] != '0') {
        char *remainder = my_mod(nbr, len_base_in_str);
        char *to_push = clean_zero_before(remainder);
        my_add_in_stack_base(&stack, to_push);
        int len_nbr = my_strlen(nbr);
        char *tmp = malloc(sizeof(char) * len_nbr + 1);
        my_strcpy(tmp, nbr);
        nbr = my_div(tmp, len_base_in_str);
        free(tmp);
    }
    free(len_base_in_str);
    return stack;
}

char *decimal_to_base(char *nb, char *base_to, char *operators)
{
    stack_base *list = fill_stack_nbr(nb, base_to);
    char *output = compute_stack(list, base_to);
    return (output);
}
