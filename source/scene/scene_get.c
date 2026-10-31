/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep

#include <stddef.h>

sfView *scene_get_view(scene_t *scene)
{
    if (!scene)
        return NULL;
    return scene->view;
}
