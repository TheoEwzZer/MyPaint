/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

sfBool is_button_clicked(struct button_s *button, sfMouseButtonEvent *event)
{
    sfFloatRect rect;

    rect = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&rect, (float)event->x, (float)event->y)) {
        if (button->state == PRESSED)
            button->state = RELEASED;
        else
            button->state = PRESSED;
        return sfTrue;
    }
    button->state = RELEASED;
    return sfFalse;
}

sfBool is_drop_button_clicked(object_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect rect;
    sfFloatRect rect2;

    rect = sfRectangleShape_getGlobalBounds(button->rect);
    if (button->drop)
        rect2 = sfRectangleShape_getGlobalBounds(button->drop);
    if (sfFloatRect_contains(&rect, (float)event->x, (float)event->y)) {
        if (button->state == PRESSED)
            button->state = RELEASED;
        else
            button->state = PRESSED;
        return sfTrue;
    }
    if (button->drop
    && !sfFloatRect_contains(&rect2, (float)event->x, (float)event->y))
        button->state = RELEASED;
    return sfFalse;
}
