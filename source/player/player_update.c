/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_update
*/
#include "consts.h"

#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Sprite.h>
 
#include <math.h>

void player_update_dir(player_t *player, sfVector2f *dir)
{
    if (!player)
        return;
    player->move.movement.x += dir->x;
    player->move.movement.y += dir->y;
}

void player_reset_inputs(player_t *player)
{
    if (!player)
        return;
    player->move.movement = (sfVector2f){0, 0};
    player->state.run = false;
}

void player_update(player_t *player, float dt)
{
    float len = 0;

    if (!player)
        return;
    len = sqrtf(player->move.movement.x * player->move.movement.x
        + player->move.movement.y * player->move.movement.y);
    if (len > 0) {
        player->move.movement.x /= len;
        player->move.movement.y /= len;
    }
    player->move.pos.x += player->move.movement.x *
        state_tab[STATE_WALKING].speed * dt;
    player->move.pos.y += player->move.movement.y *
        state_tab[STATE_WALKING].speed * dt;
    sfSprite_setPosition(player->anim.sprite, player->move.pos);
}
