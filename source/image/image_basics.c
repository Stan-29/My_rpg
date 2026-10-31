/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "consts.h"
#include "image/image.h"
#include <SFML/Graphics/Types.h>

struct image_s {
    unsigned int id;
    sfTexture *texture;
    sfSprite *sprite;
};

image_t *image_create(const images_tab_t *image_infos, unsigned int id)
{
    image_t *image = garbage_collector_malloc(sizeof(image_t));

    if (!image)
        return image_destroy(image);
    image->id = id;
    image->texture = sfTexture_createFromFile(image_infos->filepath, NULL);
    if (!image->texture)
        return image_destroy(image);
    image->sprite = sfSprite_create();
    if (!image->sprite)
        return image_destroy(image);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image_infos->sprite_sheet);
    sfSprite_setPosition(image->sprite, image_infos->pos);
    return image;
}

void *image_destroy(image_t *image)
{
    if (!image)
        return NULL;
    if (image->sprite)
        sfSprite_destroy(image->sprite);
    if (image->texture)
        sfTexture_destroy(image->texture);
    garbage_collector_free(image);
    return NULL;
}

void image_draw(image_t *image, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

unsigned int image_get_id(image_t *image)
{
    if (!image)
        return 0;
    return image->id;
}
