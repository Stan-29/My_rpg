/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine header
*/

#ifndef ENGINE_H_
    #define ENGINE_H_

    #include <SFML/Graphics/Types.h>

    #include <stdbool.h>

    #define FULL_SCREEN_WIDTH 1920
    #define FULL_SCREEN_HEIGHT 1080

typedef struct engine_s engine_t;

engine_t *engine_create(void);
unsigned int engine_run(engine_t *engine);
void engine_destroy(engine_t *engine);
void engine_resize_window(engine_t *engine, bool is_full_screen);

float engine_get_delta(engine_t *engine);
sfRenderWindow *engine_get_window(engine_t *engine);

#endif
