/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void draw_line2(var_t *var, sfColor color)
{
    for (int i = LINE->start.x; i <= LINE->end.x; i++) {
        for (int j = LINE->start.y; j <= LINE->end.y; j++)
            sfImage_setPixel(
                DRAWING->image, (unsigned int)i, (unsigned int)j, color
            );
    }
    LINE->error2 = 2 * LINE->error;
    if (LINE->error2 > -LINE->diff.y) {
        LINE->error -= LINE->diff.y;
        LINE->pos.x += LINE->step.x;
        LINE->start.x += LINE->step.x;
        LINE->end.x += LINE->step.x;
    }
    if (LINE->error2 < LINE->diff.x) {
        LINE->error += LINE->diff.x;
        LINE->pos.y += LINE->step.y;
        LINE->start.y += LINE->step.y;
        LINE->end.y += LINE->step.y;
    }
}

void draw_line(var_t *var, sfColor color)
{
    var->start.x = (unsigned int)var->first_point.x;
    var->start.y = (unsigned int)var->first_point.y;
    LINE->diff.x = (int)(var->mouse_x - var->start.x);
    LINE->diff.y = (int)(var->mouse_y - var->start.y);
    LINE->step.x = (LINE->diff.x > 0) ? 1 : -1;
    LINE->step.y = (LINE->diff.y > 0) ? 1 : -1;
    LINE->error2 = 0;
    LINE->pos.x = (int)var->start.x;
    LINE->pos.y = (int)var->start.y;
    LINE->start.x = (int)(var->start.x - var->size / 2);
    LINE->end.x = (int)(var->start.x + var->size / 2);
    LINE->start.y = (int)(var->start.y - var->size / 2);
    LINE->end.y = (int)(var->start.y + var->size / 2);
    LINE->diff.x = abs(LINE->diff.x);
    LINE->diff.y = abs(LINE->diff.y);
    LINE->error = LINE->diff.x - LINE->diff.y;
    while (LINE->pos.x != (int)var->mouse_x || LINE->pos.y != (int)var->mouse_y)
        draw_line2(var, color);
}
