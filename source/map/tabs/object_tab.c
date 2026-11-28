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
    [OBJECT_PALM] = {"./ressource/maps/objects/palm.png", true,
        {-16, -8, 32, 16}},
    [OBJECT_BUSH] = {"./ressource/maps/objects/bush.png", true,
        {-36, -14, 72, 28}},
    [OBJECT_ROCK] = {"./ressource/maps/objects/rock.png", true,
        {-36, -14, 72, 28}},
    [OBJECT_FLOWERS] = {"./ressource/maps/objects/flowers.png", false,
        {0, 0, 0, 0}},
    [OBJECT_FENCE] = {"./ressource/maps/objects/fence.png", true,
        {-80, -8, 160, 16}},
    [OBJECT_HOUSE] = {"./ressource/maps/objects/house.png", true,
        {-90, -40, 180, 80}},
    [OBJECT_MUSHROOM] = {"./ressource/maps/objects/mushroom.png", false,
        {0, 0, 0, 0}},
    [OBJECT_STUMP] = {"./ressource/maps/objects/stump.png", true,
        {-28, -10, 56, 20}},
};
