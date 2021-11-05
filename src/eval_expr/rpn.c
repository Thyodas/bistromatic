/*
** EPITECH PROJECT, 2021
** evalxpr
** File description:
** rpn.c
*/

#include "my_operators.h"
#include "my.h"
#include "unistd.h"
#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "bistromatic.h"

char *clean_zero_before(char *input, char zero_c, char sub_c, char plus_c);

char *int_to_str(int nb)
{
    int i = 0;
    int neg = 0;
    char *str = malloc(sizeof(char) * 12);

    if (nb < 0) {
        neg = 1;
        nb *= -1;
    }
    for (; nb >= 0; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        if (nb == 0)
            break;
    }
    if (neg == 1) {
        str[i + 1] = '-';
        i++;
    }
    str[i + 1] = '\0';
    return (my_revstr(str));
}

char *calculate_previous(stack_t *stack, operator_t *op)
{
    char *res = NULL;
    char *b = stack_pop(stack);
    char *a = stack_pop(stack);

    if (a == NULL || b == NULL) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    res = op->func(a[0] == '+' ? a + 1 : a, b[0] == '+' ? b + 1 : b);
    free(b);
    free(a);
    return (res);
}

stack_t *rpn(queue_t *queue, operator_t *operators_funcs)
{
    char *elt = queue_pop(queue);
    stack_t *new_stack = stack_create();
    operator_t *op = NULL;

    while (elt != NULL) {
        op = get_op(operators_funcs, elt);
        if (op->weight == 0)
            stack_push(new_stack, elt);
        else {
            stack_push(new_stack, calculate_previous(new_stack, op));
        }
        elt = queue_pop(queue);
    }
    return (new_stack);
}
