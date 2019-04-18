#include <stdio.h>
#include <string.h> // for strcopy() and string funcs
#include <stdlib.h> // for malloc(), realloc()

// our goal:
//		read a list of words entered by the user
//		store the list in an array of strings
//		print the list back

#define MAXWORDS 10000
#define MAXWORDLENGTH 50
#define MAXLINELENGTH 1000

int main(int argc, char *argv[])
{
	
	char word[MAXWORDLENGTH+1];
	char line[MAXLINELENGTH];
	
	char *wordListData; // will point to a big allocated chunk of data, where
						// all strings will be stored compactly
	
	int wordListLength = 8;
	int *wordListOffsets;
	//this will be a pointer to an array, not an array itself
	//BUT.. pointer names end up being used alot like arrays
	
	wordListOffsets = malloc(wordListLength * sizeof(int));
	//sizeof func takes a type, returns size of type in bytes
	//so for a dynamically allocated array, we need the # of cells in array
	//times # of bytes per cell(byte required by type of each cell)
	
//	int wordListOffsets[MAXWORDS] = {0}; 
	// store offsets from base pointer to know where strings start
	 
	int wordIndex;
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
		
		if(wordIndex >= wordListLength)
		{
			wordListLength = wordListLength * 2;
			wordListOffsets = realloc(wordListOffsets, wordListLength * sizeof(int));
		}
		
		// we need to save the offset into our allocated memory where
		// the next string will be stored in array that represents list of strings
		// which this time is an array of offsets
		wordListOffsets[wordIndex] = byteCount;
		//accessing cells of an array works the same way whether you
		//have an explicitly named array or a pointer to the array
		//use pointer name the same way you'd use array name
	
/*	//alternatively.... we can use pointer arithmetic.. "MAGIC"
	//if you add an int to a pointer, it adds a multiple of the size of 
	//data type that pointer is a pointer to	
		*(wordListOffsets + wordIndex) = byteCount;
		//an asterisk in front of a pointer means the actual memory location 
		//pointed to	
*/		
		
		// calculate new total number of bytes...
		byteCount = byteCount + strlen(word) + 1;
		
		// if bytecount > current allocated bytes.. need to grow allocated mem
		if(byteCount > dataSize)
		{ 
			dataSize = dataSize * 2;
			// grow the allocated space
			wordListData = realloc(wordListData, dataSize);
			// ideally after malloc or realloc, bulletproof for failure of allocating
			char *junkToGetInTheWay = malloc(dataSize);
		}
		
		// copy it into the array
		// the address of where we want to store the string is the base address
		// of our allocated memory plus the offset to where that string will start
		strcpy(wordListData + wordListOffsets[wordIndex], word); 
		
		// increment wordCnt
		wordIndex++;
		
		// how do we know when the list is finished?
	}
		
		int numWords = wordIndex;
		
		for(wordIndex = numWords - 1; wordIndex >= 0; wordIndex--)
		{
			printf("%s\n", (char *)(wordListData + wordListOffsets[wordIndex])); 
		}
}



