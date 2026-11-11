/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_manager_basics
*/
#include <criterion/criterion.h>

#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep

Test(scene_manager_create, basic_create)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager != NULL);
    scene_manager_destroy(scene_manager);
}


Test(scene_manager_destroy, basic_destroy)
{
    scene_manager_t *scene_manager = scene_manager_create();

    cr_assert(scene_manager_destroy(scene_manager) == NULL);
}


Test(scene_manager_draw, basic_draw)
{
    scene_manager_t *scene_manager = scene_manager_create();

    scene_manager_draw(scene_manager, NULL);
    cr_assert(scene_manager != NULL);
}
