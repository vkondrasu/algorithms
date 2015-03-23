#include <cstdio>
#include <math.h>
#include <string.h>
#include <iostream>


#define FORI(i,a,b,c) for(int i=(a);i<(b);i +=c)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

//template <typename T>
void print(bool* arr, int length)
{
	int size = length;// SIZE(arr);

	printf("%d\n", size);

	FOR(i,1,size)
		if(arr[i])
			printf("%d ", i);
}

bool isPrime(int number,unsigned long long int &count)
{

	if(number <= 1)
		return false;

	if(number == 2)
		return true;

	if(number%2 == 0)
		return false;

	int m = sqrt(number);

	FORI(i,3,m,2)
	{

		if(number%i == 0)
			return false;
	}

	return true;
}

void getPrimeNumbers(int limit, unsigned long long int &count)
{
	bool *primes = new bool[limit+1];
	/*FOR(i,0,limit+1)
		primes[i] = true;*/

	memset(primes, 1, sizeof(bool) * (limit+1));

	int m = sqrt(limit);

	primes[0] = primes[1] = false;

	FOR(i,2,m+1)
	{
		++count;
		if(primes[i])
		{
			FORI(k,i*i,limit+1,i)
			{
				++count;
				primes[k] = false;
			}
		}
	}

	print(primes, limit+1);

	printf("\n");
}

void getPrimeNumbers1(int limit, unsigned long long int &count)
{
	bool *primes = new bool[limit+1];
	/*FOR(i,0,limit+1)
		primes[i] = true;*/

	memset(primes, 1, sizeof(bool) * (limit+1));

	int m = sqrt(limit);

	FORI(i,2,limit+1,2)
	{
		primes[i] = false;
	}

	primes[0] = primes[1] = false;
	primes[2] = true;

	FORI(i,3,m+1,2)
	{
		++count;
		if(primes[i])
		{
			FORI(k,i*i,limit+1,2*i)
			{
				++count;
				primes[k] = false;
			}
		}
	}

	print(primes, limit+1);

	printf("\n");
}

int main(int argc, char* argv[])
{
	int num;
	printf("Enter the number to check:");
	scanf("%d", &num);

	unsigned long long int operations = 0, t_count=0;

	/*if(isPrime(num))
		printf("%d is a prime number\n",num);
	else
		printf("%d is NOT a prime number\n",num); */
	getPrimeNumbers(num, operations);
	cout<<operations<<endl;
	

	return 0;
}
