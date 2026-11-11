/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "consts.h"
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

static void image_fill_struct(image_t *image, const images_tab_t *image_infos,
    unsigned int id)
{
    image->id = id;
    image->movable_zone = image_infos->movable_zone;
    image->base_scale = image_infos->scale;
    image->base_pos = image_infos->pos;
    image->func = image_infos->func;
}

image_t *image_create(const images_tab_t *image_infos, unsigned int id)
{
    image_t *image = garbage_collector_malloc(sizeof(image_t));

    if (!image)
        return image_destroy(image);
    image_fill_struct(image, image_infos, id);
    image->texture = sfTexture_createFromFile(image_infos->filepath, NULL);
    if (!image->texture)
        return image_destroy(image);
    image->sprite = sfSprite_create();
    if (!image->sprite)
        return image_destroy(image);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    if (image_infos->sprite_sheet.width != 0)
        sfSprite_setTextureRect(image->sprite, image_infos->sprite_sheet);
    sfSprite_setPosition(image->sprite, image_infos->pos);
    sfSprite_setScale(image->sprite, image_infos->scale);
    return image;
}

void *image_destroy(void *data)
{
    image_t *image = data;

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
    if (image == NULL || window == NULL)
        return;
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

unsigned int image_start_func(image_t *image, scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    if (!image)
        return ERROR;
    return image->func(scene_manager, scene, engine);
}
