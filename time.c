/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** time
*/

#include "my_ls.h"

void tea(ls_t *ls)
{
    ls->a = 0;
    ls->max_time = 0;
    while (ls->a != ls->p_list->length) {
        if (ls->p_list->p_head->sb.st_mtime > ls->max_time)
            ls->max_time = ls->p_list->p_head->sb.st_mtime;
        ls->sd = ls->p_list->p_head->sd;
        ls->sb = ls->p_list->p_head->sb;
        dlist_remove(ls->p_list, 1);
        dlist_append(ls->p_list, ls->sd, ls->sb);
        ls->a = ls->a + 1;
    }
}