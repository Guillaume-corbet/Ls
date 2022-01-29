/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "my_ls.h"

void dlist_append_second(rlist *p_list, struct node *p_new)
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

void dlist_append(rlist *p_list, struct dirent *sd, struct stat sb)
{
    if (p_list != NULL) {
        struct node *p_new = malloc(sizeof(*p_new));
        if (p_new != NULL) {
            p_new->sd = sd;
            p_new->sb = sb;
            p_new->p_next = NULL;
            dlist_append_second(p_list, p_new);
        }
    }
}

void dlist_prepend_second(rlist *p_list, struct node *p_new)
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

void dlist_prepend(rlist *p_list, struct dirent *sd, struct stat sb)
{
    if (p_list != NULL) {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL) {
            p_new->sd = sd;
            p_new->sb = sb;
            p_new->p_prev = NULL;
            dlist_prepend_second(p_list, p_new);
        }
    }
}