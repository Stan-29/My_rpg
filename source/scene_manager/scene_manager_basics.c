/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_manager_basics
*/
#include "consts.h"

#include "garbage_collector/garbage_collector.h"
#include "scene/scene.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep

scene_manager_t *scene_manager_create(void)
{
    scene_manager_t *scene_manager =
        garbage_collector_malloc(sizeof(scene_manager_t));

    if (!scene_manager)
        return NULL;
    scene_manager->main_scene = SCENE_MENU;
    scene_manager->sub_scene = SCENE_NONE;
    for (unsigned int scene_id = SCENE_MENU; scene_id < SCENE_COUNT;
        scene_id++) {
        scene_manager->scene[scene_id] = scene_create(scene_id);
        if (!scene_manager->scene[scene_id])
            return scene_manager_destroy(scene_manager);
    }
    scene_start(scene_manager->scene[SCENE_MENU]);
    return scene_manager;
}

void *scene_manager_destroy(scene_manager_t *scene_manager)
{
    if (!scene_manager)
        return NULL;
    for (unsigned int scene_id = SCENE_NONE + 1; scene_id < SCENE_COUNT;
        scene_id++)
        scene_destroy(scene_manager->scene[scene_id]);
    garbage_collector_free(scene_manager);
    return NULL;
}

void scene_manager_draw(scene_manager_t *scene_manager,
    sfRenderWindow *window)
{
    if (!scene_manager)
        return;
    scene_draw(scene_manager->scene[scene_manager->main_scene], window);
    if (scene_manager->sub_scene != SCENE_NONE)
        scene_draw(scene_manager->scene[scene_manager->sub_scene], window);
}
