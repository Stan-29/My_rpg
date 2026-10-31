/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h"

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

linked_list_t *linked_list_create_node(void *data, unsigned int id)
{
    linked_list_t *new_elem = garbage_collector_malloc(sizeof(linked_list_t));

    if (!new_elem)
        return NULL;
    new_elem->data = data;
    new_elem->id = id;
    return new_elem;
}
