/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** save header
*/

#ifndef SAVE_H_
    #define SAVE_H_

    #include "player/player.h"

    #define SAVE_COUNT 3
    #define MAX_SAVE_INFOS 4

    #define PLAYER_SPAWN_COL 12
    #define PLAYER_SPAWN_ROW 12

typedef struct save_s {
    player_save_t player;
} save_t;

extern const save_t default_save;

extern const char *save_path_tab[];

#endif
