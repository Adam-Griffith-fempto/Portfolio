/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Important
*/

#include "../include/my.h"

char *int_to_str(int nb)
{
    float temp = nb;
    int comp = 0;
    int pos = 0;
    char *res;

    for (comp; temp >= 10; comp++)
    temp = temp / 10;
    comp++;
    res = malloc(sizeof(char) * comp + 1);
    for (comp; comp != 0; comp--) {
        res[pos] = (int)temp % 10 + 48;
        temp = temp * 10;
        pos++;
    }
    res[pos] = '\0';
    return res;
}

int malloc_sep(char *str, int i, char sep)
{
    int sp = 0;
    int sp2 = 0;
    int ret = 0;

    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == sep)
            sp++;
    if (i == -1)
        return sp;
    for (int j = 0; str[j] != '\0'; j++){
        ret++;
        if (str[j + 1] == sep && sp2 == i + 1)
            return ret;
        if (str[j] == sep){
            sp2++;
            ret = 0;
        }
    }
    return ret;
}

int malloc_tok(char *str, char *sepa)
{
    int sp = 0;
    char sep = sepa[0];

    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == sep)
            sp++;
    return sp;
}

char **sep_word_array(char *str, char sep)
{
    int i = 0;
    int c = 0;
    int f = 0;
    char **data = malloc(sizeof(char *) * (malloc_sep(str, -1, sep) + 1));

    data[c] = malloc(sizeof(char) * (malloc_sep(str, c, sep)));
    for (i; str[i] != '\0'; i++) {
        if (str[i] != sep)
        data[c][f] = str[i];
        if (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0') {
            data[c][f] = '\0';
            c++;
            f = -1;
            data[c] = malloc(sizeof(char) * (malloc_sep(str, c, sep)));
        }
        f++;
    }
    data[c + 1] = NULL;
    return data;
}
