/*
** EPITECH PROJECT, 2024
** df_tail_csv
** File description:
** csv ui
*/

#include "../include/my.h"

// void *apply(void *data, column_type_t type,
//     void *(*apply_func) (void *value))
// {
//     float *fres = malloc(sizeof(float));
//     int *ires = malloc(sizeof(int));

//     if (type == INT || type == UINT) {
//         *ires = atoi(data);
//         return int_to_str(*(int *)apply_func(ires));
//     }
//     if (type == FLOAT){
//         *fres = atof(data);
//         return apply_func(fres);
//     }
//     if (type == STRING){
//         return (char *)apply_func(data);
//     }
// }

// void apply_set(dataframe_t *ret, dataframe_t *data)
// {
//     ret->column_names = data->column_names;
//     ret->column_types = data->column_types;
//     ret->nb_rows = data->nb_rows;
//     ret->nb_columns = data->nb_columns;
//     ret->separator = data->separator;
//     ret->data = malloc(sizeof(void **) * ret->nb_rows);
// }

// void df_apply2(dataframe_t *data, dataframe_t *ret,
//     void *(*apply_func) (void *value), int cl)
// {
//     int j = 1;

//     clone_data(ret, data);
//     for (int i = 1; i != ret->nb_rows; i++) {
//         ret->data[i][cl] = apply(ret->data[i][cl], cl, apply_func);
//     }
// }

// dataframe_t *df_apply(dataframe_t *data, const char *column,
//     void *(*apply_func) (void *value))
// {
//     dataframe_t *ret = malloc(sizeof(dataframe_t));
//     int cl = -1;
//     int j = 1;

//     if (data == NULL) {
//         free(ret);
//         return NULL;
//     }
//     apply_set(ret, data);
//     for (int i = 0; ret->column_names[i] != NULL; i++)
//         if (strcmp(ret->column_names[i], column) == 0)
//             cl = i;
//     if (cl == -1)
//         return NULL;
//     df_apply2(data, ret, apply_func, cl);
//     return ret;
// }

dataframe_t *df_apply(dataframe_t *data, const char *column,
    void *(*apply_func) (void *value))
{
    return NULL;
}
