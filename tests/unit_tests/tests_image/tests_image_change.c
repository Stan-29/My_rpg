/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_image_get
*/
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>

#include "consts.h"
#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

Test(image_change_scale, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f new_scale = {0};

    image_change_scale(temp, &(sfVector2f){2, 2});
    new_scale = sfSprite_getScale(temp->sprite);
    cr_assert(new_scale.x == 2);
    cr_assert(new_scale.y == 2);
    image_destroy(temp);
}

Test(image_change_scale, image_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f new_scale = {0};

    image_change_scale(NULL, &(sfVector2f){2, 2});
    new_scale = sfSprite_getScale(temp->sprite);
    cr_assert(new_scale.x == (const float)2.8);
    cr_assert(new_scale.y == (const float)2.8);
    image_destroy(temp);
}



Test(image_change_pos, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f new_pos = {0};

    image_change_pos(temp, &(sfVector2f){2, 2});
    new_pos = sfSprite_getPosition(temp->sprite);
    cr_assert(new_pos.x == 2);
    cr_assert(new_pos.y == 2);
    image_destroy(temp);
}

Test(image_change_pos, image_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfVector2f new_pos = {0};

    image_change_pos(NULL, &(sfVector2f){2, 2});
    new_pos = sfSprite_getPosition(temp->sprite);
    cr_assert(new_pos.x == 0);
    cr_assert(new_pos.y == 0);
    image_destroy(temp);
}


Test(image_change_base_pos, basic_image_not_movable)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    image_change_base_pos(temp, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 0);
    image_destroy(temp);
}

Test(image_change_base_pos, basic_image_x_movable)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.width = 100;
    temp->movable_zone.left = 0;
    image_change_base_pos(temp, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 2);
    cr_assert(temp->base_pos.y == 0);
    image_destroy(temp);
}

Test(image_change_base_pos, basic_image_x_movable_edge_case_left)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.width = 100;
    temp->movable_zone.left = 5;
    image_change_base_pos(temp, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 5);
    cr_assert(temp->base_pos.y == 0);
    image_destroy(temp);
}

Test(image_change_base_pos, basic_image_x_movable_edge_case_right)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.width = 100;
    temp->movable_zone.left = 0;
    image_change_base_pos(temp, &(sfVector2f){102, 2});
    cr_assert(temp->base_pos.x == 100);
    cr_assert(temp->base_pos.y == 0);
    image_destroy(temp);
}


Test(image_change_base_pos, basic_image_y_movable)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.height = 100;
    temp->movable_zone.top = 0;
    image_change_base_pos(temp, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 2);
    image_destroy(temp);
}

Test(image_change_base_pos, basic_image_y_movable_edge_case_top)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.height = 100;
    temp->movable_zone.top = 5;
    image_change_base_pos(temp, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 5);
    image_destroy(temp);
}

Test(image_change_base_pos, basic_image_y_movable_edge_case_bot)
{
    image_t *temp = image_create(&images_settings_tab[0], 0);

    temp->movable_zone.height = 100;
    temp->movable_zone.top = 0;
    image_change_base_pos(temp, &(sfVector2f){2, 102});
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 100);
    image_destroy(temp);
}

Test(image_change_base_pos, image_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    image_change_base_pos(NULL, &(sfVector2f){2, 2});
    cr_assert(temp->base_pos.x == 0);
    cr_assert(temp->base_pos.y == 0);
    image_destroy(temp);
}

Test(image_change_color, basic_image)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfColor new_color = {0};

    image_change_color(temp, &(sfColor){0, 0, 0, 100});
    new_color = sfSprite_getColor(temp->sprite);
    cr_assert(new_color.r == 0);
    cr_assert(new_color.g == 0);
    cr_assert(new_color.b == 0);
    cr_assert(new_color.a == 100);
    image_destroy(temp);
}

Test(image_change_color, image_null)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);
    sfColor new_color = {0};

    image_change_color(NULL, &(sfColor){0, 0, 0, 100});
    new_color = sfSprite_getColor(temp->sprite);
    cr_assert(new_color.r == 255);
    cr_assert(new_color.g == 255);
    cr_assert(new_color.b == 255);
    cr_assert(new_color.a == 255);
    image_destroy(temp);
}