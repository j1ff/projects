#include <stdio.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"



int main(int argc, char * argv[])
{
	int xSize = 800;
	int ySize = 800;
	int c;
	double limit;
	
	sscanf(argv[1],"%lf",&limit);
	
	gfx_open(xSize, ySize, "circles");
	gfx_color(100,100,100);

	int x,y,r,newX,newR;
	printf("enter x coordinate, y coordinate, radius: ");
	scanf("%d %d %d", &x, &y, &r);
	
	circleThing(x,y,r,limit);
	
	while(1)
	{
		c = gfx_wait();
		if (c=='q') break;
	}	
	
	return 0;
}




