/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_drag
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

Test(scene_grab, basic_grab)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = image_create(&images_menu_tab[0], 0);

    scene_grab(scene, image, &(sfVector2f){0, 0});
    cr_assert(scene->held == image);
    image_destroy(image);
    scene_destroy(scene);
}

Test(scene_grab, grab_on_null)
{
    scene_t *scene = NULL;
    image_t *image = NULL;

    scene_grab(scene, image, &(sfVector2f){0, 0});
    cr_assert(scene == NULL);
}

Test(scene_release, basic_release)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = image_create(&images_menu_tab[0], 0);

    scene->held = image;
    scene_release(scene);
    cr_assert(scene->held == NULL);
    image_destroy(image);
    scene_destroy(scene);
}

Test(scene_release, release_on_null)
{
    scene_t *scene = NULL;
    image_t *image = NULL;

    scene_release(scene);
    cr_assert(scene == NULL);
}

Test(scene_handle_drag, basic_drag)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = image_create(&images_menu_tab[0], 0);

    scene->held = image;
    scene->offset.x = 0;
    scene->offset.y = 0;
    scene_handle_drag(scene, NULL);
    cr_assert(scene->held->base_pos.x == 0);
    cr_assert(scene->held->base_pos.y == 0);
    image_destroy(image);
    scene_destroy(scene);
}

Test(scene_handle_drag, scene_on_null)
{
    scene_t *scene = NULL;
    image_t *image = image_create(&images_menu_tab[0], 0);
    sfVector2f old_pos = image->base_pos;

    scene_handle_drag(scene,  NULL);
    cr_assert(image->base_pos.x == old_pos.x);
    cr_assert(image->base_pos.y == old_pos.y);
    cr_assert(scene == NULL);
    image_destroy(image);
}

Test(scene_handle_drag, scene_held_on_null)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = image_create(&images_menu_tab[0], 0);
    sfVector2f old_pos = image->base_pos;

    scene->held = image;
    scene_handle_drag(scene,  NULL);
    cr_assert(image->base_pos.x == old_pos.x);
    cr_assert(image->base_pos.y == old_pos.y);
    image_destroy(image);
    scene_destroy(scene);
}
