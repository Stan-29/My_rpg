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
    if (image->movable_zone.width != 0) {
        image->base_pos.x = pos->x;
        if (pos->x < image->movable_zone.left)
            image->base_pos.x = image->movable_zone.left;
        if (pos->x > (image->movable_zone.left + image->movable_zone.width))
            image->base_pos.x = image->movable_zone.left +
                image->movable_zone.width;
    }
    if (image->movable_zone.height != 0) {
        image->base_pos.y = pos->y;
        if (pos->y < image->movable_zone.top)
            image->base_pos.y = image->movable_zone.top;
        if (pos->y > (image->movable_zone.top + image->movable_zone.height))
            image->base_pos.y = image->movable_zone.top +
                image->movable_zone.height;
    }
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
