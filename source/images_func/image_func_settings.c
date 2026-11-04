/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "enums.h"
#include "defines.h"
#include "types.h"

#include "image/image.h"
#include "scene/scene.h"
#include "engine/engine.h"
#include "scene_manager/scene_manager.h"

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Sprite.h>

unsigned int image_func_windowed(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene_manager;
    engine_change_window(engine, false);
    scene_play_sound(scene, SOUND_CLICK);
    return OK;
}

unsigned int image_func_full_screen(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)scene_manager;
    engine_change_window(engine, true);
    scene_play_sound(scene, SOUND_CLICK);
    return OK;
}

static float get_ratio_slider(scene_t *scene)
{
    image_t *held = scene_get_held(scene);
    float ratio = (image_get_pos(held).x -
        image_get_movable_zone(held).left) /
        image_get_movable_zone(held).width;

    if (ratio < 0)
        ratio = 0;
    if (ratio > 1)
        ratio = 1;
    return ratio;
}

unsigned int image_func_music_volume(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_manager_change_music_volume(scene_manager,
        get_ratio_slider(scene));
    scene_play_sound(scene, SOUND_CLICK);
    return OK;
}

unsigned int image_func_sound_volume(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_manager_change_sound_volume(scene_manager,
        get_ratio_slider(scene));
    scene_play_sound(scene, SOUND_CLICK);
    return OK;
}
