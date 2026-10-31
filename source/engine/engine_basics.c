/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "defines.h"
#include "garbage_collector/garbage_collector.h"
#include "engine/engine_internal.h"
#include "scene/scene.h"
#include "scene_manager/scene_manager.h"

engine_t *engine_create(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
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

unsigned int engine_run(engine_t *engine)
{
    scene_manager_t *scene_manager = scene_manager_create();

    if (!scene_manager)
        return ERROR;
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        engine_events_handler(engine);
        scene_manager_draw(scene_manager, engine->window);
        sfRenderWindow_display(engine->window);
    }
    scene_manager_destroy(scene_manager);
    return OK;
}

void engine_destroy(engine_t *engine)
{
    if (!engine)
        return;
    if (engine->window)
        sfRenderWindow_destroy(engine->window);
    if (engine->clock)
        sfClock_destroy(engine->clock);
    garbage_collector_free(engine);
}
