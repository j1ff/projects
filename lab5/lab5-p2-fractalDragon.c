#include <stdio.h>
#include "myGfxShapesLib.h" // contains shapes that draw using gfx2
#include "gfx2.h"			// used for graphics



int main(int argc, char *argv[])
{

	int xSize = 800, ySize = 800;	// used in initializing gfx window
	
	int r,g,b;		// vars to hold color selection of user
	
	char input[15]; // char array to hold user input for parsing
	
	GfxPoint start, end;	// initialize GfxPoint, used as params for 
							// drawDragon(). has 2 components, .x and .y
							
	double minLineLength; 	// store var for smallest line length to draw
							// with drawDragon()						
	
	// open graphics window 
	gfx_open(xSize, ySize, "Lab 5 - p2 - fractalDragon");

while(1)	// infinite loop
{
	
	// Get user input for x y coords of start
	// using fgets and sscanf
	printf("Enter x and y coordinates of start: ");
	fgets(input,15,stdin);
	sscanf(input,"%lf %lf", &start.x, &start.y);

	// Get user input for x y coords of end
	// using fgets and sscanf
	printf("Enter x and y coordinates of end: ");
	fgets(input,15,stdin);
	sscanf(input,"%lf %lf", &end.x, &end.y);

	// Get minimum line length to draw
	printf("Enter minimum line length to display: ");
	fgets(input,15,stdin);
	sscanf(input,"%lf", &minLineLength);
	
	// Get color used to drawDragon() from user
	printf("Enter color used to draw.\nType 3 numbers for R G B (0 to 255): ");
	fgets(input,15,stdin);
	sscanf(input,"%d %d %d", &r, &g, &b);
	
	// set gfx_color with rgb values from user
	gfx_color(r,g,b);
	
	//clear screen before drawing another dragon
	gfx_clear();
	
	// call drawDragon function to draw a fractal dragon	
	drawDragon(start, end, minLineLength);
	gfx_flush;
}
}
