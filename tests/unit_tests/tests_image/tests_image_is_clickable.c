/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_image_is_clickable
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>

#include "consts.h"
#include "image/image.h"
#include "image/image_internal.h" // IWYU pragma: keep

Test(image_is_clickable, image_not_clickable)
{
    image_t *temp = image_create(&images_menu_tab[0], 0);

    cr_assert(image_is_clickable(temp) == false);
    image_destroy(temp);
}

Test(image_is_clickable, image_clickable)
{
    image_t *temp = image_create(&images_menu_tab[1], 1);

    cr_assert(image_is_clickable(temp) == true);
    image_destroy(temp);
}

Test(image_is_clickable, image_null)
{
    cr_assert(image_is_clickable(NULL) == false);
}
