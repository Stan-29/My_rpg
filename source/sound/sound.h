/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SOUND_H_
    #define SOUND_H_

    #include "consts.h"

typedef struct sound_s sound_t;

sound_t *sound_create(const sounds_tab_t *sound_infos);
void *sound_destroy(sound_t *sound);
void sound_play(sound_t *sound);
unsigned int sound_get_id(sound_t *sound);

#endif
