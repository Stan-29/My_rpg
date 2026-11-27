/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** object_tab
*/
#include "map/map_internal.h"

#include <stddef.h>

const object_tab_t object_tab[] = {
    [OBJECT_NONE] = {NULL, false, {0, 0, 0, 0}},
    [OBJECT_TREE] = {"./ressource/maps/objects/tree.png", true,
        {-24, -12, 48, 24}},
};
