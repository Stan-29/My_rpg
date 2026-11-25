/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_image_get
*/
#include <criterion/criterion.h>

#include "consts.h"

#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>

Test(image_get_sprite, basic_image)
{
    image_t *temp = image_create(&image_menu_tab[0], 0);

    cr_assert(image_get_sprite(temp) == temp->sprite);
    image_destroy(temp);
}

Test(image_get_sprite, image_null)
{
    cr_assert(image_get_sprite(NULL) == NULL);
}

Test(image_get_scale, basic_image)
{
    image_t *temp = image_create(&image_menu_tab[0], 0);
    sfVector2f scale = image_get_scale(temp);

    cr_assert_float_eq(scale.x, temp->base_scale.x, 0.01);
    cr_assert_float_eq(scale.y, temp->base_scale.y, 0.01);
    image_destroy(temp);
}

Test(image_get_scale, image_null)
{
    sfVector2f scale = image_get_scale(NULL);

    cr_assert_float_eq(scale.x, 0, 0.01);
    cr_assert_float_eq(scale.y, 0, 0.01);
}

Test(image_get_pos, basic_image)
{
    image_t *temp = image_create(&image_menu_tab[0], 0);
    sfVector2f pos = image_get_pos(temp);

    cr_assert_float_eq(pos.x, temp->base_pos.x, 0.01);
    cr_assert_float_eq(pos.y, temp->base_pos.y, 0.01);
    image_destroy(temp);
}

Test(image_get_pos, image_null)
{
    sfVector2f pos = image_get_pos(NULL);

    cr_assert_float_eq(pos.x, 0, 0.01);
    cr_assert_float_eq(pos.y, 0, 0.01);
}

Test(image_get_movable_zone, basic_image)
{
    image_t *temp = image_create(&image_menu_tab[0], 0);
    sfFloatRect rect = image_get_movable_zone(temp);

    cr_assert_float_eq(rect.top, temp->movable_zone.top, 0.01);
    cr_assert_float_eq(rect.width, temp->movable_zone.width, 0.01);
    cr_assert_float_eq(rect.height, temp->movable_zone.height, 0.01);
    cr_assert_float_eq(rect.left, temp->movable_zone.left, 0.01);
    image_destroy(temp);
}

Test(image_get_movable_zone, image_null)
{
    sfFloatRect rect = image_get_movable_zone(NULL);

    cr_assert_float_eq(rect.top, 0, 0.01);
    cr_assert_float_eq(rect.width, 0, 0.01);
    cr_assert_float_eq(rect.height, 0, 0.01);
    cr_assert_float_eq(rect.left, 0, 0.01);
}
