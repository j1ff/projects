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
	gfx_color(200,200,100);
	double xCoords[10], yCoords[10];
	
	drawPolygon(xCoords,yCoords,10);

	
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
