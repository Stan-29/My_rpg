##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = source/scene/scene_base.c		\
	source/engine/engine_base.c		\


NAME =	my_rpg

CC = epiclang

CSFML_LIB = -l csfml-window -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-network

INCLUDES = -I./include -I./source

CFLAGS = $(INCLUDES)

OBJ = 	$(SRC:.c=.o)


TEST_SRC = 	

TEST_NAME = tests

TEST_CC = gcc


all : $(OBJ)
	$(CC) -o $(NAME) main.c $(OBJ) $(CFLAGS) $(CSFML_LIB)

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

fclean:	clean
	rm -f $(NAME)

re:	
	$(MAKE) fclean
	$(MAKE) all

tests_run:
	$(TEST_CC) -o $(TEST_NAME) --coverage -lcriterion \
	$(TEST_SRC) $(SRC) $(INCLUDES) $(CSFML_INCLUDE)

gcovrex:	all
	$(MAKE) tests_run
	./$(TEST_NAME)
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

compile: re
	./$(NAME)

.PHONY: all clean fclean re compile tests_run gcoverx