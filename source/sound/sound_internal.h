/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SOUND_INTERNAL_H_
    #define SOUND_INTERNAL_H_

    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>

struct sound_s {
    unsigned int id;
    float base_volume;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
};

#endif
