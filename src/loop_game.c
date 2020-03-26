/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void destroy_structures(storage_t *store)
{
    for (int i = 0; store->windows[i]; i += 1)
        free (store->windows[i]);
    free (store->windows);
}

void display_game(storage_t *store, keyt_t *key)
{
    int b = 0;

    do {
        for (int index = 1; store->windows[index]; index += 1) {
            store->windows[index]->display(store->windows[index]->window, \
            index);
            wrefresh(store->windows[index]->window);
        }
        b = getch();
    } while (b != 27);
}

int display_menu(storage_t *store)
{
    char *options[2] = {"Play", "Quit"};
    int style = 0;
    int b = 0;

    while (b != 10) {
        for (int i = 0; i < 2; i += 1) {
            if (i == style)
                wattron(store->windows[MENU]->window, A_REVERSE);
            mvwprintw(store->windows[MENU]->window, \
            LINES/2 +i, COLS/2, options[i]);
            wattroff(store->windows[MENU]->window, A_REVERSE);
        }
        b = wgetch(store->windows[MENU]->window);
        if (b == KEY_UP)
            style -= 1;
        if (b == KEY_DOWN)
            style += 1;
        style = (style == -1 || style == 2) ? (style == -1) ? 1 : 0 : style;
    }
    return (style);
}

void loop_game(keyt_t *key)
{
    char buffer[1];
    storage_t store;
    int state = 0;

    cbreak();
    noecho();
    curs_set(0);
    srand(time(NULL));
    while (read(0, buffer, 1) == 0);
    initscr();
    keypad(stdscr, true);
    create_windows(&store);
    state = display_menu(&store);
    if (state == 1) {
        endwin();
        destroy_structures(&store);
        return;
    }
    refresh();
    display_game(&store, key);
}