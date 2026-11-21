/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "defines.h"

#include "saves.h"

#include <stddef.h>

const char *saves_path_tab[SAVE_COUNT] = {
    "./saves/save1.data",
    "./saves/save2.data",
    "./saves/save3.data"
};

const save_t default_save = {
    .player.pos.x = 0,
    .player.pos.y = 0,
    .player.skin = SKIN_BOY
};
