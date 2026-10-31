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
    garbage_collector_t *new_node = calloc(1, sizeof(garbage_collector_t));

    if (!new_node)
        return ERROR;
    new_node->data = data;
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
    void *data = calloc(1, size);

    if (!data)
        return NULL;
    if (garbage_collector_add(data) == ERROR) {
        free(data);
        return NULL;
    }
    return data;
}

void *garbage_collector_free(void *data)
{
    garbage_collector_t *temp = garbage_collector;

    while (temp != NULL) {
        if (temp->data == data)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        return NULL;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        garbage_collector = temp->next;
    free(data);
    free(temp);
    return NULL;
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
