/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene_internal.h"

sfView *scene_get_view(scene_t *scene)
{
    if (!scene)
        return NULL;
    return scene->view;
}
