/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "signal.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct global_s {
    int pid;
    int abs;
    int ord;
    int end;
} global_t;

global_t id;

int dash_h(void);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
int my_getnbr(char *str);
void my_putchar(char c);
char *my_strcat(char *dest, char *src);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void swap(char *str, int index1, int index2);
//void handler(int sig, siginfo_t *info, void *i);
int player1(char **my_map, char **enemy_map);
int player2(char **av, char **my_map, char **enemy_map);
int my_check(int ac, char **file_pos, char **av);
void disp(char **map);
char **init_map(void);
char **init_dots(char **map, int index);
int word_counter(char *str, char delimiteur);
int letter(char *str, char delimiteur, int index);
char *useful(char *str, char delimiteur, int *index);
char **str_to_wordtab(char *str, char delimiteur);
char **op(char *path);
char **change_map(char **av, char **map);
int game_player1(char **my_map, char **enemy_map, int enemy_pid);
int game_player2(char **map, char **enemy_map, int enemy_pid);
char **check_coherent_size(char **file);
char **pos_correct_game(char **file);
char **boat_size_check(char **file);
char **check_pos_boat(char **file);
char **check_size(char **file);
char **check_nb_boat(char **file);
char **file_check(char **file);
void re_init(void);
int touch_boat(char **map);
char *my_strcpy(char *src);
void handler_usr2(int index);
void handler_usr1(int index);
int lose_condition(char **map);