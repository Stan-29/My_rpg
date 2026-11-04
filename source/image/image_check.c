/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "image/image_internal.h" // IWYU pragma: keep
#include "image/image.h"

#include <unistd.h>

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
    if (image->movable_zone.width != 0 ||
        image->movable_zone.height != 0)
        return true;
    return false;
}
