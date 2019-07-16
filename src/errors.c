/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** Find and outputs based on errors
*/

#include "struct.h"

char **op(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buff;
    char **new;

    if (fd == -1)
        return (NULL);
    buff = malloc(sizeof(char) * 35);
    read(fd, buff, 35);
    new = str_to_wordtab(buff, '\n');
    new = file_check(new);
    return (new);
}

char **file_check(char **file)
{
    file = check_size(file);
    file = check_nb_boat(file);
    file = check_pos_boat(file);
    file = boat_size_check(file);
    file = pos_correct_game(file);
    file = check_coherent_size(file);
    return (file);
}

char **check_nb_boat(char **file)
{
    int i = 0;

    for (; file && file[i]; i++);
    if (i < 4)
        return (NULL);
    return (file);
}

char **check_size(char **file)
{
    int i = 0;

    for (; file && file[i]; i++) {
        if (my_strlen(file[i]) != 7)
            return (NULL);
        for (int j = i + 1; file[j]; j++) {
            if (file[i][0] == file[j][0])
                return (NULL);
        }
    }
    return (file);
}

char **check_pos_boat(char **file)
{
    for (int i = 0; file && file[i]; i++) {
        if (file[i][2] != file[i][5] && \
        file[i][3] != file[i][6])
            return (NULL);
    }
    return (file);
}