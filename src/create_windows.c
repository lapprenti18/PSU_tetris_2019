/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_windows.c
*/

#include "../include/my.h"

void update_print(WINDOW *window, int index, \
gaming_t *gaming, storage_t *store)
{
    if (index == BOARD) {
        mvwprintw(window, 1, 1, "TETRIS GAME!");
        for (int i = 0; store->map[i]; i += 1)
            mvwprintw(window, i + 1, \
            1, store->map[i]);
        for (int i = 0; gaming->tab[i]; i += 1)
            mvwprintw(window, gaming->pos_y + i, \
            gaming->pos_x, gaming->tab[i]);
    }
    if (index == NEXT) {
        mvwprintw(window, 0, 2, "next");
        for (int index = 0; store->tab[index]; index += 1) {
            mvwprintw(window, index + 1, 7, store->tab[index]);
        }
    }
    if (index == INFOS) {
        mvwprintw(window, 2, 1, "High Score\t\t%d", 100);
        mvwprintw(window, 3, 1, "Score\t\t\t%d", 50);
        mvwprintw(window, 5, 1, "Lines\t\t\t%d", 10);
        mvwprintw(window, 6, 1, "Level\t\t\t%d", 1);
        mvwprintw(window, 8, 1, "Timer\t\t\t%d", 30);
    }
}

window_t *create_window(int height, int width, \
int position_y, int position_x)
{
    WINDOW *win = newwin(height, width, position_y, position_x);
    window_t *window = malloc(sizeof(window_t));
    static int check = 0;

    keypad(win, true);
    if (check != 0)
        if (check != 1)
            wborder(win, '|', '|', '-', '-', '/', '\\', '\\', '/');
        else
            wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    else
        box(win, 0, 0);
    window->window = win;
    window->height = height;
    window->position_x = position_x;
    window->position_y = position_y;
    window->index = check;
    check += 1;
    return (window);
}

void create_windows(storage_t *store)
{
    int height = LINES - 10;

    store->windows = malloc(sizeof(window_t *) * (TOTAL + 1));
    store->windows[MENU] = create_window(0, 0, 0, 0);
    store->windows[BOARD] = create_window(height + 2, 52, 0, COLS / 2 - 28);
    store->windows[NEXT] = create_window(8, 20, 1, COLS / 2 + 26);
    store->windows[INFOS] = create_window(10, 30, 20, 50);
    store->windows[TOTAL] = NULL;
    store->tab = NULL;
    store->map = malloc(sizeof(char *) * (height + 1));
    store->map[height] = NULL;
    for (int i = 0; i < height; i += 1) {
        store->map[i] = malloc(sizeof(char) * 51);
        my_memset(store->map[i], ' ', 50);
        store->map[i][50] = 0;
    }
}