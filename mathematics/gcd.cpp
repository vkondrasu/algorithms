#include <iostream>

#include <cstdio>

#define MIN(a,b) (a>b ? b:a)
#define MAX(a,b) (a>b ? a:b)
using namespace std;

int main(int argc, char* argv[])
{
	int low = 0, high = 0, a, b;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);

	low = MIN(a,b);
	high = MAX(a,b);
	if(high%low == 0)
	{
		printf("GCD of %d, %d is: %d\n", a, b,high);
		return 0;
	}

	int temp;

	while(low != 0)
	{
		temp = high;
		high = low;
		low = temp%low;	
	}

	printf("GCD of %d, %d is: %d\n", a, b,high);

	return 0;	
}
