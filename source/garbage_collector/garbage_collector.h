/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** garbage collector header
*/

#ifndef GARBAGE_COLLECTOR_H_
    #define GARBAGE_COLLECTOR_H_

    #include <stddef.h>

typedef struct garbage_collector_s garbage_collector_t;

void *garbage_collector_malloc(size_t size);
void garbage_collector_free(void *data);
void garbage_collector_clean(void);

#endif
