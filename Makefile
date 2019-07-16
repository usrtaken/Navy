##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	main.c \
		setup.c \
		my_strlen.c \
		my_putstr.c \
		my_put_nbr.c \
		my_putchar.c \
		my_strcmp.c \
		my_getnbr.c \
		map.c \
		my_strcat.c \
		str_to_tab.c \
		errors.c \
		display.c \
		game.c \
		my_strcpy.c\
		errors1.c \
		win_lose.c\

OBJ =	$(SRC:.c=.o)

NAME =	navy

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -W -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
