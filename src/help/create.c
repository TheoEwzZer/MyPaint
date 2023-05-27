/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void create_popup_about(var_t *var)
{
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");

    var->about_popup = malloc(sizeof(popup_t));
    RECT_ABOUT = sfRectangleShape_create();
    sfRectangleShape_setPosition(RECT_ABOUT, (sfVector2f){710, 350});
    sfRectangleShape_setSize(RECT_ABOUT, (sfVector2f){400, 400});
    SET_FILLCOLOR(RECT_ABOUT, sfColor_fromRGB(254, 254, 254));
    sfRectangleShape_setOutlineThickness(RECT_ABOUT, 2);
    SET_OUTLINECOLOR(RECT_ABOUT, sfColor_fromRGB(245, 245, 245));
    TEXT_ABOUT = sfText_create();
    sfText_setFont(TEXT_ABOUT, font);
    sfText_setString(TEXT_ABOUT, MESSAGE_ABOUT);
    sfText_setCharacterSize(TEXT_ABOUT, 20);
    sfText_setPosition(TEXT_ABOUT,
        (sfVector2f){710 + 10, 350 + 10});
    sfText_setColor(TEXT_ABOUT, sfBlack);
    var->about_popup->is_active = false;
    var->close_about = init_button((sfVector2f){1080, 350},
        (sfVector2f){30, 30}, sfRed);
}

void create_popup_help(var_t *var)
{
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");

    var->help_popup = malloc(sizeof(popup_t));
    RECT_HELP = sfRectangleShape_create();
    sfRectangleShape_setPosition(RECT_HELP, (sfVector2f){610, 250});
    sfRectangleShape_setSize(RECT_HELP, (sfVector2f){600, 600});
    SET_FILLCOLOR(RECT_HELP, sfColor_fromRGB(254, 254, 254));
    sfRectangleShape_setOutlineThickness(RECT_HELP, 2);
    SET_OUTLINECOLOR(RECT_HELP, sfColor_fromRGB(245, 245, 245));
    TEXT_HELP = sfText_create();
    sfText_setFont(TEXT_HELP, font);
    sfText_setString(TEXT_HELP, MESSAGE_HELP);
    sfText_setCharacterSize(TEXT_HELP, 20);
    sfText_setPosition(TEXT_HELP, (sfVector2f){610 + 10, 250 + 10});
    sfText_setColor(TEXT_HELP, sfBlack);
    var->help_popup->is_active = false;
    var->close_help = init_button(
        (sfVector2f){1180, 250}, (sfVector2f){30, 30}, sfRed
    );
}

void create_help_menu(var_t *var)
{
    sfVector2f size = {200, 40};
    sfVector2f pos = {5, 47};
    unsigned int count = 2;
    const char *option[2] = {"About", "Help"};

    TOOL->help_menu = create_menu(
        (sfVector2f){70, 5}, (sfVector2f){60, 40}, "Help"
    );
    create_menu2(TOOL->help_menu, count, size, pos);
    for (unsigned int i = 0; i < count; i++) {
        TOOL->help_menu = add_option(TOOL->help_menu, pos, size, option[i]);
        pos.y += size.y;
    }
}

void create_tool_menu(var_t *var)
{
    sfVector2f size = {200, 40};
    sfVector2f pos = {5, 47};
    unsigned int count = 2;
    const char *option[2] = {"Pencil", "Eraser"};

    TOOL->tool_menu = create_menu(
        (sfVector2f){135, 5}, (sfVector2f){60, 40}, "Edit"
    );
    create_menu2(TOOL->tool_menu, count, size, pos);
    for (unsigned int i = 0; i < count; i++) {
        TOOL->tool_menu = add_option(TOOL->tool_menu, pos, size, option[i]);
        pos.y += size.y;
    }
}
