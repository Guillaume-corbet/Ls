/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** max
*/

#include "my_ls.h"

void weight(ls_t *ls)
{
    ls->block = 0;
    ls->a = 0;
    while (ls->a != ls->p_list->length + 2) {
        if (ls->a < ls->p_list->length)
            ls->block = ls->block + ls->p_list->p_head->sb.st_blocks / 2;
        if (ls->p_list->p_head->sb.st_size > ls->max)
            ls->max = ls->p_list->p_head->sb.st_size;
        ls->sd = ls->p_list->p_head->sd;
        ls->sb = ls->p_list->p_head->sb;
        dlist_remove(ls->p_list, 1);
        dlist_append(ls->p_list, ls->sd, ls->sb);
        ls->a = ls->a + 1;
    }
    ls->max = my_strlen(int_to_str(ls->max));
}

void length_link(ls_t *ls)
{
    ls->a = 0;
    while (ls->a != ls->p_list->length + 2) {
        if (ls->p_list->p_head->sb.st_nlink > ls->max_link)
            ls->max_link = ls->p_list->p_head->sb.st_nlink;
        ls->sd = ls->p_list->p_head->sd;
        ls->sb = ls->p_list->p_head->sb;
        dlist_remove(ls->p_list, 1);
        dlist_append(ls->p_list, ls->sd, ls->sb);
        ls->a = ls->a + 1;
    }
    ls->max_link = my_strlen(int_to_str(ls->max_link));
}

void length_user(ls_t *ls)
{
    struct passwd *pa;
    ls->a = 0;
    pa = getpwuid(ls->p_list->p_head->sb.st_uid);
    while (ls->a != ls->p_list->length + 2) {
        if (my_strlen(pa->pw_name) > ls->max_user)
            ls->max_user = my_strlen(pa->pw_name);
        ls->sd = ls->p_list->p_head->sd;
        ls->sb = ls->p_list->p_head->sb;
        dlist_remove(ls->p_list, 1);
        dlist_append(ls->p_list, ls->sd, ls->sb);
        ls->a = ls->a + 1;
    }
}

void length_group(ls_t *ls)
{
    struct group *gr;
    ls->a = 0;
    gr = getgrgid(ls->p_list->p_head->sb.st_gid);
    while (ls->a != ls->p_list->length + 2) {
        if (my_strlen(gr->gr_name) > ls->max_group)
            ls->max_group = my_strlen(gr->gr_name);
        ls->sd = ls->p_list->p_head->sd;
        ls->sb = ls->p_list->p_head->sb;
        dlist_remove(ls->p_list, 1);
        dlist_append(ls->p_list, ls->sd, ls->sb);
        ls->a = ls->a + 1;
    }
}