/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_basics
*/
#include "consts.h"
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>

player_t *player_create(void)
{
    player_t *player = garbage_collector_malloc(sizeof(player_t));

    if (!player)
        return NULL;
    return player;
}
