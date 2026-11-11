/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_linked_list_basics
*/
#include <criterion/criterion.h>

#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h" // IWYU pragma: keep

Test(linked_list_get_id, basic_get_id)
{
    linked_list_t *new_node = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_start(&list, new_node);
    cr_assert(linked_list_get_id(list) == 1);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_get_id, get_id_on_null)
{
    linked_list_t *list = NULL;

    cr_assert(linked_list_get_id(list) == 0);
}


Test(linked_list_get_data, basic_get_data)
{
    char *data = malloc(sizeof(char) * 6);
    linked_list_t *new_node = linked_list_create_node(data, 1);
    linked_list_t *list = NULL;

    linked_list_add_start(&list, new_node);
    cr_assert(linked_list_get_data(list) == data);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_get_data, get_data_on_null)
{
    linked_list_t *list = NULL;

    cr_assert(linked_list_get_data(list) == NULL);
}


Test(linked_list_get_next, basic_get_next)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    cr_assert(linked_list_get_next(list)->id == 2);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_get_next, get_next_on_null)
{
    linked_list_t *list = NULL;

    cr_assert(linked_list_get_next(list) == NULL);
}


Test(linked_list_get_prev, basic_get_next)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    cr_assert(linked_list_get_prev(list->next)->id == 1);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_get_prev, get_next_on_null)
{
    linked_list_t *list = NULL;

    cr_assert(linked_list_get_prev(list) == NULL);
}
