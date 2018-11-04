#include "myLib.h"

u16 *videoBuffer = (u16 *)0x6000000;
u32 vBlankCounter = 0;

void waitForVBlank() {
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 159);
  vBlankCounter++;
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
