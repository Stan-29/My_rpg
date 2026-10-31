/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** text_tab
*/
#include "consts.h"
#include "enums.h"
#include <SFML/Graphics/Color.h>

const text_tab_t texts_scenes_tab[] = {
    {SCENE_MENU, "ressource/fonts/vel/vel.ttf",
        "--ANANAS--", 100, &sfRed, {775, 450}},
    {SCENE_MENU, "ressource/fonts/vel/vel.ttf",
        "--details--", 50, &sfRed, {775, 650}},
    {SCENE_NONE, NULL, NULL, 0, NULL, {0, 0}}
};
