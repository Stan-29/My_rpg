/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_engine_basics
*/
#include <criterion/criterion.h>

#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"

#include <SFML/System/Clock.h>

Test(engine_destroy, basic_destroy)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));

    cr_assert(engine != NULL);
    engine->clock = sfClock_create();
    engine_destroy(engine);
}

Test(engine_destroy, destroy_on_null)
{
    engine_destroy(NULL);
    cr_assert(engine_get_window(NULL) == NULL);
}
