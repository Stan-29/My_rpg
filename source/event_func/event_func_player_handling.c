/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** event_func_player_handling
*/
#include "defines.h"
#include "types.h"

#include "scene_manager/scene_manager.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "scene/scene.h"

unsigned int event_func_run(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    if (!scene_manager || !scene || !engine)
        return ERROR;
    scene_set_player_run(scene, true);
    return OK;
}
