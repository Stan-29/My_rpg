/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** garbage collector header
*/

#ifndef GARBAGE_COLLECTOR_INTERNAL_H_
    #define GARBAGE_COLLECTOR_INTERNAL_H_

    #include "garbage_collector/garbage_collector.h"

    #include <stddef.h>

struct garbage_collector_s {
    void *data;
    garbage_collector_t *next;
    garbage_collector_t *prev;
};

#endif
