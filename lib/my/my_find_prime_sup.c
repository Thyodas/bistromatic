/*
** EPITECH PROJECT, 2021
** MY_FIND_PRIME_SUP
** File description:
** Find the first prime number superior
*/

static int my_compute_power_it_find(int nb, int p)
{
    long int result = 1;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    for (int i = 0; i < p; i++)
        result *= nb;
    if (result > 2147483647)
        return 0;

    return (int)result;
}

static int my_is_prime_find(int nb)
{

    if (nb <= 5)
        return nb > 1 && nb != 4;
    if (nb % 2 == 0 || nb % 3 == 0)
        return 0;

    for (int i = 6; my_compute_power_it_find(i - 6, 2) <= nb; i += 6) {
        if (nb % (i - 1) == 0 || nb % (i + 1) == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (1) {
        if (my_is_prime_find(nb) == 1) {
            return nb;
        }
        nb++;
    }
}
