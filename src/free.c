/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void free_filename(char **filename)
{
    free(*filename);
    *filename = NULL;
}

void destroy_color(var_t *var)
{
    sfRectangleShape_destroy(var->color->black->rect);
    sfRectangleShape_destroy(var->color->cyan->rect);
    sfRectangleShape_destroy(var->color->blue->rect);
    sfRectangleShape_destroy(var->color->green->rect);
    sfRectangleShape_destroy(var->color->magenta->rect);
    sfRectangleShape_destroy(var->color->red->rect);
    sfRectangleShape_destroy(var->color->white->rect);
    sfRectangleShape_destroy(var->color->yellow->rect);
    free(var->color->black);
    free(var->color->blue);
    free(var->color->cyan);
    free(var->color->green);
    free(var->color->magenta);
    free(var->color->red);
    free(var->color->white);
    free(var->color->yellow);
}

void final_free3(var_t *var)
{
    sfRectangleShape_destroy(var->tool->brush_menu->button->rect);
    sfRectangleShape_destroy(var->tool->brush_menu->button->drop);
    sfText_destroy(var->tool->brush_menu->button->text);
    sfRectangleShape_destroy(var->tool->file_menu->button->rect);
    sfRectangleShape_destroy(var->tool->file_menu->button->drop);
    sfText_destroy(var->tool->file_menu->button->text);
    sfRectangleShape_destroy(var->tool->help_menu->button->rect);
    sfRectangleShape_destroy(var->tool->help_menu->button->drop);
    sfText_destroy(var->tool->help_menu->button->text);
    sfRectangleShape_destroy(var->tool->size_menu->button->rect);
    sfRectangleShape_destroy(var->tool->size_menu->button->drop);
    sfText_destroy(var->tool->size_menu->button->text);
}

void final_free2(var_t *var)
{
    sfRectangleShape_destroy(var->about_popup->rect);
    sfText_destroy(var->about_popup->text);
    free(var->about_popup);
    sfRectangleShape_destroy(var->help_popup->rect);
    sfText_destroy(var->help_popup->text);
    free(var->help_popup);
    sfCircleShape_destroy(var->circle);
    sfRectangleShape_destroy(var->tool->toolbar);
    sfRectangleShape_destroy(var->tool->circle->rect);
    sfRectangleShape_destroy(var->tool->line->rect);
    sfRectangleShape_destroy(var->tool->rectangle->rect);
    final_free3(var);
}

void final_free(var_t *var)
{
    sfImage_destroy(DRAWING->image);
    while (var->undo_stack->top)
        sfImage_destroy(pop(var->undo_stack));
    free(var->undo_stack);
    while (var->redo_stack->top)
        sfImage_destroy(pop(var->redo_stack));
    free(var->redo_stack);
    sfRectangleShape_destroy(var->close_about->rect);
    free(var->close_about);
    sfRectangleShape_destroy(var->close_help->rect);
    free(var->close_help);
    free(var->drawing);
    final_free2(var);
    destroy_color(var);
    sfRenderWindow_destroy(var->window);
    free(var);
}
