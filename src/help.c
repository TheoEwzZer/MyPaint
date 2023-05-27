/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

int help(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        my_putstr("USAGE\n");
        my_putstr("\t./my_paint \n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tmy_paint is a simple graphics editor that took is\n");
        my_putstr("\tinspiration from the real Microsoft's paint\n");
        my_putstr("created by Théo Fabiano et Théo Maestracci\n");
        return 1;
    }
    return 0;
}
