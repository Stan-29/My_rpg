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

typedef enum floor_id_e {
    FLOOR_GRASS = 0,
    FLOOR_PATH,
    FLOOR_COUNT
} floor_id_t;

typedef enum object_id_e {
    OBJECT_NONE = 0,
    OBJECT_TREE,
    OBJECT_COUNT
} object_id_t;

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

typedef enum skin_id_e {
    SKIN_BOY = 0,
    SKIN_GIRL,
    SKIN_COUNT
} skin_id_t;

typedef enum state_id_e {
    STATE_IDLE = 0,
    STATE_WALKING,
    STATE_RUNNING,
    STATE_ATTACKING,
    STATE_COUNT
} state_id_t;

typedef enum dir_id_e {
    DIR_DOWN = 0,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_COUNT
} dir_id_t;

#endif
