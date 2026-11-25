/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_collision
*/
#include "defines.h"
#include "consts.h"

#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

#include <stddef.h>
#include <math.h>

static sfVector2i get_tab_pos_from_screen(const sfVector2f *pos)
{
    sfVector2i tile = {0};
    float a = (pos->x - MAP_OFFSET_X) / HALF_TILE_W;
    float b = (pos->y - MAP_OFFSET_Y) / HALF_TILE_H;

    tile.x = (int)floorf((a + b) / 2.0f);
    tile.y = (int)floorf((b - a) / 2.0f);
    return tile;
}

bool map_collides(map_t *map, const sfVector2f *feet_pos)
{
    sfVector2i tile = get_tab_pos_from_screen(feet_pos);

    if (tile.x < 0 || tile.x >= MAP_FLOORS_SIZE || tile.y < 0 ||
        tile.y >= MAP_FLOORS_SIZE)
        return true;
    return object_tab[map->map_objects[tile.y][tile.x]].solid;
}
