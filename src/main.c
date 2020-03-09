/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"

int check_order(char **tab, int save, int winner)
{
    int temp = save;

    for (int index = 0; tab[winner][index]; index += 1) {
        if (!tab[save] || !tab[save][index]) {
            temp = save;
            break;
        }
        if (tab[save][index] == tab[winner][index])
            continue;
        if (tab[winner][index] > tab[save][index]) {
            temp = save;
            break;
        }
        if (tab[winner][index] < tab[save][index]) {
            temp = winner;
            break;
        }
    }
    return (temp);
}

int ascii_order(store_t *store)
{
    int winner = 0;
    int save = 0;

    while (store->tetriminos[winner]) {
        if (store->tetriminos[winner][0] != '~')
            save = check_order(store->tetriminos, save, winner);
        winner += 1;
    }
    return (save);
}

void update_tab_and_display(store_t *store)
{
    int winner = 0;
    int temp = 0;

    winner = ascii_order(store);
    my_printf("Name ");
    for (int index = 0; store->tetriminos[winner][index]; index += 1) {
        if (store->tetriminos[winner][index] == '.')
            break;
        my_printf("%c", store->tetriminos[winner][index]);
    }
    my_printf(" : ");
    read_and_print(store->tetriminos[winner]);
    store->tetriminos[winner][0] = '~';
}

int main(int ac, char *av[])
{
    (void)ac;
    (void)av;
    DIR *fd = opendir("tetriminos");
    store_t store;

    if (!fd)
        return (84);
    reading_folder(fd, &store);
    closedir(fd);
    if (!store.tetriminos)
        return (84);
    display_blocks(&store);
    return (0);
}