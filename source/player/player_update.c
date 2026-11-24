/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_update
*/
#include "consts.h"
#include "defines.h"
#include "enums.h"

#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep
#include "map/map.h"

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

void player_set_run(player_t *player, bool running_state)
{
    if (!player)
        return;
    player->state.run = running_state;
}

void player_reset_inputs(player_t *player)
{
    if (!player)
        return;
    player->move.movement = (sfVector2f){0, 0};
    player->state.run = false;
}

static void player_update_pos(player_t *player, float dt)
{
    float len = 0;
    sfVector2f next = {0};
    state_id_t state = player->state.state;

    len = sqrtf(player->move.movement.x * player->move.movement.x
        + player->move.movement.y * player->move.movement.y);
    if (len > 0) {
        player->move.movement.x /= len;
        player->move.movement.y /= len;
    }
    next = (sfVector2f){player->move.pos.x + player->move.movement.x *
        state_tab[state].speed * dt, player->move.pos.y};
    if (!map_collides(&next))
        player->move.pos.x = next.x;
    next = (sfVector2f){player->move.pos.x, player->move.pos.y +
        player->move.movement.y * state_tab[state].speed * dt};
    if (!map_collides(&next))
        player->move.pos.y = next.y;
    sfSprite_setPosition(player->anim.sprite, player->move.pos);
}

static void player_update_state(player_t *player)
{
    if (player->move.movement.x == 0 && player->move.movement.y == 0)
        player->state.state = STATE_IDLE;
    else if (player->state.run)
        player->state.state = STATE_RUNNING;
    else
        player->state.state = STATE_WALKING;
}

static void player_update_facing(player_t *player)
{
    sfVector2f movement = player->move.movement;

    if (player->state.state == STATE_IDLE)
        return;
    if (fabsf(movement.x) >= fabsf(movement.y)) {
        if (movement.x > 0)
            player->move.facing = DIR_RIGHT;
        else
            player->move.facing = DIR_LEFT;
    } else {
        if (movement.y > 0)
            player->move.facing = DIR_DOWN;
        else
            player->move.facing = DIR_UP;
    }
}

static void player_update_change_of_state(player_t *player)
{
    if (player->state.state == player->state.prev_state &&
        player->move.facing == player->move.prev_facing)
        return;
    player->anim.timer = 0;
    player->anim.frame = 0;
    player->state.prev_state = player->state.state;
    player->move.prev_facing = player->move.facing;
}

static void player_update_anim(player_t *player, float dt)
{
    const state_tab_t *tab = &state_tab[player->state.state];

    player->anim.timer += dt;
    if (player->anim.timer >= tab->delay) {
        player->anim.timer -= tab->delay;
        player->anim.frame = (player->anim.frame + 1) % tab->frame_count;
    }
    player->anim.rect.left = player->anim.frame * FRAME_W;
    player->anim.rect.top = (tab->first_row + player->move.facing) * FRAME_H;
    sfSprite_setTextureRect(player->anim.sprite, player->anim.rect);
}

void player_update(player_t *player, float dt)
{
    if (!player)
        return;
    player_update_state(player);
    player_update_facing(player);
    player_update_change_of_state(player);
    player_update_pos(player, dt);
    player_update_anim(player, dt);
}
