/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef TEXT_INTERNAL_H_
    #define TEXT_INTERNAL_H_

    #include <SFML/Graphics/Types.h>

struct text_s {
    unsigned int id;
    sfFont *font;
    sfText *text;
};

#endif
