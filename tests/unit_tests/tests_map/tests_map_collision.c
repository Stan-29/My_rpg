/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_map_collision
*/
#include <criterion/criterion.h>

#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/System/Vector2.h>

static map_t *map = NULL;

static void setup_map(void)
{
    map = map_create();
    cr_assert(map != NULL);
    map->map_objects[0][0] = OBJECT_NONE;
    map->map_objects[2][2] = OBJECT_TREE;
    map->map_objects[MAP_FLOORS_SIZE - 1][MAP_FLOORS_SIZE - 1] = OBJECT_NONE;
}

static void destroy_map(void)
{
    map_destroy(map);
}

TestSuite(map_collides, .init = setup_map, .fini = destroy_map);

static sfVector2f tile_center(int col, int row)
{
    return (sfVector2f){TILE_TO_WORLD_X(col, row),
        TILE_TO_WORLD_Y(col, row) + HALF_TILE_H};
}

Test(map_collides, tree_tile_collides)
{
    sfVector2f pos = tile_center(2, 2);

    cr_assert(map_collides(map, &pos));
}

Test(map_collides, empty_tile_does_not_collide)
{
    sfVector2f pos = tile_center(0, 0);

    cr_assert_not(map_collides(map, &pos));
}

Test(map_collides, outside_map_collides)
{
    sfVector2f pos = {-5000, -5000};

    cr_assert(map_collides(map, &pos));
}

Test(map_collides, last_tile_is_inside_map)
{
    sfVector2f pos = tile_center(MAP_FLOORS_SIZE - 1, MAP_FLOORS_SIZE - 1);

    cr_assert_not(map_collides(map, &pos));
}
