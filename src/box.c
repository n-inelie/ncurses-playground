#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#include "dialog.h"
#include "playground.h"

void drawBox(Box box) {
    attr_on(A_BOLD, NULL);
    attr_on(box.color_pair, NULL);

    move(box.p.y, box.p.x);

    addch(ACS_ULCORNER);
    REPEAT(box.width - 2, addch(ACS_HLINE););
    addch(ACS_URCORNER);
    REPEAT(box.height - 2,
           RUNBLOCK(move(box.p.y + 1 + i, box.p.x); addch(ACS_VLINE);););
    REPEAT(box.height - 2,
           RUNBLOCK(move(box.p.y + 1 + i, box.p.x + box.width - 1);
                    addch(ACS_VLINE);););
    move(box.p.y + box.height - 1, box.p.x);
    addch(ACS_LLCORNER);
    REPEAT(box.width - 2, addch(ACS_HLINE););
    addch(ACS_LRCORNER);

    attr_off(box.color_pair, NULL);
    attr_off(A_BOLD, NULL);
}

void addTextToBox(Box box, char *text, uint line_num) {
    (void)line_num;
    uint text_len = strlen(text);

    if (text_len > box.width - 2) PANIC("Text is too long");
    if (line_num > box.height - 2) PANIC("Line number out of bounds");

    mvprintw(box.p.y + line_num, box.p.x + 1, "%s", text);
}
