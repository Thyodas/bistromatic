/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"

char *full_format(char *str);

static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    int size = 0;
    char *expr = NULL;
    char *result = NULL;

    if (ac != 4 || my_strcmp(av[1], "-h") == 0) {
        my_putstr("Usage: \n./calc base operators size_read\n\nDESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n- operators: the sym");
        my_putstr("bols for the parentheses and the 5 operators\n- size_read");
        my_putstr(":    number of characters to be read\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = full_format(get_expr(size));
    result = eval_expr(av[1], av[2], expr, size);
    my_putstr(result);
    free(expr);
    free(result);
    return (EXIT_SUCCESS);
}
