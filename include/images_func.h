/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef IMAGES_FUNC_H_
    #define IMAGES_FUNC_H_

    #include "types.h"

unsigned int image_func_start_game(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int place_holder_func(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_back_to_menu(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_exit_game(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_go_to_settings(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_exit_settings(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_windowed(scene_manager_t *,
    scene_t *, engine_t *);
unsigned int image_func_full_screen(scene_manager_t *,
    scene_t *, engine_t *);

#endif
