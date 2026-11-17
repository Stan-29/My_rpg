/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_scene_basics
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

Test(scene_create, basic_create)
{
    scene_t *scene = scene_create(SCENE_MENU);

    cr_assert(scene->id == SCENE_MENU);
    cr_assert(scene->held == NULL);
    cr_assert(scene->lists->ll_images != NULL);
    cr_assert(scene->lists->ll_sounds != NULL);
    cr_assert(scene->lists->ll_texts != NULL);
    cr_assert(scene->lists->ll_musics != NULL);
    cr_assert_float_eq(scene->offset.x, 0, 0.01);
    cr_assert_float_eq(scene->offset.y, 0, 0.01);
    cr_assert(scene->view != NULL);
    scene_destroy(scene);
}

Test(scene_destroy, basic_destroy)
{
    scene_t *scene = scene_create(SCENE_MENU);

    cr_assert(scene_destroy(scene) == NULL);
}
