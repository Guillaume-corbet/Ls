/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** move
*/

#include "my_ls.h"

void swap(rlist *p_list)
{
    struct dirent *data;
    struct dirent *data2;
    struct stat oth;
    struct stat oth2;

    data = p_list->p_head->sd;
    oth = p_list->p_head->sb;
    data2 = p_list->p_head->p_next->sd;
    oth2 = p_list->p_head->p_next->sb;
    dlist_remove(p_list, 1);
    dlist_remove(p_list, 1);
    dlist_prepend(p_list, data, oth);
    dlist_prepend(p_list, data2, oth2);
}

void super_swap(rlist *less, rlist *more)
{
    struct dirent *data;
    struct stat oth;

    data = less->p_head->sd;
    oth = less->p_head->sb;
    dlist_remove(less, 1);
    dlist_prepend(more, data, oth);
}

void rotate_left(rlist *p_list)
{
    struct dirent *data;
    struct stat oth;

    data = p_list->p_head->sd;
    oth = p_list->p_head->sb;
    dlist_remove(p_list, 1);
    dlist_append(p_list, data, oth);
}

void rotate_right(rlist *p_list)
{
    struct dirent *data;
    struct stat oth;

    data = p_list->p_tail->sd;
    oth = p_list->p_head->sb;
    dlist_remove(p_list, p_list->length);
    dlist_prepend(p_list, data, oth);
}