/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void display_size_menu(var_t *var)
{
    options_t *current_option = TOOL->size_menu->options;

    if (var->is_active) {
        DRAW_RECT(TOOL->size_menu->button->rect);
        DRAW_TEXT(TOOL->size_menu->button->text);
        while (current_option && TOOL->size_menu->button->state == PRESSED) {
            DRAW_RECT(current_option->option->rect);
            DRAW_TEXT(current_option->option->text);
            current_option = current_option->next;
        }
    }
}

void display_brush_menu(var_t *var)
{
    options_t *current_option = TOOL->brush_menu->options;

    if (var->is_active) {
        DRAW_RECT(TOOL->brush_menu->button->rect);
        DRAW_TEXT(TOOL->brush_menu->button->text);
        while (current_option && TOOL->brush_menu->button->state == PRESSED) {
            DRAW_RECT(current_option->option->rect);
            DRAW_TEXT(current_option->option->text);
            current_option = current_option->next;
        }
    }
}

void display_colors(var_t *var)
{
    if (var->is_active && var->tool_select == PENCIL) {
        DRAW_RECT(var->color->black->rect);
        DRAW_RECT(var->color->white->rect);
        DRAW_RECT(var->color->red->rect);
        DRAW_RECT(var->color->green->rect);
        DRAW_RECT(var->color->blue->rect);
        DRAW_RECT(var->color->yellow->rect);
        DRAW_RECT(var->color->magenta->rect);
        DRAW_RECT(var->color->cyan->rect);
    }
}

void display_tools(var_t *var)
{
    if (var->is_active && var->tool_select == PENCIL) {
        DRAW_RECT(TOOL->rectangle->rect);
        DRAW_RECT(TOOL->line->rect);
        sfRenderWindow_drawCircleShape(var->window, var->circle, NULL);
    }
}
