/*
** EPITECH PROJECT, 2024
** df_head_csv
** File description:
** csv ui
*/

#include "../include/my.h"

bool type_def(void *data, column_type_t type, bool(*filter_func)(void *value))
{
    float *fres = malloc(sizeof(float));
    int *ires = malloc(sizeof(int));

    if (type == INT || type == UINT) {
        *ires = atoi(data);
        return filter_func(ires);
    }
    if (type == FLOAT){
        *fres = atof(data);
        return filter_func(fres);
    }
}

void filter_set(dataframe_t *ret, dataframe_t *data)
{
    ret->column_names = data->column_names;
    ret->column_types = data->column_types;
    ret->nb_columns = data->nb_columns;
    ret->separator = data->separator;
    ret->nb_rows = 1;
    ret->data = malloc(sizeof(void **) * ret->nb_rows);
}

void df_filter2(dataframe_t *data, dataframe_t *ret,
    bool(*filter_func)(void *value), int cl)
{
    int j = 1;

    for (int i = 1; i != data->nb_rows; i++) {
        if (type_def(data->data[i][cl], data->column_types[cl], filter_func)){
            ret->data[j] = malloc(sizeof(void *) * ret->nb_columns);
            ret->data[j] = data->data[i];
            j++;
            ret->nb_rows++;
        }
    }
}

dataframe_t *df_filter(dataframe_t *data, const char *column,
    bool(*filter_func)(void *value))
{
    dataframe_t *ret = malloc(sizeof(dataframe_t));
    int cl = -1;
    int j = 1;

    if (data == NULL) {
        free(ret);
        return NULL;
    }
    filter_set(ret, data);
    for (int i = 0; ret->column_names[i] != NULL; i++)
        if (strcmp(ret->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    df_filter2(data, ret, filter_func, cl);
    return ret;
}
