/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_INTERNAL_H_
    #define SCENE_INTERNAL_H_

    #include "linked_list/linked_list.h"

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/Types.h>

struct scene_s {
    unsigned int id;
    sfView *view;
    sfMusic *music;
    linked_list_t *ll_images;
    linked_list_t *ll_texts;
};

#endif
