/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "struct.h"

int dash_h(void)
{
    char *str = "USAGE\n  ./navy [first_player_pid] navy_positions"\
    "\nDESCRIPTION\n    first_player_pid:   only for the 2nd player." \
    " pid of the first player.\n    navy_positions:     file representing"\
    "the positions of the ships.\n";
    write(1, str, my_strlen(str));
    return (0);
}

void re_init(void)
{
    id.abs = 0;
    id.end = 0;
    id.ord = 0;
}

int main(int ac, char **av)
{
    char **file_pos;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (dash_h());
    if (ac < 2 || ac > 3)
        return (84);
    re_init();
    id.pid = 0;
    if (ac == 2)
        file_pos = op(av[1]);
    else
        file_pos = op(av[2]);
    if (file_pos == NULL)
        return (84);
    return (my_check(ac, file_pos, av));
}