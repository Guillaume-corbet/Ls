/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** long_second
*/

#include "my_ls.h"

void size(ls_t *ls)
{
    ls->a = my_strlen(int_to_str(ls->p_list->p_head->sb.st_size));
    if (ls->a == 0)
        ls->a = 1;
    my_put_nbr(ls->p_list->p_head->sb.st_size);
    while (ls->a != ls->max + 1) {
        my_putchar(' ');
        ls->a = ls->a + 1;
    }
}

void display_time(ls_t *ls)
{
    ls->time = ctime(&ls->p_list->p_head->sb.st_mtime);
    while (ls->i != 16) {
        my_putchar(ls->time[ls->i]);
        ls->i = ls->i + 1;
    }
}

void name(ls_t *ls)
{
    if (ls->count_d == 1)
        my_printf(" %s%s%s", BLUE, ls->hello, RESET);
    else
        my_printf(" %s", ls->p_list->p_head->sd->d_name);
    my_putchar('\n');
}