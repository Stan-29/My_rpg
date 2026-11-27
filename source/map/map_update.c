/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_update
*/
#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

void map_update_view(map_t *map, const sfVector2f *pos, sfVector2f *dir,
    float dt)
{
    sfVector2f target = {0};
    float factor = CAMERA_SMOOTH * dt;
    sfVector2f center = {0};

    if (!map || !pos || !dir)
        return;
    if (factor > 1)
        factor = 1;
    target.x = pos->x + dir->x * CAMERA_LOOKAHEAD;
    target.y = pos->y + dir->y * CAMERA_LOOKAHEAD;
    center = sfView_getCenter(map->camera);
    center.x = center.x + (target.x - center.x) * factor;
    center.y = center.y + (target.y - center.y) * factor;
    sfView_setCenter(map->camera, center);
}

void map_set_center(map_t *map, const sfVector2f *pos)
{
    if (!map || !pos)
        return;
    sfView_setCenter(map->camera, *pos);
}
