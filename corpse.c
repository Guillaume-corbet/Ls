/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** corpse
*/

#include "my_ls.h"

void corpse_first(ls_t *ls, int argc, char **argv)
{
    while (ls->counter != ls->det_a) {
        if (ls->options[ls->counter] == 't' && ls->p_list->length > 1) {
            algo_v2(ls);
            algo_v2_sec(ls);
            ls->counter = ls->det_a - 1;
        }
        ls->counter = ls->counter + 1;
    }
    ls->counter = 0;
    while (ls->counter != ls->det_a) {
        if (ls->options[ls->counter] == 'r') {
            reverse(ls);
            ls->counter = ls->det_a - 1;
        }
        ls->counter = ls->counter + 1;
    }
}

void corpse(ls_t *ls, int argc, char **argv)
{
    weight(ls);
    length_group(ls);
    length_user(ls);
    length_link(ls);
    ls->count_letter = 0;
    ls->counter = 0;
    corpse_first(ls, argc, argv);
    ls->counter = 0;
    while (ls->counter != ls->det_a) {
        if (ls->options[ls->counter] == 'l') {
            long_main(ls);
            ls->counter = ls->det_a - 1;
            ls->count_letter = 1;
        }
        ls->counter = ls->counter + 1;
    }
    if (ls->count_letter != 1) {
        alone(ls);
    }
}