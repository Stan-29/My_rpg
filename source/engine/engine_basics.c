/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "defines.h"

#include "engine/engine_internal.h"
#include "garbage_collector/garbage_collector.h"
#include "scene_manager/scene_manager.h"
#include "scene/scene.h"

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/VideoMode.h>

engine_t *engine_create(void)
{
    sfVideoMode mode = {WINDOWED_WIDTH, WINDOWED_HEIGHT, 32};
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));

    if (!engine)
        return NULL;
    engine->window = sfRenderWindow_create(mode, "My RPG", sfClose, NULL);
    engine->clock = sfClock_create();
    if (!engine->window || !engine->clock) {
        engine_destroy(engine);
        return NULL;
    }
    sfRenderWindow_setFramerateLimit(engine->window, FPS);
    return engine;
}

unsigned int engine_run(engine_t *engine)
{
    scene_manager_t *scene_manager = scene_manager_create();

    if (!scene_manager)
        return ERROR;
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        if (engine_events_handler(engine, scene_manager) == ERROR) {
            scene_manager_destroy(scene_manager);
            return ERROR;
        }
        scene_handle_drag(scene_manager_get_current(scene_manager),
            engine->window);
        scene_handle_hover(scene_manager_get_current(scene_manager),
            engine->window);
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

sfRenderWindow *engine_get_window(engine_t *engine)
{
    if (!engine)
        return NULL;
    return engine->window;
}

void engine_change_window(engine_t *engine, bool is_full_screen)
{
    sfVideoMode windowed = {WINDOWED_WIDTH, WINDOWED_HEIGHT, 32};

    sfRenderWindow_destroy(engine->window);
    if (is_full_screen)
        engine->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
            "My RPG", sfFullscreen, NULL);
    else
        engine->window = sfRenderWindow_create(windowed, "My RPG",
            sfClose, NULL);
    sfRenderWindow_setFramerateLimit(engine->window, FPS);
}
