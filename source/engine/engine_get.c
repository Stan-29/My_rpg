/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine_get
*/
#include "types.h"

#include "engine/engine_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/VideoMode.h>

sfRenderWindow *engine_get_window(engine_t *engine)
{
    if (!engine)
        return NULL;
    return engine->window;
}

float engine_get_delta(engine_t *engine)
{
    if (!engine)
        return 0;
    return engine->delta;
}
