 ///
 /// @file    StrUtils.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 11:28:33
 ///

#ifndef __STRUTILS_H__
#define __STRUTILS_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int min(int a, int b, int c);

bool isUTF8(const string &word);

vector<string> Str2Vec(const string& rhs);
#endif
