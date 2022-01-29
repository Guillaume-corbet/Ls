/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** main
*/

#include "my_ls.h"

void path(ls_t *ls)
{
    my_putstr(ls->hello);
}

void empty(ls_t *ls)
{
    ls->counter = 0;
    while (ls->counter != ls->det_a) {
        if (ls->options[ls->counter] == 'l') {
            my_printf("total 0\n");
            ls->counter = ls->det_a - 1;
            ls->count_letter = 1;
        }
        ls->counter = ls->counter + 1;
    }
}

int my_ls(int argc, char **argv)
{
    ls_t *ls;

    ls = malloc(sizeof(ls_t));
    all_init(ls);
    determine_option(ls, argc, argv);
    ls->wri = ls->p_list_str->length;
    while (ls->p_list_str->length > 0) {
        if (ls->wri > 1)
            my_printf("%s:\n", ls->p_list_str->p_head->str);
        init(ls, argc, argv[2]);
        if (ls->p_list->length > 0) {
            corpse(ls, argc, argv);
        } else
            empty(ls);
        closedir(ls->dir);
        dlist_remove_str(ls->p_list_str, 1);
        ls->fonc = 1;
        if (ls->wri > 1 && ls->p_list_str->length > 0)
            my_putchar('\n');
    }
    return (0);
}

int main(int argc, char **argv)
{
    my_ls(argc, argv);
    return (0);
}