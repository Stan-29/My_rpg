/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_INTERNAL_H_
    #define SCENE_INTERNAL_H_

    #include "types.h"

    #include "linked_list/linked_list.h"

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

struct scene_s {
    unsigned int id;
    sfView *view;
    image_t *held;
    sfVector2f offset;
    linked_list_t *ll_images;
    linked_list_t *ll_texts;
    linked_list_t *ll_sounds;
    linked_list_t *ll_musics;
};

#endif
