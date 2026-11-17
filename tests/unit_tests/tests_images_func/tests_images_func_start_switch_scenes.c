/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_images_func_start_switch_scenes
*/
#include <criterion/criterion.h>

#include "defines.h"
#include "enums.h"

#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"

#include "images_func.h"

Test(image_func_exit_sub_scene, basic_change_in_scene)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SETTINGS;
    image_func_exit_sub_scene(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_MENU);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_exit_sub_scene, change_in_scene_from_settings_to_pause)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene_manager->sub_scene = SCENE_SETTINGS;
    image_func_exit_sub_scene(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_PAUSE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_exit_sub_scene, null_params)
{
    cr_assert(image_func_exit_sub_scene(NULL, NULL, NULL) == ERROR);
}

Test(image_func_exit_game, null_params)
{
    cr_assert(image_func_exit_game(NULL, NULL, NULL) == ERROR);
}
