/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"
#include "types.h"

#include "engine/engine.h"

unsigned int image_func_windowed(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene;
    (void)scene_manager;
    engine_change_window(engine, false);
    return OK;
}

unsigned int image_func_full_screen(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene;
    (void)scene_manager;
    engine_change_window(engine, true);
    return OK;
}

unsigned int image_func_music_volume(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene_manager;
    (void)scene;
    (void)engine;
    return OK;
}

unsigned int image_func_sound_volume(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene_manager;
    (void)scene;
    (void)engine;
    return OK;
}
