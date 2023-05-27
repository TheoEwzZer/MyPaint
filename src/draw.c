/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void change_pixel2(var_t *var, sfColor color)
{
    if (var->line_tool) {
        if (!var->first_point_choose) {
            var->first_point.x = (float)var->mouse_x;
            var->first_point.y = (float)var->mouse_y;
        } else
            draw_line(var, color);
        var->first_point_choose = !var->first_point_choose;
        return;
    }
    if (var->brush == SQUARE)
        draw_square(var, color);
    if (var->brush == CIRCLE)
        draw_circle(var, color);
}

void change_pixel(var_t *var, sfColor color)
{
    if (var->rect_tool) {
        if (!var->first_point_choose) {
            var->first_point.x = (float)var->mouse_x;
            var->first_point.y = (float)var->mouse_y;
        } else
            draw_rectangle(var, color);
        var->first_point_choose = !var->first_point_choose;
        return;
    } if (var->circle_tool) {
        if (!var->first_point_choose) {
            var->first_point.x = (float)var->mouse_x;
            var->first_point.y = (float)var->mouse_y;
        } else
            draw_circle_tool(var, color);
        var->first_point_choose = !var->first_point_choose;
        return;
    }
    change_pixel2(var, color);
}

void draw(var_t *var, sfEvent event)
{
    var->mouse_x = ((unsigned int)event.mouseMove.x
    - (var->size / 2)) / var->zoom;
    var->mouse_y = ((unsigned int)event.mouseMove.y
    - (var->size / 2) - 50) / var->zoom;

    if (var->mouse_x > 0 && var->mouse_y > 0
    && var->mouse_x + var->size < sfImage_getSize(DRAWING->image).x
    && var->mouse_y + var->size < sfImage_getSize(DRAWING->image).y) {
        var->is_active = sfFalse;
        if (sfMouse_isButtonPressed(sfMouseRight))
            change_pixel(var, sfWhite);
        else
            change_pixel(var, var->actu_color);
    }
}
