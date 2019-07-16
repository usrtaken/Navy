/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** Copy d'une string dans une autre
*/

#include "struct.h"

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
