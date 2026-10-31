/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_INTERNAL_H_
    #define SCENE_INTERNAL_H_

    #include "scene.h"

    #include "linked_list/linked_list.h"

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/View.h>
    #include <SFML/Audio/Music.h>

struct scene_s {
    unsigned int id;
    sfView *view;
    sfMusic *music;
    linked_list_t *ll_images;
    linked_list_t *ll_texts;
};

#endif
