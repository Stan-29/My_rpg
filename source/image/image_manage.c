/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"

#include "image/image_internal.h" // IWYU pragma: keep
#include "image/image.h"

#include <SFML/Graphics/Sprite.h>

void image_change_scale(image_t *image, sfVector2f *scale)
{
    if (!image)
        return;
    sfSprite_setScale(image->sprite, *scale);
}

void image_change_pos(image_t *image, sfVector2f *pos)
{
    if (!image)
        return;
    sfSprite_setPosition(image->sprite, *pos);
}

void image_set_base_pos(image_t *image, sfVector2f *pos)
{
    if (!image)
        return;
    if (image->movable_axes.x == 1)
        image->base_pos.x = pos->x;
    if (image->movable_axes.y == 1)
        image->base_pos.y = pos->y;
}

void image_change_color(image_t *image, sfColor *color)
{
    if (!image)
        return;
    sfSprite_setColor(image->sprite, *color);
}

unsigned int image_start_func(image_t *image, scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    if (!image)
        return ERROR;
    return image->func(scene_manager, scene, engine);
}
