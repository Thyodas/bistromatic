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
	  src/eval_expr/utils.c \
	  src/operators/operators.c \
	  src/eval_expr/stack_funcs.c \
	  src/eval_expr/queue_funcs.c \
	  src/operators/mul/alloc.c \
	  src/operators/mul/inf_mul.c \
	  src/operators/add_sub/inf_add_sub.c \
	  src/operators/div_mod/infin_div.c \
	  src/operators/add_sub/utils.c \
	  src/utilities/condition.c \
	  src/utilities/cleaning.c \
	  src/utilities/format.c \
	  src/utilities/conv_base.c \
	  src/utilities/utils_for_base.c \
	  src/utilities/math.c

OBJ = $(SRC:.c=.o)

NAME = calc

INCLUDE = include

LIB = lib/my

TEST_FILES = tests/test_eval_expr.c \
			 tests/test_stack_queue.c \
			 tests/test_format.c \
			 tests/test_add_sub.c \
			 src/eval_expr/eval_expr.c \
			 src/eval_expr/shunting_yard.c \
			 src/eval_expr/rpn.c \
	  		 src/eval_expr/stack_funcs.c \
	  		 src/eval_expr/queue_funcs.c \
			 src/eval_expr/utils.c \
			 src/operators/operators.c \
			 src/operators/add_sub/inf_add_sub.c \
			 src/operators/add_sub/utils.c \
			 src/operators/div_mod/infin_div.c \
			 src/utilities/format.c \
			 src/utilities/cleaning.c \
			 src/utilities/condition.c


CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

all: $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

tests_run: fclean make_lib
		   gcc -I$(INCLUDE) -o unit_tests $(TEST_FILES) -L$(LIB) -lmy\
		   --coverage -lcriterion
		   ./unit_tests

.PHONY: fclean all debug re clean tests_run make_lib $(NAME)
