/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_map_draw
*/
#include <criterion/criterion.h>

#include "map/map.h"

#include <stdbool.h>
#include <stddef.h>

Test(map_draw_floor, draw_floor_null_window)
{
    map_t *map = map_create();

    map_draw_floor(map, NULL);
    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_draw_floor, draw_floor_null_map)
{
    map_draw_floor(NULL, NULL);
}

Test(map_draw_objects, draw_objects_null_window)
{
    map_t *map = map_create();

    map_draw_objects(map, NULL, 0, false);
    map_draw_objects(map, NULL, 0, true);
    cr_assert(map != NULL);
    map_destroy(map);
}

Test(map_draw_objects, draw_objects_null_map)
{
    map_draw_objects(NULL, NULL, 0, false);
    map_draw_objects(NULL, NULL, 0, true);
}
