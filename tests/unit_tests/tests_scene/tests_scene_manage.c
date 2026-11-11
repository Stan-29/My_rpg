/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_manage
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "linked_list/linked_list.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "sound/sound.h"
#include "sound/sound_internal.h" // IWYU pragma: keep
#include "music/music.h"
#include "music/music_internal.h" // IWYU pragma: keep

Test(scene_start, basic_scene_start)
{
    scene_t *scene = scene_create(SCENE_MENU);
    scene_t *scene_game = scene_create(SCENE_GAME);

    scene_start(scene_game);
    cr_assert(scene != NULL);
    cr_assert(scene_game != NULL);
    scene_destroy(scene);
    scene_destroy(scene_game);
}

Test(scene_start, scene_start_on_null)
{
    scene_t *scene = scene_create(SCENE_MENU);
    scene_t *scene_game = NULL;

    scene_start(scene_game);
    cr_assert(scene != NULL);
    scene_destroy(scene);
}

Test(scene_change_sound_volume, basic_change_volume)
{
    scene_t *scene = scene_create(SCENE_MENU);
    sound_t *sound = NULL;

    scene_change_sound_volume(scene, 1);
    sound = linked_list_get_data(scene->ll_sounds);
    cr_assert(sound->base_volume == 50);
    scene_destroy(scene);
}

Test(scene_change_sound_volume, change_volume_on_null)
{
    scene_t *scene = NULL;

    scene_change_sound_volume(scene, 1);
    cr_assert(scene == NULL);
    scene_destroy(scene);
}


Test(scene_change_music_volume, basic_change_volume)
{
    scene_t *scene = scene_create(SCENE_MENU);
    music_t *music = NULL;

    scene_change_music_volume(scene, 1);
    music = linked_list_get_data(scene->ll_sounds);
    cr_assert(music->base_volume == 50);
    scene_destroy(scene);
}

Test(scene_change_music_volume, change_volume_on_null)
{
    scene_t *scene = NULL;

    scene_change_music_volume(scene, 1);
    cr_assert(scene == NULL);
    scene_destroy(scene);
}