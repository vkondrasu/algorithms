#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	int val = atoi(argv[1]);
	int dist = 0;
	
	while(val != 0)
	{
		dist++;
		val &= val-1;
	}
	
	cout<<dist<<endl;
	return 0;
}