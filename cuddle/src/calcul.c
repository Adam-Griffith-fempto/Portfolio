/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Important
*/

#include "../include/my.h"


int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_snumber(char *str)
{
    if (str[0] != '-')
        return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!is_digit(str[i]))
            return 0;
    }
    return 1;
}

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_digit(str[i]))
            return 0;
    }
    return 1;
}

int is_float(char *str)
{
    int p = 0;

    if (!(is_digit(str[0])) && str[0] != '-')
        return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(is_digit(str[i])) && str[i] != '.' && p != 0)
            return 0;
        if (str[i] == '.')
            p++;
    }
    if (p != 1)
        return 0;
    return 1;
}

int is_bool(char *str)
{
    char *str2 = malloc(sizeof(char) * strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++){
        str2[i] = tolower(str[i]);
    }
    str2[strlen(str)] = '\0';
    if (strcmp(str2, "true") == 0)
        return 1;
    if (strcmp(str2, "false") == 0)
        return 1;
    return 0;
}
