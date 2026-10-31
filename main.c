/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** main_function
*/
#include "defines.h"
#include "engine/engine.h"
#include "garbage_collector/garbage_collector.h"

int main(void)
{
    engine_t *engine = engine_create();
    unsigned int return_value = OK;

    if (!engine) {
        garbage_collector_clean();
        return ERROR;
    }
    return_value = engine_run(engine);
    engine_destroy(engine);
    garbage_collector_clean();
    return return_value;
}
