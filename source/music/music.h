/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

    #include "consts.h"

typedef struct music_s music_t;

music_t *music_create(const musics_tab_t *music_infos);
void *music_destroy(void *data);
void *music_stop(music_t *music);
void *music_play(music_t *music);
void music_change_volume(music_t *music, float ratio);

#endif
