/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my_paint.h"

sfImage *create_image2(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    sfImage *new_image = NULL;

    if (fd == -1)
        return NULL;
    new_image = sfImage_createFromFile(filename);
    close(fd);
    return new_image;
}

void get_valid_filename_open(char **filename)
{
    size_t len = 0;
    ssize_t read;
    bool valid_format = false;
    write(1, "Please enter the filename to open the image: ", 45);
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

void open_image_from_file(var_t *var, const char *filename)
{
    sfImage *new_image = create_image2(filename);

    if (new_image) {
        sfImage_destroy(DRAWING->image);
        DRAWING->image = new_image;
        write(1, "Image successfully opened from file ", 36);
        write(1, filename, my_strlen(filename));
        write(1, "\n", 1);
    } else {
        write(1, "Unable to load image from file ", 32);
        write(1, filename, my_strlen(filename));
        write(1, "\n", 1);
    }
}

void check_open_file_click(var_t *var)
{
    char *filename = NULL;
    sfRenderWindow_setVisible(var->window, sfFalse);
    get_valid_filename_open(&filename);
    var->mousePressed = sfFalse;
    sfSleep(sfSeconds(1));
    sfRenderWindow_setVisible(var->window, sfTrue);
    if (!filename)
        return;
    open_image_from_file(var, filename);
    free(filename);
}
