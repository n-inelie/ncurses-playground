#include <ncurses.h>
#include <stdlib.h>

#include "colors.h"

inline void printRGBColor(RGBColor rgb) {
    printf("Red: %d", rgb.r);
    printf("Green: %d", rgb.g);
    printf("Blue: %d", rgb.b);
}

void hexToRGB(HexColor hex, RGBColor *rgb) {
    char hex_part[3];
    char *endptr;
    ushort int_part;
    for (size_t i = 1; i < 7; i += 2) {
        hex_part[0] = hex[i];
        hex_part[1] = hex[i + 1];
        hex_part[2] = '\0';

        int_part = strtol(hex_part, &endptr, 16);
        switch (i) {
            case 1:
                rgb->r = int_part;
                break;
            case 3:
                rgb->g = int_part;
                break;
            case 5:
                rgb->b = int_part;
                break;
        }
    }
}

inline void initRGBColor(short color_num, RGBColor rgb) {
    init_color(color_num, rgb.r*1000/255, rgb.b*1000/255, rgb.r*1000/255);
}

inline void initHexColor(short color_num, HexColor hex) {
    RGBColor rgb;
    hexToRGB(hex, &rgb);
    initRGBColor(color_num, rgb);
}
