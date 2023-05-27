/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 24};
    sfUint32 style = sfDefaultStyle;
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My Paint", style, NULL
    );
    return window;
}

void update_image(var_t *var)
{
    sfTexture_updateFromImage(DRAWING->texture, DRAWING->image, 0, 0);
    sfSprite_setTexture(DRAWING->sprite, DRAWING->texture, sfTrue);
    SET_SCALE(DRAWING->sprite, (float)var->zoom);
    sfRenderWindow_drawSprite(var->window, DRAWING->sprite, NULL);
}

void my_paint(var_t *var, sfEvent event)
{
    while (sfRenderWindow_isOpen(var->window)) {
        while (sfRenderWindow_pollEvent(var->window, &event))
            events(var, event);
        sfRenderWindow_clear(var->window, sfColor_fromRGB(245, 245, 245));
        update_image(var);
        if (var->is_active)
            DRAW_RECT(TOOL->toolbar);
        display_colors(var); display_size_menu(var);
        display_brush_menu(var); display_tools(var);
        display_file_menu(var); display_help_menu(var);
        display_tool_menu(var);
        DRAW_RECT(TOOL->size_menu->button->drop);
        DRAW_RECT(TOOL->file_menu->button->drop);
        DRAW_RECT(TOOL->brush_menu->button->drop);
        if (var->help_popup->is_active)
            display_help_popup(var);
        if (var->about_popup->is_active)
            display_about_popup(var);
        sfRenderWindow_display(var->window);
    }
}

void init_value(int argc, char **argv, var_t *var)
{
    var->path = (argc == 2) ? argv[1] : NULL;
    var->color = malloc(sizeof(color_t));
    LINE = malloc(sizeof(line_t));
    var->close_about = malloc(sizeof(button_t));
    var->close_help = malloc(sizeof(button_t));
    TOOL = malloc(sizeof(tool_t));
    DRAWING = malloc(sizeof(drawing_t));
    var->window = create_window();
    TOOL->toolbar = create_toolbar();
    DRAWING->sprite = create_image(var);
    create_colors(var);
    var->mousePressed = sfFalse, var->size = 3, var->round = 1, var->zoom = 1;
    var->actu_color = sfBlack;
    var->undo_stack = malloc(sizeof(stack_t));
    var->undo_stack->top = NULL;
    var->redo_stack = malloc(sizeof(stack_t));
    var->redo_stack->top = NULL;
    var->start = (sfVector2u){0, 0};
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;
    var->rect_tool = sfFalse, var->circle_tool = sfFalse;
    var->is_active = sfFalse, var->line_tool = sfFalse;
    var->brush = CIRCLE;
    var->first_point_choose = sfFalse;
    init_value(argc, argv, var);
    DRAWING->last = sfImage_createFromColor(1920, 930, sfWhite);
    if (help(argc, argv))
        return 0;
    create_size_menu(var);
    create_file_menu(var);
    create_help_menu(var);
    create_tool_menu(var);
    create_brush_menu(var);
    create_popup_help(var);
    create_popup_about(var);
    create_shapes(var);
    my_paint(var, event);
    final_free(var);
}
