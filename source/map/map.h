/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map module
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct map_s map_t;

map_t *map_create(void);
void *map_destroy(map_t *map);

void map_draw_floor(map_t *map, sfRenderWindow *window);
void map_draw_objects(map_t *map, sfRenderWindow *window,
    float feet_y, bool front);

void map_update_view(map_t *map, const sfVector2f *pos, sfVector2f *dir,
    float dt);
void map_set_center(map_t *map, const sfVector2f *pos);

bool map_collides(const sfVector2f *feet);

#endif
