#include <stdlib.h>
#include <stdio.h>
#include "my_operators.h"

char *my_arr_sum(char **array)
{
    int count = 0;
    char *result = NULL;
    int i;
    int index = 0;

    for (i = 0; array[i] != 0; i++)
        count += my_strlen(array[i]);
    result = malloc(sizeof(char) * (count + 2));
    result = "0";
    index = i;
    for (i = 0; i < index; i++)
        result = my_add(result, array[i]);
    result[count] = '\0';
    return (result);
}

char *my_str_sum(char *input)
{
    int count = 0;
    int array_count = 0;

    for (int i = 0; input[i] != '\0'; i++)
        count += input[i] - '0';
    return (my_getnbr(count));
}

char *infin_div(char *dividend, char *divisor, int modulo)
{
    char *temp_value = malloc(sizeof(char) * my_strlen(divisor));
    char ***table = malloc(sizeof(char**) * 100);
    int done = 0;
    char *temp_key = "1";
    int index_table = 0;

    //FILLING LE TABLEAU TQT comme sur wiki
    while (done == 0) {
        temp_value = my_mul(temp_key, divisor);
        if (my_greater_equals(temp_value, dividend)) {
            done = 1;
            break;
        }
        char **lines = malloc(sizeof(char*) * 3); // 2 place and one for '\0'
        lines[0] = temp_key;
        lines[1] = temp_value;
        table[index_table] = lines; // ERRROR
        index_table++;
        temp_key = my_mul(temp_key, "2");
    }

    // COMPARAISON DU TABLEAU
    char **values = malloc(sizeof(char*) * (index_table + 1));
    int value = 1;
    char *result = malloc(sizeof(char) * my_strlen(dividend));

    values[0] = table[index_table - 1][1];
    result = my_add(result, table[index_table - 1][0]);
    for (int i = index_table - 1; i >= 0; i--) {
        if (my_lower(my_add(my_arr_sum(values), table[i][1]), dividend)) {
            values[value] = table[i][1];
            value++;
            result = my_add(result, table[i][0]);
        }
    }
    return modulo ? (my_sub(dividend, my_arr_sum(values))) : (result);
}
