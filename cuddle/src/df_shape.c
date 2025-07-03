/*
** EPITECH PROJECT, 2024
** df_shape_csv
** File description:
** csv ui
*/

#include "../include/my.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape;

    if (dataframe == NULL) {
        shape.nb_rows = 0;
        shape.nb_columns = 0;
        return shape;
    }
    shape.nb_rows = dataframe->nb_rows - 1;
    shape.nb_columns = dataframe->nb_columns;
    return shape;
}
