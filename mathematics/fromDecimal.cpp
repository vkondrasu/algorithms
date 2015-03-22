/*
the method fromDecimal2(), converts the given number to the given base format from decimal.
This method works for bases upto 20
*/

#include<cstdio>
#include<string.h>
#include<cstdlib>

void fromDecimal2(int number, int base, char* result)
{
	const char* digits = "0123456789ABCDEFGHIJ";
	result[0]=0;
	char* temp = new char[20];
	temp[0] = 0;

	while(number > 0)
	{
		temp[0] = digits[number%base];
		strcat(temp, result);
		strcpy(result, temp);
		temp[0] = 0; 
		number /= base; 
	}
}

int main(int argc, char* argv[])
{
	int number = atoi(argv[1]);
	int base = atoi(argv[2]);

	char* result = new char[20];
	memset(result, 0, sizeof(char) * 20);

	fromDecimal2(number, base, result);

	printf("%s\n", result);

	return 0;
}
