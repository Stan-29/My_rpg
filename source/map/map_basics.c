/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_basics
*/
#include "consts.h"
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/View.h>

static map_t *map_create_textures(map_t *map)
{
    for (unsigned int index = 0; index < FLOOR_COUNT; index++) {
        map->floor_textures[index] =
            sfTexture_createFromFile(floor_tab[index].filepath, NULL);
        if (!map->floor_textures[index])
            return map_destroy(map);
    }
    for (unsigned int index = 0; index < OBJECT_COUNT; index++) {
        if (!object_tab[index].filepath)
            continue;
        map->object_textures[index] =
            sfTexture_createFromFile(object_tab[index].filepath, NULL);
        if (!map->object_textures[index])
            return map_destroy(map);
    }
    map->sprite = sfSprite_create();
    if (!map->sprite)
        return map_destroy(map);
    return map;
}

static sfVector2f get_screen_pos_from_tab(map_t *map, int col, int row)
{
    sfVector2f pos = {0};

    pos.x = (col - row) * (TILE_W / 2.0f) + map->offset.x;
    pos.y = (col + row) * (TILE_H / 2.0f) + map->offset.y;
    return pos;
}

map_t *map_create(void)
{
    map_t *map = garbage_collector_malloc(sizeof(map_t));
    sfVector2f center = {0};

    if (!map)
        return map_destroy(map);
    map->sprite = NULL;
    map->offset = (sfVector2f){(float)FULL_SCREEN_WIDTH / 2, 100};
    center = get_screen_pos_from_tab(map, MAP_COLS / 2, MAP_ROWS / 2);
    map->camera = sfView_createFromRect((sfFloatRect){0, 0,
            FULL_SCREEN_WIDTH, FULL_SCREEN_HEIGHT});
    center.y += TILE_H / 2.0f;
    sfView_setCenter(map->camera, center);
    for (unsigned int index = 0; index < FLOOR_COUNT; index++)
        map->floor_textures[index] = NULL;
    for (unsigned int index = 0; index < OBJECT_COUNT; index++)
        map->object_textures[index] = NULL;
    return map_create_textures(map);
}

void *map_destroy(map_t *map)
{
    if (!map)
        return NULL;
    if (map->sprite)
        sfSprite_destroy(map->sprite);
    if (map->camera)
        sfView_destroy(map->camera);
    for (unsigned int index = 0; index < FLOOR_COUNT; index++)
        if (map->floor_textures[index])
            sfTexture_destroy(map->floor_textures[index]);
    for (unsigned int index = 0; index < OBJECT_COUNT; index++)
        if (map->object_textures[index])
            sfTexture_destroy(map->object_textures[index]);
    garbage_collector_free(map);
    return NULL;
}

static void map_draw_floor_tile(map_t *map, sfRenderWindow *window,
    int row, int col)
{
    sfTexture *texture = map->floor_textures[map_floor[row][col]];
    sfVector2u size = sfTexture_getSize(texture);
    float scale = (float)TILE_W / size.x;

    sfSprite_setTexture(map->sprite, texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f){scale, scale});
    sfSprite_setOrigin(map->sprite, (sfVector2f){size.x / 2.0f, 0});
    sfSprite_setPosition(map->sprite, get_screen_pos_from_tab(map, col, row));
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
}

static void map_draw_object(map_t *map, sfRenderWindow *window,
    int row, int col)
{
    int id = map_objects[row][col];
    sfTexture *texture = NULL;
    sfVector2u size = {0};
    sfVector2f pos = {0};
    float scale = 0;

    if (id == OBJECT_NONE)
        return;
    texture = map->object_textures[id];
    size = sfTexture_getSize(texture);
    scale = (float)TILE_W / size.x;
    pos = get_screen_pos_from_tab(map, col, row);
    pos.y += (float)TILE_H / 1.5;
    sfSprite_setTexture(map->sprite, texture, sfTrue);
    sfSprite_setScale(map->sprite, (sfVector2f){scale, scale});
    sfSprite_setOrigin(map->sprite, (sfVector2f){size.x / 2.0f, size.y});
    sfSprite_setPosition(map->sprite, pos);
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
}

void map_draw(map_t *map, sfRenderWindow *window)
{
    if (map == NULL || window == NULL)
        return;
    sfRenderWindow_setView(window, map->camera);
    for (int row = 0; row < MAP_ROWS; row++)
        for (int col = 0; col < MAP_COLS; col++)
            map_draw_floor_tile(map, window, row, col);
    for (int row = 0; row < MAP_ROWS; row++)
        for (int col = 0; col < MAP_COLS; col++)
            map_draw_object(map, window, row, col);
}

void map_update_view(map_t *map, sfVector2f *dir, float dt)
{
    if (!map)
        return;
    sfView_move(map->camera, (sfVector2f){dir->x * CAMERA_SPEED * dt,
            dir->y * CAMERA_SPEED * dt});
}
