/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** gaming.c
*/

#include "../include/my.h"

char **get_next_tab(int rng, store_t *store)
{
    forms_t *copy = store->forms;
    int check = 0;

    for (; copy; copy = copy->next) {
        if (check == rng)
            break;
        check += 1;
    }
    return (copy->form);
}

int check_for_collision(gaming_t *gaming)
{
    int last_line = gaming->pos_y + gaming->length;
    int pos_x = gaming->pos_x;

    if (last_line >= 52)
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

    new->pos_x = pos[0];
    new->pos_y = pos[1];
    new->tab = tab;
    new->next = *gaming;
    new->length = length;
    new->is_blocked = false;
    *gaming = new;
}