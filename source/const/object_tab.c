/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "enums.h"

#include <stddef.h>

const object_tab_t object_tab[] = {
    [OBJECT_NONE] = {NULL, false},
    [OBJECT_TREE] = {"./ressource/images/objects/tree.png", true},
};
