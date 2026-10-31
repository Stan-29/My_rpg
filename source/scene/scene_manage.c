/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "consts.h"
#include "defines.h"
#include "image/image.h"
#include "linked_list/linked_list.h"
#include "scene_internal.h"

#include <SFML/Audio/Music.h>

void scene_start(scene_t *scene)
{
    sfMusic_play(scene->music);
}

void scene_stop(scene_t *scene)
{
    sfMusic_stop(scene->music);
}

unsigned int scene_manage_click(scene_manager_t *scene_manager, scene_t *scene,
    sfVector2f *pos)
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
            images_scenes_tab[image_get_id(data)].func != NULL)
            return images_scenes_tab[image_get_id(data)].
                func(scene_manager, scene);
        temp = linked_list_get_prev(temp);
    }
    return OK;
}
