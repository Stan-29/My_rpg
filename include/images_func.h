/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef IMAGES_FUNC_H_
    #define IMAGES_FUNC_H_

    #include "types.h"

unsigned int place_holder_func(scene_manager_t *,
    scene_t *, engine_t *);

unsigned int image_func_back_to_menu(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_exit_game(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_go_to_settings(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_exit_sub_scene(scene_manager_t *,
    scene_t *, engine_t *);


unsigned int image_func_go_to_save(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_start_save1(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_start_save2(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_start_save3(scene_manager_t *,
    scene_t *, engine_t *);

unsigned int image_func_windowed(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_full_screen(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_music_volume(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_sound_volume(scene_manager_t *,
    scene_t *, engine_t *);

#endif
