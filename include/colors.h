#ifndef COLORS_H
#define COLORS_H

#include "shorthands.h"

typedef struct {
    ushort r;
    ushort g;
    ushort b;
} RGBColor;

void printRGBColor(RGBColor rgb);

typedef char *HexColor;

/* Converts HexColor to RGBColor */
void hexToRGB(HexColor hex, RGBColor *rgb);

/* Maps a color number to a custom RBGColor */
void initRGBColor(short color_num, RGBColor rgb);

/* Maps a color number to a custom HexColor */
void initHexColor(short color_num, HexColor hex);

#endif
