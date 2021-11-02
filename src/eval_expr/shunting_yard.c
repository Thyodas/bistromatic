/*
** EPITECH PROJECT, 2021
** shunting_yard.c
** File description:
** Implementation of the shunting yard algorithm in C
*/

#include <stdio.h>
#include "my.h"
#include "stack.h"
#include "queue.h"
#include "my_operators.h"

char *my_slicenbr_base(char const *str, char *base);

void op_handle(queue_t *queue, stack_t *stack, char *current,
operator_t *operators)
{
    operator_t *op = get_op(operators, current);
    char *top = stack_peek(stack);
    char *op_str = op->symbols;
    int op_weight = 0;

    if (op->weight != 0) {
        op_weight = get_op(op, op_str)->weight;
        while (get_op(op, top)->weight >= op_weight && my_strlen(top) != 0) {
            queue_add(queue, stack_pop(stack));
            top = stack_peek(stack);
        }
        stack_push(stack, op_str);
    }
}

int nb_handle(queue_t *queue, char const *str, int i, char *base)
{
    char *nbr = my_slicenbr_base(&str[i], base);
    int len = my_strlen(nbr);
    char temp[2] = {0};

    if (i > 0 && (str[i] == '-' || str[i] == '+')) {
        temp[0] = str[i - 1];
        if (str[i - 1] == ')'|| my_strstr(base, temp)) {
            free(nbr);
            return (0);
        }
    }
    if (len > 0) {
        queue_add(queue, nbr);
        return (len);
    } else {
        free(nbr);
        return (0);
    }
}

void bracket_handle(queue_t *queue, stack_t *stack, char *current)
{
    char *top = stack_peek(stack);

    if (my_strcmp("(", current) == 0) {
        stack_push(stack, "(");
    } else if (my_strcmp(")", current) == 0) {
        while (my_strcmp("(", top) != 0) {
            queue_add(queue, stack_pop(stack));
            top = stack_peek(stack);
        }
        stack_pop(stack);
    }
}

void stack_to_queue(stack_t *stack, queue_t *queue)
{
    char *top = stack_peek(stack);

    while (my_strlen(top) != 0) {
        queue_add(queue, stack_pop(stack));
        top = stack_peek(stack);
    }
    stack_free(stack);
}

queue_t *shunting_yard(char const *str, operator_t *operators, char *base)
{
    stack_t *stack = stack_create();
    queue_t *queue = queue_create();
    int i = 0;
    int nbr_len = 0;
    char current[2];
    current[1] = '\0';

    while (str[i] != '\0') {
        nbr_len = nb_handle(queue, str, i, base);
        if (nbr_len <= 0) {
            current[0] = str[i];
            op_handle(queue, stack, current, operators);
            bracket_handle(queue, stack, current);
            i++;
        } else
            i += nbr_len;
    }
    stack_to_queue(stack, queue);
    return (queue);
}
