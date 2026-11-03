/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_MANAGER_INTERNAL_H_
    #define SCENE_MANAGER_INTERNAL_H_

    #include "types.h"
    #include "enums.h"

struct scene_manager_s {
    unsigned int main_scene;
    unsigned int sub_scene;
    scene_t *scene[SCENE_COUNT];
};

#endif
