/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_manager_manage
*/
#include <SFML/Audio/Music.h>
#include <criterion/criterion.h>

#include "enums.h"
#include "linked_list/linked_list.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "music/music.h"
#include "music/music_internal.h" // IWYU pragma: keep
#include "sound/sound.h"
#include "sound/sound_internal.h" // IWYU pragma: keep


Test(scene_manager_set_scene, basic_set_scene)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_GAME);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_set_scene, set_scene_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(NULL, SCENE_GAME);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_set_scene, set_scene_on_wrong_scene_less)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(NULL, SCENE_NONE);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_set_scene, set_scene_on_wrong_scene_more)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(NULL, SCENE_COUNT);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_exit_sub, basic_set_scene)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(scene_manager, SCENE_SETTINGS);
    scene_manager_exit_sub(scene_manager);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_exit_sub, set_scene_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene_manager_exit_sub(NULL);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_GAME);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_change_music_volume, basic_change_volume_music)
{
    scene_manager_t *scene_manager = scene_manager_create();
    music_t *music = NULL;

    scene_manager_change_music_volume(scene_manager, 1);
    music = linked_list_get_data(scene_manager_get_current(scene_manager)->ll_musics);
    cr_assert(sfMusic_getVolume(music->music) == 50);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_change_music_volume, change_volume_music_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();
    music_t *music = NULL;

    scene_manager_change_music_volume(NULL, 1);
    music = linked_list_get_data(scene_manager_get_current(scene_manager)->ll_musics);
    cr_assert(sfMusic_getVolume(music->music) == 25);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_change_sound_volume, basic_change_volume_sound)
{
    scene_manager_t *scene_manager = scene_manager_create();
    sound_t *sound = NULL;

    scene_manager_change_sound_volume(scene_manager, 1);
    sound = linked_list_get_data(scene_manager_get_current(scene_manager)->ll_sounds);
    cr_assert(sfSound_getVolume(sound->sound) == 50);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_change_sound_volume, change_volume_sound_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();
    sound_t *sound = NULL;

    scene_manager_change_sound_volume(NULL, 1);
    sound = linked_list_get_data(scene_manager_get_current(scene_manager)->ll_sounds);
    cr_assert(sfSound_getVolume(sound->sound) == 25);
    scene_manager_destroy(scene_manager);
}