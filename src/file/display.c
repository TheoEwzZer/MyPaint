/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void display_file_menu(var_t *var)
{
    options_t *current_option = TOOL->file_menu->options;

    DRAW_RECT(TOOL->file_menu->button->rect);
    DRAW_TEXT(TOOL->file_menu->button->text);
    while (current_option && TOOL->file_menu->button->state == PRESSED) {
        DRAW_RECT(current_option->option->rect);
        DRAW_TEXT(current_option->option->text);
        current_option = current_option->next;
    }
}
