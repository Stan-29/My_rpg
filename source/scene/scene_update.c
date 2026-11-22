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
    if (!scene || !scene->player)
        return;
    player_update_dir(scene->player, dir);
}

void scene_update(scene_t *scene, float dt)
{
    sfVector2f pos = {0};
    sfVector2f dir = {0};

    if (!scene || !scene->map || !scene->player)
        return;
    player_update(scene->player, dt);
    pos = player_get_pos(scene->player);
    dir = player_get_movement(scene->player);
    map_update_view(scene->map, &pos, &dir, dt);
    player_reset_inputs(scene->player);
}
