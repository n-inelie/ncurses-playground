#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#define PRINT_MIDDLE_OFFSET(text, height, width, y_offset, x_offset) \
    do {                                                             \
        int text_len = strlen(text);                                 \
        mvprintw((height / 2) + y_offset,                            \
                 (width / 2) + x_offset - text_len / 2, text);       \
    } while (0)

#define PRINT_MIDDLE(text, height, width) \
    PRINT_MIDDLE_OFFSET(text, height, width, 0, 0)


#endif
