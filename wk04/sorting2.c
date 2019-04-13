#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{

int data[10] = 5,82,99,22,1,17,83,32,22,16,4;

int championIndex;

for(int i = 0; i < sizeof(data); i++)
{
	championIndex = i;
	if(data[i] > data[championIndex])
	{
		championIndex = i;
	}
	
	data[i] = data[championIndex]



}


