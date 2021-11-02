/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** eval_expr
*/

#include <stdio.h>
#include "my.h"
#include "queue.h"
#include "stack.h"
#include "my_operators.h"

queue_t *shunting_yard(char const *str, operator_t *operators, char *base);
stack_t *rpn(queue_t *queue, operator_t *operators_funcs);
char *format(char *str);

char *eval_expr(char *base, char *op, char *str, int size)
{
    char *result_str = NULL;
    char *result = NULL;
    operator_t operators[] = {{"+", &my_add, 1},
        {"-", &my_sub, 1}, {"/", &my_div, 2}, {"*", &my_mul, 2},
        {"%", &my_mod, 2}, {"", NULL, 0}};
    queue_t *result_queue = shunting_yard(format(str), operators, "0123456789");
    stack_t *result_stack = rpn(result_queue, operators);

    queue_free(result_queue);
    result_str = stack_pop(result_stack);
    result = convert_base(result_str, "0123456789", base);
    free(result_str);
    stack_free(result_stack);
    return (result);
}
