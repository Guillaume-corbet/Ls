/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** ls
*/

#include "my_ls.h"

void alone(ls_t *ls)
{
    while (ls->p_list->length != 0) {
        my_printf("%s\n", ls->p_list->p_head->sd->d_name);
        dlist_remove(ls->p_list, 1);
    }
}