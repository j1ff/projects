#include <stdio.h>
#include <stdlib.h> //needed for srand and rand
#include <time.h> //needed for seeding srand with time
#include "myGfxShapesLib.h"
#include "gfx2.h"



void printListOfDoubles(double *list, int length)
{
	for(int i=0;i < length;i++)
	{
		printf("%lf\n",list[i]);	
	}
}


int main(int argc, char* argv[])
{
    
	int xsize = 600;
	int ysize = 600;

	srand(time(NULL));
	
	double listA[100] = {15,27,999,1000,24,56,77,0.1,3.14159,-1.0,-5.55555};
	int lengthA = 10;
	
	printf("List A\n");
	printListOfDoubles(listA, lengthA);
	
	double listB[100];
	int lengthB = 100;
	
	for (int i=0;i < lengthB; i++)
	{
		//store a random number into box i
		listB[i] = (double) rand() / RAND_MAX * 200.0;
	
	}
	printf("List B\n");
	printListOfDoubles(listB, lengthB);
	
	gfx_open(xsize,ysize,"Bar Chart of Random Data");
	gfx_color(255,130,0);
	
	int barWidth = (500/lengthB);
	int barSpacing = (500 - barWidth)/lengthB -1;
	
	drawBars(listB,lengthB,25,550,barWidth, barSpacing); 

	char c;
	//wait for user to press q to quit
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c==' ') break;
	}

		






	//****************************//
	
	//read a data file to fill another array of doubles..
	double listC[1000];
	//how to open and read a file of text data
	//(1) we need a file point var.. this will keep track of the file
	//type: FILE * //this is the file pointer type
	FILE * myFile; //declares myFile as a file pointer var
	// (2) open the desired file using the fopen() func
	//fopen("pathName/to/the/filename","modeString");
	//for reading, modeString is just "r"
	//fopen() returns a file pointer (or NULL if unsuccessful)
	myFile = fopen("whatever.txt","r");
	if(myFile == NULL)
	{
		printf("***FILE NOT FOUND***\n");
		exit(1);//forces program to exit from any point
				//needs integer which will be error status of program
	}
	//(3) with the file open you can read it with "file" versions of the 
	//input funcs--> fscanf(myFile,"format string",&this,&that);
	//compare to  	  scanf(       "format string",&the,&other);
	//any input func you use on a file, the file ptr keeps track of where 
	//	you left off in the file	
	
	//example: read one num from file and print it
		/* double firstValue;
		fscanf(myFile,"%lf",&firstValue);	
		printf("First num in file is: %lf\n",firstValue);
		*/
	//(4) how to know when you've hit end of file
	//		use feof(filePointer) to detect if you've hit eof
	//		**only TRUE after attempted to read and failed**
	//lop to read one num at a time & put in next bot of listC
	
	double value;
	int i = 0;
	//make one attempt to read before starting loop
	fscanf(myFile,"%lf",&value);
	//feof will be true if hit eof in previous attempt
	while(!feof(myFile))
	{
		listC[i] = value;
		fscanf(myFile,"%lf",&value);//attempt to read the next value
		i++;
	}
	
	//(5) file should be closed when your program is done reading it
	fclose(myFile);
	
	double lengthC = i;
	gfx_clear();
	barWidth = (500/lengthC);
	
	drawBars(listC,lengthC,25,550,.7*barWidth,.3*barWidth); 
	
	
	
	
	//****************************//
	
	
	
	//wait for user to press q to quit
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;

}
