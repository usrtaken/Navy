/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "struct.h"

int verif_position(char *buff)
{
    int valeur_read = read(0, buff, 3);

    if (buff[0] < 'A' || buff[0] > 'H' || buff[1] < '1' || \
    buff[1] > '8' || buff[2] != '\n') {
        my_putstr("wrong position");
        while ((buff[2] != '\n' || buff[2] != '\n') && valeur_read == 3)
            valeur_read = read(0, buff, 3);
        return (1);
    }
    return (0);
}

void extra(char *buff, char **enemy_map)
{
    if (id.end == 1) {
        enemy_map[buff[1] - '0' + 1][(buff[0] - 'A' + 1) * 2] = 'o';
        my_putstr(":  missed\n");
    } else {
        enemy_map[buff[1] - '0' + 1][(buff[0] - 'A' + 1) * 2] = 'x';
        my_putstr(":  hit\n");
    }
}

void send_signals(char *buff, int enemy_pid)
{
    for (int i = 0; i < buff[0] - 'A' + 1; i++) {
        kill(enemy_pid, SIGUSR1);
        usleep(1000);
    }
    kill(id.pid, SIGUSR2);
    usleep(1000);
    for (int j = 0; j < buff[1] - '0'; j++) {
        kill(enemy_pid, SIGUSR1);
        usleep(1000);
    }
    kill(enemy_pid, SIGUSR2);
    usleep(10000);
}

int game_player1(char ** my_map, char **enemy_map, int enemy_pid)
{
    char *buff = malloc(sizeof(char *) * 3);

    my_putstr("\nattack:  ");
    signal(SIGUSR2, handler_usr2);
    if (verif_position(buff) == 1)
        game_player1(my_map, enemy_map, enemy_pid);
    send_signals(buff, enemy_pid);
    my_putchar(buff[0]);
    my_putchar(buff[1]);
    extra(buff, enemy_map);
    if (id.abs != 0 || id.ord != 0) {
        my_putstr("\nmy positions:\n");
        disp(my_map);
        my_putstr("\nenemy's positions:\n");
        disp(enemy_map);
        my_putstr("\nI won\n");
        return (0);
    }
    re_init();
    return (game_player2(my_map, enemy_map, enemy_pid));
}

int game_player2(char **map, char **enemy_map, int enemy_pid)
{
    signal(SIGUSR1, handler_usr1);
    signal(SIGUSR2, handler_usr2);
    my_putstr("\nwaiting for enemy's attack...\n");
    while (id.end == 0);
    while (id.end == 1);
    if (touch_boat(map) == 1)
        kill(enemy_pid, SIGUSR2);
    re_init();
    my_putstr("my positions:\n");
    disp(map);
    my_putstr("\nenemy's positions:\n");
    disp(enemy_map);
    if (lose_condition(map) == 1) {
        my_putstr("\nEnemy won\n");
        kill(enemy_pid, SIGUSR1);
        return (1);
    }
    return (game_player1(map, enemy_map, enemy_pid));
}