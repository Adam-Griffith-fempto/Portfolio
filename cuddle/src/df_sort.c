/*
** EPITECH PROJECT, 2024
** df_tail_csv
** File description:
** csv ui
*/

#include "../include/my.h"

bool sort(void *data, void *data2, column_type_t type,
    bool(*sort_func)(void *value1, void *value2))
{
    float *fres = malloc(sizeof(float));
    int *ires = malloc(sizeof(int));
    float *fres2 = malloc(sizeof(float));
    int *ires2 = malloc(sizeof(int));

    if (type == INT || type == UINT) {
        *ires = atoi(data);
        *ires2 = atoi(data2);
        return sort_func(ires, ires2);
    }
    if (type == FLOAT){
        *fres = atof(data);
        *fres2 = atof(data2);
        return sort_func(fres, fres2);
    }
    if (type == STRING){
        return sort_func(data, data2);
    }
}

void sort_set(dataframe_t *ret, dataframe_t *data)
{
    ret->column_names = data->column_names;
    ret->column_types = data->column_types;
    ret->nb_rows = data->nb_rows;
    ret->nb_columns = data->nb_columns;
    ret->separator = data->separator;
    ret->data = malloc(sizeof(void **) * ret->nb_rows);
}

void swap(dataframe_t *ret, int i, int cl,
    bool(*sort_func)(void *value1, void *value2))
{
    void **temp;

    for (int j = 1; j != ret->nb_rows; j++)
        if (sort(ret->data[j][cl], ret->data[i][cl],
            ret->column_types[cl], sort_func)){
            temp = ret->data[j];
            ret->data[j] = ret->data[i];
            ret->data[i] = temp;
        }
}

void df_sort2(dataframe_t *data, dataframe_t *ret,
    bool(*sort_func)(void *value1, void *value2), int cl)
{
    int j = 1;

    clone_data(ret, data);
    for (int i = 1; i != ret->nb_rows; i++) {
        swap(ret, i, cl, sort_func);
    }
}

dataframe_t *df_sort(dataframe_t *data, const char *column,
    bool(*sort_func)(void *value1, void *value2))
{
    dataframe_t *ret = malloc(sizeof(dataframe_t));
    int cl = -1;
    int j = 1;

    if (data == NULL) {
        free(ret);
        return NULL;
    }
    sort_set(ret, data);
    for (int i = 0; ret->column_names[i] != NULL; i++)
        if (strcmp(ret->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    df_sort2(data, ret, sort_func, cl);
    return ret;
}
