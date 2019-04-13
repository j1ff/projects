/*  myGfxShapesLib.h
 *      a library that draws various shapes using the gfx2 library
 *
 *	Author: Keith Simmons
 *	Last modified: 1/20/19  v0.1
 */

//much pi digits
//const double PI = 3.1415926535897932;

/*
 *	Defines
 */

typedef struct GfxPoint 
{
	//declare the component vars of the struct here
	double x;
	double y;	

} GfxPoint;


//------------------------------------------------------------------------//
//------------------------------------------------------------------------//


//function header for drawSquare
void drawSquare(double xCenter, double yCenter, double side);

//function header for drawCircle
void drawCircle(double xCenter, double yCenter, double radius);

//function header for drawBars
void drawBars(double * data, int dataCount, double lowerLeftX, double lowerLeftY,
			  double width, double spacing);
			  
//function header for drawRectangle
void drawRectangle(double lowerLeftX, double lowerLeftY, 
					double width, double height);
					
//function header for drawPolygon					
 void drawPolygon(GfxPoint * points, int pCount);
 
 void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount);
