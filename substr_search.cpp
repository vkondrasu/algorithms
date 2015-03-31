/*
Rabin-karp method to search for a substring in given string
*/

#include<iostream>
#include<string>
#include <math.h>

#define ALPHA_SIZE 26
//#define TO_INT(a) a-'a'

typedef unsigned long long int  ULLI;

using namespace std;

inline int TO_INT(char c)
{
	return c - 'a';
}

ULLI getNextHash(ULLI prevHash, char toRemove, char toAdd, int length)
{
	return ALPHA_SIZE * (prevHash - ((pow((double)ALPHA_SIZE, length-1) * TO_INT((char)toRemove)))) + TO_INT((char)toAdd);
}


ULLI getHash(string &text, int len)
{
	ULLI hash_value = 0;
	ULLI muliplier = 1;
	for(int i = len-1; i >= 0; i--)
	{
		hash_value += muliplier * TO_INT((char)text[i]);		
		muliplier *= ALPHA_SIZE;
	}

	return hash_value;
}

bool compareStrings(const char *s1, const char *s2, int length)
{
	for(int i = 0; i < length; i++)
	{
		if(*(s1+i) != *(s2+i))
			return false;
	}

	return true;
}

int serachPattern(string &text, string &pattern)
{
	int text_length = text.size();
	int pattern_length = pattern.size();

	//If anyone of them empty return -1
	if(text_length == 0 || pattern_length == 0)
		return -1;

	//If text is smaller than pattern then no chance of having pattern as substring of text
	if(text_length < pattern_length)
		return -1;
	
	//get hash values of pattern and text (of pattern_length)
	ULLI patternHash = getHash(pattern, pattern_length);
	ULLI textHash = getHash(text, pattern_length);
	
	//If both hash values are equal then there is a chance that the pattern is found in text at 0th index
	if(patternHash == textHash)
	{
		if(compareStrings(text.c_str(), pattern.c_str(), pattern_length))
			return 0;
	}

	int no_of_searches = text_length - pattern_length+1;

	for(int i = 1; i < no_of_searches; i++)
	{
		textHash = getNextHash(textHash, text[i-1], text[i-1+pattern_length], pattern_length);

		if(patternHash == textHash)
		{
			if(compareStrings(&(text[i]), pattern.c_str(), pattern_length))
				return i;
		}
		
	}

	return -1;
}

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout<<"Insufficient number of arguments, please pass two parameters\n";
		return -1;
	}

	string text = argv[1];
	string pattern = argv[2];

	

	cout<<serachPattern(text, pattern)<<endl;

	return 0;
}