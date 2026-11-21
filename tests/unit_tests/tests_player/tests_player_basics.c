/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_player_basics
*/
#include <criterion/criterion.h>

#include "enums.h"
#include "saves.h"

#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>

Test(player_create, basic_create)
{
    player_t *player = player_create(&default_save.player);

    cr_assert(player != NULL);
    cr_assert(player->move.facing == DIR_DOWN);
    cr_assert(player->state.state == STATE_IDLE);
    player_destroy(player);
}

Test(player_destroy, destroy_null_player)
{
    player_destroy(NULL);
}

Test(player_draw, draw_null_window)
{
    player_t *player = player_create(&default_save.player);

    player_draw(player, NULL);
    cr_assert(player != NULL);
    player_destroy(player);
}

Test(player_draw, draw_null_player)
{
    player_draw(NULL, NULL);
}
