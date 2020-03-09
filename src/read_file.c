/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** read_file.c
*/

#include "../include/my.h"

void display_blocks(store_t *store)
{
    my_printf("Tetriminos: %d\n", store->nb_tetriminos);
    do {
        my_printf("Tetriminos: ");
        update_tab_and_display(store);
    } while (!check_finish(store->tetriminos));
}

int check_finish(char **map)
{
    for (int index = 0; map[index]; index += 1) {
        if (map[index][0] != '~')
            return (0);
    }
    return (1);
}

void reading_folder(DIR *fd, store_t *store)
{
    struct dirent *dirr = readdir(fd);
    int nb_tetris = 0;
    char *files = NULL;

    for (; dirr; dirr = readdir(fd)) {
        if (dirr->d_name[0] != '.') {
            nb_tetris += 1;
            files = my_strcat(files, dirr->d_name);
            files = my_strcat(files, "\n");
        }
    }
    store->nb_tetriminos = nb_tetris;
    store->tetriminos = my_str_to_word_array(files, "\n");
}