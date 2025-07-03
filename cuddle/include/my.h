/*
** EPITECH PROJECT, 2025
** secured
** File description:
** my.h
*/

#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <fcntl.h>
#include <math.h>
#include "../include/dataframe.h"

#ifndef MY_H_
    #define MY_H_

typedef struct flags {
    int b;
    int i;
    int ui;
    int f;
    int s;
} flags_t;

//copy
float mean(float *tab, int count);
float stdev(float *tab, int n);
float min(float *tab, int n);
float max(float *tab, int n);
//error hendling
int error_handling(char *buff, char *separator);
//Set file
void rows_columns(char *buff, dataframe_t *data, char *separator);
void column_names(dataframe_t *data, char *separator, char *buff);
void fill_frame(char *buff, char *separator, dataframe_t *data);
void fill_void(dataframe_t *data, char *separator, char *buff);
float *int_tab(void ***data, int i, int rows);
char **sep_word_array(char *str, char sep);
int malloc_tok(char *str, char *sepa);
char **stok(char *buff, char *sep);
//my libc function
int my_strlen(char *str);
void my_putchar(char c);
void my_putstr(char *str);
char *my_strdup(char *str);
char *int_to_str(int nb);
// math_function
int is_number(char *str);
int is_snumber(char *str);
int is_float(char *str);
int is_bool(char *str);
// set_type
column_type_t check_type(int i, char *buff, char *separator,
    dataframe_t *data);
column_type_t set_type(column_type_t ptype, char *token);
column_type_t base_type(char *buff, char *separator, int i,
    column_type_t type);
void clone_data(dataframe_t *ret, dataframe_t *data);
// ne jamais utiliser entre un fopen et un fclose
int file_size(const char *filename);


#endif /* !MY_H_ */
