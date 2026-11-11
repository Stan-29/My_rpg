/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_handle
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

Test(scene_handle_hover, basic_handle_hover)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_handle_hover(scene, NULL);
    cr_assert(scene != NULL);
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
