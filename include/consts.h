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

typedef struct images_tab_s {
    unsigned int id_scene;
    const char *filepath;
    sfIntRect sprite_sheet;
    sfVector2f pos;
    sfVector2f scale;
    unsigned int (* func)(scene_manager_t *, scene_t *);
} images_tab_t;

extern const images_tab_t images_scenes_tab[];


typedef struct text_tab_s {
    unsigned int id_scene;
    const char *filepath;
    const char *str;
    int size;
    sfColor *color;
    sfVector2f pos;
} text_tab_t;

extern const text_tab_t texts_scenes_tab[];

typedef struct music_tab_s {
    unsigned int id_scene;
    const char *filepath;
} music_tab_t;

extern const music_tab_t musics_scenes_tab[];

typedef struct sounds_tab_s {
    unsigned int id_scene;
    unsigned int id_sound;
    const char *filepath;
    float volume;
} sounds_tab_t;

extern const sounds_tab_t sounds_scenes_tab[];

#endif
