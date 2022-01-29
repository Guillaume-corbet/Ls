/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** long
*/

#include "my_ls.h"

void long_main(ls_t *ls)
{
    my_printf("total ");
    my_put_nbr(ls->block);
    my_putchar('\n');
    while (ls->p_list->length != 0) {
        first_cols(ls);
        permission(ls);
        user(ls);
        size(ls);
        display_time(ls);
        name(ls);
        ls->i = 4;
        dlist_remove(ls->p_list, 1);
    }
}

void first_cols(ls_t *ls)
{
    ls->mode = decimal_to_octal(ls->p_list->p_head->sb.st_mode);
    ls->mode = ls->mode + 3;
    ls->a = 0;
    if (ls->p_list->p_head->sd->d_type == 4)
        my_putchar('d');
    else
        my_putchar('-');
}

void permission(ls_t *ls)
{
    my_printf((ls->p_list->p_head->sb.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IROTH) ? "r" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((ls->p_list->p_head->sb.st_mode & S_IXOTH) ? "x" : "-");
    my_printf(" ");
}

void link_l(ls_t *ls)
{
    ls->pa = getpwuid(ls->p_list->p_head->sb.st_uid);
    ls->gr = getgrgid(ls->p_list->p_head->sb.st_gid);
    ls->a = my_strlen(int_to_str(ls->p_list->p_head->sb.st_nlink));
    if (ls->a == 0)
        ls->a = 1;
    my_put_nbr(ls->p_list->p_head->sb.st_nlink);
    while (ls->a != ls->max_link + 1) {
        my_putchar(' ');
        ls->a = ls->a + 1;
    }
}

void user(ls_t *ls)
{
    link_l(ls);
    ls->a = my_strlen(ls->pa->pw_name);
    if (ls->a == 0)
        ls->a = 1;
    my_putstr(ls->pa->pw_name);
    while (ls->a != ls->max_user + 1) {
        my_putchar(' ');
        ls->a = ls->a + 1;
    }
    ls->a = my_strlen(ls->gr->gr_name);
    if (ls->a == 0)
        ls->a = 1;
    my_putstr(ls->gr->gr_name);
    while (ls->a != ls->max_group + 1) {
        my_putchar(' ');
        ls->a = ls->a + 1;
    }
}