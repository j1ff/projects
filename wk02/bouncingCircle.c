/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include <unistd.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"



int main()
{
	int ysize = 800;
	int xsize = 800;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");


	gfx_color(0,200,100);
	
	drawCircle(400,400,40);
	
	double x = 0.0;
	double xSpeed = 10.0;
	double r = 50.0;	
	
	while(1)
	{
		gfx_clear();
		drawCircle(x,400,r);
		gfx_flush();
		x += xSpeed;
		
		if (x == xsize - r) { xSpeed = -10.0; }
		
		if (x <= r) { xSpeed = 10.0; }
		//x += 10;
		usleep(120000);
	}
	
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
