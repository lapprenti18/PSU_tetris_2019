/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** gaming.c
*/

#include "../include/my.h"

void modif_map(storage_t *store, gaming_t *gaming)
{
    int check = 0;
    int temp_x = 0;

    for (int y = gaming->pos_y; check < gaming->length; y += 1) {
        temp_x = 0;
        for (int x = gaming->pos_x; gaming->tab[check][temp_x]; x += 1) {
            store->map[y][x] = gaming->tab[check][temp_x];
            temp_x += 1;
        }
        check += 1;
    }
}

char **get_next_tab(int rng, store_t *store)
{
    forms_t *copy = store->forms;
    int check = 0;

    for (; copy; copy = copy->next) {
        if (check == rng)
            break;
        check += 1;
    }
    if (!copy)
        return (NULL);
    return (copy->form);
}

int check_for_collision(gaming_t *gaming, storage_t *store)
{
    int last_line = gaming->pos_y + gaming->length;
    int pos_x = gaming->pos_x + 1;
    int pos_y = gaming->pos_y + 1;
    int length = gaming->length;

    if (last_line >= LINES - 11)
        return (1);
    return (0);
}

void add_random_form(gaming_t **gaming, store_t *store, int rng)
{
    char **tab = NULL;
    forms_t *copy = store->forms;
    int check = 0;
    int pos[2];

    for (; copy; copy = copy->next) {
        if (check == rng)
            break;
        check += 1;
    }
    pos[0] = 25;
    pos[1] = 5;
    for (check = 0; copy->form[check]; check += 1);
    add_to_gaming(gaming, pos, check, copy->form);
}

void add_to_gaming(gaming_t **gaming, int pos[2], int length, char **tab)
{
    gaming_t *new = malloc(sizeof(gaming_t));
    int height = 0;
    int len = 0;

    new->pos_x = pos[0];
    new->pos_y = pos[1];
    new->tab = tab;
    new->next = *gaming;
    new->length = length;
    new->is_blocked = false;
    for (int i = 0; tab[i]; i += 1) {
        len = my_strlen(tab[i]);
        if (len > height)
            height = len;
    }
    new->height = height;
    *gaming = new;
}