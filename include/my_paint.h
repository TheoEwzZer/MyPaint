/*
** EPITECH PROJECT, 2023
** my_paint.h
** File description:
** my_paint
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_PAINT_H_

    #define MY_PAINT_H_

    #define ABOUT_POPUP var->about_popup->is_active
    #define DRAWING var->drawing
    #define DRAW_RECT(rect) sfRenderWindow_drawRectangleShape(var->window, \
    rect, NULL)
    #define DRAW_TEXT(text) sfRenderWindow_drawText(var->window, text, NULL)
    #define GET_FILLCOLOR sfRectangleShape_getFillColor
    #define HELP_POPUP var->help_popup->is_active
    #define IS_CLICKED(button) button->is_clicked(button, &event.mouseButton)
    #define IS_HOVER(button) button->is_hover(button, &event.mouseMove)
    #define RECT_ABOUT var->about_popup->rect
    #define RECT_HELP var->help_popup->rect
    #define SET_FILLCOLOR sfRectangleShape_setFillColor
    #define SET_OUTLINECOLOR sfRectangleShape_setOutlineColor
    #define TEXT_ABOUT var->about_popup->text
    #define TEXT_HELP var->help_popup->text
    #define TOOL var->tool
    #define SET_SCALE(sprite, zoom) sfSprite_setScale(sprite, \
    (sfVector2f){zoom, zoom})
    #define LINE var->line

    #define MESSAGE_HELP "\t\t\t\t\t\t\t\t\t\t\tHELP\n\n\n\n\nOnce the " \
    "Paint software is open, you can choose to create a\nnew image or open " \
    "an existing one using the File menu.\n\nTo draw or paint on the canvas, " \
    "select a tool from the toolbar.\nThe available tools include the " \
    "pencil and eraser.\n\nAdjust the color and thickness of the tool by " \
    "selecting the\nappropriate options from the toolbar.\n\nUse the " \
    "selection tool to select a specific area of the canvas that\nyou " \
    "want to edit, copy, or move.\n\nSave your image by selecting Save " \
    "file from the File menu.\n\nTo undo or redo an action, use the Undo " \
    "or Redo buttons in the\ntoolbar or press Ctrl+Z/Ctrl+Y on your keyboard." \
    "\n\nOnce you are finished editing your image, close the Paint\nsoftware " \
    "by clicking the X in the top right-hand corner."

    #define MESSAGE_ABOUT "\t\t\t\tABOUT MY PAINT\n\n\n\n\n\t\t\t\t\t" \
    "My Paint 1.0\n\n\t\t" \
    "2023 Ectazium. All rights reserved.\n\n\t\t\ttheo.fabiano@epitech.eu" \
    "\n\n\t\ttheo.maestracci@epitech.eu" \

enum gui_state_e {
    NONE = 0,
    PRESSED,
    RELEASED,
    HOVER
};

enum gui_tool_e {
    SQUARE = 0,
    CIRCLE,
};

enum enum_tool_ {
    PENCIL = 0,
    ERASER,
};

typedef struct options_s {
    struct object_s *option;
    struct options_s *next;
} options_t;

typedef struct menu_s {
    struct object_s *button;
    struct options_s *options;
} menu_t;

typedef struct tool_s {
    sfRectangleShape *toolbar;
    sfRectangleShape *sidebar;
    struct button_s *circle;
    struct button_s *line;
    struct button_s *rectangle;
    struct menu_s *brush_menu;
    struct menu_s *file_menu;
    struct menu_s *help_menu;
    struct menu_s *size_menu;
    struct menu_s *tool_menu;
} tool_t;

typedef struct object_s {
    enum gui_state_e state;
    sfBool (*is_clicked)(struct object_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct object_s *, sfMouseMoveEvent *);
    sfRectangleShape *drop;
    sfRectangleShape *rect;
    sfText *text;
} object_t;

typedef struct button_s {
    enum gui_state_e state;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    sfBool is_active;
    sfColor color;
    sfRectangleShape *rect;
} button_t;

typedef struct popup_s {
    sfBool is_active;
    sfRectangleShape *rect;
    sfText *text;
} popup_t;

typedef struct drawing_s {
    sfImage *image;
    sfImage *last;
    sfSprite *sprite;
    sfTexture *texture;
} drawing_t;

typedef struct color_s {
    struct button_s *black;
    struct button_s *blue;
    struct button_s *cyan;
    struct button_s *green;
    struct button_s *magenta;
    struct button_s *red;
    struct button_s *white;
    struct button_s *yellow;
} color_t;

typedef struct node_s {
    sfImage *image;
    struct node_s *next;
} node_t;

typedef struct stack_s {
    struct node_s *top;
} stack_t;

typedef struct line_s {
    int error;
    int error2;
    sfVector2i diff;
    sfVector2i end;
    sfVector2i pos;
    sfVector2i start;
    sfVector2i step;
} line_t;

typedef struct var {
    button_t *close_about;
    button_t *close_help;
    char *path;
    color_t *color;
    drawing_t *drawing;
    enum gui_tool_e brush;
    enum enum_tool_ tool_select;
    int round;
    popup_t *about_popup;
    popup_t *help_popup;
    sfBool mousePressed;
    sfColor actu_color;
    sfRenderWindow *window;
    stack_t *redo_stack;
    stack_t *undo_stack;
    tool_t *tool;
    unsigned int mouse_x;
    unsigned int mouse_y;
    unsigned int size;
    unsigned int zoom;
    sfBool first_point_choose;
    sfVector2f first_point;
    sfBool rect_tool;
    sfBool circle_tool;
    sfBool line_tool;
    sfCircleShape *circle;
    sfVector2u start;
    line_t *line;
    bool is_active;
} var_t;

bool is_valid_format(char *filename);
button_t *init_button(sfVector2f position, sfVector2f size, sfColor color);
int help(int argc, char **argv);
menu_t *add_option(menu_t *size_menu, sfVector2f position,
sfVector2f size, const char *str);
menu_t *create_menu(sfVector2f position, sfVector2f size, const char *text);
object_t *init_drop_button(sfVector2f position,
sfVector2f size, const char *text);
sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event);
sfBool is_drop_button_clicked(object_t *button, sfMouseButtonEvent *event);
sfCircleShape *init_button_circle(sfVector2f position,
sfVector2f size, sfColor color);
sfImage *create_image2(const char *filename);
sfImage *pop(stack_t *stack);
sfRectangleShape *create_toolbar(void);
sfRenderWindow *create_window(void);
sfSprite *create_image(var_t *var);
void change_pixel(var_t *var, sfColor color);
void change_pixel2(var_t *var, sfColor color);
void check_brush_click(var_t *var, sfEvent event);
void check_click(var_t *var, sfEvent event);
void check_color_click(var_t *var, sfEvent event);
void check_color_click2(var_t *var, sfEvent event);
void check_color_click3(var_t *var, sfEvent event);
void check_color_click4(var_t *var, sfEvent event);
void check_file_click(var_t *var, sfEvent event);
void check_file_click(var_t *var, sfEvent event);
void check_new_file_click(var_t *var);
void check_open_file_click(var_t *var);
void check_size_click(var_t *var, sfEvent event);
void check_tool_click(var_t *var, sfEvent event);
void check_tools_click(var_t *var, sfEvent event);
void create_brush_menu(var_t *var);
void create_colors(var_t *var);
void create_file_menu(var_t *var);
void create_help_menu(var_t *var);
void create_menu2(menu_t *menu, unsigned int options,
sfVector2f size, sfVector2f pos);
void create_popup_about(var_t *var);
void create_popup_help(var_t *var);
void create_shapes(var_t *var);
void create_size_menu(var_t *var);
void create_tool_menu(var_t *var);
void display_about_popup(var_t *var);
void display_brush_menu(var_t *var);
void display_colors(var_t *var);
void display_file_menu(var_t *var);
void display_help_menu(var_t *var);
void display_help_popup(var_t *var);
void display_size_menu(var_t *var);
void display_tool_menu(var_t *var);
void display_tools(var_t *var);
void draw(var_t *var, sfEvent event);
void draw_circle(var_t *var, sfColor color);
void draw_circle2(var_t *var, unsigned int i, unsigned int j, sfColor color);
void draw_circle_tool(var_t *var, sfColor color);
void draw_circle_tool2(var_t *var, unsigned int i,
unsigned int j, sfColor color);
void draw_line(var_t *var, sfColor color);
void draw_line2(var_t *var, sfColor color);
void draw_point(var_t *var, sfEvent event);
void draw_rectangle(var_t *var, sfColor color);
void draw_rectangle2(var_t *var, unsigned int i, unsigned int j, sfColor color);
void draw_square(var_t *var, sfColor color);
void events(var_t *var, sfEvent event);
void final_free(var_t *var);
void free_filename(char **filename);
void get_valid_filename_open(char **filename);
void get_valid_filename_save(char **filename);
void init_value(int argc, char **argv, var_t *var);
void my_paint(var_t *var, sfEvent event);
void open_image_from_file(var_t *var, const char *filename);
void push(stack_t *stack, sfImage *image);
void reset_color(var_t *var);
void reset_tool(var_t *var);
void reset_undo_redo(var_t *var);
void save_image_to_file(var_t *var, const char *filename);
void swap(unsigned int *a, unsigned int *b);
void undo_redo(var_t *var, sfEvent event);
void update_image(var_t *var);
void verif_last_image(var_t *var, sfImage *last_image);
void zoom_key(var_t *var, sfEvent event);
void zoom_wheel(var_t *var, sfEvent event);
void destroy_color(var_t *var);
void final_free3(var_t *var);
void final_free2(var_t *var);

#endif /* MY_PAINT_H_ */
