/*
** PERSONAL PROJECT, 2026
** My_rpg
** File description:
** main_function
*/
#include "defines.h"
#include "engine/engine.h"
#include "scene/scene.h"

int main(int argc, char **argv)
{
    engine_t *engine = engine_create();
    scene_t *scene = scene_create(1);

    if (!engine)
        return ERROR;
    engine_run(engine, scene);
    engine_destroy(engine);
    scene_destroy(scene);
    return OK;
}
