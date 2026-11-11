/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "sound.h"
#include "sound_internal.h" // IWYU pragma: keep

#include <SFML/Audio/Types.h>

sound_t *sound_create(const sounds_tab_t *sound_infos)
{
    sound_t *sound = garbage_collector_malloc(sizeof(sound_t));

    if (!sound)
        return sound_destroy(sound);
    sound->id = sound_infos->id_sound;
    sound->base_volume = sound_infos->base_volume;
    sound->sound_buffer = sfSoundBuffer_createFromFile(sound_infos->filepath);
    if (!sound->sound_buffer)
        return sound_destroy(sound);
    sound->sound = sfSound_create();
    if (!sound->sound)
        return sound_destroy(sound);
    sfSound_setBuffer(sound->sound, sound->sound_buffer);
    sfSound_setVolume(sound->sound, sound->base_volume * INIT_RATIO);
    return sound;
}

void *sound_destroy(void *data)
{
    sound_t *sound = data;

    if (!sound)
        return NULL;
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->sound_buffer);
    garbage_collector_free(sound);
    return NULL;
}

void sound_play(sound_t *sound)
{
    if (!sound)
        return;
    sfSound_play(sound->sound);
    return;
}

void sound_change_volume(sound_t *sound, float ratio)
{
    if (!sound)
        return;
    sfSound_setVolume(sound->sound, sound->base_volume * ratio);
    return;
}

unsigned int sound_get_id(sound_t *sound)
{
    if (!sound)
        return 0;
    return sound->id;
}
