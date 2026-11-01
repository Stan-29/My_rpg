/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"
#include "enums.h"
#include "types.h"

#include "scene_manager/scene_manager.h"

unsigned int image_func_start_game(scene_manager_t *scene_manager,
    scene_t *scene)
{
    (void)scene;
    scene_manager_set_scene(scene_manager, SCENE_GAME);
    return OK;
}

unsigned int image_func_back_to_menu(scene_manager_t *scene_manager,
    scene_t *scene)
{
    (void)scene;
    scene_manager_set_scene(scene_manager, SCENE_MENU);
    return OK;
}
