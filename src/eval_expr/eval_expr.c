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
#include "bistromatic.h"

queue_t *shunting_yard(char const *str, operator_t *operators, char *base);
stack_t *rpn(queue_t *queue, operator_t *operators_funcs);
char *format(char *str, char *signs);
char *clean_zero_before(char *input);
char *full_format(char *str);

char *to_str(char c)
{
    char *new = malloc(sizeof(char) * 2);

    new[0] = c;
    new[1] = '\0';
    return (new);
}

void free_operators_str(operator_t *operators)
{
    for (int i = 0 ; operators[i].weight != 0 ; i++) {
        free(operators[i].symbols);
    }
}

char *eval_expr(char *base, char *op, char *str)
{
    char *result_str = NULL;
    char *result = NULL;
    char *format_str = full_format(str);

    operator_t operators[] = {{to_str(op[OP_PLUS_IDX]), &my_add, 1},
        {to_str(op[OP_SUB_IDX]), &my_sub, 1},
        {to_str(op[OP_MULT_IDX]), &my_mul, 2},
        {to_str(op[OP_DIV_IDX]), &my_div, 2},
        {to_str(op[OP_MOD_IDX]), &my_mod, 2},
        {"", NULL, 0}
    };
    queue_t *result_queue = shunting_yard(format_str, operators, "0123456789");
    free(format_str);
    stack_t *result_stack = rpn(result_queue, operators);
    queue_free(result_queue);
    result_str = stack_pop(result_stack);
    if (stack_pop(result_stack) != NULL || result_str == NULL) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit (84);
    }
    result = clean_zero_before(result_str);
    stack_free(result_stack);
    free_operators_str(operators);
    return (result);
}
