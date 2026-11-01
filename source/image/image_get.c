/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "image/image_internal.h" // IWYU pragma: keep
#include "image/image.h"

unsigned int image_get_id(image_t *image)
{
    if (!image)
        return 0;
    return image->id;
}

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
