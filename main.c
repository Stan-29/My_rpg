/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** main_function
*/
#include "defines.h"
#include "engine/engine.h"
#include "garbage_collector/garbage_collector.h"
#include "scene/scene.h"

int main(void)
{
    engine_t *engine = engine_create();
    scene_t *scene = scene_create(1);

    if (!engine)
        return ERROR;
    engine_run(engine, scene);
    engine_destroy(engine);
    scene_destroy(scene);
    garbage_collector_clean();
    return OK;
}
