/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map header
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "engine/engine.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

    #define TILE_W 192
    #define TILE_H 96
    #define HALF_TILE_W (TILE_W / 2.0f)
    #define HALF_TILE_H (TILE_H / 2.0f)

    #define MAP_OFFSET_X (FULL_SCREEN_WIDTH / 2.0f)
    #define MAP_OFFSET_Y 100.0f

    #define TILE_TO_WORLD_X(c, r) (((c) - (r)) * HALF_TILE_W + MAP_OFFSET_X)
    #define TILE_TO_WORLD_Y(c, r) (((c) + (r)) * HALF_TILE_H + MAP_OFFSET_Y)

typedef struct map_s map_t;

map_t *map_create(void);
void *map_destroy(map_t *map);

void map_draw_floor(map_t *map, sfRenderWindow *window);
void map_draw_objects(map_t *map, sfRenderWindow *window,
    float feet_y, bool front);

void map_update_view(map_t *map, const sfVector2f *pos, sfVector2f *dir,
    float dt);
void map_set_center(map_t *map, const sfVector2f *pos);

bool map_collides(map_t *map, const sfVector2f *feet_pos);

#endif
