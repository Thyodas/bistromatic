/*
** EPITECH PROJECT, 2021
** TEST_BASE
** File description:
** Tests for the base functions
*/

#include <criterion/criterion.h>
#include "my.h"

char *decimal_to_base(char *nb, char *base_to, char *operators);
int search_base(char *base_from, char to_search);

Test(search_base, search_base_tests)
{
    cr_assert_eq(search_base("0123456789ABCDEF", '2'), 2);
    cr_assert_eq(search_base("01", '1'), 1);
    cr_assert_eq(search_base("01", '2'), -1);
}

Test(decimal_to_base, decimal_to_base_classic)
{
    cr_assert_str_eq(decimal_to_base("123", "0123456789ABCDEF", 
    "()+-*/%"), "7B");
    cr_assert_str_eq(decimal_to_base("123", "01", "()+-*/%"),
    "1111011");
}

