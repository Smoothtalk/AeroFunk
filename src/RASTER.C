/******************************************************************************
*
* FileName: Raster.c
*
* Purpose: This file modifies the frame buffer to help the user display shapes
*          and plot pixels to the screen.
*
* FrameBuffer: The physical addresses used by the following functions to 
*              toggle pixels
*
* Names: Avinash Chandiramani, Steven Ho
*
* Assumptions: Those warnings don't affect the results.
*
******************************************************************************/

#include <stdio.h>
#include <osbind.h>
#include "raster.h"
#include "font.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define MAX_SCREEN16 ((SCREEN_HEIGHT * SCREEN_WIDTH) / 16)
#define MAX_SCREEN8 80

/******************************************************************************
*
* Name:  ClearScreen
* 
* Purpose: To clear the frame buffer.
*
* Input: 
*
*    -Base: the origin point of the frame buffer. To know where to start.
*
******************************************************************************/
void clearScreen (UINT32 *base){

    int i = 0;
    int max = MAX_SCREEN16;

    while(i < 8000){
    
        *base = *(base + i ) = 0x00000000;
        i++;
    }

}

/******************************************************************************
*
* Name: Plot Bitmap
*
* Purpose: plot any 16 x 16 bitmap
*
* Input: 
*
*    -base          : the frame buffer origin point
*    -bitmap        : starting address of the bitmap
*    -x             : where to put the bitmap in the x axis
*    -y             : where to put the bitmap in the y axis
*    -bitmap_height : the height of the bitmap
*
*
******************************************************************************/

void plot_bitmap16(UINT16 *base, const UINT16 *bitmap, int x, int y,
	int bitmap_height){
    
    int i = 0;
    int height_offset = y * 40;
    int pixel_offset = x >> 4;
	int leftShift  = x  & 15;
	int rightShift = 16 - ((16 - (16 -leftShift)) & 15);

    while(i < bitmap_height){
        
        *(base + height_offset + pixel_offset) |= (bitmap[i] >> leftShift );
        *(base + height_offset + pixel_offset + 1) |= (bitmap[i] << rightShift );
		
        height_offset+=40;
        i++;
    }
}

/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/

void clear16X16(UINT16 *base, const UINT16 *bitmap, int x, int y,
	int bitmap_height){
    
    int i = 0;
    int height_offset = y * 40;
    int pixel_offset = x >> 4;
	int leftShift  = x  & 15;
	int rightShift = 16 - ((16 - (16 -leftShift)) & 15);
 
    while(i < bitmap_height){
        
        *(base + height_offset + pixel_offset) = (bitmap[i] >> leftShift); 
        *(base + height_offset + pixel_offset + 1 ) = (bitmap[i] << rightShift);
        height_offset+=40;
        i++;
    }
}

/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/

void plot_bitmap8(UINT8 *base, const UINT8 *bitmap, int x, int y,
	int bitmap_height){
    
    int i = 0;
	int j = 0;
	int height_offset = y * 80;
    int pixel_offset = x >> 3;
	int mask = 1 << 7 - (x & 7);
   
    while(i < bitmap_height){
        
        *(base + height_offset + pixel_offset) |= mask = bitmap[i];
		if(j == 12){
			height_offset+=80;
			j=0;
		}
        i++;
		j++;
    }
}


/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/

void plot_bitmap32(UINT32 *base, const UINT32 *bitmap, int x, int y,
	int bitmap_height){
    
    int i = 0;
    int height_offset = y * 20;
	int pixel_offset = x >> 5;
	int leftShift  = x  & 31;
	int rightShift = 32 - ((32 - (32 -leftShift)) & 31);
    
    while(i < bitmap_height){
        
        *(base + height_offset + pixel_offset) |= (bitmap[i] >> leftShift);
        *(base + height_offset + pixel_offset + 1) |= (bitmap[i] << rightShift);
        height_offset+=20;
        i++;
    }

}

/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/

void clear32X32(UINT32 *base, const UINT32 *bitmap, int x, int y,int bitmap_height){
    
    int i = 0;
    int height_offset = y * 20;
	int pixel_offset = x >> 5;
	int leftShift  = x  & 31;
	int rightShift = 32 - ((32 - (32 -leftShift)) & 31);
    
    while(i < bitmap_height){
        
	*(base + height_offset + pixel_offset) = (bitmap[i] >> leftShift);
	*(base + height_offset + pixel_offset + 1) = (bitmap[i] << rightShift);
        height_offset+=20;
        i++;
    }
}
/******************************************************************************
*
* Name: Plot Glyph
*
* Purpose: To print a single character to framebuffer
*
* Input:
*
*    - base     : The framebuffer that will be used to toggle bits
*    - thisChar : The character to print
*    - x        : the x pos starting from the top left
*    - y        : the y pos of the glyph from the top left
*
******************************************************************************/

void plot_glyph(UINT8 *base, char thisChar, int x, int y){
    int i = 0;
    UINT8 *start = GLYPH_START(thisChar);
    
    UINT8 *temp = base;
    temp += y * 80;
    
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT){
        while(i < 8){
            *(temp + i * 80 + (x >> 3) ) = start[i];
            i++;
        }
    }
}

/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/

void plot_Background(UINT32 *base, const UINT32 *bitmap, int x, int y,
	int bitmap_height){
    
    int i = 0;
    
    while(i < bitmap_height){
        
        *(base + i)= bitmap[i];
        i++;
    }
}

