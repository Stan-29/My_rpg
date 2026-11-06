/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "text/text.h"
#include "text/text_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/Text.h>

static bool check_following_chars(const char *actual_str,
    unsigned int index, char *str)
{
    for (unsigned int index_str = 0; str[index_str] != '\0'; index_str++) {
        if (actual_str[index] != str[index_str])
            return false;
        index += 1;
    }
    return true;
}

bool text_contains(text_t *text, char *str)
{
    const char *actual_str = sfText_getString(text->text);

    for (unsigned int index = 0; actual_str[index] != '\0'; index++) {
        if (actual_str[index] == str[0] &&
            check_following_chars(actual_str, index, str) == true)
            return true;
    }
    return false;
}
