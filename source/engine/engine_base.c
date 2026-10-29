/*
** PERSONAL PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "engine.h"
#include "scene/scene.h"
#include <stdlib.h>
      
struct engine_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent *events;
};

engine_t *engine_create(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    engine_t *engine = malloc(sizeof(engine_t));

    if (!engine)
        return NULL;
    engine->window = sfRenderWindow_create(mode, "My RPG",
        sfResize | sfClose, NULL);
    engine->clock = sfClock_create();
    if (!engine->window || !engine->clock) {
        free(engine);
        return NULL;
    }
    return engine;
}

void engine_run(engine_t *engine, scene_t *scene)
{
    while (sfRenderWindow_isOpen(engine->window)) {
        scene_draw(scene);
    }
}

void engine_destroy(engine_t *engine)
{
    sfRenderWindow_destroy(engine->window);
    sfClock_destroy(engine->clock);
    free(engine);
}
