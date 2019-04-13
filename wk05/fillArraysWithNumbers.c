#include <stdio.h>
#include <stdlib.h> //needed for srand and rand
#include <time.h> //needed for seeding srand with time

void printListOfDoubles(double *list, int length)
{
	for(int i;i < length;i++)
	{
		printf("%lf\n",list[i]);	
	}
}


int main(int argc, char* argv[])
{
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
		listB[i] = (double) rand() / (double) RAND_MAX;
	
	}
	
	printListOfDoubles(listB, lengthB);

}
