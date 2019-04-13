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
	int ysize = 1000;
	int xsize = 1000;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(200,200,100);

	// Draw a triangle on the screen.
	drawSquare(100,100,30);
    	drawSquare(150,150,55);
	gfx_color(200,0,50);
	drawSquare(250,250,50);
	
	double r = 10.0;
		
	for(int i=0;i<10;i++){
	
		drawCircle(100,100,r);
		r += 10;
	}
	drawCircle(250,250,40);
	gfx_color(0,150,200);
	drawCircle(50,200,60);
	
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
