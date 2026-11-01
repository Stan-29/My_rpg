/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include "consts.h"

    #include <SFML/Graphics/Types.h>

typedef struct image_s image_t;

image_t *image_create(const images_tab_t *image_infos, unsigned int id);
void *image_destroy(image_t *image);
void image_draw(image_t *image, sfRenderWindow *window);

unsigned int image_get_id(image_t *image);
sfSprite *image_get_sprite(image_t *image);
sfVector2f image_get_scale(image_t *image);
sfVector2f image_get_pos(image_t *image);

void image_change_scale(image_t *image, sfVector2f *scale);
void image_change_pos(image_t *image, sfVector2f *pos);
void image_change_color(image_t *image, sfColor *color);

#endif
