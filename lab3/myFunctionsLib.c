/*	myFunctionsLib.c
 *		collection of functions for csc250
 *
 *	Author: Keith Simmons
 *		Last modified: 3/12/19
 */
#include <stdio.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"

//used for usleep()
#include <unistd.h>

/*
//function that takes 2 numbers and swaps their values
void swapNumbers(double a, double b)
{
	double swap;
	swap = a;
	a = b;
	b = swap;
}
*/

//takes an array of numbers and sorts them from smallest to largest
void sortNumbers(double list[], int size)
{

int c,d;
double swap;
int n = size;

	for (c = 0;c < n-1;c++)
	  {
		for (d = 0;d < n-c-1;d++)
		{
		  if (list[d] > list[d+1])
		  {
		    swap = list[d];
		    list[d] = list[d+1];
		    list[d+1] = swap;
		  }
		}
	  }
	  
}

//visually sorts a set of numbers
void sortVisualize(double * list,int size)
{
int xsize = 400;
int ysize = 400;
int c,d,w;
double swap;
int n = size;

//keeps graphic window open through 
while(1){

gfx_open(xsize,ysize,"Sorting");
gfx_color(100,100,100);

//Initial drawing of the array with drawBars
//calculates bar width and spacing dependent on how many bars to fill 
//the window
drawBars(list,n,50,300,.75*(300/n),.25*(300/n));
gfx_flush();

//pause long enough for user to see initial draw
usleep(300000);
	
	//outer loop will run n - 1 times where n is the size of the array passed
	//to the function
	for (c = 0;c < n-1;c++)
	  {

		//nested for loop will run n-c-1 numbers of times where n is size 
		//of array passed to function and c is the number of times the outer for 
		//loop has run
		for (d = 0;d < n-c-1;d++)
		{
			//clears initial drawing and redraws the array after every 
			//number swap then pauses long enough for user to see the sort
			//taking place
		 	gfx_clear();
	  		drawBars(list,n,50,300,.75*(300/n),.25*(300/n));
			gfx_flush();
			usleep(300000);
		  
		  if (list[d] > list[d+1])
		  {
				
		  	
		  	
			//swaps numbers if needed		
		    swap = list[d];
		    list[d] = list[d+1];
		    list[d+1] = swap;
			
		  }
		  
		}
		
	  }
		// Wait for the user to press a character.
		w = gfx_wait();

		// Quit if it is the letter q.
		if(w=='q') break;
			
		
	}
}

