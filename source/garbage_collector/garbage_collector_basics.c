/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** engine code
*/
#include "garbage_collector/garbage_collector.h"
#include "defines.h"
#include <stddef.h>
#include <stdlib.h>

static garbage_collector_t *garbage_collector = NULL;

struct garbage_collector_s {
    void *data;
    garbage_collector_t *next;
    garbage_collector_t *prev;
};

static unsigned int garbage_collector_add(void *data)
{
    garbage_collector_t *new_node = malloc(sizeof(garbage_collector_t));

    if (!new_node)
        return ERROR;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (garbage_collector == NULL)
        garbage_collector = new_node;
    else {
        garbage_collector->prev = new_node;
        new_node->next = garbage_collector;
        garbage_collector = new_node;
    }
    return OK;
}

void *garbage_collector_malloc(size_t size)
{
    void *data = malloc(size);

    if (!data)
        return NULL;
    garbage_collector_add(data);
    return data;
}

void garbage_collector_free(void *data)
{
    garbage_collector_t *temp = garbage_collector;

    while (temp != NULL) {
        if (temp->data == data)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        garbage_collector = temp->next;
    free(data);
    free(temp);
}

void garbage_collector_clean(void)
{
    garbage_collector_t *temp = NULL;

    while (garbage_collector != NULL) {
        temp = garbage_collector->next;
        free(garbage_collector->data);
        free(garbage_collector);
        garbage_collector = temp;
    }
    return;
}
