/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** text_tab
*/
#include "consts.h"

#include <SFML/Graphics/Color.h>

#include <stddef.h>

const texts_tab_t texts_menu_tab[] = {
    {"ressource/fonts/vel/vel.ttf",
        "--ANANAS--", 100, &sfBlack, {700, 100}},
    {NULL, NULL, 0, NULL, {0, 0}}
};

const texts_tab_t texts_settings_tab[] = {
    {"ressource/fonts/vel/vel.ttf",
        "--Settings--", 80, &sfBlack, {775, 270}},
    {NULL, NULL, 0, NULL, {0, 0}}
};

const texts_tab_t texts_game_tab[] = {
    {NULL, NULL, 0, NULL, {0, 0}}
};
