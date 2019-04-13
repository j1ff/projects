#include <stdio.h>
#include <string.h> // for strcopy() and string funcs
#include <stdlib.h> // for malloc()

// our goal:
//		read a list of words entered by the user
//		store the list in an array of strings
//		print the list back

#define MAXWORDS 10000
#define MAXWORDLENGTH 50
#define MAXLINELENGTH 1000

int main(int argc, char *argv[])
{
	// "easy way" with a 2d array
	
	// initizaliaze all bytes in array to 0
	char wordList[MAXWORDS][MAXWORDLENGTH+1] = {{0}};
	char word[MAXWORDLENGTH+1];
	char line[MAXLINELENGTH];
	
	printf("Please enter a list of words: \n");
	printf("(End program by hitting enter with no input.)\n");
	int wordIndex = 0;
	
	while (wordIndex < MAXWORDS)
	{
		// read the next word
		// read a whole line of text
		fgets(line, MAXLINELENGTH, stdin);
		
		// exit loop if blank line is entered
		// if first char is newline, break out of loop
		if(line[0] == '\n') break;
		
		sscanf(line, "%50s", word); // reads a line (or up to MAX...chars) stores in 
							 		// array line. now fish a word from line we just read
		
		// copy it into the array
		strcpy(&(wordList[wordIndex][0]), word);
		
		// increment wordCnt
		wordIndex++;
		
		// how do we know when the list is finished?
		
		
	}
	/////////////////////////////////////////////////////////////////////////

	char *wordListP[MAXWORDS];
		
	printf("Please enter another list of words: \n");
	printf("(End program by hitting enter with no input.)\n");
	wordIndex = 0;
	
	while (wordIndex < MAXWORDS)
	{
		// read the next word
		// read a whole line of text
		fgets(line, MAXLINELENGTH, stdin);
		
		// exit loop if blank line is entered
		// if first char is newline, break out of loop
		if(line[0] == '\n') break;
		
		sscanf(line, "%50s", word); // reads a line (or up to MAX...chars) stores in 
							 		// array line. now fish a word from line we just read
		
		// allocate memory for the word in our list
		wordListP[wordIndex] = malloc(strlen(word)+1); // malloc requests a number of bytes
											//to be allocated for program to use
											//if request is granted, then it returns
											//address of first byte of memory
 		
 		if (wordListP[wordIndex] == NULL){
 			printf("Failed to allocate memory!!\n");
 			exit(1);
 		}	
 		
		// copy it into the array
		strcpy(wordListP[wordIndex], word); // a box from wordListP is already a pointer
											  // we don't want a pointer to a pointer
		
		// increment wordCnt
		wordIndex++;
		
		// how do we know when the list is finished?
		
		
	}



}



