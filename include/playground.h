#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include "shorthands.h"

#define PRINT_MIDDLE_OFFSET(text, height, width, y_offset, x_offset) \
    do {                                                             \
        int text_len = strlen(text);                                 \
        mvprintw((height / 2) + y_offset,                            \
                 (width / 2) + x_offset - text_len / 2, text);       \
    } while (0)

#define PRINT_MIDDLE(text, height, width) \
    PRINT_MIDDLE_OFFSET(text, height, width, 0, 0)

typedef struct {
    uint y;
    uint x;
} Point;

typedef struct {
    Point p;
    uint height;
    uint width;
    uint color_pair;
} Box;

/* Draws the box on the screen */
void drawBox(Box box);

typedef enum {LEFT, CENTER, RIGHT} Align;

/* Adds text inside the box at a particular line number relative to the box */
void boxAddTextToLine(Box box, char *text, uint line_num, Align align);

/* Clear a particular line within a box */
void boxClearLine(Box box, uint line_num);

#endif
