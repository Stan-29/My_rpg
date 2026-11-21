/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_basics
*/
#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/System/Vector2.h>

#include <stddef.h>

sfVector2f *player_get_pos(player_t *player)
{
    if (!player)
        return NULL;
    return &player->move.pos;
}

sfVector2f *player_get_movement(player_t *player)
{
    if (!player)
        return NULL;
    return &player->move.movement;
}
