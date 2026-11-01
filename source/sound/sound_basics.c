/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "garbage_collector/garbage_collector.h"
#include "sound.h"

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Types.h>

struct sound_s {
    unsigned int id;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
};

sound_t *sound_create(const sounds_tab_t *sound_infos)
{
    sound_t *sound = garbage_collector_malloc(sizeof(sound_t));

    if (!sound)
        return sound_destroy(sound);
    sound->id = sound_infos->id_sound;
    sound->sound_buffer = sfSoundBuffer_createFromFile(sound_infos->filepath);
    if (!sound->sound_buffer)
        return sound_destroy(sound);
    sound->sound = sfSound_create();
    if (!sound->sound)
        return sound_destroy(sound);
    sfSound_setBuffer(sound->sound, sound->sound_buffer);
    sfSound_setVolume(sound->sound, sound_infos->volume);
    return sound;
}

void *sound_destroy(sound_t *sound)
{
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

unsigned int sound_get_id(sound_t *sound)
{
    if (!sound)
        return 0;
    return sound->id;
}
