#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//!!!add word to board --- needs to be put in standalone function addWord()
void addWord(char gameBoard[21][21],char word[20],char dir,int length,int row,int col){
	int i;
	
	if(dir == 'd'){	
			
		//loop while i is less than length of word entered	
		for (i=0;i < length;i++){
			
		//add i to row to position word downwards on board
		gameBoard[row+i][col] = word[i];		
		}
	} 
	if (dir == 'a'){
		for (i=0;i<length;i++){
			
				//add i to col to get word into correct index across board
				gameBoard[row][col+i] = word[i];
		}		
		
	} 
}

//if word is valid, returns 0. If not valid, returns 1;
int checkWord(char gameBoard[21][21],char word[20],char dir,int length,int row,int col)
{
	int valid = 0;
	int i;
	
	if(dir == 'd'){
		for(i = 0;i < length;i++){
			if(gameBoard[row+i][col] == '.'){//if cell we are looking to fill is occupied by a . or a 
											 //matching letter, do nothing
				continue;
			} else if(gameBoard[row+i][col] == word[i]){
				continue;
			} else {	//if cell doesn't contain . or matching letter, add to variable valid to be returned
				valid++;
			}			
		}
		return valid;
	}
	if(dir == 'a'){
		for(i = 0;i < length;i++){
			if(gameBoard[row][col+i] == '.'){//if cell we are looking to fill is occupied by a . or a 
											 //matching letter, do nothing
				continue;
			} else if(gameBoard[row][col+i] == word[i]){
				continue;
			} else {//if cell doesn't contain . or matching letter, add to variable valid to be returned
				valid++;
			}				
		}
		return valid;
	}	
}


int main(int argc, char * argv[])
{
	int row,col,i,j,wordLength;
	char scrabbleBoard[21][21];
	char direction;
	char word[20];
	
//seed 2d array game board with . in every position	
	for (i=0;i < 21;i++){
		for (j=0;j < 21;j++){
			scrabbleBoard[i][j] = '.';
		}	
	}
//==================================================
//infinite loop that will keep letting user input word info
while(1){

// Get word information from user and store to variables	
	printf("Enter row: ");
	scanf("%d", &row);
	row--; //subtract 1 from row to account for 0 index
	printf("Enter column: ");
	scanf("%d", &col);
	col--;//subtract 1 from col to account for 0 index
	printf("Enter (d)own or (a)cross: ");
	scanf(" %c", &direction);
	
	if (direction != 'd' && direction != 'a'){
		printf("Direction not valid! Try again.\n");
		continue;
	}
	printf("Enter word: ");
	scanf("%s", word);
	wordLength = strlen(word);
/*	
//====================================================	
//TEST print user vars
	printf("%d %d %c %s\n", row, col, direction, word);

	wordLength = strlen(word);
	printf("%d\n", wordLength);
//====================================================	
*/
//check to see if word fits on board before adding it
//!!CREATE FUNCTION checkWord()
/*
	if(direction == 'd'){
		for(i = 0;i < wordLength;i++){
			if (scrabbleBoard[row+i][col] == word[i] || 
				scrabbleBoard[row+i][col] == '.'){
				addWord(scrabbleBoard,word,direction,wordLength,row,col);
			} else {	
				printf("Word entered not valid! Try again.\n");
				continue;
			}

		}
	}
	if(direction == 'a'){
		for(i=0;i < wordLength;i++){
			if (scrabbleBoard[row][col+i] == word[i] ||
				scrabbleBoard[row][col+i] == '.'){
				addWord(scrabbleBoard,word,direction,wordLength,row,col);
			} else {
				printf("Word entered not valid! Try again.\n");
				continue;
			}
		}
	}					
*/	

	if(checkWord(scrabbleBoard,word,direction,wordLength,row,col) == 0){
		system("clear");
		addWord(scrabbleBoard,word,direction,wordLength,row,col);
	} else {
		system("clear");
		printf("Not a valid word! Try again.\n");
	}		
		
	
//print scrabble board	
	printf("   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21\n");
	for (i=0;i < 21;i++){
		printf("%2d", i+1); //print row numbers on left before each line
		for (j=0;j < 21;j++){
			
			printf(" %c ", scrabbleBoard[i][j]);
		}
		printf("\n\n");
	}		







}
}
