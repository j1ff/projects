#include <stdio.h>


long long int fib(long long int n)
{
	if(n<=1){
		return n;
	} else {
		return fib(n-1) + fib(n-2);
	}		

}




int main(int argc,char * argv[])
{
	long long int userN;
	
	printf("What value for n? ");
	scanf("%lld", &userN);
	printf("Fibonacci(%lld) = %lld\n", userN, fib(userN));
























}
