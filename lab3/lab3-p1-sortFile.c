#include <stdio.h>
#include "myGfxShapesLib.h"
#include "myFunctionsLib.h"
#include "gfx2.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
int i = 0,j;
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

//call sortNumbers() from myFunctionsLib
sortNumbers(numbers, 20);




FILE *sortedFile;
sortedFile = fopen(argv[2],"wr");

for(j = 0;j < i-1; j++)
{
	fprintf(sortedFile, "%3.1lf\n", numbers[j]);
}

fclose(sortedFile);

}
