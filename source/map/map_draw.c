/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_draw
*/
#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

static sfVector2f get_screen_pos_from_tab(int col, int row)
{
    sfVector2f pos = {0};

    pos.x = TILE_TO_WORLD_X(col, row);
    pos.y = TILE_TO_WORLD_Y(col, row);
    return pos;
}

static void map_draw_floor_tile(map_t *map, sfRenderWindow *window,
    int row, int col)
{
    sfTexture *texture = map->floor_textures[map->map_floors[row][col]];
    sfVector2u size = sfTexture_getSize(texture);
    float scale = (float)TILE_W / size.x;

    sfSprite_setTexture(map->sprite, texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f){scale, scale});
    sfSprite_setOrigin(map->sprite, (sfVector2f){size.x / 2.0f, 0});
    sfSprite_setPosition(map->sprite, get_screen_pos_from_tab(col, row));
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
}

void map_draw_floor(map_t *map, sfRenderWindow *window)
{
    if (map == NULL || window == NULL)
        return;
    sfRenderWindow_setView(window, map->camera);
    for (int row = 0; row < MAP_FLOORS_SIZE; row++)
        for (int col = 0; col < MAP_FLOORS_SIZE; col++)
            map_draw_floor_tile(map, window, row, col);
}

static sfVector2f map_get_object_base(int col, int row)
{
    sfVector2f pos = get_screen_pos_from_tab(col, row);

    pos.y += TILE_H / 1.5f;
    return pos;
}

static void map_draw_object(map_t *map, sfRenderWindow *window,
    int row, int col)
{
    int id = map->map_objects[row][col];
    sfTexture *texture = NULL;
    sfVector2u size = {0};
    sfVector2f pos = map_get_object_base(col, row);
    float scale = 0;

    if (id == OBJECT_NONE)
        return;
    texture = map->object_textures[id];
    size = sfTexture_getSize(texture);
    scale = (float)TILE_W / size.x;
    sfSprite_setTexture(map->sprite, texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f){scale, scale});
    sfSprite_setOrigin(map->sprite, (sfVector2f){size.x / 2.0f, size.y});
    sfSprite_setPosition(map->sprite, pos);
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
}

void map_draw_objects(map_t *map, sfRenderWindow *window,
    float feet_y, bool front)
{
    sfVector2f base = {0};
    bool in_front = false;
    int row = 0;
    int col = 0;

    if (map == NULL || window == NULL)
        return;
    for (int i = 0; i < MAP_FLOORS_SIZE * MAP_FLOORS_SIZE; i++) {
        row = i / MAP_FLOORS_SIZE;
        col = i % MAP_FLOORS_SIZE;
        base = map_get_object_base(col, row);
        in_front = base.y >= feet_y;
        if (in_front == front)
            map_draw_object(map, window, row, col);
    }
}
