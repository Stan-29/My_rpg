/*
** EPITECH PROJECT, 2026
** My RPG
** File description:
** test_garbage_collector_free
*/
#include <criterion/criterion.h>

#include "garbage_collector/garbage_collector.h"
#include "garbage_collector/garbage_collector_internal.h" // IWYU pragma: keep

Test(garbage_collector_free, free_size_one_list)
{
    char *temp = garbage_collector_malloc(sizeof(char) * 6);

    cr_assert(temp != NULL);
    cr_assert(garbage_collector_free(temp) == NULL);
    garbage_collector_clean();
}

Test(garbage_collector_free, free_end_list)
{
    char *temp1 = garbage_collector_malloc(sizeof(char) * 6);
    int *temp2 = garbage_collector_malloc(sizeof(int) * 6);

    cr_assert(temp1 != NULL);
    cr_assert(temp2 != NULL);
    cr_assert(garbage_collector_free(temp2) == NULL);
    garbage_collector_clean();
}

Test(garbage_collector_free, free_begin_list)
{
    char *temp1 = garbage_collector_malloc(sizeof(char) * 6);
    int *temp2 = garbage_collector_malloc(sizeof(int) * 6);

    cr_assert(temp1 != NULL);
    cr_assert(temp2 != NULL);
    cr_assert(garbage_collector_free(temp1) == NULL);
    garbage_collector_clean();
}

Test(garbage_collector_free, free_mid_list)
{
    char *temp1 = garbage_collector_malloc(sizeof(char) * 6);
    int *temp2 = garbage_collector_malloc(sizeof(int) * 6);
    int *temp3 = garbage_collector_malloc(sizeof(int) * 6);

    cr_assert(temp1 != NULL);
    cr_assert(temp2 != NULL);
    cr_assert(temp3 != NULL);
    cr_assert(garbage_collector_free(temp2) == NULL);
    garbage_collector_clean();
}

Test(garbage_collector_free, free_not_in_list)
{
    char *temp1 = garbage_collector_malloc(sizeof(char) * 6);
    int *temp2 = garbage_collector_malloc(sizeof(int) * 6);
    int *temp3 = garbage_collector_malloc(sizeof(int) * 6);
    int *temp4 = malloc(sizeof(int) * 6);

    cr_assert(temp1 != NULL);
    cr_assert(temp2 != NULL);
    cr_assert(temp3 != NULL);
    cr_assert(temp4 != NULL);
    cr_assert(garbage_collector_free(temp4) == NULL);
    garbage_collector_clean();
}
