/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef IMAGE_INTERNAL_H_
    #define IMAGE_INTERNAL_H_

    #include "types.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

struct image_s {
    unsigned int id;
    sfVector2f base_scale;
    sfVector2f base_pos;
    sfTexture *texture;
    sfSprite *sprite;
    bool is_movable;
    unsigned int (* func)(scene_manager_t *, scene_t *, engine_t *);
};

#endif
