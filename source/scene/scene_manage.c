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
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "types.h"

#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Mouse.h>

void scene_start(scene_t *scene)
{
    if (!scene->music)
        return;
    sfMusic_play(scene->music);
}

void scene_stop(scene_t *scene)
{
    if (!scene->music)
        return;
    sfMusic_stop(scene->music);
}

static void get_new_pos_and_scale(image_t *data,
    sfVector2f *new_scale, sfVector2f *new_pos, unsigned int hover)
{
    sfFloatRect local = {0};
    sfVector2f ratio = {0};

    if (hover == 2) {
        *new_scale = image_get_scale(data);
        *new_pos = image_get_pos(data);
        return;
    } else if (hover == 1)
        ratio = (sfVector2f){RATIO_HOVER_POS, RATIO_HOVER_SCALE};
    else
        ratio = (sfVector2f){RATIO_CLICK_POS, RATIO_CLICK_SCALE};
    *new_scale = image_get_scale(data);
    *new_pos = image_get_pos(data);
    local = sfSprite_getLocalBounds(image_get_sprite(data));
    new_pos->x -= local.width * new_scale->x * ratio.x;
    new_pos->y -= local.height * new_scale->y * ratio.x;
    *new_scale = (sfVector2f){new_scale->x * ratio.y, new_scale->y * ratio.y};
}

unsigned int scene_handle_click(scene_manager_t *scene_manager, scene_t *scene,
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
            images_scenes_tab[image_get_id(data)].func != NULL) {
            return images_scenes_tab[image_get_id(data)].
                func(scene_manager, scene);
        }
        temp = linked_list_get_prev(temp);
    }
    return OK;
}

static void manage_image_state(image_t *data, sfVector2f *pos,
    sfVector2f *new_scale, sfVector2f *new_pos)
{
    sfFloatRect image_bounds = {0};

    image_bounds = sfSprite_getGlobalBounds(image_get_sprite(data));
    if (sfFloatRect_contains(&image_bounds, pos->x, pos->y) &&
        images_scenes_tab[image_get_id(data)].func != NULL) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            image_change_color(data, &(sfColor){180, 180, 180, 255});
            get_new_pos_and_scale(data, new_scale, new_pos, 2);
        } else {
            get_new_pos_and_scale(data, new_scale, new_pos, 1);
        }
    } else
        get_new_pos_and_scale(data, new_scale, new_pos, 2);
}

void scene_handle_hover(scene_t *scene, sfRenderWindow *window)
{
    linked_list_t *temp = scene->ll_images;
    image_t *data = NULL;
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
        sfMouse_getPositionRenderWindow(window), scene->view);
    sfVector2f new_scale = {1, 1};
    sfVector2f new_pos = {1, 1};

    while (linked_list_get_next(temp) != NULL)
        temp = linked_list_get_next(temp);
    while (temp != NULL) {
        data = linked_list_get_data(temp);
        image_change_color(data, &sfWhite);
        manage_image_state(data, &pos, &new_scale, &new_pos);
        image_change_scale(data, &new_scale);
        image_change_pos(data, &new_pos);
        temp = linked_list_get_prev(temp);
    }
}
