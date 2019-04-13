//Test letterLibrary by drawing character in different colors and sizes

#include "gfx2.h"
#include "lab1-p1-letterLib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int xSize = 800;
	int ySize = 800;
	
	char c;
	
	//open gfx window
	gfx_open(xSize,ySize,"Drawing Letters");
	//set gfx color
	gfx_color(200,200,200);
	
	
	drawChar8(100,100,100);
	gfx_color(0,0,255);
	
	//seed rng
	srand(time(0));
	int x,y,z,size,xRand,yRand;
	
	for(int i=0;i<15;i++)
	{
	
	x = rand() % 256;
	y = rand() % 256;
	z = rand() % 256;
	xRand = rand() % 801;
	yRand = rand() % 801;
	size = rand() % 400;
	
	gfx_color(x,y,z);
	
	drawChar8(xRand,yRand,size);
	
	
	}
	
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();
	
		// Quit if it is the letter q.
		if(c=='q') break;
	}
	
	return 0;

}

