#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//define max size of 2d array
#define MAXROWS 200
#define MAXCOLS 200

void printTableOfInts(int table[MAXROWS][MAXCOLS], int nRow, int nCol)
{
	int i,j;
	
	for(i=0;i<nRow;i++)
	{
		for(j=0;j<nCol;j++)
		{
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}	


}


void printGameOfLife(int table[MAXROWS][MAXCOLS], int nRow, int nCols)
{
	int i,j;
	
	for (i=0; i < nRow; i++)
	{
		for (j=0; j < nCols; j++)
		{
			if (table[i][j] == 1) {
			printf(" * ");
			} else {
			printf("   ");
			}
		}
		printf("\n");	
	}
	

}

// write a function that takes 2 2d arrays of ints
// first will be a game of life grid of 1's and 0's
// the function will count the neighbors of each cell in grid

void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols) 
{
	int i,j,deltaRow,deltaCol;	
	


	for(i = 0;i < nRows;i++) { //loop for each row
		for(j = 0;j < nCols;j++) { // loop for each col
			countGrid[i][j] = 0;
			for(deltaRow = -1;deltaRow <= 1;deltaRow++) { //loop for each neighbor row
				for(deltaCol = -1;deltaCol <= 1;deltaCol++) { //loop for each neighbor col
					//if sourceGrid[i+deltaRow][j+deltaCol] is 1 then add 1 to the count 
				  	if( i+deltaRow >= 0 && j+deltaCol >= 0 && 	 //if neighbor not out of bounds
				  		i+deltaRow < nRows && j+deltaCol < nCols)
				  	{	
						if(deltaRow != 0 || deltaCol != 0){	
							countGrid[i][j] = countGrid[i][j] + sourceGrid[i+deltaRow][j+deltaCol];
					
						}
					}
				}
			}		
		}
	}		
}		//First attempt at counting while pausing video
			/* 
			if(grid[i-1][j-1] == 1){
			neighborCount++;
			} if(grid[i-1][j] == 1){
			neighborCount++;
			} if(grid[i-1][j+1] == 1){
			neighborCount++;
			} if(grid[i][j-1] == 1){
			neighborCount++;
			} if(grid[i][j+1] == 1){
			neighborCount++;
			} if(grid[i+1][j-1] == 1){
			neighborCount++;
			} if(grid[i+1][j] == 1){
			neighborCount++;
			} if(grid[i+1][j+1] == 1]){
			neighborCount++;
			}
			neighbor[i][j] = neighborCount;
			
			*/

// given a game of life grid, update values according to rules
void updateGameOfLife(int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols )
{
	int countGrid[MAXROWS][MAXCOLS];
	countNeighbors(golGrid,countGrid,nRows,nCols); 
	//look at each cell of golGrid and corresponding count and
	//decide whether it should be updated to 1 or 0 according to rules
	for(int i=0;i<nRows;i++){
		for(int j=0;j<nCols;j++){
			if(golGrid[i][j] == 1){ //if cell is currently alive	
				if(countGrid[i][j] < 2 || countGrid[i][j] > 3){
					golGrid[i][j] = 0;
				}	
			
			} else {		//if cell is currently empty	 
				if(countGrid[i][j] == 3){ //if cell has exactly 3 neighbors
					golGrid[i][j] = 1;	//a cell is born
				}	
			}
		}
	}
	

}


int main(int argc,char * argv[])
{
	//how many rows and cols we actually use
	int useRows = 20, useCols = 20;
	
	int rowIndex, colIndex;
	srand(time(NULL));
	
	//create 2d array
	int golGrid[MAXROWS][MAXCOLS];  /*= { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
									  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
									  {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
									  {0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
									  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									  {0},
									  {0},
									  {0},
									  {0},
									  {0} };
	
*/	
	int neighbors[MAXROWS][MAXCOLS];
	//fill with random nums
	for (rowIndex=0; rowIndex < useRows; rowIndex++)
	{
		for (colIndex=0; colIndex < useCols; colIndex++)
		{
			golGrid[rowIndex][colIndex] = rand() % 2;	
		}
		
	}

	
	printGameOfLife(golGrid, useRows, useCols);
	
	countNeighbors(golGrid, neighbors, useRows, useCols);
	printTableOfInts(neighbors, useRows, useCols);
	while(1){
		puts("=======================");
		printGameOfLife(golGrid, useRows, useCols);
		updateGameOfLife(golGrid, useRows, useCols);
		usleep(600000);
				system("clear");
	}
	
}	
