/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_scene_handle
*/
#include <criterion/criterion.h>

#include "types.h"

#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "image/image_internal.h" // IWYU pragma: keep
#include "linked_list/linked_list.h"
#include "sound/sound.h"

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>

Test(scene_handle_hover, basic_handle_hover)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_handle_hover(scene, NULL);
    cr_assert(scene != NULL);
    scene_destroy(scene);
}

Test(scene_handle_hover, hover_clickable_image)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *button = linked_list_get_data(
        linked_list_get_next(scene->lists->ll_images));

    button->base_pos = (sfVector2f){0, 0};
    sfSprite_setPosition(button->sprite, (sfVector2f){0, 0});
    scene_handle_hover(scene, NULL);
    cr_assert_float_eq(sfSprite_getScale(button->sprite).x,
        button->base_scale.x * RATIO_HOVER_SCALE, 0.01);
    scene_destroy(scene);
}

Test(scene_play_sound, basic_sound_play)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_play_sound(scene, SOUND_CLICK);
    cr_assert(scene != NULL);
    scene_destroy(scene);
}

Test(scene_play_sound, sound_play_no_button)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_play_sound(scene, SOUND_NONE);
    cr_assert(scene != NULL);
    scene_destroy(scene);
}
