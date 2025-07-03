/*
** EPITECH PROJECT, 2024
** df_head_csv
** File description:
** csv ui
*/

#include "../include/my.h"

void *get(void *data, column_type_t type)
{
    float *fres = malloc(sizeof(float));
    int *ires = malloc(sizeof(int));

    if (type == INT || type == UINT) {
        *ires = atoi(data);
        return ires;
    }
    if (type == FLOAT){
        *fres = atof(data);
        return fres;
    }
    if (type == STRING){
        return (char *)data;
    }
}

void *df_get_value(dataframe_t *data, int row, const char *column)
{
    int cl = -1;
    int j = 1;

    if (data == NULL)
        return NULL;
    for (int i = 0; data->column_names[i] != NULL; i++)
        if (strcmp(data->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    return get(data->data[row + 1][cl], data->column_types[cl]);
}

void **df_get_values(dataframe_t *data, const char *column)
{
    int cl = -1;
    int j = 1;
    void **ret = malloc(sizeof(void *) * data->nb_rows);

    if (data == NULL)
        return NULL;
    for (int i = 0; data->column_names[i] != NULL; i++)
        if (strcmp(data->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    for (int i = 0; i != data->nb_rows - 1; i++)
        ret[i] = get(data->data[i + 1][cl], data->column_types[cl]);
    return ret;
}

int value_check(int i, dataframe_t *data, int cl)
{
    for (int j = 0; j != i; j++)
        if (strcmp(data->data[i + 1][cl], data->data[j + 1][cl]) == 0)
            return 1;
    return 0;
}

void **df_get_unique_values(dataframe_t *data, const char *column)
{
    int cl = -1;
    int j = 1;
    int k = 0;
    void **ret = malloc(sizeof(void *) * data->nb_rows);

    if (data == NULL)
        return NULL;
    for (int i = 0; data->column_names[i] != NULL; i++)
        if (strcmp(data->column_names[i], column) == 0)
            cl = i;
    if (cl == -1)
        return NULL;
    for (int i = 0; i != data->nb_rows - 1; i++){
        if (value_check(i, data, cl) == 0){
            ret[k] = get(data->data[i + 1][cl], data->column_types[cl]);
            k++;
        }
    }
    return ret;
}
