/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_manager_basics
*/
#include "enums.h"

#include "garbage_collector/garbage_collector.h"
#include "scene/scene.h"
#include "scene_manager/scene_manager.h"

struct scene_manager_s {
    unsigned int current_scene;
    scene_t *scene[SCENE_COUNT];
};

scene_manager_t *scene_manager_create(void)
{
    scene_manager_t *scene_manager =
        garbage_collector_malloc(sizeof(scene_manager_t));

    if (!scene_manager)
        return NULL;
    scene_manager->current_scene = SCENE_MENU;
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
    unsigned int scene_id = SCENE_MENU;

    if (!scene_manager)
        return;
    scene_id = scene_manager->current_scene;
    scene_draw(scene_manager->scene[scene_id], window);
}

void scene_manager_set_scene(scene_manager_t *scene_manager,
    unsigned int scene_id)
{
    if (!scene_manager || scene_id <= SCENE_NONE || scene_id >= SCENE_COUNT)
        return;
    scene_stop(scene_manager->scene[scene_manager->current_scene]);
    scene_manager->current_scene = scene_id;
    scene_start(scene_manager->scene[scene_manager->current_scene]);
}

scene_t *scene_manager_get_current(scene_manager_t *scene_manager)
{
    unsigned int current_scene = 0;

    if (!scene_manager)
        return NULL;
    current_scene = scene_manager->current_scene;
    return scene_manager->scene[current_scene];
}
