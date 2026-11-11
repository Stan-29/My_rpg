/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_images_func_pause
*/
#include <criterion/criterion.h>

#include "enums.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "engine/engine.h"

#include "images_func.h"

Test(image_func_go_to_pause, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_NONE;
    image_func_go_to_pause(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_PAUSE);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_back_to_menu, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene_manager->sub_scene = SCENE_SETTINGS;
    image_func_back_to_menu(scene_manager, scene, engine);
    cr_assert(scene_manager->main_scene == SCENE_MENU);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}
