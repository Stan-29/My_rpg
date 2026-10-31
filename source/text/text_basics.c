/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "garbage_collector/garbage_collector.h"
#include "text/text.h"
#include <SFML/Graphics/Types.h>

struct text_s {
    unsigned int id;
    sfFont *font;
    sfText *text;
};

text_t *text_create(const text_tab_t *text_infos, unsigned int id)
{
    text_t *text = garbage_collector_malloc(sizeof(text_t));

    if (!text)
        return text_destroy(text);
    text->id = id;
    text->font = sfFont_createFromFile(text_infos->filepath);
    if (!text->font)
        return text_destroy(text);
    text->text = sfText_create();
    if (!text->text)
        return text_destroy(text);
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, text_infos->str);
    sfText_setCharacterSize(text->text, text_infos->size);
    sfText_setFillColor(text->text, *text_infos->color);
    sfText_setPosition(text->text, text_infos->pos);
    return text;
}

void *text_destroy(text_t *text)
{
    if (!text)
        return NULL;
    if (text->text)
        sfText_destroy(text->text);
    if (text->font)
        sfFont_destroy(text->font);
    garbage_collector_free(text);
    return NULL;
}

void text_draw(text_t *text, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, text->text, NULL);
}

unsigned int text_get_id(text_t *text)
{
    if (!text)
        return 0;
    return text->id;
}
