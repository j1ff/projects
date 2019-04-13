/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx2.h"

void drawSquare(double xCenter, double yCenter, double side)
{
	
	//calculate xy coordinates for 4 corners of square
	//ulx is upper left x, etc.
	int ulx = xCenter - side/2;
	int uly = yCenter - side/2;
	int llx = xCenter - side/2;
	int lly = yCenter + side/2;
	int lrx = xCenter + side/2;
	int lry = yCenter + side/2;
	int urx = xCenter + side/2;
	int ury = yCenter - side/2;
	
	//draw 4 lines to create square
	gfx_line(ulx,uly,llx,lly);
	gfx_line(llx,lly,lrx,lry);
	gfx_line(lrx,lry,urx,ury);
	gfx_line(urx,ury,ulx,uly);

}

int main()
{
	int ysize = 300;
	int xsize = 300;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(200,200,100);

	// Draw a triangle on the screen.
	drawSquare(100,100,30);
    drawSquare(150,150,55);

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
