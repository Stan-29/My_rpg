/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** event_func header
*/

#ifndef EVENT_FUNC_H_
    #define EVENT_FUNC_H_

    #include "types.h"

unsigned int event_func_move_up(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);
unsigned int event_func_move_down(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);
unsigned int event_func_move_left(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);
unsigned int event_func_move_right(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);
unsigned int event_func_run(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine);

#endif
