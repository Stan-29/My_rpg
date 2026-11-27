/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** music header
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

typedef enum music_id_e {
    MUSIC_NONE = 0,
    MUSIC_MENU,
    MUSIC_GAME,
    MUSIC_COUNT
} music_id_t;

typedef struct music_s music_t;

typedef struct music_tab_s {
    unsigned int id;
    const char *filepath;
    float volume;
} music_tab_t;

music_t *music_create(const music_tab_t *music_infos);
void *music_destroy(void *data);
void *music_stop(music_t *music);
void music_play(music_t *music);
void music_change_volume(music_t *music, float ratio);

#endif
