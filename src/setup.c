/*
** EPITECH PROJECT, 2019
** setup
** File description:
** setup
*/

#include "struct.h"

void handler(int sig, siginfo_t *info, void *i)
{
    id.pid = info->si_pid;
    (void) sig;
    (void) i;
}

int player1(char **my_map, char **enemy_map)
{
    int pid = getpid();
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;
    my_putstr("my_pid:   ");
    my_put_nbr(pid);
    sigaction(SIGUSR1, &act, NULL);
    my_putstr("\nwaiting for enemy connection...\n");
    pause();
    kill(id.pid, SIGUSR2);
    my_putstr("\nenemy connected\n");
    my_putstr("\nmy positions :\n");
    disp(my_map);
    my_putstr("\nenemy map :\n");
    disp(enemy_map);
    return (game_player1(my_map, enemy_map, id.pid));
}

int player2(char **av, char **my_map, char **enemy_map)
{
    int pid = getpid();
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    my_putstr("my_pid:   ");
    my_put_nbr(pid);
    my_putstr("\n");
    kill(my_getnbr(av[1]), SIGUSR1);
    sigaction(SIGUSR2, &act, NULL);
    my_putstr("successfully connected\n\n");
    my_putstr("my positions:\n");
    disp(my_map);
    my_putstr("\nenemy's positions:\n");
    disp(enemy_map);
    return (game_player2(my_map, enemy_map, my_getnbr(av[1])));
}

int my_check(int ac, char **file_pos, char **av)
{
    char **my_map = init_map();
    char **enemy_map = init_map();

    my_map = change_map(my_map, file_pos);
    if (my_map == NULL)
        return (84);
    if (ac == 2)
        return (player1(my_map, enemy_map));
    return (player2(av, my_map, enemy_map));
}