/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "garbage_collector/garbage_collector.h"
#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h" // IWYU pragma: keep

linked_list_t *linked_list_create_node(void *data, unsigned int id)
{
    linked_list_t *new_elem = garbage_collector_malloc(sizeof(linked_list_t));

    if (!new_elem)
        return NULL;
    new_elem->data = data;
    new_elem->id = id;
    return new_elem;
}

void linked_list_destroy(linked_list_t **head, void *(*destroy)(void *))
{
    while (*head != NULL) {
        if (destroy != NULL)
            destroy(linked_list_get_data(*head));
        linked_list_delete_start(head);
    }
}
