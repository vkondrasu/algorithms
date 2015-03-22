/*
The method toDecimal(int number, int base), converts the number which is in base form converts to decimal form
*/

#include <cstdio>
#include <stdlib.h>


int toDecimal(int number, int base)
{
	int result = 0;
	int multiplier = 1;

	while(number > 0)
	{
		result += number%10 * multiplier;
		multiplier *= base;
		number /= 10;
	}

	return result;
}

int main(int argc, char* argv[])
{
	int number = atoi(argv[1]);
	int base = atoi(argv[2]);

	printf("%d\n", toDecimal(number, base));

	return 0;
}


