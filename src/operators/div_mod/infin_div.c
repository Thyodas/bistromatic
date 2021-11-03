#include <stdlib.h>
#include <stdio.h>

char *my_arr_sum(char **array)
{
    int count = 0;
    int array_count = 0;
    char result = NULL;

    for (; array[array_count] != 0; array_count++)
        count += my_strlen(array[array_count]);
    result = malloc(sizeof(char) * (count + 2));
    for (int i = 0; i < array_count; i++)
        result = infin_add(result, array[i]);
    return (result);
}

char *infin_div(char *dividend, char *divisor, int modulo)
{
    char *temp_value = malloc(sizeof(char) * my_strlen(divisor));
    char ***table = malloc(sizeof(char**) * 100);
    int done = 0;
    int temp_key = 1;
    int index_table = 0;

    //FILLING LE TABLEAU TQT comme sur wiki
    while (done == 0) {
        temp_value = infin_mul(temp_key, divisor);
        if (my_greater_equals(temp_value, dividend)) {
            done = 1;
            break;
        }
        table[0][index_table] = temp_key;
        table[1][index_table] = temp_value;
        index_table++;
        temp_key *= 2;
    }

    // COMPARAISON DU TABLEAU
    char *decision = malloc(sizeof(char) * my_strlen(divisor));
    char **decision_table = malloc(sizeof(char*) * 100);
    int index_decision = 0;

    for (int i = index_table; i > 0; i--) {
        if (i == index_table && my_equal(table[1][i], dividend)) {
            decision = infin_add(decision, table[1][i]);
            decision_table[index_decision++] = table[1][i];
            break;
        } else if (my_lower_equals(ADD(my_arr_sum(decision_table), table[1][i])), dividend) {
            decision = infin_add(decision, table[1][i]);
            decision_table[index_decision++] = table[1][i];
        } else if (UPPER(ADD(my_arr_sum(decision_table), table[1][i])), dividend) {
            // do nothing
        }
    }

    return modulo ? (decision) : (my_arr_sum(decision_table));
}
