##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

all:
	gcc -o my_rpg *.c BOSS1/*.c BOSS2/*.c BOSS3/*.c -lcsfml-graphics \
	-lcsfml-audio -lcsfml-system -lcsfml-window -lm

fclean:
	rm -f my_rpg

re:    fclean all
