/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** good_print.c
*/

#include "../include/my.h"
#include "../include/garbage_collector.h"

void add_form(forms_t **forms, char **tab)
{
    forms_t *new = my_malloc(sizeof(forms_t));
    forms_t *copy = *forms;

    new->form = tab;
    new->next = NULL;
    if (!copy) {
        *forms = new;
        return;
    }
    while (copy->next)
        copy = copy->next;
    copy->next = new;
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

int my_special_len(char *str)
{
    int len = 0;
    int index = my_strlen(str) - 1;

    if (index < 0)
        return (0);
    while (index >= 0 && str[index] == ' ')
        index -= 1;
    if (index < 0)
        return (my_strlen(str));
    while (index >= 0) {
        index -= 1;
        len += 1;
    }
    return (len);
}

void check_last_error(char **tab, char **first_line, store_t *store)
{
    int len_tab = 0;
    int color = my_getnbr(first_line[2]);

    if (color > 10) {
        my_printf("Error\n");
        return;
    }
    for (; tab[len_tab]; len_tab += 1);
    if (len_tab - 1 != my_getnbr(first_line[1])) {
        my_printf("Error\n");
        return;
    }
    my_printf("Size %s*%s : Color %s :\n", first_line[0], \
    first_line[1], first_line[2]);
    add_form(&store->forms, &tab[1]);
    for (int index = 1; tab[index]; index += 1)
        my_printf("%s\n", tab[index]);
}

void final_print(char **tab, char **first_line, int check_same, store_t *store)
{
    int rows = my_getnbr(first_line[0]);
    int check_size = 0;

    for (int index = 1; tab[index]; index += 1) {
        for (int temp = 0; tab[index][temp]; temp += 1) {
            if (tab[index][temp] != '*' && tab[index][temp] != ' ') {
                my_printf("Error\n");
                return;
            }
        }
        if (my_special_len(tab[index]) == rows)
            check_same = 1;
        if (my_special_len(tab[index]) > rows)
            check_size = 1;
    }
    if (check_same == 0 || check_size == 1) {
        my_printf("Error\n");
        return;
    }
    check_last_error(tab, first_line, store);
}