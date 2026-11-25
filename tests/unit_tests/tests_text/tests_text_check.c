/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_text_check
*/
#include <criterion/criterion.h>

#include "text/text.h"
#include "text/text_internal.h" // IWYU pragma: keep

#include <stdbool.h>

Test(text_contains, basic_check)
{
    text_t *text = text_create(&text_menu_tab[0], 1);

    text_change_str(text, "abcd");
    cr_assert(text_contains(text, "abcd\0") == true);
    text_destroy(text);
}

Test(text_contains, check_on_null)
{
    text_t *text = NULL;

    text_change_str(text, "abcd");
    cr_assert(text_contains(text, "abcd\0") == false);
}

Test(text_contains, check_partial_match)
{
    text_t *text = text_create(&text_menu_tab[0], 1);

    text_change_str(text, "abcd");
    cr_assert(text_contains(text, "abd") == false);
    text_destroy(text);
}
