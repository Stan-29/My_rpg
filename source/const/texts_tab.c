/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** text_tab
*/
#include "consts.h"
#include "enums.h"

#include <SFML/Graphics/Color.h>

#include <stddef.h>

const text_tab_t texts_scenes_tab[] = {
    {SCENE_MENU, "ressource/fonts/vel/vel.ttf",
        "--ANANAS--", 100, &sfBlack, {775, 250}},
    {SCENE_NONE, NULL, NULL, 0, NULL, {0, 0}}
};
