/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "defines.h"

#include "engine/engine_internal.h"
#include "scene/scene.h"
#include "scene_manager/scene_manager.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>

static unsigned int manage_click(sfEvent event, engine_t *engine,
    scene_manager_t *scene_manager, scene_t *scene)
{
    sfVector2i pixel = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(
        engine_get_window(engine), pixel, scene_get_view(scene));

    return scene_handle_click(scene_manager, scene, &pos, engine);
}

unsigned int engine_events_handler(engine_t *engine,
    scene_manager_t *scene_manager)
{
    sfEvent event = {0};
    scene_t *scene = NULL;

    while (sfRenderWindow_pollEvent(engine->window, &event)) {
        scene = scene_manager_get_current(scene_manager);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(engine->window);
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft &&
            manage_click(event, engine, scene_manager, scene) == ERROR)
            return ERROR;
    }
    return OK;
}
