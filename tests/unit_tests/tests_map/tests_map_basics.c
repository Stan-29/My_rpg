/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_map_basics
*/
#include <criterion/criterion.h>

#include "defines.h"

#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>

Test(map_create, basic_create)
{
    map_t *map = map_create();

    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_update_view, basic_update_view)
{
    map_t *map = map_create();
    sfVector2f camera_pos = sfView_getCenter(map->camera);

    map_update_dir(map, &(sfVector2f){0, 1});
    map_update_view(map, 1);
    cr_assert_float_eq(sfView_getCenter(map->camera).y,
        camera_pos.y + CAMERA_SPEED, 0.01);
    map_destroy(map);
}

Test(map_update_view, diagonal_is_normalized)
{
    map_t *map = map_create();
    sfVector2f camera_pos = sfView_getCenter(map->camera);

    map_update_dir(map, &(sfVector2f){1, 0});
    map_update_dir(map, &(sfVector2f){0, -1});
    map_update_view(map, 1);
    cr_assert_float_eq(sfView_getCenter(map->camera).x,
        camera_pos.x + CAMERA_SPEED * 0.7071f, 0.1);
    cr_assert_float_eq(sfView_getCenter(map->camera).y,
        camera_pos.y - CAMERA_SPEED * 0.7071f, 0.1);
    map_destroy(map);
}

Test(map_update_view, opposite_keys_dont_move)
{
    map_t *map = map_create();
    sfVector2f camera_pos = sfView_getCenter(map->camera);

    map_update_dir(map, &(sfVector2f){0, 1});
    map_update_dir(map, &(sfVector2f){0, -1});
    map_update_view(map, 1);
    cr_assert_float_eq(sfView_getCenter(map->camera).y, camera_pos.y, 0.01);
    map_destroy(map);
}

Test(map_update_view, dir_is_reset_after_update)
{
    map_t *map = map_create();
    sfVector2f camera_pos = {0};

    map_update_dir(map, &(sfVector2f){0, 1});
    map_update_view(map, 1);
    camera_pos = sfView_getCenter(map->camera);
    map_update_view(map, 1);
    cr_assert_float_eq(sfView_getCenter(map->camera).y, camera_pos.y, 0.01);
    cr_assert_float_eq(map->dir.y, 0, 0.01);
    map_destroy(map);
}

Test(map_update_view, update_view_on_null)
{
    map_update_view(NULL, 1);
}

Test(map_update_dir, dir_is_summed)
{
    map_t *map = map_create();

    map_update_dir(map, &(sfVector2f){1, 0});
    map_update_dir(map, &(sfVector2f){0, 1});
    cr_assert_float_eq(map->dir.x, 1, 0.01);
    cr_assert_float_eq(map->dir.y, 1, 0.01);
    map_destroy(map);
}

Test(map_update_dir, update_dir_on_null)
{
    map_update_dir(NULL, &(sfVector2f){0, 1});
}

Test(map_draw, draw_null_window)
{
    map_t *map = map_create();

    map_draw(map, NULL);
    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_draw, draw_null_map)
{
    map_draw(NULL, NULL);
    // ne doit pas crasher
}
