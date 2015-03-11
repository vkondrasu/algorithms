/*
	Collatz conjecture: This is also called the 3n+1 problem
*/

#include<cstdio>
#include<iostream>

unsigned int cycleLength(long long int);

unsigned int cycleLengthResult[1000001]={0,1,0};

int main(int argc, char *argv[])
{
	int i=0, j= 0, curr= 0, max= 0, k= 0, temp= 0;
	
	for(i=2; i<1000001; ++i)
	{
		if(!(i&1))
			cycleLengthResult[i] = 1 + cycleLengthResult[i/2];
		else if(i%8 == 5)
			 cycleLengthResult[i] = 4 + cycleLengthResult[3 * ((i - 5) / 8) + 2];
		 else 
			 cycleLengthResult[i] = cycleLength(i);
	}
	
	while ( scanf("%d%d", &i, &j) != EOF )
	{
		printf("%d %d ", i, j);
		if ( i > j )
		{
				temp = i;
				i = j;
				j = temp;
		}
		max = 0;
		for ( k = i ; k <= j ; ++ k )
		{
				curr = cycleLengthResult[k];
				if (curr > max) max = curr;
		}
		printf("%d\n", max);
	}
	
	return 0;
}

unsigned int cycleLength(long long int arg)
{
	unsigned int value = 0;
	if(arg > 1000000)
	{
		if (arg & 1)
			return 1 + cycleLength(arg*3+1);
		else
			return 1 + cycleLength(arg/2);
	}
	else if(!cycleLengthResult[arg])
	{
		if(arg&1)
			value = 1 + cycleLength(3*arg+1);
		else
			value = 1 + cycleLength(arg/2);
	}
	else
		return cycleLengthResult[arg];
	
	return value;
}