/*
** EPITECH PROJECT, 2024
** df_read_csv
** File description:
** csv ui
*/

#include "../include/my.h"

char **stok(char *buff, char *sep)
{
    char *buff2 = my_strdup(buff);
    char **tab = malloc(sizeof(char *) * (malloc_tok(buff2, sep) + 2));
    char *token = strtok(buff2, sep);
    int c = 0;

    while (token != NULL){
        tab[c] = strdup(token);
        token = strtok(NULL, sep);
        c++;
    }
    tab[c] = NULL;
    free(buff2);
    return tab;
}

static void init_struct(const char *filename,
    char *separator, dataframe_t *data)
{
    data->nb_columns = 0;
    data->nb_rows = 0;
    data->separator = malloc(sizeof(separator_t));
    data->separator->separator = my_strdup(separator);
}

void init_function(char *buff, dataframe_t *data, char *separator)
{
    rows_columns(buff, data, separator);
    column_names(data, separator, buff);
    fill_void(data, separator, buff);
}

dataframe_t *df_read_csv(const char *filename, char *separator)
{
    int size = file_size(filename);
    dataframe_t *data = malloc(sizeof(dataframe_t));
    FILE *file;
    char *buff;
    char **tab;
    char *token;

    if (size == -1)
        return NULL;
    if (separator == NULL)
        separator = ",";
    init_struct(filename, separator, data);
    file = fopen(filename, "rb");
    buff = malloc(sizeof(char) * size);
    fread(buff, sizeof(char), size, file);
    if (error_handling(buff, separator) == 1)
        return NULL;
    init_function(buff, data, separator);
    fclose(file);
    return data;
}

// Read the file line by line
// Return a new dataframe_t instance
