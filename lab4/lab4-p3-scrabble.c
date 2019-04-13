/* 	Scrabble game
 *	Builds a 21x21 game board then allows user to specify row/col to start word, and (d)own
 *	or (a)cross. Checks to make sure a word crossing another word has correct letter at crossing point. 
 *
 *
 *	Author: Keith Simmons
 *	Date modified: 3/26/19
 */
 
#include <stdio.h>
#include <string.h>

#define ROWCOUNT 21
#define COLCOUNT 21
 
// Function that draws the scrabble board given array containing game information
void drawScrabble(char gameBoard[ROWCOUNT][COLCOUNT])
{
	int i,j;
	//draw initial column numbers above game board
	printf("    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 \n");
	
	for(i=0;i < 21;i++){
		printf("%2d ", i+1);
		for(j=0;j < 21;j++){
			printf(" %c ", gameBoard[i][j]);
		}
		printf("\n");	
	}
		
			
}	
	

  
 
int main(int argc,char * argv[])
{
	int i,j,wordLength;
	int rowNum;
	int colNum;
	char scrabbleBoard[ROWCOUNT][COLCOUNT] = {{' '}};
	char direction;
	char word[15];

while(1==1){

	//draw initial empty board
	//drawScrabble(scrabbleBoard);
	rowNum = 0;
	colNum = 0;
	
	
	printf("Enter Row  and Col: ");
	scanf("%d %d", &colNum, &rowNum);
	
	//printf("Enter column #: ");
	//scanf("%d", &col);
	
	printf("Enter (d)own or (a)cross:");
	scanf("%s", &direction);
	
	printf("Enter word: ");
	scanf("%s", word);
	
	//gets length of word entered 
//	wordLength = strlen(word);
	
	printf("%d\n", rowNum);
	printf("%d\n", colNum);
/*	if (direction == 'd'){
		
		for (i=0;i < wordLength;i++){
			scrabbleBoard[row][col] = word[i];
			row++;
		}

	}
	
	if (direction == 'a'){
		for (i = 0;i < wordLength;i++){
			scrabbleBoard[row][col+i] = word[i];
			
		}
	
	}	
*/
}

}

