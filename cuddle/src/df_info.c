/*
** EPITECH PROJECT, 2024
** df_info_csv
** File description:
** csv ui
*/

#include "../include/my.h"

char *print_type(column_type_t type)
{
    if (type == BOOL)
        return "bool";
    if (type == INT)
        return "int";
    if (type == UINT)
        return "unsigned int";
    if (type == FLOAT)
        return "float";
    if (type == STRING)
        return "string";
    if (type == UNDEFINED)
        return "undefined";
    return NULL;
}

void df_info(dataframe_t *dataframe)
{
    dataframe_t *data = malloc(sizeof(dataframe_t));

    if (dataframe == NULL){
        free(data);
        return;
    }
    data->column_names = dataframe->column_names;
    data->column_types = dataframe->column_types;
    data->nb_columns = dataframe->nb_columns;
    data->nb_rows = dataframe->nb_rows;
    data->separator = dataframe->separator;
    printf("%d columns:\n", data->nb_columns);
    for (int i = 0; i != data->nb_columns; i++) {
        printf("- %s: ", data->column_names[i]);
        printf("%s\n", print_type(data->column_types[i]));
    }
}
