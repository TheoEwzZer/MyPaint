/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;

    *a = *b;
    *b = tmp;
}

void draw_rectangle2(var_t *var, unsigned int i, unsigned int j, sfColor color)
{
    if ((i >= var->start.x && i <= var->start.x + var->size)
    || (i >= var->mouse_x - var->size && i <= var->mouse_x)
    || (j >= var->start.y && j <= var->start.y + var->size)
    || (j >= var->mouse_y - var->size && j <= var->mouse_y))
        sfImage_setPixel(DRAWING->image, i, j, color);
}

void draw_rectangle(var_t *var, sfColor color)
{
    var->start.x = (unsigned int)var->first_point.x;
    var->start.y = (unsigned int)var->first_point.y;

    if (var->mouse_x < var->start.x)
        swap(&var->mouse_x, &var->start.x);
    if (var->mouse_y < var->start.y)
        swap(&var->mouse_y, &var->start.y);
    for (unsigned int i = var->start.x; i < var->mouse_x; i++) {
        for (unsigned int j = var->start.y; j < var->mouse_y; j++) {
            draw_rectangle2(var, i, j, color);
        }
    }
}

void draw_square(var_t *var, sfColor color)
{
    unsigned int rad = var->size / 2;

    for (unsigned int i = var->mouse_x - rad; i < var->mouse_x + rad; i++) {
        for (unsigned int j = var->mouse_y - rad; j < var->mouse_y + rad; j++)
            sfImage_setPixel(DRAWING->image, i, j, color);
    }
}
