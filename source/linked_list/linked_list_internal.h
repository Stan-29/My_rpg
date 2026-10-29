/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** linked_list header
*/

#ifndef LINKED_LIST_INTERNAL_H_
    #define LINKED_LIST_INTERNAL_H_

    #include "linked_list/linked_list.h"
    #include "garbage_collector/garbage_collector.h"
    #include "defines.h"
    #include <stdlib.h>

struct linked_list_s {
    unsigned int id;
    void *data;
    linked_list_t *next;
    linked_list_t *prev;
};

#endif
