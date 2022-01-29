/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** option
*/

#include "my_ls.h"

void determine_option_second(ls_t *ls, char **argv)
{
    while (argv[ls->det_i][ls->det_z] != '\0') {
        ls->options[ls->det_a] = argv[ls->det_i][ls->det_z];
        if (ls->options[ls->det_a] == 'd')
            ls->count_d = 1;
        ls->det_a = ls->det_a + 1;
        ls->det_z = ls->det_z + 1;
    }
    ls->det_z = 1;
}

void determine_option(ls_t *ls, int argc, char **argv)
{
    ls->p_list_str = dlist_new_str();
    ls->det_i = 1;
    ls->det_a = 0;
    ls->det_z = 1;
    int atchoum = 0;
    ls->count_d = 0;
    while (ls->det_i != argc) {
        if (argv[ls->det_i][0] == '-') {
            determine_option_second(ls, argv);
        } else {
            dlist_append_str(ls->p_list_str, argv[ls->det_i]);
        }
        ls->det_i = ls->det_i + 1;
    }
    if (ls->p_list_str->length == 0)
        dlist_append_str(ls->p_list_str, ".");
}