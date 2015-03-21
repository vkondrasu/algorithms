#include <cstdio>
#include <math.h>
#define FOR(i,a,b,c) for(int i=(a);i<(b);i +=c)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

bool isPrime(int number)
{
	if(number <= 1)
		return false;

	if(number == 2)
		return true;

	if(number%2 == 0)
		return false;

	int m = sqrt(number);

	FOR(i,3,m,2)
	{
		if(number%i == 0)
			return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	int num;
	printf("Enter the number to check:");
	scanf("%d", &num);

	if(isPrime(num))
		printf("%d is a prime number\n",num);
	else
		printf("%d is NOT a prime number\n",num); 

	return 0;
}
