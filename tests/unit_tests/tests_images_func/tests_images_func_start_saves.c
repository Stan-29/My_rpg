/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_images_func_settings
*/
#include <criterion/criterion.h>

#include "enums.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "engine/engine.h"

#include "images_func.h"

Test(image_func_go_to_save, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_NONE;
    image_func_go_to_save(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_SAVE);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save1, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save1(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save2, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save2(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save3, basic_change_in_scene)
{
    engine_t *engine = NULL;
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save3(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}