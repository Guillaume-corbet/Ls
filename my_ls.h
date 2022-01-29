/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include "lib/my/my.h"
#include "lib/my_printf/my_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

struct node
{
    struct dirent *sd;
    struct stat sb;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
}rlist;

struct node_str
{
    char *str;
    struct node_str *p_next;
    struct node_str *p_prev;
};

typedef struct dlist_str
{
    size_t length;
    struct node_str *p_tail;
    struct node_str *p_head;
}rlist_str;

typedef struct my_ls_t
{
    int max_user;
    int max_group;
    int max_link;
    int wri;
    int fonc;
    int super_count;
    int block;
    int counter;
    int count_d;
    int count_letter;
    int count;
    int max;
    int max_time;
    int a;
    int i;
    int now;
    int change;
    int det_i;
    int det_a;
    int det_z;
    int zoulou;
    char *hello;
    char *time;
    char *mode;
    char *options;
    char *concat;
    DIR *dir;
    struct dirent *sd;
    struct stat sb;
    rlist *p_list;
    rlist *p_list2;
    rlist_str *p_list_str;
    struct passwd *pa;
    struct group *gr;
}ls_t;

rlist *dlist_new(void);
void dlist_remove_third(rlist *, struct node *, int, int);
void dlist_remove_second(rlist *, struct node *, int);
void dlist_remove(rlist *, int);
void dlist_append_second(rlist *, struct node *);
void dlist_append(rlist *, struct dirent *, struct stat);
void dlist_prepend_second(rlist*, struct node *);
void dlist_prepend(rlist *, struct dirent *, struct stat);
void first_cols(ls_t *);
void permission(ls_t *);
void user(ls_t *);
void size(ls_t *);
void display_time(ls_t *);
void name(ls_t *);
char *int_to_str(int nb);
char *decimal_to_octal(int nb);
void weight(ls_t *ls);
void all_init(ls_t *ls);
int init(ls_t *ls, int, char *);
void swap(rlist *);
void super_swap(rlist *, rlist *);
void rotate_left(rlist *);
void rotate_right(rlist *);
void long_main(ls_t *);
void tea(ls_t *);
int algo_v2(ls_t *);
void algo_v2_sec(ls_t *);
void alone(ls_t *);
void reverse(ls_t *);
void path(ls_t *);
void determine_option_second(ls_t *, char **);
void determine_option(ls_t *, int, char **);
void corpse(ls_t *, int, char **);
void corpse_first(ls_t *, int, char **);
int my_ls(int, char **);
rlist_str *dlist_new_str(void);
void dlist_remove_third_str(rlist_str *, struct node_str *, int, int);
void dlist_remove_second_str(rlist_str *, struct node_str *, int);
void dlist_remove_str(rlist_str *, int);
void dlist_append_second_str(rlist_str *, struct node_str *);
void dlist_append_str(rlist_str *, char *);
void dlist_prepend_second_str(rlist_str *, struct node_str *);
void dlist_prepend_str(rlist_str *, char *);
void weight(ls_t *);
void length_link(ls_t *);
void length_user(ls_t *);
void length_group(ls_t *);
void link_l(ls_t *);
void empty(ls_t *);

#endif /* !MY_LS_H_ */
