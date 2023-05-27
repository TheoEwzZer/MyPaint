/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

bool is_valid_format(char *filename)
{
    const char *formats[4] = {".bmp", ".png", ".tga", ".jpg"};
    for (unsigned int i = 0; i < 4; i++) {
        if (!my_strcmp(filename + my_strlen(filename) - 4, formats[i]))
            return true;
    }
    return false;
}
