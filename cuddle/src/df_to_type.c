/*
** EPITECH PROJECT, 2024
** df_tail_csv
** File description:
** csv ui
*/

#include "../include/my.h"

void type_set(dataframe_t *ret, dataframe_t *data)
{
    ret->column_names = data->column_names;
    ret->column_types = data->column_types;
    ret->nb_rows = data->nb_rows;
    ret->nb_columns = data->nb_columns;
    ret->separator = data->separator;
    ret->data = malloc(sizeof(void **) * ret->nb_rows);
}

dataframe_t *df_to_type(dataframe_t *data, const char *column,
    column_type_t downcast)
{
    dataframe_t *ret = malloc(sizeof(dataframe_t));
    int cl = -1;
    int j = 1;

    if (data == NULL) {
        free(ret);
        return NULL;
    }
    type_set(ret, data);
    for (int i = 0; ret->column_names[i] != NULL; i++)
        if (strcmp(ret->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    clone_data(ret, data);
    ret->column_types[cl] = downcast;
    return ret;
}
