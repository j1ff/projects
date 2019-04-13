#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWCOUNT 10
#define COLCOUNT 6

void printTableOfDoubles(double table[ROWCOUNT][COLCOUNT], int nRow, int nCols)
{
	int i,j;
	
	for (i=0; i < nRow; i++)
	{
		if (i == 0) {
		printf("%10s %7d %7d %7d %7d %7d %7d\n", "Row/Column",0,1,2,3,4,5);  
		} else {
		printf("\n");
		}
		
		for (j=0; j < nCols; j++)
		{
			if (j == 0) {
			printf("%10d %8.2lf",i, table[i][j]);
			} else {
			printf("%8.2lf", table[i][j]);
			}
		}	
	}
	printf("\n");

}

int main(int argc,char * argv[])
{
	int rowIndex, colIndex;
	srand(time(NULL));
	
	//create 2d array
	double myTable[ROWCOUNT][COLCOUNT];
	
	//fill with random nums
	for (rowIndex=0; rowIndex < ROWCOUNT; rowIndex++)
	{
		for (colIndex=0; colIndex < COLCOUNT; colIndex++)
		{
			myTable[rowIndex][colIndex] = (double) rand() / RAND_MAX * 100.0;	
		}
	}
	
	printTableOfDoubles(myTable, ROWCOUNT, COLCOUNT);
	
}	
