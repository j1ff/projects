/*  myGfxShapesLib.c
 *      a library that draws various shapes using the gfx2 library
 *
 *	Author: Keith Simmons
 *	Last modified: 3/14/19  v0.3
 */
#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"
#include <math.h>
#include <unistd.h>
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





/*	
 *	drawPolygon
 *		take a list of x coords, Y coords for points then plot lines 
 *		from one point to next, then from last point to first point
 *
 */
 
void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount)
 {
 	int i;
	for(i=0;i <= coordCount-2;i++)
	{
		gfx_line(xCoords[i],yCoords[i],xCoords[i+1],yCoords[i+1]);
	}
	 
	//draw line from last coord to beginning
	gfx_line(xCoords[i],yCoords[i],xCoords[0],yCoords[0]);
	 
 
 
 }
 
  void drawPolygon(GfxPoint * points,int pCount)
 {
 	int i;
 	int lastPointIndex = pCount - 1;
 	
 	for(i=0;i <= lastPointIndex;i++)
 	{
 	
 		gfx_line(points[i].x, points[i].y, points[(i+1)%pCount].x, points[(i+1)%pCount].y);
 	
 	}
 	//draw line from last coord to beginning
 	//gfx_line(points[i].x, points[i].y, points[0].x, points[0].y);
 
 
 
 }
 
/*	recursiveCircles
 *		draws a middle circle then draws a circle half as big on left and right
 *		until radius of circle is less than 1
 *
 */
 
void recursiveCircles(int x, int y, int r, double rlimit)
{
	int leftX, rightX, topY, botY; 
	
	drawCircle(x,y,r);
	gfx_flush();
	usleep(250000);
	
	while(r > rlimit)
	{
		topY = y-r;
		botY = y+r;
		leftX = x-r;
		rightX = x+r;
		r = r/2;
		//left circle
		recursiveCircles(leftX, y, r, rlimit);
		//right circle
		recursiveCircles(rightX, y, r, rlimit); 
		//top circle
		recursiveCircles(x,topY,r, rlimit);
		//bot circle
		recursiveCircles(x,botY,r, rlimit);
	}
}

/*	drawDragon	
 *		draws a dragon fractal
 *
 */

 void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit, int timeDelay)
 {
 	double dist = sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
 	GfxPoint newPoint;
 	//base case: draw the line
 	if( dist <= sizeLimit)
 	{
 		gfx_line(a.x,a.y,b.x,b.y);
 		gfx_flush();
 		usleep(timeDelay);
 	}
 	else
 	{
 		//calc x and y of new point
 		newPoint.x = a.x + (b.x-a.x)/2 + (b.y-a.y)/2;
 		newPoint.y = a.y + (b.y-a.y)/2 - (b.x-a.x)/2;
 		
		//recursively draw the sub-dragons 		
		drawDragon(a, newPoint, sizeLimit, timeDelay);
 		drawDragon(b, newPoint, sizeLimit, timeDelay);
 	}
 
 
 
 
 }
 
