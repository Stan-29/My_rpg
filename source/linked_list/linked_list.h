/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** linked_list header
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

typedef struct linked_list_s linked_list_t;

void linked_list_add_start(linked_list_t **linked_list,
    linked_list_t *node);
void linked_list_add_end(linked_list_t **linked_list,
    linked_list_t *node);
void linked_list_delete_start(linked_list_t **head);
void linked_list_delete_end(linked_list_t **head);
void linked_list_delete_id(linked_list_t **head, unsigned int id);

unsigned int linked_list_get_id(linked_list_t *node);
void *linked_list_get_data(linked_list_t *node);
linked_list_t *linked_list_get_next(linked_list_t *node);
linked_list_t *linked_list_create_node(void *data, unsigned int id);

#endif
