/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** map_tab
*/
#include "map/map_internal.h"

const map_tab_t map_tab[] = {
    [MAP_BEACH] = {"./ressource/maps/beach_floor.data",
        "./ressource/maps/beach_object.data"},
    [MAP_VILLAGE] = {"./ressource/maps/village_floor.data",
        "./ressource/maps/village_object.data"},
    [MAP_FOREST] = {"./ressource/maps/forest_floor.data",
        "./ressource/maps/forest_object.data"},
};
