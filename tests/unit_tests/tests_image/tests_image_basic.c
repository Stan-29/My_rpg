/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_image_create
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>

#include "consts.h"
#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

Test(image_create, basic_create)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    cr_assert(temp != NULL);
    cr_assert(temp->id == 0);
    cr_assert(temp->movable_zone.height == 0);
    cr_assert(temp->movable_zone.height == 0);
    cr_assert(temp->movable_zone.left == 0);
    cr_assert(temp->movable_zone.top == 0);
    cr_assert(temp->movable_zone.width == 0);
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 0);
    cr_assert(temp->base_scale.x == images_menu_tab[0].scale.x);
    cr_assert(temp->base_scale.y == images_menu_tab[0].scale.y);
    cr_assert(temp->func == NULL);
    cr_assert(temp->texture != NULL);
    cr_assert(temp->sprite != NULL);
    image_destroy(temp);
}

Test(image_create, create_with_null_path)
{
    image_t *temp = image_create(&images_game_tab[1], 1);

    cr_assert(temp == NULL);
    image_destroy(temp);
}


Test(image_destroy, destroy_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    cr_assert(temp != NULL);
    image_destroy(NULL);
    image_destroy(temp);
}


Test(image_draw, basic_draw)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    image_draw(temp, NULL);
    cr_assert(temp != NULL);
    image_destroy(temp);
}


Test(image_start_func, start_func_on_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    cr_assert(image_start_func(NULL, NULL, NULL, NULL) == ERROR);
    image_destroy(temp);
}

Test(image_start_func, basic_start_func)
{
    image_t *temp = image_create(&images_pause_tab[2], 2);

    cr_assert(image_start_func(temp, NULL, NULL, NULL) == ERROR);
    image_destroy(temp);
}


Test(image_create, create_with_wrong_path)
{
    images_tab_t infos = {"nope.png", {0, 0, 0, 0}, {0, 0}, {1, 1},
        {0, 0, 0, 0}, NULL};
    image_t *temp = image_create(&infos, 0);

    cr_assert(temp == NULL);
}

Test(image_draw, draw_null_image)
{
    image_draw(NULL, NULL);
    cr_assert(true);
}

Test(image_start_func, start_func_with_func)
{
    image_t *temp = image_create(&images_menu_tab[1], 1);

    cr_assert(image_start_func(temp, NULL, NULL, NULL) == ERROR);
    image_destroy(temp);
}
