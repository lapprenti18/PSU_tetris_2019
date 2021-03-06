/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

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

void update_tab_and_display(store_t *store)
{
    int winner = 0;

    winner = ascii_order(store);
    my_printf("Name ");
    for (int index = 0; store->tetriminos[winner][index]; index += 1) {
        if (store->tetriminos[winner][index] == '.')
            break;
        my_printf("%c", store->tetriminos[winner][index]);
    }
    my_printf(" : ");
    read_and_print(store->tetriminos[winner], store);
    store->tetriminos[winner][0] = '~';
}

char *str_copy(char *enter)
{
    char *temp = my_malloc(my_strlen(enter) + 1);
    temp[my_strlen(enter)] = '\0';

    for (int a = 0; a < my_strlen(enter) + 1; a += 1) {
        temp[a] = enter[a];
    }
    return (temp);
}

int main(int ac, char *av[])
{
    DIR *fd = opendir("tetriminos");
    keyt_t *key = my_malloc(sizeof(keyt_t));
    store_t store;

    if (set_up_key(key, ac, av) == 1)
        return (0);
    if (ac == 1) {
        display_usage(av[0]);
        return (0);
    }
    options(ac, av, key);
    if (!fd)
        return (84);
    reading_folder(fd, &store);
    if (!store.tetriminos)
        return (84);
    key->debug == true ? display_key(key) : 0;
    key->debug == true ? display_blocks(&store) : 0;
    loop_game(key, &store);
    return (0);
}