/*  myGfxShapesLib.c
 *      a library that draws various shapes using the gfx2 library
 *
 *	Author: Keith Simmons
 *	Last modified: 4/7/19  v0.4
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
 
/*	circleThing
 *		draws a middle circle then draws a circle half as big on left,right,
 *		top, and bottom until radius of circle is less than 1
 *
 */
 
void circleThing(int x, int y, int r, double rlimit)
{
	int leftX, rightX, topY, botY; 
	
	drawCircle(x,y,r);
	gfx_flush();
	usleep(5000);
	
	while(r > rlimit)
	{
		topY = y-r;
		botY = y+r;
		leftX = x-r;
		rightX = x+r;
		r = r/2;
		//left circle
		circleThing(leftX, y, r, rlimit);
		//right circle
		circleThing(rightX, y, r, rlimit); 
		//top circle
		circleThing(x, topY, r, rlimit);
		//bot circle
		circleThing(x, botY, r, rlimit);
	}
}

/*	drawDragon	
 *		draws a dragon fractal
 *
 */

void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit)
 {
 	int red,green,blue;
 	double dist = sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
 	GfxPoint newPoint;
 	
 	//base case: draw the line
 	if( dist <= sizeLimit)
 	{
 	/*	if(a.x < 400 && a.y < 400){
 			gfx_color(255,50,50);
 		} else if(a.x < 400 && a.y >= 400){
 			gfx_color(50,255,50);
 		} else if(a.x >= 400 && a.y < 400){	 	
 			gfx_color(50,50,255);
 		} else if(a.x >= 400 && a.y >= 400){
 			gfx_color(200,200,20);
 		} else {
 			gfx_color(100,100,100);
 		}
 	*/
 		red = a.x/3.13;
 		green = a.y/3.13;
 		blue = (b.x + b.y)/6.27;
 		gfx_color(red,green,blue); 
 	
 		gfx_line(a.x,a.y,b.x,b.y);
 	}
 	else
 	{
 		//calc x and y of new point
 		newPoint.x = a.x + (b.x-a.x)/2 + (b.y-a.y)/2;
 		newPoint.y = a.y + (b.y-a.y)/2 - (b.x-a.x)/2;
 		
		//recursively draw the sub-dragons 		
		drawDragon(a, newPoint, sizeLimit);
 		drawDragon(b, newPoint, sizeLimit);
 	} 
}

/*	recursiveTree
 *		uses gfx2 to draw a tree recursively
 *		params: baseX/baseY - base point of branch
 *				branchLength/branchAngle - used to calculate other end of branch
 *				lengthRatioA/lengthRatioB - between 0 and 1 indicating relative 
 *											length of sub branches
 *				branchAngleA/branchAngleB - added to current branches angle to get 
 *											angle for sub branches
 *				minBranchLength - stops drawing when branchLength < minBranchLength
 *
 */
 
void recursiveTree(double baseX, double baseY, double branchLength, double branchAngle,
				   double lengthRatioA, double lengthRatioB, double branchAngleA,
				   double branchAngleB, double minBranchLength)
{
	// calculate the ends point of the line to be drawn
	double endPointX = baseX + branchLength * sin(branchAngle);
	double endPointY = baseY - branchLength * cos(branchAngle);
	
	// calculate lengths for sub branches
	double lengthA = lengthRatioA * branchLength;
	double lengthB = lengthRatioB * branchLength;
	
	// calculate new angles for sub branches
	double newAngleA = branchAngle + branchAngleA;
	double newAngleB = branchAngle + branchAngleB;
	
	gfx_line(baseX,baseY,endPointX,endPointY);
	gfx_flush();
	
	
	if(branchLength < minBranchLength) return;
	else {
					
		// recursive call for subBranch A
		recursiveTree(endPointX, endPointY, lengthA, newAngleA, lengthRatioA,
					  lengthRatioB, branchAngleA, branchAngleB, minBranchLength);	
		
		// recursive call for subBranch B
		recursiveTree(endPointX, endPointY, lengthB, newAngleB, lengthRatioA,
					  lengthRatioB, branchAngleA, branchAngleB, minBranchLength);
	}
}





				    
 
