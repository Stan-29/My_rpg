/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"
#include "enums.h"

#include "scene_manager/scene_manager.h"
#include "engine/engine.h"
#include "scene/scene.h"

#include <SFML/Graphics/RenderWindow.h>

unsigned int image_func_go_to_pause(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_set_scene(scene_manager, SCENE_PAUSE);
    return OK;
}

unsigned int image_func_back_to_menu(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_set_scene(scene_manager, SCENE_MENU);
    return OK;
}
