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
    {"ressource/fonts/vel/vel.ttf",
        "Save 1", 65, &sfBlack, {540, 390}},
    {"ressource/fonts/vel/vel.ttf",
        "Chapter : 0", 40, &sfBlack, {500, 480}},
    {"ressource/fonts/vel/vel.ttf",
        "Level : 0", 40, &sfBlack, {500, 550}},
    {"ressource/fonts/vel/vel.ttf",
        "Coins : 0", 40, &sfBlack, {500, 620}},
    {"ressource/fonts/vel/vel.ttf",
        "Time : 0h", 40, &sfBlack, {500, 690}},
    {"ressource/fonts/vel/vel.ttf",
        "Save 2", 65, &sfBlack, {890, 390}},
    {"ressource/fonts/vel/vel.ttf",
        "Chapter : 0", 40, &sfBlack, {850, 480}},
    {"ressource/fonts/vel/vel.ttf",
        "Level : 0", 40, &sfBlack, {850, 550}},
    {"ressource/fonts/vel/vel.ttf",
        "Coins : 0", 40, &sfBlack, {850, 620}},
    {"ressource/fonts/vel/vel.ttf",
        "Time : 0h", 40, &sfBlack, {850, 690}},
    {"ressource/fonts/vel/vel.ttf",
        "Save 3", 65, &sfBlack, {1240, 390}},
    {"ressource/fonts/vel/vel.ttf",
        "Chapter : 0", 40, &sfBlack, {1200, 480}},
    {"ressource/fonts/vel/vel.ttf",
        "Level : 0", 40, &sfBlack, {1200, 550}},
    {"ressource/fonts/vel/vel.ttf",
        "Coins : 0", 40, &sfBlack, {1200, 620}},
    {"ressource/fonts/vel/vel.ttf",
        "Time : 0h", 40, &sfBlack, {1200, 690}},
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

const texts_tab_t texts_pause_tab[] = {
    {"ressource/fonts/vel/vel.ttf",
        "Pause Menu", 80, &sfBlack, {750, 260}},
    {"ressource/fonts/vel/vel.ttf",
        "Exit", 50, &sfBlack, {730, 420}},
    {"ressource/fonts/vel/vel.ttf",
        "Settings", 50, &sfBlack, {1020, 420}},
    {NULL, NULL, 0, NULL, {0, 0}}
};
