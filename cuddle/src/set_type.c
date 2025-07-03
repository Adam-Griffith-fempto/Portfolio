/*
** EPITECH PROJECT, 2024
** set_type.c
** File description:
** Important
*/

#include "../include/my.h"

column_type_t base_type(char *buff, char *separator, int i, column_type_t type)
{
    char **tab = stok(buff, "\n");
    char *token = strtok(tab[1], separator);

    for (int j = 0; j < i - 1; j++){
        token = strtok(NULL, separator);
    }
    if (is_number(token) == 1)
        type = UINT;
    if (is_snumber(token) == 1)
        type = INT;
    if (is_float(token) == 1)
        type = FLOAT;
    if (is_bool(token) == 1)
        type = BOOL;
    if (is_float(token) == 0 && is_snumber(token) == 0
    && is_number(token) == 0 && is_bool(token) == 0)
        type = STRING;
    free(tab);
    return type;
}

column_type_t set_type(column_type_t ptype, char *token)
{
    column_type_t type = ptype;

    if (is_number(token) == 1 && type == UINT)
        type = UINT;
    if (is_snumber(token) == 1 && (type == UINT || type == INT))
        type = INT;
    if (is_float(token) == 1 && type == FLOAT)
        type = FLOAT;
    if (is_float(token) == 1 && (type == INT || type == UINT))
        type = STRING;
    if ((is_number(token) == 1 || is_snumber(token)) && type == FLOAT)
        type = STRING;
    if (is_float(token) == 0 && is_snumber(token) == 0
    && is_number(token) == 0 && is_bool(token) == 0)
        type = STRING;
    return type;
}

column_type_t check_type(int i, char *buff, char *separator, dataframe_t *data)
{
    column_type_t type = UNDEFINED;
    char **tab = stok(buff, "\n");
    char *token;

    type = base_type(buff, separator, i, type);
    for (int k = 1; tab[k] != NULL; k++){
        tab = stok(buff, "\n");
        token = strtok(tab[k], separator);
        for (int j = 0; j < i - 1; j++){
            token = strtok(NULL, separator);
        }
        type = set_type(type, token);
    }
    free(tab);
    return type;
}

void clone_data(dataframe_t *ret, dataframe_t *data)
{
    for (int i = 1; i != data->nb_rows; i++){
        ret->data[i] = malloc(sizeof(void *) * data->nb_columns);
        for (int j = 0; j != data->nb_columns; j++)
            ret->data[i][j] = my_strdup(data->data[i][j]);
    }
}
