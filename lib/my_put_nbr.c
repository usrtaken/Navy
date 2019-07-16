/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = -147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
        return (0);
    }
    if (nb < 10) {
        my_putchar('0'+ nb);
        return (0);
    }
    my_put_nbr(nb / 10);
    my_putchar('0' + nb % 10);
    return (0);
}
