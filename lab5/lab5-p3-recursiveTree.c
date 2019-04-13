#include <stdio.h>
#include "myGfxShapesLib.h"	// contains graphic shapes drawn with gfx2
#include "gfx2.h"			// used for graphics


int main(int argc, char *argv[])
{
	char w;
	double xSize = 800, ySize = 800;
	double xStart, yStart, branchLength, branchAngle, ratioA, ratioB, angleA, angleB, minLength;
	char input[20];
	int r,g,b;
	gfx_open(xSize,ySize,"trees!");
	

	while(1)
	{
		printf("Enter R G B color values (0 to 255): ");
		fgets(input,15,stdin);
		sscanf(input,"%d %d %d", &r, &g, &b);
		printf("Enter X and Y coords of base of tree: ");
		fgets(input,15,stdin);
		sscanf(input,"%lf %lf", &xStart, &yStart);
		printf("Enter branch length, branch angle in radians, and minimum branch size: ");
		fgets(input,20,stdin);
		sscanf(input,"%lf %lf %lf", &branchLength, &branchAngle, &minLength);
		printf("For sub-branch A enter ratio of base length and angle in radians: ");
		fgets(input,15,stdin);
		sscanf(input,"%lf %lf", &ratioA, & angleA);	
		printf("For sub-branch B enter ratio of base length and angle in radians: ");
		fgets(input,15,stdin);
		sscanf(input,"%lf %lf", &ratioB, & angleB);
		
		//set color to what user entered for rgb values
		gfx_color(r,g,b);

		recursiveTree(xStart,yStart,branchLength,branchAngle,ratioA,
					  ratioB,angleA,angleB,minLength);


 	w = gfx_wait();
 	if(w == 'q') break;
 
	}
	return 0;
}
