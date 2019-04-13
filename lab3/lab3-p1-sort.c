#include <stdio.h>
#include "myGfxShapesLib.h"
#include "myFunctionsLib.h"
#include "gfx2.h"


int main()
{



//fill an array with numbers to be sorted
double numbers[10] = {8,0,4,32,11,48,99,15,19,25};

//call sortNumbers function from myFunctionsLib
sortNumbers(numbers, 10);

//print array so user can see that numbers are now in sequential order
	for(int i = 0;i<10;i++)
	{
		printf("%3.1lf\n",numbers[i]);
	}

}
