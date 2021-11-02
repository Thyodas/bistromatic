##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC    =    $(wildcard *.c)
OBJ    =    $(SRC:.c=.o)

NAME =     calc

INCDIR = include

CFLAGS = -I$(INCDIR)

all: $(NAME)

$(NAME):    $(OBJ)
		make -C lib/my
		gcc -g -o $(NAME) $(OBJ) $(CFLAGS) -L"lib/" -lmy

clean:
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:        clean
		make clean -C lib/my
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
