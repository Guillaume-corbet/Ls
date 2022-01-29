/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** init
*/

#include "my_ls.h"

void all_init(ls_t *ls)
{
    ls->hello = malloc(sizeof(char) * 1000);
    ls->mode = malloc(sizeof(char) * 100);
    ls->options = malloc(sizeof(char) * 1000);
    ls->concat = malloc(sizeof(char) * 1000);
    ls->i = 4;
    ls->count = 0;
    ls->max = 0;
    ls->a = 0;
    ls->now = 0;
    ls->change = 0;
    ls->fonc = 0;
    ls->max_link = 0;
    ls->max_group = 0;
    ls->max_user = 0;
    ls->max_time = 0;
    ls->zoulou = 0;
}

void concatenate(ls_t *ls)
{
    ls->concat = my_strcpy(ls->concat, ls->p_list_str->p_head->str);
    ls->concat = my_strcat(ls->concat, "/");
    ls->concat = my_strcat(ls->concat, ls->sd->d_name);
}

int init(ls_t *ls, int argc, char *argv)
{
    if (ls->fonc == 0) {
        ls->p_list = dlist_new();
        ls->p_list2 = dlist_new();
    }
    ls->dir = opendir(ls->p_list_str->p_head->str);
    if (ls->dir == NULL) {
        my_putstr("ERROR");
        exit(1);
    }
    while ((ls->sd = readdir(ls->dir)) != NULL) {
        concatenate(ls);
        stat(ls->concat, &ls->sb);
        if (ls->sd->d_name[0] != '.' && ls->count_d != 1)
            dlist_append(ls->p_list, ls->sd, ls->sb);
        else if (ls->count_d == 1 && ls->sd->d_name[0] == '.')
            dlist_append(ls->p_list, ls->sd, ls->sb);
    }
    return (0);
}