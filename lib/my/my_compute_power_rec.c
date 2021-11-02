/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_REC
** File description:
** Function that calcultates a power the recursive way
*/

static long long int calculate_safe(int nb, int p)
{
    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    else
        return (nb * calculate_safe(nb, p - 1));
}

int my_compute_power_rec(int nb, int p)
{
    long long int result = calculate_safe(nb, p);

    if (result > 2147483647) {
        return 0;
    } else
        return (int)result;
}
