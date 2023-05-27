/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void check_tools_click(var_t *var, sfEvent event)
{
    if (IS_CLICKED(TOOL->rectangle)) {
        reset_tool(var);
        var->rect_tool = sfTrue;
        SET_OUTLINECOLOR(TOOL->rectangle->rect, var->actu_color);
        var->first_point_choose = sfFalse;
        var->is_active = sfFalse;
    } if (IS_CLICKED(TOOL->circle)) {
        reset_tool(var);
        var->circle_tool = sfTrue;
        sfCircleShape_setOutlineColor(var->circle, var->actu_color);
        var->first_point_choose = sfFalse;
        var->is_active = sfFalse;
    } if (IS_CLICKED(TOOL->line)) {
        reset_tool(var);
        var->line_tool = sfTrue;
        SET_OUTLINECOLOR(TOOL->line->rect, var->actu_color);
        var->first_point_choose = sfFalse;
        var->is_active = sfFalse;
    }
}

void check_size_click(var_t *var, sfEvent event)
{
    IS_CLICKED(TOOL->size_menu->button);
    if (TOOL->size_menu->button->state == PRESSED) {
        if (IS_CLICKED(TOOL->size_menu->options->option)) {
            var->size = 8;
            TOOL->size_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        } if (IS_CLICKED(TOOL->size_menu->options->next->option)) {
            var->size = 5;
            TOOL->size_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        } if (IS_CLICKED(TOOL->size_menu->options->next->next->option)) {
            var->size = 3;
            TOOL->size_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        } if (IS_CLICKED(TOOL->size_menu->options->next->next->next->option)) {
            var->size = 1;
            TOOL->size_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        }
    }
}

void check_brush_click(var_t *var, sfEvent event)
{
    IS_CLICKED(TOOL->brush_menu->button);
    if (TOOL->brush_menu->button->state == PRESSED) {
        if (IS_CLICKED(TOOL->brush_menu->options->option)) {
            var->brush = SQUARE;
            TOOL->brush_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        }
        if (IS_CLICKED(TOOL->brush_menu->options->next->option)) {
            var->brush = CIRCLE;
            TOOL->brush_menu->button->state = RELEASED;
            var->is_active = sfFalse;
        }
    }
}

void check_click(var_t *var, sfEvent event)
{
    push(var->undo_stack, sfImage_copy(DRAWING->image));
    var->mousePressed = sfTrue;
    check_color_click(var, event);
    check_tools_click(var, event);
    if (IS_CLICKED(var->close_help))
        var->help_popup->is_active = false;
    else if (IS_CLICKED(var->close_about))
        var->about_popup->is_active = false;
    check_size_click(var, event);
    check_brush_click(var, event);
    check_file_click(var, event);
    check_tool_click(var, event);
    IS_CLICKED(TOOL->help_menu->button);
    if (TOOL->help_menu->button->state == PRESSED) {
        if (IS_CLICKED(TOOL->help_menu->options->option)) {
            var->help_popup->is_active = true; var->is_active = sfFalse;
        } if (IS_CLICKED(TOOL->help_menu->options->next->option)) {
            var->about_popup->is_active = true; var->is_active = sfFalse;
        }
    }
}

void events(var_t *var, sfEvent event)
{
    switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(var->window); break;
        case sfEvtMouseButtonReleased:
            var->mousePressed = sfFalse; break;
        case sfEvtMouseMoved:
            if (var->mousePressed && !HELP_POPUP && !ABOUT_POPUP)
                draw(var, event);
            break;
        case sfEvtMouseButtonPressed:
            check_click(var, event);
            draw_point(var, event); break;
        case sfEvtKeyPressed:
            undo_redo(var, event);
            zoom_key(var, event); break;
        case sfEvtMouseWheelScrolled:
            zoom_wheel(var, event); break;
        default:
            break;
    }
}
