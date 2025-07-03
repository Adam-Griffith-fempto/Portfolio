/*
** EPITECH PROJECT, 2024
** df_head_csv
** File description:
** csv ui
*/

#include "../include/my.h"

void df_describe(dataframe_t *data)
{
    int i = 0;
    float *tab;

    if (data == NULL)
        return;
    for (i = 0; i != data->nb_columns; i++){
        if (data->column_types[i] == INT || data->column_types[i] == UINT ||
        data->column_types[i] == FLOAT){
            printf("Column: %s\n", data->column_names[i]);
            printf("Count: %d\n", data->nb_rows - 1);
            tab = int_tab(data->data, i, data->nb_rows);
            printf("Mean: %.2f\n", mean(tab, data->nb_rows));
            printf("Std: %.2f\n", stdev(tab, data->nb_rows));
            printf("Min: %.2f\n", min(tab, data->nb_rows));
            printf("Max: %.2f\n", max(tab, data->nb_rows));
        }
    }
}
