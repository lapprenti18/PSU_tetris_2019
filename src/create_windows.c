/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_windows.c
*/

#include "../include/my.h"

void update_print(WINDOW *window, int index)
{
    if (index == BOARD)
        mvwprintw(window, 1, 1, "TETRIS GAME!");
    if (index == NEXT)
        mvwprintw(window, 0, 2, "next");
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
    window->display = update_print;
    check += 1;
    return (window);
}

void create_windows(storage_t *store)
{
    store->windows = malloc(sizeof(window_t *) * (TOTAL + 1));
    store->windows[MENU] = create_window(0, 0, 0, 0);
    store->windows[BOARD] = create_window(LINES - 2, 50, 1, COLS / 2 - 25);
    store->windows[NEXT] = create_window(5, 15, 1, COLS / 2 + 26);
    store->windows[INFOS] = create_window(10, 30, 20, 50);
    store->windows[TOTAL] = NULL;
}