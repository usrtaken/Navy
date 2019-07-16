/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#include "struct.h"

void swap(char *str, int index1, int index2)
{
    int i = 0;

    i = str[index1];
    str[index1] = str[index2];
    str[index2] = i;
}

int verif(char **map, char **pos, int i, int size)
{
    for (int j = 2, line = 0; line <= size; line++, j += 2) {
        if (map[pos[i][3] - '1' + 2][j + (pos[i][2] - 'A') * 2] != '.')
            return (1);
    }
    return (0);
}

int verif1(char **map, char **pos, int i, int size)
{
    for (int j = 2, line = 0; line <= size; line++, j++) {
        if (map[j + pos[i][3] - '1'][(pos[i][2] - 'A') * 2 + 2] != '.')
            return (1);
    }
    return (0);
}

char **change_map(char **map, char **pos)
{
    for (int i = 0, size; pos[i] != NULL; i++) {
        if (pos[i][3] == pos[i][6]) {
            if (pos[i][5] < pos[i][2])
                swap(pos[i], 5, 2);
            size = pos[i][5] - pos[i][2];
            if (verif(map, pos, i, size))
                return (NULL);
            for (int j = 2, line = 0; line <= size; line++, j += 2)
                map[pos[i][3] - '1' + 2][j + (pos[i][2] - 'A') * 2] = pos[i][0];
        } else if (pos[i][2] == pos[i][5]) {
            if (pos[i][6] < pos[i][3])
                swap(pos[i], 6, 3);
            size = pos[i][6] - pos[i][3];
            if (verif1(map, pos, i, size))
                return (NULL);
            for (int j = 2, line = 0; line <= size; line++, j++)
                map[j + pos[i][3] - '1'][(pos[i][2] - 'A') * 2 + 2] = pos[i][0];
        }
    }
    return (map);
}