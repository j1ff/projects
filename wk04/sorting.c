#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{

	int data[9] = 1, 77, 5, 23, 44, 92, 27, 19, 55, 71; 
	int tmp1, tmp2, lowest;
	int leftover[9];
	int sorted[9];
	
	//find lowest of first 2 nums in array
	//store lowest in var lowest, store other in array leftover
	
	tmp1 = data[0];
	tmp2 = data[1];
	if(tmp1 < tmp2)
	{
		lowest = tmp1;
		leftover[0] = tmp2;
	}
	if(tmp2 < tmp1)
	{
		lowest = tmp2;
		leftover[0] = tmp2;
	}
	

	for(int i = 2; i < sizeof(data); i++)
	{
		if(data[i] < lowest)
		{
			leftover[i-1] = lowest;
			lowest = data[i];
		}
		else{
			leftover[i-1] = data[i];
		}	
		
		
		
		
		
	
	}
}
