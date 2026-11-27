/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_scene_update
*/
#include <criterion/criterion.h>

#include "types.h"

#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "player/player_internal.h" // IWYU pragma: keep

Test(scene_update_player_dir, basic_update_player_dir)
{
    scene_t *scene = scene_create(SCENE_GAME);

    scene_update_player_dir(scene, &(sfVector2f){0, 1});
    cr_assert_float_eq(scene->player->move.movement.y, 1, 0.01);
    scene_destroy(scene);
}

Test(scene_update_player_dir, update_player_dir_without_player)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_update_player_dir(scene, &(sfVector2f){0, 1});
    cr_assert(scene->player == NULL);
    scene_destroy(scene);
}

Test(scene_update_player_dir, update_player_dir_on_null)
{
    scene_update_player_dir(NULL, &(sfVector2f){0, 1});
}

Test(scene_update, player_moves_and_inputs_reset)
{
    scene_t *scene = scene_create(SCENE_GAME);
    sfVector2f start = scene->player->move.pos;

    scene_update_player_dir(scene, &(sfVector2f){0, 1});
    scene_update(scene, 1);
    cr_assert(scene->player->move.pos.y > start.y);
    cr_assert_float_eq(scene->player->move.movement.y, 0, 0.01);
    scene_destroy(scene);
}

Test(scene_update, update_without_map)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_update(scene, 1);
    cr_assert(scene->map == NULL);
    scene_destroy(scene);
}

Test(scene_update, update_on_null)
{
    scene_update(NULL, 1);
}
