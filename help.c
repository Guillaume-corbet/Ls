/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** help
*/

#include "my_ls.h"

char *int_to_str(int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
        nb = nb / 10;
        a = a + 1;
    }
    str[a] = '\0';
    str = my_revstr(str);
    return (str);
}

char *decimal_to_octal(int nb)
{
    char *str;
    int tmp = 0;
    int i = 0;

    str = malloc(sizeof(char) * 100);
    while (i != 99) {
        str[i] = '\0';
        i = i + 1;
    }
    i = 0;
    while (nb > 0) {
        tmp = nb % 8;
        nb = nb / 8;
        str[i] = tmp + 48;
        i = i + 1;
    }
    str = my_revstr(str);
    return (str);
}