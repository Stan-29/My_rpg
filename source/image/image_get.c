/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "image/image_internal.h" // IWYU pragma: keep
#include "image/image.h"

#include <unistd.h>

sfSprite *image_get_sprite(image_t *image)
{
    if (!image)
        return 0;
    return image->sprite;
}

sfVector2f image_get_scale(image_t *image)
{
    if (!image)
        return (sfVector2f){0};
    return image->base_scale;
}

sfVector2f image_get_pos(image_t *image)
{
    if (!image)
        return (sfVector2f){0};
    return image->base_pos;
}

bool image_is_clickable(image_t *image)
{
    if (!image)
        return false;
    if (image->func != NULL)
        return true;
    return false;
}

bool image_is_movable(image_t *image)
{
    if (!image)
        return false;
    if (image->movable_axes.x != 0 ||
        image->movable_axes.y != 0)
        return true;
    return false;
}
