/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** game infos header
*/

#ifndef ENGINE_H_
    #define ENGINE_H_

    #include <SFML/Graphics/RenderWindow.h>

typedef struct engine_s engine_t;

engine_t *engine_create(void);
unsigned int engine_run(engine_t *engine);
void engine_destroy(engine_t *engine);
sfRenderWindow *engine_get_window(engine_t *engine);

#endif
