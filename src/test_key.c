/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

void test_key_four(keyt_t *key, char opt)
{
    switch (opt)
    {
        case ('f') : {
            my_strlen(optarg) == 1 ? key->key_pause = optarg : 0;
            break;
        } case ('g') : {
            key->next = true;
            break;
        } case ('h') : {
            key->debug = true;
            break;
        } case ('m') : {
            key->lvl = my_getnbr(optarg);
            break;
        } default : {
            exit (84);
        }
    }
}

void test_key_tree(keyt_t *key, char opt)
{
    switch (opt)
    {
        case ('b') : {
            my_strlen(optarg) == 1 ? key->key_right = optarg : 0;
            break;
        } case ('c') : {
            my_strlen(optarg) == 1 ? key->key_turn = optarg : 0;
            break;
        } case ('k') : {
            my_strlen(optarg) == 1 ? key->key_drop = optarg : 0;
            break;
        } case ('e') : {
            my_strlen(optarg) == 1 ? key->key_quit = optarg : 0;
            break;
        } case ('a') : {
                my_strlen(optarg) == 1 ? key->key_left = optarg : 0;
                break;
        } default :
            test_key_four(key, opt);
    }
}

void test_key_two(keyt_t *key, char opt)
{
    switch (opt)
    {
        case ('q') : {
            my_strlen(optarg) == 1 ? key->key_quit = optarg : 0;
            break;
        } case ('p') : {
            my_strlen(optarg) == 1 ? key->key_pause = optarg : 0;
            break;
        } case ('w') : {
            key->next = true;
            break;
        } case ('D') : {
            key->debug = true;
            break;
        } case ('z') : {
            my_strlen(optarg) == 1 ? key->help = 1 : 0;
            break;
        } case ('a') : {
            my_strlen(optarg) == 1 ? key->key_left = optarg : 0;
            break;
        } default :
            test_key_tree(key, opt);
    }
}

void test_key_one(keyt_t *key, char opt)    
{
    switch (opt)
    {
        case ('L') : {
            key->lvl = my_getnbr(optarg);
            break;
        } case ('l') : {
            my_strlen(optarg) == 1 ? key->key_left = optarg : 0;
            break;
        } case ('r') : {
            my_strlen(optarg) == 1 ? key->key_right = optarg : 0;
            break;
        } case ('t') : {
            my_strlen(optarg) == 1 ? key->key_turn = optarg : 0;
            break;
        } case ('d') : {
            my_strlen(optarg) == 1 ? key->key_drop = optarg : 0;
            break;
        } default :
            test_key_two(key, opt);
    }
}