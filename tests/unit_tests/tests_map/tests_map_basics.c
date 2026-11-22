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
Test(map_update_view, stopped_moves_toward_pos)
{
    map_t *map = map_create();

    map_set_center(map, &(sfVector2f){0, 0});
    map_update_view(map, &(sfVector2f){100, 0}, &(sfVector2f){0, 0}, 0.1f);
    cr_assert_float_eq(sfView_getCenter(map->camera).x,
        100 * CAMERA_SMOOTH * 0.1f, 0.01);
    map_destroy(map);
}

Test(map_update_view, moving_targets_lookahead)
{
    map_t *map = map_create();

    map_set_center(map, &(sfVector2f){0, 0});
    map_update_view(map, &(sfVector2f){0, 0}, &(sfVector2f){1, 0}, 0.1f);
    cr_assert_float_eq(sfView_getCenter(map->camera).x,
        CAMERA_LOOKAHEAD * CAMERA_SMOOTH * 0.1f, 0.01);
    map_destroy(map);
}

Test(map_update_view, big_dt_lands_on_target)
{
    map_t *map = map_create();

    map_set_center(map, &(sfVector2f){0, 0});
    map_update_view(map, &(sfVector2f){50, 20}, &(sfVector2f){0, 1}, 10);
    cr_assert_float_eq(sfView_getCenter(map->camera).x, 50, 0.01);
    cr_assert_float_eq(sfView_getCenter(map->camera).y,
        20 + CAMERA_LOOKAHEAD, 0.01);
    map_destroy(map);
}

Test(map_update_view, update_view_on_null)
{
    map_t *map = map_create();

    map_update_view(NULL, &(sfVector2f){0, 0}, &(sfVector2f){0, 0}, 1);
    map_update_view(map, NULL, &(sfVector2f){0, 0}, 1);
    map_update_view(map, &(sfVector2f){0, 0}, NULL, 1);
    map_set_center(map, NULL);
    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_set_center, basic_set_center)
{
    map_t *map = map_create();

    map_set_center(map, &(sfVector2f){42, 24});
    cr_assert_float_eq(sfView_getCenter(map->camera).x, 42, 0.01);
    cr_assert_float_eq(sfView_getCenter(map->camera).y, 24, 0.01);
    map_destroy(map);
}

Test(map_set_center, set_center_on_null)
{
    map_set_center(NULL, &(sfVector2f){0, 0});
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
}
