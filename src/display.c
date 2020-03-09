/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

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

void set_up_key(keyt_t *key)
{
    key->key_left = str_copy("ˆEOC");
    key->key_right = str_copy("ˆEOD");
    key->key_turn = str_copy("ˆEOA");
    key->key_drop = str_copy("ˆEOB");
    key->key_quit = str_copy("q");
    key->key_pause = str_copy("(space)");
    key->next = false;
    key->debug = false;
    key->lvl = 1;
    key->size = str_copy("20*10");
}