/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_manager_basics
*/
#include "enums.h"
#include "garbage_collector/garbage_collector.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep


scene_t *scene_manager_get_current(scene_manager_t *scene_manager)
{
    unsigned int current_scene = 0;

    if (!scene_manager)
        return NULL;
    current_scene = scene_manager->main_scene;
    if (scene_manager->sub_scene != SCENE_NONE)
        current_scene = scene_manager->sub_scene;
    return scene_manager->scene[current_scene];
}

unsigned int scene_manager_get_sub_id(scene_manager_t *scene_manager)
{
    if (!scene_manager)
        return SCENE_NONE;
    return scene_manager->sub_scene;
}
