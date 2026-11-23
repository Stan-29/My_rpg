/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** tests_events_func_player_handling
*/
#include <criterion/criterion.h>

#include "enums.h"

#include "scene_manager/scene_manager.h"
#include "garbage_collector/garbage_collector.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "engine/engine.h"
#include "engine/engine_internal.h" // IWYU pragma: keep
#include "player/player_internal.h" // IWYU pragma: keep

#include "events_func.h"

Test(event_func_run, basic_run)
{
    engine_t *engine = garbage_collector_malloc(sizeof(engine_t));
    scene_manager_t *scene_manager = scene_manager_create();
    scene_t *scene = NULL;

    scene_manager_set_scene(scene_manager, SCENE_GAME);
    scene = scene_manager_get_current(scene_manager);
    event_func_run(scene_manager, scene, engine);
    cr_assert(scene->player->state.run == true);
    scene_manager_destroy(scene_manager);
    engine_destroy(engine);
}

Test(scene_set_player_run, set_run_without_player)
{
    scene_t *scene = scene_create(SCENE_MENU);

    scene_set_player_run(scene, true);
    cr_assert(scene->player == NULL);
    scene_destroy(scene);
}

Test(scene_set_player_run, set_run_on_null)
{
    scene_set_player_run(NULL, true);
}
