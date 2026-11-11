/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_text_basics
*/
#include <criterion/criterion.h>

#include "text/text.h"
#include "text/text_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/Text.h>

Test(text_create, basic_create)
{
    text_t *text = text_create(&texts_menu_tab[0], 1);

    cr_assert(text != NULL);
    cr_assert(text->id == 1);
    text_destroy(text);
}

Test(text_create, create_on_NULL)
{
    text_t *text = text_create(NULL, 1);

    cr_assert(text == NULL);
    text_destroy(text);
}


Test(text_destroy, basic_destroy)
{
    text_t *text = text_create(&texts_menu_tab[0], 1);

    cr_assert(text_destroy(text) == NULL);
}

Test(text_destroy, destroy_on_null)
{
    text_t *text = NULL;

    cr_assert(text_destroy(text) == NULL);
}


Test(text_get_id, basic_get_id)
{
    text_t *text = text_create(&texts_menu_tab[0], 1);

    cr_assert(text_get_id(text) == 1);
    text_destroy(text);
}

Test(text_get_id, get_id_on_null)
{
    text_t *text = NULL;

    cr_assert(text_get_id(text) == 0);
}


Test(text_change_str, basic_change_on_text)
{
    text_t *text = text_create(&texts_menu_tab[0], 1);

    text_change_str(text, "abcd");
    cr_assert(text_contains(text, "abcd\0") == true);
    text_destroy(text);
}

Test(text_change_str, change_text_on_null)
{
    text_t *text = NULL;

    text_change_str(text, "abcd");
    cr_assert(text_contains(text, "abcd\0") == false);
}
