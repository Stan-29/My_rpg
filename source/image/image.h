/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** image header
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include "types.h"

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct image_s image_t;

typedef struct image_tab_s {
    const char *filepath;
    sfIntRect sprite_sheet;
    sfVector2f pos;
    sfVector2f scale;
    sfFloatRect movable_zone;
    unsigned int (* func)(scene_manager_t *, scene_t *, engine_t *);
} image_tab_t;

image_t *image_create(const image_tab_t *image_infos, unsigned int id);
void *image_destroy(void *data);
void image_draw(image_t *image, sfRenderWindow *window);

sfSprite *image_get_sprite(image_t *image);
sfVector2f image_get_scale(image_t *image);
sfVector2f image_get_pos(image_t *image);
sfFloatRect image_get_movable_zone(image_t *image);

bool image_is_clickable(image_t *image);
bool image_is_movable(image_t *image);

void image_change_scale(image_t *image, sfVector2f *scale);
void image_change_pos(image_t *image, sfVector2f *pos);
void image_change_base_pos(image_t *image, sfVector2f *pos);
void image_change_color(image_t *image, sfColor *color);
unsigned int image_start_func(image_t *image, scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);

#endif
