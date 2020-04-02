/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** analys_input.c
*/

#include "../include/my.h"

void rotate_right(gaming_t *gaming, char **tab, int index, int max_len)
{
    int current_len = 0;

    for (; gaming->tab[index]; index += 1) {
        current_len = my_strlen(gaming->tab[index]);
        if (current_len > max_len)
            max_len = current_len;
    }
    tab = malloc(sizeof(char *) * (max_len + 1));
    tab[max_len] = NULL;
    for (int temp = 0; temp < max_len; temp += 1) {
        tab[temp] = malloc(sizeof(char) * (index + 1));
        my_memset(tab[temp], 0, index + 1);
    }
    for (int temp = max_len; temp >= 0; temp -= 1)
        for (int i = 0; i < index; i += 1) {
            current_len = (max_len == 0) ? 0 : temp % (max_len);
            tab[current_len][i] = (temp <= \
            my_strlen(gaming->tab[i])) ? gaming->tab[i][temp] : ' ';
        }
    gaming->tab = tab;
}

int analyse_input(int b, gaming_t *gaming, store_t *store, storage_t *storage)
{
    int b = 0;

    wtimeout(storage->windows[BOARD]->window, 500);
    b = wgetch(storage->windows[BOARD]->window);
    if (b == 27)
        return (0);
    if (b == KEY_LEFT && gaming->pos_x > 1)
        gaming->pos_x -= 1;
    if (b == KEY_RIGHT && gaming->pos_x < 47)
        gaming->pos_x += 1;
    if (b == KEY_DOWN && gaming->pos_y < 52)
        gaming->pos_y += 1;
    if (b == 'd')
        rotate_right(gaming, NULL, 0, 0);
    return (1);
}