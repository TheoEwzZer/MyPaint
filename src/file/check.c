/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void check_file_click(var_t *var, sfEvent event)
{
    IS_CLICKED(TOOL->file_menu->button);
    if (TOOL->file_menu->button->state == PRESSED) {
        if (IS_CLICKED(TOOL->file_menu->options->option))
            check_new_file_click(var);
        if (IS_CLICKED(TOOL->file_menu->options->next->option))
            check_open_file_click(var);
        if (IS_CLICKED(TOOL->file_menu->options->next->next->option)) {
            sfImage_destroy(DRAWING->image);
            DRAWING->image = sfImage_createFromColor(1920, 930, sfWhite);
            TOOL->file_menu->button->state = RELEASED;
            reset_undo_redo(var);
            var->first_point_choose = sfFalse;
        }
    }
}

void check_tool_click(var_t *var, sfEvent event)
{
    IS_CLICKED(TOOL->tool_menu->button);
    if (TOOL->tool_menu->button->state == PRESSED) {
        var->is_active = sfTrue;
        if (IS_CLICKED(TOOL->tool_menu->options->option)) {
            reset_tool(var);
            var->actu_color = sfWhite;
            var->is_active = sfTrue;
            var->tool_select = ERASER;
        }
        if (IS_CLICKED(TOOL->tool_menu->options->next->option)) {
            reset_tool(var);
            var->is_active = sfTrue;
            var->tool_select = PENCIL;
            var->actu_color = sfBlack;
        }
    }
}
