/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_linked_list_basics
*/
#include <criterion/criterion.h>

#include "garbage_collector/garbage_collector.h"
#include "linked_list/linked_list.h"
#include "linked_list/linked_list_internal.h" // IWYU pragma: keep

Test(linked_list_create_node, basic_creation)
{
    linked_list_t *new_node = linked_list_create_node(NULL, 1);

    cr_assert(new_node != NULL);
    cr_assert(new_node->id == 1);
    garbage_collector_clean();
}

Test(linked_list_destroy, basic_destroy)
{
    linked_list_t *new_node1 = linked_list_create_node(NULL, 1);
    linked_list_t *new_node2 = linked_list_create_node(NULL, 2);
    linked_list_t *list = NULL;

    linked_list_add_end(&list, new_node1);
    linked_list_add_end(&list, new_node2);
    linked_list_destroy(&list, NULL);
    cr_assert(list == NULL);
}

Test(linked_list_destroy, destroy_empty)
{
    linked_list_t *list = NULL;

    linked_list_destroy(&list, NULL);
    cr_assert(list == NULL);
}