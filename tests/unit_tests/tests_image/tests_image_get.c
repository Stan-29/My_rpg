/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_image_get
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>

#include "consts.h"
#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

Test(image_get_sprite, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    cr_assert(image_get_sprite(temp) == temp->sprite);
    image_destroy(temp);
}

Test(image_get_sprite, image_null)
{
    cr_assert(image_get_sprite(NULL) == NULL);
}


Test(image_get_scale, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f scale = image_get_scale(temp);

    cr_assert(scale.x == temp->base_scale.x);
    cr_assert(scale.y == temp->base_scale.y);
    image_destroy(temp);
}

Test(image_get_scale, image_null)
{
    sfVector2f scale = image_get_scale(NULL);

    cr_assert(scale.x == 0);
    cr_assert(scale.y == 0);
}


Test(image_get_pos, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f pos = image_get_pos(temp);

    cr_assert(pos.x == temp->base_pos.x);
    cr_assert(pos.y == temp->base_pos.y);
    image_destroy(temp);
}

Test(image_get_pos, image_null)
{
    sfVector2f pos = image_get_pos(NULL);

    cr_assert(pos.x == 0);
    cr_assert(pos.y == 0);
}


Test(image_get_movable_zone, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfFloatRect rect = image_get_movable_zone(temp);

    cr_assert(rect.top == temp->movable_zone.top);
    cr_assert(rect.width == temp->movable_zone.width);
    cr_assert(rect.height == temp->movable_zone.height);
    cr_assert(rect.left == temp->movable_zone.left);
    image_destroy(temp);
}

Test(image_get_movable_zone, image_null)
{
    sfFloatRect rect = image_get_movable_zone(NULL);

    cr_assert(rect.top == 0);
    cr_assert(rect.width == 0);
    cr_assert(rect.height == 0);
    cr_assert(rect.left == 0);
}