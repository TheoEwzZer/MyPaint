/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void create_menu2(menu_t *menu, unsigned int options,
sfVector2f size, sfVector2f pos)
{
    sfVector2f new_size = {
        size.x,
        size.y + (size.y * (float)options)
    };
    sfVector2f drop_pos = {pos.x, pos.y};

    menu->button->drop = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->button->drop, drop_pos);
    sfRectangleShape_setSize(menu->button->drop, new_size);
    SET_FILLCOLOR(menu->button->drop, sfTransparent);
}

menu_t *create_menu(sfVector2f pos, sfVector2f size, const char *text)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->button = init_drop_button(pos, size, text);
    menu->button->drop = sfRectangleShape_create();
    menu->button->state = RELEASED;
    menu->options = NULL;
    return menu;
}

menu_t *add_option(menu_t *menu, sfVector2f pos,
sfVector2f size, const char *str)
{
    options_t *new_option = malloc(sizeof(options_t));
    new_option->option = init_drop_button(pos, size, str);
    new_option->next = menu->options;
    menu->options = new_option;
    return menu;
}

void create_size_menu(var_t *var)
{
    sfVector2f size = {150, 50};
    sfVector2f pos = {1785, 404};
    unsigned int count = 4;
    const char *option[4] = {"\t\t1px", "\t\t3px", "\t\t5px", "\t\t8px"};

    TOOL->size_menu = create_menu(
        (sfVector2f){1810, 352}, (sfVector2f){90, 50}, "   Size"
    );
    create_menu2(TOOL->size_menu, count, size, pos);
    for (unsigned int i = 0; i < count; i++) {
        TOOL->size_menu = add_option(TOOL->size_menu, pos, size, option[i]);
        pos.y += size.y;
    }
}

void create_brush_menu(var_t *var)
{
    sfVector2f size = {150, 50};
    sfVector2f pos = {1785, 252};
    unsigned int count = 2;
    const char *option[2] = {"\t  Circle", "\t Square"};

    TOOL->brush_menu = create_menu(
        (sfVector2f){1810, 200}, (sfVector2f){90, 50}, "Brushes"
    );
    create_menu2(TOOL->brush_menu, count, size, pos);
    for (unsigned int i = 0; i < count; i++) {
        TOOL->brush_menu = add_option(TOOL->brush_menu, pos, size, option[i]);
        pos.y += size.y;
    }
}
