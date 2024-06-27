#include <ncurses.h>
#include <string.h>

#include "playground.h"

int main(void) {
    initscr();

    raw();
    keypad(stdscr, true);
    noecho();

    attr_on(A_BOLD, NULL);
    PRINT_MIDDLE("Welcome to umm... where again?!", LINES, COLS);
    attr_off(A_BOLD, NULL);
    PRINT_MIDDLE_OFFSET("Press any key to continue...", LINES, COLS, 1, 0);
    while (1) {
        int ch = getch();
        switch (ch) {
            case 'q':
                endwin();
                return 0;
                break;
            default:
                clear();
                attr_on(A_BOLD, NULL);
                PRINT_MIDDLE("hello, world", LINES, COLS);
                attr_off(A_BOLD, NULL);
                refresh();
                break;
        }
    }

    endwin();
    return 0;
}
