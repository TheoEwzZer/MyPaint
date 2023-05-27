/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void draw_circle_tool2(var_t *var, unsigned int i,
unsigned int j, sfColor color)
{
    unsigned int radius = (var->mouse_x - var->start.x) / 2;
    unsigned int x0 = var->start.x + radius;
    unsigned int y0 = var->start.y + radius;
    unsigned int dx = i - x0;
    unsigned int dy = j - y0;

    if (dx * dx + dy * dy <= radius * radius
    && dx * dx + dy * dy >= (radius - var->size) * (radius - var->size))
        sfImage_setPixel(DRAWING->image, i, j, color);
}

void draw_circle_tool(var_t *var, sfColor color)
{
    var->start.x = (unsigned int)var->first_point.x;
    var->start.y = (unsigned int)var->first_point.y;

    if (var->mouse_x < var->start.x)
        swap(&var->mouse_x, &var->start.x);
    if (var->mouse_y < var->start.y)
        swap(&var->mouse_y, &var->start.y);
    for (unsigned int i = var->start.x; i < var->mouse_x; i++) {
        for (unsigned int j = var->start.y; j < var->mouse_y; j++)
            draw_circle_tool2(var, i, j, color);
    }
}

void draw_circle2(var_t *var, unsigned int i, unsigned int j, sfColor color)
{
    unsigned int radius = var->size / 2;
    unsigned int x0 = var->mouse_x + radius;
    unsigned int y0 = var->mouse_y + radius;
    unsigned int dx = i - x0;
    unsigned int dy = j - y0;

    if (dx * dx + dy * dy <= radius * radius)
        sfImage_setPixel(DRAWING->image, i, j, color);
}

void draw_circle(var_t *var, sfColor color)
{
    for (unsigned int i = var->mouse_x; i < var->mouse_x + var->size; i++) {
        for (unsigned int j = var->mouse_y; j < var->mouse_y + var->size; j++)
            draw_circle2(var, i, j, color);
    }
}
