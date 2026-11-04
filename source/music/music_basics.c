/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "music.h"

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>

struct music_s {
    unsigned int id;
    float base_volume;
    sfMusic *music;
};

music_t *music_create(const musics_tab_t *music_infos)
{
    music_t *music = garbage_collector_malloc(sizeof(music_t));

    if (!music)
        return music_destroy(music);
    music->id = music_infos->id;
    music->music = sfMusic_createFromFile(music_infos->filepath);
    music->base_volume = music_infos->volume;
    if (!music->music)
        return music_destroy(music);
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_setVolume(music->music, music->base_volume * INIT_RATIO);
    return music;
}

void *music_destroy(void *data)
{
    music_t *music = data;

    if (!music)
        return NULL;
    sfMusic_destroy(music->music);
    garbage_collector_free(music);
    return NULL;
}

void *music_play(music_t *music)
{
    if (!music)
        return NULL;
    sfMusic_play(music->music);
    return NULL;
}

void *music_stop(music_t *music)
{
    if (!music)
        return NULL;
    sfMusic_stop(music->music);
    return NULL;
}

void music_change_volume(music_t *music, float ratio)
{
    if (!music)
        return;
    sfMusic_setVolume(music->music, music->base_volume * ratio);
    return;
}
