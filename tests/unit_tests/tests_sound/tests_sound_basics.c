/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_sound_basics
*/
#include <criterion/criterion.h>

#include "sound/sound.h"
#include "sound/sound_internal.h" // IWYU pragma: keep
#include "scene/scene_internal.h"

Test(sound_create, basic_create)
{
    sound_t *sound = sound_create(&sound_menu_tab[0]);

    cr_assert(sound != NULL);
    cr_assert(sound->id == SOUND_CLICK);
    sound_destroy(sound);
}

Test(sound_create, create_on_null)
{
    sound_t *sound = sound_create(NULL);

    cr_assert(sound == NULL);
    sound_destroy(sound);
}

Test(sound_create, create_with_wrong_path)
{
    sound_tab_t infos = {0, "nope.wav", 50};
    sound_t *sound = sound_create(&infos);

    cr_assert(sound == NULL);
}

Test(sound_destroy, basic_destroy)
{
    sound_t *sound = sound_create(&sound_menu_tab[0]);

    cr_assert(sound_destroy(sound) == NULL);
}

Test(sound_destroy, destroy_on_null)
{
    sound_t *sound = NULL;

    cr_assert(sound_destroy(sound) == NULL);
}

Test(sound_play, basic_play)
{
    sound_t *sound = sound_create(&sound_menu_tab[0]);

    sound_play(sound);
    cr_assert(sound != NULL);
    sound_destroy(sound);
}

Test(sound_play, play_on_null)
{
    sound_t *sound = NULL;

    sound_play(sound);
    cr_assert(sound == NULL);
}

Test(sound_change_volume, basic_change_volume)
{
    sound_t *sound = sound_create(&sound_menu_tab[0]);

    sound_change_volume(sound, 1);
    cr_assert(sound != NULL);
    sound_destroy(sound);
}

Test(sound_change_volume, change_volume_on_null)
{
    sound_t *sound = NULL;

    sound_change_volume(sound, 1);
    cr_assert(sound == NULL);
}

Test(sound_get_id, basic_get_id)
{
    sound_t *sound = sound_create(&sound_menu_tab[0]);

    cr_assert(sound_get_id(sound) == SOUND_CLICK);
    sound_destroy(sound);
}

Test(sound_get_id, get_id_on_null)
{
    sound_t *sound = NULL;

    cr_assert(sound_get_id(sound) == 0);
}
