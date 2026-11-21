/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_basics
*/
#include "defines.h"

#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

#include <math.h>
 

void map_update_dir(map_t *map, sfVector2f *dir)
{
    if (!map)
        return;
    map->dir.x += dir->x;
    map->dir.y += dir->y;
}

void map_update_view(map_t *map, float dt)
{
    float len = 0;

    if (!map)
        return;
    len = sqrtf(map->dir.x * map->dir.x + map->dir.y * map->dir.y);
    if (len > 0) {
        map->dir.x /= len;
        map->dir.y /= len;
    }
    sfView_move(map->camera, (sfVector2f){map->dir.x * CAMERA_SPEED * dt,
            map->dir.y * CAMERA_SPEED * dt});
    map->dir = (sfVector2f){0};
}

void map_set_center(map_t *map, sfVector2f *pos)
{
    if (!map || !pos)
        return;
    sfView_setCenter(map->camera, *pos);
}
