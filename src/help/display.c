/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void display_help_menu(var_t *var)
{
    options_t *current_option = TOOL->help_menu->options;

    DRAW_RECT(TOOL->help_menu->button->rect);
    DRAW_TEXT(TOOL->help_menu->button->text);
    while (current_option && TOOL->help_menu->button->state == PRESSED) {
        DRAW_RECT(current_option->option->rect);
        DRAW_TEXT(current_option->option->text);
        current_option = current_option->next;
    }
}

void display_tool_menu(var_t *var)
{
    options_t *current_option = TOOL->tool_menu->options;

    DRAW_RECT(TOOL->tool_menu->button->rect);
    DRAW_TEXT(TOOL->tool_menu->button->text);
    while (current_option && TOOL->tool_menu->button->state == PRESSED) {
        DRAW_RECT(current_option->option->rect);
        DRAW_TEXT(current_option->option->text);
        current_option = current_option->next;
    }
}

void display_help_popup(var_t *var)
{
    DRAW_RECT(RECT_HELP);
    DRAW_TEXT(TEXT_HELP);
    DRAW_RECT(var->close_help->rect);
}

void display_about_popup(var_t *var)
{
    DRAW_RECT(RECT_ABOUT);
    DRAW_TEXT(TEXT_ABOUT);
    DRAW_RECT(var->close_about->rect);
}
