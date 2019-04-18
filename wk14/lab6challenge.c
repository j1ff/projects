#include <stdio.h>
#include <string.h> // used for strcmp()



void main(int argc, char *argv[])
{

	char userWord[30];		// store user input word
	char wordFromFile[30];	// store each word from file, one by one
	int match = 0;				// keep track of whether word was found in list

	printf("Enter a word: ");	// prompt user for a word, store in 
	scanf("%s", userWord);		// userWord char array

	FILE *wordList;						// create file pointer and set to wordList.txt
	wordList = fopen("GameWordList","r");
	
	while(! feof(wordList))	// do this unti end of file is hit
	{
		// set char array wordFromFile to each word, line by line
		fscanf(wordList,"%s", wordFromFile);
		
		// if the word is found in the wordList file.. 
		if (!strcmp(userWord, wordFromFile))
		{
			match = 1;	// set match to 1 if user input matches a word in list
			break;		// then break out of loop
		}
		

	}	
	
	fclose(wordList); // close file once we are done reading from it

	// if a match for userWord was found do this
	if(match == 1){
		printf("%s was found in wordList!\n", userWord);
	} else {		// otherwise do this
		printf("%s is not a word in wordList.\n", userWord);
	}		




}


