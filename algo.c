/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** algo
*/

#include "my_ls.h"

int algo_v2(ls_t *ls)
{
    tea(ls);
    while (ls->p_list->p_head->sb.st_mtime != ls->max_time)
        rotate_left(ls->p_list);
    super_swap(ls->p_list, ls->p_list2);
    if (ls->p_list->length != 1)
        algo_v2(ls);
    return (0);
}

void algo_v2_sec(ls_t *ls)
{
    super_swap(ls->p_list, ls->p_list2);
    while (ls->p_list2->length != 0)
        super_swap(ls->p_list2, ls->p_list);
}
