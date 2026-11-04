/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "enums.h"

#include <stddef.h>

const scenes_tab_t scenes_tab[SCENE_COUNT] = {
    [SCENE_MENU] = {SCENE_MENU, true, images_menu_tab, texts_menu_tab,
        musics_menu_tab, sounds_menu_tab},
    [SCENE_SAVE] = {SCENE_SAVE, false, images_save_tab,
        texts_save_tab, musics_save_tab, sounds_save_tab},
    [SCENE_SETTINGS] = {SCENE_SETTINGS, false, images_settings_tab,
        texts_settings_tab, musics_settings_tab, sounds_settings_tab},
    [SCENE_GAME] = {SCENE_GAME, true, images_game_tab, texts_game_tab,
        musics_game_tab, sounds_game_tab},
    [SCENE_PAUSE] = {SCENE_PAUSE, false, NULL, NULL, NULL, NULL},
    [SCENE_INVENTORY] = {SCENE_INVENTORY, false, NULL, NULL, NULL, NULL},
};
