#include <stdio.h>



int main(int argc, char * argv[])
{
	int a,b;
	double x,y;
	int intList[10] = { 100, 200, 300, 400, 300, 200, 100, 0, 0, 111};
	double doubList[12] = { .1, .2, .3, .4, 1000.01, 2000.02 };

	char p = '\101'; //101 octal is 65
	char q = 'B'; //same as '\102'
	
	char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	a = 5;
	b = 5555;
	x = 99.96779;
	y = 0.423847;


	//we can have variables that are themselves pointers..
	int *p1, *p2;	// declares type pointer to integer
	
	printf("a=%d, address of a: %ld, address in hex: %lx\n", a, (unsigned long int)&a, (unsigned long int)&a); 

	p1 = &a; //store the address (pointer) the memory for var a into pointer var
	p2 = &( intList[3] ); //pointer to box 3 of intList
	
	//if you havea  pointer, then the syntax
	// *pointerName gives you value stored there
	//instead of the address location
	
	printf("p1(address): %ld, p1(value stored): %d, p1(value stored): %d\n", (unsigned long int)p1, a, *p1);

	printf("p2(address): %ld, p2(value stored): %d, p2(value stored): %d\n", (unsigned long int)p2, intList[3], *p2);
}
