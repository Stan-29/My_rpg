/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "enums.h"
#include "images_func.h"

#include <stddef.h>

const images_tab_t images_scenes_tab[] = {
    {SCENE_MENU, "./ressource/images/background.png",
        {0, 0, 0, 0}, {0, 0}, {3.5, 3.5}, NULL},
    {SCENE_MENU, "./ressource/images/start_button.png",
        {0, 0, 0, 0}, {800, 500}, {0.4, 0.4}, &image_func_start_game},
    {SCENE_MENU, "./ressource/images/Exit.jpg",
        {0, 0, 0, 0}, {800, 700}, {0.2, 0.2}, &image_func_exit_game},
    {SCENE_GAME, "./ressource/images/game.png",
        {0, 0, 0, 0}, {0, 0}, {1, 1}, NULL},
    {SCENE_GAME, "./ressource/images/start_button.png",
        {0, 0, 0, 0}, {1550, 900}, {0.3, 0.3}, &image_func_back_to_menu},
    {SCENE_NONE, NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, NULL}
};
