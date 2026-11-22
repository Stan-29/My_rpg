/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_player_update
*/
#include <criterion/criterion.h>

#include "consts.h"
#include "saves.h"

#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

Test(player_update_dir, dir_is_summed)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, 0});
    player_update_dir(player, &(sfVector2f){0, 1});
    cr_assert_float_eq(player->move.movement.x, 1, 0.01);
    cr_assert_float_eq(player->move.movement.y, 1, 0.01);
    player_destroy(player);
}

Test(player_update_dir, update_dir_on_null)
{
    player_update_dir(NULL, &(sfVector2f){0, 1});
}

Test(player_reset_inputs, inputs_are_reset)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, 1});
    player->state.run = true;
    player_reset_inputs(player);
    cr_assert_float_eq(player->move.movement.x, 0, 0.01);
    cr_assert_float_eq(player->move.movement.y, 0, 0.01);
    cr_assert(player->state.run == false);
    player_destroy(player);
}

Test(player_reset_inputs, reset_on_null)
{
    player_reset_inputs(NULL);
}

Test(player_update, moves_at_walking_speed)
{
    player_t *player = player_create(&default_save.player);
    sfVector2f start = player->move.pos;

    player_update_dir(player, &(sfVector2f){0, 1});
    player_update(player, 1);
    cr_assert_float_eq(player->move.pos.y,
        start.y + state_tab[STATE_WALKING].speed, 0.01);
    cr_assert_float_eq(player->move.pos.x, start.x, 0.01);
    player_destroy(player);
}

Test(player_update, diagonal_is_normalized)
{
    player_t *player = player_create(&default_save.player);
    sfVector2f start = player->move.pos;
    float speed = state_tab[STATE_WALKING].speed;

    player_update_dir(player, &(sfVector2f){1, 0});
    player_update_dir(player, &(sfVector2f){0, -1});
    player_update(player, 1);
    cr_assert_float_eq(player->move.pos.x, start.x + speed * 0.7071f, 0.1);
    cr_assert_float_eq(player->move.pos.y, start.y - speed * 0.7071f, 0.1);
    player_destroy(player);
}

Test(player_update, opposite_keys_dont_move)
{
    player_t *player = player_create(&default_save.player);
    sfVector2f start = player->move.pos;

    player_update_dir(player, &(sfVector2f){0, 1});
    player_update_dir(player, &(sfVector2f){0, -1});
    player_update(player, 1);
    cr_assert_float_eq(player->move.pos.y, start.y, 0.01);
    player_destroy(player);
}

Test(player_update, update_on_null)
{
    player_update(NULL, 1);
}

Test(player_get_pos, basic_get_pos)
{
    player_t *player = player_create(&default_save.player);

    cr_assert_float_eq(player_get_pos(player).x,
        default_save.player.pos.x, 0.01);
    cr_assert_float_eq(player_get_pos(player).y,
        default_save.player.pos.y, 0.01);
    player_destroy(player);
}

Test(player_get_pos, get_pos_on_null)
{
    cr_assert_float_eq(player_get_pos(NULL).x, 0, 0.01);
    cr_assert_float_eq(player_get_pos(NULL).y, 0, 0.01);
}

Test(player_get_movement, basic_get_movement)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, 0});
    cr_assert_float_eq(player_get_movement(player).x, 1, 0.01);
    player_destroy(player);
}

Test(player_get_movement, get_movement_on_null)
{
    cr_assert_float_eq(player_get_movement(NULL).x, 0, 0.01);
}
