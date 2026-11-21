/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** state_tab
*/
#include "consts.h"
#include "enums.h"

const state_tab_t state_tab[] = {
    [STATE_IDLE] = {0, 5, 0.25f, 0},
    [STATE_WALKING] = {4, 5, 0.1f, PLAYER_SPEED},
    [STATE_RUNNING] = {8, 5, 0.07f, PLAYER_SPEED * 1.5f},
    [STATE_ATTACKING] = {0, 5, 0.25f, 0},
};
