/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "defines.h"
#include "consts.h"

#include "engine/engine_internal.h"
#include "image/image.h"
#include "scene/scene.h"
#include "scene_manager/scene_manager.h"
#include "types.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>

static unsigned int manage_held_image(sfEvent event, engine_t *engine,
    scene_manager_t *scene_manager, scene_t *scene)
{
    unsigned int return_value = OK;

    if (event.type == sfEvtMouseButtonReleased && scene_get_held(scene)) {
        return_value = image_start_func(scene_get_held(scene),
            scene_manager, scene, engine);
        scene_release(scene);
        return return_value;
    }
    return return_value;
}

static unsigned int manage_click(sfEvent event, engine_t *engine,
    scene_manager_t *scene_manager, scene_t *scene)
{
    sfVector2i pixel = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(
        engine_get_window(engine), pixel, scene_get_view(scene));
    image_t *image =
        scene_find_image_by_pos(scene, &pos);

    if (manage_held_image(event, engine, scene_manager, scene) == ERROR)
        return ERROR;
    if (!image)
        return OK;
    if (event.type == sfEvtMouseButtonPressed && image_is_movable(image)) {
        scene_grab(scene, image, &pos);
        return OK;
    }
    if (event.type == sfEvtMouseButtonReleased && !image_is_movable(image))
        return image_start_func(image, scene_manager, scene, engine);
    return OK;
}

static unsigned int manage_keyboard(engine_t *engine,
    scene_manager_t *scene_manager, scene_t *scene)
{
    unsigned int return_value = OK;

    for (unsigned int index = 0; events_tab[index].key_id != -1; index++) {
        if (sfKeyboard_isKeyPressed(events_tab[index].key_id))
            return_value = events_tab[index].func(scene_manager, scene, engine);
        if (return_value == ERROR)
            return ERROR;
    }
    return OK;
}

unsigned int engine_events_handler(engine_t *engine,
    scene_manager_t *scene_manager)
{
    sfEvent event = {0};
    scene_t *scene = NULL;

    while (sfRenderWindow_pollEvent(engine->window, &event)) {
        scene = scene_manager_get_current(scene_manager);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(engine->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            scene_manager_exit_sub(scene_manager);
        if ((event.type == sfEvtMouseButtonReleased ||
                event.type == sfEvtMouseButtonPressed) &&
            event.mouseButton.button == sfMouseLeft &&
            manage_click(event, engine, scene_manager, scene) == ERROR)
            return ERROR;
    }
    manage_keyboard(engine, scene_manager,
        scene_manager_get_current(scene_manager));
    return OK;
}
