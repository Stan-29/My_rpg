/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_manager_get
*/
#include <criterion/criterion.h>

#include "enums.h"
#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "scene/scene_internal.h" // IWYU pragma: keep

Test(scene_manager_get_current, basic_get_current)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_get_current, get_current_with_subscene)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    cr_assert(scene_manager_get_current(scene_manager)->id == SCENE_GAME);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_get_current, get_current_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_get_current(NULL) == NULL);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_get_main_id, basic_get_main)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_get_main_id(scene_manager) == SCENE_MENU);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_get_main_id, get_main_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_get_main_id(NULL) == SCENE_NONE);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_get_sub_id, basic_get_sub)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_set_scene(scene_manager, SCENE_SETTINGS);
    cr_assert(scene_manager_get_sub_id(scene_manager) == SCENE_SETTINGS);
    scene_manager_destroy(scene_manager);
}

Test(scene_manager_get_sub_id, get_sub_on_null)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_get_sub_id(NULL) == SCENE_NONE);
    scene_manager_destroy(scene_manager);
}
