/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_engine_get
*/
#include <criterion/criterion.h>

#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"

Test(engine_get_window, basic_get_window)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));

    cr_assert(engine != NULL);
    cr_assert(engine_get_window(engine) == NULL);
    garbage_collector_free(engine);
}

Test(engine_get_window, get_window_with_null)
{
    engine_t *engine = NULL;

    cr_assert(engine_get_window(engine) == NULL);
}

Test(engine_get_delta, basic_get_delta)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));

    cr_assert(engine != NULL);
    cr_assert_float_eq(engine_get_delta(engine), 0, 0.01);
    garbage_collector_free(engine);
}

Test(engine_get_delta, get_delta_with_null)
{
    engine_t *engine = NULL;

    cr_assert_float_eq(engine_get_delta(engine), 0, 0.01);
}
