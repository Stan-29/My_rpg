/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include "consts.h"

    #include "garbage_collector/garbage_collector.h"

    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/RenderWindow.h>

typedef struct text_s text_t;

text_t *text_create(const text_tab_t *text_infos, unsigned int id);
void *text_destroy(text_t *text);
void text_draw(text_t *text, sfRenderWindow *window);
unsigned int text_get_id(text_t *text);

#endif
