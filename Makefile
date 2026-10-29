##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = source/scene/scene_basics.c			\
	source/engine/engine_basics.c		\
	source/engine/engine_events.c		\
	source/garbage_collector/garbage_collector_basics.c		\
	source/linked_list/linked_list_basics.c			\
	source/linked_list/linked_list_handling.c		\

MAIN = main.c

MAIN_OBJ = $(MAIN:.c=.o)


NAME =	my_rpg

CC = epiclang

CSFML_LIB = -l csfml-window -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-network

INCLUDES = -I./include -I./source

CFLAGS = $(INCLUDES) -Wall -Wextra

OBJ = 	$(SRC:.c=.o)


TEST_SRC = 	

TEST_NAME = tests

TEST_CC = gcc


all: $(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	$(CC) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CSFML_LIB)

clean:
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(TEST_NAME)

fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

tests_run:
	$(TEST_CC) -o $(TEST_NAME) --coverage -lcriterion \
	$(TEST_SRC) $(SRC) $(INCLUDES) $(CSFML_LIB)

gcovrex:	all
	$(MAKE) tests_run
	./$(TEST_NAME)
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

compile: re
	./$(NAME)

.PHONY: all clean fclean re compile tests_run gcovrex