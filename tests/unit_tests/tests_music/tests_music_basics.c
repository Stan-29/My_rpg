/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_music_basics
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "music/music.h"
#include "music/music_internal.h" // IWYU pragma: keep

Test(music_create, basic_create)
{
    music_t *music = music_create(&musics_menu_tab[0]);

    cr_assert(music != NULL);
    cr_assert(music->id == MUSIC_MENU);
    music_destroy(music);
}

Test(music_create, create_on_NULL)
{
    music_t *music = music_create(&musics_settings_tab[0]);

    cr_assert(music == NULL);
    music_destroy(music);
}

Test(music_destroy, basic_destroy)
{
    music_t *music = music_create(&musics_menu_tab[0]);

    cr_assert(music_destroy(music) == NULL);
}

Test(music_destroy, destroy_on_null)
{
    music_t *music = NULL;

    cr_assert(music_destroy(music) == NULL);
}


Test(music_play, basic_play)
{
    music_t *music = music_create(&musics_menu_tab[0]);

    music_play(music);
    cr_assert(music != NULL);
    music_destroy(music);
}

Test(music_play, play_on_null)
{
    music_t *music = NULL;

    music_play(music);
    cr_assert(music == NULL);
}


Test(music_stop, basic_stop)
{
    music_t *music = music_create(&musics_menu_tab[0]);

    music_stop(music);
    cr_assert(music != NULL);
    music_destroy(music);
}

Test(music_stop, stop_on_null)
{
    music_t *music = NULL;

    music_stop(music);
    cr_assert(music == NULL);
}


Test(music_change_volume, basic_change_volume)
{
    music_t *music = music_create(&musics_menu_tab[0]);

    music_change_volume(music, 1);
    cr_assert(music != NULL);
    music_destroy(music);
}

Test(music_change_volume, cheange_volume_on_null)
{
    music_t *music = NULL;

    music_change_volume(music, 1);
    cr_assert(music == NULL);
}
