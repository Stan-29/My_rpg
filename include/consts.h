/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef CONSTS_H_
    #define CONSTS_H_

    #include "types.h"

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct images_tab_s {
    const char *filepath;
    sfIntRect sprite_sheet;
    sfVector2f pos;
    sfVector2f scale;
    sfFloatRect movable_zone;
    unsigned int (* func)(scene_manager_t *, scene_t *, engine_t *);
} images_tab_t;

extern const images_tab_t images_menu_tab[];
extern const images_tab_t images_save_tab[];
extern const images_tab_t images_settings_tab[];
extern const images_tab_t images_game_tab[];
extern const images_tab_t images_pause_tab[];


typedef struct texts_tab_s {
    const char *filepath;
    const char *str;
    int size;
    sfColor *color;
    sfVector2f pos;
} texts_tab_t;

extern const texts_tab_t texts_menu_tab[];
extern const texts_tab_t texts_save_tab[];
extern const texts_tab_t texts_settings_tab[];
extern const texts_tab_t texts_game_tab[];
extern const texts_tab_t texts_pause_tab[];


typedef struct musics_tab_s {
    unsigned int id;
    const char *filepath;
    float volume;
} musics_tab_t;

extern const musics_tab_t musics_menu_tab[];
extern const musics_tab_t musics_save_tab[];
extern const musics_tab_t musics_settings_tab[];
extern const musics_tab_t musics_game_tab[];
extern const musics_tab_t musics_pause_tab[];


typedef struct sounds_tab_s {
    unsigned int id_sound;
    const char *filepath;
    float base_volume;
} sounds_tab_t;

extern const sounds_tab_t sounds_menu_tab[];
extern const sounds_tab_t sounds_save_tab[];
extern const sounds_tab_t sounds_settings_tab[];
extern const sounds_tab_t sounds_game_tab[];
extern const sounds_tab_t sounds_pause_tab[];

typedef struct scenes_tab_s {
    unsigned int id_scene;
    bool is_main;
    const images_tab_t *images;
    const texts_tab_t *texts;
    const musics_tab_t *musics;
    const sounds_tab_t *sounds;
} scenes_tab_t;

extern const scenes_tab_t scenes_tab[];

extern const char *saves_path_tab[];

#endif
