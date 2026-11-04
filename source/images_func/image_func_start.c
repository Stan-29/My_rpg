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
#include "engine/engine.h"
#include "scene/scene.h"


#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/RenderWindow.h>

unsigned int image_func_start_game(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_set_scene(scene_manager, SCENE_GAME);
    return OK;
}

unsigned int image_func_go_to_settings(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_set_scene(scene_manager, SCENE_SETTINGS);
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

unsigned int image_func_exit_game(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene_manager;
    scene_play_sound(scene, SOUND_CLICK);
    sfRenderWindow_close(engine_get_window(engine));
    return OK;
}

unsigned int image_func_exit_settings(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_exit_sub(scene_manager);
    return OK;
}
