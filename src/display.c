/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

void options(int ac, char **av, keyt_t *key)
{
    char *flag = "L:l:r:t:d:q:p:w:D";
    int opt = 0;
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
        {0, 0, 0, 0}};

    while ((opt = getopt_long(ac, av, flag, long_options, NULL)) != -1)
        test_key_one(key, opt, av[0]);
}

int display_usage(char *name)
{
    char *str = "[options]\n\
Options:\n \
--help                 Display this help\n \
-L --level={num}       Start Tetris at level num (def: 1)\n \
-l --key-left={K}      Move the tetrimino LEFT using the K key \
(def: left arrow)\n \
-r --key-right={K}     Move the tetrimino RIGHT using the K key \
(def: right arrow)\n \
-t --key-turn={K}      TURN the tetrimino clockwise 90d using the K key \
(def: top arrow)\n \
-d --key-drop={K}      DROP the tetrimino using the K key (def: down arrow)\n \
-q --key-quit={K}      QUIT the game using the K key \
(def: 'q' key)\n \
-p --key-pause={K}     PAUSE/RESTART the game using the K key \
(def: space bar)\n \
--map-size={row,col}   Set the numbers of rows and columns \
of the map (def: 20,10)\n \
-w --without-next      Hide next tetrimino (def: false)\n \
-D --debug             Debug mode (def: false)\n";
    my_printf("Usage: %s %s", name, str);
    return (1);
}

void display_key(keyt_t *key)
{
    my_printf("*** DEBUG MODE ***\n");
    my_printf("Key Left : %s\n", key->key_left);
    my_printf("Key Right : %s\n", key->key_right);
    my_printf("Key Turn : %s\n", key->key_turn);
    my_printf("Key Drop : %s\n", key->key_drop);
    my_printf("Key Quit : %s\n", key->key_quit);
    my_printf("Key Pause : %s\n", key->key_pause);
    my_printf("Next : ");
    key->next == 0 ? my_printf("Yes\n") : my_printf("No\n");
    my_printf("Level : %d\n", key->lvl);
    my_printf("Size : %s\n", key->size);

}

int set_up_key(keyt_t *key, int ac, char *av[])
{
    if (ac == 2 && !my_strcmp(av[1], "--help"))
        return (display_usage(av[0]));
    key->key_left = str_copy("^EOC");
    key->key_right = str_copy("^EOD");
    key->key_turn = str_copy("^EOA");
    key->key_drop = str_copy("^EOB");
    key->key_quit = str_copy("q");
    key->key_pause = str_copy("p");
    key->next = false;
    key->debug = false;
    key->lvl = 1;
    key->size = str_copy("20*10");
    return (0);
}