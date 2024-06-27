#include <ncurses.h>
#include <string.h>

#include "colors.h"
#include "playground.h"

#define COLOR_DARK_ZINC 100
#define COLOR_PINK 101

int main(void) {
    initscr();
    start_color();

    raw();
    keypad(stdscr, true);
    noecho();

    initHexColor(COLOR_PINK, "#e224a9");
    initHexColor(COLOR_DARK_ZINC, "#09090b");

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_PINK, COLOR_DARK_ZINC);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

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
            default:
                clear();

                Box b1;
                b1.width = 40;
                b1.height = 20;
                b1.color_pair = COLOR_PAIR(4);
                b1.p = (Point){(LINES - b1.height) / 2, (COLS - b1.width) / 2};
                drawBox(b1);

                attr_on(A_BOLD, NULL);
                addTextToBox(b1, "List", 1);
                attr_off(A_BOLD, NULL);

                char *list[] = {"item 1", "item 2", "item 3"};
                uint list_len = 3;
                for (uint i = 0; i < list_len; i++) {
                    addTextToBox(b1, list[i], i + 3);
                }

                refresh();
                break;
        }
    }

    endwin();
    return 0;
}
