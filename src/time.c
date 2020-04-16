/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_windows.c
*/

#include "../include/my.h"

void update_times(storage_t *storage, store_t *store, gaming_t *gaming)
{
    storage->timer = clock() / 1000;
    storage->score = storage->timer + storage->bonus;
    storage->level = storage->timer / 100;
}