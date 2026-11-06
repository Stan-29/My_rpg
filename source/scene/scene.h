/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include "types.h"

    #include "linked_list/linked_list.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

scene_t *scene_create(unsigned int id);
void scene_draw(scene_t *scene, sfRenderWindow *window);
void *scene_destroy(scene_t *scene);

void scene_start(scene_t *scene);
void scene_stop(scene_t *scene);

void scene_handle_hover(scene_t *scene, sfRenderWindow *window);
void scene_play_sound(scene_t *scene, unsigned int sound_id);
void scene_change_music_volume(scene_t *scene, float ratio);
void scene_change_sound_volume(scene_t *scene, float ratio);

void scene_grab(scene_t *scene, image_t *image, sfVector2f *mouse_pos);
void scene_release(scene_t *scene);
void scene_handle_drag(scene_t *scene, sfRenderWindow *window);

sfView *scene_get_view(scene_t *scene);
image_t *scene_get_held(scene_t *scene);
image_t *scene_find_image_by_pos(scene_t *scene, sfVector2f *pos);
linked_list_t *scene_get_texts(scene_t *scene);

#endif
