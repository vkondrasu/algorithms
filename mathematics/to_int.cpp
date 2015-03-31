#include <cstdio>
#include <cstdlib>

int to_int(const char *str)
{
	int result = 0;
	int i = 0;
	int digit;
	char c;

	while( (c = *(str+i)) != 0)
	{
		//printf("%c, %d", c, i);
		digit = c - '0' ;
		if(digit > -1 && digit < 10)
		{
			result *= 10;
			result += digit;
			//printf("%d\n", result);
		}

		++i;
	}

	return result;
}

int main(int rgc, char* argv[])
{
	printf("%d\n", to_int(argv[1]));

	return 0;
}