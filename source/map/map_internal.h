/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map internal header
*/

#ifndef MAP_INTERNAL_H_
    #define MAP_INTERNAL_H_

    #include "enums.h"
    #include "defines.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

struct map_s {
    sfTexture *floor_textures[FLOOR_COUNT];
    sfTexture *object_textures[OBJECT_COUNT];
    int map_floors[MAP_FLOORS_SIZE][MAP_FLOORS_SIZE];
    int map_objects[MAP_FLOORS_SIZE][MAP_FLOORS_SIZE];
    sfSprite *sprite;
    sfView *camera;
};

#endif
