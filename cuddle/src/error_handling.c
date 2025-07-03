/*
** EPITECH PROJECT, 2024
** error_hendling.c
** File description:
** csv ui
*/

#include "../include/my.h"

int error_handling2(char **tab, char *separator, int sep_data, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == separator[0])
            sep_data++;
    }
    return sep_data;
}

int error_handling(char *buff, char *separator)
{
    char **tab;
    int sep_name = 0;
    int sep_data = 0;

    tab = stok(buff, "\n");
    for (int i = 0; tab[0][i] != '\0'; i++) {
        if (tab[0][i] == separator[0])
            sep_name++;
    }
    for (int i = 1; tab[i] != NULL; i++) {
        sep_data = error_handling2(tab, separator, sep_data, i);
        if (sep_data != sep_name)
            return 1;
        sep_data = 0;
    }
    return 0;
}
