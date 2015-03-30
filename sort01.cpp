#include <iostream>

#define SIZE(a) sizeof(a)/sizeof(a[0])
#define FOR(i,a,b) for(int i = a; i < b; i++)

using namespace std;

void printArray(int* arr, int size)
{
	FOR(i,0,size)
		cout<<arr[i];
	cout<<endl;
}

void sortZeroOne(int *arr, int size)
{
	int start = 0, end = size -1;

	while(start < end)
	{
		while(arr[start] == 0 && start < size)
			start++;
		while(arr[end] == 1 && end >= 0)
			end--;
		if(start < end)
		{
			arr[start] = (arr[start]  + arr[end] - (arr[end] = arr[start]));
		}
	}
}


int main(int argc, char* argv[])
{
	int in_array[] = {1,1,1,1,1,1,1,1,1,1,1};
	sortZeroOne(in_array, SIZE(in_array));
	printArray(in_array, SIZE(in_array));

	return 0;
}