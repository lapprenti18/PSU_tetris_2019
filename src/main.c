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

void test_key(keyt_t *key, char opt)
{
    (opt == 'L') ? key->lvl = my_getnbr(optarg) : 0;
    (opt == 'l') ? my_strlen(optarg) == 1 ? key->key_left = optarg : 0 : 0;
    (opt == 'r') ? my_strlen(optarg) == 1 ? key->key_right = optarg : 0 : 0; 
    (opt == 't') ? my_strlen(optarg) == 1 ? key->key_turn = optarg: 0 : 0;
    (opt == 'd') ? my_strlen(optarg) == 1 ? key->key_drop = optarg : 0 : 0;
    (opt == 'q') ? my_strlen(optarg) == 1 ? key->key_quit = optarg : 0 : 0;
    (opt == 'p') ? my_strlen(optarg) == 1 ? key->key_pause = optarg : 0 : 0;
    (opt == 'w') ? key->next = true : 0;
    (opt == 'D') ? key->debug = true : 0;
    (opt == 'z') ? my_strlen(optarg) == 1 ? key->help = 1 : 0 : 0;
    (opt == 'a') ? my_strlen(optarg) == 1 ? key->key_left = optarg : 0 : 0;
    (opt == 'b') ? my_strlen(optarg) == 1 ? key->key_right = optarg : 0 : 0;
    (opt == 'c') ? my_strlen(optarg) == 1 ? key->key_turn = optarg : 0 : 0;
    (opt == 'k') ? my_strlen(optarg) == 1 ? key->key_drop = optarg : 0 : 0;
    (opt == 'e') ? my_strlen(optarg) == 1 ? key->key_quit = optarg : 0 : 0;
    (opt == 'f') ? my_strlen(optarg) == 1 ? key->key_pause = optarg : 0 : 0;
    (opt == 'g') ? key->next = true : 0;
    (opt == 'h') ? key->debug = true : 0;
    (opt == 'm') ? key->lvl = my_getnbr(optarg) : 0;
}

int main(int ac, char *av[])
{
    DIR *fd = opendir("tetriminos");
    store_t store;
    keyt_t *key = my_malloc(sizeof(keyt_t));
    char *flag = "L:l:r:t:d:q:p:w:D";
    int opt;
    struct option long_options[] = {
        {"help", no_argument, 0, 'z'},
        {"level=", required_argument, 0, 'm'},
        {"map-size", required_argument, 0, 'x'},
        {"key-left=", required_argument, 0, 'a'},
        {"key-right=", required_argument, 0, 'b'},
        {"key-turn=", required_argument, 0, 'c'},
        {"key-drop=", required_argument, 0, 'k'},
        {"key-quit=", required_argument, 0, 'e'},
        {"key-pause=", required_argument, 0, 'f'},
        {"without-next", no_argument, 0, 'g'},
        {"debug", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    set_up_key(key);
    while ((opt = getopt_long(ac, av, flag, long_options, NULL)) != -1)
        test_key(key, opt);
    key->debug == true ? display_key(key) : 0;
    if (!fd)
        return (84);
    reading_folder(fd, &store);
    closedir(fd);
    display_blocks(&store);
    return (0);
}