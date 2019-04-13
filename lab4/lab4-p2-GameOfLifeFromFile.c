#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//define max size of 2d array
#define MAXROWS 200
#define MAXCOLS 200


//Prints the game of life board
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

// function that takes 2 2d arrays of ints
// first will be a game of life grid of 1's and 0's
// the function will count the neighbors of each cell in grid
void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols) 
{
	int i,j,deltaRow,deltaCol;	
	
	for(i = 0;i < nRows;i++) { //loop for each row
		for(j = 0;j < nCols;j++) { // loop for each col
			//set current countGrid cell to 0 
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
}



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
	int i,j;
	//how many rows and cols we actually use
	//set by first line in text file
	int useRows,useCols;
	//create 2d array
	int golGrid[MAXROWS][MAXCOLS];  
 
	//Initialize file pointer
	FILE * golFile;
	//open the file passed at command line
	golFile = fopen(argv[1], "r");
	//scans file for beginning line where rows and columns are stated
	fscanf(golFile, "%d %d\n", &useRows, &useCols);
	//create a char variable to store fscanf reads in order to build game board
	char  golRead;
	
	for(i=0;i < useRows;i++){
		for(j=0;j < useCols;j++){
			//scans the file and loads the next char into variable golRead
			fscanf(golFile, "%c", &golRead);
			//if golRead is *, set golGrid to a 1(live cell), otherwise
			//set to 0(dead cell)
			if(golRead == '*'){
				golGrid[i][j] = 1;
			} else {
				golGrid[i][j] = 0;	
			}
		}
	}		
	
	
	//prints game of life grid, updates it according to rules, then pauses
	//infinite loop.. will keep doing this until program is killed
	while(1){
		puts("========================================================");
		printGameOfLife(golGrid, useRows, useCols);
		usleep(1000000);
		updateGameOfLife(golGrid, useRows, useCols);
		usleep(1000000);
				system("clear");
	}
	
}	
