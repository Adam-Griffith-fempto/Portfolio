/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H
    #include <stdbool.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

// Number of rows in the dataframe
// Number of columns in the dataframe
// Array of column names
// Array of column types
// 2 D array of data values

typedef struct separator {
    char *separator;
} separator_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    separator_t *separator;
    void ***data;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

// functions
dataframe_t *df_read_csv(const char *filename, char *separator);
dataframe_t *df_write_csv(dataframe_t *data, char *filename);
dataframe_t *df_head(dataframe_t *data, int nb_rows);
dataframe_t *df_tail(dataframe_t *data, int nb_rows);
dataframe_shape_t df_shape(dataframe_t *dataframe);
dataframe_t *df_filter(dataframe_t *data,
    const char *column, bool(*filter_func)(void *value));
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);
dataframe_t *df_sort(dataframe_t *data, const char *column,
    bool(*sort_func)(void *value1, void *value2));
dataframe_t *df_to_type(dataframe_t *data, const char *column,
    column_type_t downcast);
void *df_get_value(dataframe_t *data, int row, const char *column);
void **df_get_values(dataframe_t *data, const char *column);
void **df_get_unique_values(dataframe_t *data, const char *column);
dataframe_t *df_apply(dataframe_t *data, const char *column,
    void *(*apply_func) (void *value));
#endif /* HASHTABLE_H */
