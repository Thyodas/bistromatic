/*
** EPITECH PROJECT, 2021
** ALLOC
** File description:
** Utilitary function for malloc
*/

void initialize(char *input, int size)
{
    for (int i = 0; i < size; ++i) {
        input[i] = 0;
    }
}
