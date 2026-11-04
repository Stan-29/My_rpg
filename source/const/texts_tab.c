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

const texts_tab_t texts_save_tab[] = {
    {"ressource/fonts/vel/vel.ttf",
        "--Choose a save--", 80, &sfBlack, {725, 260}},
    {NULL, NULL, 0, NULL, {0, 0}}
};

const texts_tab_t texts_settings_tab[] = {
    {"ressource/fonts/vel/vel.ttf",
        "--Settings--", 80, &sfBlack, {775, 270}},
    {"ressource/fonts/vel/vel.ttf",
        "Windowed", 50, &sfBlack, {710, 420}},
    {"ressource/fonts/vel/vel.ttf",
        "Full screen", 50, &sfBlack, {1010, 420}},
    {"ressource/fonts/vel/vel.ttf",
        "Music volume", 40, &sfBlack, {850, 530}},
    {"ressource/fonts/vel/vel.ttf",
        "Sounds volume", 40, &sfBlack, {850, 650}},
    {NULL, NULL, 0, NULL, {0, 0}}
};

const texts_tab_t texts_game_tab[] = {
    {NULL, NULL, 0, NULL, {0, 0}}
};
