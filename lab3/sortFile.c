#include <stdio.h>
#include "myGfxShapesLib.h"
#include "myFunctionsLib.h"
#include "gfx2.h"


int main(int argc, char *argv[])
{


FILE *numbers;
numbers = fopen(argv[1],"w");

double numbers[100];


//sortNumbers(numbers, 10);

sortVisualize(numbers, 10);
/*gfx_open(800,800,"test");
gfx_color(100,100,100);
drawBars(list,10,150,400,50,10);

while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

*/

for(int i = 0;i<10;i++)
{
	printf("%3.1lf\n",numbers[i]);
}






}


/*
void swap(int a, int b){
	int swap = a;
	a = b;
	b = swap;
}
*/
