/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "map/map.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

void scene_update_map_dir(scene_t *scene, sfVector2f *dir)
{
    if (!scene || !scene->map)
        return;
    map_update_dir(scene->map, dir);
}

void scene_update(scene_t *scene, float dt)
{
    if (!scene || !scene->map)
        return;
    map_update_view(scene->map, dt);
}
