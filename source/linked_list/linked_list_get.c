/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "garbage_collector/garbage_collector.h"
#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h" // IWYU pragma: keep

unsigned int linked_list_get_id(linked_list_t *node)
{
    if (node == NULL)
        return 0;
    return node->id;
}

void *linked_list_get_data(linked_list_t *node)
{
    if (node == NULL)
        return NULL;
    return node->data;
}

linked_list_t *linked_list_get_next(linked_list_t *node)
{
    if (node == NULL)
        return NULL;
    return node->next;
}

linked_list_t *linked_list_get_prev(linked_list_t *node)
{
    if (node == NULL)
        return NULL;
    return node->prev;
}
