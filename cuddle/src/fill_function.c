/*
** EPITECH PROJECT, 2024
** fill_function.c
** File description:
** Important
*/

#include "../include/my.h"

void fill_frame(char *buff, char *separator, dataframe_t *data)
{
    char **tab = stok(buff, "\n");
    char **tab2 = stok(tab[0], separator);

    for (int i = 1; tab[i]; i++){
        tab2 = stok(tab[i], separator);
        tab2[0] = strtok(tab[i], separator);
        for (int j = 0; j != data->nb_columns; j++){
            data->data[i][j] = my_strdup(tab2[j]);
        }
    }
    free(tab);
    free(tab2);
}

void fill_void(dataframe_t *data, char *separator, char *buff)
{
    char **tab = stok(buff, "\n");

    data->column_types = malloc(sizeof(column_type_t) * data->nb_columns);
    data->data = malloc(sizeof(void **) * data->nb_rows - 1);
    for (int i = 0; i != data->nb_columns; i++)
        data->column_types[i] = check_type(i + 1, buff, separator, data);
    for (int i = 0; i != data->nb_rows; i++)
        data->data[i] = malloc
        (sizeof(char *) * data->nb_columns);
    fill_frame(buff, separator, data);
}
