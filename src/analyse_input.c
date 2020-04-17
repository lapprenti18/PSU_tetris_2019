/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** analys_input.c
*/

#include "../include/my.h"

void update_map(storage_t *storage, int i)
{
    for (int y = i; y > 0; y -= 1) {
        for (int x = 0; storage->map[y - 1][x]; x += 1)
            if (storage->map[y - 1][x] == '*')
                storage->map[y][x] = '*';
        my_memset(storage->map[y - 1], ' ', 50);
    }
}

int full_line(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] != '*')
            return (0);
    return (1);
}

void rotate_right(gaming_t *gaming, char **tab, int index, int max_len)
{
    int current_len = 0;
    int i = 0;

    for (; gaming->tab[index]; index += 1) {
        current_len = my_strlen(gaming->tab[index]);
        if (current_len > max_len)
            max_len = current_len;
    }
    tab = malloc(sizeof(char *) * (max_len + 1));
    tab[max_len] = NULL;
    for (int temp = 0; temp < max_len; temp += 1)
        tab[temp] = malloc(sizeof(char) * index + 1);
    for (int x = 0; x < max_len; x += 1) {
        current_len = 0;
        for (int y = index; y > 0; y -= 1) {
            tab[i][current_len] = gaming->tab[y - 1][x];
            current_len += 1;
        }
        tab[i][current_len] = 0;
        i += 1;
    }
    for (current_len = 0; tab[current_len]; current_len += 1);
    gaming->tab = tab;
    gaming->length = current_len;
}

int analyse_input(int b, gaming_t *gaming, store_t *store, storage_t *storage)
{
    wtimeout(storage->windows[BOARD]->window, 500);
    b = wgetch(storage->windows[BOARD]->window);
    if (b == 27)
        return (0);
    for (int x = 0; storage->map[10][x]; x += 1)
        if (storage->map[10][x] == '*')
            exit (0);
    if (b == KEY_LEFT && gaming->pos_x > 1 && !gaming->is_blocked)
        gaming->pos_x -= 1;
    if (b == KEY_RIGHT && gaming->pos_x < 47 && !gaming->is_blocked)
        gaming->pos_x += 1;
    if (b == 'd' && !gaming->is_blocked && gaming->pos_x > 5 && gaming->pos_x < 45)
        rotate_right(gaming, NULL, 0, 0);
    return (1);
}