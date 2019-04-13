//use gfx2 library to draw letters, numbers, symbols 
#include <stdio.h>
#include <math.h>
#include "gfx2.h"
#include "lab1-p1-letterLib.h"



/*
 *  drawChar8
 *		uses the gfx2 library to draw number 8 in 'outline' style 
 *		takes parameters x,y of upper left corner and height
 *
 */

void drawChar8(double xUL, double yUL, double height)
{
	

	
	//calculate width to be 3/4 of height
	double width = .750 * height;
	

	//draw outline of 8
	gfx_line(xUL + (.8 * width),yUL,xUL + (.2 * width),yUL);
	gfx_line(xUL + (.2 * width),yUL,xUL,yUL + (.15 * height));
	gfx_line(xUL,yUL + (.15 * height),xUL,yUL + (.4 * height));
	gfx_line(xUL,yUL + (.4 * height),xUL + (.2 * width),yUL + (.5 * height));
	gfx_line(xUL + (.2 * width),yUL + (.5 * height),xUL,yUL + (.6 * height));
	gfx_line(xUL,yUL +(.6 * height),xUL,yUL + (.85 * height));
	gfx_line(xUL,yUL + (.85 * height),xUL + (.2 * width), yUL + height);
	gfx_line(xUL + (.2 * width),yUL + height,xUL + (.8 * width),yUL + height);
	gfx_line(xUL + (.8 * width),yUL + height,xUL + width,yUL + (.85 * height));
	gfx_line(xUL + width,yUL + (.85 * height),xUL + width,yUL + (.6 * height));
	gfx_line(xUL + width,yUL + (.6 * height),xUL + (.8 * width),yUL + (.5 * height));
	gfx_line(xUL + (.8 * width),yUL + (.5 * height),xUL + width,yUL + (.4 * height));
	gfx_line(xUL + width,yUL + (.4 * height),xUL + width,yUL + (.15 * height));
	gfx_line(xUL + width,yUL + (.15 * height),xUL + (.8 * width),yUL);
	
	//top circle inside 8
	gfx_line(xUL + (.25 * width),yUL + (.2 * height),xUL + (.25 * width),yUL + (.35 * height));
	gfx_line(xUL + (.25 * width),yUL + (.35 * height),xUL + (.75 * width),yUL + (.35 * height));
	gfx_line(xUL + (.75 * width),yUL + (.35 * height),xUL + (.75 * width),yUL + (.2 * height));
	gfx_line(xUL + (.75 * width),yUL + (.2 * height),xUL + (.25 * width),yUL + (.2 * height));
	
	//bottom circle inside 8
	gfx_line(xUL + (.25 * width),yUL + (.65 * height),xUL + (.25 * width),yUL + (.8 * height));
	gfx_line(xUL + (.25 * width),yUL + (.80 * height),xUL + (.75 * width),yUL + (.8 * height));
	gfx_line(xUL + (.75 * width),yUL + (.80 * height),xUL + (.75 * width),yUL + (.65 * height));
	gfx_line(xUL + (.75 * width),yUL + (.65 * height),xUL + (.25 * width),yUL + (.65 * height));
		
}
