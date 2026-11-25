/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_player_update
*/
#include <criterion/criterion.h>

#include "consts.h"
#include "save/save.h"

#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep
#include "map/map.h"
#include "map/map_internal.h" // IWYU pragma: keep

static map_t *map = NULL;

static void setup_map(void)
{
    map = map_create();
    cr_assert(map != NULL);
    for (int row = 0; row < MAP_FLOORS_SIZE; row++)
        for (int col = 0; col < MAP_FLOORS_SIZE; col++)
            map->map_objects[row][col] = OBJECT_NONE;
}

static void destroy_map(void)
{
    map_destroy(map);
}

TestSuite(player_update, .init = setup_map, .fini = destroy_map);

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
    player_update(player, map, 1);
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
    player_update(player, map, 1);
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
    player_update(player, map, 1);
    cr_assert_float_eq(player->move.pos.y, start.y, 0.01);
    player_destroy(player);
}

Test(player_update, update_on_null)
{
    player_update(NULL, map, 1);
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


Test(player_update, no_input_is_idle)
{
    player_t *player = player_create(&default_save.player);
    sfVector2f start = player->move.pos;

    player_update(player, map, 1);
    cr_assert(player->state.state == STATE_IDLE);
    cr_assert_float_eq(player->move.pos.x, start.x, 0.01);
    cr_assert_float_eq(player->move.pos.y, start.y, 0.01);
    player_destroy(player);
}

Test(player_update, input_is_walking)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, 0});
    player_update(player, map, 0);
    cr_assert(player->state.state == STATE_WALKING);
    player_destroy(player);
}

Test(player_update, input_and_run_is_running)
{
    player_t *player = player_create(&default_save.player);
    sfVector2f start = player->move.pos;

    player_update_dir(player, &(sfVector2f){1, 0});
    player_set_run(player, true);
    player_update(player, map, 1);
    cr_assert(player->state.state == STATE_RUNNING);
    cr_assert_float_eq(player->move.pos.x,
        start.x + state_tab[STATE_RUNNING].speed, 0.01);
    player_destroy(player);
}

Test(player_update, run_without_input_is_idle)
{
    player_t *player = player_create(&default_save.player);

    player_set_run(player, true);
    player_update(player, map, 0);
    cr_assert(player->state.state == STATE_IDLE);
    player_destroy(player);
}

Test(player_update, facing_follows_each_direction)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){-1, 0});
    player_update(player, map, 0);
    cr_assert(player->move.facing == DIR_LEFT);
    player_reset_inputs(player);
    player_update_dir(player, &(sfVector2f){1, 0});
    player_update(player, map, 0);
    cr_assert(player->move.facing == DIR_RIGHT);
    player_reset_inputs(player);
    player_update_dir(player, &(sfVector2f){0, -1});
    player_update(player, map, 0);
    cr_assert(player->move.facing == DIR_UP);
    player_reset_inputs(player);
    player_update_dir(player, &(sfVector2f){0, 1});
    player_update(player, map, 0);
    cr_assert(player->move.facing == DIR_DOWN);
    player_destroy(player);
}

Test(player_update, diagonal_faces_horizontal)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, -1});
    player_update(player, map, 0);
    cr_assert(player->move.facing == DIR_RIGHT);
    player_destroy(player);
}

Test(player_update, facing_kept_when_stopped)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){-1, 0});
    player_update(player, map, 0);
    player_reset_inputs(player);
    player_update(player, map, 0);
    cr_assert(player->state.state == STATE_IDLE);
    cr_assert(player->move.facing == DIR_LEFT);
    player_destroy(player);
}

Test(player_update, frame_advances_after_delay)
{
    player_t *player = player_create(&default_save.player);

    player_update(player, map, state_tab[STATE_IDLE].delay);
    cr_assert(player->anim.frame == 1);
    player_destroy(player);
}

Test(player_update, frame_loops_after_frame_count)
{
    player_t *player = player_create(&default_save.player);

    for (unsigned int i = 0; i < state_tab[STATE_IDLE].frame_count; i++)
        player_update(player, map, state_tab[STATE_IDLE].delay);
    cr_assert(player->anim.frame == 0);
    player_destroy(player);
}

Test(player_update, change_of_direction_resets_anim)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){1, 0});
    player_update(player, map, state_tab[STATE_WALKING].delay);
    player_reset_inputs(player);
    player_update_dir(player, &(sfVector2f){0, -1});
    player_update(player, map, 0);
    cr_assert(player->anim.frame == 0);
    cr_assert_float_eq(player->anim.timer, 0, 0.001);
    player_destroy(player);
}

Test(player_update, rect_on_running_up_row)
{
    player_t *player = player_create(&default_save.player);

    player_update_dir(player, &(sfVector2f){0, -1});
    player_set_run(player, true);
    player_update(player, map, 0);
    cr_assert(player->anim.rect.top ==
        (int)(state_tab[STATE_RUNNING].first_row + DIR_UP) * FRAME_H);
    cr_assert(player->anim.rect.left == 0);
    player_destroy(player);
}

Test(player_set_run, set_run_on_null)
{
    player_set_run(NULL, true);
}
