#include <cstdio>
#include <stdlib.h>

#define MIN(a,b) (a>b ? b:a)
#define MAX(a,b) (a>b ? a:b)

int GCD(int a, int b)
{
	int low, high;
	low = MIN(a,b);
	high = MAX(a,b);
	if(high%low == 0)
	{
		return low;
	}

	int temp;

	while(low != 0)
	{
		temp = high;
		high = low;
		low = temp%low;	
	}
	return high;
}

int LCM(int a, int b)
{
	// based on the fact that a*b = GCD(a,b) * LCM(a,b)
	return a*b/GCD(a,b);
}
int main(int argc, char* argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("LCM of %d, %d is: %d\n", a, b, LCM(a,b));

	return 0;
}

