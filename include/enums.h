/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** enums header
*/

#ifndef ENUMS_H_
    #define ENUMS_H_

typedef enum scene_id_e {
    SCENE_NONE = 0,
    SCENE_MENU,
    SCENE_SAVE,
    SCENE_SETTINGS,
    SCENE_GAME,
    SCENE_PAUSE,
    SCENE_INVENTORY,
    SCENE_COUNT
} scene_id_t;

typedef enum sounds_id_e {
    SOUND_NONE = 0,
    SOUND_CLICK,
    SOUND_COUNT
} sounds_id_t;

typedef enum musics_id_e {
    MUSIC_NONE = 0,
    MUSIC_MENU,
    MUSIC_GAME,
    MUSIC_COUNT
} musics_id_t;

#endif
