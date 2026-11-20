/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map header
*/

#ifndef MAP_INTERNAL_H_
    #define MAP_INTERNAL_H_

    #include "enums.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

struct map_s {
    sfTexture *floor_textures[FLOOR_COUNT];
    sfTexture *object_textures[OBJECT_COUNT];
    sfSprite *sprite;
    sfView *camera;
    sfVector2f dir;
};

#endif
