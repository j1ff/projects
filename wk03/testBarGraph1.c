#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"

int main(int argc,char* argv[])
{
	
	double xsize = 600;
	double ysize = 600;
	char c;
	
	int argIndex, dataIndex;
	double cmdLineValues[100];
	int numDataValues = argc -1;
		
/*	printf("Number of args: %d\n",argc);
	puts("Arg Values:");
	for(argIndex=0; argIndex < argc; argIndex++)
	{
		printf("Arg %d value: %s\n", argIndex, argv[argIndex]);
	}

	//	double x;
	//	sscanf("7.2", "%lf", &x);
	//	printf("%lf + 2.0 = %lf\n", x, x + 2.0); 
	
	puts("---------------");
	
	//instead of array of string, want array of nums..
	//define new array of numbers (doubles) and put converted 		
	//values from argv into that array...
	//puts("Converting from Strings to Floats");
	
	//for(int argIndex = 1; argIndex < argc; argIndex++)
*/	
/*
 *	convert cmd line args into array of doubles
 */
 	
	for(argIndex = 1; argIndex <= numDataValues; argIndex++)
	{
	
		sscanf(argv[argIndex], "%lf", &(cmdLineValues[argIndex-1]) );
	
	}
	
/*	for(dataIndex = 0; dataIndex < numDataValues; dataIndex++)
	{
		printf("Data Value %d: %3.3lf\n", dataIndex, cmdLineValues[dataIndex]);
	}
*/	 

/*
 *	-----Beginning of building graphics from string of doubles-------
 */
 
	gfx_open(xsize,ysize,"Drawing Bars! [test program using command line args]");
	gfx_color(255,0,0); 
	
	drawBars(cmdLineValues,numDataValues,50,550,25,5);
	
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
 
 


}
