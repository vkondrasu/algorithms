#include <cstdio>
#include <cstdlib>

/*int power(int a, int b)
{
	if(b == 0)
		return 1;
	else if(b&1)
		return a* power(a, b/2) * power(a, b/2);
	else
		return power(a, b/2) * power(a, b/2);
}*/

int power(int a, int b)
{
	if(b == 0)
		return 1;
	int temp = power(a,b/2);
	if(b&1)
		return a* temp * temp;
	else
		return temp * temp;
}

/*int power(int a, int b)
{
	int result = 1;
	while(b > 0)
	{
		result *= a;
		b--;
	}

	return result;

}*/

int main(int rgc, char* argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("%d\n", power(a,b));

	return 0;
}