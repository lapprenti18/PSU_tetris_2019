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

void display_game(storage_t *storage, keyt_t *key, \
store_t *store, gaming_t *gaming)
{
    int b = 0;
    int rng = rand() % store->nb_tetriminos;

    storage->tab = get_next_tab(rng, store);
    do {
        for (int index = 1; storage->windows[index]; index += 1) {
            wclear(storage->windows[index]->window);
            box(storage->windows[index]->window, 0, 0);
            storage->windows[index]->display(storage->windows[index]->window, \
            index, gaming, storage->tab);
            wrefresh(storage->windows[index]->window);
        }
        if (!check_for_collision(gaming))
            gaming->pos_y += 1;
        else {
            gaming->is_blocked = true;
            add_random_form(&gaming, store, rng);
            rng = rand() % store->nb_tetriminos;
            storage->tab = get_next_tab(rng, store);
        }
    } while (analyse_input(b, gaming, store, storage));
}

int display_menu(storage_t *storage)
{
    char *options[2] = {"Play", "Quit"};
    int style = 0;
    int b = 0;

    while (b != 10) {
        for (int i = 0; i < 2; i += 1) {
            if (i == style)
                wattron(storage->windows[MENU]->window, A_REVERSE);
            mvwprintw(storage->windows[MENU]->window, \
            LINES/2 +i, COLS/2, options[i]);
            wattroff(storage->windows[MENU]->window, A_REVERSE);
        }
        b = wgetch(storage->windows[MENU]->window);
        if (b == KEY_UP)
            style -= 1;
        if (b == KEY_DOWN)
            style += 1;
        style = (style == -1 || style == 2) ? (style == -1) ? 1 : 0 : style;
    }
    return (style);
}

void loop_game(keyt_t *key, store_t *store)
{
    char buffer[1];
    storage_t storage;
    gaming_t *gaming = NULL;
    int state = 0;
    int rng = rand() % store->nb_tetriminos;

    cbreak();
    srand(time(NULL));
    while (read(0, buffer, 1) == 0);
    initscr();
    keypad(stdscr, true);
    create_windows(&storage);
    state = display_menu(&storage);
    if (state == 1) {
        endwin();
        destroy_structures(&storage);
        return;
    }
    refresh();
    add_random_form(&gaming, store, rng);
    display_game(&storage, key, store, gaming);
}