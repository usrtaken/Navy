/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** day07
*/

#include "struct.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *retour = NULL;

    retour = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src)) + 1);
    while (dest[i] != '\0') {
        retour[i] = dest[i];
        i++;
    }
    while (src[j]) {
        retour[j + i] = src[j];
        j++;
    }
    retour[j + i] = '\0';
    return (retour);
}
