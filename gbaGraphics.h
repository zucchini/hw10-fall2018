
#define COLOR(r, g, b) ((r) | (g)<<5 | (b)<<10)
#define WHITE COLOR(31,31,31)
#define RED COLOR(31,0,0)
#define GREEN COLOR(0,31,0)
#define BLUE COLOR(0,0,31)
#define MAGENTA COLOR(31, 0, 31)
#define CYAN COLOR(0, 31, 31)
#define YELLOW COLOR(31, 31, 0)
#define BLACK 0
#define GRAY COLOR(5, 5, 5)

#define BUFFER0 ((u16 *) 0x06000000)
#define BUFFER1 ((u16 *) 0x0600A000)
#define PALETTE ((u16 *) 0x05000000)
#define BUFFER1FLAG 0x10

#define SCANLINECOUNTER *(volatile u16 *)0x4000006

// DMA
typedef struct
{
	const volatile void *src;
	volatile void *dst;
	u32 cnt;
} DMA_CONTROLLER;

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

void setPixel(int x, int y, u16 color);
void drawRectDMA(int x, int y, int width, int height, volatile u16 color);
void drawFullScreenImageDMA(u16 *image);
void drawImageDMA(int x, int y, int width, int height, u16 *image);
void fillScreenDMA(volatile u16 color);
void drawChar(int x, int y, char ch, u16 color);
void drawString(int x, int y, char *str, u16 color);
void drawCenteredString(int x, int y, int width, int height, char *str, u16 color);

/** Contains the pixels of each character from a 6x8 font */
// This is in the font.c file. You can replace the font if you want.
extern const unsigned char fontdata_6x8[12288];
