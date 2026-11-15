/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map module
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics/Types.h>

typedef struct map_s map_t;

map_t *map_create(void);
void *map_destroy(map_t *map);
void map_draw(map_t *map, sfRenderWindow *window);

#endif
