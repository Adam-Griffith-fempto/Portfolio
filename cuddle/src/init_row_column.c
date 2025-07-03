/*
** EPITECH PROJECT, 2024
** init_row_column.c.c
** File description:
** csv ui
*/

#include "../include/my.h"

void rows_columns(char *buff, dataframe_t *data, char *separator)
{
    char **tab = stok(buff, "\n");
    char *token;

    data->nb_columns = 0;
    data->nb_rows = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        token = strtok(tab[i], separator);
        while (token != NULL){
            token = strtok(NULL, separator);
        }
    }
    for (int i = 0; buff[i] != '\n'; i++)
        if (buff[i] == separator[0])
            data->nb_columns++;
    data->nb_columns++;
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            data->nb_rows++;
    data->nb_rows++;
}

void column_names(dataframe_t *data, char *separator, char *buff)
{
    char **tab = stok(buff, "\n");
    char *token = strtok(tab[0], separator);

    data->column_names = malloc(sizeof(char *) * data->nb_columns + 1);
    for (int i = 0; token != NULL; i++){
        data->column_names[i] = my_strdup(token);
        token = strtok(NULL, separator);
    }
    data->column_names[data->nb_columns] = NULL;
    free(tab);
}
