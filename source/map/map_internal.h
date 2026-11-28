/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map internal header
*/

#ifndef MAP_INTERNAL_H_
    #define MAP_INTERNAL_H_

    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>

    #include <stdbool.h>

    #define CAMERA_LOOKAHEAD 300
    #define CAMERA_SMOOTH 2

    #define MAP_SIZE 50

typedef enum map_id_e {
    MAP_NONE = 0,
    MAP_BEACH,
    MAP_VILLAGE,
    MAP_FOREST,
    MAP_COUNT
} map_id_t;

typedef struct map_tab_s {
    const char *floor_filepath;
    const char *object_filepath;
} map_tab_t;

extern const map_tab_t map_tab[];

typedef enum floor_id_e {
    FLOOR_GRASS = 0,
    FLOOR_PATH,
    FLOOR_SAND,
    FLOOR_WATER,
    FLOOR_COBBLE,
    FLOOR_FOREST,
    FLOOR_FLOWERS,
    FLOOR_COUNT
} floor_id_t;

typedef struct floor_tab_s {
    const char *filepath;
} floor_tab_t;

extern const floor_tab_t floor_tab[];

typedef enum object_id_e {
    OBJECT_NONE = 0,
    OBJECT_TREE,
    OBJECT_PALM,
    OBJECT_BUSH,
    OBJECT_ROCK,
    OBJECT_FLOWERS,
    OBJECT_FENCE,
    OBJECT_HOUSE,
    OBJECT_MUSHROOM,
    OBJECT_STUMP,
    OBJECT_COUNT
} object_id_t;

typedef struct object_tab_s {
    const char *filepath;
    bool solid;
    sfFloatRect hitbox;
} object_tab_t;

extern const object_tab_t object_tab[];

typedef struct single_map_s {
    int map_floors[MAP_SIZE][MAP_SIZE];
    int map_objects[MAP_SIZE][MAP_SIZE];
} single_map_t;

struct map_s {
    sfTexture *floor_textures[FLOOR_COUNT];
    sfTexture *object_textures[OBJECT_COUNT];
    map_id_t current_map;
    single_map_t maps[MAP_COUNT];
    sfSprite *sprite;
    sfView *camera;
};

#endif
