/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_events_func_move_map
*/
#include "defines.h"
#include "enums.h"

#include <criterion/criterion.h>

#include "scene_manager/scene_manager.h"
#include "scene_manager/scene_manager_internal.h" // IWYU pragma: keep
#include "garbage_collector/garbage_collector.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "map/map_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/View.h>

#include "events_func.h"
#include "types.h"

Test(event_func_move_up, basic_move_up)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sfVector2f camera_pos = {0};

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    engine->delta = 1;
    camera_pos = sfView_getCenter(scene->map->camera);
    event_func_move_up(scene_manager, scene, engine);
    cr_assert_float_eq(sfView_getCenter(scene->map->camera).y, camera_pos.y - CAMERA_SPEED, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}


Test(event_func_move_down, basic_move_down)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sfVector2f camera_pos = {0};

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    engine->delta = 1;
    camera_pos = sfView_getCenter(scene->map->camera);
    event_func_move_down(scene_manager, scene, engine);
    cr_assert_float_eq(sfView_getCenter(scene->map->camera).y, camera_pos.y + CAMERA_SPEED, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}


Test(event_func_move_left, basic_move_left)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sfVector2f camera_pos = {0};

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    engine->delta = 1;
    camera_pos = sfView_getCenter(scene->map->camera);
    event_func_move_left(scene_manager, scene, engine);
    cr_assert_float_eq(sfView_getCenter(scene->map->camera).x, camera_pos.x - CAMERA_SPEED, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}


Test(event_func_move_right, basic_move_right)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;
    sfVector2f camera_pos = {0};

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    engine->delta = 1;
    camera_pos = sfView_getCenter(scene->map->camera);
    event_func_move_right(scene_manager, scene, engine);
    cr_assert_float_eq(sfView_getCenter(scene->map->camera).x, camera_pos.x + CAMERA_SPEED, 0.01);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}
