/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_MANAGER_H_
    #define SCENE_MANAGER_H_

    #include "types.h"

    #include <SFML/Graphics/Types.h>

scene_manager_t *scene_manager_create(void);
void *scene_manager_destroy(scene_manager_t *scene_manager);
void scene_manager_draw(scene_manager_t *scene_manager,
    sfRenderWindow *window);

void scene_manager_set_scene(scene_manager_t *scene_manager,
    unsigned int scene_id);
scene_t *scene_manager_get_current(scene_manager_t *scene_manager);

#endif
