/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** game infos header
*/

#ifndef ENGINE_H_
    #define ENGINE_H_

    #include "scene/scene.h"

typedef struct engine_s engine_t;

engine_t *engine_create(void);
void engine_run(engine_t *engine, scene_t *scene);
void engine_destroy(engine_t *engine);

#endif
