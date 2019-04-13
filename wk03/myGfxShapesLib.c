/*  myGfxShapesLib.c
 *      a library that draws various shapes using the gfx2 library
 *
 *	Author: Keith Simmons
 *	Last modified: 1/20/19  v0.1
 */
#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"
#include <math.h>



/*
 *  drawSquare 
 *      draws a square with center x,y coords and side length as parameters
 */

void drawSquare(double xCenter, double yCenter, double side)
{
	
	//calculate xy coordinates for 4 corners of square
	//ulx is upper left x, etc.
	int ulx = xCenter - side/2;
	int uly = yCenter - side/2;
	int llx = xCenter - side/2;
	int lly = yCenter + side/2;
	int lrx = xCenter + side/2;
	int lry = yCenter + side/2;
	int urx = xCenter + side/2;
	int ury = yCenter - side/2;
	
	//draw 4 lines to create square
	gfx_line(ulx,uly,llx,lly);
	gfx_line(llx,lly,lrx,lry);
	gfx_line(lrx,lry,urx,ury);
	gfx_line(urx,ury,ulx,uly);

}



/*
 *  drawCircle
 *		draws a circle centered at x,y coords and radius as params
 */
 
void drawCircle(double xCenter, double yCenter, double radius)
{

	double theta = 0;
	double pi = 3.1415927;	

	while(theta < 2 * pi)
	{
		//calculate x,y of beginning of line		
		double x = xCenter + radius * cos(theta);	
		double y = yCenter + radius * sin(theta);	
		
		//add to value of theta 
		theta += 2.0 / (2.0 * pi * radius);

		//calculate x,y of end of line
		double xNext = xCenter + radius * cos(theta);
		double yNext = yCenter + radius * sin(theta);

		//draw line using x,y and xNext,yNext
		gfx_line(x,y,xNext,yNext);
	}

}

/*
 *	drawRectangle
 *		draw rectangle with params lowerLeftX,lowerLeftY,width,height
 */ 
 
 void drawRectangle(double lowerLeftX, double lowerLeftY, double width, double height)
 {
	double leftX = lowerLeftX;
	double rightX = lowerLeftX + width;
	double lowerY = lowerLeftY;
	double upperY = lowerLeftY - height;
	
	gfx_line(leftX,lowerY,leftX,upperY); 
	gfx_line(leftX,upperY,rightX,upperY);
	gfx_line(rightX,upperY,rightX,lowerY);
	gfx_line(rightX,lowerY,leftX,lowerY);
 }
 
 /*
  *	drawBars
  *		draws bar graph using drawRectangle function
  *		params: array of numbers, length of array, lower left 
  *		xy coords of first bar, bar width, and space between bars
  */
  
void drawBars(double * data, int dataCount, double lowerLeftX, double lowerLeftY,
			  double width, double spacing)
{
	double llx = lowerLeftX;
	double lly = lowerLeftY;
	
	//Loop to draw a rectangle representing each number in data[]
	for(int i = 0;i < dataCount; i++)
	{
		drawRectangle(llx, lly, width, data[i]);
		
		
		//update lower left x coord for next loop
		llx = llx + width + spacing;
	}
		
}  
