/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "image/image.h"

#include <SFML/Graphics/Sprite.h>

#include <stddef.h>

sfView *scene_get_view(scene_t *scene)
{
    if (!scene)
        return NULL;
    return scene->view;
}

image_t *scene_find_image_by_pos(scene_t *scene, sfVector2f *pos)
{
    linked_list_t *temp = scene->ll_images;
    image_t *data = NULL;
    sfFloatRect image_bounds = {0};

    while (linked_list_get_next(temp) != NULL)
        temp = linked_list_get_next(temp);
    while (temp != NULL) {
        data = linked_list_get_data(temp);
        image_bounds = sfSprite_getGlobalBounds(image_get_sprite(data));
        if (sfFloatRect_contains(&image_bounds, pos->x, pos->y) &&
            image_is_clickable(data)) {
            return data;
        }
        temp = linked_list_get_prev(temp);
    }
    return NULL;
}

image_t *scene_get_held(scene_t *scene)
{
    if (!scene)
        return NULL;
    return scene->held;
}

linked_list_t *scene_get_texts(scene_t *scene)
{
    if (!scene)
        return NULL;
    return scene->ll_texts;
}
