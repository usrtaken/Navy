/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char *string, char *str)
{
    int i = 0;

    while (string[i] != '\0') {
        if (string[i] != str[i])
            return (0);
        i++;
    }
    return (1);
}