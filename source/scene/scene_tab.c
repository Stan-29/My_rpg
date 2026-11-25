/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_tab
*/
#include "consts.h"
#include "enums.h"

#include <stddef.h>

const scene_tab_t scene_tab[SCENE_COUNT] = {
    [SCENE_MENU] = {SCENE_MENU, true, image_menu_tab, text_menu_tab,
        music_menu_tab, sound_menu_tab},
    [SCENE_SAVE] = {SCENE_SAVE, false, image_save_tab,
        text_save_tab, music_save_tab, sound_save_tab},
    [SCENE_SETTINGS] = {SCENE_SETTINGS, false, image_settings_tab,
        text_settings_tab, music_settings_tab, sound_settings_tab},
    [SCENE_GAME] = {SCENE_GAME, true, image_game_tab, text_game_tab,
        music_game_tab, sound_game_tab},
    [SCENE_PAUSE] = {SCENE_PAUSE, false, image_pause_tab, text_pause_tab,
        music_pause_tab, sound_pause_tab},
    [SCENE_INVENTORY] = {SCENE_INVENTORY, false, NULL, NULL, NULL, NULL},
};
