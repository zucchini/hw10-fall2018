#include "gba.h"

u16 *videoBuffer = (u16 *)0x6000000;
u32 vBlankCounter = 0;

void waitForVBlank() {
  // TA-TODO: IMPLEMENT

  // Write a while loop that keeps going until we're NOT in vBlank anymore:
  // (This prevents counting one vblank more than once if your game is too fast)


  // Write a while loop that keeps going until we're in vBlank:


  // Finally, increment the vBlank counter:


}

static int __qran_seed= 42;
static int sqran(int seed) {
    int old= __qran_seed;
    __qran_seed= seed;
    return old;
}

static int qran() {
    __qran_seed= 1664525*__qran_seed+1013904223;
    return (__qran_seed>>16) & 0x7FFF;
}

int randint(int min, int max) {
	return (qran()*(max-min)>>15)+min;
}

void setPixel(int x, int y, u16 color) {
  // TA-TODO: IMPLEMENT
}

void drawRectDMA(int x, int y, int width, int height, volatile u16 color) {
  // TA-TODO: IMPLEMENT
}

void drawFullScreenImageDMA(u16 *image) {
  // TA-TODO: IMPLEMENT
}

void drawImageDMA(int x, int y, int width, int height, u16 *image) {
  // TA-TODO: IMPLEMENT
}

void fillScreenDMA(volatile u16 color) {
  // TA-TODO: IMPLEMENT
}

void drawChar(int col, int row, char ch, u16 color) {
	for(int r = 0; r<8; r++) {
		for(int c=0; c<6; c++) {
			if(fontdata_6x8[OFFSET(r, c, 6) + ch*48]) {
				setPixel(videoBuffer, col+c, row+r, color);
			}
		}
	}
}

void drawString(int col, int row, char *str, u16 color) {
	while(*str) {
		drawChar(videoBuffer, col, row, *str++, color);
		col += 6;
	}
}

void drawCenteredString(int x, int y, int width, int height, char *str, u16 color) {
    u32 len = 0;
    char *strCpy = str;
    while (*strCpy) {
        len++;
        strCpy++;
    }

    u32 strWidth = 6 * len;
    u32 strHeight = 8;

    int col = x + ((width - strWidth) >> 1);
    int row = y + ((height - strHeight) >> 1);
    drawString(videoBuffer, col, row, str, color);
}
