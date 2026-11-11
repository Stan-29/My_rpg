/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_scene_get
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/Sprite.h>

Test(scene_get_view, basic_get_view)
{
    scene_t *scene = scene_create(SCENE_MENU);

    cr_assert(scene_get_view(scene) == scene->view);
    scene_destroy(scene);
}

Test(scene_get_view, get_view_on_null)
{
    scene_t *scene = NULL;

    cr_assert(scene_get_view(scene) == NULL);
}


Test(scene_find_image_by_pos, basic_find_by_pos)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = scene_find_image_by_pos(scene, &(sfVector2f){760, 410});
    sfFloatRect image_bounds = {0};

    image_bounds = sfSprite_getGlobalBounds(image->sprite);
    cr_assert(sfFloatRect_contains(&image_bounds, 760, 410) == true);
    scene_destroy(scene);
}

Test(scene_find_image_by_pos, find_by_pos_no_image)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = scene_find_image_by_pos(scene, &(sfVector2f){-1, -1});
    
    cr_assert(image == NULL);
    scene_destroy(scene);
}


Test(scene_get_held, basic_get_held)
{
    scene_t *scene = scene_create(SCENE_MENU);
    image_t *image = image_create(&images_menu_tab[0], 0);

    scene->held = image;
    cr_assert(scene_get_held(scene) == scene->held);
    image_destroy(image);
    scene_destroy(scene);
}

Test(scene_get_held, get_held_on_null)
{
    scene_t *scene = NULL;

    cr_assert(scene_get_held(scene) == NULL);
}


Test(scene_get_texts, basic_get_held)
{
    scene_t *scene = scene_create(SCENE_MENU);
    linked_list_t *list = scene_get_texts(scene);

    cr_assert(list != NULL);
    scene_destroy(scene);
}

Test(scene_get_texts, get_held_on_null)
{
    scene_t *scene = NULL;
    linked_list_t *list = scene_get_texts(scene);

    cr_assert(list == NULL);
}
