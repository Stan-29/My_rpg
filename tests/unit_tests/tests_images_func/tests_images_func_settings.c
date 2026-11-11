/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_images_func_settings
*/
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>

#include "enums.h"
#include "linked_list/linked_list.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "image/image_internal.h" // IWYU pragma: keep
#include "music/music.h" 
#include "music/music_internal.h" // IWYU pragma: keep
#include "sound/sound.h"
#include "sound/sound_internal.h" // IWYU pragma: keep

#include "images_func.h"
#include "types.h"

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>

Test(image_func_go_to_settings, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_NONE;
    image_func_go_to_settings(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_SETTINGS);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

static void add_held_with_id(scene_manager_t *scene_manager, scene_t *scene,
    unsigned int id)
{
    linked_list_t *temp = scene->ll_images;
    image_t *data = NULL;

    while (temp != NULL) {
        data = linked_list_get_data(temp);
        if (data->id == id)
            scene->held = data;
        temp = linked_list_get_next(temp);
    }
}

Test(image_func_music_volume, change_music_volume_to_min)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    music_t *music = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left, scene->held->base_pos.y};
    image_func_music_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    music = linked_list_get_data(scene->ll_musics);
    cr_assert(sfMusic_getVolume(music->music) == 0);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_music_volume, basic_change_music_volume)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    music_t *music = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left + scene->held->movable_zone.width / 2,
            scene->held->base_pos.y};
    image_func_music_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    music = linked_list_get_data(scene->ll_musics);
    cr_assert_float_eq(sfMusic_getVolume(music->music),
        music->base_volume * 0.5, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_music_volume, change_music_volume_to_max)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    music_t *music = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left + scene->held->movable_zone.width,
            scene->held->base_pos.y};
    image_func_music_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    music = linked_list_get_data(scene->ll_musics);
    cr_assert(sfMusic_getVolume(music->music) == music->base_volume);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}


Test(image_func_sound_volume, change_sound_volume_to_min)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sound_t *sound = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left, scene->held->base_pos.y};
    image_func_sound_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    sound = linked_list_get_data(scene->ll_sounds);
    cr_assert(sfSound_getVolume(sound->sound) == 0);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_sound_volume, basic_change_sound_volume)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sound_t *sound = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left + scene->held->movable_zone.width / 2,
            scene->held->base_pos.y};

    image_func_sound_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    sound = linked_list_get_data(scene->ll_sounds);
    cr_assert_float_eq(sfSound_getVolume(sound->sound),
        sound->base_volume * 0.5, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_sound_volume, change_sound_volume_to_max)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sound_t *sound = NULL;

    scene_manager->sub_scene = SCENE_SETTINGS;
    scene = scene_manager_get_current(scene_manager);
    add_held_with_id(scene_manager, scene, 6);
    scene->held->base_pos = (sfVector2f)
        {scene->held->movable_zone.left + scene->held->movable_zone.width,
            scene->held->base_pos.y};
    image_func_sound_volume(scene_manager, scene, engine);
    scene_manager->sub_scene = SCENE_NONE;
    scene = scene_manager_get_current(scene_manager);
    sound = linked_list_get_data(scene->ll_sounds);
    cr_assert(sfSound_getVolume(sound->sound) == sound->base_volume);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}