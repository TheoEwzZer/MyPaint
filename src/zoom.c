/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void zoom_key(var_t *var, sfEvent event)
{
    if (event.key.control && event.key.code == sfKeyAdd && var->zoom < 101)
        var->zoom += 1;
    if (event.key.control && event.key.code == sfKeySubtract && var->zoom > 1)
        var->zoom -= 1;
}

void zoom_wheel(var_t *var, sfEvent event)
{
    if (event.mouseWheelScroll.delta > 0 && var->zoom < 101)
        var->zoom += 1;
    else if (event.mouseWheelScroll.delta < 0 && var->zoom > 1)
        var->zoom -= 1;
}
