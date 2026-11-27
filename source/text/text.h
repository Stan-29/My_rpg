/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** text header
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct text_s text_t;

typedef struct text_tab_s {
    const char *filepath;
    const char *str;
    int size;
    sfColor *color;
    sfVector2f pos;
} text_tab_t;

text_t *text_create(const text_tab_t *text_infos, unsigned int id);
void *text_destroy(void *data);
void text_draw(text_t *text, sfRenderWindow *window);
unsigned int text_get_id(text_t *text);
bool text_contains(text_t *text, char *str);
void text_change_str(text_t *text, char *new_str);

#endif
