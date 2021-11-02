/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include "my.h"

int eval_expr(char const *str);

Test(eval_expr, positive_int)
{
    cr_assert(eval_expr("1+1+1+1+1+1+1+1+1+1+1+10000+123+456") == 10590);
    cr_assert(eval_expr("10230+(12882+1313)+(122+232)") == 24779);
}

Test(eval_expr, parentheses_hell)
{
    cr_assert(eval_expr("((((((1+1000+2+3))))))") == 1006);
    cr_assert(eval_expr("((((10230)))+(((12882+1313)+(122+232))))") == 24779);
}

Test(eval_expr, negative_int)
{
    cr_assert(eval_expr("-18323+780-6789+(1387-178)-26+23-(-623)") == -22503);
    cr_assert(eval_expr("((-18323)+(780-6789)+(1387-178)-26+23-(-623))")
    == -22503);
}

Test(eval_expr, mul_div_mod)
{
    cr_assert(eval_expr("1762*323-1239+239%(232+1)/2+4") == 567894);
    cr_assert(eval_expr("((1762*323)-(1239+23389)%(232+1)/2+(4))")
    == 569049);
}

Test(eval_expr, zeros)
{
    cr_assert(eval_expr("0+00000+000+0+0+0+0+0+0+0+0+0+0-0-(-0)") == 0);
}
