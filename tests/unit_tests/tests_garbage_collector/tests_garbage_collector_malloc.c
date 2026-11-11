/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_garbage_collector_malloc
*/
#include <criterion/criterion.h>

#include "garbage_collector/garbage_collector.h"
#include "garbage_collector/garbage_collector_internal.h" // IWYU pragma: keep

Test(garbage_collector_malloc, add_to_empty_list)
{
    char *temp = garbage_collector_malloc(sizeof(char) * 6);

    cr_assert(temp != NULL);
    garbage_collector_clean();
}

Test(garbage_collector_malloc, add_to_not_empty_list)
{
    char *temp1 = garbage_collector_malloc(sizeof(char) * 6);
    int *temp2 = garbage_collector_malloc(sizeof(int) * 6);

    cr_assert(temp1 != NULL);
    cr_assert(temp2 != NULL);
    garbage_collector_clean();
}
