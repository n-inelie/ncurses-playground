#include <ncurses.h>
#include <stdio.h>

#include "playground.h"

void drawBox(Box box) {
    attr_on(box.color_pair, NULL);

    move(box.p.y, box.p.x);

    addch(ACS_ULCORNER);
    REPEAT(box.width - 2, addch(ACS_HLINE););
    addch(ACS_URCORNER);
    REPEAT(
        box.height - 2, RUNBLOCK(
            move(box.p.y + 1 + i, box.p.x);
            addch(ACS_VLINE);
        ););
    REPEAT(
        box.height - 2, RUNBLOCK(
            move(box.p.y + 1 + i, box.p.x + box.width-1);
            addch(ACS_VLINE);
        ););
    move(box.p.y+box.height-1, box.p.x);
    addch(ACS_LLCORNER);
    REPEAT(box.width - 2, addch(ACS_HLINE););
    addch(ACS_LRCORNER);

    attr_off(box.color_pair, NULL);
}
