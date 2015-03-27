/*
Rabin-karp method to search for a substring in given string
*/

#include<iostream>
#include<string>
#include <math.h>

#define ALPHA_SIZE 26
#define TO_INT(a) a-'a'

typedef unsigned long long int  ULLI;

using namespace std;


ULLI getNextHash(ULLI prevHash, char toRemove, char toAdd, int length)
{
	return ALPHA_SIZE * (prevHash - (pow(ALPHA_SIZE, length-1) * TO_INT(toRemove)) + TO_INT(toAdd));
}

ULLI getHash(string &text, int len)
{
	ULLI hash_value = 0;
	for(int i = len-1; i >= 0; i--)
	{
		hash_value *= ALPHA_SIZE;
		hash_value += TO_INT(text[i]);
	}

	return hash_value;
}

int serachPattern(string &text, string &pattern)
{
	int text_length = text.size();
	int pattern_length = pattern.size();
	
	ULLI patternHash = getHash(pattern, pattern_length);
	ULLI textHash = getHash(text, text_length);
	
	//If both hash values are equal then there is a chance that the pattern is found in text at 0th index
	if(patternHash == textHash)
	{
		int i = 0;
		for(; i < pattern_length; i++)
		{
			if(text[i] != pattern[i])
				break;
		}

		if(i == pattern_length)
			return 0;
	}

	int no_of_searches = text_length - pattern_length + 1;
	for(int i = 1; i < no_of_searches; i++)
	{
		textHash = getNextHash(textHash, text[i-1], text[i+pattern_length], pattern_length);

		if(patternHash == textHash)
		{
			int j = i; 
			for(; j < i+pattern_length; j++)
			{
				if(text[j] != pattern[j-i])
					break;
			}

			if(j == i + pattern_length)
				return i;
		}
		
	}

	return -1;
}

int main(int argc, char* argv[])
{
	string text = argv[1];
	string pattern = argv[2];

	cout<<serachPattern(text, pattern)<<endl;

	return 0;
}
