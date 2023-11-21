#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int);

int countPrimeNos(int n)
{
	int i =2;
	if(n <2)
		return 0;
	printf("\nPrime Numbers: ");
	while(i<=n)
	{
		if(isPrime(i) == true)
			printf("%d ",i );
		i++;
	}
	return 0;
}
// https://leetcode.com/problems/count-primes/
bool isPrime(int n)
{
	//printf("\na: %d b: ",n );
	//printf("\nHello: ");
	for(int i= 2; i*i<=n; i++)
	{
		//printf("%d ", i);
		if(n%i == 0)
		{
			//printf("false\n");
			return false;
		}
	}
	return true;
}

// other method is Sieve of Eratosthenes
int countPrimeNos2(int n)
{

	int i =2;
	if(n <2)
		return 0;
	int array[n];
	array[0] = 0;
	array[1] = 0;
	for(i=2; i<=n; i++)
		array[i] = true;
	for(int i= 2; i*i<=n; i++)
	{
		//printf("Hello %d ", i);
		if(array[i] != true)
			continue;
		for(int j=i; j<=n;)
		{
			j+=i;

		//printf("Hi %d ", j);
			array[j] = false;
		}

	}
	printf("\nPrime Numbers: ");

	for(i=2; i<=n; i++)
	{
		if(array[i] == true)
			printf("%d ",i);

	}
	
	return 0;
}


int main()
{
	int n =15;

	countPrimeNos(n);
	countPrimeNos2(n);
	printf("\n");

	return 0;
}