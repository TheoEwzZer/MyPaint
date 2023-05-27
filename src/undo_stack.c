/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void push(stack_t *stack, sfImage *image)
{
    node_t *node = malloc(sizeof(node_t));

    node->image = image;
    node->next = stack->top;
    stack->top = node;
}

sfImage *pop(stack_t *stack)
{
    node_t *node = NULL;
    sfImage *image = NULL;

    if (!stack->top)
        return NULL;
    node = stack->top;
    stack->top = node->next;
    image = node->image;
    free(node);
    return image;
}

void verif_last_image(var_t *var, sfImage *last_image)
{
    if (last_image) {
        sfImage_destroy(DRAWING->image);
        DRAWING->image = last_image;
    }
}

void undo_redo(var_t *var, sfEvent event)
{
    sfImage *last_image = NULL;

    if (event.key.control && event.key.code == sfKeyZ) {
        push(var->redo_stack, sfImage_copy(DRAWING->image));
        last_image = pop(var->undo_stack);
        verif_last_image(var, last_image);
    } else if (event.key.control && event.key.code == sfKeyY) {
        push(var->undo_stack, sfImage_copy(DRAWING->image));
        last_image = pop(var->redo_stack);
        verif_last_image(var, last_image);
    }
}

void reset_undo_redo(var_t *var)
{
    node_t *node = var->undo_stack->top;
    node_t *next = NULL;

    while (node) {
        next = node->next;
        sfImage_destroy(node->image);
        free(node);
        node = next;
    }
    var->undo_stack->top = NULL;
    node = var->redo_stack->top;
    while (node) {
        next = node->next;
        sfImage_destroy(node->image);
        free(node);
        node = next;
    }
    var->redo_stack->top = NULL;
}
