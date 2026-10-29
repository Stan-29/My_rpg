/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine internal header
*/

#ifndef ENGINE_INTERNAL_H_
    #define ENGINE_INTERNAL_H_

    #include "engine/engine.h"
    #include "garbage_collector/garbage_collector.h"
    #include "defines.h"
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>

struct engine_s {
    sfRenderWindow *window;
    sfClock *clock;
};

void engine_events_handler(engine_t *engine);

#endif
