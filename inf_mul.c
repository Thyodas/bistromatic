/*
** EPITECH PROJECT, 2021
** INF_MUL
** File description:
** Infinite multiplication
*/

#include "include/my.h"

void fill_zeros(char *output, int pos, int *index)
{
    for (int i = 0; i < pos; ++i)
        output[(*index)++] = '0';
}

int compute_and_push(int tot, char *tmp, int *index, int carry)
{
    int to_push = tot % 10;
    tmp[(*index)++] = to_push + '0';
    printf("Valeur de to_push : %d\n", to_push);
    carry = tot / 10;
    return (carry);
}

char *fill_tmp(int i, char *number1, char *number2)
{
    int index = 0;
    int len2 = my_strlen(number2);
    int len_tot = my_strlen(number1) + len2;
    printf("Valeur de len tot : %d\n", len_tot);
    char *tmp = malloc(sizeof(char) * (len_tot + 2));
    int carry = 0;
    for (int j = 0; j < len2; ++j) {
        int tot = (number1[i] - '0') * (number2[j] - '0') + carry;
        carry = compute_and_push(tot, tmp, &index, carry);
    }
    if (carry != 0)
        tmp[index++] = carry + '0';
    my_revstr(tmp);
    tmp[my_strlen(tmp) - 1] = '\0';
    printf("Valeur de tmp avant le fill zero : %s\n", tmp);
    fill_zeros(tmp, i, &index);
    printf("Valeur de tmp a la %d eme iteration : %s\n\n", i, tmp);
    return tmp;
}

char *put_neg_sign(char *result, int sign)
{
    if (sign == 1)
        return result;
    char *new_result = malloc(sizeof(char) * my_strlen(result) + 2);
    new_result[0] = '-';
    for (int i = 1; i < my_strlen(result) + 1; ++i) {
        new_result[i] = result[i - 1];
    }
    return new_result;
}

void inf_mul(char *number1, char *number2, int sign)
{
    int len1 = my_strlen(number1);
    int len2 = my_strlen(number2);
    int len_tot = len1 + len2;
    my_revstr(number1);
    my_revstr(number2);
    char *result = malloc(sizeof(char) * (len_tot + 2));
    char *tmp_res = result;

    for (int i = 0; i < len1; ++i) {
        char *tmp = fill_tmp(i, number1, number2);
        result = add(tmp, tmp_res);
        tmp_res = result;
        free(tmp);
    }
    result = put_neg_sign(result, sign);
    my_putstr(result);
}
