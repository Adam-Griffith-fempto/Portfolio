/*
** EPITECH PROJECT, 2024
** df_head_csv
** File description:
** csv ui
*/

#include "../include/my.h"

void print_data(FILE *file, dataframe_t *data, int i, int j)
{
    if (j == data->nb_columns - 1)
        fwrite((char *)data->data[i][j], sizeof(char),
        strlen((char *)data->data[i][j]), file);
    else {
        fwrite((char *)data->data[i][j], sizeof(char),
        strlen((char *)data->data[i][j]), file);
        fwrite(data->separator->separator, sizeof(char), 1, file);
    }
}

void write_end(FILE * file, dataframe_t *data)
{
    fwrite("\n", sizeof(char), 1, file);
    for (int i = 1; i != data->nb_rows; i++){
        for (int j = 0; j != data->nb_columns; j++){
            print_data(file, data, i, j);
        }
        if (i != data->nb_rows - 1)
        fwrite("\n", sizeof(char), 1, file);
    }
}

dataframe_t *df_write_csv(dataframe_t *data, char *filename)
{
    FILE *file = fopen(filename, "w+");

    if (data == NULL)
        return NULL;
    for (int i = 0; data->column_names[i]; i++){
        if (!(data->column_names[i + 1]))
            fwrite(data->column_names[i], sizeof(char),
            strlen(data->column_names[i]), file);
        if ((data->column_names[i + 1])){
            fwrite(data->column_names[i], sizeof(char),
            strlen(data->column_names[i]), file);
            fwrite(data->separator->separator, sizeof(char), 1, file);
        }
    }
    write_end(file, data);
    fwrite("\n", sizeof(char), 1, file);
    return data;
}
