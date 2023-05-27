/*
** EPITECH PROJECT, 2023
** check_color
** File description:
** check_color
*/

#include "my_paint.h"

void check_color_click4(var_t *var, sfEvent event)
{
    if (IS_CLICKED(var->color->green)) {
        var->actu_color = sfGreen;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->green->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    if (IS_CLICKED(var->color->yellow)) {
        var->actu_color = sfYellow;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->yellow->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
}

void check_color_click3(var_t *var, sfEvent event)
{
    if (IS_CLICKED(var->color->magenta)) {
        var->actu_color = sfMagenta;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->magenta->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    if (IS_CLICKED(var->color->cyan)) {
        var->actu_color = sfCyan;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->cyan->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    check_color_click4(var, event);
}

void check_color_click2(var_t *var, sfEvent event)
{
    if (IS_CLICKED(var->color->blue)) {
        var->actu_color = sfBlue;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->blue->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    if (IS_CLICKED(var->color->white)) {
        var->actu_color = sfWhite;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->white->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    check_color_click3(var, event);
}

void check_color_click(var_t *var, sfEvent event)
{
    if (IS_CLICKED(var->color->black)) {
        var->actu_color = sfBlack;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->black->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    if (IS_CLICKED(var->color->red)) {
        var->actu_color = sfRed;
        reset_color(var);
        SET_OUTLINECOLOR(var->color->red->rect, sfBlack);
        if (var->rect_tool)
            SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        if (var->circle_tool)
            sfCircleShape_setOutlineColor(var->circle, var->actu_color);
    }
    check_color_click2(var, event);
}
