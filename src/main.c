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

                Box b1 = {(Point){1, 1}, 10, 10, COLOR_PAIR(1)};
                drawBox(b1);
                
                // attr_on(A_BOLD, NULL);
                // attr_on(COLOR_PAIR(2), NULL);
                // PRINT_MIDDLE("hello, world", LINES, COLS);
                // attr_off(COLOR_PAIR(2), NULL);
                // attr_off(A_BOLD, NULL);

                refresh();
                break;
        }
    }

    endwin();
    return 0;
}
