#include <stdio.h>
#include "myGfxShapesLib.h" // contains functions to draw shapes with gfx2
#include "gfx2.h"  // needed for graphics


int main(int argc, char *argv[])
{
	char postDrawAction, colorSelect; // var to track what user wishes to do after first draw
	int xCoord,yCoord,radius; // vars to store x y coords and radius of user input for use in circleThing()
	int xSize = 800, ySize = 800;
	
	// open graphics window 
	gfx_open(xSize, ySize, "Lab 5 - p1 - circleThing");


while(1)	// infinite loop to keep asking to draw circlethings
{
	
	// get x y coordinates and radius of initial circle from user and store in variables for use in circleThing()
	printf("Please enter x coordinate, y coordinate, radius of initial circle: ");
	scanf("%d %d %d", &xCoord, &yCoord, &radius);
	
	// get color of lines for case switch
	printf("Please enter (g)reen, (b)lue, or (r)ed: ");
	scanf("%s", &colorSelect);
	
	
	
	// case switch to select color. if an invalid letter is put in, 
	// will default to white
	switch(colorSelect)
	{
		case 'g': 
			gfx_color(0,200,0);			
			break;
		case 'b': 
			gfx_color(0,0,200);
			break;			
		case 'r': 
			gfx_color(200,0,0);
			break;
		default: 
			gfx_color(100,100,100);
			break;
	
	
	}

	// function from myGfxShapesLib that will draw a 
	// recursive circleThing
	circleThing(xCoord,yCoord,radius,6); 
	
	
	// prompt user for next action after first draw
	printf("Please enter (q)uit, (c)lear screen before next draw,\n"); 
	printf("or c(o)ntinue to draw again without clearing screen: ");
	scanf(" %c", &postDrawAction);
	
	if(postDrawAction == 'q'){
		 break;		//if user types q to quit, break out of loop
	} else if(postDrawAction == 'c'){ 
		gfx_clear();
		gfx_flush();
	} else if(postDrawAction == 'o'){ 
		continue;		
	} else {
		continue;									
	}
	
	
}
}









