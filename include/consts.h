/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** consts header
*/

#ifndef CONSTS_H_
    #define CONSTS_H_

    #include "types.h"

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct image_tab_s {
    const char *filepath;
    sfIntRect sprite_sheet;
    sfVector2f pos;
    sfVector2f scale;
    sfFloatRect movable_zone;
    unsigned int (* func)(scene_manager_t *, scene_t *, engine_t *);
} image_tab_t;

extern const image_tab_t image_menu_tab[];
extern const image_tab_t image_save_tab[];
extern const image_tab_t image_settings_tab[];
extern const image_tab_t image_game_tab[];
extern const image_tab_t image_pause_tab[];


typedef struct text_tab_s {
    const char *filepath;
    const char *str;
    int size;
    sfColor *color;
    sfVector2f pos;
} text_tab_t;

extern const text_tab_t text_menu_tab[];
extern const text_tab_t text_save_tab[];
extern const text_tab_t text_settings_tab[];
extern const text_tab_t text_game_tab[];
extern const text_tab_t text_pause_tab[];


typedef struct music_tab_s {
    unsigned int id;
    const char *filepath;
    float volume;
} music_tab_t;

extern const music_tab_t music_menu_tab[];
extern const music_tab_t music_save_tab[];
extern const music_tab_t music_settings_tab[];
extern const music_tab_t music_game_tab[];
extern const music_tab_t music_pause_tab[];


typedef struct sound_tab_s {
    unsigned int id_sound;
    const char *filepath;
    float base_volume;
} sound_tab_t;

extern const sound_tab_t sound_menu_tab[];
extern const sound_tab_t sound_save_tab[];
extern const sound_tab_t sound_settings_tab[];
extern const sound_tab_t sound_game_tab[];
extern const sound_tab_t sound_pause_tab[];

typedef struct scene_tab_s {
    unsigned int id_scene;
    bool is_main;
    const image_tab_t *images;
    const text_tab_t *texts;
    const music_tab_t *musics;
    const sound_tab_t *sounds;
} scene_tab_t;

extern const scene_tab_t scene_tab[];

extern const char *save_path_tab[];

typedef struct floor_tab_s {
    const char *filepath;
} floor_tab_t;

extern const floor_tab_t floor_tab[];

typedef struct object_tab_s {
    const char *filepath;
    bool solid;
    sfFloatRect hitbox;
} object_tab_t;

extern const object_tab_t object_tab[];

typedef struct skin_tab_s {
    const char *filepath;
} skin_tab_t;

extern const skin_tab_t skin_tab[];

typedef struct state_tab_s {
    unsigned int first_row;
    unsigned int frame_count;
    float delay;
    float speed;
} state_tab_t;

extern const state_tab_t state_tab[];

typedef struct event_tab_s {
    int key_id;
    unsigned int (* func)(scene_manager_t *, scene_t *, engine_t *);
} event_tab_t;

extern const event_tab_t event_tab[];

#endif
