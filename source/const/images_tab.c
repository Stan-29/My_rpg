/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "images_func.h"

#include <stddef.h>

const images_tab_t images_menu_tab[] = {
    {"./ressource/images/background.jpg",
        {0, 0, 0, 0}, {0, 0}, {2.8, 2.8}, NULL},
    {"./ressource/images/button.png",
        {0, 0, 0, 0}, {750, 400}, {0.4, 0.4}, &image_func_start_game},
    {"./ressource/images/button.png",
        {0, 0, 0, 0}, {750, 550}, {0.4, 0.4}, &image_func_go_to_settings},
    {"./ressource/images/button.png",
        {0, 0, 0, 0}, {750, 700}, {0.4, 0.4}, &image_func_exit_game},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, NULL}
};

const images_tab_t images_settings_tab[] = {
    {"./ressource/images/filter.png",
        {0, 0, 0, 0}, {0, 0}, {1920, 1080}, NULL},
    {"./ressource/images/wood_panel.png",
        {0, 0, 0, 0}, {150, -650}, {1.4, 1.4}, NULL},
    {"./ressource/images/exit_settings_button.png",
        {0, 0, 0, 0}, {700, 700}, {1, 1}, &image_func_exit_settings},
    {"./ressource/images/settings_elem.jpg",
        {458, 344, 240, 110}, {650, 400}, {1, 1}, &image_func_windowed},
    {"./ressource/images/settings_elem.jpg",
        {458, 344, 240, 110}, {950, 400}, {1, 1}, &image_func_full_screen},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, NULL}
};

const images_tab_t images_game_tab[] = {
    {"./ressource/images/game.png",
        {0, 0, 0, 0}, {0, 0}, {1, 1}, NULL},
    {"./ressource/images/button.png",
        {0, 0, 0, 0}, {1550, 900}, {0.3, 0.3}, &image_func_back_to_menu},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, NULL}
};
