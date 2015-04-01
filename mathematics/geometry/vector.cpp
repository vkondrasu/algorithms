#include <cstdio>
#include <math.h>

struct Point
{
	int x;
	int y;
};


struct Vector
{
	int x;
	int y;
};


void constructVector(Vector &vec, int x1, int x2, int y1, int y2)
{
	Point A;
	A.x = x1;
	A.y = y1;

	Point B;
	B.x = x2;
	B.y = y2;

	vec.x = A.x - B.x;
	vec.y = A.y - B.y;
}

//Compute the dot product AB ⋅ BC
int dot(const Point &A, const Point &B, const Point &C){
    Point AB;
    Point BC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    int dot = AB.x * BC.x + AB.y * BC.y;
    return dot;
}

//Compute the cross product AB x AC
int cross(const Point &A, const Point &B, const Point &C){
    Point AB;
    Point AC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    int cross = AB.x * AC.y - AB.y * AC.x;
    return cross;
}

//Compute the distance from A to B
double distance(const Point &A, const Point &B){
    int d1 = A.x - B.x;
    int d2 = A.y - B.y;
    return sqrt(d1*d1+d2*d2);
}

//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(const Point &A, const Point &B, const Point &C, bool isSegment=true){
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment){
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return (dist > 0? dist:-dist);
}

/*int vectorDotProduct(const Vector &start, const Vector &end)
{
	return start.x * end.x + start.y * end.y;
}

int vectorCrossProduct(const Vector &vec)
{
	return start.x * end.y + start.y * end.x;
}*/

int main(int argc, char* argv[])
{
	return 0;
}
