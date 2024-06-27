#include <ncurses.h>
#include <string.h>

#include "dialog.h"
#include "playground.h"

void dialog(char *title, char *message) {
    clear();
    Box b;
    b.height = LINES / 2;
    b.width = COLS / 2;
    b.color_pair = COLOR_PAIR(1);
    b.p = (Point){(LINES - b.height) / 2, (COLS - b.width) / 2};
    drawBox(b);

    uint title_len = strlen(title);
    attr_on(A_BOLD, NULL);
    mvprintw(b.p.y + 1, b.p.x + 1 + (b.width - 2 - title_len) / 2, "%s", title);
    attr_off(A_BOLD, NULL);
    mvprintw(b.p.y + 3, b.p.x + 1, "%s", message);
}
