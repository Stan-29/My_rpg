/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "map/map.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

void scene_update_player_dir(scene_t *scene, sfVector2f *dir)
{
    if (!scene || !scene->map)
        return;
    player_update_dir(scene->player, dir);
}

void scene_update(scene_t *scene, float dt)
{
    if (!scene || !scene->map)
        return;
    player_update(scene->player, dt);
    map_update_view(scene->map, player_get_pos(scene->player),
        player_get_movement(scene->player), dt);
    player_reset_inputs(scene->player);
}
