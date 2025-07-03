/*
** EPITECH PROJECT, 2024
** df_tail_csv
** File description:
** csv ui
*/

#include "../include/my.h"

void init_struct(dataframe_t *ret, dataframe_t *data, int nb_rows)
{
    ret->column_names = data->column_names;
    ret->column_types = data->column_types;
    ret->nb_columns = data->nb_columns;
    ret->nb_rows = nb_rows + 1;
}

dataframe_t *df_tail(dataframe_t *data, int nb_rows)
{
    dataframe_t *ret = malloc(sizeof(dataframe_t));
    int j = 1;

    if (nb_rows <= 0 || data == NULL) {
        free(ret);
        return NULL;
    }
    init_struct(ret, data, nb_rows);
    if (nb_rows > data->nb_rows){
        ret->nb_rows = data->nb_rows;
        nb_rows = data->nb_rows - 1;
    }
    ret->data = malloc(sizeof(void **) * ret->nb_rows + 1);
    ret->separator = data->separator;
    for (int i = data->nb_rows - nb_rows; i != data->nb_rows + 1; i++){
        ret->data[j] = malloc(sizeof(void *) * ret->nb_columns);
        ret->data[j] = data->data[i];
        j++;
    }
    return ret;
}
