/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_event_func_move_player
*/
#include <criterion/criterion.h>

#include "scene/scene.h"
#include "types.h"

#include "scene_manager/scene_manager.h"
#include "garbage_collector/garbage_collector.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "player/player_internal.h" // IWYU pragma: keep

#include "event_func/event_func.h"

Test(event_func_move_up, basic_move_up)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    event_func_move_up(scene_manager, scene, engine);
    cr_assert_float_eq(scene->player->move.movement.y, -1, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(event_func_move_down, basic_move_down)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    event_func_move_down(scene_manager, scene, engine);
    cr_assert_float_eq(scene->player->move.movement.y, 1, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(event_func_move_left, basic_move_left)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    event_func_move_left(scene_manager, scene, engine);
    cr_assert_float_eq(scene->player->move.movement.x, -1, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(event_func_move_right, basic_move_right)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    event_func_move_right(scene_manager, scene, engine);
    cr_assert_float_eq(scene->player->move.movement.x, 1, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}
