/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void create_colors(var_t *var)
{
    sfVector2f size = {30, 30};

    var->color->black = init_button((sfVector2f){1810, 608}, size, sfBlack);
    var->color->white = init_button((sfVector2f){1865, 608}, size, sfWhite);
    var->color->red = init_button((sfVector2f){1810, 658}, size, sfRed);
    var->color->green = init_button((sfVector2f){1865, 658}, size, sfGreen);
    var->color->blue = init_button((sfVector2f){1810, 708}, size, sfBlue);
    var->color->yellow = init_button((sfVector2f){1865, 708}, size, sfYellow);
    var->color->magenta = init_button((sfVector2f){1810, 758}, size, sfMagenta);
    var->color->cyan = init_button((sfVector2f){1865, 758}, size, sfCyan);
    SET_OUTLINECOLOR(var->color->black->rect, sfBlack);
}

void create_shapes(var_t *var)
{
    sfVector2f size = {30, 30};
    sfVector2f line = {30, 0.1f};

    TOOL->rectangle = init_button((sfVector2f){1810, 858}, size, sfBlack);
    TOOL->circle = init_button((sfVector2f){1865, 858}, size, sfBlack);
    TOOL->line = init_button((sfVector2f){1837, 908}, line, sfBlack);
    var->circle = init_button_circle((sfVector2f){1865, 858}, size, sfBlack);
    SET_FILLCOLOR(TOOL->rectangle->rect, sfWhite);
    sfCircleShape_setFillColor(var->circle, sfWhite);
    sfRectangleShape_setRotation(TOOL->line->rect, 45);
    SET_FILLCOLOR(TOOL->line->rect, sfColor_fromRGB(245, 245, 245));
}

sfRectangleShape *create_toolbar(void)
{
    sfRectangleShape *toolbar = sfRectangleShape_create();

    sfRectangleShape_setSize(toolbar, (sfVector2f){135, 1870});
    sfRectangleShape_setPosition(toolbar, (sfVector2f){1785, 50});
    SET_FILLCOLOR(toolbar, sfWhite);
    SET_OUTLINECOLOR(toolbar, sfColor_fromRGB(245, 245, 245));
    sfRectangleShape_setOutlineThickness(toolbar, 2);
    return toolbar;
}

sfSprite *create_image(var_t *var)
{
    sfSprite *drawing_sprite = sfSprite_create();

    if (var->path)
        DRAWING->image = sfImage_createFromFile(var->path);
    else
        DRAWING->image = sfImage_createFromColor(1920, 930, sfWhite);
    DRAWING->texture = sfTexture_createFromImage(DRAWING->image, NULL);
    sfSprite_setTexture(drawing_sprite, DRAWING->texture, sfTrue);
    sfSprite_setPosition(drawing_sprite, (sfVector2f){0, 50});
    return drawing_sprite;
}
