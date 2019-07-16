/*
** EPITECH PROJECT, 2019
** errors1.c
** File description:
** Find and outputs based on errors
*/

#include "struct.h"

char **boat_size_check(char **file)
{
    for (int i = 0; file && file[i]; i++) {
        if (file[i][0] < '2' || file[i][0] > '5')
            return (NULL);
    }
    return (file);
}

char **pos_correct_game(char **file)
{
    for (int i = 0; file && file[i]; i++) {
        if (file[i][1] != ':' || !(file[i][2] >= 'A' && file[i][2] <= 'H') || \
        !(file[i][3] >= '1' && file[i][3] <= '8') || file[i][4] != ':' || \
        !(file[i][5] >= 'A' && file[i][5] <= 'H') || \
        !(file[i][6] >= '1' && file[i][6] <= '8'))
            return (NULL);
    }
    return (file);
}

char **check_coherent_size(char **file)
{
    for (int i = 0; file && file[i]; i++) {
        if (file[i][2] == file[i][5]) {
            if (!(file[i][3] - file[i][6] + 1 == file[i][0] - '0') && \
            !(file[i][6] -file[i][3] +1 == file[i][0] - '0'))
                return (NULL);
        } else {
            if (!(file[i][2] - file[i][5] + 1 == file[i][0] - '0') && \
            !(file[i][5] -file[i][2] +1 == file[i][0] - '0'))
                return (NULL);
        }
    }
    return (file);
}

int touch_boat(char **map)
{
    my_putchar('\n');
    my_putchar(id.abs + 'A' - 1);
    my_putchar(id.ord + '0');
    my_putstr(":  ");
    if (map[id.ord + 1][id.abs * 2] == '.') {
        my_putstr("missed\n");
        map[id.ord + 1][id.abs * 2] = 'o';
        return (1);
    }
    my_putstr("hit\n");
    map[id.ord + 1][id.abs * 2] = 'x';
    return (0);
}