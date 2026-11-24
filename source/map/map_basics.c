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
#include <SFML/System/Vector2.h>

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

map_t *map_create(void)
{
    map_t *map = garbage_collector_malloc(sizeof(map_t));

    if (!map)
        return map_destroy(map);
    map->sprite = NULL;
    map->camera = sfView_createFromRect((sfFloatRect){0, 0,
            FULL_SCREEN_WIDTH, FULL_SCREEN_HEIGHT});
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
