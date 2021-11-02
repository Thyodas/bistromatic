/*
** EPITECH PROJECT, 2021
** my_operators.c
** File description:
** my_operators
*/

#ifndef MY_OPERATORS_H_
    #define MY_OPERATORS_H_

    typedef struct operator_s {
        char *symbols;
        int (*func)(int a, int b);
        int weight;
    } operator_t;
    int my_mul(int a, int b);
    int my_sub(int a, int b);
    int my_add(int a, int b);
    int my_div(int a, int b);
    int my_mod(int a, int b);
    operator_t *get_op(operator_t *array, char *str);
#endif /* !MY_OPERATORS_H_ */
