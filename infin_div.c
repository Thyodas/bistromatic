/*#include <stdlib.h>
#include <stdio.h>

char *ARRAY_SUM(char **array)
{
    // TODO Sum of an strings array
}

char *infin_div(char *dividend, char *divisor)
{
    char *temp_value = malloc(sizeof(char) * my_strlen(divisor));
    char ***table = malloc(sizeof(char**) * 100);
    int done = 0;
    int temp_key = 1;
    int index_table = 0;

    //FILLING LE TABLEAU TQT comme sur wiki
    while (done == 0) {
        temp_value = temp_key * parseStr(divisor); // TODO change to infin_mul
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
    int decision = 0;
    char **decision_table = malloc(sizeof(char*) * 100);
    int index_decision = 0;

    for (int i = index_table; i > 0; i--) {
        if (i == index_table && my_equal(table[1][i], dividend)) {
            decision += table[1][i]; // TODO replace with infin_add
            decision_table[index_decision++] = table[1][i];
            break;
        } else if (my_lower_equals(ADD(ARRAY_SUM(decision_table), table[1][i])), dividend) {
            decision += table[1][i]; // TODO replace with infin_add
            decision_table[index_decision++] = table[1][i];
        } else if (UPPER(ADD(ARRAY_SUM(decision_table), table[1][i])), dividend) {
            // do nothing
        }
    }

    return (ARRAY_SUM(decision_table)); // <- infin_div
    // return (decision); <- infin_mod
}
*/