/*
** EPITECH PROJECT, 2023
** check_color
** File description:
** check_color
*/

#include "my_paint.h"

void reset_color(var_t *var)
{
    SET_OUTLINECOLOR(var->color->black->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->red->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->green->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->blue->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->white->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->yellow->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->magenta->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(var->color->cyan->rect, sfColor_fromRGB(245, 245, 245));
}

void reset_tool(var_t *var)
{
    SET_OUTLINECOLOR(TOOL->rectangle->rect, sfColor_fromRGB(245, 245, 245));
    SET_OUTLINECOLOR(TOOL->line->rect, sfColor_fromRGB(245, 245, 245));
    sfCircleShape_setOutlineColor(var->circle, sfColor_fromRGB(245, 245, 245));
    var->rect_tool = sfFalse;
    var->circle_tool = sfFalse;
    var->line_tool = sfFalse;
}
