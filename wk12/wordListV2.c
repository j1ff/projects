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

	char *wordListP[MAXWORDS]; // an array of pointers, which will point to first
							   // byte of each string in memory
	
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
///////////////////////////////////////////////////////////////////////////////
	
	char *wordListData; // will point to a big allocated chunk of data, where
						// all strings will be stored compactly
						
	char *wordListPC[MAXWORDS] = { NULL }; // P for pointer, C for compact
	
	int byteCount = 0;
	int dataSize = 32;
	
	wordListData = malloc(dataSize); 	// allocate 32 bytes for word storage
								// 1k would be good initial size... we are using
								// 32 bytes to make easier to see grow in kdbg
	// good strategy for growing/shrinking allocated is doubling/halving when needed
	
	char *junkToGetInTheWay = malloc(dataSize);
									
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
		
		// calculate new address before updating bytecount
		char *nextStringAddress = wordListData + byteCount;
		
		// calculate new total number of bytes...
		byteCount = byteCount + strlen(word) + 1;
		
		// if bytecount > current allocated bytes.. need to grow allocated mem
		if(byteCount > dataSize)
		{ 
			dataSize = dataSize * 2;
			// grow the allocated space
			wordListData = realloc(wordListData, dataSize);
			// ideally after malloc or realloc, bulletproof for failure of allocating
			
		}
		
		
		// need a pointer into big chunk of memory to the next unused byte..
		// that's just wordListData + count of bytes used so far
		wordListPC[wordIndex] = nextStringAddress;

 		
 		
		// copy it into the array
		strcpy(wordListPC[wordIndex], word); // a box from wordListP is already a pointer
											  // we don't want a pointer to a pointer
		
		// increment wordCnt
		wordIndex++;
		
		// how do we know when the list is finished?
		
		
	}


}



