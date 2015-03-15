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

int levenshteinDistance(string s, int len_s, string t, int len_t)
{
	int **dArr = new int*[len_t+1];
	for(int i = 0; i<=len_t; i++ )
		dArr[i] = new int[len_s+1];
	
	//Intialize first column of each row with row number (starting from zero)
	for(int i = 0; i<=len_t; i++)
	{
		dArr[i][0] = i;
	}
	//Intialize first row of with column number (starting from zero)
	for(int i = 0; i<=len_s; i++)
	{
		dArr[0][i] = i;
	}
	
	for(int i = 1; i<=len_t; i++)
	{
		for(int j=1; j<=len_s; j++)
		{
			if(t[i] == s[j])
				dArr[i][j] = dArr[i-1][j-1];
			else
			{
				dArr[i][j] = min( min(dArr[i-1][j] + 1, dArr[i][j-1] + 1), dArr[i-1][j-1] +1 );
			}
		}
	}
	
	return dArr[len_t][len_s];	
	
}

int main(int argc, char* argv[])
{
	string s = "reter";
	string t = "reiterate";
	cout<<levenshteinDistance(s, s.length(), t, t.length())<<endl;
	return 0;
}