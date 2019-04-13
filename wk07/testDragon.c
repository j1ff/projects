#include <stdio.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"
#include <stdlib.h>


int main(int argc, char * argv[])
{
	int xSize = 800;
	int ySize = 800;
	int c, delay;
	double limit;
	
	if (argc >= 3) {
	sscanf(argv[1],"%lf",&limit);
	sscanf(argv[2],"%d",&delay);
	} else {
		printf("Command line args needed.\nUsage: testDragon minSegmentLength drawDelay\n");
		printf("Exiting program\n");
		exit(1);
	}
	
	gfx_open(xSize, ySize, "circles");
	gfx_color(100,100,100);

	int x,y,r,newX,newR;
	
	GfxPoint first = {.x= 200,.y=200}, last = {.x= 400,.y=400};

	drawDragon(first, last, limit, delay);
	
	while(1)
	{
		c = gfx_wait();
		if (c=='q') break;
	}	
	
	return 0;
}




