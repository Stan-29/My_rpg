/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "garbage_collector/garbage_collector.h"
#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h"

void linked_list_add_start(linked_list_t **head,
    linked_list_t *new_node)
{
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void linked_list_add_end(linked_list_t **head,
    linked_list_t *new_node)
{
    linked_list_t *temp = *head;

    if (*head == NULL) {
        *head = new_node;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void linked_list_delete_start(linked_list_t **head)
{
    linked_list_t *temp = *head;

    if (*head == NULL)
        return;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    garbage_collector_free(temp);
}

void linked_list_delete_end(linked_list_t **head)
{
    linked_list_t *temp = *head;

    if (*head == NULL)
        return;
    if (temp->next == NULL) {
        *head = NULL;
        garbage_collector_free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    garbage_collector_free(temp);
}

void linked_list_delete_id(linked_list_t **head, unsigned int id)
{
    linked_list_t *temp = *head;

    if (*head == NULL)
        return;
    while (temp != NULL && temp->id != id)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    garbage_collector_free(temp);
}
