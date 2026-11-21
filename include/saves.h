/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef SAVES_H_
    #define SAVES_H_

    #include "enums.h"

    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct player_save_s {
    sfVector2f pos;
    skin_id_t skin;
} player_save_t;

typedef struct save_s {
    player_save_t player;
} save_t;

extern const save_t default_save;

#endif
