/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void draw_point(var_t *var, sfEvent event)
{
    var->mouse_x = ((unsigned int)event.mouseButton.x
    - (var->size / 2)) / var->zoom;
    var->mouse_y = ((unsigned int)event.mouseButton.y
    - (var->size / 2) - 50) / var->zoom;

    if (var->mouse_x > 0 && var->mouse_y > 0
    && var->mouse_x + var->size < sfImage_getSize(DRAWING->image).x
    && var->mouse_y + var->size < sfImage_getSize(DRAWING->image).y) {
        if (sfMouse_isButtonPressed(sfMouseRight))
            change_pixel(var, sfWhite);
        else
            change_pixel(var, var->actu_color);
    }
}
