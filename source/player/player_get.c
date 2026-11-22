/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_basics
*/
#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/System/Vector2.h>

sfVector2f player_get_pos(player_t *player)
{
    if (!player)
        return (sfVector2f){0, 0};
    return player->move.pos;
}

sfVector2f player_get_movement(player_t *player)
{
    if (!player)
        return (sfVector2f){0, 0};
    return player->move.movement;
}
