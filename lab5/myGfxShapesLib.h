/************************************************************************  
 *	myGfxShapesLib.h													*
 *      a library that draws various shapes using the gfx2 library		*
 *																		*
 *	Author: Keith Simmons												*
 *																		*
 ************************************************************************/

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

//function header for drawPolygonWithoutStructs 
void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount);

//function header for recursiveCircles
void circleThing(int x, int y, int r, double rlimit);

//function header for drawDragon
void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit);

//function header for recursiveTree
void recursiveTree(double baseX, double baseY, double branchLength, double branchAngle,
				   double lengthRatioA, double lengthRatioB, double branchAngleA,
				   double branchAngleB, double minBranchLength);
				   
				   
				   
				   
				   
				   
				   
