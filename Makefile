##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = source/const/images_tab.c 	\
	source/const/musics_tab.c 		\
	source/const/save_tab.c 		\
	source/const/scenes_tab.c 		\
	source/const/sounds_tab.c 		\
	source/const/texts_tab.c 		\
	source/engine/engine_basics.c		\
	source/engine/engine_events.c		\
	source/garbage_collector/garbage_collector_basics.c		\
	source/image/image_basics.c			\
	source/image/image_check.c			\
	source/image/image_get.c			\
	source/image/image_change.c			\
	source/images_func/image_func_pause.c	 		\
	source/images_func/image_func_settings.c 		\
	source/images_func/image_func_start_saves.c 	\
	source/images_func/image_func_switch_scenes.c 	\
	source/linked_list/linked_list_basics.c			\
	source/linked_list/linked_list_get.c			\
	source/linked_list/linked_list_handling.c		\
	source/music/music_basics.c		\
	source/scene/scene_basics.c			\
	source/scene/scene_drag.c			\
	source/scene/scene_get.c			\
	source/scene/scene_handle.c			\
	source/scene/scene_manage.c			\
	source/scene_manager/scene_manager_basics.c			\
	source/scene_manager/scene_manager_get.c			\
	source/scene_manager/scene_manager_manage.c			\
	source/sound/sound_basics.c			\
	source/text/text_basics.c		\
	source/text/text_check.c		\

OBJ = $(SRC:.c=.o)

MAIN = main.c

MAIN_OBJ = $(MAIN:.c=.o)


NAME =	my_rpg

CC := $(shell command -v epiclang || echo cc)

BREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo /opt/homebrew)

ifneq ($(wildcard .deps/lib),)
    DEPS_INCLUDES = -isystem .deps/include
    DEPS_LIBS = -L.deps/lib -Wl,-rpath,@loader_path/.deps/lib \
		-Wl,-rpath,@loader_path/.deps/Frameworks
else
    DEPS_INCLUDES = -I$(BREW_PREFIX)/include
    DEPS_LIBS = -L$(BREW_PREFIX)/lib
endif

CSFML_LIB = $(DEPS_LIBS) -l csfml-window -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-network

INCLUDES = -I./include -I./source $(DEPS_INCLUDES)

CFLAGS = $(INCLUDES) -Wall -Wextra


TEST_SRC = tests/unit_tests/tests_garbage_collector/*.c \
	tests/unit_tests/tests_image/*.c \
	tests/unit_tests/tests_images_func/*.c \
	tests/unit_tests/tests_linked_list/*.c \
	tests/unit_tests/tests_music/*.c \
	tests/unit_tests/tests_scene/*.c \
	tests/unit_tests/tests_sound/*.c \
	tests/unit_tests/tests_text/*.c \

TEST_NAME = tests_exec

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
	rm -f *.gcno
	rm -f *.gcda
	$(TEST_CC) -o $(TEST_NAME) --coverage -lcriterion \
	$(TEST_SRC) $(SRC) $(INCLUDES) $(CSFML_LIB)

gcovrex:	all
	$(MAKE) tests_run
	./$(TEST_NAME)
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

compile: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re compile tests_run gcovrex