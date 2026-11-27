/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** event_tab
*/
#include "engine/engine_internal.h"
#include "event_func/event_func.h"

#include <SFML/Window/Keyboard.h>

#include <stddef.h>

const event_tab_t event_tab[] = {
    {sfKeyS, &event_func_move_down},
    {sfKeyZ, &event_func_move_up},
    {sfKeyQ, &event_func_move_left},
    {sfKeyD, &event_func_move_right},
    {sfKeyLShift, &event_func_run},
    {-1, NULL}
};
