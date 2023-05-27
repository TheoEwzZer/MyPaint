/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void create_file_menu(var_t *var)
{
    sfVector2f size = {200, 40};
    sfVector2f pos = {5, 47};
    unsigned int count = 3;
    const char *option[3] = {"New file", "Open file", "Save file"};

    TOOL->file_menu = create_menu(
        (sfVector2f){5, 5}, (sfVector2f){60, 40}, "File"
    );
    create_menu2(TOOL->file_menu, count, size, pos);
    for (unsigned int i = 0; i < count; i++) {
        TOOL->file_menu = add_option(TOOL->file_menu, pos, size, option[i]);
        pos.y += size.y;
    }
}
