/*
** EPITECH PROJECT, 2024
** df_head_csv
** File description:
** csv ui
*/

#include "../include/my.h"

dataframe_t *df_head(dataframe_t *data, int nb_rows)
{
    dataframe_t *ret = malloc(sizeof(dataframe_t));

    if (nb_rows <= 0 || data == NULL) {
        free(ret);
        return NULL;
    }
    if (nb_rows > data->nb_rows){
        nb_rows = data->nb_rows - 1;
    }
    ret->column_names = data->column_names;
    ret->column_types = data->column_types;
    ret->nb_columns = data->nb_columns;
    ret->separator = data->separator;
    ret->nb_rows = nb_rows + 1;
    ret->data = malloc(sizeof(void **) * ret->nb_rows + 1);
    for (int i = 1; i != nb_rows + 1; i++){
        ret->data[i] = malloc(sizeof(void *) * ret->nb_columns);
        ret->data[i] = data->data[i];
    }
    return ret;
}
