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

#include <stdio.h>
#include <stdlib.h>

static unsigned int fill_row(int map_tab[MAP_FLOORS_SIZE][MAP_FLOORS_SIZE],
    unsigned int row, char *line, unsigned int map_size)
{
    char *ptr = line;
    char *end = NULL;
    int nb = 0;
    unsigned int col = 0;

    nb = strtol(ptr, &end, 10);
    while (end != ptr) {
        ptr = end;
        if (nb < 0)
            return ERROR;
        map_tab[row][col] = nb;
        col += 1;
        nb = strtol(ptr, &end, 10);
    }
    if (col != map_size)
        return ERROR;
    return OK;
}

static unsigned int return_func(char *line, FILE *file,
    unsigned int return_value)
{
    free(line);
    fclose(file);
    return return_value;
}

static unsigned int fill_map_with_path(int map_tab[MAP_FLOORS_SIZE]
    [MAP_FLOORS_SIZE], char *filepath, unsigned int map_size)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t size = 0;
    ssize_t len = 0;
    unsigned int row = 0;

    if (!file)
        return ERROR;
    len = getline(&line, &size, file);
    while (len != -1) {
        if (fill_row(map_tab, row, line, map_size) == ERROR)
            return return_func(line, file, ERROR);
        row += 1;
        len = getline(&line, &size, file);
    }
    if (row != map_size)
        return return_func(line, file, ERROR);
    return return_func(line, file, OK);
}

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
    if (fill_map_with_path(map->map_floors, MAP_FLOORS_PATH, MAP_FLOORS_SIZE)
        == ERROR || fill_map_with_path(map->map_objects, MAP_OBJECTS_PATH,
            MAP_FLOORS_SIZE) == ERROR)
        return map_destroy(map);
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
