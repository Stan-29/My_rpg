/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine internal header
*/

#ifndef ENGINE_INTERNAL_H_
    #define ENGINE_INTERNAL_H_

    #include "engine/engine.h"
    #include "scene_manager/scene_manager.h"
    #include "scene/scene.h"
    #include <SFML/System/Clock.h>

struct engine_s {
    sfRenderWindow *window;
    sfClock *clock;
};

unsigned int engine_events_handler(engine_t *engine,
    scene_manager_t *scene_manager);

#endif
