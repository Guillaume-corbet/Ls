/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** reverse
*/

#include "my_ls.h"

void reverse(ls_t *ls)
{
    struct dirent *data;
    struct stat oth;

    while (ls->p_list->length != 0)
        super_swap(ls->p_list, ls->p_list2);
    while (ls->p_list2->length != 0) {
        data = ls->p_list2->p_head->sd;
        oth = ls->p_list2->p_head->sb;
        dlist_remove(ls->p_list2, 1);
        dlist_append(ls->p_list, data, oth);
    }
}