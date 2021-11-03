##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = main.c \
	  src/eval_expr/eval_expr.c \
	  src/eval_expr/shunting_yard.c \
	  src/eval_expr/rpn.c \
	  operators.c \
	  src/eval_expr/stack_funcs.c \
	  src/eval_expr/queue_funcs.c \
	  utils.c

OBJ = $(SRC:.c=.o)

NAME = calc

INCLUDE = include

LIB = lib/my

TEST_FILES = tests/test_eval_expr.c \
			 tests/test_stack_queue.c \
			 src/eval_expr/eval_expr.c \
			 src/eval_expr/shunting_yard.c \
			 src/eval_expr/rpn.c \
	  		 src/stack/stack_funcs.c \
	  		 src/queue/queue_funcs.c \
			 operators.c \
			 utils.c

CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

all: $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy
		 rm -f $(OBJ)

clean:
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

tests_run: fclean make_lib
		   gcc -I$(INCLUDE) -o unit_tests $(TEST_FILES) -L$(LIB) -lmy\
		   --coverage -lcriterion
		   ./unit_tests

.PHONY: fclean all debug re clean tests_run make_lib $(NAME)
