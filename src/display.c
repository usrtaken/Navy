/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display
*/

#include "struct.h"

void handler_usr1(int index)
{
    (void) index;
    if (id.end == 0)
        id.abs++;
    if (id.end == 1)
        id.ord++;
}

void handler_usr2(int index)
{
    (void) index;
    id.end++;
}

void disp(char **map)
{
    for (int i = 0; map[i]; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    int i = 0;

    while (i < 10)
        map[i++] = malloc(sizeof(char) * 19);
    for (int line = 0; line <= 9; line++) {
        if (line == 0)
            map[line] = " |A B C D E F G H\0";
        if (line == 1)
            map[line] = "-+---------------\0";
        if (line > 1)
            map = init_dots(map, line);
    }
    map[10] = NULL;
    return (map);
}

char **init_dots(char **map, int index)
{
    map[index][0] = index + '0' - 1;
    map[index][1] = 0;
    map[index] = my_strcat(map[index], "|. . . . . . . .\0");
    return (map);
}