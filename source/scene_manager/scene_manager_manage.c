/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_manager_basics
*/
#include "consts.h"

#include "scene/scene.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep

void scene_manager_set_scene(scene_manager_t *scene_manager,
    unsigned int scene_id)
{
    if (!scene_manager || scene_id <= SCENE_NONE || scene_id >= SCENE_COUNT)
        return;
    if (!scenes_tab[scene_id].is_main) {
        scene_manager->sub_scene = scene_id;
        return;
    }
    scene_stop(scene_manager->scene[scene_manager->main_scene]);
    scene_manager->sub_scene = SCENE_NONE;
    scene_manager->main_scene = scene_id;
    scene_start(scene_manager->scene[scene_manager->main_scene]);
}

void scene_manager_exit_sub(scene_manager_t *scene_manager)
{
    if (!scene_manager)
        return;
    scene_manager->sub_scene = SCENE_NONE;
}

void scene_manager_change_music_volume(scene_manager_t *scene_manager,
    float ratio)
{
    if (!scene_manager)
        return;
    for (unsigned int scene_id = SCENE_MENU; scene_id < SCENE_COUNT;
        scene_id++)
        scene_change_music_volume(scene_manager->scene[scene_id], ratio);
}

void scene_manager_change_sound_volume(scene_manager_t *scene_manager,
    float ratio)
{
    if (!scene_manager)
        return;
    for (unsigned int scene_id = SCENE_MENU; scene_id < SCENE_COUNT;
        scene_id++)
        scene_change_sound_volume(scene_manager->scene[scene_id], ratio);
}
