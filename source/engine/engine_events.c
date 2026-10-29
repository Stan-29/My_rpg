/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "engine_internal.h"

void engine_events_handler(engine_t *engine)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(engine->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(engine->window);
    }
}
