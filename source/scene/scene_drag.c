/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "image/image.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>

void scene_grab(scene_t *scene, image_t *image, sfVector2f *mouse_pos)
{
    if (!scene)
        return;
    scene->held = image;
    scene->offset.x = mouse_pos->x - image_get_pos(image).x;
    scene->offset.y = mouse_pos->y - image_get_pos(image).y;
}

void scene_release(scene_t *scene)
{
    if (!scene)
        return;
    scene->held = NULL;
    scene->offset = (sfVector2f){0, 0};
}

void scene_handle_drag(scene_t *scene, sfRenderWindow *window)
{
    sfVector2f mouse_pos = {0};
    sfVector2f new_pos = {0};

    if (!scene || !scene->held)
        return;
    if (window != NULL)
        mouse_pos = sfRenderWindow_mapPixelToCoords(window,
            sfMouse_getPositionRenderWindow(window), scene->view);
    new_pos.x = mouse_pos.x - scene->offset.x;
    new_pos.y = mouse_pos.y - scene->offset.y;
    image_change_base_pos(scene->held, &new_pos);
}
