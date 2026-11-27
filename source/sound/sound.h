/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** sound header
*/

#ifndef SOUND_H_
    #define SOUND_H_

typedef enum sound_id_e {
    SOUND_NONE = 0,
    SOUND_CLICK,
    SOUND_COUNT
} sound_id_t;

typedef struct sound_s sound_t;

typedef struct sound_tab_s {
    unsigned int id_sound;
    const char *filepath;
    float base_volume;
} sound_tab_t;

sound_t *sound_create(const sound_tab_t *sound_infos);
void *sound_destroy(void *data);
void sound_play(sound_t *sound);
void sound_change_volume(sound_t *sound, float ratio);
unsigned int sound_get_id(sound_t *sound);

#endif
