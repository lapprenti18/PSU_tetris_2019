/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** read_file.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

void good_print(char **tab)
{
    int check_len = 0;
    char **first_line = NULL; 

    for (; tab[check_len]; check_len += 1);
    if (check_len <= 1) {
        my_printf("Error\n");
        return;
    }
    first_line = my_str_to_word_array(tab[0], " ");
    for (check_len = 0; first_line[check_len]; check_len += 1) {
        if (!my_str_isnum(first_line[check_len])) {
            my_printf("Error\n");
            return;
        }
    }
    if (check_len <= 1) {
        my_printf("Error\n");
        return;
    }
    final_print(tab, first_line, 0);
}

int read_and_print(char *str)
{
    char *buffer = NULL;
    struct stat st;
    int fd = 0;
    char **tab = NULL;

    str = my_strcat("tetriminos/", str);
    fd = open(str, O_RDONLY);
    if (!fd)
        return (84);
    stat(str, &st);
    buffer = my_malloc(sizeof(char) * st.st_size + 1);
    my_memset(buffer, 0, st.st_size + 1);
    if (read(fd, buffer, st.st_size) <= 0) {
        my_printf("Error\n");
        return (84);
    }
    tab = my_str_to_word_array(buffer, "\n");
    good_print(tab);
    return (0);
}

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