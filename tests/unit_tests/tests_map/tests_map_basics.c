/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_map_basics
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
    sfVector2f camera_pos = {0};

    camera_pos = sfView_getCenter(map->camera);
    map_update_view(map, &(sfVector2f){0, 1}, 1);
    cr_assert_float_eq(sfView_getCenter(map->camera).y, camera_pos.y + CAMERA_SPEED, 0.01);
    map_destroy(map);
}

Test(map_update_view, update_view_on_null)
{
    map_t *map = NULL;

    map_update_view(map, &(sfVector2f){0, 1}, 1);
    cr_assert(map == NULL);
    map_destroy(map);
}


Test(map_draw, draw_on_null)
{
    map_t *map = map_create();

    map_draw(map, NULL);
    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_draw, draw_null_map)
{
    map_draw(NULL, NULL);
    cr_assert(true);
}
