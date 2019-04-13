#include <stdio.h>
#include "myGfxShapesLib.h"
#include "myFunctionsLib.h"
#include "gfx2.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{
int i = 0;
double numbers[100];
double x;
FILE *numberFile;
numberFile = fopen(argv[1],"r");

while(!feof(numberFile))
{
	fscanf(numberFile, "%lf", &x);
	numbers[i] = x;
	i++;
}

fclose(numberFile);





sortVisualize(numbers, 20);

/*gfx_open(800,800,"test");
gfx_color(100,100,100);
drawBars(list,10,150,400,50,10);

while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}



for(int i = 0;i<10;i++)
{
	printf("%3.1lf\n",numbers[i]);
}


*/



}


/*
void swap(int a, int b){
	int swap = a;
	a = b;
	b = swap;
}
*/
