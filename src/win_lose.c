/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** win_lose.c
*/

#include "struct.h"

int lose_condition(char **map)
{
    for (int i = 2; map[i] != NULL; i++) {
        for (int j = 2; map[i][j] != '\0'; j += 2) {
            if (map[i][j] >= '2' && map[i][j] <= '5')
                return (0);
        }
    }
    return (1);
}