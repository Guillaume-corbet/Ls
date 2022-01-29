/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "my_ls.h"

void dlist_append_second_str(rlist_str *p_list, struct node_str *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_prev = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_tail->p_next = p_new;
        p_new->p_prev = p_list->p_tail;
        p_list->p_tail = p_new;
    }
    p_list->length = p_list->length + 1;
}

void dlist_append_str(rlist_str *p_list, char *str)
{
    if (p_list != NULL) {
        struct node_str *p_new = malloc(sizeof(*p_new));
        if (p_new != NULL) {
            p_new->str = malloc(sizeof(char) * 100);
            p_new->str = str;
            p_new->p_next = NULL;
            dlist_append_second_str(p_list, p_new);
        }
    }
}

void dlist_prepend_second_str(rlist_str *p_list, struct node_str *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_next = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_head->p_prev = p_new;
        p_new->p_next = p_list->p_head;
        p_list->p_head = p_new;
    }
    p_list->length = p_list->length + 1;
}

void dlist_prepend_str(rlist_str *p_list, char *str)
{
    if (p_list != NULL) {
        struct node_str *p_new = malloc(sizeof *p_new);
        if (p_new != NULL) {
            p_new->str = malloc(sizeof(char) * 100);
            p_new->str = str;
            p_new->p_prev = NULL;
            dlist_prepend_second_str(p_list, p_new);
        }
    }
}