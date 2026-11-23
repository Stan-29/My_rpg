/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "events_func.h"

#include <SFML/Window/Keyboard.h>

#include <stddef.h>

const events_tab_t events_tab[] = {
    {sfKeyS, &event_func_move_down},
    {sfKeyZ, &event_func_move_up},
    {sfKeyQ, &event_func_move_left},
    {sfKeyD, &event_func_move_right},
    {sfKeyLShift, &event_func_run},
    {-1, NULL}
};
