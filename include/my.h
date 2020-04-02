/*
** EPITECH PROJECT, 2019
** my
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <stdbool.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <ncurses.h>

typedef struct format_t
{
    char c;
    void (*ptr)(va_list);
} format_t;

typedef struct forms_s
{
    char **form;
    struct forms_s *next;
} forms_t;

typedef struct gaming_s
{
    int pos_x;
    int pos_y;
    char **tab;
    int length;
    bool is_blocked;
    struct gaming_s *next;
} gaming_t;

typedef struct store_s
{
    char **tetriminos;
    int nb_tetriminos;
    forms_t *forms;
}store_t;

typedef struct keyt_s
{
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    bool next;
    bool debug;
    int lvl;
    int help;
    char *size;
}keyt_t;

typedef enum
{
    MENU,
    BOARD,
    NEXT,
    INFOS,
    TOTAL
} WIN;

typedef struct window_s
{
    WIN index;
    WINDOW *window;
    int height;
    int width;
    int position_x;
    int position_y;
    void (*display)(WINDOW *, int, gaming_t *, char **);
} window_t;

typedef struct storage_s
{
    window_t **windows;
    char **tab;
}storage_t;

char **get_next_tab(int rng, store_t *store);
int check_for_collision(gaming_t *gaming);
int analyse_input(int b, gaming_t *gaming, store_t *store, storage_t *storage);
void add_random_form(gaming_t **gaming, store_t *store, int rng);
void add_to_gaming(gaming_t **gaming, int pos[2], int length, char **tab);
void create_windows(storage_t *store);
void loop_game(keyt_t *key, store_t *store);
void options(int ac, char **av, keyt_t *key);
int check_order(char **tab, int save, int winner);
int set_up_key(keyt_t *key, int ac, char *av[]);
int ascii_order(store_t *store);
void final_print(char **tab, char **first_line, \
int check_same, store_t *store);
int read_and_print(char *str, store_t *store);
void update_tab_and_display(store_t *store);
void display_blocks(store_t *store);
int check_finish(char **map);
void reading_folder(DIR *fd, store_t *store);
void my_memset(char *buffer, char c, int number);
int    my_putnbr_base(int nbr, char const *base);
int    my_compute_power_rec(int nb, int p);
int    my_compute_square_root(int nb);
int    my_find_prime_sup(int nb);
int    my_getnbr(char const *str);
int    my_isneg(int n);
int    my_is_prime(int nb);
int    my_lengh(char const *str);
char    **my_malloc_words(char const *str, char **tab);
void    my_putchar(char c);
void    my_put_nbr(int nb);
int     my_putstr(char const *str);
char    *my_revstr(char *str);
int    my_showmem(char const *str, int size);
int    my_showstr(char const *str);
int    my_show_word_array(char * const *tab);
void    my_sort_int_array(int *tab, int size);
char    *my_strcapitalize(char *str);
char     *my_strcat(char *src, char *dest);
char    my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char const *src);
char    *my_strcpy2(char *dest, char const *src);
char    *my_strdup(char const *src);
int    my_str_isalpha(char const *str);
int    my_str_islower(char const *str);
int    my_str_isnum(char const *str);
int    my_str_isprintable(char const *str);
int    my_str_isupper(char const *str);
int    my_strlen(char const *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char const *src, int nb);
int    my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strstr(char *str, char const *to_find);
char    **my_str_to_word_array(char const *str, char *operator);
char    *my_strupcase(char *str);
void    my_swap(int *a, int *b);
int    my_prime(int nb);
int    my_strlen4(char const *str);
void    my_swap3(char const *dest, char const *src);
void    **my_malloc_word(char const *str, char * const *tab);
int    my_word_number(char const *str);
char   **my_word_in_tab(char const *str, char *const *tab);
int    my_str_neg(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_str_is_negative(char *str);
char    *my_str_delete_null(char *str);
char    *my_cpy_without_null(char *str, char *cpy, int letter, int zero);
char    *my_supr_null(char *str, char *cpy, int letter);
char    *my_str_is_easy(char *str, char *cpy);
int    my_int_nbr(char const *str, int letter, int size, char **endptr);
int    my_delete_non_null(char const *str);
int    my_str_tol_error(char const *str);
char    *my_infin_add(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_infin_cmp(char *str, char *str2);
char *my_supr_same(char *str, char *strtemp);
char *my_delete_neg(char *str);
char *my_strtemp(char *str, char *div);
int my_mult_zero(char *mult);
char *my_add_x_zero(int cursor);
int    my_clean_add_total(char *str, char *mult);
char *my_delete_mult(char *mult);
char *my_zeroo(char *str, char *mult);
char *my_infin_tol(char *str, char **endptr);
int my_bistro_error(int ac, char **av, char *buff);
char *my_infin_sub(char *str, char *str2);
int my_occ(char *str);
void my_putchar(char c);
void my_print_s(va_list ap);
void my_print_c(va_list ap);
void my_print_d(va_list ap);
void my_print_p(va_list ap);
void my_print_x(va_list ap);
void my_print_upcase_x(va_list ap);
void my_print_o(va_list ap);
void my_print_b(va_list ap);
void my_print_u(va_list ap);
void my_print_upcase_s(va_list ap);
void my_printf(char *format, ...);
void display_key(keyt_t *key);
char *str_copy(char *enter);
int check_order(char **tab, int save, int winner);
void test_key_four(keyt_t *key, char opt, char *name);
void test_key_tree(keyt_t *key, char opt, char *name);
void test_key_two(keyt_t *key, char opt, char *name);
void test_key_one(keyt_t *key, char opt, char *name);
int display_usage(char *name);

#endif /* MY_H_ */
