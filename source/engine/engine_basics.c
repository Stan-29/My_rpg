/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "engine/engine_internal.h"

engine_t *engine_create(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));

    if (!engine)
        return NULL;
    engine->window = sfRenderWindow_create(mode, "My RPG",
        sfResize | sfClose, NULL);
    engine->clock = sfClock_create();
    if (!engine->window || !engine->clock) {
        engine_destroy(engine);
        return NULL;
    }
    return engine;
}

void engine_run(engine_t *engine, scene_t *scene)
{
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        engine_events_handler(engine);
        scene_draw(scene);
        sfRenderWindow_display(engine->window);
    }
}

void engine_destroy(engine_t *engine)
{
    if (!engine)
        return;
    if (engine->window)
        sfRenderWindow_destroy(engine->window);
    if (engine->clock)
        sfClock_destroy(engine->clock);
}
