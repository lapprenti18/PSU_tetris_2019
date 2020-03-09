/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

int ascii_order(store_t *store)
{
    int winner = 0;

    while (store->tetriminos[winner]) {
        if (store->tetriminos[winner][0] != '~')
            break;
        winner += 1;
    }
    for (int index = winner; store->tetriminos[index]; index += 1) {
        if (store->tetriminos[index][0] != '~' && store->tetriminos[index][0] \
        < store->tetriminos[winner][0])
            winner = index;
    }
    return (winner);
}

int number_order(store_t *store)
{
    int winner = 0;

    while (store->tetriminos[winner]) {
        if (store->tetriminos[winner][0] != '~')
            break;
        winner += 1;
    }
    for (int index = winner; store->tetriminos[index]; index += 1) {
        if (store->tetriminos[index][0] != '~' && my_getnbr(\
        store->tetriminos[index]) < my_getnbr(store->tetriminos[winner]))
            winner = index;
    }
    return (winner);
}

void update_tab_and_display(store_t *store)
{
    int winner = 0;
    int temp = 0;

    for (int index = 0; store->tetriminos[index]; index += 1) {
        if (store->tetriminos[index][0] >= '0' && store->tetriminos[index][0] \
        <= '9' && store->tetriminos[index][0] != '~') {
            temp = 1;
            break;
        }
    }
    if (temp == 1)
        winner = ascii_order(store);
    else
        winner = number_order(store);
    my_printf("Name : ");
    for (int index = 0; store->tetriminos[winner][index]; index += 1) {
        if (store->tetriminos[winner][index] == '.')
            break;
        my_printf("%c", store->tetriminos[winner][index]);
    }
    my_printf("\n");
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
    (void)ac;
    (void)av;
    DIR *fd = opendir("tetriminos");
    store_t store;
    keyt_t *key;
    key = malloc(sizeof(keyt_t));

    set_up_key(key);
    display_key(key);
    if (!fd)
        return (84);
    reading_folder(fd, &store);
    closedir(fd);
    display_blocks(&store);
    return (0);
}