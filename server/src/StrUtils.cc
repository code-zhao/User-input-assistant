 ///
 /// @file    StrUtils.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 11:33:15
 ///

#include "StrUtils.h"

using namespace std;

int min(int a, int b, int c)
{
	int tmp = a < b ? a : b;
	return tmp < c ? tmp : c;
}

bool isUTF8(const string &word)
{
	return (word[0] & 0xe0 && word[1] & 0x80 && word[2] & 0x80);
}

vector<string> Str2Vec(const string &rhs)
{
	vector<string> ret;
	if(isUTF8(rhs))
	{
		for(string::size_type col = 0; col < rhs.size(); col += 3)
		{
			string sing = rhs.substr(col, 3);
			ret.push_back(sing);
		}
	}
	else
	{
		for(string::size_type col = 0; col < rhs.size(); ++col)
		{
			string sing = rhs.substr(col, 1);
			ret.push_back(sing);
		}
	}
	return ret;
}
