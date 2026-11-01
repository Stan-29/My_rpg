/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include "types.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

scene_t *scene_create(unsigned int id);
void scene_draw(scene_t *scene, sfRenderWindow *window);
void *scene_destroy(scene_t *scene);

void scene_start(scene_t *scene);
void scene_stop(scene_t *scene);
unsigned int scene_handle_click(scene_manager_t *scene_manager, scene_t *scene,
    sfVector2f *pos);
void scene_handle_hover(scene_t *scene, sfRenderWindow *window);
void scene_play_sound(scene_t *scene, unsigned int sound_id);

sfView *scene_get_view(scene_t *scene);

#endif
