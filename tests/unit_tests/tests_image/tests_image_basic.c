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
    cr_assert(temp->base_scale.x == (const float)2.8);
    cr_assert(temp->base_scale.y == (const float)2.8);
    cr_assert(temp->func == NULL);
    cr_assert(temp->texture != NULL);
    cr_assert(temp->sprite != NULL);
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