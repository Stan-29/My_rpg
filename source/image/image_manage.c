/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
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

void image_change_color(image_t *image, sfColor *color)
{
    if (!image)
        return;
    sfSprite_setColor(image->sprite, *color);
}
