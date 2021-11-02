##
## EPITECH PROJECT, 2021
## Makefile DAY10
## File description:
## Makefile used to create lib
##

SRC	=	my_putchar.c		\
		my_putstr.c			\
		my_strcmp.c			\
		my_strlen.c			\
		my_swap_char.c		\
		my_swap.c			\
		my_strncpy.c		\
		my_getnbr.c			\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
