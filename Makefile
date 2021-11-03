##
## EPITECH PROJECT, 2021
## Makefile do_op
## File description:
## Makefile used for do_op
##

SRC	=	main_inf_mul.c			\
		inf_mul.c				\
		add.c					\
		add_compute.c			\
		utils.c					\
		cleaning.c				\
		alloc.c

OBJ	=	$(SRC:.c=.o)

NAME = 	inf_mul

INCDIR = -I include/

LIBDIR = -L lib/my -lmy

all: $(NAME)

build_lib:
	make -C lib/my

$(NAME): build_lib $(OBJ)
		gcc $(SRC) -o inf_mul $(INCDIR) $(LIBDIR) -g

clean:
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:		clean
		make fclean -C lib/my
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
