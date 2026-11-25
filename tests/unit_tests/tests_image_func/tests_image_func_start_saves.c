/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_image_func_start_saves
*/
#include <criterion/criterion.h>

#include "defines.h"
#include "enums.h"

#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"

#include "image_func/image_func.h"

Test(image_func_go_to_save, basic_change_in_scene)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_NONE;
    image_func_go_to_save(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_SAVE);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_go_to_save, null_params)
{
    cr_assert(image_func_go_to_save(NULL, NULL, NULL) == ERROR);
}

Test(image_func_start_save1, basic_change_in_scene)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save1(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save1, null_params)
{
    cr_assert(image_func_start_save1(NULL, NULL, NULL) == ERROR);
}

Test(image_func_start_save2, basic_change_in_scene)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save2(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save2, null_params)
{
    cr_assert(image_func_start_save2(NULL, NULL, NULL) == ERROR);
}

Test(image_func_start_save3, basic_change_in_scene)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = scene_manager_get_current(scene_manager);

    scene_manager->sub_scene = SCENE_SAVE;
    image_func_start_save3(scene_manager, scene, engine);
    cr_assert(scene_manager->sub_scene == SCENE_NONE);
    cr_assert(scene_manager->main_scene == SCENE_GAME);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(image_func_start_save3, null_params)
{
    cr_assert(image_func_start_save3(NULL, NULL, NULL) == ERROR);
}
