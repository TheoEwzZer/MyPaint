/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

void get_valid_filename_save(char **filename)
{
    size_t len = 0;
    ssize_t read;
    bool valid_format = false;
    write(1, "Please enter the filename to save the image: ", 45);
    if ((read = getline(filename, &len, stdin)) == -1) {
        write(1, "Error when reading the input\n", 29);
        free_filename(filename);
        return;
    }
    (*filename)[read - 1] = '\0';
    if (my_strlen(*filename) >= 4)
        valid_format = is_valid_format(*filename);
    if (!valid_format) {
        write(1,
            "Invalid file format, choose a .bmp, .png, .tga or .jpg file\n"
            ,60);
        free_filename(filename);
    }
}

void save_image_to_file(var_t *var, const char *filename)
{
    if (sfImage_saveToFile(DRAWING->image, filename)) {
        write(1, "Image successfully saved to file ", 33);
        write(1, filename, my_strlen(filename));
        write(1, "\n", 1);
    } else {
        write(1, "Unable to save image to file ", 29);
        write(1, filename, my_strlen(filename));
        write(1, "\n", 1);
    }
}

void check_new_file_click(var_t *var)
{
    char *filename = NULL;
    sfRenderWindow_setVisible(var->window, sfFalse);
    get_valid_filename_save(&filename);
    var->mousePressed = sfFalse;
    sfSleep(sfSeconds(1));
    sfRenderWindow_setVisible(var->window, sfTrue);
    if (!filename)
        return;
    save_image_to_file(var, filename);
    free(filename);
}
