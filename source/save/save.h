/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** save header
*/

#ifndef SAVE_H_
    #define SAVE_H_

    #include "enums.h"

    #include <SFML/System/Vector2.h>

typedef struct player_save_s {
    sfVector2f pos;
    skin_id_t skin;
} player_save_t;

typedef struct save_s {
    player_save_t player;
} save_t;

extern const save_t default_save;

#endif
