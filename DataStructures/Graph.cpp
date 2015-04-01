#include <iostream>
#include <stack>
#include <vector> 
#include <set>




using namespace std;

struct Node
{
	vector<Node*> neighbours;
	int data;
};

bool dfs(Node* start, int key) 
{
	set<Node*> visited;
	stack<Node*> s;
	s.push(start);
	Node* top;
	while (s.empty() == false) {
		top = s.top();
		s.pop();

		if (visited.find(top) == visited.end()) 
		{
			if(top->data == key)
			{
				return true;
			}

			visited.insert(top);

			for(vector<Node*>::iterator it = top->neighbours.begin(); it != top->neighbours.end(); it++)
				s.push(*it);
		}
	}

	return false;
}

int main(int argc, char* argv[])
{
	Node A;
	Node B;
	Node C;
	Node D;
	Node E;
	Node F;
	Node G;

	A.data = 1;
	B.data = 2;
	C.data = 3;
	D.data = 4;
	E.data = 5;
	F.data = 6;
	G.data = 7;

	A.neighbours.push_back(&B);
	A.neighbours.push_back(&C);

	B.neighbours.push_back(&D);
	B.neighbours.push_back(&E);
	B.neighbours.push_back(&F);

	C.neighbours.push_back(&G);

	Node* start = &A;

	cout<<dfs(start, 6);
	cout<<dfs(start, 9);


	return 0;
}