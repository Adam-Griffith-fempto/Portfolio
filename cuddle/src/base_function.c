/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Important
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 3);
    int i = 0;

    if (!result)
        return NULL;
    if (!str) {
        free(result);
        return NULL;
    }
    for (i; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}

int file_size(char const *filename)
{
    FILE *file;
    int size;

    if (open(filename, O_RDONLY) == -1)
        return -1;
    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size = ftell(file) + 1;
    fclose(file);
    return size;
}
