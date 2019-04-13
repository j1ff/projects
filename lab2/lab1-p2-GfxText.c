#include <stdio.h>
#include "lab1-p2-letterLib.h"
#include "gfx2.h"
#include <string.h>

int main(void)
{
	char word[100];
	char c;
	int r, g, b, height;
	double xUL, yUL;
	int ySize = 800;
	int xSize = 800;
	


//Use params to write word using letterLib
	gfx_open(xSize,ySize,"Draw Text");
	
//infinite while loop encompassing program ensures that gfx screen
//stays open and user input is printed to screen until quit 
//command is issued 
while(1) {	
	//Get all params for drawText from user
	printf("Enter a word(type clear/quit to erase screen/exit): ");
	scanf("%s", word);

	//if user input is 'quit', exit program
	if(strcmp(word, "quit") == 0)
	break;
	
	//if user input is 'clear', clear the draw sreen and 
	//run through loop again
	if(strcmp(word, "clear") == 0)
	{
	gfx_clear();
	gfx_flush();
	continue;
	}
	
	printf("Enter a value for red between 0 and 255: ");
	scanf("%d", &r);

	printf("Enter a value for green between 0 and 255: ");
	scanf("%d", &g);

	printf("Enter a value for blue between 0 and 255: ");
	scanf("%d", &b);

	printf("Enter x coordinate: ");
	scanf("%lf", &xUL);

	printf("Enter y coordinate: ");
	scanf("%lf", &yUL);

	printf("Enter letter height: ");
	scanf("%d", &height);
	
	

	gfx_color(r,g,b);	
	drawText(word, xUL, yUL, height);
	gfx_flush();
}

/*
    while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}
*/
return 0;

}

