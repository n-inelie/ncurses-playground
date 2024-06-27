#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "playground.h"
#include "shorthands.h"

#define LIST_ITEM_MAX 32

int main(void) {
    initscr();
    start_color();

    raw();
    keypad(stdscr, true);
    noecho();
    
    initHexColor(COLOR_PINK, "#e224a9");
    initHexColor(COLOR_DARK_ZINC, "#09090b");
    initHexColor(COLOR_PRETTY_WHITE, "#f8f8f2");

    init_pair(69, COLOR_PRETTY_WHITE, COLOR_DARK_ZINC);
    init_pair(1, COLOR_RED, COLOR_DARK_ZINC);
    init_pair(2, COLOR_PINK, COLOR_DARK_ZINC);
    init_pair(3, COLOR_GREEN, COLOR_DARK_ZINC);
    init_pair(4, COLOR_MAGENTA, COLOR_DARK_ZINC);

    bkgd(COLOR_PAIR(69));

    attr_on(A_BOLD, NULL);
    PRINT_MIDDLE("Welcome to umm... where again?!", LINES, COLS);
    attr_off(A_BOLD, NULL);

    attr_on(COLOR_PAIR(1), NULL);
    PRINT_MIDDLE_OFFSET("Press any key to continue...", LINES, COLS, 1, 0);
    attr_off(COLOR_PAIR(1), NULL);

    while (1) {
        int ch = getch();
        switch (ch) {
            case 'q':
                endwin();
                return 0;
                break;
            default: {
                clear();
                char *list[] = {"item 1", "item 2", "item 3", "item 4",
                                "item 5"};
                uint list_len = ARR_LEN(list);
                uint selected = 2;

                Box b1;
                b1.width = 40;
                b1.height = 20;
                b1.color_pair = COLOR_PAIR(4);
                do {
                    b1.p =
                        (Point){(LINES - b1.height) / 2, (COLS - b1.width) / 2};
                    drawBox(b1);

                    attr_on(A_BOLD, NULL);
                    boxAddTextToLine(b1, "List", 1, CENTER);
                    attr_off(A_BOLD, NULL);

                    for (uint i = 0; i < list_len; i++) {
                        boxClearLine(b1, i + 1);
                        char text[16];
                        sprintf(text, "(%d) %s", i + 1, list[i]);
                        if (i + 1 == selected) {
                            attr_on(A_BOLD, NULL);
                            boxAddTextToLine(b1, text, i + 3, LEFT);
                            attr_off(A_BOLD, NULL);
                        } else {
                            boxAddTextToLine(b1, text, i + 3, LEFT);
                        }
                    }
                    refresh();
                    int ch2 = getch();
                    switch (ch2) {
                        case 'q':
                            endwin();
                            return 0;
                            break;
                        case 'k':
                            if (selected > 1) selected--;
                            break;
                        case 'j':
                            if (selected < list_len) selected++;
                            break;
                        case 'c': {
                            char *str = malloc(sizeof(char) * LIST_ITEM_MAX);
                            getnstr(str, LIST_ITEM_MAX);
                            list[selected - 1] =
                                realloc(str, sizeof(char) * LIST_ITEM_MAX);
                            clear();
                        } break;
                    }
                } while (1);
            } break;
        }
    }

    endwin();
    return 0;
}
