/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "defines.h"

#include "saves.h"

const char *saves_path_tab[SAVE_COUNT] = {
    "./saves/save1.data",
    "./saves/save2.data",
    "./saves/save3.data"
};

const save_t default_save = {
    .player.pos.x = TILE_TO_WORLD_X(PLAYER_SPAWN_COL, PLAYER_SPAWN_ROW),
    .player.pos.y = TILE_TO_WORLD_Y(PLAYER_SPAWN_COL, PLAYER_SPAWN_ROW)
        + TILE_H / 2.0f,
    .player.skin = SKIN_BOY
};
