/*
** EPITECH PROJECT, 2024
** df_read_csv
** File description:
** csv ui
*/

#include "../include/my.h"

bool filter_func ( void * value ) {
    return *( int *) value > 30;
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("data.csv", NULL);
    dataframe_t *bhead = df_head(dataframe, 3);
    dataframe_t *btail = df_tail(dataframe, 3);
    dataframe_t *head = df_head(dataframe, 15);
    dataframe_t *tail = df_tail(dataframe, 15);
    dataframe_t *filter = df_filter(dataframe, "age", filter_func);
    dataframe_shape_t shape = df_shape(dataframe);

    df_write_csv(dataframe, "result.csv");
    df_write_csv(bhead, "basic head.csv");
    df_write_csv(btail, "basic tail.csv");
    df_write_csv(head, "null head.csv");
    df_write_csv(tail, "all tail.csv");
    df_write_csv(filter, "filtered.csv");
    printf("Shape: %d rows, %d columns\n", shape.nb_rows, shape.nb_columns);
    df_info(dataframe);
    df_describe(dataframe);

    return 0;
}
