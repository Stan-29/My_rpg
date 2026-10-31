/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include "consts.h"

    #include "garbage_collector/garbage_collector.h"

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>

typedef struct image_s image_t;

image_t *image_create(const images_tab_t *image_infos, unsigned int id);
void *image_destroy(image_t *image);
void image_draw(image_t *image, sfRenderWindow *window);
unsigned int image_get_id(image_t *image);

#endif
