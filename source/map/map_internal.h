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

    #define MAP_FLOORS_PATH "./ressource/maps/map_floors.data"
    #define MAP_OBJECTS_PATH "./ressource/maps/map_objects.data"
    #define MAP_FLOORS_SIZE 50

typedef enum floor_id_e {
    FLOOR_GRASS = 0,
    FLOOR_PATH,
    FLOOR_COUNT
} floor_id_t;

typedef enum object_id_e {
    OBJECT_NONE = 0,
    OBJECT_TREE,
    OBJECT_COUNT
} object_id_t;

typedef struct floor_tab_s {
    const char *filepath;
} floor_tab_t;

extern const floor_tab_t floor_tab[];

typedef struct object_tab_s {
    const char *filepath;
    bool solid;
    sfFloatRect hitbox;
} object_tab_t;

extern const object_tab_t object_tab[];

struct map_s {
    sfTexture *floor_textures[FLOOR_COUNT];
    sfTexture *object_textures[OBJECT_COUNT];
    int map_floors[MAP_FLOORS_SIZE][MAP_FLOORS_SIZE];
    int map_objects[MAP_FLOORS_SIZE][MAP_FLOORS_SIZE];
    sfSprite *sprite;
    sfView *camera;
};

#endif
