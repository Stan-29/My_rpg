/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"

#include "scene_manager/scene_manager.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "scene/scene.h"

unsigned int event_func_move_up(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    sfVector2f dir = {0, 0};

    if (!scene_manager || !scene || !engine)
        return ERROR;
    dir.y -= 1;
    scene_update_map_dir(scene, &dir);
    return OK;
}

unsigned int event_func_move_down(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    sfVector2f dir = {0, 0};

    if (!scene_manager || !scene || !engine)
        return ERROR;
    dir.y += 1;
    scene_update_map_dir(scene, &dir);
    return OK;
}

unsigned int event_func_move_left(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    sfVector2f dir = {0, 0};

    if (!scene_manager || !scene || !engine)
        return ERROR;
    dir.x -= 1;
    scene_update_map_dir(scene, &dir);
    return OK;
}

unsigned int event_func_move_right(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    sfVector2f dir = {0, 0};

    if (!scene_manager || !scene || !engine)
        return ERROR;
    dir.x += 1;
    scene_update_map_dir(scene, &dir);
    return OK;
}
