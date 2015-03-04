#include <iostream>
#include <string>

using namespace std;

int levenshteinDistanceRecursive(string s, int len_s, string t, int len_t)
{
	if(len_s == 0) return len_t;
	if(len_t == 0) return len_s;
	
	int cost;
	
	if(s[len_s - 1] == t[len_t - 1])
		cost = 0;
	else 
		cost = 1;
	
	return min(min(levenshteinDistanceRecursive(s, len_s - 1, t, len_t)+1, levenshteinDistanceRecursive(s, len_s, t, len_t - 1)+1),levenshteinDistanceRecursive(s, len_s - 1, t, len_t- 1)+cost);
}

int main(int argc, char* argv[])
{
	string s = "reter";
	string t = "reiterate";
	cout<<levenshteinDistanceRecursive(s, s.length(), t, t.length())<<endl;
	return 0;
}