/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"
#include "enums.h"

#include "scene/scene.h"

unsigned int place_holder_func(scene_manager_t *scene_manager, scene_t *scene)
{
    scene_play_sound(scene, SOUND_CLICK);
    (void)scene_manager;
    return OK;
}
