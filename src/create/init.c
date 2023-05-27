/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

button_t *init_button(sfVector2f position, sfVector2f size, sfColor color)
{
    button_t *rect = malloc(sizeof(button_t));

    rect->rect = sfRectangleShape_create();
    rect->is_clicked = &is_button_clicked;
    rect->state = RELEASED;
    sfRectangleShape_setPosition(rect->rect, position);
    sfRectangleShape_setSize(rect->rect, size);
    SET_FILLCOLOR(rect->rect, color);
    sfRectangleShape_setOutlineThickness(rect->rect, 2);
    SET_OUTLINECOLOR(rect->rect, sfColor_fromRGB(245, 245, 245));
    rect->color = color;
    return rect;
}

sfCircleShape *init_button_circle(sfVector2f position,
sfVector2f size, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, size.x / 2);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOutlineColor(circle, sfColor_fromRGB(245, 245, 245));
    sfCircleShape_setOutlineThickness(circle, 2);
    return circle;
}

object_t *init_drop_button(sfVector2f pos, sfVector2f size, const char *text)
{
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");
    object_t *button = malloc(sizeof(object_t));

    button->rect = sfRectangleShape_create();
    button->is_clicked = &is_drop_button_clicked;
    button->state = RELEASED;
    button->drop = NULL;
    button->text = sfText_create();
    sfText_setFont(button->text, font);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, 20);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 10, pos.y + 10});
    sfText_setColor(button->text, sfBlack);
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    SET_FILLCOLOR(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    SET_OUTLINECOLOR(button->rect, sfColor_fromRGB(245, 245, 245));
    return button;
}
