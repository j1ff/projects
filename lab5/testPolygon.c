/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"



int main()
{
	int ysize = 600;
	int xsize = 600;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(255,0,0);
	double xCoords[10] = {200,300,400,300,200};
	double yCoords[10] = {200,200,300,400,400};
	int n = 5;
	
	drawPolygonWithoutStructs(xCoords,yCoords,n);
	gfx_color(0,255,100);
	//declaring an array of GfxPoint structures and initialize first 5 cells of array
	GfxPoint pointList[10] = { { .x=20, .y=20},
						       { .x=30, .y=20},
						  	   { .x=40, .y=30},
						 	   { .x=30, .y=40},
							   { .x=20, .y=40} };

	n = 5;
	drawPolygon(pointList, n);
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
