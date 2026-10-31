/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef CONSTS_H_
    #define CONSTS_H_

    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Image.h>

typedef struct images_tab_s {
    unsigned int id_scene;
    const char *filepath;
    sfIntRect sprite_sheet;
    sfVector2f pos;
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

#endif
