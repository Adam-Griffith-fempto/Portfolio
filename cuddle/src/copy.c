/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Important
*/

#include "../include/my.h"

float *int_tab(void ***data, int i, int rows)
{
    float *tab = malloc(sizeof(float) * rows - 1);

    for (int j = 1; j != rows; j++){
        tab[j - 1] = atof(data[j][i]);
    }
    return tab;
}

float mean(float *tab, int count)
{
    int sum = 0;

    for (int i = 0; i != count - 1; i++){
        sum += tab[i];
    }
    return (float)sum / (count - 1);
}

float stdev(float *tab, int n)
{
    float m = mean(tab, n);
    float v = 0.0;

    for (int i = 0; i < n - 1; i++) {
        v += pow(tab[i] - m, 2);
    }
    return sqrt(v / (n - 1));
}

float min(float *tab, int n)
{
    float min = tab[0];

    for (int i = 0; i != n - 1; i++){
        if (tab[i] < min)
            min = tab[i];
    }
    return min;
}

float max(float *tab, int n)
{
    float max = tab[0];

    for (int i = 0; i != n - 1; i++){
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}
