/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_linked_list_basics
*/
#include <criterion/criterion.h>

#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h" // IWYU pragma: keep

Test(linked_list_add_start, add_on_empty_list)
{
    linked_list_t *new_node = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_start(&list, new_node);
    cr_assert(list != NULL);
    cr_assert(list->id == 1);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_add_start, add_on_filled_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_start(&list, new_node1);
    linked_list_add_start(&list, new_node2);
    cr_assert(list != NULL);
    cr_assert(list->id == 2);
    linked_list_destroy(&list, NULL);
}


Test(linked_list_add_end, add_on_empty_list)
{
    linked_list_t *new_node = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node);
    cr_assert(list != NULL);
    cr_assert(list->id == 1);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_add_end, add_on_filled_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    cr_assert(list != NULL);
    cr_assert(list->id == 1);
    linked_list_destroy(&list, NULL);
}


Test(linked_list_delete_start, delete_one_elem_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    linked_list_delete_start(&list);
    cr_assert(list != NULL);
    cr_assert(list->id == 2);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_delete_start, delete_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_delete_start(&list);
    cr_assert(list == NULL);
    linked_list_destroy(&list, NULL);
}


Test(linked_list_delete_end, delete_one_elem_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    linked_list_delete_end(&list);
    cr_assert(list != NULL);
    cr_assert(list->id == 1);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_delete_end, delete_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_delete_end(&list);
    cr_assert(list == NULL);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_delete_id, delete_one_elem_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    linked_list_delete_id(&list, 1);
    cr_assert(list != NULL);
    cr_assert(list->id == 2);
    linked_list_destroy(&list, NULL);
}

Test(linked_list_delete_id, delete_list)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_delete_id(&list, 1);
    cr_assert(list == NULL);
    linked_list_destroy(&list, NULL);
}
