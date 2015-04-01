#include <iostream>
#include <cstring>
#include <cstdlib> 

#define MAX_ROWS 25
#define MAX_COLS 25

using namespace std;

struct Point
{
	int x, y;
};

struct Rectangle
{
	Point bootom_left, top_right;
};



bool fillA[MAX_ROWS][MAX_COLS] = {false};
//memset(fillA, 0, sizeof(bool)*MAX_ROWS*MAX_COLS);

void print()
{
	for(int row=0; row < MAX_ROWS; row++)
	{
		for(int col=0; col < MAX_COLS; col++)
		{
			if(fillA[row][col])
				cout<<"  ";
			else
				cout<<fillA[row][col]<<" ";
		}
		cout<<"\n";
	}
}

void fillARectangle(const Rectangle &rec, int color)
{
	for(int hor = rec.bootom_left.x; hor <= rec.top_right.x; hor++)
	{
		for(int vec = rec.bootom_left.y; vec <= rec.top_right.y; vec++)
		{
			if(fillA[hor][vec] == 0)
				fillA[hor][vec] = color;
		}
	}
}


int main(int argc, char* argv[])
{
	Point b_l = {1,2};
	Point t_r = {7,8};
	Rectangle recA = {b_l, t_r};
	fillARectangle(recA, 3);

	b_l.x = 20;
	b_l.y = 19;
	t_r.x = 23;
	t_r.y = 22;

	recA.bootom_left = b_l;
	recA.top_right = t_r;

	fillARectangle(recA, 8);
	print();
	return 0;
}